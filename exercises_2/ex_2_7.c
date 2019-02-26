#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void diffArray1(int array[], int n)
{
   for (int i=0; i<n; i++)
   {
       int tmp;
       while (1)
       {
           tmp = rand()%n;
           int j;
           for (j=0; j<i; j++)
           {
               if (tmp == array[j])
                   break;
           }
           if (j == i)
               break;
       }
       array[i] = tmp;
   }
}

void diffArray2(int array[], int isUsed[], int n)
{
    for (int i=0; i<n; i++)
    {
        while (1)
        {
            int tmp = rand()%n;
            if (isUsed[tmp] != 1)
            {
                isUsed[tmp] = 1;
                array[i] = tmp;
                break;
            }else
                continue;
        }
    }
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp; 
}

void diffArray3(int array[], int n)
{
    for (int i=0; i<n; i++)
        array[i] = i+1;
    for (int i=0; i<n; i++)
        swap(&array[i], &array[rand()%n]);
}

int main(int argc, char *argv[])
{
    int N;
    printf("Please input the array size N: ");
    scanf("%d", &N);
    printf("\n");

    int array1[N];
    int array2[N];
    int array3[N];
    int isUsed[640000] = {0};

    struct timeval t0;
    struct timeval t1;
    struct timeval t2;
    struct timeval t3;
    struct timeval t4;
    struct timeval t5;


    unsigned long time1, time2, time3;

    srand((unsigned)time(NULL));

    gettimeofday(&t0, NULL);
    diffArray1(array1, N);
    gettimeofday(&t1, NULL);

    time1 = 1000000*(t1.tv_sec - t0.tv_sec) + t1.tv_usec - t0.tv_usec;

    printf("time1= %ld us\n", time1);

//    for (int i=0; i<N; i++)
//        printf("%d ", array1[i]);
//    printf("\n");

    gettimeofday(&t2, NULL);
    diffArray2(array2, isUsed, N);
    gettimeofday(&t3, NULL);

    time2 = 1000000*(t3.tv_sec - t2.tv_sec) + t3.tv_usec - t2.tv_usec;

    printf("time2= %ld us\n", time2);

//    for (int i=0; i<N; i++)
//        printf("%d ", array2[i]);
//    printf("\n");

    gettimeofday(&t4, NULL);
    diffArray3(array3, N);
    gettimeofday(&t5, NULL);

    time3 = 1000000*(t5.tv_sec - t4.tv_sec) + t5.tv_usec - t4.tv_usec;

    printf("time3= %ld us\n", time3);

//    for (int i=0; i<N; i++)
//        printf("%d ", array3[i]);
//    printf("\n");

    return 0;
}
