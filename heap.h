#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Heap { //class for the heap
  int *arr; //array for heap
  int *arr2; //array for output
  int capacity; //set max amount of numbers in heap
  int heap_size; //keeps track of size of heap
 public:
  Heap(int capacity); //constructor with capacity
  ~Heap(); //destructor
  void Heapify(int); //puts the binary tree in order from largest to smallest
  int parent(int); //returns parent
  int left(int); //returns left child
  int right(int); //returns right child
  void insertKey(int); //adds to heap
  int getMax(); //returns max value of heap
  void swap(int*, int*); //swaps two numbers
  int getKey(int); //returns a key
  void printHeap(); //prints heap
  void printHeap2(int); //prints output
  void deletion(); //deletes from largest to smallest
private:
};
