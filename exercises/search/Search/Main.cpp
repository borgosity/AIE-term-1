#include <iostream>
#include <ctime>
#include <algorithm>

int LinearSearch(int arr[], int arrSize, int item)
{
	int iter = 0;
	while (arr[iter] != item && iter != arrSize)
	{
		iter++;
	}
	return iter;
}

int BinarySearch(int arr[], int arrSize, int item)
{
	int begin = 0;
	int mid = 0;
	int end = arrSize - 1;
	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (arr[mid] == item)
		{
			return mid;
		}
		else if (arr[mid] < item)
		{
			begin = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return -1;
}

int * MakeRandArr(int arr[],  int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100 +1;
	}
	return arr;
}

void LSearchTest()
{
	const int size = 10;
	int arr[size];
	const int size2 = 100;
	int arr2[size2];
	const int size3 = 10000;
	int arr3[size3];

	//int range = rand() % 100 +1;
	int range = 0;

	int * arrPtr = MakeRandArr(arr, size);
	clock_t begin = clock();
	int pos = LinearSearch(arr, size, range);
	clock_t end = clock();
	double elpased_t = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << pos << ", " << elpased_t << std::endl;

	begin = 0;
	end = 0;
	elpased_t = 0;
	begin = clock();
	arrPtr = MakeRandArr(arr2, size2);
	pos = LinearSearch(arr2, size2, range);
	elpased_t = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << pos << ", " << elpased_t << std::endl;

	begin = 0;
	end = 0;
	elpased_t = 0;
	begin = clock();
	arrPtr = MakeRandArr(arr3, size3);
	pos = LinearSearch(arr3, size3, range);
	elpased_t = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << pos << ", " << elpased_t << std::endl;
}

void BSearchTest()
{
	const int size = 10;
	int arr[size];
	const int size2 = 100;
	int arr2[size2];
	const int size3 = 10000;
	int arr3[size3];

	//int range = rand() % 100 +1;
	int range = 0;

	int * arrPtr = MakeRandArr(arr, size);
	clock_t begin = clock();
	std::sort(arr, arr + size);
	int pos = BinarySearch(arr, size, range);
	clock_t end = clock();
	double elpased_t = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << pos << ", " << elpased_t << std::endl;

	begin = 0;
	end = 0;
	elpased_t = 0;
	begin = clock();
	arrPtr = MakeRandArr(arr2, size2);
	std::sort(arr2, arr2 + size2);
	pos = BinarySearch(arr2, size2, range);
	elpased_t = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << pos << ", " << elpased_t << std::endl;

	begin = 0;
	end = 0;
	elpased_t = 0;
	begin = clock();
	arrPtr = MakeRandArr(arr3, size3);
	std::sort(arr3, arr3 + size3);
	pos = BinarySearch(arr3, size3, range);
	elpased_t = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << pos << ", " << elpased_t << std::endl;
}

int main()
{
	std::cout << "\nBinary Search\n\n";
	BSearchTest();
	std::cout << "\nLinear Search\n\n";
	LSearchTest();
	std::cout << "\nfinished!!\n\n";
	std::cin.get();

	return 0;
}