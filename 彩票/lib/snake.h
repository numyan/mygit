#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include <limits.h>


#define MOVEUP(x) printf("\033[%dA", (x)) 




static struct termios ori_attr,cur_attr;
static inline int tty_reset();
static inline int kbhit();
static inline int tty_set();
#define ROW_MAX 20
#define COL_MAX 50


#define SPEED_MAX 500
#define SPEED_MIN 125
#define SNAKELEN 3


#define SNAKE_HEAD '@'
#define SNAKE_BODY '#'
#define FOOD '$'




#define LEFT 'a'
#define RIGHT 'd'
#define UP 'w'
#define DOWN 's'


#define EAT_SPACE 1
#define EAT_FOOD 2
#define EAT_BODY 0


char dc = '0';
char bodyDc = '0';


  float speed = SPEED_MAX ;//ms
 int snake_length = 0;
 int grade  = 1;
 
 struct Location
 {
     int row;
     int col;
 };
 
 typedef struct ske
 {
     struct Location place;
     struct ske *next;
 }Snake;
 
 struct Location food;
 Snake *head = NULL;
 
 char str[ROW_MAX][COL_MAX];
 
void Init_str();
void Display();
void Init_food();
void Init_snake();
void Wait_game();


int Snake_move();
void moveToUp();
void moveToDown();
void moveToLeft();
void moveToRight();


void snakeShow();
void foodShow();
void reDisplay();
void GameOver();


void addBody(int,int);
void moveBody(int,int);
void Delay();


int isUpgrade();
int Upgrade();
void releaseSnake();
void PrintRule();

#endif