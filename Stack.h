#define DEFAULT_STACK 20
#include "List.h"
template <class T>
class Stack {
public:
	Stack(unsigned capacity = DEFAULT_STACK);
	~Stack(); //destructor
	bool isEmpty() const; //returns true if stack is empty
	bool isFull() const; //returns true if stack is full
	unsigned size() const; //returns numbers of elements in stack
	void push(T k); //put k on the top of the stack
	T pop(); //Remove and return the top element from the stack
	T peek() const; //return the top element

private:
	List <T> m_container;

};

template < class T>
Stack<T>:: Stack(unsigned capacity):m_container(capacity){}

template <class T>
Stack<T>::~Stack(){}

template<class T>
bool Stack<T>::isEmpty() const {
	return m_container.isEmpty();
}

template<class T>
bool Stack<T>::isFull() const {
	return m_container.isFull();
}

template<class T>
unsigned Stack<T>::size() const {
	return m_container.getLength();
}

template<class T>
void Stack<T>::push(T k) {
	m_container.insert(size() + 1, k);
}

template<class T>
T Stack<T>::pop() {
	return m_container.remove(size());
}

template <class T>
T Stack<T>::peek() const {
	return m_container.retrieve(size());
}