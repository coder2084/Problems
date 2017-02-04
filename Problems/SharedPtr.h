#pragma  once
#include "Solution.h"
#include <assert.h>
#include <utility>

template<class T>
class SharedPtr
{
protected:
	T* mpValue;
	int* mpRefCount;

	template <typename U> friend class WeakPtr;

public:
	SharedPtr()
		: mpValue(nullptr),
		mpRefCount(nullptr)
	{

	}

	explicit SharedPtr(T* pValue)
	{
		mpRefCount = new int(1);
		mpValue = pValue;
	}

	SharedPtr(std::nullptr_t) 
		: mpValue(nullptr), 
		  mpRefCount(nullptr) 
	{
	
	}

	SharedPtr(const SharedPtr<T>& sharedPtr)
		: mpValue(sharedPtr.mpValue),
		mpRefCount(sharedPtr.mpRefCount)
	{
		if (mpRefCount)
			++(*mpRefCount);
	}

	SharedPtr(SharedPtr&& sharedPtr)
		: mpValue(sharedPtr.mpValue),
		mpRefCount(sharedPtr.mpRefCount)
	{
		sharedPtr.mpValue = nullptr;
		sharedPtr.mpRefCount = nullptr;
	}

	~SharedPtr()
	{
		if (mpRefCount && --(*mpRefCount) == 0)
		{
			delete mpRefCount;
			delete mpValue;
		}
	}

	SharedPtr<T>& operator=(const SharedPtr<T>& sharedPtr)
	{
		if (&sharedPtr != this)
			sharedPtr<T>(sharedPtr).swap(*this);

		return *this;
	}

	SharedPtr<T>& operator=(const SharedPtr<T>&& sharedPtr)
	{
		if (!equivalent_ownership(sharedPtr))
			SharedPtr(std::move(sharedPtr)).swap(*this);
		return *this;
	}


	//replaces the managed object
	void reset()
	{
		SharedPtr<T>().swap(*this);
	}

	//returns the stored pointer 
	T* get() const
	{
		return mpValue;
	}

	//dereferences the stored pointer 
	T& operator*() const
	{
		return *mpValue;
	}

	//dereferences the stored pointer 
	T* operator->() const
	{
		return mpValue;
	}

	int use_count() const
	{
		return mpRefCount ? *mpRefCount : 0;
	}

	explicit operator bool() const
	{
		return (mpValue != NULL);
	}

private:
	bool equivalent_ownership(const SharedPtr<T>& sharedPtr)
	{
		return (mpRefCount == sharedPtr.mpRefCount);
	}

	void swap(SharedPtr& sharedPtr)
	{
		std::swap(sharedPtr.mpValue, mpValue);
		std::swap(sharedPtr.mpRefCount, mpRefCount);
	}

};

class SharedPtrTest : public Solution
{
public:
	void Test()
	{
		
		SharedPtr<int> p1(new int(100));
		SharedPtr<int> sp(new int(200));
		assert(p1.use_count() == 1);
		assert(*p1 == 100);

		SharedPtr<int> p2 = p1;
		assert(p1.use_count() == 2);
		assert(p2.use_count() == 2);
		assert(*p1 == 100);
		assert(*p2 == 100);

		{
			SharedPtr<int> p3 = p1;
			assert(p1.use_count() == 3);
			assert(p3.use_count() == 3);
			assert(*p1 == 100);
			assert(*p3 == 100);
		}
		assert(p1.use_count() == 2);
		assert(p2.use_count() == 2);

		p1.reset();
		assert(p1.get() == nullptr);
		assert(p1.use_count() == 0);
		
		assert(p2.use_count() == 1);
		p2.reset();		
		assert(p2.use_count() == 0);

		SharedPtr<int> p3 = std::move(sp);
		p3 = std::move(p2);
		
	}
};