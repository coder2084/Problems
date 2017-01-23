#pragma once

template <class T> MySharedPtr
{
	private:
		T* ptr;
		int* rc;
	public:
		MySharedPtr(T* ptr) :ptr(ptr)
		{
			rc = new int;
		}

};