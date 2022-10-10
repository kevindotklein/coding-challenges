#include <stdio.h>

void swap(int *a, int* b);
void quicksort(int *arr, int left, int right);
int kth_largest_element(int *arr, int size, int k);

int main(void){
  int arr[] = {4, 2, 9, 7, 5, 6, 7, 1, 3};
  int length = sizeof(arr) / sizeof(arr[0]);
  for(int i=0; i<length; i++){
    fprintf(stdout, "%d ", arr[i]);
  }
  fputc('\n', stdout);
  fprintf(stdout, "kth(4th) largest element: ");
  int result = kth_largest_element(arr, length, 4);
  fprintf(stdout, "%d", result);
  fputc('\n', stdout);
  return 0;
}

void swap(int *a, int* b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void quicksort(int *arr, int left, int right){
  int i=left, j=right, pivot=arr[(left+right)/2];
  while(i<=j){
    while(i<right && arr[i]<pivot){
      i++;
    }
    while(j>left && arr[j]>pivot){
      j--;
    }
    if(i<=j){
      swap(&arr[i], &arr[j]);
      i++;
      j--;
    }
  }
  if(j>left){
   quicksort(arr, left, j); 
  }
  if(i<right){
   quicksort(arr, i, right); 
  }
}

int kth_largest_element(int *arr, int size, int k){
  quicksort(arr, 0, size-1);
  return arr[size-k];
}
