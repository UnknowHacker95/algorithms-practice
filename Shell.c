#include <stdio.h>
void swap(int *a, int *b){
  int c = *a;
  *a = *b;
  *b = c;
}
void shell(int * a, int s){
  int d, i, j;
  for(d = s / 2; d > 0; d = d / 2){
    for(i = d; i < s; i++){
      for(j = i - d; j >= 0; j = j - d){
        if(a[j] > a[j+d]){
          swap(&a[j],&a[j+d]);
        }
      }
    }
  }
}
int main(void) {
  int n, k;
  scanf("%d", &n);
  int b[n];
  for(k = 0; k < n; k++) scanf("%d", &b[k]);
  shell(b, n);
  for(k = 0; k < n; k++) printf("%d ", b[k]);
  return 0;
}