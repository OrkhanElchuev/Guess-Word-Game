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
	std::string arrayOfWords[] = { " ","fly","planet","drug","calm","done","crazy","blow","cow","bring", "slap",
		"plant","print","frog","old","great","god","king","close","grade","mark","open","mango","image","mother","father","adult",
		"crap","line","form","fry","son","nose","tag","yard","year","kid",
		"magic","girl","boy","lemon","water","melon","type","pause" };
	HIDDEN_WORD = arrayOfWords[WordRandomNumber];
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false; 
	return;
}
// Difficulty setup according to the lenght of hidden word 
int GameGuess::GetMaxTries() const {
	// {x, y}  x for number of letters in the word, y is for number of given tries to guess
 	std::map<int, int>WordLengthToMaxTries{ { 3,7 },{ 4,8 },{ 5,9 },{ 6,10 } }; 
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

int GameGuess::GetCurrentTry() const { return MyCurrentTry; }
int GameGuess::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool GameGuess::IsGameWon() const { return bGameIsWon; }
