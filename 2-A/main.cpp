/*
COPYRIGHT (C) 2022 Sarah Hughes (4724822) All rights reserved.
Assignment 2-A
Author. Sarah Hughes
sch62@uakron.edu
Version. 1.01 09.10.2022
Purpose: This program will calculate the total grade for N classroom
exercises as a percentage, and determine a letter grade. The user inputs the value for N followed by each of the N
scores and totals.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout<<"How many exercises to input? ";
    int exercises;
    cin>>exercises;

    // setting up variables for the loop
    int loop = exercises;
    int pointTotal = 0;
    int scoreTotal = 0;

    while(loop>0)
    {
        // User inputs score and points, loop accumulates them and stores in separate variables
        int score;
        int points;
        cout<<"\n\nScore received for exercise "<<exercises - loop + 1<<": ";
        cin>>score;
        cout<<"\nTotal points possible for exercise "<<exercises - loop + 1<<": ";
        cin>>points;

        loop--;
        pointTotal = pointTotal + points;
        scoreTotal = scoreTotal + score;
    }

    // Percent calculation
    float percent = (static_cast<float>(scoreTotal)/static_cast<float>(pointTotal))*100;
    cout<<"\nYour total is "<<scoreTotal<<" out of "<<pointTotal<<", or "<<fixed<<setprecision(2)<<percent<<"%."<<endl;

    // Compare calculated percent to the values for each letter grade
    if(percent>=93.00)
    {
        cout<<"Your letter grade is A.";
    }
    if(percent>=90.00 && percent < 93.00)
    {
        cout<<"Your letter grade is A-.";
    }
    if(percent>=87.00 && percent < 90.00)
    {
        cout<<"Your letter grade is B+.";
    }
    if(percent>=83.00 && percent < 87.00)
    {
        cout<<"Your letter grade is B.";
    }
    if(percent>=80.00 && percent < 83.00)
    {
        cout<<"Your letter grade is B-.";
    }
    if(percent>=77.00 && percent < 80.00)
    {
        cout<<"Your letter grade is C+.";
    }
    if(percent>=73.00 && percent < 77.00)
    {
        cout<<"Your letter grade is C.";
    }
    if(percent>=70.00 && percent < 73.00)
    {
        cout<<"Your letter grade is C-.";
    }
    if(percent>=67.00 && percent < 70.00)
    {
        cout<<"Your letter grade is D+.";
    }
    if(percent>=63.00 && percent < 67.00)
    {
        cout<<"Your letter grade is D.";
    }
    if(percent>=60.00 && percent < 63.00)
    {
        cout<<"Your letter grade is D-.";
    }
    if(percent<60)
    {
        cout<<"Your letter grade is F.";
    }

}
