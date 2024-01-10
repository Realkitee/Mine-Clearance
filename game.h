#define _CRT_SECURE_NO_WARNINGS 1	

#define ROW 10
#define COL 10  // Ϊ�˱�֤���̵Ĺ����ԣ�ROW��COL��ֵ����ӦС��100

#define ROWS ROW+2
#define COLS COL+2

#define MINE_COUNT 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ��ʼ�����̵ĺ�������
void InitializeBoard(char real_board[ROWS][COLS], char show_board[ROWS][COLS]);
// ��ӡ���̵ĺ�������
void PrintBoard(char real_board[ROWS][COLS], char show_board[ROWS][COLS]);
// ɨ�׵ĺ�������
int ClearMine(char real_board[ROWS][COLS], char show_board[ROWS][COLS]);
// ɨ��ʱɨ����λ�ü��ܱ�λ�ö�����ʱ�ĵݹ麯��������
void Recursion(char real_board[ROWS][COLS], char show_board[ROWS][COLS], int row_point, int col_point);
// ����Ƿ�����������Ӯ�˵ĺ�������
int IsWin(char show_board[ROWS][COLS]);
