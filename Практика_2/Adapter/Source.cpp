#include <iostream>
#include "Queue_adapter.h"
using namespace std;

int main() {
	Queue q;

	q.push(1);
	q.push(40);
	q.push(20);
	q.push(-5);
    q.push(-40);
    q.push(23);
    q.push(336);
    q.push(321);
	q.push(1);

	q.display();

	q.pop();

	q.display();

	q.merge_sort();

    q.display();

	q.getNop();

	q.SetElement(3, 999);

	q.display();

	q.GetElement(3);
	q.GetElement(6);
	q.GetElement(0);
}