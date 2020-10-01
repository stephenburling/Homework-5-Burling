#include <iostream>
#include <vector>
#include <string>

void BubbleSort(std::vector<std::string>& vec) {
  bool x = true;
  if (vec.size() == 0) {
      x = false;
  }
  while (x == true) {
    x = false;
    for (int i = 0; i < (vec.size()-1); i++) {
      if (vec[i].compare(vec[i + 1]) >= 0) {
      swap(vec[i], vec[i+1]);
      x = true;
      }
    }
  }
}

void InsertionSort(std::vector<int>& v) {

}

void MergeSort(std::vector<std::string>& vec) {

}
