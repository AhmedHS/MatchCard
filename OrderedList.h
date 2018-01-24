#pragma once
#include "List.h"
class IsEqual { //Standard functor used to compare everything
public:
	template<class T>
	static bool compare(const T& a, const T& b) { return a == b; }
};
template <class T, class Order = IsEqual>
class OrderedList {
public:
	OrderedList(unsigned int capacity = DEFAULT_LIST); // constructor for an empty ordered list that can hold  
													   //  up to capacity Ts; default size is defined in List.h
	~OrderedList(); // destructor

	bool isEmpty() const; // returns true if the list is empty, and false otherwise  
	unsigned int getLength() const; // returns the number of Ts currently in the list

	T remove(unsigned int pos); // removes the element at location pos from the list, and returns it;
								// PRECONDITION: pos must be a valid position                                             
	T retrieve(unsigned int pos) const; // returns value at location pos without modifying it; 
										// PRECONDITION: pos must be a valid list position
	int insert(T item); // insert T at appropriate pos’n in the list and return this position


private:
	List<T> m_container;        // to hold the list of Ts
};

template <class T, class Order>
OrderedList<T, Order> ::OrderedList(unsigned int capacity) : m_container(capacity) {}

template <class T, class Order>
OrderedList<T, Order> :: ~OrderedList() {}

template <class T, class Order>
bool OrderedList<T, Order> ::isEmpty() const {
	return m_container.isEmpty();
}

template <class T, class Order>
unsigned int OrderedList<T, Order> ::getLength() const {
	return m_container.getLength();
}

template <class T, class Order>
T OrderedList<T, Order> ::remove(unsigned int pos) {
	return m_container.remove(pos);
}

template <class T, class Order>
T OrderedList<T, Order> ::retrieve(unsigned int pos) const {
	return m_container.retrieve(pos);
}

template <class T, class Order>
int OrderedList<T, Order> ::insert(T item) {
	unsigned int k;
	for (k = 1; k <= getLength(); k++)
		if (Order::compare(item, retrieve(k))) break;
	m_container.insert(k, item);
	return k;
}


