#include "stdio.h"
#include "ctype.h"

void enterArray(int *a) {
  int i;
  for (i = 0; i < 9; i++) a[i] = 0;
}

void printArray(int *a) {
  int i, j, c = 0;
  for (i = 0; i < 3; i++) {
      printf("|");
    for (j = 0; j < 3; j++) {
      if(a[c] == 1) printf("X");
      else if(a[c] == 50) printf("O");
      else printf(" ");
      
      printf("|");
      c++;
    }
    
    printf("\n");
  }
}

int whowon(int sum) {
  if(sum == 3) return 1;
  if(sum == 150) return 2;
  return 0;
}

int checkWin(int *a) {
  int sumD = 0, sumV = 0, sumH = 0, sumOD = 0, i, j;
  int b[3][3], c = 0;
  
  for (i = 0; i < 3; i++) {
    for (j = 0;j < 3; j++) {
      b[i][j] = a[c];
      c++;
    }
  }

  for (i = 0; i < 3; i++) {
    for (j = 0;j < 3; j++) {
      sumV += b[j][i];
      sumH += b[i][j];
      if(whowon(sumV)) return whowon(sumV);
      if(whowon(sumH)) return whowon(sumH);
      if(j == i) sumD += b[i][j];
      if(i + j == 2) sumOD += b[i][j];
    }
    
    sumV = 0;
    sumH = 0;
  }

  if(whowon(sumD)) return whowon(sumD);
  if(whowon(sumOD)) return whowon(sumOD);

  return 0;
}

int main() {
  int a[9], win = 0, enter = 0;
  int z = 0;
  int c = 0;
  enterArray(a);
  printArray(a);

  while(!win) {
    while(!enter) {
      printf("player 1 pick a positon ");
      scanf("%d", &z);
      if(a[z-1] == 0) {
        a[z-1] = 1;
        printArray(a);
        c++;
        break;
      }
    }

    win = checkWin(a);
    if(win) break;
    if(c == 9) { 
      win=0;
      break; 
    }

    while(!enter) {
      printf("player 2 pick a positon ");
      scanf("%d",&z);
      if(a[z-1]==0){
        a[z-1]=50;
        printArray(a);
        c++;
        break;
      }
    }

    win = checkWin(a);
    if(win) break;
  }
  
  if(win!=0) printf("|| PLAYER %d WINS ||\n",win );
  else printf("No one wins\n");

  return 0;
}
