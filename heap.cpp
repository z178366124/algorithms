#include "heap.h"
#include <cmath>
#include <iostream>

/*
heap<int>* H = new heap<FNN>();
cout << H->pop() << endl;
*/

//! @brief 默认比较
//! @tparam T 
//! @param a 
//! @param b 
//! @return 
template <class T>
int ocmp(T a, T b) {
	return a > b ? 1 : 0;
}

template <class T>
heap<T>::heap() {
	size = 0;  // 当前堆内元素个数
	capacity = 20;  // 堆容器空间
	array = new T[capacity];  // 初始化堆容器
	cmp = ocmp;  // 默认的比较器
}

template <class T>
heap<T>::heap(int (*ocmp)(T,T)) {
	size = 0;  // 当前堆内元素个数
	capacity = 20;  // 堆容器空间
	array = new T[capacity];  // 初始化堆容器
	cmp = ocmp;  // 自定义结构体的比较器
}

template <class T>
heap<T>::~heap() {  // 析构
	delete[] array;
}




template <class T>
void heap<T>::addArr() {  // 容器扩容，每次是之前的两倍
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
	//array[len] > array[(len - 1) >> 1]
	while (cmp(array[len], array[(len - 1) >> 1]) && len>0) {
		tmp = array[len];
		array[len] = array[(len - 1) >> 1];
		array[(len - 1) >> 1] = tmp;
		len = (len - 1) >> 1;
	}
	size++;
}

template <class T>
T heap<T>::pop() {  // 退出元素
	T node = array[0];
	size--;
	array[0] = array[size];
	int len = 0;
	T tmp;
	//array[len * 2 + 1] > array[len]
	//array[len * 2 + 2] > array[len]
	while ((cmp(array[len * 2 + 1],array[len]) && len*2+1<size) || (cmp(array[len * 2 + 2], array[len]) && len*2+2<size)) {
		if (cmp(array[len * 2 + 1],array[len * 2 + 2])) {
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
