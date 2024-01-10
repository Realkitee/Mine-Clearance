#define _CRT_SECURE_NO_WARNINGS 1	

#include "game.h"

void GameMenu() 
{
	printf("------------------------\n");
	printf("---------0.Exit---------\n");
	printf("---------1.Play---------\n");
	printf("------------------------\n");
	printf("��ѡ��(0/1) >");
}


int main() 
{
	int input = 0;
	int ret1 = 1;// 1��ʾδ�ȵ��ף�0��ʾ�ȵ�����
	int ret2 = 1;// 1��ʾ��δ���������ף�δӮ��0��ʾ�����������ף�Ӯ��
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
			// ��ʼ������
			InitializeBoard(real_board , show_board);
			// ��ӡ����
			PrintBoard(real_board, show_board);
			while (1) 
			{
				// ɨ��
				ret1 = ClearMine(real_board, show_board);
				if (ret1 == 0) // �ȵ����ˣ���ǰ��ʾ������¶����
				{
					for (i = 0;i < ROWS;i++) 
					{
						for (j = 0;j < COLS;j++) 
						{
							show_board[i][j] = real_board[i][j];
						}
					}
					// ��ӡ����
					PrintBoard(real_board, show_board);
					printf("�ȵ����ˣ���Ϸʧ��\n");
					break;
				}
				ret2 = IsWin(show_board);
				if (ret2 == 0) 
				{
					// ��ӡ����
					PrintBoard(real_board, show_board);
					// ��ʾ������¶���̺���Ϸ������־
					for (i = 0;i < ROWS;i++)
					{
						for (j = 0;j < COLS;j++)
						{
							show_board[i][j] = real_board[i][j];
						}
					}
					PrintBoard(real_board, show_board);
					printf("��ϲ�ɹ��Ų��ȫ������\n");
					break;
				}
				else 
				{
					// ��ӡ����
					PrintBoard(real_board, show_board);
				}
			}			
			break;
		default:
			printf("ѡ�����\n");
			break;
		}

	} while (input);
	return 0;
}