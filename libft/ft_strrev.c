/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:18:23 by ppanchen          #+#    #+#             */
/*   Updated: 2016/11/30 16:19:22 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	*rev;

	rev = (char *)malloc(ft_strlen(str) + 1);
	if (!rev)
		return (0);
	j = ft_strlen(str);
	i = 0;
	while (j > 0)
	{
		rev[i] = str[j - 1];
		i++;
		j--;
	}
	rev[i] = 0;
	return (rev);
}
