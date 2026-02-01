#include <iostream>
using namespace std;

/*  
template <class T>
class Box {
private:
    T value;
public:
    Box(T v) : value(v) {}

    // Function defined outside class
    T getValue();
};

// Defining member function outside class requires full template syntax
template <class T>
T Box<T>::getValue() {
    return value;
}

int main() {
    Box<int> intBox(123);
    Box<string> strBox("Hello World !");

    cout << intBox.getValue() << endl; // Output: 123
    cout << strBox.getValue() << endl; // Output: Hello Wolrd !
}
*/

template <typename T = int> // Default type is int
class Data {
    T item;
public:
    Data(T i) : item(i) {}
    void display() {
        cout << "Item: " << item << endl;
	}
};

int main() {
    Data<> d1(50.5);      // Uses default <int>
    Data<double> d2(5.5); // Overrides with <double>

	d1.display(); // Output: Item: 50
}
