#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Heap {
  int *arr;
  int capacity;
  int heap_size;
 public:
  Heap(int capacity);
  ~Heap();
  void Heapify(int);
  int parent(int);
  int left(int);
  int right(int);
  void deleteKey(int);
  void insertKey(int);
  int getMax();
  int extractMax();
  void swap(int*, int*);
  int getKey(int);
  void printHeap();
  void decreaseKey(int, int);
 private:
};
