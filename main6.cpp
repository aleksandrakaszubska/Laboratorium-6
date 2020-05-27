#define _CRT_SECURE_NO_WARNINGS 
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "gauss.h"

void HilbertMatrix(double N, double **H);
void displayMatrix(double N, double **H);
void computeVec(double N, double **H, double *b);
void plotVec(double N, double *v);


void main()
{
	double N=2;
	double **H;								//macierz Hilberta

	H=(double**)malloc(N*sizeof(double*));				//alokowanie tablicy H o wymiarze N*N
	for(int i = 0; i<N; i++)
	{
		H[i]=(double*)malloc(N*sizeof(double));
	}

	double *b=(double*)malloc(N*sizeof(double));
	double *x=(double*)malloc(N*sizeof(double));

	HilbertMatrix(N,H);
	displayMatrix(N,H);
	computeVec(N,H,b);
	plotVec(N,b);
	gauss(N,H,x,b);

	free(x);
	free(b);
}

void HilbertMatrix(double N, double **H)					// funkcja tworzy macierz H
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			H[i][j]=1/(1+(double)i+(double)j);
		}
	}
}

void displayMatrix(double N, double **H)				//funkcja drukuje macierz H na ekran
{

	printf("Macierz H: \n");
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			printf(" %10.2lf ", H[i][j]);
		}
		printf("\n");
	}
}


void computeVec(double N, double **H, double *b)				//funkcja oblicza wektor prawych stron b
{
	double praw_str;
	for(int i=0; i<N; i++)
	{
		praw_str=0;
		for(int j=0; j<N; j++)
		{
			praw_str+=H[i][j];
	}
	
	b[i]=praw_str;
	}

}


void plotVec(double N, double *v)					//funkcja wyswietla wektor prawych stron
{
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			printf(" %10.2lf ", v);
		}
		printf("\n");
	}

}


