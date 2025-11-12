#include< stdio.h >
#include< string.h >
#include< stdlib.h >
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
    a++;
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
Int a = 0;
int b = ((n % 2) == 1) ? ((n - 1) / 2) : (n/2);
while(a < b){
rev[a] = arr[n - a - 1];
rev[n - a - 1] = arr[a];
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
return a + SunStringASCII(p+1);
}
}
void ReverseString(char *start, char *end);
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
printf("\n Sum of ASCII values (recursive): %d", SumStringASCII(str, str + len- 1));
printf("String reversed recursively: %s\n", str);
free(str);
return 0;
}
