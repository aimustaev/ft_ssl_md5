/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:25:20 by aimustaev         #+#    #+#             */
/*   Updated: 2023/01/09 22:07:48 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static char	*md5tostr(unsigned int hashbuff[4])
{
	char	*out;
	int		i;
	uint8_t	*p;
	int		j;

	i = 0;
	out = ft_strnew(32);
	while (i < 4)
	{
		p = (uint8_t *)&hashbuff[i];
		j = -1;
		while (++j < 4)
		{
			out[i * 8 + j * 2] = char_to_hex((p[j] >> 4));
			out[i * 8 + j * 2 + 1] = char_to_hex(p[j]);
		}
		i++;
	}
	return (out);
}

char		*ft_md5(t_msg *msg)
{
	char			*out;
	unsigned int	hash_buffer[4];

	process_md5(msg->contents, msg->len, hash_buffer);
	out = md5tostr(hash_buffer);
	return (out);
}
