#include "RepoList.h"

using namespace std;

RepoList::RepoList()
    : numRepos(0), head(nullptr), tail(nullptr) {}


RepoList::RepoList(RepoList& other)
    : numRepos(0), head(nullptr), tail(nullptr) {
    Node* current = other.head;
    while (current != nullptr) {
        add(new Repo(*(current->repo)));
        current = current->next;
    }
}

RepoList::~RepoList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current->repo;
        delete current;
        current = next;
    }
}


bool RepoList::add(Repo* newRepo) {
    Node* newNode = new Node(newRepo);

    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    ++numRepos;
    return true;
}

Repo* RepoList::get(const string& title) {
    Node* current = head;
    while (current != nullptr) {
        if (current->repo->getTitle() == title) {
            return current->repo;
        }
        current = current->next;
    }
    return nullptr;
}

Repo* RepoList::get(int index) {
    if (index < 0 || index >= numRepos) return nullptr;
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->repo;
}

Repo* RepoList::remove(const string& title) {
    Node* current = head;
    while (current != nullptr) {
        if (current->repo->getTitle() == title) {
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            if (current == head) head = current->next;
            if (current == tail) tail = current->prev;

            Repo* removedRepo = current->repo;
            delete current;
            --numRepos;
            return removedRepo;
        }
        current = current->next;
    }
    return nullptr;
}

Repo* RepoList::remove(int index) {
    if (index < 0 || index >= numRepos) return nullptr;
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
   
    if (current->prev) current->prev->next = current->next;
    if (current->next) current->next->prev = current->prev;
    if (current == head) head = current->next;
    if (current == tail) tail = current->prev;
   
    Repo* removedRepo = current->repo;
    delete current;
    --numRepos;
    return removedRepo;
}

int RepoList::size() const {
    return numRepos;
}

bool RepoList::isFull() const {
    return false;
}

void RepoList::print() const {
    Node* current = head;
    while (current != nullptr) {
        current->repo->print();
    }
}
