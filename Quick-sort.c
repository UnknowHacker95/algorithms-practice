#include <stdio.h>
void swap(int *a, int *b){
  int c = *a;
  *a = *b;
  *b = c;
}
void quick(int * a, int fi, int en){
  //fi - первый элемент в подмассиве, en - последний
  int left = fi, right = en, p = a[(left + right) / 2];
  while(left <= right){
    while(a[left] < p) left ++;
    while(a[right] > p) right --;
    if(left <= right){
      swap(&a[left], &a[right]);
      left++;
      right--;
    }
  }
  if(fi < right) quick(a, fi, right);
  if(left < en) quick(a, left, en);
}
int main(void) {
  int n, k;
  scanf("%d", &n);
  int b[n];
  for(k = 0; k < n; k++) scanf("%d", &b[k]);
  quick(b, 0, n - 1);
  for(k = 0; k < n; k++) printf("%d ", b[k]);
  return 0;
}