#include <iostream>
#include <vector>

using namespace std;

void merge(int arr[], int l, int mid, int r){
  int i = l;
  int j = mid+1;
  int k = l;
  int temp[r+1];
  while(i<=mid && j<=r) {
    if(arr[i] < arr[j]){
      temp[k] = arr[i];
      i++;
    } else{
      temp[k] = arr[j];
      j++;
    }
    k++;
  } 
  while(i<=mid) {
    temp[k] = arr[i];
    i++;
    k++;
  }
  while(j<=r) {
    temp[k] = arr[j];
    j++;
    k++;
  }

  for(int s=l;s<=r;s++){
    arr[s] = temp[s];
  }
}


void mergeSort(int arr[], int l, int r) {
  if(l<r){
    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr,l,mid,r);
  }
}

void performMergeSort() {
  int n;
  cout << " Welcome to my merge sort programm" << endl << endl;
  cout << "Enter length of array : ";
  cin >> n;
  cout << endl;
  int arr[n];
  for(int i=0; i<n; i++) {
    cout << "Enter element at index " << i << " : ";
    cin  >> arr[i] ;
    cout << endl;
  }

  cout << "* Before Merge Sort :-" << endl<< endl;
  for(int x : arr) {
    cout << x << " ";
  }
  mergeSort(arr,0,n-1);
  cout << endl << endl;
  cout << "* After Merge Sort :-" << endl<< endl;
  for(int x : arr) {
    cout << x << " ";
  }
  cout <<endl;
}



int performSelectionSort() {
  vector<int> A = {10,9,10000,7,6,5,4,3,2,1,0};
  int i = 0,j,min_index;
  while(i<A.size()-1) {
    j=i+1;
    min_index = i;
    while(j<A.size()){
      if(A[j] < A[min_index]){
        min_index = j;
      }
      j++;
    }
    swap(A[i],A[min_index]);
    i++;
  }
  for(int x : A){
    cout << x << endl;
  }
  return 0;
}

int main() {
  int res;
  cout << "What do you want to do ?" <<endl;
  cout << " 1 for Merge Sort "<<endl;
  cout << " 2 for Selection Sort "<<endl;
  cout << " 3 to exit  "<<endl;
  cin  >>res;

  switch (res) {
    case 1: {
      performMergeSort();
      break;
    }
    case 2:{
      performSelectionSort();
      break;
    }
    case 3:{
      break;
    }
    default:{
    cout << "Wrong input"<<endl << endl;
    main();
    }
  }
  return 0;
}