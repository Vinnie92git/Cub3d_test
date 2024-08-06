/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 07:25:54 by amanjon-          #+#    #+#             */
/*   Updated: 2024/07/24 10:26:12 by vini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <string.h>
# include <stdio.h>
# include <unistd.h>
// # include <xlocale.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../../Libft/include/libft.h"

char	*get_next_line(int fd);
size_t	ft_strlen_g(char *str);
char	*ft_strchr_g(char *s, int c);
char	*ft_strjoin_g(char *s1, char *s2);
char	*ft_join(char *dest, char *s1, char *s2);

#endif
