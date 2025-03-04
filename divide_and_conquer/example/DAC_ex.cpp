// C++ code to demonstrate Divide and
// Conquer Algorithm#include<iostream>
# include<iostream>
using namespace std;

// function to find the maximum no.
// in a given array.
int DAC_Max(int a[], int index, int l)
{
    int max;
    if(l - 1 == 0)
    {
      return a[index];
    }
    if(index >= l - 2)
    {
        if(a[index] > a[index + 1])
          return a[index];
        else
          return a[index + 1];
    }  
    max = DAC_Max(a, index + 1, l);    
    if(a[index] > max)
       return a[index];
    else
       return max;
}

// Function to find the minimum no.
// in a given array
int DAC_Min(int a[], int index, int l)
{
    int min;
      if(l - 1 == 0)
    {
      return a[index];
    }
    if(index >= l - 2)
    {
        if(a[index] < a[index + 1])
          return a[index];
        else
          return a[index + 1];
    }
    
    min = DAC_Min(a, index + 1, l);   
    if(a[index] < min)
       return a[index];
    else
       return min;
}

// Driver code
int main()
{
   int a[7] = { 70, 250, 50, 80, 140, 12, 14 };
    int n = sizeof(a) / sizeof(a[0]);
    int max, min;
    max = DAC_Max(a, 0, n);
    min = DAC_Min(a, 0, n);
    cout << "The minimum number in a given array is : " << min << endl;
    cout << "The maximum number in a given array is : " << max << endl;
    return 0;
}

// This code is contributed by probinsah.
