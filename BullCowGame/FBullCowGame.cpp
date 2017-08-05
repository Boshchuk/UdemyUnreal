#pragma once

#include "FBullCowGame.h"
#include <map>

// to make syntax unreal
#define TMap std::map
using int32 = int;

FBullCowGame::FBullCowGame() { 	Reset(); }



int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetMyTries() const { return 0; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { 	return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const { 
	TMap<int32, int32> WorldLenghtToMaxTries{ {3,4},{4,7}, {5,10},{6,15},{7,20} };

	return WorldLenghtToMaxTries[MyHiddenWord.length()];
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))// if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) {
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::Ok;
	}
}

void FBullCowGame::Reset()
{
	const FString Hidden_Word = "planet"; // this must be an isigram

	MyHiddenWord = Hidden_Word;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

//Recive a VALID Guess, incriments turns and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); // assuming same length as guess


	for(int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		// comare letters agains the hidded word
		for (int32 GChar=0; GChar < WordLength; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[MHWChar] )
			{
				if (MHWChar == GChar) // if they're in the same place
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return  BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter word as isogramm
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen; // setup map

	for (auto Letter : Word) // for all kerrers of the world
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter] == true)
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
		}
	}
	
	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	// treat 0 and 1 letter word as isogramm
	if (Word.length() == 0) { return true; }

	for (auto Letter : Word) // for all kerrers of the world
	{
		if (!islower(Letter))
		{
			return false;
		}
	}

	return true;
}



void FBullCowGame::StartGame()
{
}

void FBullCowGame::DisplayHelp()
{
}

void FBullCowGame::GetInput()
{
}

bool FBullCowGame::WantRestart()
{
	return false;
}
