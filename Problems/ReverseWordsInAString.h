#pragma once
#include "solution.h"

class ReverseWords : public Solution
{
private:
	void reverseWord(string&s, int start, int end)
	{
		while (start < end)
		{
			swap(s[start], s[end]);
			start++;
			end--;
		}
	}
	string& reverseWords(string &s)
	{
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == ' ')
				continue;
			int startIndex = i;
			int endIndex = i;
			while (i++ < s.length()-1 && s[i] != ' ')
				endIndex++;

			reverseWord(s, startIndex, endIndex);
		}

		reverseWord(s, 0, s.length()-1);

		return s;
	}
public:
	void Test()
	{
		string test = " ";
		cout << "ReverseWordsr [" << test << "] is: " << reverseWords(test) << endl;
	}
};