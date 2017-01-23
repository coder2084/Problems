#include "TwoSum.h"
#include "AddTwoNumbers.h"
#include "LogestSubstringWithoutRepeatingC.h"
#include "NextPermuationSameDigits.h"
#include "Permuations.h"
#include "CoinChange.h"

int main(int argc, char* argv[])
{
	vector<shared_ptr<Solution>> v;
	v.push_back(std::make_unique<TwoSum>());
	v.push_back(std::make_unique<AddTwoNumbers>());
	v.push_back(std::make_unique<LongestSubstring>());
	v.push_back(std::make_unique<NextPermuation>());
	v.push_back(std::make_unique<Permutations>());
	v.push_back(std::make_unique<CoinChange>());

	for (auto&& elem : v)
	{
		elem->Test();
	}

	return 0;
}