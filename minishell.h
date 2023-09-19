/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:23:32 by sgundogd          #+#    #+#             */
/*   Updated: 2023/09/19 20:25:46 by sgundogd         ###   ########.fr       */
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


void	ft_lstclear(t_list **lst);
t_list	*ft_create(int nbr);
void	ft_cleaner(char **ptr);
void ft_parser(char *str,t_list **total_line);
char **ft_split_2(char *str, t_list **total_line);

#endif
