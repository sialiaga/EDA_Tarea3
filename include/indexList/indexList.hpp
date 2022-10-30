/*
 * linkedList.hpp
 *
 */

#ifndef INDEXLIST_HPP_
#define INDEXLIST_HPP_

#include "indexList/indexNode.hpp"
#include <string>

namespace indexList {

class IndexList {
private:
	IndexNode* head;
	int length;

public:
	IndexList();
	void insertLast(std::string);
	void insertFirst(std::string);
	void removeFirst();
	void removeText(std::string);
	void remove(int _index);
	void removeAll();
	IndexNode* find(int _index);
	IndexNode* findText(std::string);
	void print();
	virtual ~IndexList();
};

} /* namespace eda */

#endif /* INDEXLIST_HPP_ */
