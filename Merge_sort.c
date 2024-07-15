#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
  int i,j;
  i=left;
  j=mid+1;
  int p=0;
  int b[(right-left)+1];
  while(i<=mid&&j<=right){
      if(arr[i]<arr[j]){
        b[p++]=arr[i];    
          i++;
      }
      else{
          b[p++]=arr[j];
          j++;
      }
  }
  while(i<=mid){
      b[p++]=arr[i];
      i++;
  }
  while(j<=right){
      b[p++]=arr[j];
      j++;
  }
  int k=0;
  for(int i=left;i<=right;i++){
      arr[i]=b[k];
      k++;
  }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, arrSize);

    mergeSort(arr, 0, arrSize - 1);

    printf("Sorted array: ");
    printArray(arr, arrSize);

    return 0;
}
