#include <iostream>
#include <string>
#include <vector>

class CBitsArray
{
public:
	CBitsArray();

	const bool Get(size_t idx);
	void Set(int idx, bool value);
	int Length();
	void Resize(size_t newBitsSize);
	void Print();

private:
	int GetByteFromBit(size_t bitIndex);

	std::vector<char> m_bitsArray;
	size_t m_count;
};
