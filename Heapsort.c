#include <stdio.h>
void swap(int *a, int *b){
  int c = *a;
  *a = *b;
  *b = c;
}
void down(int *a, int k, int j){
  int max = j, left = 2 * j + 1, right = 2 * j + 2;
  if(a[left] > a[max] && left < k) max = left;
  if(a[right] > a[max] && right < k) max = right;
  if(max != j){
    swap(&a[max], &a[j]);
    down(a, k, max);
  }
}
void heap(int *a, int m){
  int f;
  for(f = m/2 - 1; f >= 0; f--) down(a, m, f);
  for(f = m - 1; f >= 0; f--){
    swap(&a[0], &a[f]);
    down(a, f, 0);
  }
}
int main(void) {
  int n, k;
  scanf("%d", &n);
  int b[n];
  for(k = 0; k < n; k++) scanf("%d", &b[k]);
  heap(b, n);
  for(k = 0; k < n; k++) printf("%d ", b[k]);
  return 0;
}