#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void uniform(char *str, int len)
{
	int i;
	FILE *fp;
	fp = fopen(str,"w");
	for (i = 0; i < len; i++)
	{
	fprintf(fp,"%lf\n",(double)rand()/RAND_MAX);
	}
	fclose(fp);
}
void Vl(char *str, int len)
{
	uniform("un.dat", 1000000);
	int i;
	FILE *fp,*fp1;
	double x, V;
	double log10( double arg );
	fp = fopen("v.dat","w");
	fp1 = fopen("un.dat","r");
//	fp = fopen("v.dat","w");
	//fscanf(fp,"%lf",&x);
	while(fscanf(fp1,"%lf",&x)!=EOF)
	{
		i=i+1;
		V=-2*log(1-x);
		fprintf(fp,"%lf\n",V);
	}
	fclose(fp1);
	fclose(fp);
}
int  main(void)
{ 
//	double v;
	Vl("v.dat",1000000);
//	printf("%lf",v);
	return 0;
}
