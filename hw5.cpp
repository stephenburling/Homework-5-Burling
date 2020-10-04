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
      if (vec[i].compare(vec[i + 1]) > 0) {
      swap(vec[i], vec[i+1]);
      x = true;
      }
    }
  }
}
static void insertionSortRecursiveHelper(std::vector<int>& vec, int size)
{
    if (size <= 1) {
        return;
    }

    insertionSortRecursiveHelper(vec, size - 1);

    int last_element = vec[size - 1];
    int index = size - 2;

    while (index >= 0 && vec[index] > last_element)
    {
        vec[index + 1] = vec[index];
        index--;
    }

    vec[index + 1] = last_element;
}

void InsertionSort(std::vector<int>& v) {

    insertionSortRecursiveHelper(v, v.size());
    
}

static void MergeSortHelper(std::vector<std::string>& vec, int left_bound, int right_bound) {

}

void MergeSort(std::vector<std::string>& vec) {

}
