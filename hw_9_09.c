#include <stdio.h>
#include <stdlib.h>

// лишние пустые строки в коде
int main()
{

	int number, k;
	int N = 100;
	int count = 0;
	int a[N];
	
	scanf("%d", &number);
	
	// можно использовать memset для инициализации массива
	for (int i = 0; i < N; ++i) {
		
		a[i] = 0;
	}
	
	// 1) если начиная с некого момент number равен 0, то и на всех последующих итерациях цикла for оно останется нулем
	// -> for (int i = 0; i < N && number != 0; ++i)
	// 2) старайтесь выносить логически законченные куски кода в отдельные ф-и. Например, код по переводу из 10й в 2ю систему сч. можно было бы вынести в отдельную ф-ю.
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
	


