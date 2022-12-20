#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 26;

string randomWord(string[], int);
void availableLetters(char[], int);
bool guessCheck(char[], int, char, string);


int main() {
	srand(time(0));
	string word;
	bool correct;
	char guess;
	char letters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	string wordList[] = {"pint", "grape", "pig", "cream", "hog", "crab", "slime", "park", "piss", "clean"};
	char blanks[27] = {};
	string placehold[5] = {};
	int incorrect = 7;
	
	word = randomWord(wordList, 10);
	cout << word << endl;
	for(int i=0; i<word.length(); i++){
		blanks[i] = '-';
	}
	cout << "The word to guess has " << word.length() << " letters." << endl;

	while(incorrect>0){
		cout << "You have " << incorrect << " incorrect guesses remaining." << endl;
		string wordGuess = "";
		cout << "Available letters: ";
		availableLetters(letters, SIZE);
		for(int i=0; i<word.length(); i++){
			cout << blanks[i];
		}
		cout << endl << "Guess a letter:" << endl;

		cin >> guess;
		cin.ignore();

		correct = guessCheck(letters, SIZE, guess, word);
		if(correct == true){
			cout << "Correct guess!" << endl;
		}else{
			incorrect--;
			cout << "Incorrect..." << guess << " is not a letter in the word. You have " << incorrect << " incorrect guesses left." << endl;
		}

		for(int i=0; i<word.length(); i++){
			if(word.at(i) == guess){
				blanks[i] = guess;
				placehold[i] = guess;
			}
		}
		for(int i=0; i<word.length(); i++){
			wordGuess = wordGuess + placehold[i];
		}
		if(wordGuess == word){
			break;
		}		
	}
	if(incorrect != 0){
		cout << "Congrats! You guessed the word!" << endl;
	}else if(incorrect == 0){
		cout << "You lose!" << endl;
	}

	return 0;
}

void availableLetters(char arr[], int size) {
	// arr is a reference to the numbers array in main
	int i = 0;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
    cout << endl;
}

string randomWord(string arr[], int size){
    return arr[(rand() % (size))];
}

bool guessCheck(char arr[], int size, char guess, string word){
	int n = 0;
	for(int i=0; i<size; i++){
		if(arr[i] == guess){
			arr[i] = ' ';
		}
	}
	for(int i=0; i<word.length(); i++){
		if(guess == word.at(i)){
			n++;
		}
	}
	if(n==0){
		return false;
	}
	return true;
}
