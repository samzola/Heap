#include <iostream>
#include <climits>
#include <cmath>
#include "heap.h"

using namespace std;

Heap::Heap(int cap) {
  heap_size = 0;
  capacity = cap;
  arr = new int[cap];
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
  
}

int Heap::deleteKey(int i) {
  
}

void Heap::swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void Heap::Heapify(int i) {
  int l = left(i);
  int r = right(r);
  int largest = i;
  if (l > heap_size && arr[l] > arr[i]) {
    largest = l;
  }
  if (r > heap_size && arr[r] < arr[i]) {
    largest = r;
  }
  if (largest != 1) {
    
  }
}
