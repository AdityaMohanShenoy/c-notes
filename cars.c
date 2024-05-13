#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *fp;
    char line[1000];
    char *token,*CARID,*BRAND,*MODEL;
    int count = 0;
    int n=0;


    fp = fopen("cars.csv","r");
    if (fp==NULL)
    {
        printf("ERROR WITH OPS");
      
    }

    while(fgets(line,1000,fp)!=NULL)
    {
        CARID=strtok(line,",");
        BRAND = strtok(NULL,",");
        MODEL = strtok(NULL,",");
        token = strtok(NULL,",");
        


        if (strcmp(token,"2020")==0)
        {
            count++;
            //printf("%d",count);
        }
    }
    printf("%d",count);

}