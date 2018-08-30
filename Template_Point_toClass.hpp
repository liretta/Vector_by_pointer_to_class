#include <memory>

template <typename T>

class PointToClassCompare
{
	T*mpT;
public:
	PointToClassCompare (T*pT):mpT(pT) {}
	/*bool operator()(T*pT)
	{
		return *mpT == *pT;
	}*/

	/*bool operator() (const std::shared_ptr<T>&rSh)
	{
		return *mpT == *rSh;
	}*/
};