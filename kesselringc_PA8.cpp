#include <iostream>
#include <ctime>

using namespace std;

const int NUM_ROWS = 10;
const int NUM_COLS = 10;

// lets store ship info in 3 parallel arrays
const string shipNames[] = {"carrier", "battleship", "cruiser", "submarine", "destroyer"};
const char shipSymbols[] = {'c', 'b', 'r', 's', 'd'};
// task: one more parallel array for ship sizes
const int shipSizes[] = {5, 4, 3, 3, 2};

void fillArray(char[NUM_ROWS][NUM_COLS], int, int);
void printArray(const char[NUM_ROWS][NUM_COLS], int, int);
void placeShip(const string[], const int[], const char[], char[][10]);
void randomPlaceShip(const string[], const int[], const char[], char[][10]);
void opponentPlaceShip(const string[], const int[], const char[], char[][10]);
bool isWinner(char[]);
bool checkShot(int, int, char[][10], char[][10]);
int isSunkShip(char[][10], const char[]);
void opponentShot(char[][10]);
void displaySunkShip(char[][10]);


int main() {
	srand(time(0));
	string choice;
	int x, y, playerSink, computerSink, whoFirst;
	bool winner = false;
	char grid1[NUM_ROWS][NUM_COLS]; // 10 x 10 chars
	char grid2[NUM_ROWS][NUM_COLS]; // opponents board
	char gridBlank[NUM_ROWS][NUM_COLS];
	bool check = true; 
	
	fillArray(grid1, NUM_ROWS, NUM_COLS);
	fillArray(grid2, NUM_ROWS, NUM_COLS);
	fillArray(gridBlank, NUM_ROWS, NUM_COLS);
	opponentPlaceShip(shipNames, shipSizes, shipSymbols, grid2);

	// task: printArray(twoD, numRows, numCols);
	// that prints the two d array as a grid
	//printArray(grid1, NUM_ROWS, NUM_COLS);
	cout << "Press r to place ships randomly or t for manual" << endl;
	cin >> choice;
	if(choice == "r"){
		randomPlaceShip(shipNames, shipSizes, shipSymbols, grid1);
	}
	else if(choice == "t"){
		placeShip(shipNames, shipSizes, shipSymbols, grid1);
	}	
	cout << "Your board: \n";
	printArray(grid1, NUM_ROWS, NUM_COLS);
	cout << "Opponents board for testing: "<<endl;
	printArray(grid2, NUM_ROWS, NUM_COLS);
		
	whoFirst = (rand() % (1));
	while(winner == false){
		if(whoFirst == 1){
			while(true){
				cout  << "Enter a coordinate for where you want to shoot: two integers 0-9." << endl;
				cin >> x;
				cin >> y;
				check = checkShot(y,x, grid2, gridBlank);
				if(check == true){
					break;
				}
			}
			playerSink = isSunkShip(grid2, shipSymbols);
			computerSink = isSunkShip(grid1, shipSymbols);
			displaySunkShip(grid2);
			opponentShot(grid1);
		}
		else{
			opponentShot(grid1);
			while(true){
				cout  << "Enter a coordinate for where you want to shoot: two integers 0-9." << endl;
				cin >> x;
				cin >> y;
				check = checkShot(y,x, grid2, gridBlank);
				if(check == true){
					break;
				}
			}
			playerSink = isSunkShip(grid2, shipSymbols);
			computerSink = isSunkShip(grid1, shipSymbols);
			displaySunkShip(grid2);
		}
		cout << "\nYour board:\n";
		printArray(grid1, NUM_ROWS, NUM_COLS);
		cout << "Attacks on opponent: \n";
		printArray(gridBlank, NUM_ROWS, NUM_COLS);
		if(playerSink == 0){
			cout << "You win!" << endl;
			break;
		}
		else if(computerSink == 0){
			cout << "You lose! The computer wins." << endl;
			break;
		}
	}
	// task: randomlyPlaceShips(p1SolutionGrid);
	// randomlyPlaceShips(p2SolutionGrid);
	// in this function, something like ...
	// for each ship i in our parallel arrays of ships
	//		call randomlyPlaceSingleShip(grid, shipNamees[i], shipSymbols[i], shipSizes[i]);
	

	return 0;
}

void printArray(const char arr[NUM_ROWS][NUM_COLS], int rows, int cols) {
	int i, j, count = 0;
	
	cout << "  0 1 2 3 4 5 6 7 8 9\n";
	for (i = 0; i < rows; i++) {
		cout << count << " ";
		count++;
		for (j = 0; j < cols; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void fillArray(char arr[NUM_ROWS][NUM_COLS], int rows, int cols) {
	int i, j;
	
	// outer loop iterates over each row
	for (i = 0; i < rows; i++) {
		// inner loop iterates over int in arr[i] (row)
		for (j = 0; j < cols; j++) {
			arr[i][j] = '-';
		}
	}
}

void placeShip(const string shipNames[], const int shipSizes[], const char shipSymbols[], char grid[][10]){
	int x,y;
	for(int i = 0; i<5; i++){
		cout << "enter " << shipSizes[i] << " cells to place the " << shipNames[i] << " across. Don't overlap ships!!\n";
		for(int j=0; j<shipSizes[i]; j++){
			cin >> x;
			cin >> y;
			if(grid[x][y] == '-'){
				grid[x][y] = shipSymbols[i];
			}
			else{
				cout << "Ships cannot overlap, re-enter" << endl;
				j--;
			}
		}
	printArray(grid, 10, 10);
	}
}

void randomPlaceShip(const string shipNames[], const int shipSizes[], const char shipSymbols[], char grid[][10]){
	for(int i=2; i<7; i++){
		grid[i][0] = shipSymbols[0];
	}
	for(int i=0; i<4; i++){
		grid[0][i] = shipSymbols[1];
	}
	for(int i=6; i<9; i++){
		grid[6][i] = shipSymbols[2];
	}
	for(int i=3; i<6; i++){
		grid[i][9] = shipSymbols[3];
	}
	for(int i=1; i<3; i++){
		grid[i][6] = shipSymbols[4];
	}
	
}

void opponentPlaceShip(const string shipNames[], const int shipSizes[], const char shipSymbols[], char grid[][10]){
	for(int i=1; i<6; i++){
		grid[i][9] = shipSymbols[0];
	}
	for(int i=2; i<6; i++){
		grid[9][i] = shipSymbols[1];
	}
	for(int i=2; i<5; i++){
		grid[2][i] = shipSymbols[2];
	}
	for(int i=2; i<5; i++){
		grid[i][0] = shipSymbols[3];
	}
	for(int i=5; i<7; i++){
		grid[i][4] = shipSymbols[4];
	}
}

bool isWinner(char grid[][10]){
	int count = 0;
	for(int i=0; i<10; i++){
		for (int j = 0; j < 10; j++) {
			if(grid[i][j] == '*'){
				count++;
			}
		}
	}
	if(count == 17){
		return false;
	}else{
		return true;
	}
}

bool checkShot(int x, int y, char grid[][10], char blank[][10]){
	if(blank[x][y] == '*' || blank[x][y] == 'm'){
		cout << "You already shot there, try again.\n";
		return false;
	}
	else if(grid[x][y] == '-'){
		cout << "Miss..." << endl;
		blank[x][y] = 'm';
		return true;
	}else{
		cout << "Hit!" << endl;
		blank[x][y] = '*';
		grid[x][y] = '*';
		return true;
	}
}

int isSunkShip(char grid[][10], const char symbols[]){
	int count = 0, c=0, b=0, r=0, s=0, d=0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if(grid[i][j] == 'c' || grid[i][j] == 'b' ||grid[i][j] == 'r' ||grid[i][j] == 's' ||grid[i][j] == 'd'){
				count++;
			}
		}
	}
	return count;
}
void displaySunkShip(char grid[][10]){
	int count = 0, c=5, b=4, r=3, s=3, d=2;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if(grid[i][j] == 'c' || grid[i][j] == 'b' ||grid[i][j] == 'r' ||grid[i][j] == 's' ||grid[i][j] == 'd'){
				count++;
				if(grid[i][j] == 'c'){
					c--;
				}else if(grid[i][j] == 'b'){
					b--;
				}else if(grid[i][j] == 'r'){
					r--;
				}else if(grid[i][j] == 's'){
					s--;
				}else if(grid[i][j] == 'd'){
					d--;
				}
			}
		}
	}
	if(c==5){
		cout << "Carrier is sunk.\n";
	}
	if(b==4){
		cout << "Battleship is sunk.\n";
	}
	if(r==3){
		cout << "Cruiser is sunk.\n";
	}
	if(s==3){
		cout << "Submarine is sunk.\n";
	}
	if(d==2){
		cout << "Destroyer is sunk.\n";
	}
				
}

void opponentShot(char grid[][10]){
	srand(time(0));
	int x = (rand() % (10));
	int y = (rand() % (10));
	if(grid[x][y] == '-'){
		cout << "The opponent shot at " << x << " " << y << ", and missed!"<<endl;
		grid[x][y] = 'm';
	}else if(grid[x][y] == '*' || grid[x][y] == 'm'){
		opponentShot(grid);
	}else if(grid[x][y] == 'c' || grid[x][y] == 'b' || grid[x][y] == 'r' || grid[x][y] == 's' || grid[x][y] == 'd'){
		grid[x][y] = '*';
		cout << "The opponent shot at " << x << " " << y << ", and hit..."<<endl;
	}
}