#include "practico3.h"

//Clase Voto.
Voto::Voto(){
	codigo = -1;
	opcion = 0;
}

void Voto::setCodigo(int cod){
	if(codigo==-1){
		codigo = cod;
	}
	else{
		std::cout << "EL siguiente voto ya tiene un código asignado." << std::endl;
		codigo = -1;
	}
}

void Voto::setOpcion(int cod, int opt){
	if(cod == codigo){
		if(opt==1 || opt==2){
		opcion = opt;
		}
		else{
			std::cout << "Opción inválida." << std::endl;
			opcion = 0;
		}
	}
	else{
		std::cout << "Se está intentando proceder con la votación, pero el voto es incorrecto." << std::endl;
	}
}

int Voto::leer(int cod){
	if(cod == codigo){
		std::cout << "Código: " << codigo << std::endl;
		std::cout << "Opción: " << opcion << std::endl;
		//Estos 2 cout se pueden probar para que se vayan mostrando los códigos y opciones por cada voto.

		return opcion;
	}
	else{
		std::cout << "El código que intentó leer no existe." << std::endl;
		return -1;
	}
}


//Clase Padron.
Padron::Padron(){
	firma = NULL;
}

Padron::~Padron(){
	delete firma;
	firma = NULL;
}

void Padron::sign(){
	bool *firma;
	firma = new bool;
	*firma = true;
	this->firma = firma;
}

bool Padron::checkFirma(){
	if(*firma == true){
		std::cout << "Firma registrada correctamente." << std::endl;
		return true;
	}
	else{
		std::cout << "Firma no registrada." << std::endl;
		return false;
	}
}





//main
int main(){
	int clave;
	std::cout << "Introduzca clave para abrir urna: ";
	std::cin >> clave;

	if(clave==999){
		std::cout << "\nIniciando votaciones..." << std::endl;
		int cantidad;
		std::cout << "\nIntroduzca cantidad de votos: ";
		std::cin >> cantidad;

		int i;
		for(i=0;i<cantidad;i++){
			Voto *ptr_v;
			ptr_v = new Voto();

			ptr_v -> setCodigo(i);

			int votacion;
			std::cout << "\nIngrese su voto (1.- Apruebo / 2.- Rechazo): ";
			std::cin >> votacion;
			ptr_v -> setOpcion(i, votacion);

			ptr_v -> leer(i);

			Padron *ptr_p;
			ptr_p = new Padron();

			ptr_p -> sign();
			ptr_p -> checkFirma();
			ptr_p -> ~Padron();

			delete ptr_v;
			delete ptr_p;

		}
	}
	
	else{
		std::cout << "\nClave incorrecta." << std::endl;
	}

	return 0;
}