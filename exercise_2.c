#include <stdio.h>

int add(int a, int b){
return a + b;
}

int max(int a, int b){
return (a > b) ? a : b;
}

float average(int arr[], int n){
int a = 0;
int sum = 0;
while(a < n){
sum += arr[a];
a++;
}
return sum / n;
}

int main() {
int n;
printf("enter n: ");
scanf("%d", &n);
int a = 0;
int array[n];
int max_number = 0;
while(a < n){
printf("enter array[%d] slot: ", a);
scanf("%d", array + a);
max_number = max(array[a], max_number);
a++;
}
printf("the largest number of this array is %d\n", max_number);
printf("the mean of this array is %f\n", average(array, n));
return 0;
}
