#include <stdio.h>
char c;
int k = 0;
int flag = 1;
int tk = 1;
int state = 1;
int k2 = 0;
void main(){
  FILE *fin;
  fin = fopen("test.txt", "r");
  while (k2 != 10) {
    c = getchar();
    switch (state) {
      case 1: if (c != '/'){
        state = 1;
      } else {
        state = 2;
      }
          break;
      case 2: if (c != '*'){
        state =1;
      } else {
        state = 3;
      }
          break;
      case 3: flag = 0;
        if ((c == ' ') || (c == '\n')){
        k+=1;
      } else if (c == '*'){
        state = 4;
      }
          break;
      case 4: if (c = '/') {
        state = 1;
      } else {
        state = 3;
      }
          break;
  }
}if (flag == 0) {
printf("слов%d", k+tk);
}if (flag == 1) {
printf("двустрочное комментирование не найдено\n");
}
}
