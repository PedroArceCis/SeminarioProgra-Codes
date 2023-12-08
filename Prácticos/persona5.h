#include <iostream>
#include <string>
#include <vector>

class Persona{
public:
	Persona(std::string name, std::string secondname, int rutificador);
	std::string getNombre();
	std::string getApellido();
	int getRut();
	std::string Nombre;
	std::string Apellido;
protected:
	int RUT;
};

class ListaCurso{
public:
	ListaCurso(std::vector<Persona*> alumnos, int clases);
	void ingresarAsistencia(Persona *p);

	std::vector<Persona*> Personas;
	int Catedras;
	void mayorAsistencia();
	void menorAsistencia();
protected:
	float obtenerAsistencia(int rutificador);
	std::vector<int> Asistencia;
};
