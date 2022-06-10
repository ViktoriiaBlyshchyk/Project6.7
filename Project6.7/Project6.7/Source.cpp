#include <iostream>

using namespace std;

template<class T>
class Predicate
{
public:
	virtual bool operator () (T x) = 0;
};

template<class T>
class LessThen6 : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x < 6;
	}
};

template<class T>
class Zero : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		T zero = T();
		return x == zero;
	}
};

template<class T>
class Positive : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x > 0;
	}
};

template<class T>
class Negative : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x < 0;
	}
};

template<class T>
class Even : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x % 2 == 0;
	}
};

template<class T>
class Odd : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x % 2 != 0;
	}
};

template<class T>
T min_element(T *begin, T *end)
{
 
    T min = *begin;
	for (T* from = begin; from < end; from++) 
		if (*from < min)
		{
			min = *from;
		}
	return min;
}

template<class T>
T min_element_if(T* begin, T* end, Predicate<T>& p)
{
	T min = *begin;
	for (T* from = begin; from < end; from++)
	{
		if (p(*from) && *from < min) 
		{
			min = *from;
		}
	}
	return min;
}

int main()
{
	int a[5] = { 3, -2, 5, -4, 6 }; 
	cout << "Min element = " << min_element(&a[0], &a[5]) << endl;

	Predicate<int>* pos = new Positive<int>(); 
	cout << "Min element( > 0) = " << min_element_if(&a[0], &a[5], *pos) << endl;

	Predicate<int>* les = new LessThen6<int>(); 
	cout << "Min element( < 6) = " << min_element_if(&a[0], &a[5], *les) << endl;
	
	return 0;
}
