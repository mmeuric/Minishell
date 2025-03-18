/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:35:56 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 23:35:57 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	count_words(char const *s, char c)
{
	int	in_word;
	int	i;
	int	count;

	in_word = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (in_word && s[i] == c)
			in_word = 0;
		else if (!in_word && s[i] != c)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static int	word_len(char const *ptr, char c)
{
	int	len;

	len = 0;
	while (ptr[len] && ptr[len] != c)
		len++;
	return (len);
}

static char	*create_str(char const *word_start, char c)
{
	char	*str;

	str = ft_malloc(word_len(word_start, c) + 1);
	if (str)
		ft_strlcpy(str, word_start, word_len(word_start, c) + 1);
	return (str);
}

static int	fill_target(char const *s, char c, char **target, int word_count)
{
	int		i;
	int		in_word;
	int		target_i;

	i = 0;
	target_i = 0;
	in_word = 0;
	while (s[i] && target_i < word_count)
	{
		if (s[i] == c)
			in_word = 0;
		else if (!in_word && s[i] != c)
		{
			in_word = 1;
			target[target_i++] = create_str(s + i, c);
			if (target[target_i - 1] == NULL)
			{
				while (target_i--)
					free(target[target_i]);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**target;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	target = ft_malloc((word_count + 1) * sizeof(char *));
	if (!target)
		return (NULL);
	if (!fill_target(s, c, target, word_count))
	{
		free(target);
		return (NULL);
	}
	target[word_count] = 0;
	return (target);
}
