#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
 
        Node<T>* first;
	int n;

    public:

        //Métodos propios
	
	//Constructor
	ListLinked() {
		first = nullptr;
		n = 0;
	}

	//Destructor
	~ListLinked() override {
		while (first !=nullptr) {
			Node<T>* aux = first->next;
			delete first;
			first = aux;
		}
	}

        //Sobrecarga del operador [], deveulve el elemento que hay en la posicion pos
	T operator[](int pos) {
		if (pos < 0 || pos >= n) {
			throw std::out_of_range("Posición inválida!");
		}
	        Node<T>* aux = first;
	        for (int i = 0; i < pos; i++) {
		        aux = aux->next;
		}
	        return aux->data;	
	}

       //Sobrecarga <<, para imprimir una instancia de ListLinked por pantalla
       friend std::ostream& operator<<(std::ostream &out, ListLinked &list) {
                out << "List => [";
                if (list.n > 0) {
	            out << "\n";
                }
                Node<T>* aux = list.first;
                while (aux != nullptr) {
	            out << "  " << aux->data << "\n";
                    aux = aux->next;
                }
                out << "]";
                return out;
       }

       //Atributos heredados
       
       //Insertar e en pos
       void insert(int pos, T e) override {
	       if (pos < 0 || pos > n) {
		       throw std::out_of_range("Posición inválida!");
	       }
	       if (pos == 0) {
                       first = new Node<T>(e, first);   
	       } else {
		       Node<T>* prev = first;
		       for (int i = 0; i < pos -1; i++) {
			       prev = prev->next;
		       }
		       prev->next = new Node<T>(e, prev->next);
	       }
	       n++;       
	              
       }

       //Insertar e al final
       void append(T e) override {
               insert(n, e);
       }

       //Inserta e al principio
       void prepend(T e) override {
	       insert(0, e);
       }

       //Elimina y devuelve el elemento que hay en pos
       T remove(int pos) override {
	        if (pos < 0 || pos >= n) {
			throw std::out_of_range("Posición inválida!");
		}
		Node<T>* borrar;	
                if (pos == 0) {
			borrar = first;
			first = first->next;
		} else {
		        Node<T>* prev = first;
		        for (int i = 0; i < pos - 1; i++) {
				prev = prev->next;
			}
		        borrar = prev->next;
		        prev->next = borrar->next;
		}
		T elemento = borrar->data;
	        delete borrar;
	        n--;
		return elemento;	
       }

	//Devuelve el elemento que hay en pos
	T get(int pos) override {
		if (pos < 0 || pos >= n) {
			throw std::out_of_range("Posición inválida!");
		}
		Node<T>* aux = first;
		for (int i = 0; i < pos; i++) {
			aux = aux->next;
		}
		return aux->data;	
	}
	
	//Busca e y devuelve su pos
	int search(T e) override {
		Node<T>* aux = first;
		for (int i = 0; i < n; i++) {
			if (aux->data == e) {
				return i;
			}
		        aux = aux->next;
		}
	        return -1;
	}	

	//Indica si la lista está vacía
	bool empty() override {
		return n == 0;
	}

	//Devuelve el numero de elementos 
	int size() override {
		return n;
	}	
};

#endif LIST_LINKED_H
