#include <iostream>
#include "Queue_adapter.h"
#include <cstdlib>
using namespace std;

int main() {
	Queue q;

	int N_s[10] = {300, 600, 900, 1200, 1500, 1800, 2100, 2400, 2700, 3000};

	for(int j = 0; j < 10; j++){
		q.clear();

		for(int i = 0; i < N_s[j]; i++){
			q.push(rand());
		}

		q.free_nop();
		q.MergeSort();
	}
}