#include <iostream>
#include "Queue_adapter.h"
#include <cstdlib>
using namespace std;

int main() {
	Queue q;

	for(int i = 0; i < 501; i++){
		q.push(rand());
	}

	q.free_nop();
	q.MergeSort();

	q.getNop();

	Queue t;
	
	for(int i = 0; i < 5001; i++){
		t.push(rand());
	}

	t.free_nop();
	t.MergeSort();
	
	t.getNop();

	t.free_nop();
	t.getNop();
}