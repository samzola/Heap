#include <iostream>
#include <climits>
#include <cmath>
#include "heap.h"

using namespace std;

Heap::Heap(int cap) {
  heap_size = 0;
  capacity = cap;
  arr = new int[cap];
  arr2 = new int[cap];
}

Heap::~Heap() {}

int Heap::parent(int i) {
  return (i-1)/2;
}

int Heap::left(int i) {
  return (2*i)+1;
}

int Heap::right(int i) {
  return (2*1)+2;
}

int Heap::getMax() {
  return arr[0];
}

int Heap::extractMax() {
  if (heap_size <= 0) {
    return INT_MAX;
  }
  if (heap_size == 1) {
    heap_size--;
    return arr[0];
  }

  int root = arr[0];
  arr[0] = arr[heap_size-1];
  heap_size--;
  Heapify(0);

  return root;
}

void Heap::deleteKey(int i) {
  increaseKey(i, INT_MAX);
  extractMax();
}

void Heap::insertKey(int k) {
  if (heap_size == capacity) {
    cout << "Cannot insert" << endl;
    return;
  }

  heap_size++;
  int i = heap_size - 1;
  arr[i] = k;
  while (i != 0 && arr[parent(i)] < arr[i]) {
    swap(&arr[i], &arr[parent(i)]);
    i = parent(i);
  }
}


void Heap::increaseKey(int i, int newval) {
  arr[i] = newval;
  while (i != 0 && arr[parent(i)] < arr[i]) {
    swap(&arr[i], &arr[parent(i)]);
    i = parent(i);
  }
}

void Heap::swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void Heap::Heapify(int i) {
  int l = left(i);
  int r = right(i);
  int largest = i;
  if (l < heap_size && arr[l] > arr[i]) {
    largest = l;
  }
  if (r < heap_size && arr[r] > arr[largest]) {
    largest = r;
  }
  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    Heapify(largest);
  }
}

int Heap::getKey(int i) {
  return arr[i];
}

void Heap::printHeap() {
  int counter = 0;
  while (counter < heap_size) {
    cout << arr[counter] << " ";
    counter++;
  }
}

void Heap::printHeap2() {
  int counter = 0;
  while (counter < sizeof(arr2)) {
    cout << arr2[counter] << " ";
    counter++;
  }
}

void Heap::deletion() {
  int twoCount = 0;
  while (arr[0] != NULL) {
    arr2[twoCount] = arr[0];
    //printHeap2();
    //cout << "Array: " << arr2[twoCount] << ", twoCount: " << twoCount << endl;
    twoCount++;
    int last = arr[heap_size-1];
    arr[0] = last;
    heap_size--;
    Heapify(0);
  }
}
