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
