#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    FILE *fp;
    fp = fopen("input_number.txt", "r");
    if (fp == NULL)
    {
        printf("The input file could not opened.\n");
        printf("The program exit.\n");
        return -1;
    }

    int n, k_th;
    fscanf(fp,"%d", &n);
    fscanf(fp, "%d", &k_th);
    int array[k_th];
    int tmp, cnt = 0;

    struct timeval start;
    struct timeval end;
    unsigned long timer;
    gettimeofday(&start, NULL);
    while (fscanf(fp, "%d", &tmp) != EOF)
    {
        if (cnt < k_th && cnt != k_th-1)
        {
            array[cnt] = tmp;
            cnt++;
        }else if (cnt ==k_th-1)
        {
            array[cnt] = tmp;
            qsort(array, k_th, sizeof(int), cmpfunc);
            cnt++;
        }else
        {
            for (int i=k_th-1; i>=0; i--)
            {
                if (array[i] < tmp)
                {
                    for (int j = 0; j<i; j++)
                        array[j] = array[j+1];
                    array[i] = tmp;
                    break;
                }
            }
        }
    }
    gettimeofday(&end, NULL);

    fclose(fp);
    
    timer = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;

    printf("The k_th largest num is %d\n", array[0]);
    printf("timer=%ld us\n", timer);

    return 0;
}
