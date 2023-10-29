/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:23:32 by sgundogd          #+#    #+#             */
/*   Updated: 2023/10/29 04:44:19 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define  MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"

typedef struct s_data
{
	char			*content;
	int				type;
	struct s_data	*next;
}					t_data;

void ft_parser(char *str,t_data **total_line);
void ft_split_2(char *str, t_data **total_line);
t_data	*ft_last(t_data *lst);
t_data	*ft_create(char *str);
char	**ft_spc_split(char const *s);
int is_operate(char s);
int is_quote(char *s);

#endif
