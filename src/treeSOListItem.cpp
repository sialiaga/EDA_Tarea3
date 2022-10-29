/*
 * childNode.cpp
 *
 *  Created on: Aug 30, 2022
 *      Author: jsaavedr
 */

#include "treeSO/treeSOListItem.hpp"

namespace treeSO {

TreeSOListItem::TreeSOListItem(): data(), ptrNext(nullptr) {
	// TODO Auto-generated constructor stub

}

TreeSOListItem::TreeSOListItem(Item* _data,
		TreeSOListItem* next) : data(_data), ptrNext(next){

}
void TreeSOListItem::setData(Item* _data){
	data = _data;
}
void TreeSOListItem::setNext(TreeSOListItem* _next){
	ptrNext = _next;
}
Item* TreeSOListItem::getData(){
	return data;
}
TreeSOListItem* TreeSOListItem::getNext(){
	return ptrNext;
}

TreeSOListItem::~TreeSOListItem() {
	//Actions when a TreeSOListItem is deleted
	delete data;
}

} /* namespace trees */
