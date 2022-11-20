/*
COPYRIGHT (C) 2022 Sarah Hughes (4724822) All rights reserved.
Assignment 6-B
Author. Sarah Hughes
sch62@uakron.edu
Version. 1.01 10.31.2022
Purpose: The purpose of this assignment is to make sure that you know how to write a program that
uses files and file processing. The program also contains functions and does input, output,
flow of control and/or calculations. In other words, read from file, output to another file but
in a neater way.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using std::ifstream;
using std::ofstream;

// I/O file stream objects
ifstream inFile;
ofstream outFile;

// input/output files
const std::string OUTPUT = "Inventory.txt";
const std::string INPUT = "ASSGN6-B.txt";

//function prototypes
void header();
void repeatedChar(char, int);
void filePrint(ifstream&, ofstream&);

// main, where i open and close the files, and call the functions to do all the work
int main()
{
    inFile.open(INPUT);
    outFile.open(OUTPUT);

    header();
    filePrint(inFile, outFile);

    inFile.close();
    outFile.close();
    return 0;
}

// I couldn't get setfill() to work cause it was replacing all of the spaces
// in the output with '=' so i made the repeated char function to repeat a char as much as you want,
// which i will use in the header() function below this one
void repeatedChar(char letter, int num)
{
    for(int i = 0; i <= num; i++)
    {
        std::cout<<letter;
        outFile<<letter;
    }
}

// Okay i know this looks like a mess but hear me out:
//...
// i doubled all the outputs here so it prints to console and the outFile,
// and used the aforementioned repeatedChar function
// probably a much better way to do this but my brain is smooth.
void header()
{
    repeatedChar('=', 66);
    std::cout<<"\n=";
    outFile<<"\n=";
    repeatedChar(' ', 19);
    std::cout<<"FARMER'S MARKET INVENTORY";
    outFile<<"FARMER'S MARKET INVENTORY";
    repeatedChar(' ', 19);
    std::cout<<"=\n";
    outFile<<"=\n";
    repeatedChar('=', 66);
    std::cout<<"\n";
    outFile<<"\n";
}

// the meat and potatoes
void filePrint(ifstream& inFile, ofstream& outFile)
{

    //important variables
    std::string farmName;
    std::string item;
    float cost, total, grandTotal;
    int count, countTotal;

    // the following happens until the end of the file
    while(!inFile.eof())
    {

        // i use getline() to store whatever is before ',' into farmName
        getline(inFile, farmName, ',');

        // rest of the line is already conveniently separated by count, item, cost, and total
        // so i just stream those into their respective variables
        inFile>>count>>item>>cost>>total;

        // and of course i add everything up while inside the loop to use later
        grandTotal+=total;
        countTotal+= count;

        // formatting stuff. I double outputs so they output in console
        // and outFile in exactly the same way
        std::cout<<std::left<<std::setw(25)<<farmName; // I separated farmName so its less miserable to read
        outFile<<std::left<<std::setw(25)<<farmName;
        
        // this hurts my eyes
        outFile<<count<<" "<<item<<" @ "<<std::setprecision(2)<<std::fixed<<cost<<" each totaling $"<<total<<std::endl;
        std::cout<<count<<" "<<item<<" @ "<<std::setprecision(2)<<std::fixed<<cost<<" each totaling $"<<total<<std::endl;

        std::cout<<"...\n";
        outFile<<"...\n";
    }

    // suffering
    outFile<<std::endl<<std::left<<std::setw(25)<<"Grand Total: ";
    outFile<<countTotal<<" items totaling $"<<grandTotal<<std::endl;

    std::cout<<std::endl<<std::left<<std::setw(25)<<"Grand Total: ";
    std::cout<<countTotal<<" items totaling $"<<grandTotal<<std::endl;
}