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
    v = { "emma", "dora", "ruth", "stephen", "alisha", "alex", "ziegellaub", "eichler" };
   
    //MergeSort(v);
   // std::cout << "Testing vector: " << std::endl;
    
    InsertionSort(vi);

    for (int i = 0; i < vi.size(); i++) {
        std::cout << vi[i] << std::endl;
    }

    auto begin = vi.begin();
    auto end = vi.end();
    std::vector<int> tempV(begin, end-4);


}