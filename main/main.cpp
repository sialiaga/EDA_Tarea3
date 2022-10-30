#include <iostream>
#include "treeSO/treeSO.hpp"
#include "indexList/indexList.hpp"
#include <string>

using namespace std;
using namespace treeSO;
using namespace indexList;

TreeSO so;
string position;

int main(int argc, char const *argv[]){
	IndexList test;
	test.insertFirst("juan");
	test.insertFirst("miguel");
	test.insertFirst("macarena");
	test.insertLast("javiera");
	test.print();
	test.findText("Miguel");
	//test.removeText("miguel");
	test.print();
}

// int main(int argc, char const *argv[])
// {
// 	so.setRoot(new Item("root", true));
// 	cout << "TreeSO" << endl << "¡Bienvenido a TreeSO!" << endl << "¡Autores: Samuel Aliaga y Catalina Vergara!" << endl;
// 	while (true)
// 	{
// 		break;	
// 	}
	
// 	return 0;
// }


// int main(int nargs, char** vargs){
// 	treeSO::TreeSO tree;
// 	tree.setRoot(new treeSO::Item("puerta"));
// 	tree.insert("comedor","puerta");
// 	tree.insert("cocina","comedor");
// 	tree.insert("patio","puerta");
// 	tree.insert("calle","patio");
// 	tree.insert("garage","cocina");
// 	tree.insert("segundo piso","comedor");
// 	tree.traverse();
// 	std::cout<<"Mostrar los hijos de comedor" << std::endl;
// 	treeSO::Item* node = tree.find("comedor");
// 	if (node != nullptr){
// 		node->getChildren()->print();
// 	}
// 	return 0;
// }
