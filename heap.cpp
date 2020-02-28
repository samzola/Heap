#include <iostream>
#include <climits>
#include <cmath>
#include "heap.h"

using namespace std;

Heap::Heap(int cap) { //constructor with capacity set
  heap_size = 0;
  capacity = cap;
  arr = new int[cap];
  arr2 = new int[cap];
}

Heap::~Heap() {} //destructor

int Heap::parent(int i) { //returns parent
  return (i-1)/2;
}

int Heap::left(int i) { //returns left child
  return ((2*i)+1);
}

int Heap::right(int i) { //returns right child
  return ((2*1)+2);
}

int Heap::getMax() { //returns largest number
  return arr[0];
}

void Heap::insertKey(int k) { //inserts a number
  if (heap_size == capacity) { //check if heap is at capacity
    cout << "Cannot insert" << endl; //if so, tell user it cannot be inserted
    return;
  }

  heap_size++; //add to heap size
  int i = heap_size - 1;
  arr[i] = k; //make a node with the number
  while (i != 0 && arr[parent(i)] < arr[i]) { //make sure node is in correct place
    swap(&arr[i], &arr[parent(i)]);
    i = parent(i);
  }
}

void Heap::swap(int *x, int *y) { //swap two nodes
  int temp = *x;
  *x = *y;
  *y = temp;
}

void Heap::Heapify(int i) { //makes max heap
  int l = (2*i)+1; //left child
  int r = (2*i)+2; //right child
  int largest = i; //keeps track of largest node
  if (l < heap_size && arr[l] > arr[i]) { //if left is larger than current node, make it largest
    largest = l;
  }
  if (r < heap_size && arr[r] > arr[largest]) { //if right is larger than current, make it largest
    largest = r;
  }
  if (largest != i) { //if largest has changed
    swap(&arr[i], &arr[largest]); //swap positions
    Heapify(largest); //recursively call heapify
  }
}

int Heap::getKey(int i) { //returns certain key
  return arr[i];
}

void Heap::printHeap() { //prints main heap
  cout << endl;
  int num = 1; //keeps track of row
  int printed = 0; //keeps track of number printed for each row
  for (int i = 0; i < heap_size; i++) { //for loop to run through each number
    cout << arr[i] << " "; //print numbers 
    printed++;
    if (printed == num) { //keep printing until number printed in each row is max
      cout << endl; //move to next row
      num = num << 1; //reset num and printed
      printed = 0;
    }
  }
  cout << endl;
}

void Heap::printHeap2(int sizeh) { //prints output
  int counter = 0;
  int s = sizeh;
  while (counter < s) {
    cout << arr2[counter] << " ";
    counter++;
  }
}

void Heap::deletion() { //deletes every number from largest to smallest
  int twoCount = 0; //keeps track of array index for output
  int hsize = heap_size; //variable to pass into printHeap2
  while (arr[0] != NULL) { //while there are still numbers in the heap
    arr2[twoCount] = arr[0]; //add max value to arr2
    twoCount++;
    int last = arr[heap_size-1]; //move last node to first node
    arr[0] = last; //deletes first node
    heap_size--;
    Heapify(0); //re-heapify to make order correct
  }
  cout << "Output: ";
  printHeap2(hsize); //print second heap
  cout << endl;
}
