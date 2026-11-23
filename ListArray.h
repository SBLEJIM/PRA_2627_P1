#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include "List.h"
#include <stdexcept>

template <typename T>
class ListArray : public List<T> {
	private:
		T*arr;
		int max;
		int n;
		static const int MINSIZE;

		void resize(int new_size) {
			T* nuevo = new T[new_size];
			for (int i = 0; i < n; i++) {
				nuevo[i] = arr[i];
			}
		        delete[] arr;
		        arr = nuevo;
	                max = new_size;
		}	

	public:	
		ListArray(){
			arr = new T[MINSIZE];
			max = MINSIZE;
			n = 0;
		}
	       
	        ~ListArray() override {
			delete[] arr;
		}
	 
	        T operator[](int pos) {
			return get(pos);
		}

	        friend std::ostream& operator<<(std::ostream &out, ListArray<T> &list) {
			out << "List => [";
			if (list.n > 0) {
				out << "\n";
			}
		        for (int i = 0; i < list.n; i++) {
			        out << "  " << list.arr[i] << "\n";
			}
		        out << "]";
		        return out;
		}	

		

                //Métodos heredados de List
		
		//Inserta e en pos
		void insert(int pos, T e) override {
			if( pos < 0 || pos > n) {
				throw std::out_of_range("La posición no es válida");
			}
			if (n == max) {
				resize(max *2);
			}

		        for (int i = n - 1 ; i >= pos ; i--) {
			        arr[i + 1] = arr[i];
			}
		        arr[pos] = e;
		        n++;
		}	
                
		//Inserta e al final de la lista
		void append (T e) override {
			insert(n, e);
		}

	        //Inserta e al principio de la lista 
		void prepend(T e) override {
		        insert(0, e);
		}

	       //Elimina y devuelve el elemento en la posición pos
	       T remove(int pos) override {
		       if ( pos < 0 || pos >= n) {
			       throw std::out_of_range("Posición inválida!");
		       }
		       T elemento = arr[pos];
		       for (int i = pos + 1; i < n; i++) {
			      arr[i -1] = arr[i];
		       }
	               n--;
		       return elemento;
	        }	       


		//Devuelve el elemento que haya en pos
		T get(int pos) override {
			if (pos < 0 || pos >=n) {
				throw std::out_of_range("Posición inválida!");
			}
		        return arr[pos];
		}	
                
		//Devuelve la posicion de la primera ocurremica de e, o -1 si no está
		int search(T e) override {
			for (int i = 0; i < n; i++) {
				if (arr[i] == e) {
					return i;
				}
			}
		        return -1;
		}	

		//
		//Devuelve true si está vacío
		bool empty() override {
			return n == 0;
		}	

		//Devuelve el número de elementos de la lista 
		int size() override {
			return n;
		}



};	

template <typename T>
const int ListArray<T>::MINSIZE = 2;

#endif
