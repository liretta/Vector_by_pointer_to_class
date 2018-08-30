#pragma once

class Array
{
	int ma;
	int *mpAr;
public:
	Array(int a) :ma(a) {}
	int get() { return ma; }
	operator int() const
	{
		return ma;
	}
};