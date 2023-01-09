/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:25:11 by aimustaev         #+#    #+#             */
/*   Updated: 2023/01/09 21:51:35 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

/*
** Gathers input from stdin and prints results.
*/

void	handle_stdin(const t_ssl_func *ssl_f)
{
	t_msg			*msg;
	char			buffer[SSL_READ_BUFFSIZE];
	unsigned char	*tmp;
	ssize_t			ret;

	msg = init_msg();
	while ((ret = read(0, buffer, SSL_READ_BUFFSIZE)) > 0)
	{
		tmp = msg->contents;
		msg->contents = ft_memalloc(msg->len + ret);
		ft_memcpy(msg->contents, tmp, msg->len);
		ft_memcpy(msg->contents + msg->len, buffer, ret);
		msg->len += ret;
		ft_memdel((void **)&tmp);
	}
	if (g_ft_ssl_flags & FTSSL_P)
	{
		write(1, msg->contents, msg->len);
	}
	ft_printf("%s\n", (tmp = (unsigned char *)ssl_f->funct(msg)));
	ft_memdel((void **)&tmp);
	del_msg(&msg);
}
