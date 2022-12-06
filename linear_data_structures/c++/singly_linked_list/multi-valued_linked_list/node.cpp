#include "./node.hpp"

node::node() 
{
	is_int = true;
	is_dbl = false; 
	is_char = false;
	is_str = false;
	int_value = 0;		
	next = NULL;
}

node::node(int v)
{
	is_int = true;
	is_dbl = false; 
	is_char = false;
	is_str = false;
	int_value = v;
	next = NULL;
}

node::node(double v)
{
	is_int = false;
	is_dbl = true; 
	is_char = false;
	is_str = false;
	dbl_value = v;
	next = NULL;
}

node::node(char v)
{
	is_int = false;
	is_dbl = false; 
	is_char = true;
	is_str = false;
	char_value = v;
	next = NULL;
}

node::node(std::string v)
{
	is_int = false;
	is_dbl = false; 
	is_char = false;
	is_str = true;
	str_value = v;
	next = NULL;
}

node::~node() 
{
	/* Node memory will be release by the list */
}

/* copy constructor: called whenever such an object is created from another object of the same class, passed as argument, returned, etc */
node::node(const node& obj)
{
	is_int = obj.is_int;
	is_dbl = obj.is_dbl;
	is_char = obj.is_char;
	is_str = obj.is_str;

	int_value = obj.int_value;
	dbl_value = obj.dbl_value;
	char_value = obj.char_value;
	str_value = obj.str_value;

	/* Shallow copy other node next pointer */				
	next = obj.next;
}

/* overloaded assignment: defines object assignment behaviour. Object reference return value allows for chained assignments */
node& node::operator =(const node& obj)
{
	is_int = obj.is_int;
	is_dbl = obj.is_dbl;
	is_char = obj.is_char;
	is_str = obj.is_str;

	int_value = obj.int_value;
	dbl_value = obj.dbl_value;
	char_value = obj.char_value;
	str_value = obj.str_value;

	/* Shallow copy other node next pointer */				
	next = obj.next;

	return *this;
}

input_t node::check_value() const 
{
	if(is_int) {
		return input_t::INT;
	}
	else if(is_dbl) {
		return input_t::DBL;
	}
	else if(is_char) {
		return input_t::CHAR;
	}
	else if(is_str) {
		return input_t::STR;
	}
	return input_t::UNKNOWN;
}

int node::get_int_value() const 
{
	return this->int_value;
}
