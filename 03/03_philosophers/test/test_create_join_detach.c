/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_create_join_detach.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:02:52 by jiychoi           #+#    #+#             */
/*   Updated: 2021/08/06 15:45:22 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<pthread.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>

typedef struct s_thread_struct
{
	pthread_t	thread_id;
	int			index;
	int			value;
}				t_thread_struct;

void	*thread_function(void *param)
{
	int				index;
	t_thread_struct	*data;

	index = 0;
	data = (t_thread_struct *)param;
	while (index < 10)
	{
		printf("%dth Thread %llu\t:\tindex %d\n",
			data->index, (unsigned long long)data->thread_id, index++);
		sleep(1);
	}
	return (0);
}

int	main(void)
{
	t_thread_struct	threads[10];
	int				index;
	int				thread_err;

	index = -1;
	while (++index < 10)
	{
		threads[index].index = index;
		thread_err = pthread_create(&threads[index].thread_id, NULL,
				thread_function, (void *)&threads[index]);
		printf("Thread index %d created\n", index);
		if (thread_err < 0)
			exit(0);
	}
	index = -1;
	while (++index < 10)
	{
		pthread_join(threads[index].thread_id,
			(void **)&(threads[index].value));
		printf("Thread index %d joined\n", index);
	}
	printf("All the threads call finished\n");
	exit(0);
}
