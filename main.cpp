#include <iostream>
#include <cstring>
#include "heap.h"

using namespace std;

int main() {
  Heap h(100);
  /*bool playing = true;
  while (playing == true) {
    cout << "Please enter a command." << endl;
    char* input = new char[10];
    cin >> input;
    cin.get();
    if (strcmp("add", input) == 0) {
      int inNum = 0;
      cout << "Enter a value to be added to the heap." << endl;
      cin >> inNum;
      h.insertKey(inNum);
    }
    else if (strcmp("quit", input) == 0) {
      playing = false;
    }
    else if (strcmp("print", input) == 0) {
      h.printHeap();
      cout << endl;
    }
  }*/
  cout << "Please enter values for the heap." << endl;
  char *input = new char[100];
  cin.getline(input, 100, '\n');
  char *token = strtok(input, " ");
  while (token != NULL) {
    int token2 = atoi(token);
    h.insertKey(token2);
    token = strtok(NULL, " ");
  }
  h.printHeap();
}
