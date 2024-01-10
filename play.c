#define _CRT_SECURE_NO_WARNINGS 1	

#include "game.h"

void GameMenu() 
{
	printf("------------------------\n");
	printf("---------0.Exit---------\n");
	printf("---------1.Play---------\n");
	printf("------------------------\n");
	printf("请选择(0/1) >");
}


int main() 
{
	int input = 0;
	int ret1 = 1;// 1表示未踩到雷，0表示踩到雷了
	int ret2 = 1;// 1表示还未排完所有雷，未赢；0表示排完了所有雷，赢了
	int i = 0;
	int j = 0;
	char real_board[ROWS][COLS] = { 0 };
	char show_board[ROWS][COLS] = { 0 };
	do 
	{
		GameMenu();
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			input = 0;
			break;
		case 1:
			// 初始化棋盘
			InitializeBoard(real_board , show_board);
			// 打印棋盘
			PrintBoard(real_board, show_board);
			while (1) 
			{
				// 扫雷
				ret1 = ClearMine(real_board, show_board);
				if (ret1 == 0) // 踩到雷了，提前显示地雷裸露棋盘
				{
					for (i = 0;i < ROWS;i++) 
					{
						for (j = 0;j < COLS;j++) 
						{
							show_board[i][j] = real_board[i][j];
						}
					}
					// 打印棋盘
					PrintBoard(real_board, show_board);
					printf("踩到雷了，游戏失败\n");
					break;
				}
				ret2 = IsWin(show_board);
				if (ret2 == 0) 
				{
					// 打印棋盘
					PrintBoard(real_board, show_board);
					// 显示地雷裸露棋盘和游戏结束标志
					for (i = 0;i < ROWS;i++)
					{
						for (j = 0;j < COLS;j++)
						{
							show_board[i][j] = real_board[i][j];
						}
					}
					PrintBoard(real_board, show_board);
					printf("恭喜成功排查出全部地雷\n");
					break;
				}
				else 
				{
					// 打印棋盘
					PrintBoard(real_board, show_board);
				}
			}			
			break;
		default:
			printf("选择错误\n");
			break;
		}

	} while (input);
	return 0;
}