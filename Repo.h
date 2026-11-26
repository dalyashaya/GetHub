#ifndef REPO_H
#define REPO_H

#include <string>
#include "File.h"
#include "FileList.h"
#include "defs.h"

using namespace std;

class Repo {
public:
    // Constructor
    Repo(const string& title, const string& owner);

    // Copy constructor
    Repo(Repo&);

    // Destructor
    ~Repo();

    // Getter functions
    const string& getTitle() const;
    const string& getOwner() const;

    // Other functions
    int getNumFiles() const;
    bool addFile(const string& title, const string& content, const Date& date);
    bool removeFile(int);
    bool lessThan(const Repo&) const;
    void print() const;
    void printFiles() const;
    void printContents(int file) const;

private:
    string title;
    string owner;
    FileList* fileList;
};

#endif