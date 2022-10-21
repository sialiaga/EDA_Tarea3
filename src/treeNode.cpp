/*
 * treeNode.cpp
 *
 *  Created on: Aug 30, 2022
 *      Author: jsaavedr
 */

#include "trees/treeNode.hpp"

namespace trees {

TreeNode::TreeNode(): parent(nullptr), dataText("0"), dataType(false), children(new TreeList()) {
}

TreeNode::TreeNode(std::string val): parent(nullptr), dataText(val), dataType(false), children(new TreeList()) {
}

void TreeNode::setParent(TreeNode* node){
	parent = node;
}
void TreeNode::setData(std::string text){
	dataText = text;
}
void TreeNode::setType(bool type){
	dataType = type;
}
void TreeNode::setChildren(TreeList* list){
	children = list;
}
TreeNode* TreeNode::getParent(){
	return parent;
}
std::string TreeNode::getData(){
	return dataText;
}
bool TreeNode::getType(){
	return dataType;
}
TreeList* TreeNode::getChildren(){
	return children;
}

TreeNode::~TreeNode() {
	//action when a treeNode is deleted
	//delete the descendants only
	if (children != nullptr){
		delete children;
	}
}

} /* namespace trees */
