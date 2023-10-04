#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr;
	int max;
	int n;
	static const int MINSIZE;

    public:
        ListArray(){
	    max = 0;
	    n = 0;
	}

        ~ListArray(){
	}

	T operator[](int pos){
	    if (pos < 0 || pos >= max)
            throw std::out_of_range("Posición inválida");


	}
};
