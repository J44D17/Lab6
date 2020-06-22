#include<iostream>
#include <stdlib.h>
#include "LinkedList.h"
#include <conio.h>

using namespace std;

int main(){

    int opcion,dato;
    LinkedList<float> lista;

    do{
    cout<<"\tMENU"<<endl;
    cout<<"1.- Insertar elemento"<<endl;
    cout<<"2.- Mostrar lista"<<endl;
    cout<<"3.- Eliminar elemento"<<endl;
    cout<<"4.- Salir"<<endl;
    cout<<"Opcion: ";cin>>opcion;

    switch(opcion){
        case 1:cout<<"Digite un numero para la cabeza: ";
        cin>>dato;
        lista.insertAtHead(dato);
        cout<<endl;
        system("pause");
        break;

        case 2:cout<<"Digite un numero para la cola: ";
        cin>>dato;
        lista.insertAtTail(dato);
        cout<<endl;
        system("pause");
        break;
    
        case 3:
        lista.print();
        system("pause");
        break;

        case 4:
        lista.print();
        cout<<endl;
        cout<<"Digite la posicion de numero a eliminar: ";
        cin>>dato;
        lista.removePos(dato);
        cout<<endl;
        system("pause");
        break;

        case 5:
        lista.print();
        cout<<endl;
        cout<<"Desea elimianar: ";
        cin>>dato;
        lista.removePos(dato);
        cout<<endl;
        system("pause");
        break;

        }
        
        
        system("cls");
    }while(opcion != 4);
    
    getch();
    return 0;
}