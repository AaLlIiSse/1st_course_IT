#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "person.h"

void usage(){
    printf("Usage: program input_filename output_filename\n");
}

int readperson(FILE *in, person *p){
    return fscanf(in, "%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->surname, p->initials, p->sex, &p->group,
    &p->dm, &p->ma, &p->la, &p->inf, &p->soc) == 9;
}

int main(int argc, char* argv[]){
    if (argc != 3){
        usage();
        return 1;
    }
    person p;
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");

    if (!(out&&in)){
        perror("Can't open file");
        return 2;
    }
    while (readperson(in, &p)){
        fwrite(&p, sizeof(p), 1, out);
    }
    return 0;
}
