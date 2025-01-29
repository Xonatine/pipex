/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:21:32 by frlorenz          #+#    #+#             */
/*   Updated: 2025/01/29 12:40:30 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../include/pipex.h"

void exit_error(void)
{
    perror("ERROR");
    exit(EXIT_FAILURE);
}

void custom_error(char *header, char *msg)
{
    ft_putstr_fd(header, 2);
    ft_putstr_fd(": ", 2);
    ft_putstr_fd(msg, 2);
    ft_putstr_fd("\n", 2);
}

void free_split(char **str)
{
    int i;

    i = 0;
    while (str[i])
        free(str[i++]);
    free(str);
}

char *get_cmd(char *cmd, char **envp)
{
    char    **envp_paths;
    char    *path;
    char    *cmd_path;
    int     i;
    
    i = 0;
    while (!ft_strnstr(envp[i], "PATH=", 5))
        i++;
    envp_paths = ft_split(envp[i] + 5, ':');
    i = -1;
    while (envp_paths[++i])
    {
        path = ft_strjoin(envp_paths[i], "/");
        cmd_path = ft_strjoin(path, cmd);
        free(path);
        if (access (cmd_path, F_OK) == 0)
        {
            free_split(envp_paths);
            return (cmd_path);
        }
        free(cmd_path);
    }
    free_split(envp_paths);
    custom_error(cmd, "command not found");
    return (NULL);
}

void run_cmd(char *cmd, char **envp)
{
    char    **cmd_flags;
    char    *path;

    cmd_flags = ft_split(cmd, ' ');
    path = get_cmd(cmd_flags[0], envp);
    if (!path)
    {
        free_split(cmd_flags);
        free(path);
        exit(127);
    }
    if (execve(path, cmd_flags, envp) == -1)
    {
        free_split(cmd_flags);
        free (path);
        exit_error();
    }
}