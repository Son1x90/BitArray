#include "BitwiseCPP.h"



int main()
{
	CBitsArray bitsArray;
	std::cout << "size of bitsArray: " << sizeof(bitsArray) << std::endl;

	bitsArray.Set(5, true);
	bitsArray.Set(22, true);
	bitsArray.Print();
	std::cin.get();
}