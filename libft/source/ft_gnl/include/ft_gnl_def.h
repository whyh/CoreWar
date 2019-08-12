/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:29:55 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/11 19:30:05 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_DEF_H

# define FT_GNL_DEF_H

# define FT_GNL_BUFF_SIZE 1000

typedef struct			s_gnl_list
{
	int					fd;
	char				*buff;
	struct s_gnl_list	*next;
}						t_gnl_list;

typedef struct			s_gnl_data
{
	t_gnl_list			*node;
	char				rbuff[FT_GNL_BUFF_SIZE + 1];
	ssize_t				rlen;
	ssize_t				len;
	char				*tmp;
	int					ret_flag;
}						t_gnl_data;

#endif
