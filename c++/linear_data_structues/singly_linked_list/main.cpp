#include <iostream>
#include "./singly_linked_list.hpp"

int main()
{
	linked_lists::sll list = linked_lists::sll<double>(0);
	list.push(1);
	list.push(2);
	linked_lists::sll list2 = list;
	std::cout << list2 << std::endl;
	list.pop();
	std::cout << list << std::endl;
	std::cout << list2 << std::endl;
	return 0;
}
