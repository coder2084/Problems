#pragma once
#include "Solution.h"
/*
Given an string and a dic­tio­nary of words, find out if the input string can be bro­ken into a space-separated
sequence of one or more dic­tio­nary words.
*/

class WordBreak : public Solution
{
private:
	set<string> dict;
public:
	string Solve(string s)
	{
		if (dict.find(s) != dict.end())
			return s;
		int len = s.length();
		for (int i = 1; i < len; ++i)
		{
			string prefix = s.substr(0, i);
			if (dict.find(prefix) != dict.end())
			{
				string suffix = s.substr(i, len - i-1);
				string segSuffix = Solve(suffix);
				if (segSuffix != "")
					return segSuffix + " " + segSuffix;
			}
		}
		
		return "";
	}
};
