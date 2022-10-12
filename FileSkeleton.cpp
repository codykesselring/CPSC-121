#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile; // for reading from a file
	ofstream outputFile; // for writing to a file
    
    double counter = 0, total = 0;
    int num;
    // transactions.txt is a file in the same directory as this .cpp file
	inputFile.open("numbers.txt");

	// the avg_.txt file wnumbers.txt will be created
	outputFile.open("avg_numbers");

    // Verifying the inputFile opens, lets the user know
    if (inputFile.fail()) {
		cout << "Error opening input file. Exiting program." << endl;
		exit(-1);
	}
    else {
        cout << "Input file opens successfully" << endl;
    }
	
    // Verifying the outputFile opens, lets the user know
	if (!outputFile.is_open()) {
		cout << "Error opening output file. Exiting program." << endl;
		exit(-1);
	}
    else {
        cout << "Output file opens successfully" << endl;
    }

    // this is where file manipulation happens
    while(!inputFile.eof()){
        inputFile >> num;
        counter+=1;
        total+=num;
    }
    outputFile << "the average of these numbers is " << total/counter;
 
    // Closing files 
    inputFile.close();
    outputFile.close();

    return 0;
}