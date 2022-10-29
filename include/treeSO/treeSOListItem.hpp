/*
 * childNode.hpp
 *
 *  Created on: Aug 30, 2022
 *      Author: jsaavedr
 */

#ifndef CHILDITEM_HPP_
#define CHILDITEM_HPP_

#include "treeSO/Item.hpp"

namespace treeSO {
class Item;
class TreeSOListItem {
private:
	Item* data;
	TreeSOListItem* ptrNext;

public:
	TreeSOListItem();
	TreeSOListItem(Item* _data, TreeSOListItem* next = nullptr);
	void setData(Item* _data);
	void setNext(TreeSOListItem* _next);
	Item* getData();
	TreeSOListItem* getNext();
	virtual ~TreeSOListItem();
};

} /* namespace trees */

#endif /* CHILDNODE_HPP_ */
