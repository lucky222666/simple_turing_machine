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

//construct the trasnformation table_list
delta_5unit delta_list_a[9] = {
	delta_5unit('x','a','B','y','R'),
	delta_5unit('y','a','a','y','R'),
	delta_5unit('y','b','b','y','R'),
	delta_5unit('y','c','c','y','R'),
	delta_5unit('y','B','B','z','R'),
	delta_5unit('z','B','a','A','S'),
	delta_5unit('z','a','a','z','R'),
	delta_5unit('z','b','b','z','R'),
	delta_5unit('z','c','c','z','R')
};
delta_5unit delta_list_b[9] = {
	delta_5unit('x','b','B','y','R'),
	delta_5unit('y','a','a','y','R'),
	delta_5unit('y','b','b','y','R'),
	delta_5unit('y','c','c','y','R'),
	delta_5unit('y','B','B','z','R'),
	delta_5unit('z','B','b','A','S'),
	delta_5unit('z','a','a','z','R'),
	delta_5unit('z','b','b','z','R'),
	delta_5unit('z','c','c','z','R')
};
delta_5unit delta_list_c[9] = {
	delta_5unit('x','c','B','y','R'),
	delta_5unit('y','a','a','y','R'),
	delta_5unit('y','b','b','y','R'),
	delta_5unit('y','c','c','y','R'),
	delta_5unit('y','B','B','z','R'),
	delta_5unit('z','B','c','A','S'),
	delta_5unit('z','a','a','z','R'),
	delta_5unit('z','b','b','z','R'),
	delta_5unit('z','c','c','z','R')
};

int main()
{
	//read input file
	char buf[MAX_LINE];
	FILE *fp,*fp0;
	int len;

	if ((fp0 = fopen("seven_unit_copy.txt", "r")) == NULL)
	{
		perror("fail to read.");
		exit(1);
	}
	fclose(fp0);

	if ((fp = fopen("test_copy.txt", "r")) == NULL)
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
		char line[MAXN] = { 'B' };
		int k;
		for (k = 0; k < len; k++)
			line[k] = buf[k];
		line[k] = '\0';

		delta_5unit test('x', line[1], '\0', '\0', '\0');	 //initialize one delta_5unit
		int i = 1;
		for (int j = 1; j <= (strlen(line) - 2) / 2; j++)
		{
			if (line[j] == 'a')						//judge the first letter i will meet
			{
				while (test.ori_state != 'A')		//this circulation is still on
				{
					if (test.ori_state == 'x')		//state comparision
					{
						switch (test.read)
						{
						case 'a':
							test = delta_list_a[0];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						default:
							break;
						}
					}
					else if (test.ori_state == 'y')
					{
						switch (test.read)
						{
						case 'a':
							test = delta_list_a[1];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						case 'b':
							test = delta_list_a[2];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						case 'c':
							test = delta_list_a[3];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						case 'B':
							test = delta_list_a[4];
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
						case 'a':
							test = delta_list_a[6];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						case 'b':
							test = delta_list_a[7];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						case 'c':
							test = delta_list_a[8];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						case 'B':
							test = delta_list_a[5];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;


						}
					}

					test = delta_5unit(test.nxt_state, line[i], '\0', '\0', '\0');
				}
			}
			else if (line[j] == 'b')				//the first meeting  letter is b
			{
				while (test.ori_state != 'A')
				{
					if (test.ori_state == 'x')
					{
						switch (test.read)
						{
						case 'b':
							test = delta_list_b[0];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						default:
							break;
						}
					}
					else if (test.ori_state == 'y')
					{
						switch (test.read)
						{
						case 'a':
							test = delta_list_b[1];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						case 'b':
							test = delta_list_b[2];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						case 'c':
							test = delta_list_b[3];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						case 'B':
							test = delta_list_b[4];
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
						case 'a':
							test = delta_list_b[6];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						case 'b':
							test = delta_list_b[7];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						case 'c':
							test = delta_list_b[8];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						case 'B':
							test = delta_list_b[5];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;


						}
					}

					test = delta_5unit(test.nxt_state, line[i], '\0', '\0', '\0');
				}
			}
			else if (line[j] == 'c')					//the first meeting  letter is b
			{
				while (test.ori_state != 'A')
				{
					if (test.ori_state == 'x')
					{
						switch (test.read)
						{
						case 'c':
							test = delta_list_c[0];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						default:
							break;
						}
					}
					else if (test.ori_state == 'y')
					{
						switch (test.read)
						{
						case 'a':
							test = delta_list_c[1];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						case 'b':
							test = delta_list_c[2];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						case 'c':
							test = delta_list_c[3];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						case 'B':
							test = delta_list_c[4];
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
						case 'a':
							test = delta_list_c[6];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						case 'b':
							test = delta_list_c[7];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						case 'c':
							test = delta_list_c[8];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;
						case 'B':
							test = delta_list_c[5];
							line[i] = test.write;
							if (test.move == 'R')i++;
							else if (test.move == 'L')i--;
							break;


						}
					}

					test = delta_5unit(test.nxt_state, line[i], '\0', '\0', '\0');
				}
			}
			i = j + 1;

			test = delta_5unit('x', line[i], '\0', '\0', '\0');
		}

		//print  the result
		cout << "Now here is the result:";
		for (int j = 0; j < strlen(line); j++)
		{
			if (line[j] != 'B')
				cout << line[j];
		}
		cout << 'B';
		for (int j = 0; j < strlen(line); j++)
		{
			if (line[j] != 'B')
				cout << line[j];
		}
		
		cout << endl << endl;
	}
	fclose(fp);
	return 0;
}
