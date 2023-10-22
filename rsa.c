#include "factor.h"
/**
 * main - a main function of the program.
 * @argc: a number of command-line arguments.
 * @argv: a command-line arguments.
 * a function takes a filename as a command-line argument.
 * It opens the file,
 * reads it line by line, and applies
 * the factorize function to each line.
 * Return: Returns 0 on success,
 * and an error code on failure.
 */
int main(int argc, char *argv[])
{
	FILE *varfptr;
	size_t count;
	ssize_t varline;
	char *buffer = NULL;
	int e_code = EXIT_FAILURE;
	int varargc = argc;

	if (varargc != 2)
	{
		fprintf(stderr, "Usage: factor tests/rsa-1\n");
		exit(e_code);
	}
	varfptr = fopen(argv[1], "r");
	if (varfptr == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(e_code);
	}
	while((varline = getline(&buffer, &count, varfptr)) != -1)
	{
		int result = factorize(buffer);
		if (result != 0)
		{
			fprintf(stderr, "Error: factorize failed on line %s\n", buffer);
			exit(e_code);
		}
	}
	e_code = EXIT_SUCCESS;
	return (e_code);
}
/**
 * factorize -a function takes a string buffer as input,
 * converts it to an integer,
 * and then finds the factors of the integer.
 * It prints the factors to the console.
 * @buffer: pointer to the address of the number
 * Return: return Returns 0 on success.
 */
int factorize(char *buffer)
{
	u_int32_t varnum;
	u_int32_t y;
	u_int32_t varfactor;
	int vreturn = 0;

	varnum = atoi(buffer);

	for (y = 2; y < varnum; y++)
	{
		if (varnum % y == 0)
		{
			varfactor = varnum / y;
			printf("%d=%d*%d\n", varnum, varfactor, y);
			break;
		}
	}

	return (vreturn);
}

