/*
 * IndexList.cpp
 *
 */

#include <iostream>
#include "indexList/indexList.hpp"

namespace indexList {

IndexList::IndexList(): head(nullptr), length(0) {

}

void IndexList::insertFirst(std::string text){
	IndexNode* node = new IndexNode(0, text);
	
	if (head == nullptr) {
		head = node;
		length++;
	}
	else{
		for (IndexNode* aux_node = head; 
					aux_node != nullptr;
					aux_node=aux_node->getNext()) {
			
			
			aux_node->setIndex(aux_node->getIndex() + 1);

		}
		length++;
		node->setNext(head);
		head = node;
	}
}

void IndexList::insertLast(std::string text){
	IndexNode* node = new IndexNode(length, text);
	if (head == nullptr) {
		head = node;
	}
	else{
		IndexNode* ptr = head;
		while(ptr->getNext() != nullptr){
			ptr = ptr->getNext();
		}
		ptr->setNext(node);
	}
	length++;
}

void IndexList::removeFirst(){
	IndexNode* ptr = head;
	if (head != nullptr){
		head = head->getNext();
		for (IndexNode* aux_node = head; 
					aux_node != nullptr;
					aux_node=aux_node->getNext()) {
			
			aux_node->setIndex(aux_node->getIndex() - 1);

		}
		delete ptr;
		length--;
	}
}

void IndexList::removeText(std::string text){
	IndexNode* ptr = head;
	IndexNode* ptr_prev = nullptr;
	while (ptr != nullptr){
		if (ptr->getDataText() == text){
			//erase IndexNode
			if (ptr_prev == nullptr) {
				for (IndexNode* aux_node = ptr->getNext(); 
							aux_node != nullptr;
							aux_node=aux_node->getNext()) {
			
					aux_node->setIndex(aux_node->getIndex() - 1);

				}
				head = ptr->getNext();
				length--;
				delete ptr;
				ptr = head;
				break;
			}
			else{
				for (IndexNode* aux_node = ptr->getNext(); 
							aux_node != nullptr;
							aux_node=aux_node->getNext()) {
			
					aux_node->setIndex(aux_node->getIndex() - 1);

				}
				ptr_prev->setNext(ptr->getNext());
				length--;
				delete ptr;
				ptr = ptr_prev->getNext();
				break;
			}
		}
		else{
			ptr_prev = ptr;
			ptr = ptr->getNext();
		}
	}
}

void IndexList::remove(int _index){
	IndexNode* ptr = head;
	IndexNode* ptr_prev = nullptr;
	while (ptr != nullptr){
		if (ptr->getIndex() == _index){
			//erase IndexNode
			if (ptr_prev == nullptr) {
				for (IndexNode* aux_node = ptr->getNext(); 
							aux_node != nullptr;
							aux_node=aux_node->getNext()) {
			
					aux_node->setIndex(aux_node->getIndex() - 1);

				}
				head = ptr->getNext();
				length--;
				delete ptr;
				ptr = head;
				break;
			}
			else{
				for (IndexNode* aux_node = ptr->getNext(); 
							aux_node != nullptr;
							aux_node=aux_node->getNext()) {
			
					aux_node->setIndex(aux_node->getIndex() - 1);

				}
				ptr_prev->setNext(ptr->getNext());
				length--;
				delete ptr;
				ptr = ptr_prev->getNext();
				break;
			}
		}
		else{
			ptr_prev = ptr;
			ptr = ptr->getNext();
		}
	}
}

void IndexList::removeAll(){

	while (head != nullptr){
		removeFirst();
	}
}

IndexNode* IndexList::find(int _index){
	IndexNode* ptr = head;
	while ((ptr != nullptr) && (ptr->getIndex() != _index)){
		ptr = ptr->getNext();
	}
	return ptr;
}

IndexNode* IndexList::findText(std::string text){
	IndexNode* ptr = head;
	while ((ptr != nullptr) && (ptr->getDataText() != text)){
		ptr = ptr->getNext();
	}
	return ptr;
}

IndexNode* IndexList::getHead(){
	return head;
}

int IndexList::getLength(){
	return length;
}

void IndexList::print(){
	IndexNode* ptr = head;
	while (ptr != nullptr) {
		std::cout << " -> ";
		ptr->print();
		ptr = ptr->getNext();
	}
	std::cout << std::endl;
}

IndexList::~IndexList() {
	removeAll();
}

} /* namespace eda */
