#include <iostream>
#include "BoundedArray.h"
#include "HybridList.h"

#include <vector>

class Node {
public:
	int data;
	Node* next;
};

class NodeArr {
public:
	std::vector<int> data0;
	std::vector<int>* data;
	int* data2;
	//int data;
	NodeArr* next;
};

void NodeTest() {
	Node* head = nullptr;
	Node* a = nullptr;
	Node* b = nullptr;
	Node* c = nullptr;

	head = new Node();
	a = new Node();
	b = new Node();
	c = new Node();

	a->data = 1;
	b->data = 3;
	c->data = 2;

	head->next = a;
	a->next = b;
	b->next = c;
	c->next = NULL;

	/*
		Node* x = head->next;
		while (x != NULL) {
			std::cout << "Node: " << x->data << std::endl;
			x = x->next;
		}
	*/
	Node* y = head->next;
	int count = 0;
	while (y != NULL) {
		count++;
		if (count > 2) {
			std::cout << "SPLIT Node" << std::endl;
			std::cout << "Splitted: " << y->data << std::endl;
			y = y->next;
			continue;
		}
		std::cout << "Node: " << y->data << std::endl;
		y = y->next;
	}
}

void arrTestVector() {
	
	std::vector<BoundedArray*> vec;
	BoundedArray* arr = new BoundedArray(0, 4);
	int j = 0;
	int currentIND = 0;
	for (int i = 0; i < 21; i++) {
		arr->push_back(i);
		if (arr->size() > 2) {
			vec.push_back(arr);
			arr = new BoundedArray(0, 4);
		}
	}

	for (int i = 0; i < vec.size(); i++) {
		std::cout << "START ";
		for (int j = 0; j < vec[i]->size(); j++) {
			std::cout << vec[i]->at(j) << " ";
		}
		std::cout << " END"<<std::endl;

	}
}

//i am going to insert numbers 1 to 5 inclusive

void NodeArrayTest() {
	BoundedArray arr1(0, 4);
	arr1.push_back(1);
	arr1.push_back(2);
	arr1.push_back(3);
	arr1.push_back(4);


	BoundedArray arr2(0, 4);
	arr2.push_back(5);
	arr2.push_back(6);
	arr2.push_back(7);
	arr2.push_back(8);
	
	
	/*
	NodeArr* head = nullptr;
	NodeArr* a = nullptr;
	NodeArr* b = nullptr;
	NodeArr* c = nullptr;

	head = new NodeArr();
	a = new NodeArr();
	b = new NodeArr();
	c = new NodeArr();
	*/
	HybridList list(5);
	list.push_back(1);
	list.push_back(1);
	list.push_back(1);
	list.push_back(1);
	list.push_back(1);
	list.push_back(1);
	list.push_back(1);


	//HybridList newx;
	

	//HybridListNode newNode;

	
	//newx.push_back(newNode);


	//HybridListNode next = null

	

	//arr.push_back(1);
	//arr.push_back(2);




}

//implementation of nodearray

void NodeArrayImplem() {
	std::vector<int> vec(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	
	std::vector<int> vec2(0);
	vec2.push_back(5);
	vec2.push_back(6);
	vec2.push_back(7);
	vec2.push_back(8);

	NodeArr* head = new NodeArr();
	NodeArr* nArr = new NodeArr();
	NodeArr* nArr2 = new NodeArr();
	
	
	nArr->data0 = vec;
	nArr->data = &vec;
	nArr2->data = &vec2;

	head->next = nArr;
	nArr->next = nArr2;
	nArr2->next = nullptr;

	NodeArr* nodeCur = head->next;
	while (nodeCur != nullptr) {
		std::cout << "Found a listnode" << std::endl;
		
		for (int i = 0; i < 4; i++) {
			std::cout << nodeCur->data->at(i) << " ";
		}
		std::cout << std::endl;
		nodeCur = nodeCur->next;
	}
}





int main() {

	HybridList hListA(4);
	hListA.push_back(11.11);
	hListA.push_back(22.22);
	hListA.push_back(33.33);
	hListA.push_back(44.44);
	hListA.push_back(55.55);
//	hListA.push_back(66.66);
//	hListA.push_back(77.77);
	//hListA.push_back(88.88);
	//hListA.push_back(99.99);
	//hListA.push_back(999.999);
	//hListA.push_back(999.999);
	//hListA.push_back(999.999);
	//hListA.pop_back();
	//hListA.pop_back();
	//hListA.pop_back();
	//hListA.pop_back();
	//hListA.pop_back();
	//hListA.pop_back();

	hListA.pop_back();
	hListA.pop_back();
	hListA.pop_back();
	hListA.pop_back();
	hListA.pop_back();

	//hListA.erase(0);
//	hListA.erase(0);
//	hListA.erase(0);
//	hListA.erase(0);
//	hListA.erase(0);
//	hListA.erase(0);
//	hListA.erase(3);
//	hListA.erase(3);

	//hListA.erase(3);

	//hListA.insert(3, 43.21);//can be inserted in 0 but cant be inserted in 1
	//hListA.insert(3, 43.21);//can be inserted in 0 but cant be inserted in 1
	//hListA.insert(0, 43.21);//can be inserted in 0 but cant be inserted in 1
	//hListA.insert(0, 43.21);//can be inserted in 0 but cant be inserted in 1
	//hListA.insert(0, 43.21);//can be inserted in 0 but cant be inserted in 1
	//hListA.insert(0, 43.21);//can be inserted in 0 but cant be inserted in 1

	//hListA.insert(0,43.11);//can be inserted in 0 but cant be inserted in 1

	//hListA.push_back(43.21);//can be inserted in 0 but cant be inserted in 1
	//hListA.insert(0, 43.21);//can be inserted in 0 but cant be inserted in 1
	//hListA.insert(0, 43.21);//can be inserted in 0 but cant be inserted in 1
	//hListA.insert(1, 43.21);//can be inserted in 0 but cant be inserted in 1
	//hListA.insert(1, 43.21);//can be inserted in 0 but cant be inserted in 1
	//hListA.insert(1, 43.21);//can be inserted in 0 but cant be inserted in 1
	//hListA.insert(1, 43.21);//can be inserted in 0 but cant be inserted in 1


	//hListA.insert(8, 43.21);
	//hListA.insert(8, 42.21);
	//hListA.insert(8, 41.21);
	//hListA.insert(8, 40.21);
	//hListA.erase(1);
	//hListA.erase(2);
	//hListA.erase(3);
	//hListA.erase(4);
	//hListA.erase(4);
	//hListA.erase(6);
	//hListA.pop_back();
	//hListA.pop_back();
	//hListA.pop_back();
    //hListA.push_back(111.111);
	//hListA.pop_back();
	//hListA.push_back(222.222);
	//hListA.push_back(333.333);

	
	
	
	HybridListNode* he;
	he = hListA.front();
	int rPointer = 0;
	while (he != nullptr) {
		std::cout << "Found an LL" << std::endl;
		for (int i = 0; i < he->size(); i++) {
		std::cout << he->at(i);
		std::cout << " ";
		rPointer++;
		}	
		std::cout<<he->size() << std::endl;
		he = he->next;
	}
	return 0;
}