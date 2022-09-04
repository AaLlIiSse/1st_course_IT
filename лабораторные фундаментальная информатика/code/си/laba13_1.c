#include <stdio.h>
#include <ctype.h>

int rubbish(int c)
{
 return c == ' ' || c == '\t' || c == ',' || c == '\n';
}

unsigned int char_to_set(char c){
  c = tolower(c);
  if(c < 'a' || c > 'z'){
    return 0;
  } else {
    return 1u<<(c-'a');
  }
}
// weerd
void main(){
  int c; int check = 0;
  unsigned int letter_set = 0;
  while ((c = getchar()) !=EOF){
    c=tolower(c);
    if(!(rubbish(c))){
      letter_set = letter_set | char_to_set(c);
      if ((letter_set & 1u<<(c -'a')) == 1){
        check = 1;
      } else {
        check = 0;
      }
    }
  }
  if (check == 0){
    printf("Нет повторяющихся букв");
  } else {
    printf("Есть повторяющиеся буквы");
  }
}
