#pragma once
#ifndef HEAP_H

#define DEAP_H

template <class T>
class heap {
private:
	int capacity;// ��ǰ����
	T* array;  // ������
	int size;  // �Ѵ�С
public:
	heap();
	~heap();
	void push(T data);
	T pop();
	void sort();
	void addArr();
};

#endif // !HEAP_H
