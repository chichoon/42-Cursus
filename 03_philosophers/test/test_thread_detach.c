/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_thread_detach.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:25:21 by jiychoi           #+#    #+#             */
/*   Updated: 2021/08/06 10:47:55 by jiychoi          ###   ########.fr       */
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

void	*thread_func_2(void *data)
{
	int				index;
	t_thread_struct	*thread;

	index = -1;
	thread = (t_thread_struct *)data;
	while (++index < 10)
	{
		printf("%dth Thread %llu\t:\tindex %d\n",
			thread->index, (unsigned long long)thread->thread_id, index);
		sleep(1);
	}
	return (0);
}

void	*thread_func_1(void *data)
{
	int				index;
	int				thread_err;
	t_thread_struct	*thread_data;

	index = -1;
	thread_data = (t_thread_struct *)data;
	while (++index < 10)
	{
		thread_data[index].index = index;
		thread_err = pthread_create(&thread_data[index].thread_id, NULL,
				thread_func_2, (void *)&thread_data[index]);
		if (thread_err < 0)
			exit(0);
		printf("Sub thread %d created.\n", index);
	}
	index = -1;
	while (++index < 10)
	{
		pthread_detach(thread_data[index].thread_id);
		printf("Thread index %d detached.\n", index);
	}
	printf("Parent thread died. byebye...\n");
	return (0);
}

int	main(void)
{
	t_thread_struct	threads[10];
	pthread_t		thread_id;
	int				thread_err;

	printf("this is main thread\n");
	thread_id = 0;
	thread_err = pthread_create(&thread_id, NULL,
			thread_func_1, (void *)threads);
	if (thread_err < 0)
		exit(0);
	printf("Parent thread created.\n");
	pthread_detach(thread_id);
	printf("All the threads call finished\n");
	while (1)
		;
}
