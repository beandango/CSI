/*
COPYRIGHT (C) 2022 Sarah Hughes (4724822) All rights reserved.
Assignment 5-A
Author. Sarah Hughes
sch62@uakron.edu
Version. 1.01 10.09.2022
Purpose: This program will use a function isPrime() to tell a user if 
a number they entered is prime or not. All input is validated and 
the user is given the option to repeat if they want to. 
*/

#include <iostream>
#include <limits>

int isPrime(int n)
{
    bool prime = true;
    for(int i = 2; i <= n / 2; i++)
    {
        if(n % i == 0)
        {
            prime = false;
            break;
        }
    }
    return prime;
}

int main()
{
    bool loopFlag = true, prime, again = true;
    int num;
    char againYN = ' ';
    
    // loop shenanigans
    // basically almost entire main() is under this loop, and
    // after the program outputs if user's num
    // is prime or not, it asks "Again?" and this loop happens
    // based on that answer.
    while(again)
    {
        do // input validation for initial num input
        {
            std::cout<<"\nEnter any positive integer, and I will tell you \n"
                    <<"if it is prime or not.\n";
            std::cin>>num;
            if(std::cin.fail()||num <= 0)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"\n------Invalid Input.------";
            }

            // special case for 1, cause the function will
            // say that 1 is a prime number when it's not
            // 1 is weird cause technically yes, 
            // it's only divisible by 1 and itself but it is 1 so...
            // neither prime nor composite
            else if (num == 1)
            {
                loopFlag = false; // input good, no more validation loop
                std::cout<<num<<" is not a prime number\n";
            }
            else
            {
                loopFlag = false; // input good, no more validation loop
                bool flag = isPrime(num);
                if(flag==true)
                {
                    std::cout<<num<<" is a prime number\n";
                }
                else
                {
                    std::cout<<num<<" is not a prime number\n";
                }
            }
        } 
        while (loopFlag);

        // more loop shenanigans
        // input validation for the "Again?" question
        bool againCheck = true;
        do
        {
            std::cout<<"\nAgain? (y/n) -> Case sensitive\n";
            std::cin>>againYN;
            if(std::cin.fail() || (againYN != 'y' && againYN != 'n'))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"\n------Invalid Input.------";
            }
            else 
            {
                againCheck = false; // input good, no more validation loop
                if (againYN == 'y')
                {
                    again = true;
                }
                else
                {
                    again = false;
                }
            }
        }
        while(againCheck);
    }
}