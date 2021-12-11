#include "hotrace.h"

typedef struct s_data
{
    char             *keyword;
    char             *value;
    struct s_data    *next;
} t_data;



int get_datas(t_data **data)
{
    char    c;
    char    *line;
	int		

    c = '\0';
    while (get_next_line(0, &line) > 0)
    {
        printf("line = %s\n", line);

    }
}

int main(int ac, char **av)
{
    t_data *data;
    (void)ac;
    (void)av;

    data = NULL;
    get_datas(&data);
    return (0);
}
