#include <stdio.h>
#include <math.h>
void swap(int *a, int *b){
  int c = *a;
  *a = *b;
  *b = c;
}
void vs(int*a, int m){
  for (int i = 1; i < m; i++){
    int t = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > t){
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = t;
  }
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
int w(int *a, int p, int k){
  int i, c = 0;
  for(i = 0; i < k; i++){
    if(a[i] == p){
      c = i;
      break;
    }
  }
  return c;
}
void introsort(int *a, int l, int beg, int e){
  int k = e - beg + 1;
  if(k <= 16) vs(a, k);
  if(l == 0) heap(a, k);
  else{
    quick(a, 0, k - 1);
    int p = a[(beg + e) / 2];
    int g = w(a, p, k);
    introsort(a, l - 1, 0, g - 1);
    introsort(a, l - 1, g + 1, k);
  }
}
void intro(int *a, int k){
  int limit = log(k) * 2;
  introsort(a, limit, 0, k-1);
}
int main(void) {
  int n, k;
  scanf("%d", &n);
  int b[n];
  for(k = 0; k < n; k++) scanf("%d", &b[k]);
  intro(b, n);
  for(k = 0; k < n; k++) printf("%d ", b[k]);
  return 0;  return 0;
}