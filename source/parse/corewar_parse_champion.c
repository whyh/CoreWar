/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_parse_champion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 17:15:04 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/02 22:54:35 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fcntl.h"
#include "libft.h"
#include "corewar_parse.h"

static bool	static_parse_mode(t_parse *parse, const unsigned char *buff,
			char mode, unsigned int length)
{
	unsigned int	i;

	i = 0;
	while (i < length)
	{
		if (mode == MODE_MAGIC_HEADER
		&& ((MAGIC_HEADER >> (8 * (length - i - 1))) & 255) != buff[i])
			return (false);
		else if (mode == MODE_NAME)
			parse->champs[parse->pos - 1].name[i] = (char)buff[i];
		else if (mode == MODE_NULL
		&& ((MAGIC_NULL >> (8 * (length - i - 1))) & 255) != buff[i])
			return (false);
		else if (mode == CODE_SIZE_LENGTH)
			parse->champs[parse->pos - 1].code_size =
			parse->champs[parse->pos - 1].code_size << 8
			| (unsigned int)buff[i];
		else if (mode == MODE_COMMENT)
			parse->champs[parse->pos - 1].comment[i] = (char)buff[i];
		++i;
	}
	return (true);
}

static bool	static_parse(t_parse *parse, int fd)
{
	unsigned char	buff[MAGIC_HEADER_LENGTH];
	unsigned char	buff2[NAME_LENGTH];

	if (read(fd, &buff, MAGIC_HEADER_LENGTH) != MAGIC_HEADER_LENGTH
	|| !static_parse_mode(
	parse, buff, MODE_MAGIC_HEADER, MAGIC_HEADER_LENGTH))
	{
		ft_printf("[redError:~] Magic Header is invalid ");
		return (false);
	}
	if (read(fd, buff2, NAME_LENGTH) != NAME_LENGTH
	|| !static_parse_mode(parse, buff2, MODE_NAME, NAME_LENGTH))
	{
		ft_printf("[redError:~] Champion's name is invalid ");
		return (false);
	}
	return (true);
}

static bool	static_parse2(t_parse *parse, int fd)
{
	unsigned char	buff[MAGIC_NULL_LENGTH];
	unsigned char	buff2[CODE_SIZE_LENGTH];

	if (read(fd, buff, MAGIC_NULL_LENGTH) != MAGIC_NULL_LENGTH
	|| !static_parse_mode(parse, buff, MODE_NULL, MAGIC_NULL_LENGTH))
	{
		ft_printf("[redError:~] Magic Null after the name is invalid ");
		return (false);
	}
	if (read(fd, buff2, CODE_SIZE_LENGTH) != CODE_SIZE_LENGTH
	|| !static_parse_mode(
	parse, buff2, MODE_CODE_SIZE, CODE_SIZE_LENGTH)
	|| parse->champs[parse->pos - 1].code_size > CODE_LENGTH)
	{
		ft_printf("[redError:~] Champion's code size is invalid ");
		return (false);
	}
	return (true);
}

static bool	static_parse3(t_parse *parse, int fd)
{
	unsigned char	buff[COMMENT_LENGTH];
	unsigned char	buff2[MAGIC_NULL_LENGTH];

	if (read(fd, buff, COMMENT_LENGTH) != COMMENT_LENGTH
	|| !static_parse_mode(parse, buff, MODE_COMMENT, COMMENT_LENGTH))
	{
		ft_printf("[redError:~] Champion's comment is invalid ");
		return (false);
	}
	if (read(fd, buff2, MAGIC_NULL_LENGTH) != MAGIC_NULL_LENGTH
	|| !static_parse_mode(parse, buff2, MODE_NULL, MAGIC_NULL_LENGTH))
	{
		ft_printf("[redError:~] Magic Null after the comment is invalid ");
		return (false);
	}
	return (true);
}

bool		corewar_parse_champion(t_parse *parse, const char *file)
{
	t_champ	*champ;
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_printf("[redError:~] Can't open a file ");
		return (false);
	}
	if (!static_parse(parse, fd) || !static_parse2(parse, fd)
	|| !static_parse3(parse, fd))
		return (false);
	champ = &parse->champs[parse->pos - 1];
	champ->code = ft_memalloc(sizeof(unsigned char) * (champ->code_size + 1));
	if (read(fd, champ->code, champ->code_size + 1) != champ->code_size)
	{
		ft_printf("[redError:~] Champion's code size differs from specified ");
		return (false);
	}
	champ->code[champ->code_size] = '\0';
	parse->pos = 0;
	return (true);
}
