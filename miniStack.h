#pragma once
#ifndef MINISTACK_H
#define MINISTACK_H

template <class T>
class Node {
private:
	T data;
	Node* pre;
public:
	Node();
	~Node();
	T get();
	Node<T>* getPre();
	void set(T da,Node<T>* const p);
};

template <class T>
class miniStack {
private:
	int count;
	Node<T>* pre;
public:
	miniStack();
	void push(T data);
	T pop();
	int size();
};

#endif