#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
namespace sll
{
	/* forward declaration for output stream friend operator */
	template <typename t> class singly_linked_list;
	template <typename t> std::ostream& operator <<(std::ostream&, const singly_linked_list<t>& obj);

	template <typename t>
	struct sll_node {
		t value;
		sll_node *next;
	};


	template <typename t>
	class singly_linked_list
	{
		friend std::ostream& operator << <>(std::ostream&, const singly_linked_list&);
		public:
			singly_linked_list(t value=0);
			singly_linked_list(const singly_linked_list<t>&);
			~singly_linked_list();
			singly_linked_list<t>& operator =(const singly_linked_list<t>&);	
			/* push: prepend a new node to the list */
			void push(t value);
			/* pop: remove the top node of the list and return its value */	
			t pop();
		protected:
		private:
			/* copy: copies the values of the argument's nodes in a new list of nodes attached to head */
			void copy(const singly_linked_list<t>&);
			int length;
			struct sll_node<t> *head;
	};
}

#include "./singly_linked_list.cpp"
#endif //LINKED_LIST_H
