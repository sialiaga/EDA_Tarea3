#include <iostream>
#include "treeSO/treeSO.hpp"
#include <string>

using namespace std;
using namespace treeSO;

TreeSO so;
string position;

int main(int argc, char const *argv[])
{
	so.setRoot(new Item("root"));
	cout << "TreeSO" << endl << "¡Bienvenido a TreeSO!" << endl << "¡Autores: Samuel Aliaga y Catalina Vergara!" << endl;
	while (true)
	{
		break;	
	}
	
	return 0;
}


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
