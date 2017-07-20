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

	return  BullCowCount;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString guess) const
{
	if (false)// if the guess isn't an isogram
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


		// return error
	//if the guess isn't all lowecase
		//return error
	// otherwise 
		//return ok

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
