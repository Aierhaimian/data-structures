#include <stdio.h>
#include <stdlib.h>

int Max3(int num1, int num2, int num3)
{
  int Max;
  Max = num1>num2 ? num1 : num2;
  Max = Max>num3 ? Max : num3;

  return Max;
}

int MaxSubSum(int array[], int left, int right)
{
  int MaxLeftSum, MaxRightSum;
  int MaxLeftBorderSum, MaxRightBorderSum;
  int LeftBorderSum, RightBorderSum;

  if (left == right)
  {
    if (array[left] > 0)
      return array[left];
    else
      return 0;
  }

  int mid = (left+right)/2;
  MaxLeftSum = MaxSubSum(array, left, mid);
  MaxRightSum = MaxSubSum(array, mid+1, right);

  MaxLeftSum = 0; LeftBorderSum = 0;
  for (int i=mid; i>=left; i--)
  {
    LeftBorderSum += array[i];
    if (LeftBorderSum > MaxLeftBorderSum)
      MaxLeftBorderSum = LeftBorderSum;
  }

  MaxRightBorderSum = 0; RightBorderSum = 0;
  for (int i=mid+1; i<=right; i++)
  {
    RightBorderSum += array[i];
    if (RightBorderSum > MaxRightBorderSum)
      MaxRightBorderSum = RightBorderSum;
  }

  return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum+MaxRightBorderSum);
}

//Time Complicity: O(NlogN)
int MaxSubsequenceSum3(int array[], int n)
{
  return MaxSubSum(array, 0, n-1);
}

//Time Complicity: O(N^3)
int Max_subsequence_sum_01(int array[], int n)
{
    int Max_sum = INT_MIN;
    for (int i=0; i<n; i++)
    {
        for (int j=i; j<n; j++)
        {
            int This_sum = 0;
            for (int k=i; k<=j; k++)
            {
                This_sum += array[k];
            }

            if (This_sum > Max_sum)
                Max_sum = This_sum;
        }
    }

    return Max_sum;
}

//Time Complicity: O(N^2)
int Max_subsequence_sum_02(int array[], int n)
{
    int Max_sum = INT_MIN;
    for (int i=0; i<n; i++)
    {
        int This_sum = 0;
        for (int j=i; j<n; j++)
        {
            This_sum += array[j];
            if (This_sum > Max_sum)
                Max_sum = This_sum;
        }
    }

    return Max_sum;
}

//Time Complicity: O(N)
int Max_subsequence_sum_04(int array[], int n)
{
    int Max_sum = INT_MIN;
    for (int i=0; i<n; i++)
    {
        int This_sum = 0;
        This_sum += array[j];
        if (This_sum > Max_sum)
        	Max_sum = This_sum;
	else if (This_sum < 0)
		This_sum = 0;
    }

    return Max_sum;
}


int main(int argc, char **argv)
{
  if (argc > 2)
  {
    printf("Parameter error!\nPlease input: ./MaxSubsequenceSum input_number.txt\n");
    return -1;
  }

  FILE *fp;
  fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
    printf("The input file open failed.\n");
    return -1;
  }

  int n;
  fscanf(fp, "%d", &n);
  int array[n];
  int i = 0;
  while (fscanf(fp, "%d", array+i) != EOF)
    i++;

  fclose(fp);

  int res = MaxSubsequenceSum3(array, n);
  printf("Algorithm 3: The max subsequence sum is %d.\n", res);

  return 0;
}
