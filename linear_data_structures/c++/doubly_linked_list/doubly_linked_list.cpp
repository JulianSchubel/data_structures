#include "./doubly_linked_list.hpp"

namespace linked_lists 
{
	template <typename t> dll<t>::dll(t value)
	{
		length = 0;
		head = new(struct dll_node<t>);
		head->value = value;
		head->next = NULL;
		head->previous = NULL;
	}

	template <typename t> dll<t>::~dll()
	{
		struct dll_node<t> *temp;
		while(head != NULL) {
			temp = head;
			head = head->next;
			delete(temp);
		}
	}

	template <typename t> dll<t>::dll(const dll<t>&obj)
	{
		this->length = obj.length;
		this->copy(obj);
	}

	template <typename t> dll<t>& dll<t>::operator =(const dll<t>&obj)
	{
		this->length = obj.length;
		this->copy(obj);
	}

	template <typename t> void dll<t>::push(t value)
	{
		struct dll_node<t> *new_node = new(struct dll_node<t>);
		new_node->value = value;
		new_node->next = head;
		new_node->previous = NULL;
		head->previous = new_node;
		head = new_node;
		++length;
	}

	template <typename t> t dll<t>::pop()
	{
		if(length > 0) {
			struct dll_node<t> *old_node = head;
			t value = head->value;
			head = head->next;
			head->previous = NULL;
			delete(old_node);
			--length;
			return value;
		}
		std::cout << __LINE__ << ": Attempted to pop from an empty list" << std::endl;
        std::exit(EXIT_FAILURE);
	}

	template <typename t> void dll<t>::copy(const dll<t>&obj)
	{
		struct dll_node<t> *cursor = obj.head;
		head = new(struct dll_node<t>);
		if(cursor != NULL) {
			head->value = cursor->value;
			head->next = NULL;
			head->previous = NULL;
			cursor = cursor->next;
		}
		else {
			head->value = 0;
			head->next = NULL;
			head->previous = NULL;
		}
		struct dll_node<t> *temp = head; 
		while(cursor != NULL) {
			struct dll_node<t> *new_node = new(struct dll_node<t>);
			new_node->value = cursor->value;
			new_node->next = NULL;
			new_node->previous = temp;
			temp->next = new_node;
			temp = new_node; 
			cursor = cursor->next;
		}
	}

	template <typename t> void dll<t>::reverse() {
		struct dll_node<t> *cursor = head;
		struct dll_node<t> *last = head;
		while(cursor != NULL) {
			struct dll_node<t> *temp = cursor->next;
			cursor->next = cursor->previous;
			cursor->previous = temp;
			last = cursor;
			cursor = temp;
		}
		head = last;
	}

	template <typename t> std::ostream& operator <<(std::ostream& outs, const dll<t>&obj)
	{
		struct dll_node<t> *cursor = obj.head;
		while(cursor != NULL) {
			outs << cursor->value << " ";
			cursor = cursor->next;
		}
		return outs;
	}
}
