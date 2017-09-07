#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>


int main(int argc,char *argv[])
{
	FILE *fd;
	int buffer;
	int i;
	fd=fopen(argv[1],"r");

	int x=0;

	printf("#ifndef CONFIG_SPL_BUILD\n");

	printf("unsigned int const image1[] __attribute__((aligned(4)))= {\n");


		do{

			for(i=0;i<=2;i++)
			{
     				buffer=fgetc(fd);


      				x+=buffer<<(8*i);
			}

		printf("0x00%x,\n",x);

		
		x=0;
		}while(buffer!=EOF);
		printf("};\n");
		printf("#endif");
fclose(fd);
return 0;
}



