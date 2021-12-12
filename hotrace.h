/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:46:57 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/12 18:46:29 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include "get_next_line.h"

# define KEYWORD 0
# define VALUE 1
# define CAPACITY 4294967

typedef struct s_ht_item
{
	char	*key;
	char	*value;
}	t_ht_item;

typedef struct s_bucket
{
	t_ht_item		*item;
	struct s_bucket	*next;
}	t_bucket;

typedef struct s_hashtable
{
	t_ht_item	**items;
	t_bucket	**buckets;
	int			size;
	int			count;
}	t_hashtable;

/*
** Utils
*/
int				ft_strncmp(const char *str1, const char *str2, size_t count);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_bzero(void *b, size_t len);
void			ft_putstr(char *str);
int				ft_strlen(char *str);

/*
** Free
*/
void			free_table(t_hashtable *table);
void			free_buckets_arrays(t_hashtable *table);
void			free_buckets(t_bucket *list);
void			free_item(t_ht_item *item);
t_ht_item		*bucket_remove(t_bucket *list);

/*
** Search
*/
void			search_datas(t_hashtable *table);
void			print_search(t_hashtable *table, char *key);
char			*hashtable_search(t_hashtable *table, char *key);

/*
** Hash
*/
unsigned long	hash_function(char *str);

/*
** Create
*/
t_hashtable		*create_table(int size);
t_bucket		**create_buckets(t_hashtable *table);
t_ht_item		*create_item(char *key, char *value);

/*
** Insert
*/
void			ht_insert(t_hashtable *table, char *key, char *value);
t_bucket		*bucket_insert(t_bucket *list, t_ht_item *item);

/*
** Bucket
*/
t_bucket		*allocate_bucket(void);
t_bucket		*init_bucket(t_bucket *new, t_ht_item *item);

#endif
