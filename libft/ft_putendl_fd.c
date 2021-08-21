/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 14:23:07 by bahn              #+#    #+#             */
/*   Updated: 2021/08/21 12:04:55 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *c, int fd)
{
	if (fd < 0)
		return ;
	ft_putstr_fd(c, fd);
	ft_putchar_fd('\n', fd);
}
