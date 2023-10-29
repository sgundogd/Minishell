/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:24:32 by sgundogd          #+#    #+#             */
/*   Updated: 2023/10/29 11:08:30 by sgundogd         ###   ########.fr       */
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
				if(tmp_2 && (*(tmp_1->content) == *(tmp_2->content) || *(tmp_1->content) =='|'))
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

/*void ft_control(char *line)
{
	int i = 0;
	while(line[i])
	{
		if(line[i] == '<' || line[i] == '>')
			if(line[i+1] == line[i] && line[i+2] == line[i])
				printf("error1");
		if(line[i] == '|')
			if(line[i+1] == line[i] && line[i+2] == line[i])
				printf("error1");
		i++;
	}

}*/

int main()
{
	t_data *total_line;
	int i = 0;
	while (1)
	{
		i = 0;
		total_line = malloc(sizeof(t_data));
		total_line = NULL;
		char *line;
		line = readline("minishell$ ");
		if(*line && line)
		{
			add_history(line);
			//ft_control(line);
			ft_parser(line, &total_line);
			while (total_line)
			{
				printf("\neleman %d ---->    %s\n", i,total_line->content);
				total_line = total_line->next;
				i++;
			}

		}
	}
}
