/*
given a sorted array of integers arr and an integer target, find the index of the first and the last position of target in arr.
if target cannot be found in arr, return [-1,-1]
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int find_start(int *arr, int size, int target);
int find_end(int *arr, int size, int target);
int* find_first_n_last(int *arr, int size, int target);

int main(void){
  int *result = malloc(sizeof(int) * 2);
  fprintf(stdout, "array: ");
  int arr[SIZE] = {1, 3, 5, 5, 5, 5, 5, 5, 8, 9};
  for(int i=0; i<SIZE; i++){
    fprintf(stdout, "%d ", arr[i]);
  }
  fputc('\n', stdout);
  fprintf(stdout, "result: ");
  result = find_first_n_last(arr, SIZE, 5);
  for(int i=0; i<2; i++){
    fprintf(stdout, "%d ", result[i]);
  }
  fputc('\n', stdout);
  free(result);
  return 0;
}

int find_start(int *arr, int size, int target){
  if(arr[0]==target) return 0;
  int left = 0, right = size-1;
  while(left <= right){
    int mid = (left+right)/2;
    if(arr[mid]==target && arr[mid-1]<target) return mid;
    else if(arr[mid]<target) left = mid+1;
    else right = mid-1;
  }
  return -1;
}

int find_end(int *arr, int size, int target){
  if(arr[size-1]==target) return size-1;
  int left=0, right=size-1;
  while(left <= right){
    int mid = (left+right)/2;
    if(arr[mid]==target && arr[mid+1]>target) return mid;
    else if(arr[mid]>target) right = mid-1;
    else left = mid+1;
  }
  return -1;
}

int* find_first_n_last(int *arr, int size, int target){
  int *result = malloc(sizeof(int) * 2);
  if(size < 1 || target < arr[0] || target > arr[size-1]){
    result[0] = -1;
    result[1] = -1;
    return result;
  }
  int start = find_start(arr, size, target);
  int end = find_end(arr, size, target);
  result[0] = start;
  result[1] = end;
  return result;
  free(result);
}
