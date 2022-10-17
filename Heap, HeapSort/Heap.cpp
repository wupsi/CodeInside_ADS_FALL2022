#include <iostream>
#include <vector>
using namespace std;

struct Heap{
private:
    vector<int> mh;

    int parent(int i){
        return (i - 1) / 2;
    }

    int left(int i){
        return (i * 2) + 1;
    }

    int right(int i){
        return (i * 2) + 2;
    }

public:

    int getMax(){
        return mh[0];
    }

    int extractMax(){
        int root = mh[0];
        swap(mh[mh.size() - 1], mh[0]);             // Step 1: swap
        mh.pop_back();                              // Step 2: remove
        if(!mh.empty()) heapify(0);                 // Step 3: heapify

        return root;
    }

    void heapify(int root){
        int largest = root, left = 2 * root + 1, right = 2 * root + 2;

        if(left < mh.size() and mh[left] > mh[largest])
            largest = left;
        if(right < mh.size() and mh[right] > mh[largest])
            largest = right;
        
        if(largest != root){
            swap(mh[root], mh[largest]);
            heapify(largest);
        }
    }

    void insert(int x){
        mh.push_back(x);
        int nw = mh.size() - 1;

        while(nw != 0 and mh[nw] > mh[parent(nw)]){
            swap(mh[nw], mh[parent(nw)]);
            nw = parent(nw);
        }
    }
    
    void HeapSort(){
        for(int i = mh.size() / 2 - 1; i >= 0; i--)
            heapify(i);

        for(int i = mh.size() - 1; i >= 0; i--){
            print();
            swap(mh[0], mh[i]);
            heapify(0);
        }
    }

    void print(){
        for(int i = 0; i < mh.size(); i++)
            cout << mh[i] << " ";
        
        cout << endl;
    }
};


int main(){

    Heap hp;
	int n = 12;
	int mh[n] = {5, 9, 1, 7, 2, 3, 11, 10, 12, 4, 8, 6};
	  
    for(int i = 0; i < n; i++){
        hp.insert(mh[i]);
    }

    hp.HeapSort();
    hp.print();
}