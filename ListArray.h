#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr;
	int max;
	int n;
	static const int MINSIZE;

        void resize(int new_size){
	     if (new_size < MINSIZE)
                  new_size = MINSIZE;
	     T* new_arr = new T[new_size];
	     for (int i = 0; i < n; i++) 
                  new_arr[i] = arr[i];
	     delete[] arr; 
             arr = new_arr; 
             max = new_size; 
	}

    public:
        ListArray(){
	    max = 0;
	    arr = new T[max];
	    n = 0;
	    MINSIZE;
	}

        ~ListArray(){
	    delete[] arr;
	}

	void insert(int pos, T e) override {
	    if (pos < 0 || pos > max - 1) 
                throw std::out_of_range("Índice fuera de rango");
	    if (n == max) 
                resize(max +1);
	    for (int i = n; i > pos; i--) 
                arr[i] = arr[i - 1];
	    arr[pos] = e;
	    n++;
	}
    
	void append(T e) override {
	    if (n == max) 
                resize(max +1);
	    arr[n] = e;
	    n++;
	}

	void prepend(T e) override {
            if (n == max) 
                resize(max +1);
	    for (int i = n; i > 0; i--) 
                arr[i] = arr[i - 1];
	    arr[0] = e;
	    n++; 
     	}

	T remove(int pos) override {
            if (pos < 0 || pos > max - 1) 
                throw std::out_of_range("Índice fuera de rango");
            T removedElement = arr[pos];
	    for (int i = pos; i < n - 1; i++) 
                arr[i] = arr[i + 1];
	    n--;
	    return removedElement;
	}

	T get(int pos) override {
            if (pos < 0 || pos > max - 1) 
                throw std::out_of_range("Índice fuera de rango");
            return arr[pos]; 
	}

	int search(T e) override {
            for (int i = 0; i < n; i++) {
                if (arr[i] == e) 
                    return i;
	    }
	    return -1;
	}

	bool empty() override {
            return n == 0;
	}

	int size() override {
            return n;
	}

	T operator[](int pos){
	    if (pos < 0 || pos >= max)
                throw std::out_of_range("Índice fuera de rango");
	    return arr[pos];
	}

	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
	    out << "[";
            for (int i = 0; i < list.n; ++i) {
                 out << list.arr[i];
                 if (i < list.n - 1) 
                      out << " ";
            }
            out << "]";
            return out;
        }


};
