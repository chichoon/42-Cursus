# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 13:27:36 by jiychoi           #+#    #+#              #
#    Updated: 2021/05/21 01:05:37 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -o test  ft_printf_csp_0.c ft_printf_csp_1.c ft_printf_csp_2.c ft_printf_csp_3.c ft_printf_diux_0.c ft_printf_diux_1.c ft_printf_diux_2.c ft_printf_utils1.c ft_printf_utils2.c ft_printf_utils3.c ft_printf_fmt.c ft_printf.c -g -I printft.h
./test
while true
do
	echo -e "need debug? (y/n)"

	read answer
	if [ ${answer} == "y" ]
	then
		lldb test
		rm -rf test.dSYM
		rm test
		break
	elif [ ${answer} == "n" ]
	then
		rm -rf test.dSYM
		rm test
		break
	fi
done
