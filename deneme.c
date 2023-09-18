#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

size_t	ft_strlen(const char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[start + i] && i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}


char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!ptr)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}


void ft_parser(char *str)
{
	int i = 0;
	int counter = 0;
	char **ptr;
	while(str[i])
	{
		if(str[i] == '|')
			counter++;
		i++;
	}
	ptr = malloc(sizeof(char *)* (counter + 2));
	int j = 0;
	i = 0;
	int k = 0;
	while (j<=counter)
	{
		k = i;
		while (str[i] && str[i]!='|')
		{
			i++;
		}
		ptr[j] = ft_strdup(ft_substr(str,k,i-k));
		i = i+1;
		j++;
	}
	j = 0;
	while (j<=counter)
	{
		printf("\"%s\"\n",ptr[j]);
		j++;
	}


}

int main()
{
	while (1)
	{
		char *line;
		char buff[200];
		line = readline("minishell$ ");
		if(*line && line)
			add_history(line);
		ft_parser(line);
	}
}
