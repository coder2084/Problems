#pragma once
#include "solution.h"

class FrequencySort : public Solution
{
private:
	string frequencySort(string s) {
		unordered_map<char, int> freq;
		vector<string> bucket(s.size() + 1, "");
		string res;

		//count frequency of each character
		for (char c : s) freq[c]++;
		//put character into frequency bucket
		for (auto& it : freq) {
			int n = it.second;
			char c = it.first;
			bucket[n].append(n, c);
		}
		//form descending sorted string
		for (int i = s.size(); i > 0; i--) {
			if (!bucket[i].empty())
				res.append(bucket[i]);
		}
		return res;
	}

	string frequencySort2(string s)
	{
		char counts[256] = { 0 };
		for (auto c : s) counts[c]++;

		sort(s.begin(), s.end(), [&](char a, char b) { return counts[a] > counts[b] || (counts[a] == counts[b] && a < b); });

		return s;
	}

public:
	void Test()
	{
		string test = "tree";
		cout << "Frequency Sort for [" << test << "] and S=" << frequencySort2(test) << endl;
	}
};
