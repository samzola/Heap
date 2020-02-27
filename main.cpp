#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "heap.h"

using namespace std;

int main() {
  Heap h(100);
  cout << "Please enter how you would like to input your numbers (console or file)." << endl;
  char *method = new char[10];
  char *input = new char[100];
  cin.getline(method, 10, '\n');
  if (strcmp("console", method) == 0) {
    cout << "Please enter values for the heap with spaces between each value." << endl;
    cin.getline(input, 100, '\n');
    char *token = strtok(input, " ");
    while (token != NULL) {
      int token2 = atoi(token);
      h.insertKey(token2);
      token = strtok(NULL, " ");
    }
  }
  else if (strcmp("file", method) == 0) {
    cout << "Please enter the name of the file." << endl;
    char *fileI = new char[100];
    cin.get(fileI, 100, '\n');
    streampos size;
    ifstream file(fileI, ios::in | ios::binary | ios::ate);
    if (file.is_open()) {
    size = file.tellg();
    file.seekg(0, ios::beg);
    file.read(input, size);
    file.close();
    char *token = strtok(input, " ");
    while (token != NULL) {
      int token2 = atoi(token);
      h.insertKey(token2);
      token = strtok(NULL, " ");
    }
    }
  }
  cout << endl << "Heap: ";
  h.printHeap();
  cout << endl;
  h.deletion();
}
