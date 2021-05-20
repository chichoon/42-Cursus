# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 13:27:36 by jiychoi           #+#    #+#              #
#    Updated: 2021/05/20 13:28:14 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -o test -Wall -Wextra -Werror ft_printf_printing1.c ft_printf_printing2.c ft_printf_printing3.c ft_printf_utils1.c ft_printf_utils2.c ft_printf_utils3.c ft_printf_params_1.c ft_printf_params_2.c ft_printf_fmt.c ft_printf.c -g -I printft.h
