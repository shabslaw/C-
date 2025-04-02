#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void PrintMessage(string message, bool printTop = true, bool printBottom = true) {
    if (printTop) {
        cout << "+-----------------------------------+" << endl;
        cout << "|";
    }
    else {
        cout << "|";
    }

    bool front = true;
    for (int i = message.length(); i < 35; i++) {
        message = front ? " " + message : message + " ";
        front = !front;
    }

    cout << message;

    if (printBottom) {
        cout << "|" << endl;
        cout << "+-----------------------------------+" << endl;
    }
    else {
        cout << "|" << endl;
    }
}

void DrawHangman(int guessCount = 0) {
    if (guessCount >= 1) PrintMessage("|", false, false);
    else PrintMessage(" ", false, false);

    if (guessCount >= 2) PrintMessage("|", false, false);
    else PrintMessage(" ", false, false);

    if (guessCount >= 3) PrintMessage("O", false, false);
    else PrintMessage(" ", false, false);

    if (guessCount == 4) PrintMessage("/  ", false, false);
    else if (guessCount == 5) PrintMessage("/| ", false, false);
    else if (guessCount >= 6) PrintMessage("/|\\", false, false);
    else PrintMessage(" ", false, false);

    if (guessCount >= 7) PrintMessage("|", false, false);
    else PrintMessage(" ", false, false);

    if (guessCount == 8) PrintMessage("/  ", false, false);
    else if (guessCount >= 9) PrintMessage("/ \\", false, false);
    else PrintMessage(" ", false, false);
}

void PrintLetters(string input, char from, char to) {
    string s;
    for (char i = from; i <= to; i++) {
        if (input.find(toupper(i)) == string::npos && input.find(tolower(i)) == string::npos) {
            s += i;
            s += " ";
        }
        else {
            s += "  ";
        }
    }
    PrintMessage(s, false, false);
}

void PrintAvailableLetters(string taken) {
    PrintMessage("Available Letters");
    PrintLetters(taken, 'A', 'M');
    PrintLetters(taken, 'N', 'Z');
}

bool PrintWordAndCheckWin(string word, string guessed) {
    bool won = true;
    string s;
    for (char c : word) {
        if (guessed.find(toupper(c)) == string::npos && guessed.find(tolower(c)) == string::npos) {
            won = false;
            s += "_ ";
        }
        else {
            s += c;
            s += " ";
        }
    }
    PrintMessage(s, false);
    return won;
}

string LoadRandomWord(string path) {
    vector<string> words;
    ifstream file(path);
    
    if (file.is_open()) {
        string word;
        while (getline(file, word)) {
            if (!word.empty()) {
                words.push_back(word);
            }
        }
        file.close();
    }
    
    // If file couldn't be opened or is empty, use default words
    if (words.empty()) {
        words = {"HANGMAN", "PROGRAMMING", "COMPUTER", "DEVELOPER", "CODING"};
    }
    
    return words[rand() % words.size()];
}

int CountWrongGuesses(string word, string guessed) {
    int errors = 0;
    for (char c : guessed) {
        if (word.find(toupper(c)) == string::npos && word.find(tolower(c)) == string::npos) {
            errors++;
        }
    }
    return errors;
}

int main() {
    srand(time(0));
    string guesses;
    string wordToGuess = LoadRandomWord("words.txt");
    int tries = 0;
    bool win = false;

    // Convert word to uppercase for consistency
    transform(wordToGuess.begin(), wordToGuess.end(), wordToGuess.begin(), ::toupper);

    do {
        system("cls");  // Use "clear" if on Linux/Mac
        PrintMessage("HANGMAN");
        DrawHangman(tries);
        PrintAvailableLetters(guesses);
        PrintMessage("Guess the Word");
        win = PrintWordAndCheckWin(wordToGuess, guesses);

        if (win) break;

        char x;
        cout << ">"; 
        cin >> x;
        x = toupper(x);  // Convert to uppercase

        if (isalpha(x) && guesses.find(x) == string::npos) {
            guesses += x;
        }

        tries = CountWrongGuesses(wordToGuess, guesses);

    } while (tries < 10);

    if (win) {
        PrintMessage("YOU WON!");
    }
    else {
        PrintMessage("GAME OVER!");
        PrintMessage("The word was: " + wordToGuess);
    }

    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get();
    return 0;
}