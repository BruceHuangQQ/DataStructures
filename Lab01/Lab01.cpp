#include <cstddef>
#include <iostream>

//2n+1
//void printIntArray(int aArray[], size_t aSize)
//{
//	std::cout << "[";
//	//print the elements until the array ends
//	//n+1
//	for (int i = 0; i < aSize; i++)
//	{
//		//print the element of that sequence
//		std::cout << aArray[i];
//		//if it doesnt end, print comma
//		//n
//		if (i != aSize - 1)
//		{
//			std::cout << ",";
//		}
//	}
//	std::cout << "]";
//}

//n+1
void printIntArray(int aArray[], size_t aSize)
{
	std::cout << "[";
	//if this is the first element
	//print first
	//n-1
	if (aSize > 0)
	{
		std::cout << aArray[0];
		for (int i = 1; i < aSize; i++)
		{
			std::cout << ",";
			std::cout << aArray[i];
		}
	}
	//print next
	std::cout << "]";
}



int main()
{
	int lArray[] = { 23, 4, 67, 1, 0, -20, 29, -100, 32, 99, -56 };
	size_t lSize = sizeof(lArray) / sizeof(int);
	printIntArray(lArray, lSize);
	return 0;
}