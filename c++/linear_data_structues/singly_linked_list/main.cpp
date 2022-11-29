#include <iostream>
#include "./singly_linked_list.hpp"

int main()
{
	sll::singly_linked_list list = sll::singly_linked_list<double>(0);
	list.push(1);
	list.push(2);
	sll::singly_linked_list list2 = list;
	std::cout << list2 << std::endl;
	list.pop();
	std::cout << list << std::endl;
	std::cout << list2 << std::endl;
	return 0;
}
