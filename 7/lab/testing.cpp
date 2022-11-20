#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream inFile;      // Input file object
    ofstream outFile;  // Output file object
    string inName;      // Input file name
    string outName;   // Output file name
    char input;           // To hold a character of input

    // Get the input file name.
    cout<<"Enter the input file name: ";

    cin>>inName;

    // Open the input file.
    inFile.open(inName);

   // Test for errors.
   if (!inFile)
    {
    // There was an error so display an error
    // message and end the program.
    cout<<"Error opening " << inFile << endl;
    exit(EXIT_FAILURE);
    }

    // Get the output file name.</p>
    cout << "Enter the output file name: ";

    cin>>outName;

// Open the output file.
    outFile.open(outName);

 // Test for errors.
    if (!outFile)
     {
// There was an error so display an error
 // message and end the program.
    cout << "Error opening " << outFile << endl;
     exit(EXIT_FAILURE);
}

// Read the contents of the input file, one
// character at a time, encrypt it, and store
// it in the output file.
    while(!inFile.eof())
    {
        inFile>>input;
        input +=10;
        outFile<<input;
    }
    cout << "The file has been encrypted.\n";
// Close both files.
    inFile.close();
    outFile.close();

    return 0;
}