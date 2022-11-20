/*
COPYRIGHT (C) 2022 Sarah Hughes (4724822) All rights reserved.
CSI Lab 02
Author. Sarah Hughes
sch62@uakron.edu
Version. 1.01 09.07.2022
Purpose: This program will calculate the total rating for some number of tweets as a percentage,
given input from the user indicating the name of the person, followed by the count of the 
tweet likes and total tweets.
*/


// Constants
const double STATETAX = .25;
const double COUNTYTAX = .75;
const double FEDTAX = 1.25;

// Variables
int statePop;
int countyPop;
int fedPop;

// Actual program starts here
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Declaring variables
    string twittererName = "";
    int tweets = 0;
    int likes = 0;

    // Prompting user for input, storing input
    cout<<"Who is the twitterer? ";
    cin>>twittererName;
    cout<<"\nNumber of tweets: ";
    cin>>tweets;
    cout<<"\nNumber of likes: ";
    cin>>likes;

    // Making sure the number of tweets isn't 0
    if(tweets == 0)
    {
        cout<<"\nError: cannot divide by 0"<<endl;
        return 0;
    }

    // Percentage calculation, display result
    double percentage = likes/static_cast<float>(tweets)*100;
    cout<<"\nYour total is "<<likes<<" out of "<<tweets<<", or "<<fixed<<setprecision(2)<<percentage<<"%."<<endl;

    // Determine twitter rating using percentage, display rating
    if(percentage >= 93.00)
    {
        cout<<"\nYour twitter rating is Awesome!"<<endl;
    }
    if(percentage < 93.00 && percentage >= 90.00)
    {
        cout<<"\nYour twitter rating is Semi-awesome"<<endl;
    }
    if(percentage < 90.00 && percentage >= 87.00)
    {
        cout<<"\nYour twitter rating is Better than most"<<endl;
    }
    if(percentage < 87.00 && percentage >= 83.00)
    {
        cout<<"\nYour twitter rating is Well liked"<<endl;
    }
    if(percentage < 83.00 && percentage >= 80.00)
    {
        cout<<"\nYour twitter rating is Semi-well liked"<<endl;
    }
    if(percentage < 80.00 && percentage >= 77.00)
    {
        cout<<"\nYour twitter rating is Pretty good"<<endl;
    }
    if(percentage < 77.00 && percentage >= 73.00)
    {
        cout<<"\nYour twitter rating is Good"<<endl;
    }
    if(percentage < 73.00 && percentage >= 70.00)
    {
        cout<<"\nYour twitter rating is Okay, I guess"<<endl;
    }
    if(percentage < 70.00 && percentage >= 67.00)
    {
        cout<<"\nYour twitter rating is Some dislikes"<<endl;
    }
    if(percentage < 67.00 && percentage >= 63.00)
    {
        cout<<"\nYour twitter rating is More dislikes than not"<<endl;
    }
    if(percentage < 63.00 && percentage >= 60.00)
    {
        cout<<"\nYour twitter rating is Dislikes rule"<<endl;
    }
    if(percentage < 60.00)
    {
        cout<<"\nYour twitter rating is Oh, bad news"<<endl;
    }
    
}