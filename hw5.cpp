/*
BubbleSort:
    initiate bool x to true
    if size of passed vector is 0, set x to false
    while x is true
        set x to false
        for each element in the vector
            if the current element is greater than the next element (or further down the alphabet)
                swap the current element and the next element
                set x to true.

InsertionSortRecursiveHelper
    if size of passed vector is 0, return 
    recursively call InsertionSortRecursiveHelper with current vector and size of vector minus one
    initialize last_element equal to the last element found in the vector
    initialize index to the element before last_element
    while the index is greater than or equal to zero and the element found in the vector at the given index is greater than the last_element
        set the next element indexed in the vector equal to the current indexed element
        decrement the index
    set the next element indexed in vector equal to last_element

InsertionSort
    call InsertionSortRecursiveHelper with passed vector and size of vector

MergeSort
    if size of passed vector is equal to 0, return 
    intialize int middle to equal the size of the vector divided by two
    initialize subvector left_vec with the contents of passed vector v from beginning of vector to the midpoint
    initialize subvector right_vec with the contents of passed vector v from midpoint of vector to the end
    if current v size is greater than two
        recursively call MergeSort with left_vec and again with right_vec
    initialize left_counter, right_counter, and vec_counter to zero
    while left_counter is less than the size of left_vec AND right_counter is less than the size of right_vec
        if current element indexed in left_vec is less than the current element indexed in right_vec
            set current element in main vector to the element in left_vec
        else, if current elements in both left_vec and right_vec are equal
            set current element in main vector to the element in left_vec
            increment left_vec
            increment main vector 
            set current element in main vector to the element in right vec
            increment right_vec
        else,
            set current element in main vector to the element in right vec
            increment right_vec
        increment main vector
    while there are still elements in left_vec
        copy elements into main vector
    while there are still elements in right_vec
        copy elements into main vector
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

static void InsertionSortRecursiveHelper(std::vector<int>& v, int size) {
    if (size <= 1) {
        return;
    }

    InsertionSortRecursiveHelper(v, size - 1);

    int last_element = v[size - 1];
    int index = size - 2;

    while (index >= 0 && v[index] > last_element){
        v[index + 1] = v[index];
        index--;
    }

    v[index + 1] = last_element;
}

void InsertionSort(std::vector<int>& v) {
    InsertionSortRecursiveHelper(v, v.size());
}

void MergeSort(std::vector<std::string>& v) {
    if (v.size() == 1) {
        return;
    }

  int middle = v.size() / 2;

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
