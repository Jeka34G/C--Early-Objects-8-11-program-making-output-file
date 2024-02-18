#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {

	int counter = 0; // Counter for the range-based for loop

	const int NUM_OFFICES = 12;
	ifstream dataIn;
	ofstream outputFile;
	int office;					// Loop counter
	double sales[NUM_OFFICES],	// Array to hold the sales data
		totalSales = 0.0,		// Accumulator initialized to zero
		averageSales,
		highestSales,
		lowestSales;

	// Open the data file
	dataIn.open("sales.dat");
	if (!dataIn)
		cout << "Error opening data file.\n";
	else
	{
		// Fill the array with data from the file
		for (office = 0; office < NUM_OFFICES; office++)
			dataIn >> sales[office];
		dataIn.close();
		int index = 6;
		cout << "The " << index << " index in the array is " << sales[index] << endl;

		// Open the output file
		outputFile.open("redoing.dat");

		for (int val : sales)
		{
			static bool beginNewLine = true; // ...
			int newlineAfter = 5; // After how many output the newline starts

			if (counter != newlineAfter)
			{	
				cout << "The value of beginNewLine is " << beginNewLine << endl;

				if (beginNewLine == false) {
				outputFile << setw(7) << val << "  ";
				cout << "Outputting val and space\n";
				}
				else if (beginNewLine == true)
				{
					outputFile << val << "  ";
					cout << "Outputting val and space WITHOUT SETW\n";
					beginNewLine = false;
				}
			}
			
			else 
			{

				outputFile << setw(7) << val <<  endl;
				cout << "Outputting val and space AND ENDL\n";
				beginNewLine = true;
			}

			counter++;
			cout << "The counter is " << counter << endl;
		}



	}
	return 0;
}
