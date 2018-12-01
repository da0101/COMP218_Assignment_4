#include "PairOfDice.h"

// Default constructor
PairOfDice::PairOfDice() {
    die1 = 0;
    die2 = 0;
    newMaxRoll = 6;
    totalScore = 0;
    srand(static_cast<unsigned int>(time(0)));
}

// Overload constructor
PairOfDice::PairOfDice(int maxRoll) {
    die1 = 0;
    die2 = 0;
    newMaxRoll = maxRoll;
    totalScore = 0;
    srand(static_cast<unsigned int>(time(0)));
}

// Destructor
PairOfDice::~PairOfDice() {
}

// Accessor functions

// Function to access the value of die1
int PairOfDice::getDie1() const {
    return die1;
}

// Function to access the value of die2
int PairOfDice::getDie2() const {
    return die2;
}

// Function to access the value of maximum amount of rolls
int PairOfDice::getMaxRoll() const {
    return newMaxRoll;
}

//=============================================//

// Function to generate random number
void PairOfDice::rollDice() {
    die1 = rand() % newMaxRoll + 1;
    die2 = rand() % newMaxRoll + 1;
}

// Function to check if either of dice is equal to 1
bool PairOfDice::rolledSingleOne() {
    return (die1 == 1 && die2 != 1) || (die1 != 1 && die2 == 1);
}

// Function to check if both dice are equal to 1
bool PairOfDice::rolledTwoOnes() {
    return die1 == 1 && die2 == 1;
}

// Function to check if dice values are equal other than 1
bool PairOfDice::rolledPairsOtherThanOnes() {
    return die1 == die2 && die1 != 1;
}

// Function to get the sum of dice values
int PairOfDice::totalRoll() {
    return die1 + die2;
}

// Function to print the values of dice
void PairOfDice::showRoll() {
    cout << "Die 1: " << die1 << ", Die 2: " << die2;
}
