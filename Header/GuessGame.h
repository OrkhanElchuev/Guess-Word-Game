#pragma once

// Include library
#include <string>

// Helpful variables for checking the validity of input and getting hidden access
enum EGuessStatus{
  	Invalid_Status,
	OK,
	Wrong_Length,
	NOT_Lowercase,
	Not_Isogram,
	Hidden_Access
};

// Class declaration
class GameGuess{
public:
    GameGuess(); // Constructor 
    
    	// Functions definition
	void Reset();
	int GetMaxTries() const;
	int GetCurrentTry() const;
	int GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(std::string) const;
	GameGuess SubmitValidGuess(std::string);
	// Variables initiation
	std::string MyHiddenWord;
	int order = 0;
	int letter = 0;
  
private: 
    //Variables definition
	int MyCurrentTry;
	bool bGameIsWon;
	bool IsLowerCase(std::string) const;
	bool IsIsogram(std::string) const;
};

  
    
