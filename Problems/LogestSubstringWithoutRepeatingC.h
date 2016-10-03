#pragma once
#include "Solution.h"

class LongestSubstring :public Solution
{
private:
	int lengthOfLongestSubstring(string s) {
		int result = 0, cur = 0, head = 0;
		unordered_map<char, int> mp;

		for (size_t i = 0; i < s.length(); i++) {
			if (mp.find(s[i]) == mp.end()) {
				mp[s[i]] = i;
				cur++;
			}
			else {
				head = max(mp[s[i]], head);
				cur = min(i - mp[s[i]], i - head);

				mp[s[i]] = i;
			}
			result = (result > cur) ? result : cur;
		}

		return result;
	}

public:
	void Test()
	{
		string test = "TestlengthOfLongestSubstring";

		cout << "Solution for Longest Substring without repeating characters for " << test << ": " << lengthOfLongestSubstring(test) << endl;
	}

};