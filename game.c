#define _CRT_SECURE_NO_WARNINGS 1	

#include "game.h"

// 初始化棋盘的函数
void InitializeBoard(char real_board[ROWS][COLS], char show_board[ROWS][COLS]) 
{
	srand((unsigned int)time(NULL));
	int i = 0;
	int j = 0;
	for (i = 0;i < ROWS;i++) 
	{
		for (j = 0;j < COLS;j++) 
		{
			real_board[i][j] = '0';//字符0表示无雷
		}
	}
	for (i = 0;i < ROWS;i++)
	{
		for (j = 0;j < COLS;j++)
		{
			show_board[i][j] = '0';// 先全部设为字符0。考虑后面的递归逻辑，不能全部设为字符*
		}
	}
	for (i = 1;i < ROWS - 1;i++)
	{
		for (j = 1;j < COLS - 1;j++)
		{
			show_board[i][j] = '*';// 再把显示的部分设为字符*
		}
	}
	//随机放雷
	int mine_count = MINE_COUNT;
	while (mine_count) 
	{
		int a = rand() % ROW + 1;
		int b = rand() % COL + 1;
		if (real_board[a][b] == '0') 
		{
			real_board[a][b] = '1';//字符1代表有雷
			mine_count --;
		}
	}
}

// 打印棋盘的函数
void PrintBoard(char real_board[ROWS][COLS], char show_board[ROWS][COLS]) 
{
	printf("\n--------- 雷区 ---------\n");
	int i = 0;
	int j = 0;
	for (i = 0;i < COLS - 1;i++) 
	{
		if (COL < 100)
		{
			if (i < 10)
				printf("0%d ", i);
			else
				printf("%d ", i);
		}
	}
	printf("\n");
	for (i = 1;i < ROWS-1;i++) 
	{
		if (ROW < 100) 
		{
			if (i < 10)
				printf("0%d ", i);
			else
				printf("%d ", i);
		}
		for (j = 1;j < COLS-1;j++) 
		{
			if (COL < 100)
				printf(" %c ", show_board[i][j]);
		}
		printf("\n");
	}
	printf("--------- 雷区 ---------\n\n");
}

// 扫雷的函数
int ClearMine(char real_board[ROWS][COLS], char show_board[ROWS][COLS]) 
{
	int row_point = 0;
	int col_point = 0;
	printf("请输入本次扫雷位置(如:4 6) >");	
	while (1) 
	{
		scanf("%d %d", &row_point, &col_point);
		if (row_point <= ROW && col_point <= COL && row_point >= 1 && col_point >= 1) 
			break;			
		else 
			printf("位置坐标输入错误,请重新输入 >");		
	}

	if (real_board[row_point][col_point] == '1') 
		return 0;
	else if (real_board[row_point][col_point] == '0') 
		Recursion(real_board, show_board, row_point, col_point);// 递归	

	return 1;
}

// 递归逻辑:如果point_mine_count≠0，则在该位置展示该位置周边雷数(这是终止条件);如果point_mine_count=0,则在该位置展示该位置周边雷数，即为0，且对周边的8个位置中还未展示周边雷数的位置继续进行这个递归逻辑(直接对周边的8个位置全部进行递归逻辑也合理，但是会导致栈溢出)
void Recursion(char real_board[ROWS][COLS], char show_board[ROWS][COLS], int row_point, int col_point)
{
	int i = 0;
	int j = 0;
	int point_mine_count = 0;
	for (i = -1;i <= 1;i++)
	{
		for (j = -1;j <= 1;j++)
		{
			if (real_board[row_point + i][col_point + j] == '1')
				point_mine_count++;
		}
	}
	if (point_mine_count == 0 && row_point <= ROW && col_point <= COL && row_point >= 1 && col_point >= 1)
	{
		show_board[row_point][col_point] = '0';
		for (i = -1;i <= 1;i++) 
		{
			for (j = -1;j <= 1;j++) 
			{
				if (i != 0 || j != 0) // 排除本位置，只对周边8个位置进行条件递归
				{
					if (show_board[row_point + i][col_point + j] == '*')
						Recursion(real_board, show_board, row_point + i, col_point + j);
				}		
			}
		}
	}
	else
	{
		show_board[row_point][col_point] = point_mine_count + '0';
	}
}

// 检查是否排完所有雷赢了的函数
int IsWin(char show_board[ROWS][COLS]) 
{
	int i = 0;
	int j = 0;
	int star_count = 0;
	for (i = 1;i < ROWS - 1;i++) 
	{
		for (j = 1;j < COLS - 1;j++) 
		{
			if (show_board[i][j] == '*')
				star_count++;
		}
	}
	if (star_count == MINE_COUNT)
		return 0;
	return 1;
}


