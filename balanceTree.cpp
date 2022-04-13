#include <queue>
#include "balanceTree.h"
#include <iostream>


template <class T>
T Max(T a, T b)
{
	return (a > b ? a : b);
}

template <class T>
int getHeight(DataNode<T>* rot) {
	if (rot == NULL) return 1;
	rot->height = Max(getHeight(rot->leftNode), getHeight(rot->rightNode));
	return rot->height + 1;
}

template <class T>
DataNode<T>::DataNode(T da, DataNode* left, DataNode* right) {
	data = da;
	leftNode = left;
	rightNode = right;
	height = 0;
}

template <class T>
void balanceTree<T>::findNode(T da,DataNode<T>* rot) {
	if (rot->data > da) {
		if (rot->leftNode == NULL) {
			DataNode<T>* node = new DataNode<T>(da, NULL, NULL);
			rot->leftNode = node;
			//left2 = 1;
			return;
		}
		findNode(da, rot->leftNode);
	}
	if (rot->data < da) {
		if (rot->rightNode == NULL) {
			DataNode<T>* node = new DataNode<T>(da, NULL, NULL);
			rot->rightNode = node;
			//right2 = 1;
			return;
		}
		findNode(da, rot->rightNode);
	}
}

template <class T>
DataNode<T>* balanceTree<T>::findTwo(DataNode<T>* rot) {
	std::cout << "rot-data:" << rot->data << std::endl;
	DataNode<T>* btt = NULL;
	int r, l;
	if (rot->leftNode == NULL)l = 0;
	else {
		l = rot->leftNode->height;
	}
	if (rot->rightNode == NULL)r = 0;
	else {
		r = rot->rightNode->height;
	}
	int h = l-r;
	if (h > 1 || h < -1) {
		btt = rot;
		is_root = 1;
	}
	queue<DataNode<T>*> Q;
	Q.push(rot);
	while (!Q.empty()) {
		rot = Q.front();
		std::cout << "rot-data2:" << rot->data << std::endl;
		Q.pop();
		if (rot->leftNode != NULL) {
			
			if (rot->leftNode->leftNode == NULL)l = 0;
			else l = rot->leftNode->leftNode->height;
			if (rot->leftNode->rightNode == NULL)r = 0;
			else r = rot->leftNode->rightNode->height;
			h = l - r;
			if (h <= 1 && h >= -1) {
				Q.push(rot->leftNode);
			}
			if (h > 1 || h < -1) {
				btt = rot;
				Q.push(rot->leftNode);
				is_root = 0;
			}
		}
		if (rot->rightNode != NULL) {
			if (rot->rightNode->leftNode == NULL)l = 0;
			else l = rot->rightNode->leftNode->height;
			if (rot->rightNode->rightNode == NULL)r = 0;
			else r = rot->rightNode->rightNode->height;
			h = l - r;
			if (h <= 1 && h >= -1) {
				Q.push(rot->rightNode);
			}
			if (h > 1 || h < -1) {
				btt = rot;
				Q.push(rot->rightNode);
				is_root = 0;
			}
		}
	}
	return btt;
}

//! @brief  右旋转
//! @tparam T 
//! @param da 
template <class T>
void balanceTree<T>::rightXZ(DataNode<T>* rot) {
	if (is_root==1) {
		root = rot->leftNode;
		DataNode<T>* tmp = rot->leftNode->rightNode;
		rot->leftNode->rightNode = rot;
		rot->leftNode = tmp;
		return;
	}
	else {
		std::cout << "右旋转" << std::endl;
		DataNode<T>* a= NULL;
		if (fx == 0) {
			a = rot->leftNode;
		}
		else {
			a = rot->rightNode;
		}
		DataNode<T>* tmp = a->leftNode->rightNode;
		DataNode<T>* mid = a->leftNode;
		mid->rightNode = a;
		a->leftNode = tmp;
		if (fx == 0) {
			rot->leftNode=mid;
		}
		else {
			rot->rightNode=mid;
		}
	}
}

template <class T>
void balanceTree<T>::leftXZ(DataNode<T>* rot) {
	if (is_root == 1) {
		root = rot->rightNode;
		DataNode<T>* tmp = rot->rightNode->leftNode;
		rot->rightNode->leftNode = rot;
		rot->rightNode = tmp;
		return;
	}
	else {
		std::cout << "左旋转" << std::endl;
		DataNode<T>* a= NULL;
		if (fx == 0) {
			a = rot->leftNode;
		}
		else {
			a = rot->rightNode;
		}
		DataNode<T>* tmp = a->rightNode->leftNode;
		DataNode<T>* mid = a->rightNode;
		mid->leftNode = a;
		a->rightNode = tmp;
		if (fx == 0) {
			rot->leftNode = mid;
		}
		else {
			rot->rightNode = mid;
		}
	}
}

template <class T>
void balanceTree<T>::LRXZ(DataNode<T>* rot) {
	if (is_root == 1) {
		DataNode<T>* a = rot;
		DataNode<T>* b = rot->leftNode;  //交换变量的临时空间
		DataNode<T>* c = b->rightNode;
		DataNode<T>* c_left = c->leftNode;
		DataNode<T>* c_right = c->rightNode;
		c->leftNode = b;
		c->rightNode = a;
		a->leftNode = c_right;
		b->rightNode = c_left;
		root = c;
		//rightXZ(rot);
	}
	else {
		DataNode<T>* a= NULL;
		if (fx == 0) {
			a= rot->leftNode;
		}
		else if (fx == 1) {
			a = rot->rightNode;
		}
		DataNode<T>* b = a->leftNode;
		DataNode<T>* c = b->rightNode;
		DataNode<T>* c_left = c->leftNode;
		DataNode<T>* c_right = c->rightNode;
		c->leftNode = b;
		c->rightNode = a;
		a->leftNode = c_right;
		b->rightNode = c_left;
		//a = c;
		if (fx == 0) {
			rot->leftNode = c;
		}
		else {
			rot->rightNode = c;
		}
	}
}


template <class T>
void balanceTree<T>::RLXZ(DataNode<T>* rot) {
	if (is_root == 1) {
		DataNode<T>* a = rot;
		DataNode<T>* b = rot->rightNode;  //交换变量的临时空间
		DataNode<T>* c = b->leftNode;
		DataNode<T>* c_left = c->leftNode;
		DataNode<T>* c_right = c->rightNode;
		c->leftNode = a;
		c->rightNode = b;
		a->leftNode = c_left;
		b->rightNode = c_right;
		root = c;
		//rightXZ(rot);
	}
	else {
		DataNode<T>* a=NULL;
		if (fx == 0) {
			a = rot->leftNode;
		}
		else if (fx == 1) {
			a = rot->rightNode;
		}
		DataNode<T>* b = a->rightNode;
		DataNode<T>* c = b->leftNode;
		DataNode<T>* c_left = c->leftNode;
		DataNode<T>* c_right = c->rightNode;
		c->leftNode = a;
		c->rightNode = b;
		a->leftNode = c_left;
		b->rightNode = c_right;
		if (fx == 0) {
			rot->leftNode = c;
		}
		else {
			rot->rightNode = c;
		}
	}
}


template <class T>
void balanceTree<T>::push(T da) {
	if (root == NULL) {
		DataNode<T>* node = new DataNode<T>(da,NULL,NULL);
		root = node;
		return;
	}
	left1 = 0, left2 = 0, right1 = 0, right2 = 0;
	//if (da < root->data) left1 = 1;
	//else right1 = 1;
	DataNode<T>* rot = root;
	findNode(da, rot);
	getHeight<T>(root);
	DataNode<T>* p = findTwo(rot);
	DataNode<T>* pp = p;
	if (p != NULL) {
		std::cout << "is_root:" << is_root << std::endl;
		if (is_root==0) {
			if (da < pp->data) {
				pp = pp->leftNode;
			}
			else if (da > pp->data) {
				pp = pp->rightNode;
			}
			if (da < p->data) {
				fx = 0;//left
			}
			else if (da > p->data) {
				fx = 1;//right
			}
		}
		if (da<pp->data) {
			left1 = 1;
			pp = pp->leftNode;
		}
		else if (da > pp->data) {
			right1 = 1;
			pp = pp->rightNode;
		}
		if (da < pp->data) {
			left2 = 1;
		}
		else if (da > pp->data) {
			right2 = 1;
		}


		std::cout <<"da:"<< da<<" p:"<<p->data << std::endl;
		std::cout << left1 << right1 << left2 << right2 << std::endl;
		if (left1 == 1 && left2 == 1) {
			rightXZ(p);
		}
		else if (right1 == 1 && right2 == 1) {
			leftXZ(p);
		}
		else if (left1 == 1 && right2 == 1) {
			LRXZ(p);
		}
		else if (right1 == 1 && left2 == 1) {
			RLXZ(p);
		}
		/*std::cout << "no" << std::endl;
		std::cout << left1 << right1 << left2 << right2 << std::endl;*/
	}
}


template <class T>
balanceTree<T>::balanceTree() {
	root = NULL;
	size = 0;
	right1 = 0;
	left1 = 0;
	right2 = 0;
	left2 = 0;
}