#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    string enter;
    int money; 
    int randNum;
    int randSum=0;
    int wager = 0;
    int wagerSum =0;
    int target=0;
    int die = 1;

    cout << "A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots. After the dice have come to rest, the sum of the spots on the two upward faces is calculated. If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw (called \"craps\"), the player loses (i.e. the \"house\" wins). If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's \"point.\" To win, you must continue rolling the dice until you \"make your point.\" The player loses by rolling a 7 before making the point." << endl;
    cout << "Press enter to play.";
    getline(cin, enter);
    if(enter == "n"){
        cout << "Goodbye! Thanks for playing." << endl;
        return 0;
    }

    cout << "What is your initial bank balance: ";
    cin >> money;
    while(money>=0){
            cout << "Your available balance is $" << money << endl;
            cout << "Please enter initial wager: ";
            cin >> wager;   
            randSum = 0;         
            while(wager >money || wager<0){
                wager = 0;
                cout << "That is not a valid wager" << endl;
                cout << "Please enter a wager: ";
                cin >> wager;
            }
            for(int i =0; i<2; i++){
                randNum = 0;
                randNum = (rand() % (6-1+1))+1;
                randSum+=randNum;
                cout << "die" << die << ": " << randNum << endl;
                die++;
            }
            money-=wager;
            wagerSum +=wager;
            cout << "The die rolled " << randSum << endl;
            if(randSum == 7 || randSum == 11){
                            cout << "You Win! Your available balance is $" << money << endl;
                            cout << "Press enter to play again or 'n' to exit." << endl;
                            money = money + (wagerSum*2);
                            cin.ignore();
                            getline(cin, enter); 
                            if(enter == "n"){
                            cout << "Goodbye! Thanks for playing." << endl;
                            randSum = 0;
                            wagerSum = 0;
                            return 0;
                        }
            }
            else if(randSum== 2|| randSum==3 || randSum== 12){
                cout << "You lose!\nPress enter to play again." << endl;
                            cin.ignore();
                            getline(cin, enter);   
            }
            else{
                cout << "Your point is " << randSum << endl;
                target = randSum;
                //cout << "Your available balance is $" << money << endl;
                cout << "Press enter to continue or 'n' to exit:" << endl;
                cin.ignore();
                getline(cin, enter);
                if(enter == "n"){
                    cout << "Goodbye! Thanks for playing." << endl;
                    return 0;
            }                
            while(true){
                        randSum = 0;
                        cout << "Your available balance is $" << money << endl;
                        cout << "Total wager so far: $" << wagerSum << endl;
                        cout << "Please enter a wager: ";
                        cin >> wager;
                        while(wager >money || wager<0){
                            wager = 0;
                            cout << "That is not a valid wager" << endl;
                            cout << "Please enter a wager: ";
                            cin >> wager;
                        }
                        money -=wager;
                        wagerSum += wager;
                        die = 1;
                        for(int i =0; i<2; i++){
                            randNum = 0;
                            randNum = (rand() % (6-1+1))+1;
                            randSum+=randNum;
                            cout << "die" << die << ": " << randNum << endl;
                            die++;
                        }
                        cout << "The die rolled " << randSum << endl;
                        if(randSum == target){
                            money=money+(wagerSum*2);
                            cout << "You Win! Your available balance is $" << money << endl;
                            cout << "Press enter to play again or 'n' to exit." << endl;
                            cin.ignore();
                            getline(cin, enter);
                            if(enter == "n"){
                                 cout << "Goodbye! Thanks for playing." << endl;
                                 return 0;
                            }
                            wagerSum=0;
                            break;
                        }
                        else if(randSum== 7 || randSum== 12){
                            if(money == 0){
                                cout << "You lose!\nYou are out of money" << endl;
                                return 0;
                            }
                            cout << "You lose!\nPress enter to play again or 'n' to exit." << endl;
                            cin.ignore();
                            getline(cin, enter);
                            if(enter == "n"){
                                 cout << "Goodbye! Thanks for playing." << endl;
                                 return 0;
                            }
                            break;
                        }
                        else{
                            cout << "You need to keep rolling to make your point (" << target << ")" << endl;
                            cout << "Press enter to continue or 'n' to exit:" << endl;
                            cin.ignore();
                            getline(cin, enter);
                            if(enter == "n"){
                                cout << "Goodbye! Thanks for playing." << endl;
                                return 0;
                            }      
                        }
                    
            }
        }
    }

    return 0;
}