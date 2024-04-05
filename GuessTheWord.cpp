#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main() {
  // Word list
  vector<string> words = {"resistor", "capacitor", "coil", "computer", "transistor", "diode", "wire", "circuit", "motherboard", "programming"};

  // Randomly select a word
  srand(time(0)); // Seed random number generator
  int randomIndex = rand() % words.size();
  string targetWord = words[randomIndex];

  // Game variables
  int remainingGuesses = 12;
  string guessedWord(targetWord.size(), '-'); // Initialize guessed word with dashes

  // Game loop
  while (remainingGuesses > 0 && guessedWord != targetWord) {
    cout << "You have " << remainingGuesses << " guesses remaining." << endl;
    cout << "Current guess: " << guessedWord << endl;

    char guess;
    cout << "Guess a lowercase letter: ";
    cin >> guess;

    bool found = false;
    for (int i = 0; i < targetWord.size(); ++i) {
      if (targetWord[i] == guess) {
        guessedWord[i] = guess;
        found = true; // Mark a successful guess
      }
    }

    if (found) {
      cout << "Correct guess!" << endl;
    } else {
      remainingGuesses--;
      cout << "Incorrect guess. Try again." << endl;
    }
  }

  if (remainingGuesses > 0) {
    cout << "Congratulations! You guessed the word: " << targetWord << endl;
  } else {
    cout << "You ran out of guesses. The word was: " << targetWord << endl;
  }

  return 0;
}
