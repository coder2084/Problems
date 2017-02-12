#pragma once
#include "Solution.h"
/*
Objec­tive: Given a amount ‘A’ and n coins,   v1<v2<v3<.….……<vn . 
Write a pro­gram to find out min­i­mum num­bers of coins required to make the change for the amount ‘A’.
*/

class CoinChange : public Solution
{
private:
	map<int, int> memo;

	int Solve(int amount, vector<int>& coins) 
	{
		if (amount == 0) return 0;

		int res = std::numeric_limits<int>::max();

		for (size_t i = 0; i < coins.size(); ++i)
		{
			if (coins[i] <= amount)
			{
				int subRes = Solve(amount - coins[i], coins);

				if (subRes != numeric_limits<int>::max() && subRes+1 < res)
					res = subRes + 1;
			}
		}

		return res;	
	}

	int SolveDynamic(int amount, vector<int>& coins)
	{
		if (amount == 0) return 0;

		if (memo.find(amount) != memo.end())
			return memo[amount];

		int res = std::numeric_limits<int>::max();

		for (size_t i = 0; i < coins.size(); ++i)
		{
			if (coins[i] <= amount)
			{
				int subRes = SolveDynamic(amount - coins[i], coins);

				if (subRes != numeric_limits<int>::max() && subRes + 1 < res)
					res = subRes + 1;
			}
		}

		memo[amount] = res;

		return res;
	}

public:
	void Test()
	{
		int amount = 15;
		vector<int> coins = { 1,2,5,10 };

		cout << "Minimum coin change recursive : " << Solve(amount, coins) << endl;

		cout << "Minimum coin change dynamic : " << SolveDynamic(amount, coins) << endl;
	}
};
