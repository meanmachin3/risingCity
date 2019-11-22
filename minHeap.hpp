#ifndef PROJECT1_MINHEAP_H
#define PROJECT1_MINHEAP_H

struct Building{

	int building_num;
	int executed_time;
	int total_time;
	struct Node* twin;
};

class Heap{
private:

public:
	struct Building* root;
	int element_added;

	Building* insert(int, int, int, Node*);

	Building* removeMin();

	void swap(Building *, Building *);
	
	void heapify();

	Heap(int);
	
	void updateMin(int);

	int left_child(int);

	int right_child(int);
	
	~Heap(){
		delete root;
	}
};


#endif //PROJECT1_MINHEAP_H
