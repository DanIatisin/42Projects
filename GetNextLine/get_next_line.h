/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <diatisin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:15:12 by diatisin          #+#    #+#             */
/*   Updated: 2026/07/30 11:11:08 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

char    *get_next_line(int fd);
char    *ft_strjoin(const char *s1, const char *s2);
char    *ft_strchr(const char *s, int c);
char    *ft_strdup(const char *s);
size_t  ft_strlen(const char *s);

#endif