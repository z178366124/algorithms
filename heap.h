#pragma once
#ifndef HEAP_H

#define DEAP_H

template <class T>
class heap {
private:
	int capacity;// 当前容量
	T* array;  // 堆数组
	int size;  // 堆大小
public:
	heap();
	~heap();
	void push(T data);
	T pop();
	void sort();
	void addArr();
};

#endif // !HEAP_H
