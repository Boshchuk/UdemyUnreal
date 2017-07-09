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

FString GetGuess() {
	FString Guess = "";

	int32 currentTry = BCGame.GetCurrentTry();

	std::cout <<"Try " << currentTry << ". Enter you guess: ";
	getline(std::cin, Guess);

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
	// Todo: change from for to while loop
	for (int32 i = 0; i < MaxTries; i++)
	{
		FString Guess = GetGuess(); // TODO make loop checking valid

		// submit valid guess to the game, and recieve counts
		FBullCowCount bull_cow_count = BCGame.SubmitGuess(Guess);

		// print numbe of bulls and cows

		std::cout << "Bulls = " << bull_cow_count.Bulls;
		std::cout << ". Cows = " << bull_cow_count.Cows << std::endl;

		//PrintInput(Guess);
	}

	// TODO: summarise game
}