#ifndef HUFFMAN_DICT
#define HUFFMAN_DICT
#include <iostream>

struct CharUInt{
	char c;
	unsigned int i;
};

class HuffmanDict{
private:
	CharUInt *dict = nullptr;
	size_t manyItems = 0;
	size_t capacity = DEFAULT_CAPACITY;
	const static size_t DEFAULT_CAPACITY = 10;

public:
	HuffmanDict():
	dict(new CharUInt[DEFAULT_CAPACITY])
	{
	//	std::cout << size() << '\n';
	}
	
	HuffmanDict(size_t i_capacity):
	dict(new CharUInt[i_capacity]),
	capacity(i_capacity)
	{
	//	std::cout << size() << '\n';
	}

	//CharUInt& operator[](int c);
	
	unsigned int& operator[]
	(char c);
	
	CharUInt& operator()(size_t idx){ return dict[idx]; }

	CharUInt* getDict(){ return dict; }

	size_t size()const { return manyItems; }

	size_t getCapacity()const { return capacity; }

	bool isEmpty()const { return manyItems == 0;}

	void reallocate();

	~HuffmanDict();

	friend std::ostream& operator<<(
	std::ostream &out, const HuffmanDict &d);

	friend std::istream& operator>>(
	std::istream &in, HuffmanDict &d);
};
#endif
