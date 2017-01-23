#include "TwoSum.h"
#include "AddTwoNumbers.h"
#include "LogestSubstringWithoutRepeatingC.h"
#include "WordTransform.h"
#include "FrequencySort.h"
#include "MergeTwoSortedArrays.h"
#include "ReverseWordsInAString.h"

int main(int argc, char* argv[])
{
	vector<shared_ptr<Solution>> v;
	v.push_back(std::make_shared<TwoSum>());
	v.push_back(std::make_shared<AddTwoNumbers>());
	v.push_back(std::make_shared<LongestSubstring>());
	v.push_back(std::make_shared<WordTransform>());
	v.push_back(std::make_shared<FrequencySort>());
	v.push_back(std::make_shared<MergeTwoSortedArrays>());
	v.push_back(std::make_shared<ReverseWords>());

	for (auto&& elem : v)
	{
		elem->Test();
	}

	return 0;
}