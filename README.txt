PROGRAM DETAILS
PA1:
	Write a chatbot program that interacts with the user in the following manner:
   	 1. Find out the name of the user (string). Reply with a greeting, such as "It's so nice to meet you <user's name>! My name is <name of your chatbot>".
   	 2. Find out where the user is from (string). Reply with a positive statement, such as "<location> sounds like a pleasant place to be from!".
   	 3. Find out what year the user was born in (integer). Figure out how old the user is in years based on their birth year. Reply with a value that relates the user's age to your chatbot's age (pick an age for your chatbot), such as "You are <user's age> years old, that makes you 1.5 times as old as I am! I'm only <chatbot's age> years YOUNG!."
    	 4. Find out the user's dream car (string). Reply with a comment that expresses interest in the car, such as "Wow, I've always wanted a <car> as well.
  	 5. Find out how much the dream car costs (float). Then start a conversation about the cost of the car:
       	 1. A comment about how expensive the car is, such as "Gee, that is spendy."
      	  2. Find out how many years the user would take a loan out to pay for <car> (integer)
       	 3. Find out what annual interest rate (percent) the user expects to get for <car> (float)
       	 4. Reply with the expected monthly payment and total amount of money the user would pay for <car> (car price + interest), such as "Your monthly payment for the <car> is <monthly payment>, that is a total of <total cal cost>!”.
		For calculating monthly payments, use the following formula:
		mpymnt = (r(P))/(1-(1+r)^-n)
PA2: 
	Your quiz must contain 10 questions. These 10 questions include at least 2 of each of the following different types of questions:
	Multiple choice (5 options a-e)
	The user enters in a character "a" through "e" for their answer.
	Example:
	1) The population of Spokane is roughly what? Please enter a character a-e.
	a) 215k
	b) 20k
	c) 105k
	d) 400k
	e) 550k

PA3:
	Solve this problem twice, once using a while loop (part 1) and again using a for loop (part 2).
	Part 1: Using a while loop, write code that prompts the user for an integer, n, where n >= 0. The program determines the factorial of n, represented as n!. The factorial of a number such as n! is equal to n * (n – 1) * (n – 2) * ... * 1. 0! is equal to 1 and 1! is also equal to 1.
	Part 2: Resolve part 1 using a for loop instead of a while loop.

PA4:
	Write a program that implements craps according to the rules. Additionally:
    • When the program first begins, show the user the rules of Craps. 
    • Before each initial throw of the dice, prompt the user to ask him/her to keep playing or quit. Game play ends when the user chooses to quit or runs out of money.
    • Your program should allow for wagering before each roll. This means that you need to prompt the user for an initial bank balance from which wagers will be added or subtracted. 
        ◦ Validate the initial bank balance entered by the user greater than zero. If the initial bank balance is not greater than zero, then inform the user and re-prompt.
    • Before each roll prompt the user for a wager. This includes rolls when the user is trying to make their point. Wagers must be less than or equal to the available bank balance. 
        ◦ The available bank balance is based on the accumulation of the previous wagers this game.
    • Once a game is lost or won, the bank balance should be adjusted. 
    • Additional wagering details include:
        ◦ Require the user to enter a non-zero wager for the first roll. Allow the user to enter a wager of 0 for subsequent “point” rolls.
        ◦ Validate that the user’s wager is within the limits of the player's available balance. If the wager exceeds the player's available balance, then inform the user and re-prompt.

PA5:
	Write a program that reads in US locations from an input file. The locations include a road trip origin (starting location), destination (ending location), and several road trip "waypoints" (stops in between the origin and destination).
	The output of your program has two parts:
    1. Status messages displayed to the console. These messages simply let the user know what the program is currently computing (e.g. "Reading in road trip origin location from gainesville_roadtrip.txt...", etc.).
    2. Road trip information and statistics written to an output file. Name your output file <input file base name>_stats.txt. For example, for the provided input file, "gainesville_roadtrip.txt", the corresponding output file is "gainesville_roadtrip_stats.txt". The stats to be written to the output file include:
        a. Distances in miles between each consecutive road trip stop.
        b. Total number of waypoints on the road trip.
        c. Total number of days on the road trip.
        d. Total miles traveled on the road trip.
        e. Names of the two consecutive road trip stops with the most distance between them and that distance in miles.
        f. Name of the waypoint with the longest stay and its number of days.
        g. Average miles between between each stop (including origin, waypoints, and destination).

PA6:
	Write a program to play the game Pass the Pigs. Pass the Pigs is a popular games of chance for two or more players based on a dice game called Pig.

	The rules of the game are straightforward. A player tosses two toy pigs, each of which has a dot on one side (see image below). Each pig can land in one of six positions:
    1. On its side
        a. Side with dot down
        b. Side with dot up
    2. Razorback (on its back)
    3. Trotter (on all four feet)
    4. Snouter (balanced on front two feet and its snout)
    5. Leaning jowler (balanced on one foot, snout, and ear)
	points vary depending on what your pigs land on

PA7:
    1. Read 10 words for the user to guess into an array of strings
    2. Select a random word from the array of strings to the word the user has to guess
    3. Maintain 2 char arrays:
        a. availableLetters: a char array of the available letters the user can choose their guess from. Initialize availableLetters as the lowercase alphabet. As the user guesses letters, replace the corresponding guessed letter with a space to denote the letter has already been guessed.
        b. visibleLetters: a char array of the not guessed letters in word. Initialize visibleLetters to all dashes ("-"). As the user correctly guesses a letter, replace the corresponding dash(es) with the correct letter.
    4. The main game loop:
        a. Display information regarding the status of the game (visibleLetters, availableLetters, and the number of incorrect guesses remaining (the user gets 7 incorrect guesses)).
        b. Prompt the user to enter their guess. If the user tries to guess a letter they have already guessed, inform the user and re-prompt.
        c. Exit the loop if the users completely guesses the letters of the word or if the user runs out of incorrect guesses.

PA8:
	Write a program that simulates the game of Battleship. Battleship is a two player Navy game. The objective of the game is to sink all ships in your enemy's fleet. The Player to sink his/her enemy's fleet first wins. 
	Both players' fleets consist of 5 ships that are hidden from the enemy. Each ship may be differentiated by its "size" (besides the Cruiser and Submarine) or number of cells it expands on the game board:
    		1. Carrier has 5 cells
    		2. Battleship has 4 cells
    		3. Cruiser has 3 cells
    		4. Submarine has 3 cells
    		5. Destroyer has 2 cells.
	The program should be built such that the user is Player1 and the computer is Player2. 









