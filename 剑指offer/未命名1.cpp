#include<stdio.h>
#define fuck(x) (((x)+2)/3)

int main(){
 int l, r;
 while(~scanf("%d%d", &l, &r))
 printf("%d\n", r-l+1-fuck(r)+fuck(l-1));
 return 0;
}
