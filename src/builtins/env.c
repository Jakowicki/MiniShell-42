#include "minishell.h"

char	*ft_extract_key(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (smieciarz(ft_substr(str, 0, i), false));
		i++;
	}
	return (ft_strdup(str));
}

char	*ft_extract_value(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			i++;
			return (smieciarz(	
					ft_substr(str, i, ft_strlen(str) - 1), false));
		}
		i++;
	}
	return (NULL);
}

void	ft_init_envlst(void)
{
	int		i;
	char	**enviro;
	char	*key;
	char	*value;

	enviro = g_minishell.enviro;
	if (!enviro)
		return ;
	i = 0;
	while (enviro[i])
	{
		key = ft_extract_key(enviro[i]);
		value = ft_extract_value(enviro[i]);
		ft_update_envlst(key, value, true);
		i++;
	}
}