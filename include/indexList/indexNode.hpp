/*
 * node.hpp
 *
 */

#ifndef INDEXNODE_HPP_
#define INDEXNODE_HPP_

#include <string>

namespace indexList {

class IndexNode {
private:
	int index;
	std::string dataText;
	IndexNode* ptrNext;
public:
	IndexNode(int _index, std::string _dataText, IndexNode* next = nullptr);
	void setIndex(int _index);
	void setDataText(std::string _dataText);
	void setNext(IndexNode* _next);
	int getIndex();
	std::string getDataText();
	IndexNode* getNext();
	void print();
	virtual ~IndexNode();
};

} /* namespace IndexNode */

#endif /* INDEXNODE_HPP_ */
