#include <stdio.h>
#include <string.h>

void main()
{
int i;
char str[10], temp[10]="Computer";
for (i = 0; i < 4; i++)
{
gets(str);
if (strcmp(temp, str)<0) strcmp(temp, str);
}
puts(temp);
}
