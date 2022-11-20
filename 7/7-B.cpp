/*
COPYRIGHT (C) 2022 Sarah Hughes (4724822) All rights reserved.
Assignment 7-B
Author. Sarah Hughes
sch62@uakron.edu
Version. 1.01 11.14.2022
Purpose: The purpose of this assignment is to make sure that you know how to write a program that
uses sorting and arrays. The program also contains functions and may perform input,
output, files and file processing, flow of control, and/or calculations. Please note that this
assignment indicates precisely what your program should accomplish, without a precise
indication of how the program works. Part of your assignment is designing the techniques of
how the program works.
*/


// include directives
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using std::ifstream;
using std::ofstream;

#define IN_FILE "ASSGN6-B.txt"
#define OUT_FILE "inventory_totals.txt"

ifstream inFile;
ofstream outFile;

void sort(std::string item[], int count[], double price[], int num);

int main()
{
	inFile.open(IN_FILE);
    outFile.open(OUT_FILE);
	std::string line;
	std::string item[29];
	int count[29];
	double price[29];
	int i = 0;
	int itemCount = 0;

	while (std::getline(inFile, line))
	{
		int pos = line.find(',');
		if (pos == std::string::npos) continue;
		line = line.substr(pos + 2);
		std::stringstream ss(line);
		ss >> count[i] >> item[i] >> price[i];
		i++;
	}

	sort(item, count, price, i);
	std::string currentItem = item[0];
	int totalQty = 0, sumQty = 0;
	double totalPrice = 0;

	std::cout << std::setfill('=') << std::setw(65) << " " << std::endl
		<< "=" << std::setfill(' ') << std::setw(42) << std::right
		<< "FARMER\'S MARKET INVENTORY" << std::setw(21) << "=" << std::endl
		<< std::setfill('=') << std::setw(65) << " " << std::setfill(' ') << std::endl;

	

	for (int k = 0; k < i; k++)
	{
		if (item[k] == currentItem)
		{
			totalPrice += count[k] * price[k];
			totalQty += count[k];
			sumQty += count[k];
			itemCount += 1;
		}
		else
		{
			std::cout << std::fixed << std::setprecision(2)  << itemCount << " loads of " << currentItem << " were delivered" << std::endl;
			currentItem = item[k];
			totalPrice = count[k] * price[k];
			totalQty = count[k];
			sumQty += count[k];
			itemCount = 1;
		}
	}
	std::cout << std::fixed << itemCount << std::setprecision(2) << " loads of " << currentItem << " were delivered" << std::endl;
	std::cout  << "There were " << sumQty << " items contributed to this week's event." << std::endl;
	return 0;
}

void sort(std::string item[], int count[], double price[], int num)
{
	for (int k = 0; k < num; k++) 
		for (int i = 0; i < num - 1; i++)
			for (int j = i + 1; j < num; j++)
				if (item[i].compare(item[j]) > 0)
				{
					std::string tmp1; 
                    int tmp2; 
                    double tmp3;
					tmp1 = item[i]; 
                    tmp2 = count[i]; 
                    tmp3 = price[i];
					item[i] = item[j]; 
                    count[i] = count[j]; 
                    price[i] = price[j];
					item[j] = tmp1; 
                    count[j] = tmp2; 
                    price[j] = tmp3;
					
				}
}