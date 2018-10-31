#include<iostream>

using namespace std;

namespace jack
{
	template<class T>
	class auto_ptr
	{
		pubilc:
		explicit auto_ptr(T* p=NULL):pointer(p){}
		template<class U>
		auto_ptr(auto_ptr<U> &rhs):pointer(rhs.release()){}
		~auto_ptr(){delete pointer;}
		}
		template<class U>
		auto_ptr<T>& operator=(auto_ptr<U>& rhs)
		{
			if(this!=&rhs) reset(rhs.release());
			return *this
		}
		T& operator*() const
		{
			return *pointer;
		}
		T* operator->() const
		{
			return pointer;
		}
 		private:
		T* pointer;	
	};	
}; 










