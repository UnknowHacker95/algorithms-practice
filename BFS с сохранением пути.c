#include <stdio.h> 
// n - кол-во вершин, s - начальная вершина, t - конечная
int main(){
  int n,s,f,i,j,ind,count,cur,x;
  scanf("%d", &n);
  int fire[n+1];
  int queue[n+1];
  int m[n+1];
  int p[n+1];
  int G[n+1][n+1];
  for (i = 1;i <= n; i++){
    for (j = 1;j <= n; j++){
      scanf("%d", &G[i][j]);
    }
  }
  for (i = 1; i <= n; i++){
    fire[i] = -1;
  }
  scanf("%d %d", &s, &f);
  count = 1;
  queue[count] = s;
  fire[s] = 0;
  m[s] = 0;
  ind = 1;
  cur = queue[ind];
  while((fire[f] == -1) && (ind <= count)){
    for (i = 1; i <= n; i++){
      if ((G[cur][i] == 1)&&(fire[i] == -1)){
        count = count + 1;
        queue[count] = i;
        fire[i] = fire[cur] + 1;
        m[i] = cur;
      }
    }
    ind = ind + 1;
    cur  = queue[ind];
  }
  if(fire[f] == -1){
    printf("Невозможно");
  } else if(fire[f] == 0){
    printf("Путь длины 0)");
  } else {
    printf("%d\n", fire[f]);
    p[1] = f;
    x = f;
    i = 2;
    while(m[x] != 0){
      x = m[x];
      p[i] = x;
      i = i + 1;
    }
    for(j = i; j >= 1; j--){
      if(p[j] != 0){
        printf("%d ", p[j]);
      }
    }
  }
  return 0;
}