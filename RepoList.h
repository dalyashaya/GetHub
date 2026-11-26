#ifndef REPOLIST_H
#define REPOLIST_H

#include <iostream>
#include <string>
#include "Repo.h"
#include "defs.h"

using namespace std;

class RepoList {
	public:
		// Constructor
		RepoList();
	
		// Copy constructor
		RepoList(RepoList&);
	
		// Destructor
		~RepoList();
	
		// Other functions
		bool add(Repo*);
		Repo* get(const string& title);
		Repo* get(int);
		Repo* remove(const string& title);
		Repo* remove(int);
		int size() const;
		bool isFull() const;
		void print() const;

	private:
		struct Node {
			Repo* repo;
			Node* next;
			Node* prev;
			Node(Repo* r) : repo(r), next(nullptr), prev(nullptr) {}
		};

		int numRepos;
		Node* head;
		Node* tail;
};

#endif