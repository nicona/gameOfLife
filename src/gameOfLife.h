//
//  gameOfLife.h
//  Assingment2
//
//  Created by Nicolaus Nagel on 2/16/14.
//  Copyright (c) 2014 Nicolaus Nagel. All rights reserved.
//

#ifndef __Assingment2__gameOfLife__
#define __Assingment2__gameOfLife__


#include <fstream>
#include <vector>
#include <iostream>
#include <unistd.h>

using namespace std;

class gameOfLife{
public:
    
    //user input and answer methods
    void userConfig();//random or file configuration
    void userMode(); //what mode
    void runOption(); //brief or manual run time
    void fileMethod(); //if file option what mode, mirror, dougnut, or classic
    
    //different configuration modes
    void randomArr(int userRow, int userColumn); //orginial array output
    void fileArr(string filePath);  //method that reads from the file that given the user path
    
    //the 3 different mode options
    void classico(); //classic mode
    void mirror(); //mirror mode method
    void doughnut();//doughnut mode method
    
    
    //print and swith methods
    void switchBoard(); //this method will swith the main board with the updated board
    void printArray(); //will print the array
    void outputFile(); // will output the file into the given text file;

    //creation of the game boards
    char** arr; // creation of the main board
    char** arr1; //temp gameboard definiton
    
    
    //all value definitions
    string configuration;// random or flat file configuration
    string mode;//mirror, doughnut, or classic mode
    string runAnswer; //brief or input simulation
    string end;//ends simulation in brief mode
    
    string answer2; //next generation answer
    string filePath; // user input for file path
    string filePath2;//file path for where the board is supposed to be outputted.
   
    int userRow, userColumn; // user input for column and row...
    double userDensity; // user input for density
    double density; // random number between 0 and 1
    
    
    
};



#endif /* defined(__Assingment2__gameOfLife__) */
