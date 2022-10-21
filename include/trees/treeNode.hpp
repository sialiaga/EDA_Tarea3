/*
 * treeNode.hpp
 *
 *  Created on: Aug 30, 2022
 *      Author: jsaavedr
 */

#ifndef TREENODE_HPP_
#define TREENODE_HPP_

#include "trees/treeList.hpp"
#include <string>

namespace trees {

class TreeList;
class TreeNode {
private:
	TreeNode* parent;
	std::string dataText;
	bool dataType;
	TreeList* children;
public:
	TreeNode();
	TreeNode(std::string dataText);
	void setParent(TreeNode* node);
	void setData(std::string text);
	void setType(bool type);
	void setChildren(TreeList* list);
	TreeNode* getParent();
	std::string getData();
	bool getType();
	TreeList* getChildren();
	virtual ~TreeNode();
};

} /* namespace trees */

#endif /* TREENODE_HPP_ */
