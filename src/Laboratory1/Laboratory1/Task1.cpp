#include "DynamicArray.h"
#include <algorithm>
#include <iostream>

using namespace std;

int SumArrayRecursive(int arr[], int n)
{
	if (n == 0) // n
	{
		return 0; // 1
	}
	return arr[n - 1] + SumArrayRecursive(arr, n - 1); //1+n


}
// O(n)