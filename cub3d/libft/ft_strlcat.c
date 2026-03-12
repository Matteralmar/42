/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 00:04:03 by anezkahavra       #+#    #+#             */
/*   Updated: 2024/06/25 17:27:00 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	total;
	int		srcsize;
	int		dstlen;

	srcsize = ft_strlen(src);
	if (dstsize > ft_strlen(dst))
		dstlen = ft_strlen(dst);
	else
		dstlen = dstsize;
	total = dstlen + srcsize + 1;
	if (dstsize == 0 || dstsize < (unsigned int)dstlen)
		return (ft_strlen(src) + dstsize);
	if (total >= dstsize)
		srcsize = dstsize - dstlen - 1;
	if (srcsize > 0)
		ft_strlcpy(dst + dstlen, src, srcsize + 1);
	return (total - 1);
}

/* int main(void)
{
    size_t dstsize = 7;
    char *dst = "hjakj";
    const char *src = "kja";
    printf("%zu", ft_strlcat(dst, src, dstsize));
    return (0);
} */
