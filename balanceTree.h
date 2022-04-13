#pragma once
#ifndef BALANCETREE_H
#define BALANCETREE_H

template <class T>
class DataNode {
public:
	int height;
	T data;
	DataNode<T>* leftNode;
	DataNode<T>* rightNode;
	DataNode(T, DataNode* left, DataNode* right);
	~DataNode();
};

template <class T>
class balanceTree {
private:
	int size;
	int left1, right1, left2, right2,fx,is_root;
public:
	DataNode<T>* root;
	void push(T da);
	T pop();
	void findNode(T da, DataNode<T>* rot);
	DataNode<T>* findTwo(DataNode<T>* rot);
	void rightXZ(DataNode<T>* rot);
	void leftXZ(DataNode<T>* rot);
	void LRXZ(DataNode<T>* rot);
	void RLXZ(DataNode<T>* rot);
	balanceTree();
	~balanceTree();
};


#endif // !BALANCETREE_H
