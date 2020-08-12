

#include <iostream>

using namespace std;

void heapify(int* arr, int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
}

void printArray(int* arr, int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 

// main function to do heap sort 
void heapSort(int* arr, int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
    
    printArray(arr, n); 
    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
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
      
    cout << "done" <<endl;
    heapSort(array, size); 
    
  
    cout << "Sorted array is \n"; 
    printArray(array, size);
    
    delete[] array;

    return 0;
}
