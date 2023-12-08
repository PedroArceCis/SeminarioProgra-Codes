#include<iostream>
using namespace std;

const int M=5;

struct mesa{
	int personas;
	int used;
};


mesa *initMesas(){

	int i;
	mesa *local;

	local = new mesa[M];

	for(i=0;i<M;i++){
		local[i].personas=0;
		local[i].used=0;

	}

	return local;
}

mesa *checkMesa(mesa *local){
	cout << "\nMesas incializadas..." << endl;
	mesa *a;
	a = new mesa;
	int i;
	for(i=0;i<M;i++){
		cout << "Mesa " << i << ". ";
		cout << "Personas: " << local[i].personas << ". ";
		cout << "Usada: " << local[i].used << "." << endl;
		int j;
		for(j=0;j<M;j++){
			if(local[j].used == 0){
				a = &local[j];
				break;
			}
			if(i==M-1){
				if(local[j].used == 1){
					a = NULL;
				}
			}
		}
	}
	cout << "Mesa disponible: " << &a << endl;
	return a;
}


int main(){

	mesa *local1;
	local1 = initMesas();
	mesa *m1 = checkMesa(local1);
	delete[] local1;
	delete m1;

	return 0;
}
