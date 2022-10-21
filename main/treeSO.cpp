#include <iostream>
#include "trees/tree.hpp"
#include <cstring>

int main(int nargs, char** vargs){
	trees::Tree tree;
	tree.setRoot(new trees::TreeNode("puerta"));
	tree.insert("comedor","puerta");
	tree.insert("cocina","comedor");
	tree.insert("patio","puerta");
	tree.insert("calle","patio");
	tree.insert("garage","cocina");
	tree.insert("segundo piso","comedor");
	tree.traverse();
	std::cout<<"Mostrar los hijos de comedor" << std::endl;
	trees::TreeNode* node = tree.find("comedor");
	if (node != nullptr){
		node->getChildren()->print();
	}
	return 0;
}
