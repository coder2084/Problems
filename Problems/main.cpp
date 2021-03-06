#include "TwoSum.h"
#include "AddTwoNumbers.h"
#include "LogestSubstringWithoutRepeatingC.h"
#include "NextPermuationSameDigits.h"
#include "Permuations.h"
#include "CoinChange.h"
#include "WordTransform.h"
#include "SharedPtr.h"
#include "WeakPtr.h"
#include "EditDistance.h"
#include "CountPath.h"
#include "LIS.h"
#include "LowerBound.h"
#include "SumRootToLeaf.h"
#include "BinaryTreePaths.h"
#include "MaxInSortedRotatedArray.h"
#include "Kruskal.h"
#include "Hamiltonian.h"

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
	v.push_back(std::make_unique<EditDistance>());
	v.push_back(std::make_unique<CountPath>());
	v.push_back(std::make_unique<SumRootToLeaf>());
	v.push_back(std::make_unique<BinaryTreePaths>());
	v.push_back(std::make_unique<Kruskal>());
	v.push_back(std::make_unique<Hamiltonian>());

	for (auto&& elem : v)
	{
		elem->Test();
	}

	return 0;
}
