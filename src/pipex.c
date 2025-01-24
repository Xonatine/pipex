/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:36:05 by frlorenz          #+#    #+#             */
/*   Updated: 2025/01/23 19:06:08 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int argc, char **argv, char **envp)
{
    int fd[2];
    int   pid;
    
    if (argc == 5)
    {
        pipe(fd);
        pid = fork(); //!!!!!controlar el -1 por si falla!!!!!
        if (pid == 0) //Codigo ejecutado por el HIJO 1
        {
            close(fd[1]); // cerrar el fd de lectura
            printf("HIJO 1 => %i\n", pid);
            exit(0); 
        }
        else //codigo ejecutado por el PADRE
        {
            close(fd[0]); //cerrar el fd de escritura
            printf("PADRE => %i\n", pid);
            pid = fork(); //!!!!!controlar el -1 por si falla!!!!!
            if (pid == 0)
            {
                close(fd[1]);// cerrar el fd de lectura
                printf("HIJO 2 => %i\n", pid);
                exit(0); 
            }
            else // codigo ejecutado por el PADRE
            {
                close(fd[0]);//cerrar el fd de escritura
                printf("PADRE => %i\n", pid);
            }
        }
    }
    else //tienen que ser 5 argumentos ERROR !!CAMBIAR!!
    {
        ft_printf("%s\n", argv[0]);
        ft_printf("%s\n", envp[1]);
        /*while(*envp)
            ft_printf("%s\n", *envp++);*/
    }
    return (0);
}
