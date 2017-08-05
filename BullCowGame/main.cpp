/* This is the console executable, that create game and run it
 */

#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// to make syntax Unreal friendly
using FString = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();

FString GetValidGuess();
void PrintInput(FString Guess);
void PrintGameSummary();



FBullCowGame BCGame; // instanstiate a new game, which we re-use across plays


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

	std::cout << "\n\nWelcome to bulls and cows, a fun word game.\n";
	std::cout << "Can you guess the" << WORD_LENGTH;
	std::cout << " letter isogramm I'm thinking on?\n";
	std::cout << std::endl;

	return;
}

// plats a single game to complitions
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FString Guess = GetValidGuess();

		// submit valid guess to the game, and recieve counts
		FBullCowCount bull_cow_count = BCGame.SubmitValidGuess(Guess);

		// print number of bulls and cows

		std::cout << "Bulls = " << bull_cow_count.Bulls;
		std::cout << ". Cows = " << bull_cow_count.Cows << "\n\n";

	}

	PrintGameSummary();

	return;
}

// loop continualy until get valid guess
FString GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FString Guess = "";
	do {
		int32 currentTry = BCGame.GetCurrentTry();

		std::cout << "Try " << currentTry << " of " << BCGame.GetMaxTries();
		std::cout << ". Enter you guess: ";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << "letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all letters in lower case.\n\n";
			break;
		default:
			// assume the Guess is valid;
			break;
		}
		
	} while (Status != EGuessStatus::Ok); // keep looping 

	return Guess;
}


void PrintInput(FString Guess)
{
	std::cout << "Your guess was: ";
	std::cout << Guess << std::endl;
	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with same hidden word (y/n)? ";
	FString Response = "";
	getline(std::cin, Response);

	char firstLetter = Response[0];

	return (firstLetter =='y') || (firstLetter =='Y');
}

void PrintGameSummary() 
{
	if (BCGame.IsGameWon()) 
	{
		std::cout << "\n You won!\n";
	}
	else 
	{
		std::cout << "Better kuck next time!\n";
	}

	return;
};

