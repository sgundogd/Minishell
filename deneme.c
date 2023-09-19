/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deneme.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:24:32 by sgundogd          #+#    #+#             */
/*   Updated: 2023/09/19 20:26:39 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **ft_split_2(char *str, t_list **total_line)
{
	int i = 0;
	int counter = 0;
	int start = 0;
	char **ptr;
	while(str[i])
	{
		if(str[i] == '|' || str[i] == '>' || str[i] == '<')
			counter++;
		i++;
	}
	ptr = malloc(sizeof(char *)* (counter * 2 + 2));
	int j = 0;
	i = 0;
	while (str[i])
	{
		if(str[i] == '|' ||str[i] == '<' ||str[i] == '>')
		{
		if(ft_isprint(str[i-1]) && str[i-1] != '<' && str[i-1] != '>' && str[i-1] != '|')
		{
			ptr[j] = ft_substr(str,start,i-start);
			j++;
			ptr[j] = ft_substr(str,i,1);
			j++;
		}
		else
		{
			ptr[j] = ft_substr(str,i,1);
			j++;

		}
		start = i+1;
		}
		i++;
	}
	if(str[start])
	{
		ptr[j] = ft_substr(str,start,i-start);
		j++;
	}
	ptr[j] = NULL;
	j = 0;
	return(ptr);
}

void ft_parser(char *str,t_list **total_line)
{
	char **ptr;
	char **dnm;
	int i;

	i = 0;
	ptr = ft_split(str,' ');
	while(ptr[i])
	{
		dnm = ft_split_2(ptr[i],total_line);
		i++;

	}
}

void	ft_cleaner(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free (ptr);
}
t_list	*ft_create(int nbr)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->data = nbr;
	new->next = NULL;
	return (new);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*new;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		new = (*lst)->next;
		(*lst)->data = 0;
		free(*lst);
		(*lst) = new;
	}
}
int main()
{
	t_list *total_line;
	while (1)
	{
		char *line;
		line = readline("minishell$ ");
		if(*line && line)
			add_history(line);
		ft_parser(line, &total_line);
	}
}
