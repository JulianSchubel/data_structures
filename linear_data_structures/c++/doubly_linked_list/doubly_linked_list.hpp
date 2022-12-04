#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <iostream>

namespace linked_lists
{

	template <typename t> struct dll_node {
		t value;
		dll_node *next;
		dll_node *previous;
	};

	/* Forward declarations for output stream overload */
	template <typename t> class dll;
	template <typename t> std::ostream& operator <<(std::ostream&, const dll<t>&);

	template <typename t> class dll
	{
		friend std::ostream& operator << <>(std::ostream&, const dll<t>&);
		public:
			dll(t value = 0);
			/* big three */
			dll(const dll<t>&);
			~dll();
			dll<t>& operator =(const dll<t>&);
		
			void push(t value);
			t pop();
			void reverse();
		protected:
		private:
			void copy(const dll<t>&);
			int length;
			struct dll_node<t> *head;
	};
}

#include "./doubly_linked_list.cpp"
#endif /* DOUBLY_LINKED_LIST_H */ 
