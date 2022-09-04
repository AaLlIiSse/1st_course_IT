#include <stdio.h>
#include <stdlib.h>

struct matrix{
  int V[100];
  int N, M;
  int not0_el;
};
typedef struct matrix Matrix;
typedef struct max_and_col{
  int max;
  int col;
}mal;

void menu(){
  puts("1. Read matrices A.");
  puts("2. Print matrices A.");
  puts("3. Task.");
  puts("4. Print Task.");
  puts("5. Quit.");
}
Matrix read(FILE *in){
  Matrix ans;
  int index=0, a;
	ans.not0_el=0;
	ans.V[index]=0;
	fscanf(in, "%dx%d\n", &ans.N, &ans.M);
	for (int i = 1; i <= ans.N; i++) {
		index+=1;
		ans.V[index]=i;
		for (int j = 1; j <= ans.M; j++) {
			fscanf(in, "%d", &a);
			if (a!=0) {
				index+=1;
				ans.V[index]=j;
				index+=1;
				ans.V[index]=a;
				ans.not0_el+=1;
			}
		}
		fscanf(in, "\n");
		index+=1;
		ans.V[index]=0;
	}
	index+=1;
	ans.V[index]=0;
	return ans;
}

void print(Matrix a){
  //c - collomn
	int index=1;
	for (int c=2;c<2*(a.N+a.not0_el+1);c+=2){
		if (a.V[c]==0){
			index=1;
			for(int j=a.V[c-2];j<a.M;j++){
				printf("%5d",0);
			}
			printf("\n");
		} else {
			for(int j=index;j<a.V[c];j++){
				printf("%5d",0);
				index=a.V[c];
			}
			printf("%5d",a.V[c+1]);
			index+=1;
		}
	}
}

void print_v(Matrix a){
  for (int i=0; i < 2*(a.N + a.not0_el + 1); i++){
    printf("%d ", a.V[i]);
  }
}

mal col_max_el(Matrix a){
  mal m;
  int max=0;
  int collomn, sign = 1;
  for (int c=2;c<2*(a.N+a.not0_el+1);c+=2){
    if ((a.V[c]!=0)&&(abs(a.V[c+1]) > max)){
      max = abs(a.V[c+1]);
      if (a.V[c+1] < 0){
        sign = -1;
      }
      collomn = a.V[c];
    }
  }
  m.max = max*sign;
  m.col = collomn;
  return m;
}

Matrix task(Matrix a, int max_col, int max){
  for (int c=2;c<2*(a.N+a.not0_el+1);c+=2){
    if ((a.V[c]==max_col)&&(a.V[c]!=0)){
      a.V[c+1]=a.V[c+1]/max;
    }
  }
  return a;
}


int main(){
  Matrix A;
  int a, g = 1;
  FILE *finput = fopen("exemple7.txt", "r");
  if (!finput){
    perror("Can't open file");
    return 1;
  }
  A = read(finput);
  mal m = col_max_el(A);
  int max = m.max;
  int col = m.col;
  menu();
/*  print(A);
  printf("%d\n", max );
  A = task(A, col, max);
  print(A);*/
   while(g){
        printf("Enter what do you want ");
        scanf("%d", &a);
        switch(a) {
            case 1:{
                printf("The matrices were successfully read\n");
                break;
              }
            case 2: {
            	printf("Matrix A:\n");
          		print(A);
          		printf("Inner data of matrix: ");
          	  print_v(A);
          		printf("\n");
                break;
              }
            case 3: {
              task(A, col, max);
              printf("Task successfully done\n");
              break;
            }
            case 4: {
              A = task(A, col, max);
              print(A);
              break;
            }
            case 5:{
              printf("The program is closed\n");
              return 0;
              break;
            case 6:
            g = 0;
            break;
          }
        }
     }
   }
