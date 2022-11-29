#include "./singly_linked_list.hpp"

namespace linked_lists
{
	/* destructor */
	template <typename t>
	sll<t>::~sll()
	{
			while(head != NULL) {
					struct sll_node<t> *temp = head;
					head = head->next;
					delete(temp);
			}
	}

	/* default constructor */
	template <typename t>
	sll<t>::sll(t value)
	{
			head = new(struct sll_node<t>);
			head->next = NULL;
			head->value = value;
			length = 1;
	}

	/* copy constructor */
	template <typename t>
	sll<t>::sll(const sll<t> &obj)
	{
		this->length = obj.length;
		this->copy(obj);
	}
	
	/* overloaded assignment operator */
	template <typename t>
	sll<t>& sll<t>::operator =(const sll<t>& obj)
	{
		this->length = obj.length;
		this->copy(obj);
	}


	template <typename t>
	void sll<t>::push(t value)
	{
		struct sll_node<t> *new_node = new(struct sll_node<t>);
		new_node->next = head;
		new_node->value = value;
		this->head = new_node;
		++length;
	}
	
	template <typename t>
	t sll<t>::pop()
	{
		if(length > 0) {
			t temp = head->value;	
			struct sll_node<t> *old_node = head;
			head = head->next;
			delete(old_node);
			--length;
			return temp;
		}
		std::cout << __LINE__ << ": Attempted to pop from an empty list" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	/* overloaded insertion operator */
	template <typename t>
	std::ostream& operator <<(std::ostream& outs, const sll<t> &obj)
	{
		struct sll_node<t> *cursor = obj.head;
		while(cursor != NULL) {
			std::cout << cursor->value << " ";
			cursor = cursor->next;
		}
		return outs;
	}

	/* conveience copy function */
	template <typename t>
	void sll<t>::copy(const sll<t> &obj)
	{
		struct sll_node<t> *cursor = obj.head;
		head = new(struct sll_node<t>);
		if(cursor != NULL) {
			head->value = cursor->value;
			head->next = NULL;
			cursor = cursor->next;
		}
		else {
			head->value = 0;
			head->next = NULL;
		}
		struct sll_node<t> *temp = head;
		while( cursor != NULL) {
			struct sll_node<t> *new_node = new(struct sll_node<t>);
			new_node->value = cursor->value;
			new_node->next = NULL;
			temp->next = new_node;
			temp = temp->next;
			cursor = cursor->next;
		}
	}
}
