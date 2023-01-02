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

double mean(char *str)
{
int i=0,c;
FILE *fp;
double x, temp=0.0, mu=0.0;

fp = fopen(str,"r");
//get numbers from file
while(fscanf(fp,"%lf",&x)!=EOF)
{
//Count numbers in file
i=i+1;
//Add all numbers in file
temp = temp+x;
}
fclose(fp);
mu = temp/(i-1);
return mu;

}

double variance(char *str)
{
int i=0,c;
FILE *fp;
double x, temp=0.0,var=0.0,mu;

fp = fopen(str,"r");
//get numbers from file
while(fscanf(fp,"%lf",&x)!=EOF)
{
//Count numbers in file
i=i+1;
//Add all numbers in file
temp = temp+x*x;
}
fclose(fp);
//printf("u2=%lf ",temp);
temp = temp/(i-1);
var=temp-(mu*mu);
return var;

}


int  main(void) //main function begins
{
 
//Uniform random numbers
uniform("uni.dat", 1000000);

//Gaussian random numbers
//gaussian("gau.dat", 1000000);

//Mean of uniform
printf("%lf",mean("uni.dat"));
printf("%lf",variance("uni.dat"));
return 0;
}

