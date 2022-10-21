/*
 * node.hpp
 *
 */

#ifndef NODE_HPP_
#define NODE_HPP_

#include <string>

namespace eda {

class Node {
private:
	int data;
	std::string dataText;
	bool dataType;
	Node* ptrNext;
public:
	Node();
	Node(int _data, Node* next = nullptr);
	void setData(int _data);
	void setDataText(std::string _dataText);
	void setDataType(bool _dataType);
	void setNext(Node* _next);
	int getData();
	std::string getDataText();
	bool getDataType();
	Node* getNext();
	void print();
	virtual ~Node();
};

} /* namespace eda */

#endif /* NODE_HPP_ */
