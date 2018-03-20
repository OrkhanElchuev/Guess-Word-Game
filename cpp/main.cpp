// Import libraries
#include <iostream>
#include <string>

// Functions declaration
void PrintIntro();
void PlayGame();
void PrintGameSummary();
std::string GetValidGuess();
bool AskToPlayAgain();

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
	std::cout << " Write <<show the word>> to reveal the word"; // Cheating phrase to unhide the word
	return;
}
