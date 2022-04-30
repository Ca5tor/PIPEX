/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltacos <ltacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:25:16 by ltacos            #+#    #+#             */
/*   Updated: 2022/04/26 15:54:00 by ltacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	podshet_civerok(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i += 1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		vsego_ciferok;
	char	*p_str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	vsego_ciferok = podshet_civerok(n);
	p_str = (char *)malloc(vsego_ciferok + 1);
	if (!p_str)
		return (NULL);
	p_str[vsego_ciferok] = '\0';
	if (n < 0)
	{
		p_str[0] = '-';
		n = -n;
	}
	while (n > 0 && vsego_ciferok--)
	{
		p_str[vsego_ciferok] = '0' + (n % 10);
		n /= 10;
	}
	return (p_str);
}
