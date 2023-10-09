#pragma once
#include<iostream>
#include<queue>
using namespace std;

class Queue {
private:
	queue<int> q;
	int nop = 0;
public:
	void push(int n) {
		q.push(n); nop++;
	}

	void pop() {
		q.pop(); nop++;
	}

	int back() {
		nop++;
		return q.back();
	}

	int front() {
		nop++;
		return q.front();
	}

	int size() {
		nop++;
		return q.size();
	}

	void display() {
		queue<int> q_tmp = q; nop++;
		while (!q_tmp.empty()) {
			cout << q_tmp.front() << " "; nop++;
			q_tmp.pop(); nop++;
		}
		cout << endl; nop++;
	}
	
	void getNop(){
		cout<<nop<<endl;
	}

    void merge_sort() {
        int n = q.size();
        int* a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = q.front(); q.pop();
        }

        int mid = n / 2;
        if (n % 2 == 1)
            mid++;
        int h = 1;

        int* c = new int[n];
        int step;
        while (h < n)
        {
            step = h;
            int i = 0;
            int j = mid;
            int k = 0;
            while (step <= mid)
            {
                while ((i < step) && (j < n) && (j < (mid + step)))
                {
                    if (a[i] < a[j])
                    {
                        c[k] = a[i];
                        i++; k++;
                    }
                    else {
                        c[k] = a[j];
                        j++; k++;
                    }
                }
                while (i < step) {
                    c[k] = a[i];
                    i++; k++;
                }
                while ((j < (mid + step)) && (j < n)) {
                    c[k] = a[j];
                    j++; k++;
                }
                step = step + h;
            }
            h = h * 2;

            for (i = 0; i < n; i++)
                a[i] = c[i];
        }
        for (int i = 0; i < n; i++) {
            q.push(c[i]);
        }  
    }
};
