/*
 * childrenList.cpp
 *
 *  Created on: Aug 31, 2022
 *      Author: jsaavedr
 */

#include "treeSO/treeSOList.hpp"
#include <iostream>
namespace treeSO {

TreeSOList::TreeSOList(): head(nullptr) {
	// TODO Auto-generated constructor stub
}

void TreeSOList::insertFirst(Item* Item){
	TreeSOListItem* node = new TreeSOListItem(Item);
	if (head == nullptr) {
		head = node;
	}
	else{
		node->setNext(head);
		head = node;
	}
}

TreeSOListItem* TreeSOList::getHead(){
	return head;
}

void TreeSOList::removeFirst(){
	TreeSOListItem* ptr = head;
	if (head != nullptr){
		head = head->getNext();
		delete ptr;
	}
}


void TreeSOList::remove(std::string val){
	TreeSOListItem* ptr = head;
	TreeSOListItem* ptr_prev = nullptr;
	while (ptr != nullptr){
		if ((ptr->getData())->getData() == val){
			//erase node
			if (ptr_prev == nullptr) {
				head = ptr->getNext();
				delete ptr;
				ptr = head;
			}
			else{
				ptr_prev->setNext(ptr->getNext());
				delete ptr;
				ptr = ptr_prev->getNext();
			}
		}
		else{
			ptr_prev = ptr;
			ptr = ptr->getNext();
		}
	}
}

void TreeSOList::removeAll(){
	while (head != nullptr){
		removeFirst();
	}
}

Item* TreeSOList::find(std::string val){
	TreeSOListItem* ptr = head;
	while ((ptr != nullptr) && ((ptr->getData())->getData() != val)){
		ptr = ptr->getNext();
	}
	return ptr->getData();
}

bool TreeSOList::isEmpty(){
	return (head == nullptr);
}

void TreeSOList::print(){
	TreeSOListItem* ptr = head;
	while (ptr != nullptr){
		std::cout << ptr->getData()->getData() << " - " <<std::endl;
		ptr = ptr -> getNext();
	}
}

TreeSOList::~TreeSOList() {
	removeAll();
}





} /* namespace trees */


