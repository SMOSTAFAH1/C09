/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shashemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:41:37 by shashemi          #+#    #+#             */
/*   Updated: 2024/08/28 09:41:39 by shashemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	char_is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (c == 0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (char_is_separator(str[i + 1], charset) == 1
			&& char_is_separator(str[i], charset) == 0)
			words++;
		i++;
	}
	return (words);
}

void	write_word(char *dest, char *from, char *charset)
{
	int	i;

	i = 0;
	while (char_is_separator(from[i], charset) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = 0;
}

void	write_split(char **split, char *str, char *charset)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (char_is_separator(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (char_is_separator(str[i + j], charset) == 0)
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			write_word(split[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		words;

	words = count_words(str, charset);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	res[words] = 0;
	write_split(res, str, charset);
	return (res);
}

/*
#include <stdio.h>

int main() {
	char *str = "Hola,esto-es-una,prueba";
	char *charset = ",-";
	char **result = ft_split(str, charset);
	
	int i = 0;
	while (result[i]) {
		printf("%s ", result[i]);
		i++;
	}
	i = 0;
	while (result[i]) {
		free(result[i]);
		i++;
	}
	free(result);
	return 0;
}
*/