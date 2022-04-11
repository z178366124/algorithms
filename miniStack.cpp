#include "miniStack.h"
#include <iostream>

/*template <class T>
class Node {
private:
	T data;
	Node* pre;
public:
	Node() {
		this->pre = NULL;
		this->data = 0;
	}
	~Node() {
		std::cout << "����" << std::endl;
	}
	T get() {
		return this->data;
	}
	void set(T da) {
		this->data = da;
	}

};*/



/*
���캯�� ��ʼ��
*/
template <class T>
Node<T>::Node() {
	pre = NULL;
	data = 0;
}


template <class T>
Node<T>::~Node() {
	std::cout << "����" << std::endl;
}

/*
��ȡԪ��
*/
template <class T>
T Node<T>::get() {
	return data;
}

template <class T>
void Node<T>::set(T da,Node<T>* const p) {
	data = da;
	pre = p;
}

template <class T>
Node<T>* Node<T>::getPre() {
	return pre;
}

template void Node<int>::set(int da,Node<int>* const p);
template void Node<double>::set(double da,Node<double>* const  p);

template int Node<int>::get();
template double Node<double>::get();

template Node<int>::~Node();
template Node<double>::~Node();

template Node<int>::Node();
template Node<double>::Node();


template <class T>
miniStack<T>::miniStack() {
	count = 0;
	pre = NULL;
}
template miniStack<double>::miniStack();
template miniStack<int>::miniStack();

template <class T>
void miniStack<T>::push(T data) {
	Node<T>* node = new Node<T>();
	node->set(data,pre);
	pre = node;
	count++;
}
template void miniStack<int>::push(int data);
template void miniStack<double>::push(double data);



//! @brief �˳�ջ
//! @tparam T ����
//! @return �����˳�����
template <class T>
T miniStack<T>::pop() {
	if (pre != NULL) {
		Node<T>* node = pre;
		pre = node->getPre();
		T da = node->get();
		delete node;
		count--;
		return da;
	}
	throw "ջ��������,�޷�ȡ��!";
}
template int miniStack<int>::pop();
template double miniStack<double>::pop();

template <class T>
int miniStack<T>::size() {
	return count;
}
template int miniStack<int>::size();
