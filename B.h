#pragma once

class B
{
	int mb;
public:
	B(int b) :mb(b) {}
	int getA() { return mb; }
	operator int() const
	{
		return mb;
	}
};