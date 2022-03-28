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

delta_5unit delta_list[12] = {
	delta_5unit('a','1','1','a','R'),
	delta_5unit('a','0','0','a','R'),
	delta_5unit('a','B','B','b','L'),
	delta_5unit('b','1','0','c','L'),
	delta_5unit('c','0','0','c','L'),
	delta_5unit('c','1','1','c','L'),
	delta_5unit('c','B','B','A','S'),
	delta_5unit('b','0','1','d','L'),
	delta_5unit('d','1','0','c','L'),
	delta_5unit('d','0','1','d','L'),
	delta_5unit('d','B','B','A','S'),
	delta_5unit('b','B','B','R','S')
};

int main()
{
	//read input file
	char buf[MAX_LINE];
	FILE *fp,*fp0;
	int len;


	if ((fp0 = fopen("seven_unit_minus.txt", "r")) == NULL)
	{
		perror("fail to read.");
		exit(1);
	}
	fclose(fp0);

	if ((fp = fopen("test_minus.txt", "r")) == NULL)
	{
		perror("fail to read.");
		exit(1);
	}
	while (fgets(buf, MAX_LINE, fp)&& strlen(buf)!=1)
	{
		len = strlen(buf);
		buf[len] = '\0';
		if(len==3) break;
		printf("The input binary number is %s, and len=%d\n", buf, len);

		/*termination input:
		cout << "Please input a number with format B***B***B(* on behalf of 1): ";
		cin >> line;	
		*/
		char line[MAXN] = "B10010B";
		int k;
		for (k = 0; k < len; k++)
			line[k] = buf[k];
		line[k] = '\0';

		delta_5unit test('a', line[1], '\0', '\0', '\0');		//initialize one delta_5unit
		int i = 1;
		while (test.ori_state != 'A' && test.ori_state != 'R')
		{
			if (test.ori_state == 'a')
			{
				switch (test.read)
				{
				case '0':
					test = delta_list[1];
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
					test = delta_list[2];
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
					test = delta_list[7];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				case '1':
					test = delta_list[3];
					line[i] = test.write;
					if (test.move == 'R')i++;
					else if (test.move == 'L')i--;
					break;
				case 'B':
					test = delta_list[11];
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
					test = delta_list[4];
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
					test = delta_list[6];
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
					test = delta_list[8];
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

			test = delta_5unit(test.nxt_state, line[i], '\0', '\0', '\0');
		}

		//print the result
		cout << "The input binary number minus one is: ";
		if (line[1] == '1')cout << line[1];
		for (int j = 2; j < strlen(line) - 1; j++)
			cout << line[j];
		cout << endl;

		cout << endl;
	}
	fclose(fp);
	return 0;
}
