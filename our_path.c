#include "our_main.h"

/**
 * _environ - get environ
 * @var: string
 * Return: pointer or NULL
 */

char *_environ(char *var)
{
	char *hind, *hana, *hawa, *env;
	int i;

	if (environ == NULL)
	{
		fprintf(stderr, "Error: environ is NULL\n");
		return (NULL);
	}
	for (i = 0; environ[i]; i++)
	{
		hind = strdup(environ[i]);
		if (hind == NULL)
		{
			fprintf(stderr, "Error: Memory allocation failed\n");
			return (NULL);
		}
		hana = strtok(hind, "=");
		if (strcmp(hana, var) == 0)
		{
			hawa = strtok(NULL, "\n");
			if (hawa == NULL)
			{
				free(hind);
				return (NULL);
			}
			env = strdup(hawa);
			free(hind);
			return (env);
		}
		free(hind);
		hind = NULL;
	}
	return (NULL);
}

/**
 * ourPath - function found the path
 * @ranim: string
 * Return: pointer or NULL
 */

char *ourPath(char *ranim)
{
	char *_path, *ful_path = NULL, *dr;
	struct stat esra;
	int i;

	for (i = 0; ranim[i]; i++)
	{
		if (ranim[i] == '/')
		{
			if (stat(ranim, &esra) == 0)
				return (strdup(ranim));
			return (NULL);
		}
	}
	_path = _environ("PATH");
	if (_path == NULL)
		return (NULL);
	dr = strtok(_path, ":");
	while (dr)
	{
		ful_path = malloc(strlen(dr) + strlen(ranim) + 2);
		if (ful_path)
		{
			strcpy(ful_path, dr);
			strcat(ful_path, "/");
			strcat(ful_path, ranim);
			strcat(ful_path, "\0");
			if (stat(ful_path, &esra) == 0)
			{
				free(_path);
				return (ful_path);
			}
			free(ful_path), ful_path = NULL;
			dr = strtok(NULL, ":");
		}
	}
	free(_path);
	return (NULL);
}

/**
 * _error - function print error
 * @path: path pointer
 * @command: command pointer
 * @ind: index
 * Return: Nothing
 */
void _error(char *path, char *command, int ind)
{

	fprintf(stderr, "%s: %d: %s: not found\n", path, ind, command);
}

/**
 * ranim - function change integer to charcter
 * @x: int value
 * Return: pointer
 */

char *ranim(int x)
{
	char buf[20];
	int i = 0;

	if (x == 0)
		buf[i++]  = '0';
	else
	{
		while (x > 0)
		{
			buf[i++] = (x % 10) + '0';
			x /= 10;
		}
	}
	buf[i] = '\0';
	rev_str(buf, i);
	return (strdup(buf));
}

/**
 * rev_str - reverse string
 * @a: string to be rseversed
 * @n: int value
 * Return: Nothing
 */

void rev_str(char *a, int n)
{
	char temporary;
	int counter, x;

	x = 0;
	x = n - 1;
	counter = 0;
	while (counter < x)
	{
		temporary = a[counter];
		a[counter] = a[x];
		a[x] = temporary;
		counter++;
		x--;
	}
}
