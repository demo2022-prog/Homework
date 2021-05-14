#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	printf("%s\n", "Enter the number");
	int n = 0;
	scanf("%d", &n);
	for (int i = 2; i < n; ++i)
	{
		if (n % i == 0)
		{
			printf("%s\n", "This number is not prime");
			break;
		}
		else 
		{
			printf("%s\n", "This number is prime");
			break;
		}
	}
	return 0;
}