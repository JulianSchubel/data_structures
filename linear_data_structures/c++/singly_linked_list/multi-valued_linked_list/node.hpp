#ifndef MULTIVALUED_NODE_H
#define MULTIVALUED_NODE_H
#include <iostream>
#include <string>

typedef enum {
	INT=0,
	DBL,
	CHAR,
	STR,
	UNKNOWN
} input_t;

class node
{
	public:
		node();
		node(int);
		node(char);
		node(double);
		node(std::string);

		/* BIG THREE */
		~node();
		node(const node&);
		node& operator =(const node&);

		/* MUTATORS */
		void put_value(int);
		void put_value(double);
		void put_value(char);
		void put_value(std::string);
		void put_next(node *);
		
		/* ACCESSORS */		
		input_t check_value() const;
		int get_int_value() const;
		double get_double_value() const;
		char get_char_value() const;
		std::string get_str_value() const;
		node * get_next(void) const;

	protected:
	private:
		bool is_int;
		bool is_dbl;
		bool is_char;
		bool is_str;

		int int_value;
		double dbl_value;
		char char_value;
		std::string str_value;
		node *next;
};

#include "./node.cpp"
#endif //MULTIVALUED_NODE_H
