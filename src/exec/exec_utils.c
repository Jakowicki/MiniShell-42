#include "minishell.h"

static void ft_del(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	*smieciarz(void *ptr, bool clean)
{
	static t_list	*kosz_list;

	if (clean)
	{
		ft_lstclear(&kosz_list, ft_del);
		return (NULL);
	}
	else
	{
		ft_lstadd_back(&kosz_list, ft_lstnew(ptr));
		return (ptr);
	}
}