#include <stdio.h>
#include <stdlib.h>

int main()
{

	int number, k;
	int N = 100;
	int count = 0;
	int a[N];
	
	scanf("%d", &number);
	
	for (int i = 0; i < N; ++i) {
		
		a[i] = 0;
	}
	
	for (int i = 0; i < N; ++i) {
	
		if (number != 0) {
			k = number % 2;
			a[i] = k;
			number = number / 2;
			count ++;
		}
	}
	
	for (int j = count - 1; j >= 0; --j) {
		
		printf("%d", a[j]);
	}
	
	return 0;
}
	


