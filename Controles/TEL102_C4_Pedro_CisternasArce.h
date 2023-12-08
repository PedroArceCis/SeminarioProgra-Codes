#include<iostream>
#include<string>
#include <vector>
using namespace std;

const int cobro = 1000; // Cobro por transaccion realizada
const int saldoMax_cvista = 500000; // Saldo maximo Cuenta Vista
const int retiroMax_cvista = 50000; // Retiro maximo por transaccion Cuenta Vista

class Cuenta{
    public:
        Cuenta(int id, int s, int tipo);
        int getId();
        int getSaldo();
        int getTipo();
        bool virtual depositar(int d) = 0; // Deposita cantidad d de dinero
        bool virtual retirar(int d) = 0; // Retira cantidad d de dinero
    protected:
        int idCuenta;
        int saldo;
        int tipoCuenta;
        
};


class Banco{
    public:
        Banco(vector<Cuenta*> &c);
        bool transaccion(int id1, int id2,int d);
        void estadoBanco();
    private:
        vector<Cuenta*> cuentas;
        int ganancias;
};


class CuentaCorriente: public Cuenta{
public:
	CuentaCorriente(int id, int s);
	bool depositar(int d);
	bool retirar (int d);
};


class CuentaVista: public Cuenta{
public:
	CuentaVista(int id, int s);
	bool depositar(int d);
	bool retirar (int d);
};