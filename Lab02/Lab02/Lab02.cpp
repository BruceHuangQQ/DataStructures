
// Run in terminal
#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"
void readData(std::istream& aInStream, Map aArray[], int aSize)
{
	for (int i = 0; i < aSize; i++) 
	{
		int v1, v2;
		aInStream >> v1 >> v2;
		aArray[i].key = v1;
		aArray[i].value = v2;
	}
}

void performInsertionSortKeyValuePairs(Map aArray[], int aSize)
{
	//#insertion sort
	//	n = len(thisdict) #n = the length of the array
	//	i = 1

	//	while i < n:
	//j = i

	//	while j > 0 and thisdict[j - 1]["year"] < thisdict[j]["year"]: #< is desc, > is ascend
	//		thisdict[j], thisdict[j - 1] = thisdict[j - 1], thisdict[j]   # swap
	//		j = j - 1

	//		i = i + 1

	int n = aSize;
	int i = 1;

	while (i < n)
	{
		int j = i;
		while (j > 0 && aArray[j - 1].value < aArray[j].value)
		{
			Map temp = aArray[j];
			aArray[j] = aArray[j - 1];
			aArray[j - 1] = temp;
			j = j - 1;
		}
		i = i + 1;
	}
}

void printValues(Map aArray[], int aSize)
{
	std::cout << "[";
	if (aSize > 0)
	{
		std::cout << "(" << aArray[0].key << "," << aArray[0].value << ")";
		//std::cout << aArray[0];
		for (int i = 0; i < aSize; i++)
		{
			//std::cout << aArray[i];
			std::cout << ",";
			std::cout << "(" << aArray[i].key << "," << aArray[i].value << ")";
		}
	}
	std::cout << "]";
}

int main(int argc, char* argv[]) //what do the arguments mean????
{
	if (argc != 2)
	{
		std::cerr << "Illegal command invocation." << std::endl;
		std::cerr << "Usage: Records Data.txt" << std::endl;
		return 1; // return argument error
	}
	std::ifstream lInput(argv[1]); // create input file object
	if (!lInput.good())
	{
		std::cerr << "Error opening " << argv[1] << std::endl;
		return 2; // return input file error
	}
	// read data size
	int lSize = 0;
	lInput >> lSize;
	std::cout << "Number of entries: " << lSize << std::endl;
	// allocate memory
	Map* lArray = new Map[lSize];
	readData(lInput, lArray, lSize);
	performInsertionSortKeyValuePairs(lArray, lSize);
	printValues(lArray, lSize);
	// free memory
	delete[] lArray;
	return 0; // return success	
}
