/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillv1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siosif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:01:39 by siosif            #+#    #+#             */
/*   Updated: 2018/01/05 19:32:01 by siosif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include <stdio.h>

void	ft_error(char *str)
{
	puts(str);
	exit(0);
}


void	ft_vecini(char *str)
{
	int i;
	int vecini;
	
	i = 0;
	vecini = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (str[i - 1] == '#' && (i - 1) >= 0)
				vecini++;
			if (str[i + 1] == '#')
				vecini++;
			if (str[i - 5] == '#' && (i - 5) >= 0)
				vecini++;
			if (str[i + 5] == '#' && (i + 5) <= 19)
				vecini++;
		}
		i++;
	}
	if (vecini != 6 && vecini != 8)
		ft_error("a13");
}

void	ft_rules(char *str, int j)
{	
	char	*tmp;
	int		i;
	int		count;

	tmp = ft_memalloc(21);
	tmp = ft_strncpy(tmp,(const char*)str,21);
	if (tmp[20] != '\n' && j == 0) 
			ft_error("a1");
	i = 0;
	count = 0;
	while (i < 20)
	{
		if (i == 4 || i == 9 || i == 14 || i == 19) 
		{	
			if (tmp[i] != '\n')
				ft_error("a2");
		}
		else if (tmp[i] != '#' && tmp[i] != '.')  
			ft_error("a3");
		if (tmp[i] == '#')
			count++;
		i++;
	}
	if (count != 4)
		ft_error("a4");
	ft_vecini(tmp);
}

void	ft_check(char *str)
{
	int i;
	int j;
	int len;
	int pieces;
	
	j = 0;
	i = 0; 
	len = ft_strlen(str) - 20;
	pieces = 1;
	if (len % 21 != 0)
		ft_error("a5");
	while (pieces <= (len / 21))
	{	
		ft_rules(str + i,j);
		i = i + 21;
		pieces++;
	}
	if (pieces == (len / 21 + 1))
	{
		j = 1;
		ft_rules(str+i, j);
	}
	printf("pieces = %d\n", pieces);
}



char	*ft_openread(char *argv)
{
	int		fd;
	int		i;
	int 	buff;
	char	tmp[560];
	
	if ((fd = open(argv, O_RDONLY)) < 0) 
		ft_error("a6");
	ft_bzero(tmp, 560);
	if ((buff = read(fd, tmp, 560)) < 0)
		ft_error("a7");	

	if (ft_strlen(tmp) > 545)  // error?? ??? ????
		ft_error("a8");
	return (ft_strdup(tmp));
}

int		main(int argc, char **argv)
{
	char	*read;

	if (argc != 2) 
		ft_error("a9"); // USAGE 
	read = ft_openread(argv[1]);
	ft_check(read);
	//puts(read);  // il scoti mai tarziu

	return (0);
}

