/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltacos <ltacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:28:25 by ltacos            #+#    #+#             */
/*   Updated: 2021/11/09 17:28:25 by ltacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		n1;
	int		n2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	str = (char *)malloc(n1 + n2 + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < n1)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < n2 + 1)
	{
		str[n1 + i] = s2[i];
		i++;
	}
	return (str);
}
