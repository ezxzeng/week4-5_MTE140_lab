#include "a1_doubly_linked_list.hpp"
#include <iostream>

DoublyLinkedList::Node::Node(DataType data)
{
	value = data;
}

DoublyLinkedList::DoublyLinkedList()
{
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
	return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
	if(size_ == 0) return true;
	return false;
}

bool DoublyLinkedList::full() const
{
	if(size_ == CAPACITY) return true;
	return false;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
	if(index >= size_ || index < 0){
		return tail_->value;
	}
	else{
		Node* select = head_;
		for(int i = 0; i < index; i++){
			select = select-> next;
		}
		return select->value;
	}
}

unsigned int DoublyLinkedList::search(DataType value) const
{
	if (size_ == 0) return 0;
	else{
		int i = 0;
		Node* select = head_;
		while(i < size_){
			if (select->value == value){
				return i;
			}
			else{
				select = select->next;
				i++;
			}
		}
		return size_;
	}
}

void DoublyLinkedList::print() const
{
	if(head_ == NULL) return;
	std::cout << "(";
	Node* node = head_;
	while(node != NULL){
		std::cout << "[" << node->value << "]" ;
		node = node->next;
		if (node!= NULL) std::cout << "-><-";
	}
	std::cout << "-> NULL" << std::endl;
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
	if (index > (size_ - 1)) return NULL;
    else if (index == (size_ - 1)) return tail_;
    else if (index > ((size_ - 1) / 2)) {
        Node* select = tail_;
        for (int i = 0; i < (size_ - 1 - index); i++) {
            select = select->prev;
        }
        return select;
    }
    else {
        Node* select = head_;
        for (int i = 0; i <= index; i++) {
            select = select->next;
        }
        return select;
    }
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	if(index > size_ || index < 0){
		return false;
	}
	else if(index == 0){
		return insert_front(value);
	}
	else if(index == size_){
		return insert_back(value);
	}
	else{
		Node* select = head_;
		for(int i = 0; i < index; i++){
			select = select-> next;
		}
		Node* temp = new Node(value);
		temp->prev = select->prev;
		temp->next = select;
		select->prev = temp;
		select = temp->prev;
		select->next = temp;
		size_++;
		return true;
	}
	return false;
}

bool DoublyLinkedList::insert_front(DataType value)
{
	if(size_ == 0){
		head_ = new Node(value);
		tail_ = head_;
		head_->prev = NULL;
		head_->next = NULL;
		size_ ++;
		return true;
	}
	else{
		Node* temp = head_;
		head_ = new Node(value);
		head_-> next = temp;
		head_-> prev = NULL;
		temp-> prev = head_;
		size_++;
		return true;
	}
	return false;
}

bool DoublyLinkedList::insert_back(DataType value)
{
	if(size_ == 0){
		head_ = new Node(value);
		tail_ = head_;
		head_->prev = NULL;
		head_->next = NULL;
		size_ ++;
		return true;
	}
	else{
		Node* temp = tail_;
		tail_ = new Node(value);
		temp->next = tail_;
		tail_->next = NULL;
		tail_-> prev = temp;
		size_++;
		return true;
	}
	return false;
}

bool DoublyLinkedList::remove(unsigned int index)
{
	if (index > (size_ - 1)) return false;
    else if (index == (size_ - 1)){
    	return remove_back();
	}
	else if (index == 0){
		return remove_front(); 
	}
	else{
		Node* temp = this->getNode(index);
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		temp = NULL;
		return true;
	}
}

bool DoublyLinkedList::remove_front()
{
	if(size_ == 0) return false;
	else if(size_ == 1){
		delete(head_);
		head_ = NULL;
		tail_ = NULL;
		size_ = 0;
		return true;
	}
	else{
		Node* temp = head_->next;
		delete(head_);
		head_ = temp;
		head_-> prev = NULL;
		size_--;
		return true;
	}
	return false;
}

bool DoublyLinkedList::remove_back()
{
	if(size_ == 0) return false;
	else if(size_ == 1){
		delete(tail_);
		head_ = NULL;
		tail_ = NULL;
		size_ = 0;
		return true;
	}
	else{
		Node* temp = tail_->prev;
		delete(tail_);
		tail_ = temp;
		tail_->next = NULL;
		size_--;
		return true;
	}
	return false;
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
	if(index >= size_ || index < 0){
		return false;
	}
	else{
		Node* select = head_;
		for(int i = 0; i < index; i++){
			select = select-> next;
		}
		select->value = value;
		return true;
	}
	return false;
}

bool DoublyLinkedList::is_sorted_asc() const {
}

bool DoublyLinkedList::is_sorted_desc() const {
}

bool DoublyLinkedList::insert_sorted_asc(DataType val) {
}

bool DoublyLinkedList::insert_sorted_desc(DataType val) {
}

void DoublyLinkedList::sort_asc() {
}
    
void DoublyLinkedList::sort_desc() {
}


