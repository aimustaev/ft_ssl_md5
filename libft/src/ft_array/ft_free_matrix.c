/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:15:36 by slynell           #+#    #+#             */
/*   Updated: 2020/08/03 13:54:47 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix_char(char ***matrix, int count_row)
{
	int i;

	i = -1;
	while (++i < count_row)
		free((*matrix)[i]);
	free(*matrix);
	*matrix = NULL;
}

void	ft_free_matrix_int(int ***matrix, int count_row)
{
	int i;

	i = -1;
	while (++i < count_row)
		free((*matrix)[i]);
	free(*matrix);
	*matrix = NULL;
}
