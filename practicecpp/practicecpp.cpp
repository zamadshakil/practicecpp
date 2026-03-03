
/*
#include <iostream>
using namespace std;

int findMax(int arr[], int left, int right) {
    // Base case: If the array has only one element
    if (left == right) {
        return arr[left];
    }
    // Find the middle point
    int mid = left + (right - left) / 2;
    // Recursively find the maximum in the left and right halves
    int maxLeft = findMax(arr, left, mid);
    int maxRight = findMax(arr, mid + 1, right);
    // Return the maximum of the two halves
    return (maxLeft > maxRight) ? maxLeft : maxRight;
}

int main() {
    int arr[] = {3, 5, 7, 2, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxElement = findMax(arr, 0, n - 1);
    cout << "The maximum element in the array is: " << maxElement << endl;
    return 0;
}

/*
================================================================================
                    TIME & SPACE COMPLEXITY SCENARIOS
================================================================================

------------------------------------------------------------------------------
                           TIME COMPLEXITY
------------------------------------------------------------------------------

1. O(1) - Constant Time
   - Execution time does not depend on input size
   - Example: Accessing array element by index, push/pop on stack

   int getFirst(int arr[]) {
       return arr[0];  // Always 1 operation regardless of array size
   }

------------------------------------------------------------------------------

2. O(log n) - Logarithmic Time
   - Input size is reduced by half each iteration
   - Example: Binary search, operations on balanced BST

   int binarySearch(int arr[], int left, int right, int target) {
       while (left <= right) {
           int mid = left + (right - left) / 2;
           if (arr[mid] == target) return mid;
           else if (arr[mid] < target) left = mid + 1;
           else right = mid - 1;
       }
       return -1;
   }

------------------------------------------------------------------------------

3. O(n) - Linear Time
   - Execution time grows linearly with input size
   - Example: Linear search, traversing array once

   int linearSearch(int arr[], int n, int target) {
       for (int i = 0; i < n; i++) {
           if (arr[i] == target) return i;
       }
       return -1;
   }

------------------------------------------------------------------------------

4. O(n log n) - Linearithmic Time
   - Common in efficient sorting algorithms
   - Example: Merge sort, Quick sort (average case), Heap sort

   void mergeSort(int arr[], int left, int right) {
       if (left < right) {
           int mid = left + (right - left) / 2;
           mergeSort(arr, left, mid);      // O(log n) divisions
           mergeSort(arr, mid + 1, right);
           merge(arr, left, mid, right);   // O(n) merge operation
       }
   }

------------------------------------------------------------------------------

5. O(n^2) - Quadratic Time
   - Nested loops over input
   - Example: Bubble sort, Selection sort, comparing all pairs

   void bubbleSort(int arr[], int n) {
       for (int i = 0; i < n - 1; i++) {       // O(n)
           for (int j = 0; j < n - i - 1; j++) { // O(n)
               if (arr[j] > arr[j + 1]) {
                   swap(arr[j], arr[j + 1]);
               }
           }
       }
   }

------------------------------------------------------------------------------

6. O(n^3) - Cubic Time
   - Three nested loops
   - Example: Matrix multiplication (naive), finding triplets

   void matrixMultiply(int A[][N], int B[][N], int C[][N], int n) {
       for (int i = 0; i < n; i++) {
           for (int j = 0; j < n; j++) {
               C[i][j] = 0;
               for (int k = 0; k < n; k++) {
                   C[i][j] += A[i][k] * B[k][j];
               }
           }
       }
   }

------------------------------------------------------------------------------

7. O(2^n) - Exponential Time
   - Doubles with each additional input
   - Example: Recursive Fibonacci (naive), generating all subsets

   int fibonacci(int n) {
       if (n <= 1) return n;
       return fibonacci(n - 1) + fibonacci(n - 2);  // Two recursive calls
   }

   // Generating all subsets of a set
   void generateSubsets(int arr[], int n, int index, vector<int>& current) {
       if (index == n) {
           // print current subset
           return;
       }
       // Exclude current element
       generateSubsets(arr, n, index + 1, current);
       // Include current element
       current.push_back(arr[index]);
       generateSubsets(arr, n, index + 1, current);
       current.pop_back();
   }

------------------------------------------------------------------------------

8. O(n!) - Factorial Time
   - All permutations of input
   - Example: Generating all permutations, brute force TSP

   void permutations(string str, int left, int right) {
       if (left == right) {
           cout << str << endl;
           return;
       }
       for (int i = left; i <= right; i++) {
           swap(str[left], str[i]);
           permutations(str, left + 1, right);
           swap(str[left], str[i]);  // backtrack
       }
   }

------------------------------------------------------------------------------
                           SPACE COMPLEXITY
------------------------------------------------------------------------------

1. O(1) - Constant Space
   - Fixed amount of memory regardless of input
   - Example: Iterative algorithms with fixed variables

   int sum(int arr[], int n) {
       int total = 0;  // Only one variable
       for (int i = 0; i < n; i++) {
           total += arr[i];
       }
       return total;
   }

------------------------------------------------------------------------------

2. O(log n) - Logarithmic Space
   - Usually from recursive call stack in divide & conquer
   - Example: Binary search (recursive), balanced tree traversal

   int binarySearchRecursive(int arr[], int left, int right, int target) {
       if (left > right) return -1;
       int mid = left + (right - left) / 2;
       if (arr[mid] == target) return mid;
       if (arr[mid] < target)
           return binarySearchRecursive(arr, mid + 1, right, target);
       return binarySearchRecursive(arr, left, mid - 1, target);
   }
   // Call stack depth = O(log n)

------------------------------------------------------------------------------

3. O(n) - Linear Space
   - Memory grows proportionally with input
   - Example: Storing copy of array, recursive DFS, hash table

   int* copyArray(int arr[], int n) {
       int* copy = new int[n];  // O(n) space
       for (int i = 0; i < n; i++) {
           copy[i] = arr[i];
       }
       return copy;
   }

   // Recursive factorial - O(n) call stack
   int factorial(int n) {
       if (n <= 1) return 1;
       return n * factorial(n - 1);
   }

------------------------------------------------------------------------------

4. O(n^2) - Quadratic Space
   - 2D data structures
   - Example: Adjacency matrix, DP table for LCS

   int** create2DArray(int n) {
       int** matrix = new int*[n];
       for (int i = 0; i < n; i++) {
           matrix[i] = new int[n];  // n * n = O(n^2) space
       }
       return matrix;
   }

------------------------------------------------------------------------------

================================================================================
                    COMPLEXITY COMPARISON TABLE
================================================================================

    Input Size |  O(1)  | O(log n) |  O(n)  | O(n log n) |  O(n^2)  |  O(2^n)
   ------------|--------|----------|--------|------------|----------|----------
        10     |    1   |    3     |   10   |     33     |    100   |   1024
       100     |    1   |    7     |  100   |    664     |  10,000  |  1.27e30
      1000     |    1   |   10     | 1000   |   9,966    | 1,000,000| Overflow
     10000     |    1   |   13     |10000   |  132,877   | 100M     | Overflow

================================================================================
                    COMMON ALGORITHMS & THEIR COMPLEXITIES
================================================================================

    Algorithm              | Time (Best) | Time (Avg)  | Time (Worst) | Space
   ------------------------|-------------|-------------|--------------|-------
    Bubble Sort            |    O(n)     |   O(n^2)    |    O(n^2)    |  O(1)
    Selection Sort         |   O(n^2)    |   O(n^2)    |    O(n^2)    |  O(1)
    Insertion Sort         |    O(n)     |   O(n^2)    |    O(n^2)    |  O(1)
    Merge Sort             | O(n log n)  | O(n log n)  |  O(n log n)  |  O(n)
    Quick Sort             | O(n log n)  | O(n log n)  |    O(n^2)    |O(log n)
    Heap Sort              | O(n log n)  | O(n log n)  |  O(n log n)  |  O(1)
    Binary Search          |    O(1)     |  O(log n)   |   O(log n)   |  O(1)
    Linear Search          |    O(1)     |    O(n)     |     O(n)     |  O(1)
    Hash Table (Insert)    |    O(1)     |    O(1)     |     O(n)     |  O(n)
    BST (Search/Insert)    |  O(log n)   |  O(log n)   |     O(n)     |  O(n)
    DFS/BFS (Graph)        |  O(V + E)   |  O(V + E)   |   O(V + E)   |  O(V)

================================================================================
*/


*/

//Here 



