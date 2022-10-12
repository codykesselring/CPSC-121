#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
	string userName;
	string userFrom;
	string dreamCar;
	int yearBorn;
	int carPrice;
	float interestRate;
	int loanLength;
	float mpg;
	
	cout << "What is your name?" << endl;
	//cin >> userName; // reads characters in until it reaches whitespace
	// whitespace: spaces, newlines, tabs
	getline(cin, userName);
	cout << "Hi there, it is nice to meet you " << userName << "." << endl; 
	
	cout << "Where are you from? " << endl;
	getline(cin, userFrom);
	cout <<userFrom<< " sounds like a beautiful place!" << endl;


	cout <<"What year were you born in?" << endl;
	cin >> yearBorn;
	cout << "You are " << (2022 - yearBorn) << " years old that makes you " << ((2022-yearBorn)/2.0) << " times older than me, I'm 2 years old." << endl;
	
	cin.ignore(); //to flush newline out of previous cin

	cout << "What is your dream car?" << endl;
	getline(cin,dreamCar);

	cout << "How many miles per gallon does your dream car have?" << endl;
	cin >> mpg;
	if(mpg>=34.1){
		cout << "That's a great MPG, it exceeds the desired 34.1!" << endl;
	}else{
		cout << "That's a poor MPG that is less than the desired MPG of 34.1" << endl;
	}

	
	cout << "I have always wanted a " << dreamCar << " as well. How much does a " << dreamCar << " cost? " << endl;
	cin >> carPrice;
	cout << "Gee that's spendy! What is a reasonable yearly interest rate on a beautiful car like that?" << endl;
	cin >> interestRate;
	cout << "if you had to take out a loan to buy the " << dreamCar << ", how many years would you take the loan out for?" << endl;
	cin >> loanLength;
	
	float r = (interestRate/100.0)/12.0;
	float n = pow((1.0+r) , -12.0*loanLength);
	float monthlyInterest = (carPrice*r)/(1.0-n);
	
	cout << "if you bought the " << dreamCar << ", you would have a monthly payment of $" << monthlyInterest << ". That's a total of $" << (monthlyInterest*12)*loanLength << "!" <<endl;
	cout <<  "Hope you enjoy, " << userName << ", I gotta go!" <<endl;
	return 0;
}