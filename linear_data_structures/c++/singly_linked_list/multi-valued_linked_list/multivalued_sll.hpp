#include "./node.hpp"
#include <iostream>

class multivalued_sll
{
	public:
		multivalued_sll();
		~multivalued_sll();
		multivalued_sll& multivalued_sll(const multivalued_sll&);
		multivalued_sll& operator =(const multivalued_sll&);

	protected:
	private:
		node * head;
}
