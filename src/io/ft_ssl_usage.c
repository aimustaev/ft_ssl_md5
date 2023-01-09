/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_usage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:25:00 by aimustaev         #+#    #+#             */
/*   Updated: 2023/01/09 21:26:16 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

/*
** A couple functions to print usages.
** These dynamically add new functions with ease
** by adding new options in the haeder.
*/

void	ft_ssl_usage(void)
{
	int i;

	i = 0;
	ft_printf("usage: ft_ssl command [-");
	while (g_ssl_opts[i].c && g_ssl_opts[i].c != 's')
		ft_printf("%c", g_ssl_opts[i++].c);
	ft_printf("] [-s string] [files ...]\n");
}

void	ft_ssl_help(void)
{
	int i;

	ft_ssl_usage();
	ft_printf("\nOptions:\n");
	i = -1;
	while (g_ssl_opts[++i].c)
		ft_printf("-%c -- %s\n", g_ssl_opts[i].c, g_ssl_opts[i].desc);
	i = 0;
	ft_printf("\nStandard commands:\n");
	ft_printf("\nMessage Digest commands:\n");
	while (g_ssl_functs[i].name)
		ft_printf("   %s\n", g_ssl_functs[i++].name);
	ft_printf("\nCipher commands:\n");
	exit(0);
}
