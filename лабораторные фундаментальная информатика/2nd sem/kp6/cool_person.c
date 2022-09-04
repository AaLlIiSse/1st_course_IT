#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "person.h"

void usage() {
    printf("Usage: program [-key] filename\nKeys: -f xor -p\n");
}

int one_five(int a, int b, int c, int d, int e){
  int n = 0;
  int arr[5] = {a, b, c, d, e};
  for (int i = 0; i == 4; i++){
    if (arr[i] == 5){
      n+=1;
    }
    if (n>1){
      return 0;
      break;
    }
  }
  return 1;
}



int main(int argc, char *argv[]) {
    FILE *in;
    int f = 0, p = 0;
    if (strcmp(argv[1],"-f")==0) {
      f=1;
      if (argc!=3) {
        usage();
        return 1;
      }
      in=fopen(argv[2],"r");
    }
    else if (strcmp(argv[1],"-p")==0) {
      t=1;
      if (argc!=5) {
        usage();
        return 1;
      }
      in=fopen(argv[2],"r");
    }
    else {
      usage();
      return 2;
    }

    person per;

    if (!in) {
        perror("Can not open file\n");
        return 3;
    }

    if (f==1) {
        printf("___________________________________________________________________________________\n");
        printf("|        SURNAME          | I |   S   |   G  |              MARKS                 |\n");
        printf("___________________________________________________________________________________\n");
    }

    while (fread(&per, sizeof(per), 1, in) == 1) {
        if (f==1) {
            printf("|%15s  |%3s  |%5s  |%7d  |%5d  |%5d  |%5d  |%5d  |%5d |\n", per.surname, per.initials, per.sex, per.group,
                   per.dm, per.ma, per.la, per.inf, per.soc);
            printf("___________________________________________________________________________________\n");
        }
    }

    if (f==1) {
        return 0;
    }

    printf("\t\t\t\t\tANSWER\n");
    printf("___________________________________________________________________________________\n");
    printf("|        SURNAME          | I |   N   |   W   |        TO        | TIME | TR | CH |\n");
    printf("___________________________________________________________________________________\n");
    while (fread(&per, sizeof(per), 1, in) == 1) {
        if (per.sex == "F" && one_five(per.dm, per.ma, per.la, per.inf, per.soc) == 1) {
            printf("|%15s  |%3s  |%5s  |%7d  |%5d  |%5d  |%5d  |%5d  |%5d |\n", per.surname, per.initials, per.sex, per.group,
                 per.dm, per.ma, per.la, per.inf, per.soc);
            printf("___________________________________________________________________________________\n");
        }
    }
    return 0;
}
