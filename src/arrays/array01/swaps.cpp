// Sample code for demonstration

#include <iostream>
using namespace std;

void swapByTemp(int &a,int &b){
    int temp = a;
    a=b;
    b=temp;
}

void swapByXOR(int &a,int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void swapBy_ADD_SUB(int &a,int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

void swapSTL(int &a, int &b) {
    swap(a, b);
}

void swapMulDiv(int &a, int &b) {
    if (b == 0) return; // Avoid divide-by-zero
    a = a * b;
    b = a / b;
    a = a / b;
}


int main() {
    int a=10;
    int b=20;
    swapBy_ADD_SUB(a,b);
    cout<<"a:"<<a<<" b:"<<b<<endl;
    swapByTemp(a,b);
    cout<<"a:"<<a<<" b:"<<b<<endl;
    swapByXOR(a,b);
    cout<<"a:"<<a<<" b:"<<b<<endl;
    swapSTL(a,b);
    cout<<"a:"<<a<<" b:"<<b<<endl;
    swapMulDiv(a,b);
    cout<<"a:"<<a<<" b:"<<b<<endl;

    return 0;
}