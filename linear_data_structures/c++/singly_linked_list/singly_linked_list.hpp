#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
namespace linked_lists
{
	/* forward declaration for output stream friend operator */
	template <typename t> class sll;
	template <typename t> std::ostream& operator <<(std::ostream&, const sll<t>& obj);

	template <typename t>
	struct sll_node {
		t value;
		sll_node *next;
	};


	template <typename t>
	class sll
	{
		friend std::ostream& operator << <>(std::ostream&, const sll&);
		public:
			sll(t value=0);
			sll(const sll<t>&);
			~sll();
			sll<t>& operator =(const sll<t>&);	
			/* push: prepend a new node to the list */
			void push(t value);
			/* pop: remove the top node of the list and return its value */	
			t pop();
		protected:
		private:
			/* copy: copies the values of the argument's nodes in a new list of nodes attached to head */
			void copy(const sll<t>&);
			int length;
			struct sll_node<t> *head;
	};
}

#include "./singly_linked_list.cpp"
#endif //LINKED_LIST_H
