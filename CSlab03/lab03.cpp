/*
COPYRIGHT (C) 2022 Sarah Hughes (4724822) All rights reserved.
Lab 03
Author. Sarah Hughes
sch62@uakron.edu
Version. 1.01 09.21.2022
Purpose: This lab's purpose is to learn about input-validation and setting up reusable, expandable code for 
input validation on future projects. 
*/

#include <iostream> // for input-output stream operations
#include <iomanip> // for providing parametric manipulators operations
#include <limits> // for providing elements with the characteristic of arithmetic types 
using std::cout; // for printing output to console
using std::cin; // for taking in input from user
using std::endl; // for creating a line break in an IO stream


int main() 
{
double organisms = 0.00; // to hold the number of organisms

// get the number of organisms

bool loopFlag = true; // Control flag for the loop

do // post test loop
{
    cout<<"Enter the starting number of organisms: "; // initial input prompt
    cin>>organisms; // store input into organisms

    // Do not accept a number less than 2 for the
    // starting size of the population
    if((cin.fail()) || organisms < 2 ) // tests 2 conditions
    {
        cout<<"The starting number of organisms must be a valid number that is at least 2.\n"; // question
        cin.clear(); // clear failed input
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // ignore everything that was input before. Start over

    }
    else // if cin does not fail (good input!)
    {
        loopFlag = false; // change bool to false, no more loop
    }

} while (loopFlag); // after the above is done once, it only repeats while loopFLag is true

return 0; // Ends the program and returns a 0 back to the operating system

}

/*
What does the using std::..., do for us, and why would we use this instead of using std
namespace?

    using namespace std imports all of the identifiers from std. Since we're only using cout, cin, and endl, its more 
    efficient to just call in those three instead of the entire namespace. Also, if there's some future version of the namespace 
    that adds an identifier that conflicts with one of your own, you get errors. Better to import only exactly what you need.

What about cin.fail() for console input?

    cin.fail() = true when the user tries to input a value that doesnt match the data type of the variable it's being stored into.
    For example, if you have int a, and cin>>a, then you must only enter integer values. Otherwise, cin.fail() = true.

What was a short-circuit evaluation?

    Basically, if you have a logical operator like || or &&, then the computer will only evaulate those sub-expressions 
    until the result is determined, and will skip any extra evaluations. 

    For example, 
    if((cin.fail()) || organisms < 2)
    {
        do something
    }

    If cin.fail() == true, then the result of that || statement is already determined to be true, so, the computer doesnt bother 
    to evaluate the organisms < 2 part.

What about the parameters for ignore, the numeric limits and streamsize?

    numeric_limits tells computer how much of cin to ignore.
    '\n' is a delimiter, meaning cin will be ignored up until the end of the line, and numeric_limits<streamsize>::max()
    sets the number of characters to ignore, in this case, the maximum number of characters that are needed.

*/
