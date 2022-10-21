/*
 * nodo.cpp
 */

#include "lLists/node.hpp"
#include <iostream>
#include <string>

namespace eda {


Node::Node(): data(-1), ptrNext(nullptr) {
}

Node::Node(int val, Node* next): data(val), ptrNext(next) {

}

void Node::setData(int _data){
	data = _data;
}

void Node::setDataText(std::string _dataText){
	dataText = _dataText;
}

void Node::setDataType(bool _dataType){
	dataType = _dataType;
}

void Node::setNext(Node* next){
	ptrNext = next;
}

int Node::getData(){
	return data;
}
std::string Node::getDataText(){
	return dataText;
}
bool Node::getDataType(){
	return dataType;
}
Node* Node::getNext(){
	return ptrNext;
}

void Node::print(){
	std::cout << data ;
}

Node::~Node() {

}

} /* namespace eda */
