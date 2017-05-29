#pragma once
#include "solution.h"
/*
Find the maximum number in sorted rotated array
i.e.:
arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
Result = 10
*/

class MaxInSortedRotatedArray : public Solution
{
private:
	int Solve(vector<int>& arr)
	{
		//int m = arr[0];
		return arr[BinarySearch(arr, 0, arr.size())];
	}

	int BinarySearch(vector<int>& arr, size_t l, size_t r)
	{
		if (l > r)
			return arr[arr.size() - 1];
		size_t mid = (l + r) / 2;
		int prevIndex = (mid == 0) ? arr.size() - 1 : mid - 1;;
		int nextIndex = (mid == (arr.size() - 1)) ? 0 : mid + 1;
		if (arr[mid] > arr[prevIndex] && arr[mid] > arr[nextIndex])
			return mid;
		else if (arr[mid] < arr[l])
			return BinarySearch(arr, l, mid - 1);
		else
			return BinarySearch(arr, mid + 1, r);
	}

public:
	void Test()
	{
		vector<int> arr = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
		
		cout << "Maximum in a sorted and rotated array: " << Solve(arr) << endl;
	}
};
