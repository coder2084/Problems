#pragma once
#include <memory> 
#include <iostream>

using std::cout;
using std::endl;

template<typename T, typename Deleter = std::default_delete<T>>
class my_unique_ptr
{
public:
	my_unique_ptr()
		:pointer(nullptr)
	{
		cout << ("my_unique_ptr() \n");
	}

	explicit my_unique_ptr(T* pValue)
		:pointer(pValue)
	{

		cout << ("my_unique_ptr() pValue\n");
	}

	my_unique_ptr(std::nullptr_t)
		:pointer(nullptr)
	{
		cout << ("my_unique_ptr() nullptr\n");
	}

	explicit my_unique_ptr(T* pValue, Deleter pfnDeleter)
		:pointer(pValue), deleter(pfnDeleter)
	{
		cout << ("my_unique_ptr() with deleter \n");
	}

	my_unique_ptr(my_unique_ptr<T, Deleter>&& x)
		: pointer(x.release()), deleter(std::forward<Deleter>(x.get_deleter()))
	{
		cout << "move constructor called " << endl;
	}

	T& operator*() const
	{
		return *pointer;
	}

	my_unique_ptr<T, Deleter>& operator=(my_unique_ptr<T, Deleter>&& x)
	{
		reset(x.release());
		deleter = std::move(std::forward<Deleter>(x.get_deleter()));
		return *this;
	}

	my_unique_ptr<T, Deleter>& operator=(std::nullptr_t)
	{
		reset();
		return *this;
	}

	~my_unique_ptr()
	{
		reset();
	}

	void reset(T* pValue = nullptr)
	{
		if (pValue != pointer)
		{
			get_deleter()(pointer);
			pointer = pValue;
		}
	}

	T* release()
	{
		T* const pTemp = pointer;
		pointer = nullptr;
		return pTemp;
	}

	///    struct X{ void DoSomething(); }; 
	///    unique_ptr<int> ptr(new X);
	///    ptr->DoSomething();
	T* operator->() const
	{
		return pointer;
	}

	operator bool() const
	{
		return (pointer != nullptr);
	}


	T* get() const
	{
		return pointer;
	}

	Deleter& get_deleter()
	{
		return deleter;
	}

protected:
	T* pointer;
	Deleter deleter;
};