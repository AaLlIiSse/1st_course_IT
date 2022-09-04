#ifndef _person_h_
#define _person_h_

typedef struct{
  int dm, ma, la, inf, soc;
} MARKS;

typedef struct {
  char surname[25];
    char initials[2];
    char sex[1];
    int group;
    MARKS marks;
} person;
#endif
