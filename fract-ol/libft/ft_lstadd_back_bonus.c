/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:07:00 by gvasylie          #+#    #+#             */
/*   Updated: 2025/05/29 13:07:00 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!alst || !new)
		return ;
	last = ft_lstlast(*alst);
	if (!last)
		*alst = new;
	else
		last->next = new;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 

typedef struct s_list {
    char *content;
    struct s_list *next;
} t_list;

void    free_content(void *content)
{
    free(content);
}

void    ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (!lst || !del)
        return ;
    del(lst->content);
    free(lst);
}

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list    *tmp;

    if (!lst || !del)
        return ;
    while (*lst)
    {
        tmp = (*lst)->next;
        ft_lstdelone(*lst, del);
        *lst = tmp;
    }
    *lst = NULL;
}

t_list    *ft_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

void    ft_lstadd_back(t_list **alst, t_list *new)
{
    t_list    *last;

    if (!alst || !new)
        return ;
    last = ft_lstlast(*alst);
    if (!last)
        *alst = new;
    else
        last->next = new;
}

void ft_lstadd_front(t_list **alst, t_list *new)
{
    new->next = *alst;
    *alst = new;
}

int    ft_lstsize(t_list *lst)
{
    int        i;

    i = 0;
    while (lst)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}

t_list    *ft_lstnew(void *content)
{
    t_list    *new;

    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

void    write_first_byte(void *b)
{
    unsigned char *tmp;
    tmp = (unsigned char *)b;
    write(1, tmp, 1);
}

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    while (lst)
    {
        f(lst->content);
        lst = lst->next;
    }
}

int main() {
  
    t_list *tmp;
    t_list *head;

    int *c1 = malloc(sizeof(int));
    if (!c1) exit(1);
    *c1 = 72;

    int *c2 = malloc(sizeof(int));
    if (!c2) exit(1);
    *c2 = 101;

    char *c3 = malloc(strlen("yep") + 1);
    if (!c3) exit(1);
    strcpy(c3, "yep");
    
    tmp = ft_lstnew(c1);
    head = ft_lstnew(c2);

    ft_lstadd_front(&head, tmp);
    tmp = ft_lstnew(c3);
    ft_lstadd_back(&head, tmp);
    tmp = NULL;
    ft_lstiter(head, write_first_byte);

    printf("\nFirst node content: %d\n", *(int *)(head->content));
    printf("Second node content: %c\n", *(char *)(head->next->content));
    printf("Third node content: %s\n", head->next->next->content);
    printf("Size: %d\n", ft_lstsize(head));
    ft_lstclear(&head, free_content);
    return 0;
}

*/