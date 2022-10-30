/*
 * nodo.cpp
 */

#include "indexList/indexNode.hpp"
#include <iostream>
#include <string>

namespace indexList {


IndexNode::IndexNode(int _index, std::string _dataText, IndexNode* next): index(_index), dataText(_dataText), ptrNext(next) {

}

void IndexNode::setIndex(int _index){
	index = _index;
}

void IndexNode::setDataText(std::string _dataText){
	dataText = _dataText;
}

void IndexNode::setNext(IndexNode* next){
	ptrNext = next;
}

int IndexNode::getIndex(){
	return index;
}
std::string IndexNode::getDataText(){
	return dataText;
}
IndexNode* IndexNode::getNext(){
	return ptrNext;
}

void IndexNode::print(){
	std::cout << "index: " << index << ", " << "Text: "<< dataText << std::endl;
}

IndexNode::~IndexNode() {

}

} /* namespace indexList */
