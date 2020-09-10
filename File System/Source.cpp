#include<iostream>
#include"File.h"
using namespace std;

int main() {
	ItemFS* fileZ = new File("z.doc", 12000);
	ItemFS* fileW = new File("w.doc", 23000);
	Folder* folderA = new Folder("A");
	Folder* folderB = new Folder("B");
	folderB->addFile(fileW);
	folderA->addFile(fileZ);
	folderA->addFile(folderB);
	cout << fileZ->getSize() << endl;
	cout << folderA->getSize() << endl;
	folderA->printInfo();
}