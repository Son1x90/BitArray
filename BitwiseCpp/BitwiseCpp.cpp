// BitwiseCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "BitwiseCPP.h"


CBitsArray::CBitsArray()
{
	m_count = 0;
}

const bool CBitsArray::Get(size_t idx)
{
	if (idx > Length() - 1)
		return 0;

	unsigned char bitMask = 1 << (idx % 8);
	return m_bitsArray[idx / 8] & bitMask;
}

void CBitsArray::Set(int idx, bool value)
{
	if (idx > (Length() - 1))
		Resize(idx + 1);

	auto currentByte = &m_bitsArray[GetByteFromBit(idx)];
	*currentByte |= (1 << (idx % 8));
}

int CBitsArray::Length()
{
	return m_count;
}

void CBitsArray::Resize(size_t newBitsSize)
{
	size_t newByteSize = GetByteFromBit(newBitsSize);
	newByteSize++;

	m_bitsArray.resize(newByteSize, 0);
	m_count = newByteSize * 8;
}

void CBitsArray::Print()
{
	for (size_t i = 0; i < Length(); i++)
		std::cout << "Bit" << i << ":" << Get(i) << std::endl;
}

//interesting observation order that came through during debugging: 23,25,24
int CBitsArray::GetByteFromBit(size_t bitIndex)
{
	return (bitIndex / 8);
}
