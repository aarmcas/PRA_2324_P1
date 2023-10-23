#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
 
        Node<T>* first;
	int n;

    public:

        ListLinked(){
		first = nullptr;
		n = 0;
	}

	~ListLinked(){
		while (first != nullptr) {
        		Node<T>* aux = first->next; 
        		delete first;
			first = aux; 
	    	}
	}

	T operator[](int pos){
		if (pos < 0 || pos >= n) 
        		throw std::out_of_range("Índice fuera de rango");
    		Node<T>* aux = first;
    		for (int i = 0; i < pos; i++) 
        		aux = aux -> next;
    		return aux -> data;
	}

	friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
    		Node<T>* aux = list.first;
    		out << "[";
    		while (aux != nullptr) {
        		out << aux -> data;
        		aux = aux -> next;
        			if (aux != nullptr) 
            				out << ", ";
    		}	
    		out << "]";

    		return out;
	}

};
