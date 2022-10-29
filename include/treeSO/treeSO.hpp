/*
 * tree.hpp
 *
 *  Created on: Aug 31, 2022
 *      Author: jsaavedr
 */

#ifndef TREESO_HPP_
#define TREESO_HPP_

#include "treeSO/Item.hpp"
#include <string>


namespace treeSO {

class TreeSO {
private:
	Item* root;
public:
	TreeSO();
	void setRoot(Item* node);
	void insert(Item* node, Item* parent);
	void insert(std::string child, bool IsFolder, std::string parent);
	Item* find_rec(std::string val, Item* node);
	Item* find(std::string val);
	void traverse_rec(Item* node, int level);
	void traverse();
	virtual ~TreeSO();
};

} /* namespace trees */

#endif /* TREESO_HPP_ */
