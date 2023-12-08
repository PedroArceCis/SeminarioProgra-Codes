#include <iostream>
using namespace std;

struct estudiante
{
	char nombre[40];
	char apellido[40];
	float promedio;
	int mejorNota;
};

estudiante input()
{
	estudiante e1;
	cout << "ingrese el nombre del estudiante: ";
	cin >> e1.nombre;
	cout << "\ningrese el apellido del estudiante: ";
	cin >> e1.apellido;
	cout << "\ningrese el promedio del estudiante: ";
	cin >> e1.promedio;
	cout << "\ningrese la mejor nota del estudiante: ";
	cin >> e1.mejorNota;
	cout << "\n";
	return e1;
}

void condicionGlobal(estudiante e1)
{
	if (e1.promedio >= 55)
	{
		cout << "El estudiante aprobó." << endl;
	}
	else if (50 <= e1.promedio < 55 && e1.mejorNota>= 70)
	{
		cout << "El estudiante tiene derecho a rendir control global." <<endl;
	}
	if (50 <= e1.promedio < 55 && e1.mejorNota < 70 || e1.promedio < 50)
	{
		cout << "El estudiante reprobó." << endl;
	} 
}

void ejercicio4()
{
	int nroEstudiantes;
	float promedio, sumaPromedio;
	estudiante e1, mejor, peor;
	mejor.promedio = 0;
	peor.promedio = 101;
	cout << "Ingrese el número de estudiantes: ";
	cin >> nroEstudiantes;
	estudiante estudiantesArreglo[nroEstudiantes];
	for (int i = 0; i < nroEstudiantes; i++)
	{
		estudiantesArreglo[i] = input();
		sumaPromedio += estudiantesArreglo[i].promedio;
		if (estudiantesArreglo[i].promedio < peor.promedio)
		{
			peor = estudiantesArreglo[i];
		}
		if (estudiantesArreglo[i].promedio > mejor.promedio)
		{
			mejor = estudiantesArreglo[i];
		}

	}
	promedio = sumaPromedio/nroEstudiantes;
	cout << mejor.nombre << " " << mejor.apellido << " es el estudiante con mejor promedio, con un promedio de: " << mejor.promedio << endl;
	cout << peor.nombre << " " << peor.apellido << " es el estudiante con peor promedio, con un promedio de: " << peor.promedio<<endl;
	cout << "El promedio del curso es: " << promedio << endl;
}
int main()
{
	ejercicio4();
	return 0;
}