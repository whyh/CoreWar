/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 15:34:32 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/17 18:53:19 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar_parse.h"

static bool	static_extension(const char *file)
{
	size_t	i;

	i = ft_strlen(file);
	if (file[i - 4] != '.' || file[i - 3] != 'c' || file[i - 2] != 'o'
	|| file[i - 1] != 'r')
	{
		ft_printf("[redError:~] Invalid extension of a champion ");
		return (false);
	}
	return (true);
}

static bool	static_valid(t_parse *parse)
{
	unsigned int	i;

	if (parse->n_champs < MIN_CHAMPIONS)
	{
		ft_printf("[redError:~] Less than [yellow%u~] champions specified\n",
		MIN_CHAMPIONS);
		return (false);
	}
	i = 0;
	while (i < parse->n_champs)
	{
		if (!parse->champs[i].id)
		{
			ft_printf("[redError:~] %s\n",
			"Champions were not specified in the right order");
			return (false);
		}
		++i;
	}
	return (true);
}

static bool	static_pos(t_parse *parse)
{
	unsigned int i;

	if (!parse->pos)
	{
		i = 0;
		while (parse->champs[i].id != 0 && i < MAX_CHAMPIONS)
			++i;
		if (i == MAX_CHAMPIONS)
		{
			ft_printf("[redError:~] More than [yellow%u~] champions specified ",
			MAX_CHAMPIONS);
			return (false);
		}
		parse->pos = i + 1;
	}
	else
	{
		if (parse->champs[parse->pos - 1].id)
		{
			ft_printf("[redError:~] Specified position is already occupied ");
			return (false);
		}
	}
	parse->champs[parse->pos - 1].id = parse->pos;
	return (true);
}

static void	static_init(t_parse *parse)
{
	unsigned int	i;

	i = 0;
	while (i < MAX_CHAMPIONS)
	{
		parse->champs[i].id = 0;
		parse->champs[i].code_size = 0;
		parse->champs[i].code = NULL;
		++i;
	}
	parse->vis = false;
	parse->dump = 0;
	parse->pos = 0;
	parse->n_champs = 0;
}

bool		corewar_parse(t_parse *parse, unsigned int argc, const char **argv)
{
	unsigned int	i;

	static_init(parse);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (!corewar_parse_options(parse, argv, &i))
				return (0);
			++i;
		}
		else
		{
			if (!static_extension(argv[i]) || !static_pos(parse)
			|| !corewar_parse_champion(parse, argv[i]))
			{
				ft_printf("[yellowFile %s~]\n", argv[i]);
				return (0);
			}
			parse->n_champs++;
		}
		++i;
	}
	return (static_valid(parse));
}
