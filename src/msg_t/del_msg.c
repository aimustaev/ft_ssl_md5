/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:25:29 by aimustaev         #+#    #+#             */
/*   Updated: 2023/01/09 20:25:30 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

/*
** both t_msg and the char* are going to be alloced.
** Delete them in order.
*/

void	del_msg(t_msg **msg)
{
	ft_memdel((void**)&((*msg)->contents));
	free((*msg));
	*msg = NULL;
}
