/*
COPYRIGHT (C) 2022 Sarah Hughes (4724822) All rights reserved.
Assignment 3-A
Author. Sarah Hughes
sch62@uakron.edu
Version. 1.01 09.11.2022
Purpose: This program will ask the user for two positive integers no
greater than 75. The program will then display a rectangle shape on the screen using the
character ‘X’. The numbers entered by the user will be the lengths of each of the two sides
of the square.
*/

#include <iostream>
using namespace std;

int main()
{
    int len, wid;
    cout<<"Please enter two integers, no greater than 75.\nI will make a rectangle for you. :)\n";
    cin>>len>>wid;

    // Check if input matches data type
    while (cin.fail())
    {
        // Clear bad input
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        // Try again...
        cout<<"\nOops! Thats not an integer.\n\nPlease enter two integers, no greater than 75.\n";
        cin>>len>>wid;
    }

    // Check if numbers are no greater than 75
    while (len > 75 || wid > 75)
    {
        // Clear bad input
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        // Try again...
        cout<<"\nOops! That numbers's too big!\n\nPlease enter two integers, no greater than 75.\n";
        cin>>len>>wid;
    }
    
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < wid; j++)
        {
            cout<<"X";
        }
        cout<<"\n";
    }
}
