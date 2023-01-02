#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void uniform(char *str, int len)
{
	int i;
	FILE *fp;

	fp = fopen(str,"w");
	//Generate numbers
	for (i = 0; i < len; i++)
	{
		fprintf(fp,"%lf\n",(double)rand()/RAND_MAX);
	}
	fclose(fp);
}
void tri(char *str, int len)
{
	int i;

	//Uniform random numbers
	uniform("Uni1.dat", 1000000);
	uniform("Uni2.dat", 1000000);

	FILE *fp,*fp1,*fp2;
	double T,x,y;

fp = fopen("T.dat","w");
	fp1 = fopen("Uni1.dat","r");
	fp2 = fopen("Uni2.dat","r");

	//get numbers from file
	while((fscanf(fp1,"%lf",&x)!=EOF) && (fscanf(fp2,"%lf",&y)!=EOF))
         
	{
		i=i+1;

	//Addi numbers in files
		T=x+y;
		//fp=fopen("T.dat","w+");
		fprintf(fp,"%lf\n",T);
		//fclose(fp);
		//printf("x=%lf",x);
		
		//printf("y=%lf",y);
		//printf("T=%lf",T);
	}
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
//fp=fopen("T.dat","w");
//fclose(fp);

}
int  main(void) //main function begins
{	
//	double T;
	tri("T.dat",1000000);
//	printf("T.dat");
	return 0;
}

