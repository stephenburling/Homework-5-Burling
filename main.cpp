#include <iostream>
#include <vector>
#include "hw5.h"

void print(std::vector<std::string>& v) {
    std::cout << "[";
    bool first = true;
    for (auto x : v) {
        if (!first) {
            std::cout << ", ";
        }
        std::cout << x;
        first = false;
    }
    std::cout << "]";
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> v;
    std::vector<int> vi;
    vi = {4,1,7,5,6,9};
    v = { "emma", "dora", "ruth", "ziegellaub", "eichler" };
    std::cout << "Case 1: ";

    //print(vi);
    MergeSort(v);
    for (int i = 0; i < vi.size(); i++) {
        std::cout << vi[i] << std::endl;
    }
    //print(vi);
    //std::cout << "Expected: [dora, eichler, emma, ruth, ziegellaub]" << std::endl;
}