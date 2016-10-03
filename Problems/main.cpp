#include "TwoSum.h"
#include "AddTwoNumbers.h"

int main(int argc, char* argv[])
{
	vector<shared_ptr<Solution>> v;
	v.push_back(std::make_shared<TwoSum>());
	v.push_back(std::make_shared<AddTwoNumbers>());

	for (auto&& elem : v)
	{
		elem->Test();
	}

	return 0;
}