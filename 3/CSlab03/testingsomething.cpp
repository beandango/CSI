#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int x, y;
    x = -1;
    y = 0; 
    while (x < 3)
    {
        y += 2;
        x += 1;
        cout<<x<<" "<<y<<endl;
    }
    cout<<"final: "<<x<<" "<<y;
}