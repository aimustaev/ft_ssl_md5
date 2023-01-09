/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_endian_uint64.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:28:02 by aimustaev         #+#    #+#             */
/*   Updated: 2023/01/09 20:28:02 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
** Converts the endianness of a 64 bit integer.
*/

unsigned long long	swap_endian_uint64(long long bits)
{
	return (
		((bits & 0xff00000000000000ULL) >> 56) |
		((bits & 0x00ff000000000000ULL) >> 40) |
		((bits & 0x0000ff0000000000ULL) >> 24) |
		((bits & 0x000000ff00000000ULL) >> 8) |
		((bits & 0x00000000ff000000ULL) << 8) |
		((bits & 0x0000000000ff0000ULL) << 24) |
		((bits & 0x000000000000ff00ULL) << 40) |
		((bits & 0x00000000000000ffULL) << 56));
}
