#include <iostream>
#include <limits>
#include <iomanip>

long int factorial(int n)
{
    int result = 1;
    for(int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int num, j;
    bool loopFlag = true;
    while(j<10)
    {
        do
        {
            std::cout<<"Enter a nonnegative number greater than zero."<<std::endl;
            std::cin>>num;
            if(num<=0 || std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<<"Invalid Input.\n";
            }
            else
            {
                std::cout<<"Factorial #"<<j+1<<": "<<factorial(num)<<std::endl;
                loopFlag = false;
                j++;
            }

        } while (loopFlag);
    }
}