/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartet_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:27:31 by aimustaev         #+#    #+#             */
/*   Updated: 2023/01/09 20:27:58 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns a hex character representing a quartet of bytes.
*/

char	quartet_to_hex(unsigned char quartet)
{
	quartet = quartet & 0xf;
	if (quartet < 10)
		return (quartet + '0');
	else
		return ((quartet - 10) + 'a');
}
