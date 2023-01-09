/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:12:49 by aimustaev         #+#    #+#             */
/*   Updated: 2023/01/09 20:12:50 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putupper(char *str)
{
	while (*str)
	{
		*str >= 'a' && *str <= 'z' ? ft_putchar(*str - 32) : ft_putchar(*str);
		str++;
	}
}
