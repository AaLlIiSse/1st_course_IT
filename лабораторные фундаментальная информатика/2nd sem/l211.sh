#!/bin/bash

flag=0
if [[ $# -lt 0 ]]; then
   echo "Need at least one argument: start directory"
   exit 1
fi
 if [[ "$1" = "-?" ]]; then 
 echo "The programm recursively go around directories and counts executable files in them. If you want set directory use parametr -dir. By default it is Download"
 flag=1
fi

if [ -n "$1" ] && [ "$1" == "-dir" ]; then 
  startdir="$2"
  else 
  startdir=~/Загрузки
  fi
  
if [[ ! -d "$startdir" ]]; then
   echo "'$startdir' is not directory"
  exit 2
fi

if [[ "$flag" -ne "1" ]]; then
 for i in $(find "$startdir" -type d); do
  echo "$i: ";
  (find "$i" -executable -type f | wc -l);
  echo "$(find "$i" -executable -type f)"
  printf "\n"
 done 
else 
exit 3
fi

exit 0
