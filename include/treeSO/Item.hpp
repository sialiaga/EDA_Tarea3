/*
 * Item.hpp
 *
 *  Created on: Aug 30, 2022
 *      Author: jsaavedr
 */

#ifndef ITEM_HPP_
#define ITEM_HPP_

#include "treeSO/treeSOList.hpp"
#include <string>

namespace treeSO {

class TreeSOList;
class Item {
private:
	Item* parent;
	std::string dataText;
	bool folderType;
	TreeSOList* children;
public:
	Item();
	Item(std::string dataText);
	void setParent(Item* node);
	void setData(std::string text);
	void setType(bool type);
	void setChildren(TreeSOList* list);
	Item* getParent();
	std::string getData();
	bool getType();
	TreeSOList* getChildren();
	virtual ~Item();
};

} /* namespace trees */

#endif /* ITEM_HPP_ */
