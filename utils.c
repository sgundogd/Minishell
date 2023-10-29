/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:49:00 by sgundogd          #+#    #+#             */
/*   Updated: 2023/10/29 04:44:02 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*ft_last(t_data *lst)
{
	while (lst)
	{
		if (lst->next)
			lst = lst->next;
		else
			return (lst);
	}
	return (NULL);
}

t_data	*ft_create(char *str)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	new->content = str;
	new->next = NULL;
	return (new);
}

int is_operate(char s)
{
	if ( s == '<' || s == '>' ||s == '|')
		return(1);
	return(0);
}
int is_quote(char *s)
{
	int i = 0;
	while (s[i])
	{
		if ( s[i] == '\'' || s[i] == '"' )
			return(1);
		i++;
	}
	return(0);
}
