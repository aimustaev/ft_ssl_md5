/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_explicit_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:25:16 by aimustaev         #+#    #+#             */
/*   Updated: 2023/01/09 21:51:35 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

/*
** The output format depends on what the original
** parameter was, this is tracked by is_string.
*/

static void	print_original(char *o, int is_string)
{
	if (is_string)
		ft_printf("\"%s\"", o);
	else
		ft_printf("%s", o);
}

/*
** Formats the output into an explicit output print
*/

void		print_explicit_format(
	t_ssl_func hashtype,
	char *out_digest,
	char *original,
	int is_string)
{
	if (g_ft_ssl_flags & FTSSL_Q)
		ft_printf(out_digest);
	else if (g_ft_ssl_flags & FTSSL_R)
	{
		ft_printf("%s ", out_digest);
		print_original(original, is_string);
	}
	else
	{
		ft_putupper(hashtype.name);
		ft_printf(" (");
		print_original(original, is_string);
		ft_printf(") = %s", out_digest);
	}
	ft_printf("\n");
}
