#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	// task: open gainesville_roadtrip.txt for reading
	// check that you successfully opened file
	ifstream inputFile;
	ofstream outputFile;
	string line;
	int meters, days, meterSum = 0, waySum = 0, daySum = 0, longDays = 0, counter = 0;
	double largestMeter, avgDist = 0.0, avgDays = 0.0;
	string meterString, daysString, waypoint, newline, previous, longPrev, longWay, dayWay;
	
	inputFile.open("gainesville_roadtrip.txt");
	outputFile.open("roadtrip_stats.txt");
	if (inputFile.is_open()) {
		cout << "Successfully opened input file" << endl;
	}
	else {
		cout << "Failed to open input file" << endl;
		exit(-1);
	}
	if (!outputFile.is_open()) {
		cout << "Error opening output file. Exiting program." << endl;
		exit(-1);
	}
    else {
        cout << "Output file opens successfully" << endl;
    }
	
	// process
	// there is only one origin the file
	// read it before the loop
	
	// task: read in each line of the file using getline()
	// print out the line to the console

	cout << "Welcome to the road trip analyzer program!\nRoadtrip origin, destination, waypoints, distance between waypoints in\nmeters, and number of days spent at each waypoint will be read in from a\nfile.\nThe program write to an output file the distance in miles between each\nwaypoint on the trip and statistics about the trip. Enjoy!\n\nReading in road trip stop information from gainesville_roadtrip.txt..." << endl;
	getline(inputFile, line);
	//outputFile << line;
	previous = line;
	cout << "Origin: " << line << endl;
	getline(inputFile, newline);
	while (!inputFile.eof()) {
		// hint: currently each iteration reads one line
		// change it so each iteration reads on waypoint triple
		// meters (int), waypoint name (string), days (int)
		//getline(inputFile, meterString);
		//meters = stoi(meterString);
		
		inputFile >> meters;
		meterSum += meters;
		getline(inputFile, newline);
		getline(inputFile, waypoint);
		waySum++;
		cout << "Processing waypoint " << waypoint;
		if(!inputFile.eof()){
			//getline(inputFile, daysString);
			//days = stoi(daysString);
			inputFile >> days;
			getline(inputFile, newline);
			daySum += days;
			cout << " " << days << " days" << endl;
		}
		getline(inputFile, newline);
	
		outputFile << previous <<  " to " << waypoint << ": " << meters/1609.34 << " miles" << endl;
		previous = waypoint;
		if(largestMeter<meters){
			largestMeter = meters;
			longWay = waypoint;
			longPrev = previous;
		}
		if(longDays<days){
			longDays = days;
			dayWay = waypoint;
		}
		avgDays += days;
		avgDist += meters;
		counter++;
	}
	outputFile << "\n**Roadtrip Stats**" << endl;
	outputFile << "Number of waypoints on roadtrip: "<< waySum << "\nNumber of days on roadtrip: " << daySum << "\nTotal miles traveled on roadtrip: " << meterSum/1609.34 << endl;
	outputFile << "Longest roadtrip distance between waypoints is " << longPrev << "to " << longWay << ": " << largestMeter/1609.34 << " miles" << endl;
	outputFile << "Longest roadtrip days at one waypoint is " << dayWay << " at " << longDays << " days" << endl;
	outputFile << "Average roadtrip distance between stops is: " << (avgDist/1609.34)/counter << " miles" << endl;
	outputFile << "Average roadtrip days at one waypoint: " << avgDays/counter << " days" << endl;

	cout << "\nWriting stop stats to roadtrip_stats.txt...\nClosing files..." << endl;
	
	inputFile.close();

	return 0;
}