/*
COPYRIGHT (C) 2022 Sarah Hughes (4724822) All rights reserved.
Assignment 4-A
Author. Sarah Hughes
sch62@uakron.edu
Version. 1.01 10.04.2022
Purpose: This program will ask the user for an initial balance, interest rate, 
number of years to calculate compound interest, and a money goal. The program will
output the balance after one year of interest, the balance after how many years the 
user inputs, and then it will output the amount of years until the balance 
reaches the goal amount inputted. 
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
using std::cout;
using std::cin;
using std::endl;

// Balance after one year
double newBalance(double initialBalance, double interestRate)
{
    return initialBalance + (interestRate*initialBalance);
}

// Balance after n years (compound interest)
double newBalance(double initialBalance, double interestRate, int n)
{
    return initialBalance * (pow((1 + interestRate), n));
}

// pretest loop to check newBalance() for its value after i years.
// loop ends when the new balance is at least the goal.
int yearsNeeded(double initialBalance, double interestRate, double goal)
{
    int i = 0;
    bool loop = true;
    while(loop)
    {
        double balance = newBalance(initialBalance, interestRate, i);
        if(balance >= goal)
        {
            loop = false;
        }
        else
        {
            i++;
        }
    }
    return i;
}


int main()
{
    // Variables
    double intBal, intRate, moneyGoal;
    int years;
    cout.precision(2);
    cout.setf(std::ios::fixed, std::ios::floatfield);

    // loops for input validation
    // Probably a better way to do this, but this is what I came up with
    bool loop1 = true, loop2 = true, loop3 = true, loop4 = true;

    do // Posttest loop
    {
        cout<<"Initial balance?"<<endl;
        cin>>intBal;
        if(cin.fail() || intBal <= 0)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"Invalid Input\n"
                <<"Please enter a positive number.\n";
        }
        else
        {
            loop1 = false;
        }
    }
    while(loop1);
    
    do // Posttest loop
    {
        cout<<"\nInterest Rate?"<<endl;
        cin>>intRate;
        if(cin.fail() || intRate <= 0)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"Invalid Input\n"
                <<"Please enter a positive number.\n";
        }
        else
        {
            loop2 = false;
        }
    }
    while(loop2);
    
    do // Posttest loop
    {
        cout<<"\nNumber of years to calculate compound interest?"<<endl;
        cin>>years;
        if(cin.fail() || years <= 0)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"Invalid Input\n"
                <<"Please enter a positive number.\n";
        }
        else
        {
            loop3 = false;
        }
    }
    while(loop3);

    do // Posttest loop
    {
        cout<<"\nMoney goal?"<<endl;
        cin>>moneyGoal;
        if(cin.fail() || moneyGoal <= 0)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"Invalid Input\n"
                <<"Please enter a positive number.\n";
        }
        else
        {
            loop4 = false;
        }
    }
    while(loop4);

    cout<<"New balance after one year: $"<<newBalance(intBal, intRate)<<endl;
    cout<<"New balance after "<<years<<" years: $"<<newBalance(intBal, intRate, years)<<endl;
    cout<<"Years until $"<<moneyGoal<<": "<<yearsNeeded(intBal, intRate, moneyGoal);
}