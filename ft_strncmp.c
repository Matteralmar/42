/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:57:48 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/14 16:01:47 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strcmp(char *s1, char *s2, unsigned int n)
{

    while(*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
        n--;
    }
    if(n == 0)
        return 0;
    return (unsigned char)*s1 - (unsigned char)*s2;

}

int main()
{
    char str1[] = "aahfdd";
    char str2[] = "aafsd";
    printf("%d",ft_strcmp(str1, str2, 3));
}