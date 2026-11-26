#include "FileList.h"

using namespace std;

FileList::FileList()
    : numFiles(0), head(nullptr), tail(nullptr) {}


FileList::FileList(FileList& other)
    : numFiles(0), head(nullptr), tail(nullptr) {
    Node* current = other.head;
    while (current != nullptr) {
        add(new File(*(current->file)));
        current = current->next;
    }
}

FileList::~FileList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current->file;
        delete current;
        current = next;
    }
}

bool FileList::add(File* newFile) {
    Node* newNode = new Node{newFile, nullptr, nullptr};

    if (!head) {
        head = tail = newNode;
    } else {
        Node* current = head;
        while (current != nullptr && current->file->lessThan(*newFile)) {
            current = current->next;
        }
        if (!current) { 
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else if (current == head) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else {
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }
    }
    ++numFiles;
    return true; 
}

File* FileList::get( string& name)  {
    Node* current = head;
    while (current != nullptr) {
        if (current->file->getName() == name) {
            return current->file;
        }
        current = current->next;
    }
    return nullptr;
}

File* FileList::get(int index)  {
    if (index < 0 || index >= numFiles) return nullptr;
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->file;
}

File* FileList::remove( string& name) {
    Node* current = head;
    while (current != nullptr) {
        if (current->file->getName() == name) {
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            if (current == head) head = current->next;
            if (current == tail) tail = current->prev;

            File* removedFile = current->file;
            delete current;
            --numFiles;
            return removedFile;
        }
        current = current->next;
    }
    return nullptr;
}

File* FileList::remove( int index) {
    if (index < 0 || index >= numFiles) return nullptr;
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
   
    if (current->prev) current->prev->next = current->next;
    if (current->next) current->next->prev = current->prev;
    if (current == head) head = current->next;
    if (current == tail) tail = current->prev;
   
    File* removedFile = current->file;
    delete current;
    --numFiles;
    return removedFile;
}

int FileList::size() const {
    return numFiles;
}

bool FileList::isFull() const {
    return false; 
}


void FileList::print() const {
    Node* current = head;
    while (current != nullptr) {
        current->file->print();
        current = current->next;
        cout << endl;
    }
}