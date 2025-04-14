#include <iostream>
#include "myarray.h"

int main() {
	myarray<int> arr;
	arr.addelem(5);
	arr.addelem(10);
	arr.addelem(15);
	arr.addelem(20);	

	std::cout << "array size: " << arr.size() << std::endl;
	std::cout << "array sum: " << arr.sum() << std::endl;

	std::cout << "array max: " << arr.maxi() << std::endl;	
	std::cout << "array min: " << arr.mini() << std::endl;

	myarray<int> sliced =  arr.slice(1, 3);
	std::cout << "sliced array size: " << sliced.size() << std::endl;
	std::cout << "sliced array: ";
	for (std::size_t i = 0; i < sliced.size(); ++i) {
		std::cout << sliced.at(i) << " ";
	}
	std::cout << std::endl;
	return 0;
}
