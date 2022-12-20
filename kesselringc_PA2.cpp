#include <iostream> // input/output(io)

using namespace std; //allows us to type the following instead of line 5
// cout << "content";
// std::cout << "content";

int main(){
    float correct = 0;
    int playerCount;
    string releaseDate;
    bool yone;
    int pentaKill;
    string skinCount;
    bool lux;
    bool worlds;
    int skt;
    bool fizz;
    string rank;
    bool yes = 0;

    cout << "Welcome to the League of Legends quiz!\n 1) How many players are in one match at a time? \nEnter an integer: ";
    
    cin >> playerCount;
    if(playerCount == 10){
        cout << "Correct!" << endl;
        correct++;
    }else{
        cout << "Incorrect :(\nThe correct answer is 10."<< endl;
    }

    cout << "2) When was the League of Legends release date? Please enter a character a-e.\na) October 15,2009 \nb) October 27, 2009 \nc) October 16, 2009 \nd) November 25, 2009 \ne) November 28, 2009" << endl;
    cin >> releaseDate;
    if(releaseDate == "b"){
        cout << "Correct!" << endl;
        correct++;
    }else{
        cout<<"Incorrect :(\nThe correct answer is b." << endl;
    }

    cout << "3) True or false: Yone is Yasuo's brother. Type 1 for true or 0 for false." << endl;
    cin >> yone;
    if(yone == 1){
        cout << "Correct!" << endl;
        correct++;
    }else{
        cout << "Incorrect :(\nThe correct answer is true." << endl;
    }

    cout << "4) How many kills does one player need in a short time for a \"Penta Kill\"? \nEnter an integer: ";
    cin >> pentaKill;
    if(pentaKill == 5){
        cout << "Correct!" << endl;
        correct++;
    }else{
        cout<<"Incorrect :(\n The correct answer is 5." << endl;
    }

    cout << "5) How many additional skins does the champion, \"Sylas\" have? Enter a character a-e. \na) 1\nb) 2\nc) 3\nd) 4\ne) 5" << endl;
    cin >> skinCount;
    if(skinCount == "b"){
        cout << "Correct!" << endl;
        correct++;
    }else{
        cout << "Incorrect :(\nThe correct answer is b." << endl;
    }

    cout << "6) Lux is considered the lady of darkness, true or false? Enter 1 for true or 0 for false." << endl;
    cin >> lux;
    if(lux==0){
        cout << "Correct!" << endl;
        correct++;
    }else{
        cout << "Incorrect. She is actually the Lady of Luminosity." << endl;
    }

    cout << "7) The professional team, Samsung Galaxy won the World Championship against SK Telecom in 2016, true or false?\nEnter 1 for true or 0 for false." <<endl;
    cin >> worlds;
    if(worlds == 0){
        cout << "Correct!" << endl;
        correct++;
    }else{
        cout << "Incorrect, the answer is false, SKT won the 2016 World Championship" << endl;
    }

    cout << "8) How many World Championships have SK Telecom participated in? \nEnter an integer: ";
    cin >> skt;
    if(skt == 3){
        cout << "Correct!" << endl;
        correct++;
    }else{
        cout << "Incorrect... the correct answer is 3." << endl;
    }

    cout << "9) The champion, Fizz, has a pet shark, true or false? Enter 0 for false and 1 for true." << endl;
    cin  >> fizz;
    if(fizz == 1){
        cout << "Correct!" << endl;
        correct++;
    }else{
        cout << "Incorrect, the correct answer is true." << endl;

    }

    cout << "10) What's the highest rank in the game. Enter a chacter a-e. \na) Bronze\nb) Diamond\nc) Platinum\nd) Challenger\ne) Master" << endl;
    cin >> rank;
    if(rank == "d"){
        cout << "Correct!" << endl;
        correct++;
    }else{
        cout << "Incorrect. The correct answer is d) Challenger." << endl;
    }

    if(correct <= 3){
        cout << "You got " << correct << "/10 correct!\nYou fucking suck." << endl;
    }else if(correct>3 && correct<7){
        cout << "You got " << correct << "/10 correct!\nYou're pretty knowledgable, but you could do better." << endl;
    }else{
        cout << "You got " << correct << "/10 correct!\nYou know your stuff! Go outside and touch some grass now." << endl;
    }
    
    return 0;
}