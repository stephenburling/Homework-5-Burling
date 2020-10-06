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

void MergeSort(std::vector<std::string>& vec) {

    if (vec.size() == 1) {
        return;
    }
        int last = vec.size();
        int middle = last / 2;

        auto left = vec.begin();
        auto midpoint = vec.begin() + middle;
        auto right = vec.end();

        std::vector<std::string> leftVec(left,midpoint);
        std::vector<std::string> rightVec(midpoint, right);

    if (vec.size() > 2) {
        MergeSort(leftVec);
        MergeSort(rightVec);
    }
        int leftCounter = 0;
        int rightCounter = 0;
        int vecCounter = 0;

        while (leftCounter < leftVec.size() && rightCounter < rightVec.size()) {
            if (leftVec[leftCounter].compare(rightVec[rightCounter]) < 0) {
                vec[vecCounter] = leftVec[leftCounter];
                  leftCounter++;
            }else if (leftVec[leftCounter].compare(rightVec[rightCounter]) == 0) {
                vec[vecCounter] = leftVec[leftCounter];
                  leftCounter++;
                  vecCounter++;
                vec[vecCounter] = rightVec[rightCounter];
                  rightCounter++;
            }
            else {
                vec[vecCounter] = rightVec[rightCounter];
                  rightCounter++;
            }
                  vecCounter++;
        }
        while (leftCounter < leftVec.size()) {
            vec[vecCounter] = leftVec[leftCounter];
              leftCounter++;
              vecCounter++;
        }
        while (rightCounter < rightVec.size()) {
            vec[vecCounter] = rightVec[rightCounter];
              rightCounter++;
              vecCounter++;
        }
}
