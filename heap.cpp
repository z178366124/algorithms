#include "heap.h"
#include <cmath>
#include <iostream>

template <class T>
heap<T>::heap() {
	size = 0;  // 当前堆内元素个数
	capacity = 20;  // 堆容器空间
	array = new T[capacity];  // 初始化堆容器
}

template <class T>
heap<T>::~heap() {  // 析构
	delete[] array;
}


template <class T>
void heap<T>::addArr() {
	T* oldarr = array;
	array = new T[capacity << 1];
	for (int i = 0;i < capacity;i++)array[i] = oldarr[i];
	capacity = capacity << 1;
	delete[] oldarr;
}



template <class T>
void heap<T>::push(T data) {  // 大顶堆
	if (size >= capacity) addArr();
	array[size] = data;
	T tmp;
	int len=size;
	while (array[len] > array[(len - 1) >> 1] && len>0) {
		tmp = array[len];
		array[len] = array[(len - 1) >> 1];
		array[(len - 1) >> 1] = tmp;
		len = (len - 1) >> 1;
	}
	size++;
}

template <class T>
T heap<T>::pop() {
	T node = array[0];
	size--;
	array[0] = array[size];
	int len = 0;
	T tmp;
	while ((array[len * 2 + 1] > array[len] && len*2+1<size) || (array[len * 2 + 2] > array[len] && len*2+2<size)) {
		if (array[len * 2 + 1] > array[len*2+2]) {
			tmp = array[len * 2 + 1];
			array[len * 2 + 1] = array[len];
			array[len] = tmp;
			len = len * 2 + 1;
		}
		else{
			tmp = array[len * 2 + 2];
			array[len * 2 + 2] = array[len];
			array[len] = tmp;
			len = len * 2 + 2;
		}
	}
	return node;
}