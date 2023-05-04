#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest = root;
   int left = 2*root +1;   //Left child
   int right =  2*root +2; //Right child

   if(arr[largest]<arr[left] && left<n){
      largest = left;
   }

   if(arr[largest]<arr[right] && right<n){
      largest = right;
   }

   if(largest != root){
      //Swap arr[root] and arr[largest]
      swap(arr[root],arr[largest]);

      heapify(arr,n,largest);
   }
}

// implementing heap sort
void heapSort(int arr[], int n){
   // build heap
   for(int i = n/2 -1; i >= 0; i--){
      heapify(arr,n,i);
   }

   // extracting elements from heap one by one
   for(int i= n - 1; i>=0 ;i--){
      swap(arr[0],arr[i]);
      heapify(arr,i,0);
   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   // int heap_arr[] = {4,17,3,12,9,6};
   // int heap_arr[] = {7, 2, 9, 5, 1, 12, 10};
   // int heap_arr[] = {15, 3, 11, 9, 7, 4, 8, 2};
   // int heap_arr[] = {10, 14, 8, 12, 6, 1, 3, 9, 2};
   // int heap_arr[] = {13, 11, 7, 9, 4, 5, 8, 15, 6, 2};

   //Getting array size as input
   int size;
   cout << "Enter the size of the array: ";
   cin>>size;
   int heap_arr[size];
   cout << "Enter the numbers: ";

   //Getting array as input
   for (int i = 0; i < size; ++i) {
      cin >> heap_arr[i];
   }
   cout<<"\n";

   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);  //Sorting the array
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}