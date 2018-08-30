#include <iostream>

class A
{
	int ma;
public:
	A(int a): ma(a) {}
	int GetA() { return ma; }
	bool operator== (const A&R)
	{
		return ma == R.ma;
	}
	friend std::ostream & operator<<(std::ostream &out, const A&a)
	{
		out << a.ma;
		return out;
	};

	/*operator int()
	{
		return ma;
	}*/
};