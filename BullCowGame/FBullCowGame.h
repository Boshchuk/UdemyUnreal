/*The game logic(no view cide or direct user interaction)
The game is a simple guess thw word game base on MasterMind
*/

#pragma once
#include <string>

// to make syntax Unreal friendly
using FString = std::string;
using int32 = int;


struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	Ok,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
	//EmptyInput,
	//StringIsToHigh
};

class FBullCowGame
{
public:
	
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetMyTries() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void StartGame();
	void DisplayHelp();
	void GetInput();
	bool WantRestart();
	void Reset();

	// provide a methode for counting bulls and cows, and increasing try #
	FBullCowCount SubmitValidGuess(FString Guess);

private:
	// see constructor for initialization
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;


	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};