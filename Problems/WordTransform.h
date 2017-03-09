#pragma once
#include "Solution.h"

/*
Given a source word, target word and an English dictionary, transform the source word to target 
by changing/adding/removing 1 character at a time, while all intermediate words being valid English 
words. Return the transformation chain which has the smallest number of intermediate words.
*/

class WordTransform : public Solution
{
private:
	map<const string*,unordered_set<const string*>> graph;	

	void AddEdge(const string* from, const string* to)
	{
		graph[from].insert(to);
		graph[to].insert(from);
	}

	void ProcessDictionary(unordered_set<string> dictionary)
	{
		string tmp;
		string letters("abcdefghijklmnopqrstuvwxyz");
		for (auto& s:dictionary )
		{
			for (size_t i = 0; i < s.length(); i++)
			{
				//remove one letter
				tmp = s.substr(0, i) + s.substr(i + 1, s.length() - 1 - i);
				auto w = dictionary.find(tmp);
				if ( w!= dictionary.end())
				{
					AddEdge(&s, &(*w));
				}

				//change character
				for (auto l : letters)
				{
					tmp = s;
					tmp[i] = l;
					auto w = dictionary.find(tmp);
					if ( w != dictionary.end() && tmp != s)
					{
						AddEdge(&s, &(*w));
					}
				}
			}
		}
	}

	vector<const string*> WordTransformPath(string source, string target,unordered_set<string> dictionary)
	{
		ProcessDictionary(dictionary);
		vector<const string*> path;

		set<const string*> visited;
		queue<const string*> q;
		auto s = dictionary.find(source);
		q.push(&(*s));
		path.push_back(&(*s));
		visited.insert(&(*s));
		while (!q.empty())
		{
			auto w = q.front();
			visited.insert(w);
			auto neighbourhs = graph[&(*w)];
			for (auto& n : neighbourhs)
				if (visited.find(&(*n)) == visited.end())
				{
					q.push(&(*n));
					visited.insert(&(*n));
				}

		}

		return path;
	}

	int LadderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
		unordered_set<string> head, tail, *phead, *ptail;
		head.insert(beginWord);
		tail.insert(endWord);
		int dist = 2;
		while (!head.empty() && !tail.empty()) {
			if (head.size() < tail.size()) {
				phead = &head;
				ptail = &tail;
			}
			else {
				phead = &tail;
				ptail = &head;
			}
			unordered_set<string> temp;
			for (auto itr = phead->begin(); itr != phead->end(); itr++) {
				string word = *itr;
				wordDict.erase(word);
				for (int p = 0; p < (int)word.length(); p++) {
					char letter = word[p];
					for (int k = 0; k < 26; k++) {
						word[p] = 'a' + k;
						if (ptail->find(word) != ptail->end())
							return dist;
						if (wordDict.find(word) != wordDict.end()) {
							temp.insert(word);
							wordDict.erase(word);
						}
					}
					word[p] = letter;
				}
			}
			dist++;
			swap(*phead, temp);
		}
		return 0;
	}

public:
	void Test()
	{
		unordered_set<string> dictionary = { "cat","cap","cas","caz","bat","cet","crt","bar","car","ber","bed"};
		string source = "cat";
		string target = "bed";
		
		cout << "WordTransform [" << source << "," << target << "] is =" << LadderLength(source, target, dictionary) << endl;
	}
	
};
