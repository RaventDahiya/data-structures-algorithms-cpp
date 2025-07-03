#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int imag;

public:
    // Constructor
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    // Function to display the complex number
    void show() {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }

    // Function to add two complex numbers
    Complex add(const Complex& obj) {
        Complex ans;
        ans.real = this->real + obj.real;
        ans.imag = this->imag + obj.imag;
        return ans;
    }
};

int main() {
    Complex c1(1, 2);
    Complex c2(2, 4);
    Complex c3 = c1.add(c2);
    c3.show();  // Output: 3 + 6i
    return 0;
}
