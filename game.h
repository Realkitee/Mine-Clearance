#define _CRT_SECURE_NO_WARNINGS 1	

#define ROW 10
#define COL 10  // 为了保证棋盘的规整性，ROW和COL的值设置应小于100

#define ROWS ROW+2
#define COLS COL+2

#define MINE_COUNT 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 初始化棋盘的函数声明
void InitializeBoard(char real_board[ROWS][COLS], char show_board[ROWS][COLS]);
// 打印棋盘的函数声明
void PrintBoard(char real_board[ROWS][COLS], char show_board[ROWS][COLS]);
// 扫雷的函数声明
int ClearMine(char real_board[ROWS][COLS], char show_board[ROWS][COLS]);
// 扫雷时扫到本位置及周边位置都无雷时的递归函数的声明
void Recursion(char real_board[ROWS][COLS], char show_board[ROWS][COLS], int row_point, int col_point);
// 检查是否排完所有雷赢了的函数声明
int IsWin(char show_board[ROWS][COLS]);
