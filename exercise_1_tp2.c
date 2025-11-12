#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *LoadString(int N){
    char *name = (char *) malloc(sizeof(char) * N);
    fgets(name, N, stdin);
    return name;
};
int StringLength(char *str){
    int a = 0;
    while( *(str + a) != '\0'){
        a++;
    }
    
    return a;
};
void LoadArray(char *p, char arr[]){
    int a = StringLength(p);
    int b = 0;
    while(b < a){
        *(arr + b) = *(p + b);
        b++;
    }
};
void ReverseArray(char arr[], char rev[], int n){
int a = 0;
while(a < n){
rev[a] = arr[n - a - 1];
a++;
}
}
void DisplayArray(char arr[], int n){
int a = 0;
while(a < n){
printf("%c", arr[a]);
a++;
}
printf("\n");
}
int SumStringASCII(char *p){
int a;
if(*p == '\0'){
return 0;
}else{
a = *p;
return a + SumStringASCII(p+1);
}
}
void ReverseString(char *start, char *end){
if(start < end){
char tmp = *start;
*start = *end;
*end = tmp;
ReverseString(start + 1, end - 1);
}
}
int main() {
char *str;
int n;
printf("Please enter the maximum size of the string:\n");
scanf("%d", &n);
getchar();
str = LoadString(n);
int len = StringLength(str);
char arr[len + 1], rev[len + 1];
LoadArray(str, arr);
printf("\n Original array: ");
DisplayArray(arr, len);
ReverseArray(arr, rev, len);
printf("\n Reversed array: ");
DisplayArray(rev, len);
int sum = SumStringASCII(str);
printf("\n Sum of ASCII values (recursive): %d", SumStringASCII(str));
ReverseString(str, str + len -1);
printf("\nString reversed recursively: %s\n", str);
free(str);
return 0;
}
