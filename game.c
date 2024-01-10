#define _CRT_SECURE_NO_WARNINGS 1	

#include "game.h"

// ��ʼ�����̵ĺ���
void InitializeBoard(char real_board[ROWS][COLS], char show_board[ROWS][COLS]) 
{
	srand((unsigned int)time(NULL));
	int i = 0;
	int j = 0;
	for (i = 0;i < ROWS;i++) 
	{
		for (j = 0;j < COLS;j++) 
		{
			real_board[i][j] = '0';//�ַ�0��ʾ����
		}
	}
	for (i = 0;i < ROWS;i++)
	{
		for (j = 0;j < COLS;j++)
		{
			show_board[i][j] = '0';// ��ȫ����Ϊ�ַ�0�����Ǻ���ĵݹ��߼�������ȫ����Ϊ�ַ�*
		}
	}
	for (i = 1;i < ROWS - 1;i++)
	{
		for (j = 1;j < COLS - 1;j++)
		{
			show_board[i][j] = '*';// �ٰ���ʾ�Ĳ�����Ϊ�ַ�*
		}
	}
	//�������
	int mine_count = MINE_COUNT;
	while (mine_count) 
	{
		int a = rand() % ROW + 1;
		int b = rand() % COL + 1;
		if (real_board[a][b] == '0') 
		{
			real_board[a][b] = '1';//�ַ�1��������
			mine_count --;
		}
	}
}

// ��ӡ���̵ĺ���
void PrintBoard(char real_board[ROWS][COLS], char show_board[ROWS][COLS]) 
{
	printf("\n--------- ���� ---------\n");
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
	printf("--------- ���� ---------\n\n");
}

// ɨ�׵ĺ���
int ClearMine(char real_board[ROWS][COLS], char show_board[ROWS][COLS]) 
{
	int row_point = 0;
	int col_point = 0;
	printf("�����뱾��ɨ��λ��(��:4 6) >");	
	while (1) 
	{
		scanf("%d %d", &row_point, &col_point);
		if (row_point <= ROW && col_point <= COL && row_point >= 1 && col_point >= 1) 
			break;			
		else 
			printf("λ�������������,���������� >");		
	}

	if (real_board[row_point][col_point] == '1') 
		return 0;
	else if (real_board[row_point][col_point] == '0') 
		Recursion(real_board, show_board, row_point, col_point);// �ݹ�	

	return 1;
}

// �ݹ��߼�:���point_mine_count��0�����ڸ�λ��չʾ��λ���ܱ�����(������ֹ����);���point_mine_count=0,���ڸ�λ��չʾ��λ���ܱ���������Ϊ0���Ҷ��ܱߵ�8��λ���л�δչʾ�ܱ�������λ�ü�����������ݹ��߼�(ֱ�Ӷ��ܱߵ�8��λ��ȫ�����еݹ��߼�Ҳ�������ǻᵼ��ջ���)
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
				if (i != 0 || j != 0) // �ų���λ�ã�ֻ���ܱ�8��λ�ý��������ݹ�
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

// ����Ƿ�����������Ӯ�˵ĺ���
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


