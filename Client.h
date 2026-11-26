#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include "Repo.h"
#include "GetHub.h"

class Client {
public:
    // Constructor
    Client();
   
    // Destructor
    ~Client();

    void cloneRepo(GetHub& hub, int index);
   
    void printRepo() const;
   
    void printFileContents(int index) const;

    bool hasRepo() const {
    return currentRepo != nullptr;
}

private:
    Repo* currentRepo;
};
#endif
