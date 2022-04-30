/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:21:10 by marvin            #+#    #+#             */
/*   Updated: 2021/11/03 22:21:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*t_src;

	i = 0;
	t_src = (unsigned char *)src;
	while (i < n)
	{
		if (t_src[i] == (unsigned char)c)
			return (t_src + i);
		i++;
	}
	return (0);
}
