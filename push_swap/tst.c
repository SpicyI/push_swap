#include "./libft/libft.h"

int main(void)
{
    t_list **a;
    t_list *b;
    int h= 5;
    int *k;
    
    k = malloc(sizeof(int) * 1);
    k[0] = 5;
    b = ft_lstnew(k);
    *a = b;
    printf("%d\n",(*a)->content);
}