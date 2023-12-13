#include "our_main.h"

/**
 * alrady_exist - check if the command builtin
 * @ranim: string to be checked
 * Return: int value
 */

int alrady_exist(char *ranim)
{
	char *esra[] = {"exit", "echo", "env", "cd", NULL};
	int j;

	for (j = 0; esra[j]; j++)
	{
		if (strcmp(ranim, esra[j]) == 0)
			return (1);
	}
	return (0);
}

/**
 * check_command - check for exit and env
 * @ranim: pointer to pointer
 * @arv: pointer to string
 * @fuad: string of integer
 * @ind: index
 * Return: Nothing
 */

void check_command(char **ranim, char *arv[], int *fuad, int ind)
{
	(void) ind;
	(void) arv;

	if (strcmp(ranim[0], "exit") == 0)
		_exit_exit(ranim, fuad);
	else if (strcmp(ranim[0], "env") == 0)
		put_environ(ranim, fuad);
}

/**
 * put_environ - function print environ
 * @ranim: pointer to pointer
 * @fuad: pointer of integer
 * Return: Nothing
 */
void put_environ(char **ranim, int *fuad)
{
	int j, i;
	char *tmp = NULL;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[j]; j++)
		{
			if (strcmp(environ[i], environ[j]) > 0)
			{
				tmp = environ[i];
				environ[i] = environ[j];
				environ[j] = tmp;
			}
		}
	}
	for (j = 0; environ[j]; j++)
	{
		write(STDOUT_FILENO, environ[j], strlen(environ[j]));
		write(STDOUT_FILENO, "\n", 1);
	}
	_free_free(ranim);
	(*fuad) = 0;
}
/**
 * _exit_exit - exit from shell
 * @ranim: pointer to pointer
 * @fuad: string of integer
 * Return: Nothing
 */

void _exit_exit(char **ranim, int *fuad)
{
	_free_free(ranim);
	exit(*fuad);
}
