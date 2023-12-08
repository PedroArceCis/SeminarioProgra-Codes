#include "TEL102_C4_Pedro_CisternasArce.h"

/*Métodos Clase Cuenta.*/
Cuenta::Cuenta(int id, int s, int tipo){
	idCuenta = id;
	saldo = s;
	tipoCuenta = tipo;
}

int Cuenta::getId(){
    return idCuenta;
}

int Cuenta::getSaldo(){
    return saldo;
}

int Cuenta::getTipo(){
	return tipoCuenta;
}


/*Métodos Cuenta Corriente.*/
CuentaCorriente::CuentaCorriente(int id, int s): Cuenta(id, s, 1) {}

bool CuentaCorriente::depositar(int d){
	saldo+=d;
	return true;
}

bool CuentaCorriente::retirar(int d){
	saldo-=d;
	return true;
}


/*Métodos Cuenta Vista.*/
CuentaVista::CuentaVista(int id, int s): Cuenta(id, s, 0) {}

bool CuentaVista::depositar(int d){
	if(saldo+d > saldoMax_cvista){
		return false;
	}
	else{
		saldo+=d;
		return true;
	}
}

bool CuentaVista::retirar(int d){
	if(d > retiroMax_cvista){
		return false;
	}
	else if(saldo-d < 0){
		return false;
	}
	else{
		saldo-=d;
		return true;
	}
}


/*Métodos Clase Banco.*/
Banco::Banco(vector<Cuenta*> &c){
	cuentas = c;
	ganancias = 0;
}

bool Banco::transaccion(int id1, int id2,int d){
	int i;
	for(i=0;i<cuentas.size();i++){
		if(cuentas[i]->getId() == id1){
			int j;
			for(j=0;j<cuentas.size();j++){
				if(cuentas[j]->getId() == id2){
					if(cuentas[i]->retirar(d+cobro) && cuentas[j]->depositar(d)){
                    	ganancias+=cobro;
                    	return true;
                    }
                    else{
                    	return false;
                    }
                }
                if(j == cuentas.size()-1){  
                    if(cuentas[j]->getId() != id2){
                        cout << "\nERROR: Id de la segunda cuenta no encontrado para la transaccion." << endl;
                        return false;
                    }
                }
            }
        }
        if(i == cuentas.size()-1){
            if(cuentas[i]->getId() != id1){
                cout << "\nERROR: Id de primera cuenta no encontrado para la transaccion." << endl;
                return false;
            }
        }
    }
    return false;
}

void Banco::estadoBanco(){
	cout << "\n";
	int i;
	for(i=0;i<cuentas.size();i++){
		cout << "Cuenta N°" << i+1 << ".\n";
		cout << "ID: " << cuentas[i]->getId() << endl;
		if(cuentas[i]->getTipo() == 0){
			cout << "Tipo de cuenta: Cuenta Vista." << endl;
		}
		else if(cuentas[i]->getTipo() == 1){
			cout << "Tipo de cuenta: Cuenta Corriente." << endl;
		}
		cout << "Saldo: $" << cuentas[i]->getSaldo() << "\n\n";
	}
	cout << "Ganancias: $" << ganancias << endl;
}


/*Main*/

int main(){
	vector<Cuenta*> cuentitas = {new CuentaVista(1124, 400000),
	new CuentaVista(5748, 400000),
	new CuentaCorriente(9935, 700000),
	new CuentaCorriente(7548, 1500000)};

	Banco *b;
	b = new Banco(cuentitas);

	cout << "\n|Estado inicial del banco.|" << endl;
	b->estadoBanco();

	//////////////////////////////////////

	if(b->transaccion(9935, 5748, 200000)){
		cout << "\nTransaccion N°1 realizada correctamente." << endl;
	}
	else{
		cout << "\nTransaccion N°1 no es posible de realizar." << endl;
	}

	//////////////////////////////////

	if(b->transaccion(9935, 1124, 50000)){
		cout << "\nTransaccion N°2 realizada correctamente." << endl;
	}
	else{
		cout << "\nTransaccion N°2 no es posible de realizar." << endl;
	}

	////////////////////////////////////

	if(b->transaccion(9935, 7548, 800000)){
		cout << "\nTransaccion N°3 realizada correctamente." << endl;
	}
	else{
		cout << "\nTransaccion N°3 no es posible de realizar." << endl;
	}

	//////////////////////////////////

	if(b->transaccion(5748, 1124, 500000)){
		cout << "\nTransaccion N°4 realizada correctamente." << endl;
	}
	else{
		cout << "\nTransaccion N°4 no es posible de realizar." << endl;
	}

	////////////////////////////////

	if(b->transaccion(9935, 1124, 100000)){
		cout << "\nTransaccion N°5 realizada correctamente." << endl;
	}
	else{
		cout << "\nTransaccion N°5 no es posible de realizar." << endl;
	}

	///////////////////////////////////

	cout << "\nTransacciones finalizadas." << endl;

	cout << "\n|Estado final del banco.|" << endl;
	b->estadoBanco();

	//Liberación de memoria.
	int i;
	for(i=0;i<cuentitas.size();i++){
		delete cuentitas[i];
	}
	delete b;

	return 0;
}
