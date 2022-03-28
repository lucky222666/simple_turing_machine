#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define MAXN 100
#define MAX_LINE 1024
using namespace std;


typedef struct delta_5unit {
	char ori_state;
	char read;
	char write;
	char nxt_state;
	char move;

	delta_5unit(char a, char b, char c, char d, char e)
	{
		ori_state = a;
		read = b;
		write = c;
		nxt_state = d;
		move = e;
	}
}delta_5unit;

delta_5unit delta_list[21] = {
	delta_5unit('a','1','1','a','R'),
	delta_5unit('a','B','B','b','R'),
	delta_5unit('b','1','1','g','R'),
	delta_5unit('g','B','B','c','L'),
	delta_5unit('g','1','1','g','R'),
	delta_5unit('c','1','0','d','L'),
	delta_5unit('d','1','1','d','L'),
	delta_5unit('d','B','B','e','L'),
	delta_5unit('e','1','0','f','R'),
	delta_5unit('g','0','0','c','L'),
	delta_5unit('f','B','B','b','R'),
	delta_5unit('e','0','0','e','L'),
	delta_5unit('f','0','0','f','R'),
	delta_5unit('b','0','0','A','S'),
	delta_5unit('a','0','0','R','S'),
	delta_5unit('b','B','B','R','S'),
	delta_5unit('c','0','0','R','S'),
	delta_5unit('c','B','B','R','S'),
	delta_5unit('d','0','0','R','S'),
	delta_5unit('e','B','B','R','S'),
	delta_5unit('f','1','1','R','S')
};

int main()
{
	//read input file
	char buf[MAX_LINE];
	FILE *fp,*fp0;
	int len;

	
	if ((fp0 = fopen("seven_unit_sub.txt", "r")) == NULL)
	{
		perror("fail to read.");
		exit(1);
	}
	fclose(fp0);

	if ((fp = fopen("test_sub.txt", "r")) == NULL)
	{
		perror("fail to read.");
		exit(1);
	}
	while (fgets(buf, MAX_LINE, fp)&& strlen(buf)!=1)
	{
		len = strlen(buf);
		buf[len] = '\0';
		printf("The input line string is %s, and len=%d\n", buf, len);


		/*termination input:
		cout << "Please input a number with format B***B***B(* on behalf of 1): ";
		cin >> line;	
		*/
		char line[MAXN] = "B111111B11B";
		int k;
		for (k = 0; k < len; k++)
			line[k] = buf[k];
		line[k] = '\0';
		delta_5unit test('a', line[1], '\0', '\0', '\0');	 //initialize one delta_5unit
		int i = 1;
		while (test.ori_state != 'A' && test.ori_state != 'R')
		{
			if (test.ori_state == 'a')
			{
				switch (test.read)
				{
				case '0':
					test = delta_list[14];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				case '1':
					test = delta_list[0];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				case 'B':
					test = delta_list[1];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				}

			}
			else if (test.ori_state == 'b')
			{
				switch (test.read)
				{
				case '0':
					test = delta_list[13];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				case '1':
					test = delta_list[2];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				case 'B':
					test = delta_list[15];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				}
			}
			else if (test.ori_state == 'c')
			{
				switch (test.read)
				{
				case '0':
					test = delta_list[16];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				case '1':
					test = delta_list[5];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				case 'B':
					test = delta_list[17];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				}
			}
			else if (test.ori_state == 'd')
			{
				switch (test.read)
				{
				case '0':
					test = delta_list[18];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				case '1':
					test = delta_list[6];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				case 'B':
					test = delta_list[7];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				}
			}
			else if (test.ori_state == 'e')
			{
				switch (test.read)
				{
				case '0':
					test = delta_list[11];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				case '1':
					test = delta_list[8];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				case 'B':
					test = delta_list[19];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				}
			}
			else if (test.ori_state == 'f')
			{
				switch (test.read)
				{
				case '0':
					test = delta_list[12];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				case '1':
					test = delta_list[20];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				case 'B':
					test = delta_list[10];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				}
			}
			else
			{
				switch (test.read)
				{
				case '0':
					test = delta_list[9];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				case '1':
					test = delta_list[4];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				case 'B':
					test = delta_list[3];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				}
			}

			test = delta_5unit(test.nxt_state, line[i], '\0', '\0', '\0');
		}

		//print the result
		cout << "the result of subtraction is ";
		int j = 1;
		while (line[j] == '1')
		{
			cout << line[j];
			j++;
		}
		cout << endl << "The value of subtraction is " << j - 1 << endl;
		
		cout << endl;
	}
	fclose(fp);
	return 0;
}
