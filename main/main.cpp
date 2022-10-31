#include <iostream>
#include <string>
#include <sstream>
#include "treeSO/treeSO.hpp"
#include "indexList/indexList.hpp"

using namespace std;
using namespace treeSO;
using namespace indexList;

TreeSO so;
Item * itemPosition;
string itemStrPosition;
string usercin;

IndexList textPosition;

int auxLenght;
string auxString;
string auxStrInstruction;
string auxStrPosition;
IndexList auxInstruction;
IndexList auxPosition;
Item * auxItemPosition;
IndexNode * auxNode;

//TOOLS	
void split(IndexList &aux, string t, char s)
{
    stringstream text(t);
    aux.removeAll();
    string temp_text;

    while (getline(text, temp_text, s))
    {
        aux.insertLast(temp_text);
    }
}

void show_error(string type){
	if(type=="cm_ne") cout<< "ERROR: Comando no existente" << endl;
	else if(type=="cm_ac") cout<< "ERROR: conflicto con argumentos entregado"<<endl;
	else if(type=="fl_nf") cout<< "ERROR: Archivo no encontrado"<<endl;
	else if(type=="cm_ic") cout<< "ERROR: Conflicto con item seleccionado"<<endl;
}

int find_location(){
	TreeSOListItem* ptr;
	int IsFound = 0;
	for (int i=0; i<auxPosition.getLength();i++){
		auxString = auxPosition.find(i)->getDataText();
		if(i == 0){
			if(auxString == ".") {
				auxItemPosition = itemPosition;
				IsFound  = 1;
				continue;
			}
			else if(auxString == ".."){
				if (itemPosition->getParent() != nullptr){
					auxItemPosition = itemPosition->getParent();
					IsFound  = 1;
					continue;
				}
				else return 0;
			}
			else if(auxString == ""){
				 auxItemPosition = so.find("root");
				 IsFound  = 1;
				 continue;
			}
		}
		IsFound  = 0;
		for(ptr=auxItemPosition->getChildren()->getHead(); ptr != nullptr; ptr= ptr->getNext())
		{
			if(ptr->getData()->getData() == auxString){
				IsFound = 1;
				auxItemPosition = auxItemPosition->getChildren()->find(auxString);
			}
		}
		
	}
	return IsFound ;
}

//FUNCTION
void command_clean(){
	cout << string(0, '\n');
	cout << "TreeSO" << endl << "¡Bienvenido a TreeSO!" << endl << "¡Autores: Samuel Aliaga y Catalina Vergara!" << endl;
}

void command_cd(){
	split(auxPosition, auxInstruction.find(1)->getDataText(), '/');

}

void command_ls(){
	split(auxPosition, auxInstruction.find(1)->getDataText(), '/');
	if(find_location()) auxItemPosition->getChildren()->print();
	else show_error("fl_nf");
	

}

void command_mkdir(){
	auxString = auxInstruction.find(1)->getDataText();
	if(auxString == "/" or auxString == "." or auxString == "..") show_error("cm_ac");
	else so.insert(new Item(auxString, true), itemPosition);
}

void command_mkfile(){
	
}

void command_rm(){
	
}

void command_tree(){
	
}

void command_find(){
	
}

int main(int argc, char const *argv[])
{
	so.setRoot(new Item("root", true));
	itemPosition = so.find("root");
	auxStrPosition = "root";
	so.insert(new Item("documentos", true), itemPosition);
	so.insert(new Item("fotos", true), itemPosition);
	so.insert(new Item("videos", true), itemPosition);
	so.insert(new Item("video.mp4", false), itemPosition);
	itemPosition = so.find("documentos");
	auxStrPosition += "/documentos";
	command_clean();
	while (true)
	{
		split(textPosition, auxStrPosition, '/');
		if (itemPosition == so.find("root")) cout << "/";
		for(auxNode = textPosition.getHead()->getNext(); 
				auxNode != nullptr; 
				auxNode = auxNode->getNext()){
					cout << "/";
					cout << auxNode->getDataText();
				}
		cout << "#";
		getline(cin>>ws, usercin); split(auxInstruction, usercin, ' ');
		auxLenght = auxInstruction.getLength();
		auxStrInstruction = auxInstruction.find(0)->getDataText();
		if(auxStrInstruction == "exit"){
			if(auxLenght == 1) break;
			else show_error("cm_ac");
		}
		else if(auxStrInstruction == "clean"){
			if(auxLenght == 1) command_clean();
			else show_error("cm_ac");
		}
		else if(auxStrInstruction == "cd"){
			if(auxLenght == 2) command_cd();
			else show_error("cm_ac");
		}
		else if(auxStrInstruction == "ls"){
			if(auxLenght == 2) command_ls();
			else show_error("cm_ac");
		}
		else if(auxStrInstruction == "mkdir"){
			if(auxLenght == 2) command_mkdir();
			else show_error("cm_ac");
		}
		else if(auxStrInstruction == "mkfile"){
			if(auxLenght == 3) command_mkfile();
			else show_error("cm_ac");
		}
		else if(auxStrInstruction == "rm"){
			if(auxLenght == 2) command_rm();
			else show_error("cm_ac");
		}
		else if(auxStrInstruction == "tree"){
			if(auxLenght == 2) command_tree();
			else show_error("cm_ac");
		}
		else if(auxStrInstruction == "find"){
			if(auxLenght == 2) command_find();
			else show_error("cm_ac");
		}
		else show_error("cm_ne");
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
