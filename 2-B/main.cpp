/*
COPYRIGHT (C) 2022 Sarah Hughes (4724822) All rights reserved.
Assignment 2-B
Author. Sarah Hughes
sch62@uakron.edu
Version. 1.01 09.11.2022
Purpose: This program will take in 10 whole numbers, positive, negative, or 0, and show the user
the sums of the positive numbers, the negative numbers, and all of the numbers respectively.
*/

#include <iostream>
using namespace std;

int main()
{
    int number, negSum, posSum;
    cout<<"Enter in ten whole numbers one by one.\nThey can be positive, negative, or equal to 0.\n";

    // New number is inputted every loop and is compared to 0
    for(int i = 0; i < 10; i++)
    {
        cin>>number;

        if(number >= 0)
        {
            // if number is positive, it is added to the positive sum
            posSum += number;
        }
        else
        {
            // same as above, but negative
            negSum += number;
        }
    }

    // final results output :)
    cout<<"The sum of positive numbers is: "<<posSum<<endl;
    cout<<"The sum of negative numbers is: "<<negSum<<endl;
    cout<<"The total sum of all numbers is: "<<posSum+negSum<<endl;    
}

