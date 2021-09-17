/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:41:15 by jiychoi           #+#    #+#             */
/*   Updated: 2021/08/07 20:33:19 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<pthread.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>

typedef struct s_thread_struct
{
	pthread_t		thread_id;
	int				index;
	pthread_mutex_t	*mutex;
	int				value;
}				t_thread_struct;

void	*thread_function(void *param)
{
	int				index;
	t_thread_struct	*data;

	index = -1;
	data = (t_thread_struct *)param;
	printf("Mutex lock ->\n");
	pthread_mutex_lock(data->mutex);
	while (++index < 10)
	{
		printf("%dth Thread %llu\t:\tindex %d\n",
			data->index, (unsigned long long)data->thread_id, index);
		sleep(1);
	}
	pthread_mutex_unlock(data->mutex);
	printf("<- Mutex unlocked by %dth thread\n", data->index);
	return (0);
}

int	main(void)
{
	t_thread_struct	threads[10];
	pthread_mutex_t	*mutex;
	int				thread_err;
	int				index;

	index = -1;
	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mutex, NULL);
	while (++index < 10)
	{
		threads[index].index = index;
		threads[index].mutex = mutex;
		thread_err = pthread_create(&threads[index].thread_id, NULL,
				thread_function, (void *)&threads[index]);
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
	printf("All the threads call finished");
}
