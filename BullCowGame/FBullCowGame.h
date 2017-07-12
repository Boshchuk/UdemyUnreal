#pragma once

#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
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
	void Reset(int32 WordLength); // TODO: make more reach return

	// provide a methode for counting bulls and cows, and increasing try #
	FBullCowCount SubmitGuess(FString Guess);
private:
	// see constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};