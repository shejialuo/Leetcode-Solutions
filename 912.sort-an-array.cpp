/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] Sort an Array
 */

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  vector<int> insertionSort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
      int j = i - 1;
      int value = nums[i];
      while (j >= 0 && value < nums[j]) {
        nums[j + 1] = nums[j];
        j--;
      }

      nums[j + 1] = value;
    }

    return nums;
  }

  vector<int> selectionSort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      int minValue = numeric_limits<int>::max();
      int k = -1;

      for (int j = i; j < nums.size(); j++) {
        if (nums[j] < minValue) {
          k = j;
          minValue = nums[j];
        }
      }

      swap(nums[i], nums[k]);
    }
    return nums;
  }

  vector<int> buddleSort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      for (int j = nums.size() - 1; j > i; j--) {
        if (nums[j] < nums[j - 1]) {
          swap(nums[j], nums[j - 1]);
        }
      }
    }
    return nums;
  }

  void mergeArray(vector<int> &nums, int start, int mid, int end) {
    vector<int> array1(mid - start + 2, 0);
    for (int i = 0; i < mid - start + 1; i++) {
      array1[i] = nums[i + start];
    }
    array1.back() = numeric_limits<int>::max();

    vector<int> array2(end - mid + 1, 0);
    for (int i = 0; i < end - mid; i++) {
      array2[i] = nums[i + mid + 1];
    }
    array2.back() = numeric_limits<int>::max();

    for (int i = 0, j = 0, k = start; k <= end; k++) {
      if (array1[i] < array2[j]) {
        nums[k] = array1[i++];
      } else {
        nums[k] = array2[j++];
      }
    }
  }

  void sortArrayDivideAndConquer(vector<int> &nums, int start, int end) {
    if (start < end) {
      int mid = (start + end) / 2;
      sortArrayDivideAndConquer(nums, start, mid);
      sortArrayDivideAndConquer(nums, mid + 1, end);
      mergeArray(nums, start, mid, end);
    }
  }

  int partition(vector<int> &nums, int start, int end) {
    int pivot = nums[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
      if (nums[j] < pivot) {
        swap(nums[++i], nums[j]);
      }
    }
    swap(nums[i + 1], nums[end]);
    return i + 1;
  }

  void quickSort(vector<int> &nums, int start, int end) {
    if (start < end) {
      int mid = partition(nums, start, end);
      quickSort(nums, start, mid - 1);
      quickSort(nums, mid + 1, end);
    }
  }

  class Heap {
  private:
    vector<int> data;
    size_t heapSize;

    int left(int index) { return 2 * index; }
    int right(int index) { return 2 * index + 1; }

  public:
    Heap() = delete;
    Heap(const vector<int> &d) : data{d}, heapSize{data.size()} { buildHeap(); }

    void maxHeapify(int index) {
      int largest = index;
      if (left(index) < heapSize && data[left(index)] > data[largest]) {
        largest = left(index);
      }
      if (right(index) < heapSize && data[right(index)] > data[largest]) {
        largest = right(index);
      }

      if (largest != index) {
        swap(data[largest], data[index]);
        maxHeapify(largest);
      }
    }

    void buildHeap() {
      for (int i = data.size() / 2; i >= 0; i--) {
        maxHeapify(i);
      }
    }

    void sortedArray() {
      while (heapSize > 0) {
        swap(data[heapSize - 1], data[0]);
        heapSize--;
        maxHeapify(0);
      }
    }
  };

public:
  vector<int> sortArray(vector<int> &nums) {
    sortArrayDivideAndConquer(nums, 0, nums.size() - 1);
    return nums;
  }
};
// @lc code=end
