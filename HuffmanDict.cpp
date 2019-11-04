#include "HuffmanDict.h"
/*
CharUInt& HuffmanDict::operator[](int i)
{
	return dict[i];
}
*/

unsigned int& HuffmanDict::operator[]
(char c)
{
	for (size_t i = 0; i < manyItems; ++i){
		if (dict[i].c == c){
			return dict[i].i;
		}
	}
	if (manyItems == capacity)
		reallocate();
	CharUInt temp;
	temp.c = c;
	temp.i = 0;
	dict[manyItems] = temp;
	++manyItems;
	return dict[manyItems - 1].i;
}

void HuffmanDict::reallocate(){
	CharUInt *temp = dict;
	dict = new CharUInt[capacity * 2];
	for (size_t i = 0; i < manyItems; ++i)
		dict[i] = temp[i];
	capacity *= 2;
	delete[] temp;
}

HuffmanDict::~HuffmanDict(){
	if (dict)
		delete[] dict;
}

std::ostream& operator<<(std::ostream &out,
const HuffmanDict &d)
{
	out << '{';
	//std::cout << "Size of dict to be printed: "
	//	<< d.size() << '\n';
	//std::cout << (0 < d.size() - 1) << '\n';
	if (d.size() == 0){
		out << '}';
		return out;
	}
	for (size_t i = 0; i < d.size() - 1; ++i){
		//std::cout << "i: " << i << " d.size() - 1: "
		//<< (d.size() - 1) << "\n";
		out << '(' << d.dict[i].c 
		<< ',' <<  d.dict[i].i
		<< ')' << ',';
	}
	if (d.size() > 0)
		out << '(' 
		<< d.dict[d.size() - 1].c << ','
		<< d.dict[d.size()-1].i << ')';
	out << '}';
	return out;
}

std::istream& operator>>(std::istream &in,
HuffmanDict &d)
{
	return in;
}


