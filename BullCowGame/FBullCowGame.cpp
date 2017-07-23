#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame() { 	Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetMyTries() const { return 0; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { 	return bGameIsWon; }

EGuessStatus FBullCowGame::CheckGuessValidity(FString guess) const
{
	if (!IsIsogram(guess))// if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) {
		return EGuessStatus::Not_Lowercase;
	}
	else if (guess.length != GetHiddenWordLength())
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
	constexpr int32 MAX_TRIES = 8;
	const FString Hidden_Word = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = Hidden_Word;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

void FBullCowGame::Reset(int32 WordLength)
{
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

	for (char Letter : Word) // for all kerrers of the world
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
