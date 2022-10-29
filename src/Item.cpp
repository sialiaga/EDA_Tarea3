/*
 * treeNode.cpp
 *
 *  Created on: Aug 30, 2022
 *      Author: jsaavedr
 */

#include "treeSO/Item.hpp"

namespace treeSO {

Item::Item(): parent(nullptr), dataText("0"), folderType(false), children(new TreeSOList()) {
}

Item::Item(std::string val, bool IsFolder): parent(nullptr), dataText(val), folderType(IsFolder), children(new TreeSOList()) {
}

void Item::setParent(Item* node){
	parent = node;
}
void Item::setData(std::string text){
	dataText = text;
}
void Item::setType(bool type){
	folderType = type;
}
void Item::setChildren(TreeSOList* list){
	children = list;
}
Item* Item::getParent(){
	return parent;
}
std::string Item::getData(){
	return dataText;
}
bool Item::getType(){
	return folderType;
}
TreeSOList* Item::getChildren(){
	return children;
}

Item::~Item() {
	if (children != nullptr){
		delete children;
	}
}

} /* namespace treeSO */
