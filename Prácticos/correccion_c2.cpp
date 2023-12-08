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
	mesa *m;
	m = new mesa;
	m->personas=0;
	m->used=0;
	int i;
	for(i=0;i<M;i++){
		cout << "Mesa " << i << ". ";
		cout << "Personas: " << local[i].personas << ". ";
		cout << "Usada: " << local[i].used << "." << endl;
	}
	int j;
	for(j=0;j<M;j++){
		if(local[j].used == 0){
			m = &local[j];
			//cout << "eo= " << &local[j] << endl;
			break;
		}
		if(j==M-1){
			if(local[j].used == 1){
				m = NULL;
			}
		}
	}
	//cout << "Mesa disponible: " << m << endl;
	return m;
}


int main(){

	mesa *local1;
	local1 = initMesas();
	mesa *m1;
	m1 = checkMesa(local1);
	cout << "Mesa disponible: " << m1 << endl;
	delete[] local1;
	//delete m1;

	return 0;
}
