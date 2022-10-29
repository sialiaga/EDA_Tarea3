/*
 * childrenList.hpp
 *
 *  Created on: Aug 31, 2022
 *      Author: jsaavedr
 */

#ifndef CHILDRENLIST_HPP_
#define CHILDRENLIST_HPP_

#include "treeSO/treeSOListItem.hpp"
#include <string>

namespace treeSO {

class Item;
class TreeSOListItem;
class TreeSOList {
private:
	TreeSOListItem* head;
public:
	TreeSOList();
	TreeSOListItem* getHead();
	void insertFirst(Item* Item);
	void removeFirst();
	void remove(std::string val);
	void removeAll();
	bool isEmpty();
	Item* find(std::string val);
	void print();
	virtual ~TreeSOList();
};

} /* namespace trees */

#endif /* CHILDRENLIST_HPP_ */
