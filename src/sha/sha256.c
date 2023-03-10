/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:25:56 by aimustaev         #+#    #+#             */
/*   Updated: 2023/01/09 22:07:48 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static unsigned char	*expand_msg(uint8_t *initial_msg,
	size_t initial_len, size_t *new_len)
{
	unsigned char	*msg;
	uint64_t		bits_len;

	*new_len = initial_len;
	*new_len += 1;
	while (*new_len % 64 != 56)
		*new_len += 1;
	msg = (unsigned char *)malloc(sizeof(unsigned char) * (*new_len + 8));
	ft_bzero(msg, *new_len + 8);
	ft_memcpy(msg, initial_msg, initial_len);
	msg[initial_len] = (unsigned char)128;
	bits_len = swap_endian_uint64(initial_len * 8);
	ft_memcpy(msg + *new_len, &bits_len, 8);
	return (msg);
}

static char				*sha256tostr(unsigned int hashbuff[8])
{
	char	*out;
	int		i;
	uint8_t	*p;
	int		j;

	i = 0;
	out = ft_strnew(64 + 1);
	while (i < 8)
	{
		p = (uint8_t *)&hashbuff[i];
		j = 0;
		while (j < 4)
		{
			out[i * 8 + j * 2] = char_to_hex((p[3 - j] >> 4));
			out[i * 8 + j * 2 + 1] = char_to_hex(p[3 - j]);
			j++;
		}
		i++;
	}
	return (out);
}

static void				init_hash(unsigned int h[8])
{
	h[0] = 0x6a09e667;
	h[1] = 0xbb67ae85;
	h[2] = 0x3c6ef372;
	h[3] = 0xa54ff53a;
	h[4] = 0x510e527f;
	h[5] = 0x9b05688c;
	h[6] = 0x1f83d9ab;
	h[7] = 0x5be0cd19;
}

char					*ft_sha256(t_msg *initial_msg)
{
	unsigned int	h[8];
	size_t			new_len;
	unsigned char	*msg;
	char			*digest;

	init_hash(h);
	msg = expand_msg(initial_msg->contents, initial_msg->len, &new_len);
	process_sha256(msg, new_len, h);
	digest = sha256tostr(h);
	free(msg);
	return (digest);
}
