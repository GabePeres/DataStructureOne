/* strtok example */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
  char str[] ="{85,Wolverine,m,135,88,1.63,(99)99999-9999}";
  char * pch;
  //printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str,",{}");
  printf ("fora 2: %d\n",atoi(pch));
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, ",{}");
  }
  return 0;
}
