#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *fp;
    char line[1000];
    char *token;
    int count = 0;
    int n=0;

    fp = fopen("cars.csv","r");
    if (fp==NULL)
    {
        printf("ERROR WITH OPS");
      
    }

    while(fgets(line,sizeof(line),fp))
    {
        strtok(line,",");
        while(n <3)
        {
            token = strtok(NULL,",");//token will have year now 
            n++;
        }

        if (strcmp(token,"2020")==0)
        {
            count++;
            printf("%d",count);
        }
    }
    printf("%d",count);

}