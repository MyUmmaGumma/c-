#include <iostream>
using namespace std;

template <class T>
class MaxHeap {
      private:
            T *arr;
            int size;  
            
            T left(int i)
            {
                return 2*i;
            }

            T right(int i)
            {
                return 2*i+1;
            }

            T parent(int i) 
            {
                return i/2;
            }

            void swap(T &i, T &j)
            {
                T temp;
                temp = i;
                i = j;
                j = temp;
            }
    public:
            void max_heapify(int i, int size_arr)
            {
                int l = left(i);
                int r = right(i);
                int largest = -1;
                
                if (l <= size_arr && arr[l] > arr[i]) {
                    largest = l;
                } else {
                    largest = i;
                }
        
                if (r <= size_arr && arr[r] > arr[largest]) {
                    largest = r;
                }

                if (largest != i) {
                    swap(arr[largest], arr[i]);
                    max_heapify(arr, largest, size_arr);
                } 
            
            }
        
            void build_map_heap() {
                for (int i = size/2; i <= 0; i--) {
                    max_heapify(i, size);
                }
            }

            void print(int *arr)
            {
                 int i = 0;
                 for (; i < size; ++i) {
                    cout<<arr[i];
                 }
                 cout<<endl;
            }


};
