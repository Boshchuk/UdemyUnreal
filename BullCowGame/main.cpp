/* This is the console executable, that create game and run it
 */

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();

FString GetGuess();
void PrintInput(FString Guess);

FBullCowGame BCGame; // instanstiate a game


int main()
{
	auto bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	
	
	return 0;
}


void PrintIntro()
{
	// introduce the game
	int32 WORD_LENGTH = BCGame.GetHiddenWordLength();

	std::cout << "Welcome to bulls and cows, a fun word game.\n";
	std::cout << "Can you guess the" << WORD_LENGTH;
	std::cout << " letter isogramm I'm thinking on?\n";
	std::cout << std::endl;

	return;
}

// loop continualy until get valid guess
FString GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		FString Guess = "";

		int32 currentTry = BCGame.GetCurrentTry();

		std::cout << "Try " << currentTry << ". Enter you guess: ";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " + BCGame.GetHiddenWordLength + "letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all letters in lower case.\n";
			break;
		default:
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::Ok); // keep looping 
}


void PrintInput(FString Guess)
{
	std::cout << "Your guess was: ";
	std::cout << Guess << std::endl;
	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you watn to play again (y/n)? ";
	FString Response = "";
	getline(std::cin, Response);

	char firstLetter = Response[0];

	return (firstLetter =='y') || (firstLetter =='Y');
}


void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	
	for (int32 i = 0; i < MaxTries; i++) // Todo: change from for to while loop
	{
		FString Guess = GetValidGuess(); 

		// submit valid guess to the game, and recieve counts
		FBullCowCount bull_cow_count = BCGame.SubmitGuess(Guess);

		// print numbe of bulls and cows

		std::cout << "Bulls = " << bull_cow_count.Bulls;
		std::cout << ". Cows = " << bull_cow_count.Cows << "\n\n";

		//PrintInput(Guess);
	}

	// TODO: summarise game
}