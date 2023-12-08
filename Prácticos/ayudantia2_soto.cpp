#include <iostream>
using namespace std;


void swap(int a,int b){
	cout << "\na = " << a << endl;
	cout << "b = " << b << endl;
	cout << "Intercambiando valores..." << endl;
	int array[2];
	array[0] = a;
	array[1] = b;
	int &x = a;
	x = b;
	cout << "a = " << a << endl;
	int &y = b;
	y = array[0];
	cout << "b = " << b << endl;
}


int main(){

	swap(1, 2);
	return 0;
}