#include<iostream>
#include<cstring>
using namespace std;

struct poke{
	char nombre[40];
	float peso;
};

poke fillPoke(){
	poke pkmn;
	cout << "Introduzca el nombre de su poke: ";
	cin >> pkmn.nombre;
	cout << "\nIntroduzca el peso de " << pkmn.nombre << ": ";
	cin >> pkmn.peso;
	cout << endl;
	return pkmn;
}

poke heavierPoke(poke team[6]){
	poke heavy;
	int i;
	float a = 0;
	for(i=0;i<6;i++){
		if(team[i].peso > a){
			a = team[i].peso;
		}
	};
	for(i=0;i<6;i++){
		if(team[i].peso == a){
			heavy = team[i];
		}
	};
	return heavy;
}

int main(){
	poke equipo[6], pesado;
	int i;
	for (i=0;i<6;i++){
		poke a;
		a = fillPoke();
		equipo[i] = a;
	};
	pesado = heavierPoke(equipo);
	cout << "El Poke más pesado es " << pesado.nombre << " con ";
	cout << pesado.peso << " [kg]." << endl;

	return 0;
}