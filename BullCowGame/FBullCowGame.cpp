#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	
	const FString Hidden_Word = "planet";
	MyHiddenWord = Hidden_Word;

	MyCurrentTry = 1;
	
	return;
}

void FBullCowGame::Reset(int32 WordLength)
{
	return;
}
//Recive a VALID Guess, incriments turns and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	
	int32 length = MyHiddenWord.length();
	for(int32 i = 0; i < length; i++)
	{
		// comare letters agains the hidded word
		for (int32 j=0; j < length; j++)
		{
			if (MyHiddenWord[i] == Guess[j])
			{
				BullCowCount.Bulls++;
			}else
			{
				BullCowCount.Cows++;
			}
		}
	}

	return  BullCowCount;
}

int32 FBullCowGame::GetMaxTries()
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry;}

int32 FBullCowGame::GetMyTries() const {	return 0; }

bool FBullCowGame::IsGameWon()
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
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
