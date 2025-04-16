/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:01:36 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/14 18:04:02 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
    {
        i++;
    }
    while (src[j] != '\0' && j < nb)
    {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';

    return dest;
}

int main()
{
    char str1[100] = "aahfdd";
    char str2[] = "aafsd";

    char *result = ft_strncat(str1, str2, 3);

    printf("Result: %s\n", result);

    return 0;
}