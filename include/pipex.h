/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:40:13 by frlorenz          #+#    #+#             */
/*   Updated: 2025/01/23 11:44:41 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PIPEX_H
# define PIPEX_H

# include "../lib/libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>

void run_cmd(char *cmd, char **envp);
char *get_cmd_path(char *cmd, char **envp);
void free_split(char **str);
void exit_error(void);
void custom_error(char *header, char *msg);
void check_envp(char **envp);
void sub_process(int *fd, char **argv, char **envp);
void main_process(int *fd, char **argv, char **envp);

#endif