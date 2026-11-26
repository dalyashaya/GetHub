
#ifndef FILELIST_H
#define FILELIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include "File.h"
#include "defs.h"


using namespace std;

// TODO make this a linked list
class Node {
	public:
		File* file;
		Node* next;
		Node* prev;
};

class FileList {
		
	public:
		//constructor
		FileList();
		//copy constructor
		FileList(FileList&);
		
		//destructor
		~FileList();
		
		//other
		bool add(File*);
		File* get( string& name) ;
		File* get(int index) ;
		File* remove( string& name);
		File* remove( int index) ;
		int size() const;
		bool isFull() const;
		void print() const;
	
	private:
		int numFiles;
		Node* head;
		Node* tail;
};
#endif
