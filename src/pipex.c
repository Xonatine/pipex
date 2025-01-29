/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:36:05 by frlorenz          #+#    #+#             */
/*   Updated: 2025/01/29 11:32:50 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void main_process(int *fd, char **argv, char **envp);
void sub_process(int *fd, char **argv, char **envp);

int main(int argc, char **argv, char **envp)
{
    int fd[2];
    int   pid;
    
    if (argc == 5)
    {
        if (pipe(fd) == 1)
            exit_error();
        pid = fork();
        if (pid == -1)
            exit_error();
        if (pid == 0)
            sub_process(fd, argv, envp);
        waitpid(pid, NULL, 0);
        main_process(fd, argv, envp);
    }
    else
    {
        custom_error("Error", "Wrong number of arguments");
        exit(1);
    }
    return (0);
}

void main_process(int *fd, char **argv, char **envp)
{
    int fd_out;

    fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd_out == -1)
        exit_error();
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    dup2(fd_out, STDOUT_FILENO);
    run_cmd(argv[3], envp);
}

void sub_process(int *fd, char **argv, char **envp)
{
    int fd_in;

    fd_in = open(argv[1], O_RDONLY, 0777);
    if (fd_in == -1)
        exit_error();
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    dup2(fd_in, STDIN_FILENO);
    run_cmd(argv[2], envp);
}