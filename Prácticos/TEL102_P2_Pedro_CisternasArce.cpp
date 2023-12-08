#include <iostream>
#include<cstring> //en vola esto ni uso esto
using namespace std;

/* Practico 2
 * Las tildes han sido omitidas intencionalmente para evitar problemas de compatibilidad
 */

struct help{
    char cat;
    help *connection = NULL;
};

/* Complete aqui su codigo para las funciones solicitadas */

help *createSequence(int length){
    static help *lala;
    lala[length];
    cout << "\nCreando secuencia..." << endl;

    int i;
    for(i=0;i<length;i++){
        cout << "Ingrese cat: ";
        if(i==0){
            cin >> lala[0].cat;
            cin >> lala.connection
        }
        if(i!=0){
            cin >> lala[i].cat;
        }
        cout << endl;
    };
    return lala;

}

//Clasificaciones:
//• S se relaciona con T o B, y viceversa.
//• J se relaciona con M, y viceversa.



int main(){
    // Pruebe lo solicitado acá, modifique los ejemplos para verificar otros casos.
    // Crear Secuencias de Categorias

    int l1 = 4; // Largo C a t e g o r i a s b a s e
    help *h1 = createSequence(l1);

    //int l1=4; // Largo Categorias base
    //int l2=10; // Largo Recomendaciones disponibles
    //help *h1 = createSequence(l1); // Categorias bases
    //help *h2 = createSequence(l2); // Recomendaciones disponible
    //connectSequences(h1, l1, h2, l2); // Conexión de recomendaciones
    //showHELP(h1, l1); // Mostrar recomendaciones

    return 0;
}


