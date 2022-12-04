#include "./doubly_linked_list.hpp"

int main()
{
	linked_lists::dll list1 = linked_lists::dll<double>(0);
	list1.push(1);
	list1.push(2);
	std::cout << list1 << std::endl;
	list1.reverse();
	std::cout << list1 << std::endl;
	list1.pop();
	std::cout << list1 << std::endl;
	linked_lists::dll list2 = list1;
	std::cout << list2 << std::endl;
}
