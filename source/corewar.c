/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:22:00 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/25 16:16:09 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

void		corewar_dump(const unsigned char *arena, t_vis *vis)
{
	unsigned int	i;

	if (vis)
		return ;
	i = 0;
	while (i < ARENA_SIZE)
	{
		if (!i)
			ft_printf("[red0x~][yellow0000~] [red:~] ");
		else if (!(i % DUMP_BYTES_PER_LINE))
			ft_printf("[red0x~][yellow%04x~] [red:~] ", i);
		if (arena[i] != 0 && arena[i] < 16)
			ft_printf("[green0%x~]", arena[i]);
		else if (arena[i] != 0)
			ft_printf("[green%x~]", arena[i]);
		else
			ft_printf("[cyan00~]");
		if (!((i + 1) % DUMP_BYTES_PER_LINE))
			ft_printf("\n");
		else
			ft_printf(" ");
		++i;
	}
}

static void	static_introduction(t_parse *parse)
{
	unsigned int	i;

	ft_printf("[greenIntroducing contestants...~]\n");
	i = 0;
	while (i < parse->n_champs)
	{
		ft_printf("[red*~] [yellowPlayer %u~][red,~]", parse->champs[i].id);
		ft_printf("[yellow weighing %u bytes~][red,~]",
		parse->champs[i].code_size);
		ft_printf(" [yellow%s~]", parse->champs[i].name);
		ft_printf(" [red\"~][green%s~][red\"~] [red!~]\n",
		parse->champs[i].comment);
		++i;
	}
}

static void	static_print_usage(void)
{
	ft_printf("[greenUsage:~] [cyan./corewar~] [red-v~][yellow %s %s %s~]\n",
	"champ/ChinaWall.cor", "champ/helltrain.cor", "champ/toto.cor");
}

int			main(int argc, char **argv)
{
	t_parse	parse;
	t_data	data;
	t_vis	vis;

	if (!corewar_parse(&parse, (unsigned int)argc, (const char **)argv))
	{
		static_print_usage();
		corewar_exit(&parse, NULL, NULL);
		return (false);
	}
	if (parse.vis)
	{
		if (!corewar_vis_init(&vis))
		{
			corewar_exit(&parse, NULL, &vis);
			return (false);
		}
		corewar_vm(&data, &parse, &vis);
		corewar_exit(&parse, &data, &vis);
		return (true);
	}
	static_introduction(&parse);
	corewar_vm(&data, &parse, NULL);
	corewar_exit(&parse, &data, NULL);
	return (true);
}
