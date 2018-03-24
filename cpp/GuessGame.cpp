#pragma once

// Including header file
#include "GuessGame.h"

// Including libraries
#include<map>
#include<ctime>
#include<cstdlib>

GameGuess::GameGuess() { Reset(); }

// Set all the hidden word to one of the words in the array
void GameGuess::Reset() 
{
	MyCurrentTry = 1;
	srand(time(0));
	int WordRandomNumber = 0;
	// Generate a random number for array of words 
  	WordRandomNumber = 1 + (rand() % 44);
	std::string HIDDEN_WORD = "";
	// Array of the hidden words
	std::string arrayOfWords[] = { " ","fly","planet","drug","calm","done","crazy","blow","cow","bring","slap",
		"plant","print","frog","old","great","god","king","close","grade","mark","open","mango","image","mother","father","adult",
		"soul","line","form","fry","son","nose","tag","yard","year","kid",
		"magic","girl","boy","lemon","water","melon","type","pause" };
	HIDDEN_WORD = arrayOfWords[WordRandomNumber];
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false; 
	return;
}

// Difficulty setup according to the length of hidden word 
int GameGuess::GetMaxTries() const {
	// {x, y}  x for number of letters in the word, y is for number of given tries to guess
 	std::map<int, int>WordLengthToMaxTries{ { 3,7 },{ 4,8 },{ 5,9 },{ 6,10 } }; 
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

int GameGuess::GetCurrentTry() const { return MyCurrentTry; }
int GameGuess::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool GameGuess::IsGameWon() const { return bGameIsWon; }

// Function for checking whether the input is lowercase
bool GameGuess::IsLowerCase(std::string Word) const
{
	for (auto Letter : Word) {
		if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}

// Check whether the input has repeating letters
bool GameGuess::IsIsogram(std::string Word) const{
	std::map<char, bool> LetterSeen; // Set up the map
	for (auto Letter : Word) // For all letters of the word
	{
		Letter = tolower(Letter); 
		if (LetterSeen[Letter]) { // If the letter is in the map
			return false; // Word is not an isogram 
		}
		else {
			LetterSeen[Letter] = true; // Add the letter to the map
		}
	}
	return true; 
}

// Function for increasing "order" and "letter" values and submitting the guess
GameGuess GameGuess::SubmitValidGuess(std::string guess){
	MyCurrentTry++;  // Get the current value of try
	GameGuess GameGuessCount;
	int WordLength = MyHiddenWord.length();
	// Loop through all the tries
	for (int MHWChar = 0; MHWChar < WordLength; MHWChar++) {   
		// Loop  through the word length 
		for (int GChar = 0; GChar < WordLength; GChar++) {
			// Check the validity of input
			if (guess[GChar] == MyHiddenWord[MHWChar]) {  
				if (MHWChar == GChar) {
					GameGuessCount.order++; 
				}
				else {
					GameGuessCount.letter++;
				}
			}
		}
	}
	if (GameGuessCount.order == WordLength) {
		bGameIsWon = true;
	} else {
		bGameIsWon = false;
	}
	return GameGuessCount;
}

// Validity check for the input: isogram, lowercase, length.
EGuessStatus GameGuess::CheckGuessValidity(std::string Guess) const { 
	if (!IsIsogram(Guess)) { // If the guess has repeating letters (not isogram)
		return EGuessStatus::Not_Isogram;
	}
	if (!IsLowerCase(Guess)) {
		return EGuessStatus::NOT_Lowercase; // If the word has upper case letter
	}
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length; // Number of letters in the input is incorrect
	else {
		return EGuessStatus::OK; // If everything is fine
	}
}
