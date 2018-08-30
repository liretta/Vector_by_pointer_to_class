#include "A.h"
#include"Template_Point_toClass.hpp"
#include "B.h"
#include <memory>
#include <vector>
#include <algorithm>
#define classWork

//pointer to class, overload type-operator and assignment operator

int main()
{

#ifndef classWork
	
	std::vector<std::shared_ptr<A> > vcSh;
	for (int i = 0; i < 10;++i)
		vcSh.push_back(std::shared_ptr<A>(new A(rand() % 21)));
		
	std::shared_ptr<A> sh(new A(5)), sh0;
	if (sh.get() != 0)
		std::cout << sh->GetA() << std::endl;

	A a(8);
	std::cout << a << std::endl;

	//emplementation search in vector by smart-ptr
	std::vector<std::shared_ptr<A> >::iterator iter, itEnd = vcSh.end(), it5;
	for(iter=vcSh.begin(); iter < itEnd; ++iter)
		std::cout <<' ' << *(*iter);

	std::cout << std::endl;
	it5 = std::find_if(vcSh.begin(), vcSh.end(), PointToClassCompare<A>(&a));
	if (it5 != vcSh.end())
		std::cout << *(*it5);// dereference iterator, then dereference shared_ptr
	std::cout << std::endl;

    //new class B
	std::vector <B*> vcB;
	for (int i = 0; i < 10; ++i)
		vcB.push_back(new B(rand() % 20));
	
	B b(5);
	
	std::vector <B*>::iterator it15;
	it15 = std::find_if(vcB.begin(), vcB.end(), [&b](const B* pB) {return b == *pB;});
	std::cout << *(*it15) << std::endl;

	int n(10), m(5);
	auto pFn = [n, &m]() {/*n += 2;*/ m += 2; std::cout << "n: " << n << std::endl;};
	m = 20;
	n = 20;
	pFn();
	std::cout << n << ' ' << m << std::endl;

#endif // !classWork

	//delete from vector
	std::vector <int> vcI;
	for (int i = 0; i < 10; ++i)
		vcI.push_back(rand()%20);

	std::vector<int>::iterator iterI, itBegI, itEndI = vcI.end(), itLogEnd;
	for (iterI = vcI.begin(); iterI < itEndI; ++iterI)
		std::cout << ' ' << *iterI;
	std::cout << std::endl;

	itLogEnd = std::remove(vcI.begin(), vcI.end(), 2); 
	
	for (int i = 0, nSize = vcI.size();i < nSize; ++i)
		std::cout << vcI[i] << ' ';
	std::cout << std::endl;

	for (itBegI = vcI.begin(); itBegI < itLogEnd; ++itBegI)
		std::cout << *itBegI << ' ' << std::endl;

	std::cout << "Size: " << vcI.size() << " capacity: " << vcI.capacity() << std::endl;
	vcI.erase(itLogEnd, vcI.end());
	std::cout << "Size: " << vcI.size() << " capacity: " << vcI.capacity() << std::endl;

	vcI.shrink_to_fit();
	std::cout << "Size: " << vcI.size() << " capacity: " << vcI.capacity() << std::endl;

	////////remove for class A
	std::vector <A> vcA;
	for (int i = 0; i < 20; ++i)
		vcA.push_back(rand() % 20);

	std::vector<A>::iterator iterA, itBegA, itEndA = vcA.end(), itLogEndA;
	for (iterA = vcA.begin(); iterA < itEndA; ++iterA)
		std::cout << ' ' << *iterA;
	std::cout << std::endl;

	itLogEndA = std::remove(vcA.begin(), vcA.end(), 2); 
													   
	for (int i = 0, nSize = vcA.size();i < nSize; ++i)
		std::cout << vcA[i] << ' ';
	std::cout << std::endl;

	for (itBegA = vcA.begin(); itBegA < itLogEndA; ++itBegA)
		std::cout << *itBegA << ' ' << std::endl;

	std::cout << "Size: " << vcA.size() << " capacity: " << vcA.capacity() << std::endl;
	vcA.erase(itLogEndA, vcA.end());
	std::cout << "Size: " << vcA.size() << " capacity: " << vcA.capacity() << std::endl;

	vcI.shrink_to_fit();
	std::cout << "Size: " << vcA.size() << " capacity: " << vcA.capacity() << std::endl;

	std::unique_ptr<A> uni(new A(5));
	std::cout << *(uni) << std::endl;

	system("pause");
	return 0;
}