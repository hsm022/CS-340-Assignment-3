
/* This program is a modified version of heapsort code from https://www.geeksforgeeks.org/heap-sort/. */

#include <iostream>

using namespace std;

void heapify(int* array, int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && array[l] > array[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && array[r] > array[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(array[i], array[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(array, n, largest); 
    } 
}

void printArray(int* array, int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << array[i] << " "; 
    cout << endl << endl; 
} 

// main function to do heap sort 
void heapSort(int* array, int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(array, n, i); 
    
    cout << endl << "Result of turning the initial array to a max-heap:" << endl; 
    printArray(array, n); 

    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--) 
    { 
        // Move current root to end 
        swap(array[0], array[i]); 
  
        // call max heapify on the reduced heap 
        heapify(array, i, 0); 

        cout << "Swapping the root node and re-heapifying the max-heap:" << endl;
        printArray(array, n);
    } 
} 



int main()
{
   
    int size;
    cout << "Enter the total number of inputs you will be providing:";
    cin >> size;
    
    int *array = new int[size]; // dynamic array
  
    for(int i = 0;i<size;i++)
      {cout << "Enter " << i+1 << " of " << size <<":";
          cin >> array[i];}
      
    heapSort(array, size); 
    
  
    cout << "Final Sorted array is \n"; 
    printArray(array, size);
    
    delete[] array;

    return 0;
}
