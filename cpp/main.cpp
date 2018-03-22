// Import libraries
#include <iostream>
#include <string>

// Import Header file
#include "GuessGame.h"

// Functions declaration
void PrintIntro();
void PlayGame();
void PrintGameSummary();
std::string GetValidGuess();
bool AskToPlayAgain();

GameGuess Game; // Creating class object

// The main function, where the program starts 
int main() {
  	bool bPlayAgain = false; // Set by default false to execute functions inside (do while structure) 
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
		Game.GetHiddenWordLength();
	} while (bPlayAgain);
	return 0;
}

// Introduction text in the game
void PrintIntro() {
	Game.Reset();
	std::cout << " \nWelcome to Guess The Word Game created by Orkhan Elchuev\n\n";
	std::cout << " Can you guess the " << Game.GetHiddenWordLength(); // Get the quantity of letters in the hidden word
	std::cout << " letter word I am thinking of?\n";
	std::cout << " The word doesnt have any repeating letter!\n";
	std::cout << " If you guess the order of letters in the hidden word, the number of >Order< will increase!\n";
	std::cout << " If you guess the letter from the hidden word, the number of >Letters< will increase!\n";
	std::cout << " You will have " << Game.GetMaxTries() << " tries to guess the word. GOOD LUCK!\n";
	std::cout << " Write <<show the word>> to reveal the word\n\n"; // Cheating phrase to unhide the word
	return;
}

// The game body
void PlayGame() {
	Game.Reset();  // Reset all the game stats
	// Get the maximum try for user according to the difficulty of the game
	int MaxTries = Game.GetMaxTries(); 
	// Iterate through the loop until the game is won or tries ends
	while (!Game.IsGameWon() && Game.GetCurrentTry() <= MaxTries) {
		std::string guess = GetValidGuess();
		GameGuess GameGuessCount = Game.SubmitValidGuess(guess);
		// Write the quantity of letters in the correct order
		std::cout << "Order = " << GameGuessCount.order; 
		// Write the quantity of letters which exists in the hidden word
		std::cout << "  Letters = " << GameGuessCount.letter << "\n\n";
	}
	// Printing the messages at the end of the game according to the game status
	PrintGameSummary();
	return;
}

// Suggest to start a new game
bool AskToPlayAgain() {
	std::cout << "Do you want to play again?(Enter y - yes, or n - no): ";
	std::string response = "";
	std::getline(std::cin, response);
	// If the first letter of your input is y it will"be recognized as "yes"
	return (response[0] == 'y') || (response[0] == 'Y');
}


// Some motivational phrases after each try
void MotivationPhrase(){
	int CurrentTry = Game.GetCurrentTry();
	if (CurrentTry == 1 || CurrentTry == 6) {
		std::cout << "Pretty cool!\n";
	}
	else if (CurrentTry == 2 || CurrentTry == 7) {
		std::cout << "Good!\n";
	}
	else if (CurrentTry == 3 || CurrentTry == 8) {
		std::cout << "Almost!\n";
	}
	else if (CurrentTry == 4 || CurrentTry == 9) {
		std::cout << "Great!\n";
	}
	else if (CurrentTry == 5 || CurrentTry == 10) {
		std::cout << "Incredible!\n";
	}
}

// Get the guess from the user and print it out
std::string GetValidGuess() {
	std::string guess = " ";
	EGuessStatus Status = EGuessStatus::Invalid_Status; // Set current status of input as invalid
	do {
		int CurrentTry = Game.GetCurrentTry(); // Get the number of current try 
		std::cout << "Try (" << CurrentTry << " of " << Game.GetMaxTries() << ") Please, enter your guess: ";
		std::getline(std::cin, guess); // Get an input from the user
		// Special password for revealing the hidden word
		if (guess == "show the word") { 
			std::cout << Game.MyHiddenWord << std::endl;
			break;
		}
		// Checking validity of answer and printing different error messages
		Status = Game.CheckGuessValidity(guess);
		switch (Status) {
		case EGuessStatus::Not_Isogram: // Check for the repetition of letters
			std::cout << "Please enter a word without repeating letters!\n\n";
			break;
		case EGuessStatus::Wrong_Length: // Check for the proper word length 
			std::cout << "Please Enter a " << Game.GetHiddenWordLength() << " letter word!\n\n";
			break;
		case EGuessStatus::NOT_Lowercase: // Check if all the letters are lowercase
			std::cout << "Please Enter all lowercase letters!\n\n";
			break;
		default: 
			MotivationPhrase(); // Printing Motivational phrases
			break;
		}
	} while (Status != EGuessStatus::OK);
	return guess;
}

// Print the game summary
void PrintGameSummary() {
	// Check if the game is won or not. Print corresponding messages according to the game status
	if (Game.IsGameWon()) { 
		std::cout << "WELL DONE - YOU WIN!\n";
	}
	else {
		std::cout << "Better luck next time!\n";
	}
}
