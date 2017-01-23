#pragma once
#include "Solution.h"

class MergeTwoSortedArrays : public Solution
{
	private:
		vector<int>& merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
		{
			int i = m-1, j = n-1, k = m + n - 1;
			while (k >= 0)
			{
				if (i >=0 && j >= 0)
				{
					if (nums1[i] > nums2[j])
						nums1[k--] = nums1[i--];
					else
						nums1[k--] = nums2[j--];
				}
				else
				{
					while (i >= 0)
						nums1[k--] = nums1[i--];
					while (j >= 0)
						nums1[k--] = nums2[j--];
				}
			}

			return nums1;
		}

	public:
		void Test()
		{
			vector<int> v1 = { 1,7,9,14 };
			vector<int> v2 = { 2,3,6,10 };
			int m = v1.size();
			int n = v2.size();

			v1.resize(m + n);

			cout << "Solution for MergeTwoSortedArrays for " << v1 << " and " << v2 << ":\n " << merge(v1,m,v2,n) << endl;
		}
};

