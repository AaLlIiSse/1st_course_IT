
/*#include <limits.h>
unsigned rev(unsigned n) {
  unsigned r = 0;
  for (int i = sizeof(n)*CHAR_BIT; n > 0 ; i--) {
    r *= 2;
    r += n % 2;
    n /= 2;
  }
  return r;
}
int main(void) {
  int n;
  scanf("%d", &n);
  printf("%d\n", rev(n));
  return 0;
}*/
#include <math.h>
#include <stdio.h>

void printgr1(int a)
{
char *g1[]={"nol","odin","dva","tri","chetire","pyat","shest","sem","vosem","devat"};
char *g2[]={"desyat","dvadzat","tridzat","sorok","pyatdisat","shizdisyat","semdesat","vosemdesat","devyanosto"};
char *g3[]={"sto","dveste","trista","chetiresta","pyatsot","shestsot","semsot","vosemsot","devyatsot"};
char *g4[]={"odinnadzat","dvenadzat","trinadzat","chetirnadzat","patnadzat","shestnadzat","semnadzat","vosemnadzat","devyatnadzat"};

int sotni1=a/100%10;
int desyatki1=a/10%10;
int edinici1=a/1%10;

if(sotni1)
printf("%s ",g3[sotni1-1]);
if(desyatki1)
printf("%s ",(desyatki1==1 && edinici1>0) ? g4[edinici1-1]:g2[desyatki1-1]);
if(edinici1)
printf("%s ",(desyatki1==1 && edinici1>0) ? "":g1[edinici1]);
}

int main(void)
{
  int n;
  scanf("%d",&n);
  // 12 345 678
  int n1=0;
  char *nm1[]={"edinic","tisyach","milionov"};
  int id1=0;
  while(n)
  {
    printgr1(n%1000);
    if(n%1000)
    printf("%s ",nm1[id1]);
    n/=1000;
    id1++;
  }
  system("pause");
  return 0;
}
