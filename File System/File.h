#pragma once
#include<iostream>
#include<vector>

using namespace std;

class ItemFS abstract
{
protected:
	string name;
public:
	ItemFS() = default;
	ItemFS(const string& name) :name(name) {

	}
	virtual size_t getSize() const abstract;
	virtual void printInfo() const abstract;
};
class File : public ItemFS
{
     size_t size;
public:
	File(const string& name, size_t size) :ItemFS(name),size(size) {

	}
	size_t getSize()const override {
		return size;
	}
	void printInfo()const override {
		cout << "Name->" << ItemFS::name << endl;
		cout << "Size->" << size << endl;
	}
	
};
class Folder : public ItemFS
{
	vector<ItemFS*>files;
	
public:
	Folder(const string& name) :ItemFS(name) {

	}
	void addFile(ItemFS* file) {
		files.push_back(file);
	}
	size_t getSize()const override {
	    size_t sum = 0;
		for (auto f : files) {
			sum += f->getSize();
		}
		return sum;
	}
	void printInfo()const override{
		for (auto f : files) {
			f->printInfo();
		}
		cout << "Folder size->" << getSize() << endl;
	
	}
};
