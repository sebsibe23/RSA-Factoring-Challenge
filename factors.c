#include <stdio.h>
/**
 * factorize - Factorizes a number into a product of two smaller numbers.
 *@varnum: The number to be factorized.
 *
 * Return: return void. The function directly prints the
 * factorization to stdout.
 */
void factorize(long long varnum)
{
	long long divisor;
	long long varquotient;

	for (divisor = 2; divisor * divisor <= varnum; divisor++)
	{
		if (varnum % divisor == 0)
		{
			varquotient = varnum / divisor;
			printf("%lld=%lld*%lld\n", varnum, divisor, varquotient);
			return;
		}
	}
	printf("%lld=%lld*%lld\n", varnum, varnum, 1LL);
}

/**
 * main - Reads numbers from a file and factorizes them.
 * Return: return int. Returns 0 if the program finishes successfully,
 * and 1 if a file could not be opened.
 */
int main(void)
{
	char *varfname = "tests/test00";
	FILE *varfPointer = fopen(varfname, "r");
	long long num;
	int varreadStatus;
	int ereturn = 1;
	int sreturn = 0;

	if (varfPointer == NULL)
	{
		printf("Could not open file %s", varfname);
		return (ereturn);
	}

	while ((varreadStatus = fscanf(varfPointer, "%lld", &num)) == 1)
	{
		factorize(num);
	}
	if (varreadStatus != EOF)
	{
		printf("Failed to read the number\n");
		return (ereturn);
	}
	fclose(varfPointer);
	return (sreturn);
}


