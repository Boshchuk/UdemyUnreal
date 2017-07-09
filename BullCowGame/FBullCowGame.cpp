#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { 	Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetMyTries() const { return 0; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString Hidden_Word = "ant";

	MyMaxTries = MAX_TRIES;
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
	
	int32 HiddenWordLength = MyHiddenWord.length();
	for(int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		// comare letters agains the hidded word
		for (int32 GChar=0; GChar < HiddenWordLength; GChar++)
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

	return  BullCowCount;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString) const
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
