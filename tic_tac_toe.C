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

 int run(void);

 void check(void);
 int
 main(void) {
   int a = run();
 }
 int run(void) {
   char done;
   blue();
   printf("GAME OF TIC TAC TOE:\n");

   printf("PLAYER WILL BE PLAYING AGAINST COMPUTER...\n");

   done = ' ';

   Initializing();

   while (done == ' ') {

     Show_matrix();

     Playermove();

     done = Result(); /* see if winner */

     if (done != ' ')
       break; /* winner! */

     Computermove();

     done = Result(); /* see if winner */
   }
   system("clear");
   yellow();
   if (done == 'X')
     printf("You won!!!!\n");
   green();
   if (done == 'O') {
     printf("Computer won!!!!\n");
   }
   if (done == 'd') {
     printf("Draw!!!!\n");
   }
   reset();
   Show_matrix();
   /* show final positions */
   system("clear");
   check();
 }
 void check(void) {
   system("clear");
   yellow();
   printf("Do you want to start again?(y/n)");
   char chh;
   scanf(" %c", & chh);
   if (chh == 'y') {
     system("clear");
     run();
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

 /* Get a player's move. */

 void
 Playermove(void) {

   int x, y, z;
   green();
   printf("Enter X,Y coordinates for your move: ");
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

     Playermove();
   } else {
     matrix[x][y] = 'X';
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
