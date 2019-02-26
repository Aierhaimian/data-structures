#include <stdio.h>
#include <sys/time.h>

int swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int selection_kth_number(int array[], int n, int k)
{
  int i, j;
  for (i=0; i<n-1; i++) //外层循环控制趟数，总趟数为n-1
  {
    for(j=0; j<n-1-i; j++) //内层循环为当前第i趟所需的比较次数
    {
      if (array[j] < array[j+1])
        swap(&array[j], &array[j+1]);
    }
  }

  return array[k-1];

}



int main(int argc, char** argv) {
  FILE *fp;
  fp = fopen("input_number.txt", "r");
  if (fp == NULL)
  {
    printf("Can not open file and exit program.\n");
    return 0;
  }

  int n,k;
  fscanf(fp, "%d", &n);
  fscanf(fp, "%d", &k);
  int array[n];
  int i = 0;
  while (fscanf(fp, "%d", &array[i]) != EOF)
    i++;
  
  fclose(fp);

  struct timeval start;
  struct timeval end;

  unsigned long timer;

  int k_th = 0;
  gettimeofday(&start, NULL);
  k_th = selection_kth_number(array, n, k);
  gettimeofday(&end, NULL);

  timer = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;

  printf("The kth largest number is %d\n", k_th);
  printf("timer=%ld us\n", timer);

  return 0;
}
