/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_ftssl_opts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:26:09 by aimustaev         #+#    #+#             */
/*   Updated: 2023/01/09 22:03:58 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

// По названию параметра возвращаем бит флага
int get_ft_ssl_opt(char c)
{
	int i;

	i = 0;
	while (g_ssl_opts[i].c)
	{
		if (c == g_ssl_opts[i].c)
			return (g_ssl_opts[i].flag);
		i++;
	}
	return (0);
}

// Алертим если невалидный флаг
static void print_invalid_ssl_flag(char c)
{
	ft_printf("ft_ssl: Error: Invalid flag: %c\n", c);
	ft_ssl_usage();
	exit(0);
}

// Обработка флагов которые мы вводим при старте утилиты -qs
void load_ftssl_opts(char **argv, int *arc_iterator)
{
	int i;
	int j;
	int val;

	i = 0;
	while (argv[i] && argv[i][0] == '-' && argv[i][1])
	{
		j = 0;
		while (argv[i][++j])
		{
			if ((val = get_ft_ssl_opt(argv[i][j])) > 0)
				g_ft_ssl_flags |= val;
			else
				print_invalid_ssl_flag(argv[i][j]);
			if (val == FTSSL_S)
			{
				*arc_iterator += i;
				return;
			}
		}
		i++;
	}
	*arc_iterator += i;
}
