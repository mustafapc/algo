#include <stdio.h>

void pma(int array[4][4]){
int a = 0;
int b = 0;

while(a < 4){
	while(b < 4){
	printf("%d ", array[a][b]);
	b++;
	}
printf("\n");
b = 0;
a++;
}
}

int main(){
int array1[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
printf("before\n");
pma(array1);
printf("after\n");
int a = 0;
int b = 0;
int array2[4][4];
while(a < 4){
	while(b < 4){
	array2[a][b] = array1[b][a];
	b++;
	}
b = 0;
a++;
}
pma(array2);
return 0;
}
