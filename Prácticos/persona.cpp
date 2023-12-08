#include "persona5.h"

Persona::Persona(std::string name, std::string secondname, int rutificador){
	Nombre = name;
	Apellido = secondname;
	RUT = rutificador;
}

std::string Persona::getNombre(){
	return Nombre;
}

std::string Persona::getApellido(){
	return Apellido;
}

int Persona::getRut(){
	return RUT;
}

ListaCurso::ListaCurso(std::vector<Persona*> alumnos, int clases){
	Personas = alumnos;
	Catedras = clases;
	int i;
	for(i=0;i<Personas.size();i++){
		Asistencia.push_back(0);
	}
}

void ListaCurso::ingresarAsistencia(Persona *p){
	int i;
	for(i=0;i<Asistencia.size();i++){
		if(Personas[i]==p){
			Asistencia[i]++;
			break;
		}
	}
}

float ListaCurso::obtenerAsistencia(int rutificador){
	int i;
	for(i=0;i<Asistencia.size();i++){
		if(Personas[i]->getRut()==rutificador){
			return Asistencia[i];
			break;
		}
	}
	return -1;
}

void ListaCurso::mayorAsistencia(){
	int i;
	int num_mayor = 0;
	for(i=0;i<Personas.size();i++){
		if(obtenerAsistencia(Personas[i]->getRut())>num_mayor){
			num_mayor = obtenerAsistencia(Personas[i]->getRut());
		}
	}
	std::cout << "\nLos alumnos con mayor asistencia del curso son: " << std::endl;
	for(i=0;i<Personas.size();i++){
		if(obtenerAsistencia(Personas[i]->getRut())==num_mayor){
			std::cout << "-" << Personas[i]->getNombre() << " " << Personas[i]->getApellido() << std::endl;
		}
	}
	std::cout << "Con asistencia de " << num_mayor << " dias de " << Catedras << std::endl;
}

void ListaCurso::menorAsistencia(){
	int i;
	int num_menor = Catedras;
	for(i=0;i<Personas.size();i++){
		if(obtenerAsistencia(Personas[i]->getRut())<num_menor){
			num_menor = obtenerAsistencia(Personas[i]->getRut());
		}
	}
	std::cout << "\nLos alumnos con menor asistencia del curso son: " << std::endl;
	for(i=0;i<Personas.size();i++){
		if(obtenerAsistencia(Personas[i]->getRut())==num_menor){
			std::cout << "-" << Personas[i]->getNombre() << " " << Personas[i]->getApellido() << std::endl;
		}
	}
	std::cout << "Con asistencia de " << num_menor << " dias de " << Catedras << std::endl;
}


int main(){
	int cant;
	std::cout << "\nIngrese cantidad de alumnos: ";
	std::cin >> cant;
	std::vector<Persona*> estudiantes(0);
	int i;
	for(i=0;i<cant;i++){
		std::string nom;
		std::string ap;
		int num;
		std::cout << "\nIngrese nombre de estudiante N°" << i+1 << ": ";
		std::cin >> nom;
		std::cout << "\nIngrese apellido: ";
		std::cin >> ap;
		std::cout << "\nIngrese RUT (sin guion, reemplaze la K con un 0): ";
		std::cin >> num;
		Persona *a;
		a = new Persona(nom, ap, num);
		estudiantes.push_back(a);
	}
	int dias;
	std::cout << "\n¿Cuantos dias de catedra quiere pasar asistencia?: ";
	std::cin >> dias;
	ListaCurso *lc;
	lc = new ListaCurso(estudiantes, dias);
	for(i=0;i<dias;i++){
		std::cout << "\n|DIA " << i+1<< "|" << std::endl;
		int j;
		for(j=0;j<cant;j++){
			int presente;
			std::cout << "\n¿" << estudiantes[j]->getNombre() << " " << estudiantes[j]->getApellido() << "?" << std::endl;
			std::cout << "(1.- Presente / 2.- Ausente): ";
			std::cin >> presente;
			if(presente==1){
				lc->ingresarAsistencia(estudiantes[j]);
			}
			else if(presente!=2){
				std::cout << "ERROR: Opcion Incorrecta..." << std::endl;
			}
		}
	}

	lc->menorAsistencia();
	lc->mayorAsistencia();

	for(i=0;i<cant;i++){
		delete estudiantes[i];
	}
	delete lc;

	return 0;
}