#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

typedef unsigned set_data_elem;
enum {
    bits_per_char = 8,
    bits_per_elem = sizeof(set_data_elem) * bits_per_char,
    datalen = (1 << bits_per_char) / bits_per_elem
};

typedef struct {
    set_data_elem data[datalen];
 } set;

void set_clear(set *s) {
    memset(s->data, 0, sizeof(s->data));
}

void set_insert(set *s, int c) {
    s->data[c / bits_per_elem] |= 1u << (c % bits_per_elem);
}

int set_size(const set *s) {
    int i, size = 0;
    for(i = 0; i != 1 << bits_per_char; i++) {
        if(set_in(s, i)) {
            size++;
         }
    }
return size;
}

bool is_razd(char c) {
    if (c == ' ' | c == '\n' | c == EOF | c == ',') return true;
    else return false;
}
bool is_sogl(int c){
    switch (c) {
        case 'b':
        case 'c':
        case 'd':
        case 'f':
        case 'g':
        case 'h':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'v':
        case 'w':
        case 'x':
        case 'z':
            return true;
            break;
        default:
            return false;
            break;

 }
}

int main() {
    char c;
    int state = 1;
    int size;
    int k = 0;
    set num;
    set_clear(&num);
    while ((с = getchar())!=EOF) {
      switch (state){
        case 1: if (c != (is_sogl(c))){
          state = 1;
        } else {
          state = 2;
          break;
        }
        case 2: size = set_size(&num);
        set_insert(&num, tolower(c) - "a");
        if (is_sogl(c)){
          if (size != set_size(&num)){
          sost = 2;
        } else {
          sost = 3;
        }
      }
        else if (is_razd(c)){
          sost = 1;
          k+=1;
          set_clear(&num);
        } else if (!(is_sogl(c))){
            sost = 1;
          }
        break;
        case 3: if is_razd(c){
          sost = 1;
          set_clear(&num);
        } else {
          sost = 3;
        }
            break;
      }

    if (k != 0) printf("Есть слова со всеми разными согласными. Их: %d\n",k);
    if (k == 0) printf("Нет таких слов\n");
}
