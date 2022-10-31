/*
 * tree.cpp
 *
 *  Created on: Aug 31, 2022
 *      Author: jsaavedr
 */

#include "treeSO/treeSO.hpp"
#include <iostream>

namespace treeSO {

TreeSO::TreeSO(): root(nullptr) {

}

void TreeSO::setRoot(Item* node){
	if (root == nullptr){
		root = node;
	}
}
void TreeSO::insert(Item* child, Item* parent){
	if (parent != nullptr){
		parent->getChildren()->insertFirst(child);
		child->setParent(parent);
	}
}

void TreeSO::insert(std::string val, bool IsFolder, std::string val_parent){
	Item* parent = find(val_parent);
	if (parent != nullptr){
		Item* child = new Item(val, IsFolder);
		insert(child, parent);
		std::cout << "insertado " << val << " in " << val_parent << " at " << parent << std::endl;
	}
}

Item* TreeSO::find_rec(std::string val, Item* node){
	Item* ans = nullptr;
	if (node != nullptr){
		if (node->getData() == val){
			ans = node;
		}
		else{ // search in children
			TreeSOList* childrenList = node->getChildren();
			TreeSOListItem* ptr = childrenList->getHead();
			while (ptr!=nullptr && ans == nullptr){
				ans = find_rec(val, ptr->getData());
				ptr = ptr->getNext();
			}
		}
	}
	return ans;
}

Item* TreeSO::find(std::string val){
	Item* ans = find_rec(val, root);
	return ans;
}


void TreeSO::traverse_rec(Item* node, int level){
	int i;
	if (node != nullptr){
		if (level == 1){
			std::cout <<std::string((level-1), ' ')<< "|" << std::endl;
			std::cout <<std::string((level-1), ' ')<< "└";
			for (i=0; i<level;i++) std::cout << "─";
		}	
		if (level > 1) {
			std::cout <<std::string((level-1), ' ')<< "|" << std::endl;
			std::cout <<std::string((level-1), ' ')<< "└";
			for (i=0; i<level;i++) std::cout << "─";
		}
		if(node->getData() == "root") std::cout<<"/"<<std::endl;
		else std::cout<<node->getData()<<std::endl;
		TreeSOList* childrenList = node->getChildren();
		TreeSOListItem* ptr = childrenList->getHead();
		while (ptr!=nullptr){
			traverse_rec(ptr->getData(), level + 1);
			ptr = ptr->getNext();
		}
	}
}

void TreeSO::traverse(){
	traverse_rec(root, 1);
}

TreeSO::~TreeSO() {
	delete root;
}

} /* namespace trees */
