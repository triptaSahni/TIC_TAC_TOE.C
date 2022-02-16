/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <stdio.h>

#include <stdlib.h>

#include <time.h>

void
green() {
        printf("\033[2;32m");
} // FOR GIVING COLOURING EFFECT TO CODE // 

void
blue() {
        printf("\033[2;34m");
}

void
yellow() {
        printf("\033[2;33m");
}

void
reset() {
        printf("\033[0m");
}

char matrix[3][3]; // DEFINING MATRIX //

char Result(void); // CHECKING IF SOMEONE WON OR LOOSE OR GAME IS DRAW //

void Initializing(void); // INITIALIZING VALUES TO THE MATRIX //

void Playermove(void); // INPUTS PLAYER MOVE //

void Computermove(void); // INPUTS COMPUTER MOVE //

void Show_matrix(void); // FOR DISPLAYING REFRESHED MATRIX AFTER EACH MOVE //

void runU(void);

void check(void);

void call(void);

void runC(void);
void score(int a,int b,char name1[],char name2[]);
void Playermove1(char name1[],char a);
char name11[20],name22[20];
 char chh;
void Playermove2(char name2[]);
int n1=0;int n2=0;char t1;int flag=0;
int main(void) {
   call();
   return 0;
}

void call(void){
   
    system("clear");
    yellow();
    printf("Do you want to play with another USER or COMPUTER?(u/c)");
    char take;
    scanf(" %c",&take);
    if(flag==1)
    {
        if(take=='c')
        {
          if(t1=='c')
          {
              runC();
          }
          else
          {
             n1=0;
             n2=0;
             runU();
          }
        }
        else
        {
          if(t1=='u')
          {
              runU();
          }
          else
          {
             n2=0;
             n1=0;
             runC();
          }  
        }
    }
    else
    {if(take=='c')
    {
        t1='c';
        runC();
    }
    else{
    t1='u';
        runU();
    }
        
    }
}
void runU(void){
    system("clear");
        char done;
        blue();
        printf("GAME OF TIC TAC TOE:\n");

        printf("PLAYER WILL BE PLAYING AGAINST USER...\n");
        
        printf("Enter first player name:");
        scanf("%s",name11);
     
        printf("Enter second player name:");
        scanf("%s",name22);
    
        done = ' ';

        Initializing();
        system("clear");
        
        while (done == ' ') {

                Show_matrix();
                
                Playermove1(name11,'X');

                done = Result(); /* see if winner */

                if (done != ' ')
                        break; /* winner! */
                Show_matrix();
                Playermove1(name22,'O');

                done = Result(); /* see if winner */
        }
        system("clear");
        yellow();
        if (done == 'X')
               { n1++;
                   printf("%s won!!!!\n",name11);
                   
               }
        green();
        if (done == 'O') {
              { n2++;
                  printf("%s won!!!!\n",name22);
                  
              }
        }
        if (done == 'd') {
                printf("Draw!!!!\n");
        }
        reset();
        Show_matrix();
        /* show final positions */
        
        score(n1,n2,name11,name22);
        check();
}

void runC(void) {
    system("clear");
        char done;
        //char name1[20];
        blue();
        printf("GAME OF TIC TAC TOE:\n");

        printf("PLAYER WILL BE PLAYING AGAINST COMPUTER...\n");
         printf("Enter Player name:");
        scanf("%s",name11);
        done = ' ';
char name33[9]={'C','O','M','P','U','T','E','R','\0'};
        Initializing();
        system("clear");
        yellow();
        printf("GAME CONTINUES:\n");
        while (done == ' ') {

                Show_matrix();

                Playermove1(name11,'X');

                done = Result(); /* see if winner */

                if (done != ' ')
                        break; /* winner! */

                Computermove();

                done = Result(); /* see if winner */
        }
        system("clear");
        yellow();
        if (done == 'X')
               {n1++; printf("You won!!!!\n");}
        green();
        if (done == 'O') {
            n2++;
                printf("Computer won!!!!\n");
        }
        if (done == 'd') {
                printf("Draw!!!!\n");
        }
        reset();
        Show_matrix();
        score(n1,n2,name11,"COMPUTER");
        /* show final positions */
        check();
}
 void score(int a,int b,char name1[],char name2[])
 { 
    
     reset();
   printf("                 SCORES\n");
   printf("                  %s %d",name1,a);
   printf(" %s %d\n",name2,b);
 }
void check(void) {
        yellow();
        printf("Do you want to start again?(y/n)");
       
        scanf(" %c", & chh);
        if (chh == 'y') {
            flag=1;
                system("clear");
                score(n1,n2,name11,name22);
                call();
        }
}
/* Initialize the matrix. */

void
Initializing(void) {

        int i, j;

        for (i = 0; i < 3; i++)

                for (j = 0; j < 3; j++)
                        matrix[i][j] = ' ';

}

//get player move
void
Playermove1(char name1[],char a) {

        int x, y, z;
        green();
        printf("Enter the cell in which you want to try your move %s: ",name1);
        scanf("%d", & z);
        system("clear");
        yellow();
        if (z == 1) {
                x = 0;
                y = 0;
        } else if (z == 2) {
                x = 0;
                y = 1;
        } else if (z == 3) {
                x = 0;
                y = 2;
        } else if (z == 4) {
                x = 1;
                y = 0;
        } else if (z == 5) {
                x = 1;
                y = 1;
        } else if (z == 6) {
                x = 1;
                y = 2;
        } else if (z == 7) {
                x = 2;
                y = 0;
        } else if (z == 8) {
                x = 2;
                y = 1;
        } else if (z == 9) {
                x = 2;
                y = 2;
        }
        printf("GAME CONTINUES:\n");
        if (matrix[x][y] != ' ') {
                Show_matrix();
                printf("Invalid move, try again.\n");

                Playermove1(name1,a);
        } else {
                matrix[x][y] = a;
        }
}

/* Get a move from the computer. */
int generate_random(int l, int r) { //this will generate random number in range l and r
        int i;
        int rand_num = (rand() % (r - l + 1)) + l;
        return (rand_num);
}

void
Computermove(void) {
        srand(time(0));
        int i, j;
        i = generate_random(0, 2);
        j = generate_random(0, 2);
        while (matrix[i][j] != ' ') {
                i = generate_random(0, 2);
                j = generate_random(0, 2);
        }

        matrix[i][j] = 'O';
}

/* Display the matrix on the screen. */

void
Show_matrix(void) {

        int t;
        for (t = 0; t < 3; t++) {
                green();
                printf("\t\t\t %c | %c | %c ", matrix[t][0], matrix[t][1],
                        matrix[t][2]);
                yellow();
                if (t != 2)
                        printf("\n\t\t\t---|---|---\n");
        }
        reset();
        printf("\n");
}

/* See if there is a winner. */

char
Result(void) {

        int i;

        for (i = 0; i < 3; i++) /* Result rows */

                if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
                        return matrix[i][0];

        for (i = 0; i < 3; i++) /* Result columns */

                if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
                        return matrix[0][i];

        /* test diagonals */

        if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])

                return matrix[0][0];

        if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])

                return matrix[0][2];
        //for draw
        int flag = 0;
        for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++) {
                        if (matrix[i][j] == ' ') {
                                flag = 1;
                        }
                }
        if (flag == 0) {
                return 'd';
        }
        return ' ';

}



