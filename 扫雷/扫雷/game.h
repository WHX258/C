#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#define ROW 9
#define COL 9
//��˿���change the size of board
//row��col�Ķ���Ҫ��rowsǰ�棬����ʶ�𲻳���
#define ROWS COL + 2
#define COLS ROW + 2

#define EASY_COUNT 10

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void menu();

void Initial(char Board[ROWS][COLS],int rows,int cols,char first);

void Display(char Board[ROWS][COLS], int rows, int cols);

void setmine(char Board[ROWS][COLS], int row, int col);

int Findmine(char mineBoard[ROWS][COLS],char showBoard[ROWS][COLS], int row, int col);