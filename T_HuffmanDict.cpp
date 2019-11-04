#include <iostream>
#include "HuffmanDict.h"

int main(){
	std::cout << "Calling default constructor:\n";
	HuffmanDict h(3);
	std::cout << h << '\n'
	<< "------------------------------------\n";

	std::cout << "Setting a to 5:\n";
	h['a'] = 5;
	std::cout << "a: " << h['a'] << '\n';
	std::cout << "Setting b to 3:\n";
	h['b'] = 3;
	std::cout << "b: " << h['b'] << '\n';
	std::cout << "Setting c to 6:\n";
	h['c'] = 6;
	std::cout << "c: " << h['c'] << '\n';
	std::cout << "Expected: {(a,5),(b,3),(c,6)}\n";
	std::cout << h << '\n'
	<< "------------------------------------\n";
	

	CharUInt *data;
	data = h.getDict();
	std::cout << "Using the getDict() to return a"
		<< " pointer to the array in dict:\n";
	for (size_t i = 0; i < h.size(); ++i){
		std::cout << data[i].c << ',' 
		<< data[i].i << '\n';
	}

	std::cout 
	<< "------------------------------------\n";
	std::cout << "Using functor to get each CharUInt:\n";
	CharUInt temp;
	for (size_t i = 0; i < h.size(); ++i){
		temp = h(i);
		std::cout << temp.c << ','
		<< temp.i << '\n';
	}
	std::cout 
	<< "------------------------------------\n";
	std::cout << "Testing the reallocate function:\n";
	h['d'] = 10;
	std::cout << "Expect: {(a,5),(b,3),(c,6),(d,10)}\n";
	std::cout << "h: "<< h << '\n';

	return 0;
}
