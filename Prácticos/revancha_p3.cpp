#include "practico3.h"

//Clase Voto.

Voto::Voto(){
	codigo = -1;
	opcion = -1;
}

void Voto::setCodigo(int cod){
	if(codigo==-1){
		codigo = cod;
	}
	else{
		std::cout << "Su intento de voto ya tiene código asignado." << std::endl;
	}
}

void Voto::setOpcion(int cod, int opt){
	if(codigo==cod){
		if(opt==1 || opt==2){
			opcion = opt;
		}
		else{
			std::cout << "Voto nulo." << std::endl;
			opcion = 0;
		}
	}
	else{
		std::cout << "ERROR: El código ingresado no coincide para proceder con la votación." << std::endl;
	}
}

int Voto::leer(int cod){
	if(codigo==cod){
		return opcion;
	}
	else{
		return -1;
	}
}


//Clase Padron.

Padron::Padron(){
	firma = new bool;
	*firma = false;
}

Padron::~Padron(){
	delete firma;
	firma = NULL;
}

void Padron::sign(){
	if(checkFirma()){
		std::cout << "El padron ya fue firmado." << std::endl;
	}
	else{
		std::cout << "Firmando padron..." << std::endl;
		*firma = true;
		std::cout << "Padron correctamente firmado." << std::endl;
	}
}

bool Padron::checkFirma(){
	return *firma;
}


//Clase Urna.

Urna::Urna(int cod_mesa, int votantes){
	sellada = true;
	codigo = cod_mesa;
	libro_firmas = new Padron[votantes];
	votos = new Voto[votantes];
	sufragios = 0;
}

Urna::~Urna(){
	sellada = false;
	codigo = -1;
	delete[] libro_firmas;
	libro_firmas = NULL;
	delete[] votos;
	votos = NULL;
	sufragios = -1;
}


bool Urna::votar(int cod_voto,int opcion){
	if(votos[cod_voto].leer(cod_voto)!=-1){
		std::cout << "ERROR: El voto del código ingresado debió haber sido ya registrado con anterioridad. Imposible proceder con la votación." << std::endl;
		return false;
	}
	else{
		votos[cod_voto].setCodigo(cod_voto);
		votos[cod_voto].setOpcion(cod_voto, opcion);
		libro_firmas[cod_voto].sign();
		sufragios += 1;
		return true;
	}
}

void Urna::escrutar(int cod_mesa){
	if(cod_mesa != codigo){
		std::cout << "ERROR: Código ingresado de mesa no válido." << std::endl;
	}
	else if(codigo==-1 || sellada==false){
		std::cout << "ERROR: Mesa ya escrutada." << std::endl;
	}
	else{
		sellada = false;
		int apruebo, rechazo, nulo, i;
		apruebo = 0;
		rechazo = 0;
		nulo = 0;
		for(i=0;i<sufragios;i++){
			if(votos[i].leer(i)==1){
				apruebo += 1;
			}
			else if(votos[i].leer(i)==2){
				rechazo += 1;
			}
			else if(votos[i].leer(i)==0){
				nulo += 1;
			}
			else{
				std::cout << "ERROR: Lectura no válida de voto a la hora de escrutar." << std::endl;
				break;
			}
		}
		std::cout << "\nConteo de votos finalizado." << std::endl;
		std::cout << "Apruebo: " << apruebo << " votos." << std::endl;
		std::cout << "Rechazo: " << rechazo << " votos." << std::endl;
		std::cout << "Nulo: " << nulo << " votos." << std::endl;
	}
}


//main

int main(){
	int clave_mesa;
	std::cout << "Introduzca código de mesa para comenzar: ";
	std::cin >> clave_mesa;
	int cant_votos;
	std::cout << "\nIntroduzca cantidad de votos: ";
	std::cin >> cant_votos;
	Urna *ptr_u;
	ptr_u = new Urna(clave_mesa, cant_votos);
	int x;
	for(x=0;x<cant_votos;x++){
		int op_voto;
		std::cout << "\nIngrese su voto." << std::endl;
		std::cout << "(1.-Apruebo / 2.-Rechazo): ";
		std::cin >> op_voto;
		ptr_u -> votar(x, op_voto);
	}
	ptr_u -> escrutar(clave_mesa);
	ptr_u -> ~Urna();
	delete ptr_u;
	return 0;
}

