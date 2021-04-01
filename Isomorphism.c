/* Practical - 2
Def: Check if two given graphs are Isomorphic or not!
*/

#include <stdio.h>
#include <stdlib.h>
#define max 100


void display(int[max][max], int *);
int checkdegree(int[max][max], int *, int[max]);
void sort(int[max], int *);
int isomorphic(int[max], int[max], int *);

void main(void)
{
	int A[max][max], B[max][max], vertex, edgeA, edgeB, degA[max], degB[max], degreeA = 0, degreeB = 0, flag = 0;
	system("clear");
	printf("\n\tTwo graphs are Isomorphic if: both have same number of vertices, edges\n\t& same number of vertices having equal degree.\n\n");
	printf("\n\tEnter number of vertex of Graph A: ");
	scanf("%d", &vertex);
	flag = vertex;
	printf("\n\tEnter number of edges in Graph A: ");
	scanf("%d", &edgeA);
	int a, b;
	for (int i = 0; i < edgeA; i++)
	{
		printf("\n\tEnter the starting and ending vertex of edge %d ", (i + 1));
		scanf("%d %d", &a, &b);
		A[a - 1][b - 1] = 1;
		A[b - 1][a - 1] = 1;
	}

	vertex = 0;
	printf("\n\tEnter number of vertex of Graph B: ");
	scanf("%d", &vertex);

	printf("\n\tEnter number of edges in Graph B: ");
	scanf("%d", &edgeB);
	for (int i = 0; i < edgeB; i++)
	{
		printf("\n\tEnter the starting and ending vertex of edge %d :", (i + 1));
		scanf("%d %d", &a, &b);
		B[a - 1][b - 1] = 1;
		B[b - 1][a - 1] = 1;
	}

	printf("\n\tGenerated Random Simple graph A:\n");
	display(A, &flag);
	printf("\n\tGenerated Random Simple graph B:\n");
	display(B, &vertex);
	if (flag == vertex)
	{
		degreeA = checkdegree(A, &vertex, degA);
		degreeB = checkdegree(B, &vertex, degB);
		flag = 0;
		if (degreeA == degreeB)
		{
			sort(degA, &vertex);
			sort(degB, &vertex);

			printf("\n\tDegree sequence of Graph A is:\n");
			for (int i = 0; i < vertex; i++)
			{
				printf("%d ->", degA[i]);
			}

			printf("\n\tDegree sequence of Graph B is:\n");
			for (int i = 0; i < vertex; i++)
			{
				printf("%d ->", degB[i]);
			}

			flag = isomorphic(degA, degB, &vertex);
			if (flag == 1)
				printf("\n\tBoth graphs are Not Isomorphic beacuse the degree sequence of both the graph is not same!\n");
			else if (flag == 0)
				printf("\n\tBoth graphs are Isomorphic!\n");
		}
		else
			printf("\n\tBoth graphs are Not Isomorphic because the degree of both the graphs is different!\n");
	}
	else
		printf("\n\tBoth graphs are Not Isomorphic because the number of vertices are not same!\n");
}


void display(int A[max][max], int *vertex)
{
	int i = 0, j;
	for (; i < (*vertex); i++)
	{
		j = 0;
		for (; j < (*vertex); j++)
		{
			printf("  %d", A[i][j]);
		}
		printf("\n");
	}
	return;
}

int checkdegree(int A[max][max], int *vertex, int degA[max])
{
	int i = 0, j, degreeA, k = 0;
	for (; i < (*vertex); i++, k++)
	{
		j = 0, degreeA = 0;
		for (; j < (*vertex); j++)
		{
			if (A[i][j] == 1)
				degreeA++;
		}
		degA[k] = degreeA;
	}
	degreeA = 0;
	for (k = 0; k < (*vertex); k++)
	{
		degreeA = (degreeA + degA[k]);
	}
	return (degreeA);
}

void sort(int degA[max], int *vertex)
{
	int i = 0, j, temp = 0;
	for (; i < (*vertex); i++)
	{
		j = 0;
		for (; j < (*vertex) - i - 1; j++)
		{
			if (degA[j] > degA[j + 1])
			{
				temp = degA[j];
				degA[j] = degA[j + 1];
				degA[j + 1] = temp;
			}
		}
	}
	return;
}

int isomorphic(int degA[max], int degB[max], int *vertex)
{
	int flag = 0, i = 0, j = 0;
	for (; i < (*vertex); i++, j++)
	{
		if (degA[i] != degB[j])
		{
			flag = 1;
			break;
		}
	}
	return (flag);
}
