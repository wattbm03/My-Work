// Please add your name below
// Name: Breeanna Watters

// FILE: sort.cpp
// Implementation of sorting functions.

#include "sort.h"
#include <cstdlib>
using namespace std;

static void swap(string &s1, string &s2) {
  string temp;
  temp = s1;
  s1 = s2;
  s2 = temp;
}

//////////////// Bubble Sort ////////////////////////////
void bubblesort(string data[], size_t n) {
  size_t k = 0;
  bool switched = true;
  while (k < n - 1 && switched) {
    switched = false;
    k++;
    for (size_t i = 0; i < n - k; ++i) {
      if (data[i] > data[i + 1]) {
        swap(data[i], data[i + 1]);
        switched = true;
      }
    }
  }
}

//////////////// Selection Sort /////////////////////////
void selectionsort(string data[], size_t n) {
  // TO-DO: Add selection sort implementation
  string small;
  int i = 0;
  int j = 0;
  for (i = 0; i < n - 1; i++) {
    small = data[i]; // data for smallest value
    for (j = i + 1; j < n; j++) {
      if (data[j] <= data[i]) // compare strings to one another
        swap(data[i], data[j]);
    }
  }
}

//////////////// Insertion Sort /////////////////////////
void insertionsort(string data[], size_t n) {
  // TO-DO: Add insertion sort implementation
  string temp;
  int i, j;
  for (i = 1; i < n; i++) {
    temp = data[i]; // set low value into the temp spot
    j = i - 1;      // set j to have 1 less index that i
    while (
        data[j] >= temp &&
        j >=
            0) { // see if data at j index is bigger than the one at the i index
      data[j + 1] = data[j]; // takes i data and moves it to j
      j--;
    }
    data[j + 1] = temp; // makes swap from othe numbers/strings
  }
}

//////////////// Shell Sort ////////////////////////////
void shellsort(string data[], size_t n) {
  // TO-DO: Add shell sort implementation
  // ------
  // You can choose any valid K-sequence
  int k, i, j;
  for (k = n / 2; k > 0; k = k / 2) { // to set gap value up and decrease gap
                                      // value each time interated
    for (i = k; i < n; i++) {
      for (j = i - k; j >= 0; j = j - k) { // to detremine the lists
        if (data[j] <= data[j + k])        // to compare data in the small list
          break;                           // to end the cycle
        else
          swap(data[j], data[j + k]); // swap data to make it small to large
      }
    }
  }
}

////////////////// Quick Sort ///////////////////////////
static size_t partition(string data[], size_t n);

void quicksort(string data[], size_t n) {
  if (n > 1) {
    size_t pivot_index; // Array index for the pivot element
    size_t n1;          // Number of elements before the pivot element
    size_t n2;          // Number of elements after the pivot element

    // Partition the array, and set the pivot index
    pivot_index = partition(data, n);

    // Compute the sizes of the subarrays
    n1 = pivot_index + 1;
    n2 = n - n1;

    // Recursive calls to sort the subarrays
    quicksort(data, n1);
    quicksort((data + pivot_index + 1), n2);
  }
}

static size_t partition(string data[], size_t n)
// Postcondition: rearrange the data array and return position (j), such that
//   -- all elements stored in data[0] through data[j] are <= pivot;
//   -- all elements stored in data[j+1] through the end are >= pivot.
{
  // TO-DO: Add implementation of partition function in quick sort
  // ------
  // Please implement the Hoare partition scheme
  int low, high;
  low = 0; // set low value
  high = n - 1; // set high value

  string pivot = data[low]; // set pivot up
  int i = low - 1; // set shifter up for right
  int j = high + 1; // set shifter for left up

  while (true) {

    do {i++;}
      while (data[i] < pivot); // if right data is less than pivoit continue shifting i

    do {j--;} 
      while (data[j] > pivot); // if left data is bigger than pivot continue shifting j

    if (i >= j) // when i and j hit each other return the j value
      return j;

    swap(data[i], data[j]); // swap i and j when the first two while iner loops are met
  }
}

////////////////// (Top-Down) Merge Sort /////////////////
static void merge(string data[], size_t n1, size_t n2);

void mergesort(string data[], size_t n) {
  if (n > 1) {
    // Compute the sizes of the subarrays
    size_t n1 = n / 2;
    size_t n2 = n - n1;

    // Sort two subarrays
    mergesort(data, n1);
    mergesort(data + n1, n2);

    // Merge the two sorted halves
    merge(data, n1, n2);
  }
}

static void merge(string data[], size_t n1, size_t n2)
// Precondition: data is an array with n1+n2 elements, where
// the first n1 elements and the last n2 elements are sorted, respectively.
// Postcondition: The elements of data array have been rearranged so
// that data[0] <= data[1] <= ... <= data[n-1].
{
  // TO-DO: Add implementation of merge function
  int i, j, k;
  int l=0; // to set low
  int m=n1-1; // to set mid point
  string L[n1], R[n2]; // to add extra storage, because it is needed
  for(i = 0; i<n1; i++)
    L[i] = data[l+i]; // to store data in L
  for(j = 0; j<n2; j++)
    R[j] = data[m+1+j]; // to store higher values in R
  i = 0; 
  j = 0;
  k = l;
  while(i < n1 && j<n2) { //when both n1 and n2 are greater than i and j go on
    if(L[i] <= R[j]) {//if L is less than R store L back in data
         data[k] = L[i];
         i++; // contine on
      }
    else{
      data[k] = R[j]; // put R in Data of k
      j++;
      }
    k++; // now iterate data to next spot
   }
   while(i<n1) {   
      data[k] = L[i]; // when not equal iterate the L vales into data
      i++;
      k++;
   }
   while(j<n2) {     
      data[k] = R[j];//when not equal iterate the R vales into data
      j++; 
      k++;
   }
}