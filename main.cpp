#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "PairOfDice.h"

using namespace std;

// Declaring the object of type PairOfDice
PairOfDice pairOfDice;
int humanScore = 0;
int computerScore;

// Printing the header at the beginning of the program
void printHeader() {
    cout << "-------****-------****-------****-------****-------****-------" << endl;
    cout << "                      Welcome to my Dice Game!                " << endl;
    cout << "-------****-------****-------****-------****-------****-------" << endl;
    cout << endl;
}

// Setting the number of sides for dice
int getDiceNumberOfSides() {
    int numSides;
    cout << "How many sides do your dice have <minimum 4>? ";
    cin >> numSides;
    cout << endl;
    if (numSides >= 4) {
        return numSides;
    }
    return getDiceNumberOfSides();
}

// Function to propose another roll
bool shouldRollAgain() {
    char answer;
    cout << "Do you want to roll again? <Y or anything else for no> ";
    cin >> answer;
    cout << endl;
    return answer == 'Y' || answer == 'y';
}

// Function to print score
void printScoreToDate(int score) {
    cout << "        --> Score to date: " << score << endl << endl;
}
// Function to print game results.
void printGameResults() {
    cout << "GAME RSULTS:" << endl;
    if (humanScore > computerScore) {
        cout << "The human is the winner with the score of " << humanScore << endl;
    }
    else if (computerScore > humanScore) {
        cout << "The comuter is the winner with the score of " << computerScore << endl;
    }
    else {
        cout << "We have a tie! Both human and computer scored " << computerScore << endl;
    }
    cout << "Hope you enjoyed your game!" << endl;
}

// Human's turn function
void humanTurn() {
    pairOfDice.rollDice();
    cout << "Human Rolled: ";
    pairOfDice.showRoll();
    cout << endl;
    // Checking if human rolled two ones
    if (pairOfDice.rolledTwoOnes()) {
        humanScore = 0;
        printScoreToDate(humanScore);
        return;
    }
    // Checking if computer rolled single one
    if (pairOfDice.rolledSingleOne()) {
        printScoreToDate(humanScore);
        return;
    }
    // Checking of other than ones same numbers were rolled at the same time
    if (pairOfDice.rolledPairsOtherThanOnes()) {
        humanScore += pairOfDice.totalRoll() * 2;
    }
    else {
        humanScore += pairOfDice.totalRoll();
    }
    printScoreToDate(humanScore);
    // Allowing the user to decide if roll again
    if (shouldRollAgain()) {
        humanTurn();
    }
}

// Computer's turn function
void computerTurn() {
    pairOfDice.rollDice();
    cout << "Computer Rolled: ";
    pairOfDice.showRoll();
    cout << endl;
    // Checking if computer rolled two ones
    if (pairOfDice.rolledTwoOnes()) {
        computerScore = 0;
        printScoreToDate(computerScore);
        return;
    }
    // Checking if computer rolled single one
    if (pairOfDice.rolledSingleOne()) {
        printScoreToDate(computerScore);
        return;
    }
    
    // Calculating score and checking if other numbers were rolled at the same time
    computerScore += pairOfDice.rolledPairsOtherThanOnes() ? pairOfDice.totalRoll() * 2 : pairOfDice.totalRoll();
    printScoreToDate(computerScore);

    if (computerScore <= 100 || computerScore <= humanScore) {
        computerTurn();
    }
}

// Function to call human or computer turns
void playRound() {
    
    cout << endl << endl;
    cout << "Human's turn" << endl;
    cout << "------------" << endl << endl;
    humanTurn();
    
    cout << endl << endl;
    cout << "Computer's turn" << endl;
    cout << "---------------" << endl << endl;
    computerTurn();
    
    if (humanScore < 100 && computerScore < 100) {
        playRound();
        return;
    }
    printGameResults();
}

// main function
int main() {
    printHeader();
    pairOfDice = PairOfDice(getDiceNumberOfSides());
    playRound();
    return 0;
}
