/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 02:52:02 by kkaneko           #+#    #+#             */
/*   Updated: 2022/06/05 01:30:28 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define ARG_ERR "Argument error\n"
# define SEND_ERR "Signal sending is failed\n"
# define INIT_ERR "Initialization is failed\n"
# define MALLOC_ERR "Allocation is failed\n"
# define PER_BYTE 8
# define STX 0x02
# define ETX 0x03
# define ACK 0x06
# define SLEEP_USEC 300
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# define INIT NULL

#endif
