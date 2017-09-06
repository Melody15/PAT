#include <stdio.h>
#define N 10000

int main()
{ 
  int m, n;
  scanf("%d %d", &m, &n);
  int i, k, j = 1;
  int a[N+1];
  a[j] = 2;
  j++;
  for(i = 3; i < 107500; i++){
    for(k = 2; k < i; k++){
      if(i % k == 0){
        break;
      }
      if(k == i-1){
        a[j] = i;
        j++;
      }
    }
    if(j > n) break;
  }

  int count = 0;
 
  for(i = m; i < n; i++){
    if(count == 9){
      printf("%d\n", a[i]);
      count = 0;
      continue;
    }
    printf("%d ", a[i]);
    count++;
  }
  printf("%d", a[n]);
  return 0;
}
