/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:24:32 by sgundogd          #+#    #+#             */
/*   Updated: 2023/10/29 04:44:38 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_control(t_data **total_line)
{
	t_data *tmp_1;
	t_data *tmp_2;

	tmp_1 = *total_line;

	while (tmp_1)
	{
		if(*(tmp_1->content) == '|' || *(tmp_1->content) == '<' || *(tmp_1->content) == '>')
		{
			tmp_2=tmp_1->next;
			if(tmp_2 && *(tmp_1->content) == *(tmp_2->content))
			{
				tmp_2 = tmp_2->next;
				if(tmp_2 && *(tmp_1->content) == *(tmp_2->content))
					printf("error 1\n");
			}
			else
			{
				if(tmp_2 && (*(tmp_2->content) == '|' || *(tmp_2->content) == '<' || *(tmp_2->content) == '>'))
					printf("error 2\n");
			}
		}
		tmp_1= tmp_1->next;

	}

}

int main()
{
	t_data *total_line;
	while (1)
	{
		total_line = malloc(sizeof(t_data));
		total_line = NULL;
		char *line;
		line = readline("minishell$ ");
		if(*line && line)
		{
			add_history(line);
			ft_parser(line, &total_line);
			while (total_line)
			{
				printf("%s\n", total_line->content);
				total_line = total_line->next;
			}

			ft_control(&total_line);
		}
	}
}
