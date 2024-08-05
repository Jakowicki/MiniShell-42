#include "../../includes/minishell.h"

void del(void *to_free)
{
    free(to_free);
    to_free = NULL;
}

void *GC_collector(void *list, bool free)
{
    static t_list *to_free;
    if(free){
        ft_lstclear(&to_free, del);
        return(NULL);
    }
    else{
        ft_lstadd_back(&to_free, ft_lstnew(list));
        return(list);
    }
}
