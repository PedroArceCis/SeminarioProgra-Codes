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
		//std::cout << "Código: " << codigo << std::endl;
		//std::cout << "Opción: " << opcion << std::endl;
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

/*ACLRACION IMPORTANTE:
Se me complico mas de la cuenta todo lo relacionado a la clase Urna.
Por ende, deje comentado todo lo que alcance a hacer respecto a esta
aunque no funcione, a la vez de funciones en el main que las llevaba
rato usando solo con las clases Voto y Padron, a la vez de algo extra
que deje especificados solo para que el concepto de conteo de votaciones
no se perdiese aunque mi programa no cuente con urna.*/
//Clase Urna.
/*Urna::Urna(int cod_mesa, int votantes){
	sellada = true;
	codigo = cod_mesa;
	libro_firmas = new Padron[votantes];
	votos = new Voto[votantes];
	sufragios = votantes;
}

Urna::~Urna(){
	delete[] libro_firmas;
	libro_firmas = NULL;
	delete[] votos;
	votos = NULL;
}

bool Urna::votar(int cod_voto, int opcion){

	votos[cod_voto] -> setCodigo(cod_voto);
	votos[cod_voto] -> setOpcion(cod_voto, opcion);
	votos[cod_voto] -> leer(cod_voto)
	
	libro_firmas[cod_voto] -> sign();
	libro_firmas[cod_voto] -> checkFirma();
	libro_firmas[cod_voto] -> ~Padron();

	return true;
}

void Urna::escrutar(int cod_mesa){
	int x;
	int apruebo=0;
	int rechazo=0;
	int nulo=0;

	for(x=0;x<cod_mesa;x++){
		if(votos[x].opcion==1){
			apruebo+=1;
		}
		else if(votos[x].opcion==2){
			rechazo+=1;
		}
		else{
			nulo+=1;
		}
	}

	std::cout << "\nApruebo = " << apruebo << std::endl;
	std::cout << "\nRechazo = " << rechazo << std::endl;
	std::cout << "\nNulo = " << nulo << std::endl;

}*/


//main
int main(){
	int clave;
	std::cout << "Introduzca clave para abrir urna: ";
	std::cin >> clave;

	//Parte extra para darle igual funcionalidad al programa sin clase urna.
	int apruebo=0;
	int rechazo=0;
	int nulo=0;

	if(clave==999){
		std::cout << "\nIniciando votaciones..." << std::endl;
		int cantidad;
		std::cout << "\nIntroduzca cantidad de votos: ";
		std::cin >> cantidad;

		/*Urna *ptr_u;
		ptr_u = new Urna(clave, cantidad);*/

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

			//Parte extra para darle igual funcionalidad al programa sin clase urna.
			if(votacion==1){
				apruebo+=1;
			}
			else if(votacion==2){
				rechazo+=1;
			}
			else{
				nulo+=1;
			}

			/*ptr_u -> votar(i, votacion);
			if(i==cantidad-1){
				ptr_u -> escrutar(i);
			}*/
		}
		/*ptr_u -> ~Urna();
		delete ptr_u;*/
	}
	
	else{
		std::cout << "\nClave incorrecta." << std::endl;
	}


	//Parte extra para darle igual funcionalidad al programa sin clase urna.
	std::cout << "\nVotaciones finalizadas." << std::endl;
	std::cout << "Apruebo = " << apruebo << std::endl;
	std::cout << "Rechazo = " << rechazo << std::endl;
	std::cout << "Nulo = " << nulo << std::endl;

	return 0;
}