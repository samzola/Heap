#include <iostream>
#include <cstring>
#include "heap.h"

using namespace std;

int main() {
  Heap h(100);

  cout << "Please enter values for the heap." << endl;
  char *input = new char[100];
  cin.getline(input, 100, '\n');
  char *token = strtok(input, " ");
  while (token != NULL) {
    int token2 = atoi(token);
    h.insertKey(token2);
    token = strtok(NULL, " ");
  }
  cout << "Heap: ";
  h.printHeap();
  cout << endl;
  h.deletion();
  cout << "Output: ";
  h.printHeap2();
  cout << endl;
}
