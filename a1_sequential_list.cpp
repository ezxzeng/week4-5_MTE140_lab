#include "a1_sequential_list.hpp"
#include <cstdlib>

SequentialList::SequentialList(unsigned int cap)
{
	capacity_ = cap;
	size_ = 0 ;
	data_ = new DataType[cap];
}

SequentialList::~SequentialList()
{
	delete [] data_;
	data_ = NULL;
}

unsigned int SequentialList::size() const
{
	return size_;
}

unsigned int SequentialList::capacity() const
{
	return capacity_;
}

bool SequentialList::empty() const
{
	if (size_ == 0) return true;
	return false;
}

bool SequentialList::full() const
{
	if (size_ == capacity_) return true;
	return false;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if (index < size_){
		return data_[index];
	}
	return data_[size_];
}

unsigned int SequentialList::search(DataType val) const
{
	for (int i = 0; i < size_; i++) {
		if (data_[i] == val)
			return i;
	}
	return size_;
}

void SequentialList::print() const
{
}

bool SequentialList::insert(DataType val, unsigned int index)
{
	if(index < 0 || index > size_ || size_ == capacity_) return false;
	else{
		for (int i = size_; i > index ; i--)  {
			data_[i] = data_[i-1];
		}
		data_[index] = val;
		size_++;
		return true;
	}
	return false;
}

bool SequentialList::insert_front(DataType val)
{
	if (size_ == 0) {
		data_[0] = val;
		size_++;
		return true;
	}
	else if (size_ == capacity_) {
		return false;
	}
	else {
		for (int i = size_; i > 0 ; i--)  {
			data_[i] = data_[i-1];
		}
		data_[0] = val;
		size_++;
		return true;
	}
	return false;
}

bool SequentialList::insert_back(DataType val)
{
	if (size_ < capacity_) {
		data_[size_] = val;
		size_++;
		return true;
	}
	return false;
		
}

bool SequentialList::remove(unsigned int index)
{
	if (index < 0 || index > size_ || size_ == 0)	return false;
	else {
		for (int i = index; i < size_--; i++) {
			data_[i] = data_[i + 1];
		}
		data_[size_] = NULL;
		return true;
	}
	return false;
}

bool SequentialList::remove_front()
{
	if (size_ == 0)	return false;
	else if (size_ == 1) {
		data_[0] = NULL;
		size_ = 0;
		return true;
	}
	else {
		for (int i = 0; i < size_--; i++) {
			data_[i] = data_[i + 1];
		}
		data_[size_] = NULL;
		return true;
	}
	return false;
}

bool SequentialList::remove_back()
{
	if (size_ == 0)	return false;
	else{
		data_[size_] = NULL;
		size_--;
		return true;	
	}
	return false;
}

bool SequentialList::replace(unsigned int index, DataType val)
{
	if(index < 0 || index > size_) return false;
	else{
		data_[index] = val;
		return true;
	}
	return false;
}

bool SequentialList::is_sorted_asc() const {
	for(int i = 0; i < size_ - 1; i++){
		if(data_[i] > data_[i+1]) return false;
	}
	return true;
}

bool SequentialList::is_sorted_desc() const {
	for(int i = 0; i < size_ - 1; i++){
		if(data_[i] < data_[i+1]) return false;
	}
	return true;
}

bool SequentialList::insert_sorted_asc(DataType val) {
	for(int i = size_; i > 0; i--){
		if(data_[i-1] < val){
			data_[i] = val;
			size_++;
			return true;
		}
		else{
			data_[i] = data_[i-1];
		}
	}
	return false;
}

bool SequentialList::insert_sorted_desc(DataType val) {
	for(int i = size_; i > 0; i--){
		if(data_[i-1] > val){
			data_[i] = val;
			size_++;
			return true;
		}
		else{
			data_[i] = data_[i-1];
		}
	}
	return false;
}

void SequentialList::sort_asc() {
	for(int i = size_; i > 0; i--){
		DataType temp = data_[i];
		remove(i);
		insert_sorted_asc(temp);
	}
	return;
}
    
void SequentialList::sort_desc() {
	for(int i = size_; i > 0; i--){
		DataType temp = data_[i];
		remove(i);
		insert_sorted_desc(temp);
	}
	return;
}
