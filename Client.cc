#include "Client.h"
#include <iostream>

using namespace std;

Client::Client()
    : currentRepo(nullptr) {}

Client::~Client() {
    delete currentRepo;
}

void Client::cloneRepo(GetHub& hub, int index) {
    if (currentRepo != nullptr) {
        delete currentRepo;
        currentRepo = nullptr;
    }

    Repo* repoToClone = nullptr;
    if (!hub.download(index, &repoToClone) || repoToClone == nullptr) {
        cout << "Error: Failed to download repo at index " << index << "." << endl;
        return;
    }

    try {
        currentRepo = new Repo(*repoToClone);
    } catch (bad_alloc& e) {
        cout << "Error: Failed to allocate memory for cloning repo." << endl;
        currentRepo = nullptr;
    }
}

void Client::printRepo() const {
    if (currentRepo == nullptr) {
        cout << "Error: No repo is currently selected." << endl;
        return;
    }
    currentRepo->printFiles();
}

void Client::printFileContents(int index) const {
    if (currentRepo == nullptr) {
        cout << "Error: No repo is currently selected." << endl;
        return;
    }
    currentRepo->printContents(index);
}
