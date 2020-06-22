#include <iostream>
#include "Node.h"

using namespace std;

template <class VM>
class LinkedList
{
    private:
	int size;
	Node<VM> *head;
	
	public:
		
		class LLIterador
		{
			Node<VM> *iter;
			LinkedList<VM> lista;
			int pos;
	
			public:
		
				LLIterador(LinkedList<VM> lista);
				LLIterador(Node<VM> *n);
				LLIterador(LinkedList<VM> lista, int posicion);
				bool hasNext();
				Node<VM>* Next();
				LLIterador* first();
		        		
				LLIterador& operator = (Node<VM> *ptr);
				VM operator *();
		
				void operator ++ (int)
				{
					iter = iter->getsiguiente();
				}
		
				friend ostream& operator << (ostream &o,const LLIterador &lli)
				{
					o << lli.iter->getdato() ;
    				return o;
				}
		
		};
	
	
	public:

		LinkedList();
		LinkedList(const LinkedList &copia);

		void insertAtHead(const Node<VM> &n);
		void insertAtTail(const Node<VM> &n);
		void insertPos(const Node<VM> &n, int pos);
		void removeHead();
		void removeTail();
		void removePos(const int pos);
		void print();
		LLIterador begin();
		LLIterador end();
		
		Node<VM> *getHead();
		~LinkedList();
		
					
};

template <class VM>
LinkedList<VM>::LLIterador::LLIterador(LinkedList<VM> lista)
{
	iter = lista.getHead();
}

template <class VM>
LinkedList<VM>::LLIterador::LLIterador(Node<VM> *n)
{
	iter = n;
}


template <class VM>
LinkedList<VM>::LLIterador::LLIterador(LinkedList<VM> lista, int posicion)
{
	iter = lista.getHead();
	if (posicion != 0) 
	{
		while (iter != NULL && posicion)
		{
			iter = iter->getsiguiente();
			posicion--;
		}
	}
}


template <class VM>
bool LinkedList<VM>::LLIterador::hasNext()
{
	if (iter->getsiguiente() != NULL)		 
	{
		return true;
	}
	return false;
}

template <class VM>
Node<VM>* LinkedList<VM>::LLIterador::Next()
{
	return iter->getsiguiente();
}


template <class VM>
typename LinkedList<VM>::LLIterador* LinkedList<VM>::LLIterador::first()
{
	iter = lista.getHead();
}


template <class VM>
typename LinkedList<VM>::LLIterador& LinkedList<VM>::LLIterador::operator = (Node<VM> *ptr)
{
	iter = ptr;
}

template <class VM>
VM LinkedList<VM>::LLIterador::operator *()
{
	return iter->getdato();
}

//Constructor por defecto
template <class VM>
LinkedList<VM>::LinkedList()
{
	head = NULL;
	size = 0;
}

//Constructor copia
template <class VM>
LinkedList<VM>::LinkedList(const LinkedList &copia)
{
	size = copia.size;
	head  = copia.head;
}

//Eliminar el "head" del arreglo:
template <class VM>
void LinkedList<VM>::removeHead()
{
	Node<VM> *temp = head;
    head = head->getsiguiente();
    delete temp;
    return;
}


//Eliminar el último nodo del arreglo:
template <class VM>
void LinkedList<VM>::removeTail()
{
	Node<VM> *puntero = head;
	Node<VM> *temp = puntero;
	while(puntero->getsiguiente()!=NULL)
	{
		temp = puntero;
		puntero = puntero->getsiguiente();
	}
	    
	delete puntero;
	temp->setNext(NULL);
}

//Eliminar un nodo de cualquier posición del arreglo:
template <class VM>
void LinkedList<VM>::removePos(const int pos)
{
	int posicion = pos;
	
	if(posicion == 0 )
    {
        Node<VM> *temp = head;
        head = head->getsiguiente();
        delete temp;
        return;//Para no ejecutar los demás pasos
    }
    
    Node<VM> *puntero = head;
    while(puntero->getsiguiente()!=NULL && --posicion)
       	puntero = puntero->getsiguiente();
		
    if(puntero->getsiguiente()==NULL)  return;
	    
    Node<VM> *temp = puntero->getsiguiente();
    puntero->setNext(puntero->getsiguiente()->getsiguiente());
	delete temp;
	
    size--;

}

template <class VM>
void LinkedList<VM>::print()
{
	//Se itera sobre todos los elementos y se imprimen sus datos miembro
	Node<VM> *puntero = head;
	int k = 1;
	while(puntero)
    {
    	cout<< "Elemento "<< k<< ": "<< puntero->getdato()<<endl;
        puntero = puntero->getsiguiente();
        k++;
    }
}

//Insertar un nodo en la posición adecuada (para que esté ordenado)

template <class VM>
void LinkedList<VM>::insertAtHead(const Node<VM> &n)
{
	Node<VM> *new_node = new Node<VM>(n);
	Node<VM> *puntero = head;
	if (size == 0) 
	{
		head = new_node;
		size++;
		return;
	}
	
	new_node->setNext(head);
	head = new_node;
	
	size++;
}

template <class VM>
void LinkedList<VM>::insertAtTail(const Node<VM> &n)
{
	Node<VM> *new_node = new Node<VM>(n);
	Node<VM> *puntero = head;
	if (size == 0) 
	{
		head = new_node;
		size++;
		return;
	}
		
	while (puntero->getsiguiente() != NULL)
	{
		puntero = puntero->getsiguiente();
    }
    puntero->setNext(new_node);
		
	size++;	
}

template <class VM>
void LinkedList<VM>::insertPos(const Node<VM> &n, int pos)
{
	Node<VM> *new_node = new Node<VM>(n);
	
	if(pos==0)
    {
        new_node->setNext(head);
        head = new_node;
        return;
    }
    pos--;
    
    Node<VM> *puntero = head;
    while(puntero != NULL && --pos)
    {
        puntero = puntero->getsiguiente();
    }
    
    if(puntero == NULL)
    return;//La posición más grande que la longitud de la lista
    new_node->setNext(puntero->getsiguiente());
    puntero->setNext(new_node);
	
	size++;
}


template <class VM>
typename LinkedList<VM>::LLIterador LinkedList<VM>::begin()
{
	LLIterador ite(head); 
	return ite;
}


template <class VM>
typename LinkedList<VM>::LLIterador LinkedList<VM>::end()
{
	LLIterador ite(head);
		
	if (size != 0) 
	{
		while ( LinkedList::LLIterador::iter != NULL)
		{
			ite = ite->Next();
		}
	}
	 
	return ite;
}


template <class VM>
Node<VM>* LinkedList<VM>::getHead()
{
	return head;
}

//Destructor
template <class VM>
LinkedList<VM>::~LinkedList()
{
	Node<VM> *puntero = head;
	Node<VM> *siguiente2 = NULL;
	
	//Se libera la memoria asignada con new
	while(puntero != NULL)
    {
        siguiente2 = puntero->getsiguiente();
        delete puntero;
        puntero = siguiente2;
    }
}




