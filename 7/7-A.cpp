/*
COPYRIGHT (C) 2022 Sarah Hughes (4724822) All rights reserved.
Assignment 7-A
Author. Sarah Hughes
sch62@uakron.edu
Version. 1.01 11.14.2022
Purpose: The purpose of this assignment is to make sure that you know how to write a program that
uses sorting and arrays. The program also contains functions and may perform input,
output, files and file processing, flow of control, and/or calculations. Please note that this
assignment indicates precisely what your program should accomplish, without a precise
indication of how the program works. Part of your assignment is designing the techniques of
how the program works.
*/

// include directives
#include <iostream>
#include <fstream>
#include <iomanip>
using std::ifstream;
using std::ofstream;

// some defines cause i wanted to be extra
#define IN_FILE "ASSGN6-B.txt"
#define OUT_FILE "inventory_totals.txt"

// the file objects
ifstream inFile;
ofstream outFile;


// a lot of functions uhh
// this does the main sorting stuff
void sort(std::string items[], int itemCounts[], float itemTotals[]); 

// these three swaps are for the sorting bit above
void swapString(std::string *xp, std::string *yp); 
void swapInt(int *xp, int *yp);
void swapFloat(float *xp, float *yp);

// this is does the final bit of sorting and displays everything
void display(std::string items[], int itemCounts[], float itemTotals[], ifstream& inFile, ofstream& outFile);

// header and repeatedChar to facilitate printing out that header
void header();
void repeatedChar(char, int);


int main()
{
    inFile.open(IN_FILE); // #define go brrrrr
    outFile.open(OUT_FILE);

    // variables 
    int count;
    std::string item, farmName;
    float cost, total;
    std::string items[29];
    int itemCounts[29];
    float itemTotals[29];
    
    // 7 othert functions and i didnt bother to make this one into a function
    // monkaS
    while(!inFile.eof())
    {

        int k;
        getline(inFile, farmName, ',');
        inFile >> count >> item >> cost >> total;

        items[k] = item;
        itemCounts[k] = count;
        itemTotals[k] = total;

        k++;
    }

    // yes
    header();
    sort(items, itemCounts, itemTotals);
    display(items, itemCounts, itemTotals, inFile, outFile);

   inFile.close();
   outFile.close();
}

// too many swaps
void swapString(std::string *xp, std::string *yp)
{
    std::string temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void swapInt(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void swapFloat(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// here i cry, and my tears form a selection sort that orders the items alphabetically
void sort(std::string items[], int itemCounts[], float itemTotals[])
{
    int i, j, min_idx;
 
    for (i = 0; i < 28; i++)
    {
        min_idx = i;
        for (j = i+1; j < 28; j++)
        if (items[j] < items[min_idx])
            min_idx = j;
 
        if(min_idx!=i)
            swapString(&items[min_idx], &items[i]);
            swapInt(&itemCounts[min_idx], &itemCounts[i]);
            swapFloat(&itemTotals[min_idx], &itemTotals[i]);
    }
}

// with the power of sadness, i create loops of pure suffering
// with this ultimate power at my disposal, i do something really poggers
// I have regular variables assigned to index i of the first loop, and then a while loop
// that increments everything so long as the item in the current index matches the one in the next

// Then i had a weird && thing cause pickles was giving me a hard time 
// how can pickles be both so problematic and also delicious?
// anyway, here's Wonderwall
void display(std::string items[], int itemCounts[], float itemTotals[], ifstream& inFile, ofstream& outFile)
{
  std::string item;
  int count;
  float total;
  for(int i = 0; i < 28; i++)
  {
    item = items[i];
    count = itemCounts[i];
    total = itemTotals[i];
    while(items[i] == items[i + 1])
    {
      count += itemCounts[i + 1];
      total += itemTotals[i + 1];
      i++;
    }
    if(count > 0 && total > 0)
    {
      std::cout << std::setw(20) << std::left << item+":";
      std::cout << " " << count << " items totaling $" << total << "\n";
      outFile << std::setw(20) << std::left << item+":";
      outFile << " " << count << " items totaling $" << total << "\n";
    }
  }
}

// yeah
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

// yeah part 2
// this is for the header function ^^^
void repeatedChar(char letter, int num)
{
    for(int i = 0; i <= num; i++)
    {
        std::cout<<letter;
        outFile<<letter;
    }
}