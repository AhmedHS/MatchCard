#include "List.h"
template<class T>
class Queue {
public:
	Queue(); //builds an empty queue
	~Queue();
	bool isEmpty() const; // returns true if the queue is empty
	void enqueue(T k); // adds k to the end of the queue
	T dequeue(); //removes and returns the item at the front of the queue
private:
	List<T> m_container; 
};

template<class T>
Queue<T>::Queue() {}
template<class T>
Queue<T>::~Queue(){} // default constructor

template<class T>
bool Queue<T>::isEmpty() const {
	return m_container.isEmpty();
}


template<class T>
void Queue<T>::enqueue(T k) {
	m_container.append(k);
}

template<class T>
T Queue<T>::dequeue() {
	return m_container.remove(1);
}
