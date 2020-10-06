/*
BubbleSort:
  initiate bool x to true
  if size of passed vector is 0, set x to false

*/
#include <iostream>
#include <vector>
#include <string>

void BubbleSort(std::vector<std::string>& v) {
  bool x = true;
  if (v.size() == 0) {
      x = false;
  }
  while (x == true) {
    x = false;
    for (int i = 0; i < (v.size()-1); i++) {
      if (v[i].compare(v[i + 1]) > 0) {
      swap(v[i], v[i+1]);
      x = true;
      }
    }
  }
}

static void insertionSortRecursiveHelper(std::vector<int>& v, int size) {
    if (size <= 1) {
        return;
    }

    insertionSortRecursiveHelper(v, size - 1);

    int last_element = v[size - 1];
    int index = size - 2;

    while (index >= 0 && v[index] > last_element){
        v[index + 1] = v[index];
        index--;
    }

    v[index + 1] = last_element;
}

void InsertionSort(std::vector<int>& v) {
    insertionSortRecursiveHelper(v, v.size());
}

void MergeSort(std::vector<std::string>& v) {
  if (v.size() == 1) {
    return;
  }
  int size = v.size();
  int middle = size / 2;

  std::vector<std::string> left_vec(v.begin(),v.begin()+middle);
  std::vector<std::string> right_vec(v.begin() + middle, v.end());

  if (v.size() > 2) {
    MergeSort(left_vec);
    MergeSort(right_vec);
  }
  int left_counter = 0;
  int right_counter = 0;
  int vec_counter = 0;

  while (left_counter < left_vec.size() && right_counter < right_vec.size()) {
    if (left_vec[left_counter].compare(right_vec[right_counter]) < 0) {
      v[vec_counter] = left_vec[left_counter];
      left_counter++;

    }else if (left_vec[left_counter].compare(right_vec[right_counter]) == 0) {
      v[vec_counter] = left_vec[left_counter];
      left_counter++;
      vec_counter++;

      v[vec_counter] = right_vec[right_counter];
      right_counter++;
    }
    else {
      v[vec_counter] = right_vec[right_counter];
      right_counter++;
    }
    vec_counter++;
  }
  while (left_counter < left_vec.size()) {
    v[vec_counter] = left_vec[left_counter];
    left_counter++;
    vec_counter++;
  }
  while (right_counter < right_vec.size()) {
    v[vec_counter] = right_vec[right_counter];
    right_counter++;
    vec_counter++;
  }
}
