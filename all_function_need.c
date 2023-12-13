#include "our_main.h"

/**
 * _get_line - takes the input from user
 * Return: pointer
 */

char *_get_line(void)
{
	char *esra = NULL;
	size_t n;
	ssize_t fuad = 0;

	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "$ ", 2);
	fuad = getline(&esra, &n, stdin);
	if (fuad == -1)
	{
		free(esra);
		return (NULL);
	}
	return (esra);
}

/**
 * our_tokenizer- split the string
 * @atika: string
 * Return: pointer to string
 */

char **our_tokenizer(char *atika)
{
	char **cmd = NULL, *tok = NULL, *temp = NULL,  *delm = " \t\n";
	int count = 0, i;

	if (atika == NULL)
		return (NULL);
	temp = strdup(atika);
	tok = strtok(temp, delm);
	if (tok == NULL)
	{
		free(atika);
		atika = NULL;
		free(temp);
		temp = NULL;
		return (NULL);
	}
	for (; tok;)
	{
		count++;
		tok = strtok(NULL, delm);
	}
	free(temp), temp = NULL;
	cmd = malloc(sizeof(char *) * (count + 1));
	if (cmd == NULL)
	{
		free(atika);
		atika = NULL;
		return (NULL);
	}
	tok = strtok(atika, delm);
	for (i = 0; tok != NULL; i++)
	{
		cmd[i] = strdup(tok);
		tok = strtok(NULL, delm);
	}
	free(atika);
	atika = NULL;
	cmd[i] = NULL;
	return (cmd);
}

/**
 * _free_free - function free
 * @esra: pointe to string
 * Return: Nothing
 */
void _free_free(char **esra)
{
	int i = 0;

	if (esra == NULL)
		return;
	while (esra[i])
	{
		free(esra[i]);
		esra[i] = NULL;
		i++;
	}
	free(esra);
	esra = NULL;
}


/**
 * execute_fun- for execuation
 * @ranim: pointer to pointer
 * @ala: pointer to string
 * @ind: index
 * Return: int value
 */

int execute_fun(char **ranim, char **ala, int ind)
{
	char *ful_path;
	pid_t eman;
	int stat;

	ful_path = ourPath(ranim[0]);
	if (ful_path == NULL)
	{
		_error(ala[0], ranim[0], ind);
		_free_free(ranim);
		return (127);
	}
	eman = fork();

	if (eman == 0)
	{
		if (execve(ful_path, ranim, environ) == -1)
		{
			free(ful_path);
			ful_path = NULL;
			perror(ala[0]);
			_free_free(ranim);
			exit(100);
		}
	}
	else
	{
		waitpid(eman, &stat, 0);
		_free_free(ranim);
		free(ful_path);
		ful_path = NULL;
	}
	return (WEXITSTATUS(stat));
}

/**
 * main - main function
 * @argc: argument
 * @argv: pointer to array
 * Return: int value
 */
int main(int argc, char *argv[])
{
	char *esra = NULL;
	char **atika = NULL;
	int stat = 0;
	int ind = 0;

	(void)argc;
	while (1)
	{
		esra = _get_line();
		if (esra == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}
		ind++;
		atika = our_tokenizer(esra);
		if (!atika)
			continue;

		if (alrady_exist(atika[0]))
			check_command(atika, argv, &stat, ind);
		else
			stat = execute_fun(atika, argv, ind);
	}
}
