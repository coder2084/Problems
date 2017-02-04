#pragma once
#include "Solution.h"
#include "SharedPtr.h"

template<typename T>
class WeakPtr
{
protected:
	T* mpValue;
	int* mpRefCount;
	template <typename U> friend class SharedPtr;

public:

	WeakPtr()
		: mpValue(nullptr)
		, mpRefCount(nullptr)
	{

	}

	WeakPtr(const WeakPtr<T>& weakPtr)
		: mpValue(weakPtr.mpValue)
		, mpRefCount(weakPtr.mpRefCount)
	{
		if (mpRefCount)
			++(*mpRefCount);
	}

	WeakPtr(WeakPtr<T>&& weakPtr)
		: mpValue(weakPtr.mpValue)
		, mpRefCount(weakPtr.mpRefCount)
	{
		weakPtr.mpValue = nullptr;
		weakPtr.mpRefCount = nullptr;
	}

	//construct from shared pointer
	WeakPtr(const SharedPtr<T>& sharedPtr)
		: mpValue(sharedPtr.mpValue)
		, mpRefCount(sharedPtr.mpRefCount)
	{
		if (mpRefCount)
			++(*mpRefCount);
	}

	~WeakPtr()
	{
		if (--(*mpRefCount) == 0)
			delete mpRefCount;
	}

	WeakPtr& operator=(const WeakPtr<T>& weakPtr)
	{
		if (mpRefCount != weakPtr.mpRefCount)
		{
			//release old reference
			if (mpRefCount && --(*mpRefCount) == 0)
				delete mpRefCount;

			//add new reference
			mpValue = weakPtr.mpValue;
			mpRefCount = weakPtr.mpRefCount;
			if (mpRefCount)
				++(*mpRefCount);
		}

		return *this;
	}

	WeakPtr<T>& operator=(const SharedPtr<T>& sharedPtr)
	{
		if (mpRefCount != sharedPtr.mpRefCount)
		{
			//release old reference
			if (mpRefCount && --(*mpRefCount) == 0)
				delete mpRefCount;

			//add new reference
			mpValue = sharedPtr.mpValue;
			mpRefCount = sharedPtr.mpRefCount;
			if (mpRefCount)
				++(*mpRefCount);
		}

		return *this;
	}

	SharedPtr<T> lock() const
	{
		//this should be thread safe
		shared_ptr<T> temp;
		temp.mpRefCount = mpRefCount ? ++(*mpRefCount) ? mpRefCount;

		if (temp.mpRefCount)
			temp.mpValue = mpValue;

		return temp;
	}
};

class WeakPtrTest : public Solution
{
public:
	void Test()
	{
		SharedPtr<int> sp(new int(100));

		WeakPtr<int> wp(sp);


		WeakPtr<int> wp2;
		wp2 = sp;
		
		WeakPtr<int> wp3(wp2);
	}
};
