#include "TwoSum.h"
#include "AddTwoNumbers.h"
#include "LogestSubstringWithoutRepeatingC.h"
#include "NextPermuationSameDigits.h"
#include "Permuations.h"
#include "CoinChange.h"
#include "WordTransform.h"
#include "SharedPtr.h"
#include "WeakPtr.h"


int main(int argc, char* argv[])
{
	vector<shared_ptr<Solution>> v;
	v.push_back(std::make_unique<TwoSum>());
	v.push_back(std::make_unique<AddTwoNumbers>());
	v.push_back(std::make_unique<LongestSubstring>());
	v.push_back(std::make_unique<NextPermuation>());
	v.push_back(std::make_unique<Permutations>());
	v.push_back(std::make_unique<CoinChange>());
	v.push_back(std::make_unique<WordTransform>());
	v.push_back(std::make_unique<SharedPtrTest>());
	v.push_back(std::make_unique<WeakPtrTest>());

	for (auto&& elem : v)
	{
		elem->Test();
	}

	cout << (1 << 1) << endl;

	return 0;
}