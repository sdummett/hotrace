/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:43:56 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/12 00:13:33 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
 
typedef struct s_ht_item {
    char*	key;
    char*	value;
} t_ht_item;
 
typedef struct s_hashtable {
    t_ht_item**	items;
    int			size;
    int			count;
} t_hashtable;

typedef struct s_alpha_table
{
	t_hashtable *table;
} t_alpha_table;

int ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_bzero(void *b, size_t len)
{
	while (len)
	{
		*(unsigned char *)b = 0;
		b++;
		len--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(size * nmemb);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void print_alpha_table(t_alpha_table *alpha_table)
{
	unsigned int	i;

	i = 0;
	while (i < ALPHA_TABLE_SIZE)
	{
		printf("%p\n", alpha_table[i].table);
		i++;
	}
}
void	init_alpha_table(t_alpha_table *alpha_table)
{
	unsigned int	i;

	i = 0;
	while (i < ALPHA_TABLE_SIZE)
	{
		alpha_table[i].table = NULL;
		i++;
	}
}

unsigned long hash_function(char* str) 
{
    unsigned long	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		i = i + str[j];
		j++;
	}
	return (i % CAPACITY);
}

void free_item(t_ht_item* item)
{
    free(item->key);
    free(item->value);
    free(item);
}
 
void free_table(t_hashtable* table)
{
	int	i;

	i = 0;
	while (i < table->size)
	{
        if (table->items[i] != NULL)
            free_item(table->items[i]);
		i++;
	}
    free(table->items);
    free(table);
}

t_ht_item* create_item(char* key, char* value)
{
    t_ht_item*	item;
	
	item = (t_ht_item*)malloc(sizeof(t_ht_item));
	item->key = key;
	item->value = value;
    return (item);
}

t_hashtable* create_table(int size)
{
	int				i;
    t_hashtable*	table;
	
	table = (t_hashtable*)malloc(sizeof(t_hashtable));
    table->size = size;
    table->count = 0;
    table->items = (t_ht_item**) ft_calloc(table->size, sizeof(t_ht_item*));
    i = 0;
	while(i < table->size)
	{
		table->items[i] = NULL;
		i++;
	}
	return (table);
}

int	ft_strncmp(const char *str1, const char *str2, size_t count)
{
	if (!count)
		return (0);
	while (--count && *str1)
	{
		if (*str1 != *str2)
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

void handle_collision(t_hashtable *table, t_ht_item *item)
{
	(void)table;
	(void)item;
	ft_putstr("Collision detected\n");
}

void ht_insert(t_hashtable* table, char* key, char* value)
{
	t_ht_item*	item;
	t_ht_item*	current_item;
	int			index;
	
	item = create_item(key, value);
	index = hash_function(key);
	printf("Hash is %d before inserting \n", index);
	current_item = table->items[index];
	if (current_item == NULL)
	{
		if (table->count == table->size)
		{
			ft_putstr("Insert Error: Hash Table is full\n");
			free_item(item);
			return;
		}
		table->items[index] = item; 
		table->count++;
	}
	else
	{
			if (ft_strncmp(current_item->key, key, ft_strlen(key)) == 0)
			{
				free(table->items[index]->value);
				table->items[index]->value = value;
				return;
			}
		else
		{
			handle_collision(table, item);
			return;
		}
	}
}

char	*hashtable_search(t_hashtable* table, char* key)
{
    int index;
    t_ht_item* item;
	
	if (table == NULL)
		return (NULL);
	index = hash_function(key);
	item = table->items[index];
    if (item != NULL)
	{
        if (ft_strncmp(item->key, key, ft_strlen(key)) == 0)
            return (item->value);
    }
    return NULL;
}

void print_search(t_hashtable* table, char* key)
{
    char* val;

	if (table == NULL)
		printf("Key:%s does not exist\n", key);
    if ((val = hashtable_search(table, key)) == NULL)
	{
        printf("Key:%s does not exist\n", key);
        return;
    }
    else
        printf("Key:%s, Value:%s\n", key, val);
}
 
void print_table(t_hashtable* table)
{
    printf("\nHash Table\n-------------------\n");
    for (int i=0; i<table->size; i++) {
        if (table->items[i]) {
            printf("Index:%d, Key:%s, Value:%s\n", i, table->items[i]->key, table->items[i]->value);
        }
    }
    printf("-------------------\n\n");
}

int get_datas(t_alpha_table *alpha_table)
{
    char    *line;
	char	*key;
	int		type;

	type = KEYWORD;
	printf("Entering get_datas...\n");
    while (get_next_line(0, &line) > 0)
    {
		if (ft_strlen(line) == 0)
	   	{
			free(line);
			break ;
		}
		if (type == KEYWORD)
		{
			if (alpha_table[(unsigned int)line[0]].table == NULL)
				alpha_table[(unsigned int)line[0]].table = create_table(CAPACITY);
			printf("hash is %lu\n", hash_function(line));
			key = line;
			type = VALUE;
		}
		else if (type == VALUE)
		{
			//printf("hash is %lu\n", hash_function(line));
			ht_insert(alpha_table[(unsigned int)key[0]].table, key, line);
			type = KEYWORD;
		}
    }
	return (0);
}

void search_datas(t_alpha_table *alpha_table)
{
	char    *line;

	printf("Entering search_datas...\n");
    while (get_next_line(0, &line) > 0)
    {
		print_search(alpha_table[(unsigned int)line[0]].table, line);
    }
}

int main(void)
{
	t_alpha_table alpha_table[ALPHA_TABLE_SIZE];
	init_alpha_table(alpha_table);
	print_alpha_table(alpha_table);
	get_datas(alpha_table);
	search_datas(alpha_table);
	return (0);
}
