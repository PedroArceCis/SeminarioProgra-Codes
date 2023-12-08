#include <iostream>
using namespace std;
/* Practico 2
 * Las tildes han sido omitidas intencionalmente para evitar problemas de compatibilidad
 */

struct help{
    char cat;
    help *connection =NULL;
};

help *createSequence(int length){
    help *a;
    a = new help[length];
    cout << "\nCreando Secuencia..." << endl;
    int i;
    for(i=0;i<length;i++){
        cout << "Ingrese cat: ";
        cin >> a[i].cat;
        cout << endl;
    }
    return a;
}

void connectSequences(help *h1, int l1, help *h2, int l2){
    int i;
    for(i=0;i<l1;i++){

        if(h1[i].cat == 'S'){
            int j;
            for(j=0;j<l2;j++){
                if(h2[j].cat == 'T'){
                    if(&h2[j]!=h1[i].connection){
                        h1[i].connection = &h2[j];
                        break;
                    }
                }
                if(h2[j].cat == 'B'){
                    if(&h2[j]!=h1[i].connection){
                        h1[i].connection = &h2[j];
                        break;
                    }
                }
            }
        }


        if(h1[i].cat == 'T'){
            int a;
            for(a=0;a<l2;a++){
                if(h2[a].cat == 'S'){
                    if(&h2[a]!=h1[i].connection){
                        h1[i].connection = &h2[a];
                        break;
                    }
                }
            }
        }


        if(h1[i].cat == 'B'){
            int b;
            for(b=0;b<l2;b++){
                if(h2[b].cat == 'S'){
                    if(&h2[b]!=h1[i].connection){
                        h1[i].connection = &h2[b];
                        break;
                    }
                }
            }
        }


        if(h1[i].cat == 'J'){
            int m;
            for(m=0;m<l2;m++){
                if(h2[m].cat == 'M'){
                    if(&h2[m]!=h1[i].connection){
                        h1[i].connection = &h2[m];
                        break;
                    }
                }
            }
        }


        if(h1[i].cat == 'M'){
            int x;
            for(x=0;x<l2;x++){
                if(h2[x].cat == 'J'){
                    if(&h2[x]!=h1[i].connection){
                        h1[i].connection = &h2[x];
                        break;
                    }
                }
            }
        }

    }

}



void showHELP(help *h, int length){
    cout << "Las recomendaciones son: " << endl;
    int i;
    for(i=0;i<length;i++){
        cout << h[i].cat << "-" << h[i].connection -> cat << endl;
    }
}




int main()
{
    int l1=4; // Largo Categorias base
    int l2=10; // Largo Recomendaciones disponibles
    help *h1 = createSequence(l1); // Categorias bases
    help *h2 = createSequence(l2); // Recomendaciones disponible
    connectSequences(h1, l1, h2, l2); // Conexión de recomendaciones
    showHELP(h1, l1); // Mostrar recomendaciones
    delete[] h1;
    delete[] h2;
    return 0;
}
