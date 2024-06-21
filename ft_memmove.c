/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelniko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:56:44 by amelniko          #+#    #+#             */
/*   Updated: 2024/06/20 11:56:46 by amelniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *mem_dest, const void *mem_src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			index;

	if (!mem_dest || !mem_src)
		return (NULL);
	dest = (unsigned char *) mem_dest;
	src = (unsigned char *) mem_src;
	index = n;
	if (mem_dest > mem_src)
	{
		while (index >= 0)
		{
			dest[index] = src[index];
			index--;
		}
	}
	else
		ft_memcpy(mem_dest, mem_src, n);
	return (mem_dest);
}
