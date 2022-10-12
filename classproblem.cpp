#include <iostream> // input/output(io)
#include <cstdlib> //import random number command
using namespace std; //allows us to type the following instead of line 5
// cout << "content";
// std::cout << "content";

int main(){
    int randNum, userNum, totalSum = 0;

    cout <<"Please enter an integer: ";
    cin >> userNum; //how many time roll dice
    for(int i=0; i<userNum; i++){
        randNum = (rand()%(6-1+1))+1; //rand num between 1 and 6
        cout << randNum << endl;
        totalSum += randNum;
    }


    return 0;
}