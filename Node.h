#include <iostream>

using namespace std;

template <class JD>

class Node{
    private:
        JD dato;
        Node *siguiente;
        
    public:
        Node();//Constructor cuando inicie
        Node(JD);//Constructor cuando reciba un entero
        Node(Node &);//constructor cuando reciba otro nodo
        ~Node();

        JD getdato();
        void setdato(JD);

        Node *getsiguiente();
        void setsiguiente(Node *);
};

template <class JD>

Node<JD>::Node(){
    dato=0;
    siguiente=NULL;
}

template <class JD>

Node<JD>::Node(JD dato){
    this->dato=dato;
    siguiente=NULL;
}

template <class JD>

Node<JD>::Node(Node &nodo){
    dato=nodo.dato;
    siguiente=nodo.siguiente;
}

template <class JD>

Node<JD>::~Node(){
}

template <class JD>

JD Node<JD>::getdato(){
    return dato;
}

template <class JD>

void Node<JD>::setdato(JD dato){
    this->dato=dato;
}

template <class JD>

Node<JD> *Node<JD>::getsiguiente(){
    return siguiente;
}

template <class JD>

void Node<JD>::setsiguiente(Node *siguiente){
    this->siguiente=siguiente;
}
