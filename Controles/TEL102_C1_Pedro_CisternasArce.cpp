#include<iostream>
#include<cmath>
#define N 100
using namespace std;

struct valores{
	double aprox[N];
	double diff[N];
	int n;
};

//Función para (2i)!
int exp(int num){ 
	int i;
	int res = 1;
	int numcopy = num;
	for(i=0;i<num;i++){
		res *= numcopy;
		numcopy -= 1;
	};
	return res;
}

double elevar(double num1, int num2){
	int i;
	double res = 1;
	for(i=0;i<num2;i++){
		res *= num1;
	};
	return res;

}



double cosAprox(double x, int n){
	int i;
	double res;
	for(i=0;i<n;i++){
		double numerador = 0;
		double denominador = 0;

		double num1 = elevar(-1, i);
		double num2 = elevar(x, 2*i);
		numerador += num1*num2;

		denominador += exp(2*i);

		res += numerador/denominador;

	}


	return res;
}

double valAbs(double n){
	if(n<0){
		n *= -1;
	};
	return n;
}

double precision(double x, double p){

	int i;
	double aproximado;
	double pres;
	double coseno;
	coseno = cos(x);
	for(i=0;i<100;i++){
		aproximado = cosAprox(x,i);
		double resta = valAbs(aproximado-coseno);
		if(resta<=p){
			pres = i;
			i=101;
		}
	}
	return pres;
}



int main(){
	double x;
	double n;
	//double p;
	cout << "Ingrese valor: ";
	cin >> x;
	cout << endl << "Ingrese n: ";
	cin >> n;
	cout << endl;
	double a;
	a = cosAprox(x,n);
	cout << "Resultado: " << a << endl;
	//cout << "Ingrese precisión: ";
	//cin >> p;
	//a = precision(x, p);
	//cout << "Resultado: " << cosAprox(x, a) << endl;
	//cout << "Nivel de precisión: " << a << endl;

	//TODO LO ANTERIORMENTE COMENTADO ERA PARA PROBAR EL ITEM 2,
	//ITEM EL CUAL NO FUNCÓ (Osease mi función precision).
	//SI SE INTENTA PROBAR SOLO SACA SIN SENTIDOS.

	return 0;
}
