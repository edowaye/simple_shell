#include "shell.h"

/**
  *_myenv - function that prints the current environment
  *@info: Struct containing arguments that may
  *be used
  *
  *Return: 0
  */

int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
  *_getenv - funtion that fetches value of an environment var
  *@info: Struct containing arguments that may be used
  *@name: variable environment name
  *
  *Return: value fetched
  *
  */

char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
  *_mysetenv - function that initializes or modifies
  *a new or existing environment variable
  *
  *@info: Struct containing arguments that may be used
  *
  *Return: 0
  *
  */

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
  *_myunsetenv - function that removes an environment variable
  *
  *@info: Structure containing arguments that may be used
  *
  *Return: 0
  *
  */

int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
  *populate_env_list - function that populates the
  *environment's linked list
  *
  *@info: Structure containing arguments that may be used
  *
  *Return: 0
  *
  */

int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
