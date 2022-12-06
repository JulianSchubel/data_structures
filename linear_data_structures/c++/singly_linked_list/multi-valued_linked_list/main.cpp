#include "./node.hpp"
#include <iostream>

int main()
{
	node n = node();
	input_t x = n.check_value(); 
	if(x == input_t::INT) {
		std::cout << "Node is an int value of: " << n.get_int_value() << std::endl;
	}	
}
