#include <iostream>
using namespace std;

void swap(int** a, int** b) {
    int* temp = *a;
    *a = *b;
    *b = temp;

}

void swap2(int* a, int* b) {
    int* temp = a;
    a = b;
    b = temp;

}



int main() {
    int a = 5, b = 4;
    int *ptra = &a;
    int *ptrb = &b;    
  //  swap(&ptra, &ptrb);
  //  cout << *ptra << " " << *ptrb << endl;
    swap(ptra, ptrb);
    cout << *ptra << " " << *ptrb << endl;
    cout << a << " " << b << endl;
}