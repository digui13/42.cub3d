/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:04:05 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/08 20:52:33 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

char	*my_strndup(const char *s, int qty)
{
	char	*p;
	int		cnt;

	p = (char *)malloc(qty + 1);
	cnt = 0;
	if (p == NULL)
		return (NULL);
	while (cnt < qty)
	{
		*(p + cnt) = *(s + cnt);
		cnt++;
	}
	*(p + cnt) = '\0';
	return (p);
}

int	my_strcmp(char *s1, char *s2)
{
	int	inc;

	inc = 0;
	while (*(s1 + inc) == *(s2 + inc))
	{
		if (*(s1 + inc) == '\0')
			return (0);
		inc++;
	}
	return (*(s1 + inc) - *(s2 + inc));
}
