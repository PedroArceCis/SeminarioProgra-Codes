#include<iostream>
using namespace std;

// Las tildes han sido omitidas

const int cobro = 1000; // Cobro por transaccion
const int n_cuentas = 4; // Numero de cuentas

class Cuenta{
    public:
        Cuenta(int idCuenta, int saldo);
        int getId();
        int getSaldo();
        void depositar(int d); // Deposita cantidad d de dinero
        bool retirar(int d); // Retira cantidad d de dinero
    private:
        int idCuenta;
        int saldo;
};

class Banco{
    public:
        Banco(int n_cuentas, Cuenta *cuentas);
        ~Banco();
        bool transaccion(int id1, int id2,int d); // Transaccion entre cuentas con d dinero
        void estadoBanco(); // Muestra cuentas del banco
    private:
        Cuenta *cuentas;
        int n_cuentas;
        int ganancias;
};


//Clase Cuenta.
Cuenta::Cuenta(int idCuenta, int saldo){
    this->idCuenta = idCuenta;
    this->saldo = saldo;
}

int Cuenta::getId(){
    return idCuenta;
}

int Cuenta::getSaldo(){
    return saldo;
}

void Cuenta::depositar(int d){
    saldo+=d;
}

bool Cuenta::retirar(int d){
    if(d>saldo){
        std::cout << "ERROR: Se ha intentado retirar mas dinero del disponible." << std::endl;
        return false;
    }
    else{
        saldo-=d;
        return true;
    }
}


//Clase Banco.
Banco::Banco(int n_cuentas, Cuenta *cuentas){
    this->cuentas = cuentas;
    this->n_cuentas = n_cuentas;
    ganancias = 0;
}

Banco::~Banco(){
    delete[] cuentas;
    cuentas = NULL;
    n_cuentas = 0;
    ganancias = 0;
}

bool Banco::transaccion(int id1, int id2,int d){
    int i;
    for(i=0;i<n_cuentas;i++){
        if(cuentas[i].getId()==id1){
            int f;
            for(f=0;f<n_cuentas;f++){
                if(cuentas[f].getId()==id2){
                    cuentas[i].retirar(d+cobro);
                    ganancias+=cobro;
                    cuentas[f].depositar(d);
                    return true;
                }
                if(f==n_cuentas-1){  
                    if(cuentas[f].getId()!=id2){
                        std::cout << "ERROR: Id de la segunda cuenta no encontrado para la transaccion." << std::endl;
                        return false;
                    }
                }
            }
        }
        if(i==n_cuentas-1){
            if(cuentas[i].getId()!=id1){
                std::cout << "ERROR: Id de primera cuenta no encontrado para la transaccion." << std::endl;
                return false;
            }
        }
    }
    return false;
}

void Banco::estadoBanco(){
    int i;
    for(i=0;i<n_cuentas;i++){
        std::cout << "\nCuenta n° " << i+1 << ":" << std::endl;
        std::cout << "Id = " << cuentas[i].getId() << std::endl;
        std::cout << "Saldo = " << cuentas[i].getSaldo() << std::endl;
    }
}


//main.
int main(){
    //Intento de crear el arreglo de cuentas.
    //Cuenta *ptr_c;
    //ptr_c = new Cuenta[n_cuentas];

    //Intento de crear las cuentas por separado.
    Cuenta *cuenta1;
    cuenta1 = new Cuenta(1124, 200000);
    Cuenta *cuenta2;
    cuenta2 = new Cuenta(5748, 50000);
    Cuenta *cuenta3;
    cuenta3 = new Cuenta(9935, 30000);
    Cuenta *cuenta4;
    cuenta4 = new Cuenta(7548, 100000);
    //Intento fallido de intentar establecer las posiciones del arreglo :(
    //ptr_c[0] = Cuenta(1124, 200000);
    //ptr_c[1] = Cuenta(5748, 50000);
    //ptr_c[2] = Cuenta(9935, 30000);
    //ptr_c[3] = Cuenta(7548, 100000);


    //Eliminación de punteros.
    //delete ptr_c;
    delete cuenta1;
    delete cuenta2;
    delete cuenta3;
    delete cuenta4;

    return 0;
}