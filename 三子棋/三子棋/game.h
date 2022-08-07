#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3
//宏定义不用写 = ；

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu();

void InitBoard(char board[ROW][COL], int row, int col);

void PrintBoard(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL], int row, int col);

void ComputerMove(char board, int row, int col);

char IsWin(char board, int row, int col);

int IsFull(char board[ROW][COL], int row, int col);