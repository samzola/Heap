/*
 * Author: Sam Zola
 * Date: 2/27/20
 * Program: This program allows the user to input data into a heap data structure, which outputs the data from largest to smallest.
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "heap.h"

using namespace std;

int main() {
  Heap h(100); //initialize heap
  cout << "Please enter how you would like to input your numbers (console or file)." << endl; //ask how they want to input
  char *method = new char[10];
  char *input = new char[100];
  cin.getline(method, 10, '\n');
  if (strcmp("console", method) == 0) { //if they say console, ask user to input numbers
    cout << "Please enter values for the heap with spaces between each value." << endl;
    cin.getline(input, 100, '\n'); //read in the numbers
    char *token = strtok(input, " "); //separate the numbers into tokens
    while (token != NULL) {
      int token2 = atoi(token); //turn token into int from char*
      h.insertKey(token2); //insert int token into heap
      token = strtok(NULL, " "); //keep going through numbers
    }
  }
  else if (strcmp("file", method) == 0) { //if they say file, ask for file name
    cout << "Please enter the name of the file." << endl;
    char *fileI = new char[100];
    cin.get(fileI, 100, '\n'); //read in file name
    streampos size;
    ifstream file(fileI, ios::in | ios::binary | ios::ate);
    if (file.is_open()) {
    size = file.tellg();
    file.seekg(0, ios::beg); //search for the file and read it
    file.read(input, size);
    file.close();
    char *token = strtok(input, " "); //separate numbers into tokens
    while (token != NULL) {
      int token2 = atoi(token); //turn token into int from char*
      h.insertKey(token2); //insert int token into heap
      token = strtok(NULL, " "); //keep going through numbers
    }
    }
  }
  cout << endl << "Heap: ";
  h.printHeap(); //print heap
  cout << endl;
  h.deletion(); //remove numbers, largest to smallest, and add to/print output
}
