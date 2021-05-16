#include <stdio.h>

void NumTranslateBinary (int n) {
	if (n != 0)
	{
		NumTranslateBinary(n / 2);
	} 
	else {
		return;
	}
	printf("%d", n % 2);
 	return;
}

double ExpRec (double a, double b) {
	double result = 0;
	if (b <= 0){
		return 1;
	}
	else {
		return a * ExpRec(a, (b-1));
	}
}

int main(int argc, char const *argv[]){
	
	int n;
	printf("%s\n", "Enter the number");
	scanf("%d", &n);
	NumTranslateBinary(n);
	printf("\n");

	double a, b;
	printf("%s\n", "Enter the base");
	scanf("%lf", &a);
	printf("%s\n", "Enter the exponent");
	scanf("%lf", &b);
	printf("%lf\n",ExpRec(a, b));
	return 0;
}