
#ifndef PairOfDice_h
#define PairOfDice_h

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


class PairOfDice {

// Attriutes
int die1, die2;
int newMaxRoll;
int rollCount;
int totalScore;

public:
    
    //Constructors
    PairOfDice();
    PairOfDice(int);
    
    //Destructor
    ~PairOfDice();
    
    void init(int maxRoll);
    
    // Accessors Functions
    int getDie1() const;
    int getDie2() const;
    int getMaxRoll() const;
    
    // Game logic functions
    void rollDice();
    bool rolledSingleOne();
    bool rolledTwoOnes();
    bool rolledPairsOtherThanOnes();
    
    int totalRoll();
    void showRoll();
};

#endif /* PairOfDice_h */
