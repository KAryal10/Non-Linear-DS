#include <iostream>
using namespace std;
// #include "BoundedArrayConst.h"
#include "BoundedArray.h"

int main() {
	BoundedArray arr1();
	BoundedArray arr2(2);
	BoundedArray arr3(5,10);
	
	//cout << "Size: " << arr1.size() << " Capacity: " << arr1.capacity() << endl;
	cout << "Size: " << arr2.size() << " Capacity: " << arr2.capacity() << endl;
	cout << "Size: " << arr3.size() << " Capacity: " << arr3.capacity() << endl;
	
	cout << "overload [] - " << "Value: " << arr3[1] << endl;
	
	arr3.insert(1,10);
	cout << "insert - " << "Size: " << arr3.size() << " Capacity: " << arr3.capacity() << endl;
	
	arr3.push_back(2.0);
	cout << "PUSH BACK - " << "Size: " << arr3.size() << " Capacity: " << arr3.capacity() << endl;

	arr3.push_back(2.0);
	cout << "PUSH BACK - " << "Size: " << arr3.size() << " Capacity: " << arr3.capacity() << endl;




	BoundedArray arr4(51, 60);
	cout << "Arr3 Size before : " << arr3.size() << " Capacity: " << arr3.capacity() << endl;
	arr3 = arr4;
	cout << "Arr3 Size After: " << arr3.size() << " Capacity: " << arr3.capacity() << endl;

	
	return 0;
}