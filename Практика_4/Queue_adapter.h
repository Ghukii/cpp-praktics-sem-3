#pragma once
#include<iostream>
#include<queue>
#include<vector>
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

    void MergeSortImpl(vector<int>& values, vector<int>& buffer, int l, int r) {
        if (l < r) {
            int m = (l + r) / 2; nop++;
            MergeSortImpl(values, buffer, l, m); nop++;
            MergeSortImpl(values, buffer, m + 1, r); nop++;

            int k = l;
            for (int i = l, j = m + 1; i <= m || j <= r; ) {
                if (j > r || (i <= m && values[i] < values[j])) {
                        buffer[k] = values[i]; nop++;
                        ++i; nop++;
                } 
                else {
                    buffer[k] = values[j]; nop++;
                    ++j; nop++;
                }
                ++k; nop++;
            }
            for (int i = l; i <= r; ++i) {
                values[i] = buffer[i]; nop++;
            }
            while(!q.empty()){
                q.pop(); nop++;
            }
            for (int i = l; i <= r; ++i) {
                q.push(values[i]); nop++;
            }
        }
    }

    void MergeSort() {
        vector <int> values; nop++;

        while(!q.empty()){
            values.push_back(q.front()); nop++;
            q.pop(); nop++;
        }

        if (!values.empty()) {
            vector<int> buffer(values.size()); nop++;
            MergeSortImpl(values, buffer, 0, values.size() - 1); nop++;
        }
    }

    void SetElement(int index, int data){
        int s = q.size(); nop++;
        int* tmp = new int[q.size()]; nop++;
        for(int i=0;i<s;i++){
            tmp[i] = q.front(); nop++;
            q.pop(); nop++;
        }
        tmp[index] = data; nop++;
        for(int i=0;i<s;i++){
            q.push(tmp[i]); nop++;
        }
        delete[] tmp; nop++;
    }

    void GetElement(int index){
        int s = q.size(); nop++;
        int* tmp = new int[q.size()]; nop++;
        for(int i=0;i<s;i++){
            tmp[i] = q.front(); nop++;
            q.pop(); nop++;
        }

        cout << tmp[index] << endl;

        for(int i=0;i<s;i++){
            q.push(tmp[i]); nop++;
        }
        
        delete[] tmp; nop++;
    }
};