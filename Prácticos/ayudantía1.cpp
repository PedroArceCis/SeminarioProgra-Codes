#include<iostream>
using namespace std;

struct estudiante{
	char nombre[30];
	char apellido[30];
	float promedio;
	int best_nota;
};

estudiante info(){
	estudiante e;
	cout << "Ingrese el nombre del estudiante: ";
	cin >> e.nombre;
	cout << "\nIngrese el apellido del estudiante: ";
	cin >> e.apellido;
	cout << "\nIngrese el promedio de notas del estudiante: ";
	cin >> e.promedio;
	cout << "\nIngrese la mejor nota del estudiante: ";
	cin >> e.best_nota;
	cout << endl;
	return e;
}

void semestre(estudiante e){
	if(e.promedio>=55){
		cout << e.nombre << " " << e.apellido;
		cout << " ha aprobado el ramo con un " << e.promedio;
		cout << " de promedio." << endl;
	}
	else if(e.promedio>=50 && e.best_nota>=70){
		cout << e.nombre << " " << e.apellido;
		cout << " tiene derecho a rendir el global con un " << e.promedio;
		cout << " de promedio." << endl;
	}
	else if(1>0){
		cout << e.nombre << " " << e.apellido;
		cout << " ha reprobado el ramo con un " << e.promedio;
		cout << " de promedio." << endl;
	}
}

void curso(){

	int n;
	cout << "Ingrese el nÃºmero de estudiantes: ";
	cin >> n;
	cout << "\n";
	estudiante es[n];
	int i;
	for(i=0;i<n;i++){
		es[i]=info();
	}
	int mejor_promedio=-1;
	int peor_promedio=101;
	float suma_promedios=0;
	for(i=0;i<n;i++){
		suma_promedios += es[i].promedio;
		if(es[i].promedio>mejor_promedio){
			mejor_promedio = es[i].promedio;
		}
		if(es[i].promedio<peor_promedio){
			peor_promedio = es[i].promedio;
		}
	}
	for(i=0;i<n;i++){
		if(es[i].promedio==mejor_promedio){
			cout << es[i].nombre << " " << es[i].apellido;
			cout << " fuÃ© el mejor promedio del curso." << endl;
		}
		if(es[i].promedio==peor_promedio){
			cout << es[i].nombre << " " << es[i].apellido;
			cout << " fuÃ© el peor promedio del curso." << endl;
		}
	}
	float promediofinal = suma_promedios/n;
	cout << "El promedio final del curso fue de " << promediofinal << endl;
}



int main(){

	curso();

	return 0;
}
