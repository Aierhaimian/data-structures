#include <stdio.h>
#include <sys/time.h>

int sum1(int N)
{
    int Sum = 0;
    for(int i=0; i<N; i++)
        Sum++;
    return Sum;
}

int sum2(int N)
{
    int Sum = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            Sum++;
    return Sum;
}

int sum3(int N)
{
    int Sum = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<N*N; j++)
            Sum++;
    return Sum;
}

int sum4(int N)
{
    int Sum = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<i; j++)
            Sum++;
    return Sum;
}

int sum5(int N)
{
    int Sum = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<i*i; j++)
            for(int k=0; k<j; k++)
                Sum++;
    return Sum;
}

int sum6(int N)
{
    int Sum = 0;
    for(int i=0; i<N; i++)
        for(int j=1; j<i*i; j++)
            if(j%i == 0)
                for(int k=0; k<j; k++)
                    Sum++;
    return Sum;
}

int main(int argc, char **argv)
{
    int N;
    int Sum1, Sum2, Sum3, Sum4, Sum5, Sum6;
    struct timeval start;
    struct timeval t1, t2, t3, t4, t5;
    struct timeval end;
    
    printf("Please input Number scale:\n");
    scanf("%d", &N);

    gettimeofday(&start, NULL);
    Sum1 = sum1(N);
    gettimeofday(&t1, NULL);
    Sum2 = sum2(N);
    gettimeofday(&t2, NULL);
    Sum3 = sum3(N);
    gettimeofday(&t3, NULL);
    Sum4 = sum4(N);
    gettimeofday(&t4, NULL);
    Sum5 = sum5(N);
    gettimeofday(&t5, NULL);
    Sum6 = sum6(N);
    gettimeofday(&end, NULL);

    unsigned long timer1, timer2, timer3, timer4, timer5, timer6;

    timer1 = 1000000 * (t1.tv_sec - start.tv_sec) + t1.tv_usec - start.tv_usec;
    timer2 = 1000000 * (t2.tv_sec - t1.tv_sec) + t2.tv_usec - t1.tv_usec;
    timer3 = 1000000 * (t3.tv_sec - t2.tv_sec) + t3.tv_usec - t2.tv_usec;
    timer4 = 1000000 * (t4.tv_sec - t3.tv_sec) + t4.tv_usec - t3.tv_usec;
    timer5 = 1000000 * (t5.tv_sec - t4.tv_sec) + t5.tv_usec - t4.tv_usec;
    timer6 = 1000000 * (end.tv_sec - t5.tv_sec) + end.tv_usec - t5.tv_usec;

    printf("Sum1 = %d, time1= %ld\n", Sum1, timer1);
    printf("Sum2 = %d, time2= %ld\n", Sum2, timer2);
    printf("Sum3 = %d, time3= %ld\n", Sum3, timer3);
    printf("Sum4 = %d, time4= %ld\n", Sum4, timer4);
    printf("Sum5 = %d, time5= %ld\n", Sum5, timer5);
    printf("Sum6 = %d, time6= %ld\n", Sum6, timer6);

    return 0;
}
