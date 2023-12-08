#include<iostream>
using namespace std;

struct alumno{
	char nom[20];
	alumno *padrino = NULL;
};

int main(){

	alumno mechon, secundon;

	cout << "\nNombre del mechon: ";
	cin >> mechon.nom;
	cout << "\nNombre del padrino: "
	cin >> secundon.nom;
	//mechon.nom = "Pedro";
	//secundon.nom = "Nico";

	mechon.padrino = &secundon;

	cout << "\nEl padrino del " << mechon.nom;
	cout << " es el " << mechon.padrino -> nom << endl;

	return 0;
}