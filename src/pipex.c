/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:36:05 by frlorenz          #+#    #+#             */
/*   Updated: 2025/01/29 12:04:01 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void main_process(char **argv, int *pipe, char **envp, int status);
void process_out(int *fd, char **argv, char **envp);
void process_in(int *fd, char **argv, char **envp);

int main(int argc, char **argv, char **envp)
{
    int fd[2];
    int   status;
    
    status = 0;
    if (argc == 5)
    {
        if (pipe(fd) == -1)
            exit_error();
        main_process(argv, fd, envp, status);
    }
    else
    {
        custom_error("Error", "Wrong number of arguments");
        exit(EXIT_FAILURE);
    }
    return (0);
}

void    main_process(char **argv, int *pipe, char **envp, int status)
{
    pid_t pid_one;
    pid_t pid_two;

    pid_one = fork();
    if (pid_one == -1)
        exit_error();
    else if (pid_one == 0)
        process_in(pipe, argv, envp);
    else if (pid_one > 0)
    {
        pid_two = fork();
        close(pipe[1]);
        if (pid_two == -1)
            exit_error();
        else if (pid_two == 0)
            process_out(pipe, argv, envp);
        else if (pid_two > 0)
        {
            close(pipe[0]);
            waitpid(pid_two, &status, 0);
            waitpid(pid_one, &status, 0);
        }
    }

}

void process_out(int *fd, char **argv, char **envp)
{
    int fd_out;

    fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd_out == -1)
        exit_error();
    dup2(fd[0], STDIN_FILENO);
    dup2(fd_out, STDOUT_FILENO);
    close(fd_out);
    run_cmd(argv[3], envp);
}

void process_in(int *fd, char **argv, char **envp)
{
    int fd_in;

    fd_in = open(argv[1], O_RDONLY, 0777);
    if (fd_in == -1)
        exit_error();
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    dup2(fd_in, STDIN_FILENO);
    close(fd_in);
    run_cmd(argv[2], envp);
}
