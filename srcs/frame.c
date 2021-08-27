/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:54:42 by bahn              #+#    #+#             */
/*   Updated: 2021/08/27 20:52:53 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_frame	*frame_init(void)
{
	t_frame	*frame;

	frame = (t_frame *)malloc(sizeof(t_frame));
	if (frame == NULL)
		ft_puterr();
	frame->a = NULL;
	frame->b = NULL;
	frame->op_cnt = (t_op_cnt *)malloc(sizeof(t_op_cnt));
	if (frame->op_cnt == NULL)
		ft_puterr();
	frame->cmd = NULL;
	return (frame);
}

void	frame_free(t_frame *frame)
{
	void	*temp;

	while (frame->a != NULL)
	{
		temp = frame->a->next;
		free(frame->a);
		frame->a = temp;
	}
	while (frame->b != NULL)
	{
		temp = frame->b->next;
		free(frame->b);
		frame->b = temp;
	}
	if (frame->cmd != NULL)
		free(frame->cmd);
	free(frame);
}
