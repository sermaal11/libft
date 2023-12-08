/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:09:44 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/17 16:08:07 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	void 			*content;
	struct s_list 	*next;
}					t_list;

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_isalnum(int c)
{
	if ((c>= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = b;
	while (i < len)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return (s);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	i = 0;
	dst_ptr = (unsigned char *)dst;
	src_ptr = (const unsigned char *)src;
	if (dst_ptr == NULL && src_ptr == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*dst_ptr = *src_ptr;
		dst_ptr++;
		src_ptr++;
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d == s)
		return (dst);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d = d + len - 1;
		s = s + len - 1;
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	i = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	available_space;
	size_t	i;
	size_t	total_len;

	dst_len = 0;
	while (dst[dst_len] != '\0' && dst_len < dstsize)
	{
		dst_len++;
	}
	available_space = dstsize - dst_len;
	if (available_space > 1)
	{
		i = 0;
		while (src[i] != '\0' && i < available_space - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	total_len = dst_len + ft_strlen(src);
	return (total_len);
}

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 32;
		return (c);
	}
	else
		return (c);
}

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
		return (c);
	}
	else
		return (c);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last_occurrence = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (last_occurrence);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	p = s;
	i = 0;
	while (i < n)
	{
		if (*p == (unsigned char) c)
			return ((void *)p);
		p++;
		i++;
	}
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = s1;
	p2 = s2;
	i = 0;
	while (i < n)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	needle_len = ft_strlen(needle);
	i = 0;
	if (needle_len == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] && needle_len <= len - i)
	{
		if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
		|| str [i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = count * size;
	ptr = malloc(total_size);
	if (ptr != NULL)
	{
		ft_memset(ptr, 0, total_size);
	}
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;
	int		i;

	len = ft_strlen(s1);
	copy = (char *)malloc(len + 1);
	i = 0;
	if (copy == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub_s;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (start + len > s_len)
		len = s_len - start;
	sub_s = (char *)malloc((len + 1) * sizeof(char));
	if (sub_s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*final_s;

	s1_len = 0;
	s2_len = 0;
	if (s1 != NULL)
		s1_len = ft_strlen(s1);
	if (s2 != NULL)
		s2_len = ft_strlen(s2);
	final_s = (char *)malloc(s1_len + s2_len + 1);
	if (final_s == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_memcpy(final_s, s1, s1_len);
	if (s2 != NULL)
		ft_memcpy(final_s + s1_len, s2, s2_len);
	final_s[s1_len + s2_len] = '\0';
	return (final_s);
	free(final_s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	start;
	size_t	end;
	char	*sub_s;

	if (s1 == NULL || set == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
		start++;
	end = s1_len;
	while (end > start && ft_strchr(set, s1[end - 1]) != NULL)
		end--;
	sub_s = ft_substr(s1, start, end - start);
	return (sub_s);
}

// Funcion para contar palabras

size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (count);
}

// Funcion para conocer el inicio de mi palabra

size_t	get_init_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

// Funcion para liberar memoria

static void	free_memory(size_t i, char **str)
{
	while (i > 0)
	{
		i--;
		free(*(str + i));
	}
	free(str);
}

// funcion para hacer hacer split

static char	**to_split(const char *s, char c, char **str, size_t w_count)
{
	size_t	row;
	size_t	col;

	row = 0;
	col = 0;
	while (row < w_count)
	{
		while (*(s + col) != '\0' && *(s + col) == c)
		{
			col++;
		}
		*(str + row) = ft_substr(s, col, get_init_len(&*(s + col), c));
		if (*(str + row) == NULL)
		{
			free_memory(row, str);
			return (NULL);
		}
		while (*(s + col) != '\0' && *(s + col) != c)
		{
			col++;
		}
		row++;
	}
	*(str + row) = NULL;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	size_t	words;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	str = (char **)malloc((words + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	str = to_split(s, c, str, words);
	return (str);
}

static int	get_num_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = get_num_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

char ft_toupper_wrapper(unsigned int index, char c) 
{
  // Llamamos a ft_toupper y pasamos 'c' como argumento
	return (char)ft_toupper((int)c);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}

void print_index_and_char(unsigned int index, char *c)
{
	printf("Carácter en índice %u: %c\n", index, *c);
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = (n * (-1));
		}
		if (n < 10)
		{
			a = n + '0';
			write(fd, &a, 1);
		}
		else
		{
			ft_putnbr_fd((n / 10), fd);
			a = (n % 10) + '0';
			write(fd, &a, 1);
		}
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		count;

	count = 0;
	current = lst;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
	}
	current->next = new;
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL && del != NULL)
	{
		del(lst->content);
		free(lst);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

void multiply_by_two(void *data) 
{
    int *value = (int *)data;
    *value = (*value) * 2;
}

static void	del_wrapper(void *content)
{
	free(content);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*next_list;
	void	*v;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		v = f(lst->content);
		next_list = ft_lstnew(v);
		if (next_list == NULL)
		{
			del (v);
			ft_lstclear(&new_list, del_wrapper);
			return (NULL);
		}
		ft_lstadd_back(&new_list, next_list);
		lst = lst->next;
	}
	return (new_list);
}

void *multiply_by_two_wrapper(void *data)
{
    multiply_by_two(data);
    return data;
}


int	main(void)
{
	//ft_isalpha
	printf("\n");
	printf("ft_isalpha\n");
	printf("Esta funcion devuelve un 1 si el char es una letra y un 0 si no.\n");
	printf("Para un caracter 'a', el resultado es %d\n", ft_isalpha('a'));
	printf("Para un caracter 'A', el resultado es %d\n", ft_isalpha('A'));
	printf("Para un caracter '$', el resultado es %d\n", ft_isalpha('$'));
	printf("\n");

	//ft_isdigit

	printf("ft_isdigit\n");
	printf("Esta funcion devuelve un 1 si el char es un numero y un 0 si no.\n");
	printf("Para un caracter '1', el resultado es %d\n", ft_isdigit('1'));
	printf("Para un caracter '5', el resultado es %d\n", ft_isdigit('5'));
	printf("Para un caracter 'a', el resultado es %d\n", ft_isdigit('a'));
	printf("\n");

	//ft_isalnum
	
	printf("ft_isalnum\n");
	printf("Esta funcion devuelve un 1 si el char es alfanumerico y un 0 si no.\n");
	printf("Para un caracter '1', el resultado es %d\n", ft_isalnum('1'));
	printf("Para un caracter 'a', el resultado es %d\n", ft_isalnum('a'));
	printf("Para un caracter 'Z', el resultado es %d\n", ft_isalnum('Z'));
	printf("Para un caracter '$', el resultado es %d\n", ft_isalnum('$'));
	printf("\n");

	//ft_isascii
	
	printf("ft_isascii\n");
	printf("Esta funcion devuelve un 1 si el char pertence a la tabla ASCII y\nun 0 si no.\n");
	printf("Para un caracter '1', el resultado es %d\n", ft_isascii('1'));
	printf("Para un caracter 'a', el resultado es %d\n", ft_isascii('a'));
	printf("Para un caracter 'Z', el resultado es %d\n", ft_isascii('Z'));
	printf("Para un caracter '$', el resultado es %d\n", ft_isascii('$'));
	printf("Para un caracter 128, el resultado es %d\n", ft_isascii(128));
	printf("\n");

	//ft_isprint
	
	printf("ft_isprint\n");
	printf("Esta funcion devuelve un 1 si el char es imprimible y un 0 si no.\n");
	printf("Para un caracter '1', el resultado es %d\n", ft_isprint('1'));
	printf("Para un caracter 'a', el resultado es %d\n", ft_isprint('a'));
	printf("Para un caracter 10 , el resultado es %d\n", ft_isprint(10));
	printf("\n");

	//ft_strlen
	
	printf("ft_strlen\n");
	char *str;
	printf("Esta funcion devulve la longitud de un str.\n");
	str = "Hola mundo";
	printf("El str es %s y su longitud es %d caracteres\n", str, ft_strlen(str));
	printf("\n");

	//ft_memset
	
	printf("ft_memset\n");
	printf("Esta funcion modifica tantos char de el inicio de un str por un char a\nnuestra eleccion.\n");
	char str_memset[20] = "Hola mundo";
	printf("Str antes de realizar memset: %s\n", str_memset);
	printf("Sustituimos las 2 primeras posciones del str con el char '$'\n");
	printf("Str despues de realizar memset: %s\n", (char *)ft_memset(str_memset, '$', 2));
	printf("\n");

	//ft_bzero
	
	printf("ft_bzero\n");
	printf("Esta funcion modifica tantos char de un str por el simbolo NULL.\n");
  char str_bzero[20] = "Hola mundo";
  printf("Str antes de realizar bzero: %s\n", str_bzero);
  printf("Str despues de realizar bzero: %s\n", (char *)ft_bzero(str_bzero, 2));
  printf("\n");

	//ft_memcpy
	char str_memcpy_src[] = "Hola mundo";
	char str_memcpy_dst[20];
	printf("ft_memcpy\n");
	printf("Esta funcion copia un str src en un dst, pero no tiene en cuenta\ndesbordamientos de memoria.\n");
	printf("Str dst antes de realizar memcpy: %s\n", str_memcpy_dst);
	printf("Str dst despues de realizar memcpy: %s\n", (char *)ft_memcpy(str_memcpy_dst, str_memcpy_src, 10));
	printf("\n");

	//ft_memmove
	char str_memmove_src[] = "Hola mundo";
	char str_memmove_dst[20];
	printf("ft_memmove\n");
	printf("Esta funcion copia un str src en un dst, pero tiene en cuenta\ndesborda    mientos de memoria.\n");
	printf("Str dst antes de realizar memmove: %s\n", str_memmove_dst);
	printf("Str dst despues de realizar memmove: %s\n", (char *)ft_memmove(str_memmove_dst, str_memmove_src, 10));
	printf("\n");

	//ft_strlcpy -- No entiendo muy bien para que se le da el ultimo parametro
	const char *str_strlcpy_src = "Hola mundo";
	char str_strlcpy_dst[20];
	printf("ft_strlcpy\n");
	printf("Esta funcion copia 'n' char de un str src a un str dst.\n");
	printf("Strlcpy ha copiado %zu caracteres de src a dst\n", ft_strlcpy(str_strlcpy_dst, str_strlcpy_src, 4));
//printf("Strlcpy ha copiado %zu caracteres de src a dst\n", strlcpy(str_strlcpy_dst, str_strlcpy_src, 4));	
	printf("\n");

	//ft_strlcat
	char str_strlcat_dst[20] = " mundo";
	char str_strlcat_src[] = "Hola";
	printf("ft_strlcat\n");
	printf("Esta funcion concatena un str con otro str y devulve el tamaño final\ndel str.\n");
	printf("El str src es %s\n", str_strlcat_src);
	printf("El str dst es %s\n", str_strlcat_dst);
	printf("El tamaño final del str resultante es %zu\n", ft_strlcat(str_strlcat_src, str_strlcat_dst, 20));
	printf("\n");

	//ft_toupper
	printf("ft_toupper\n");
	printf("Esta funcion convierte un char minuscula en mayuscula.\n");
	printf("Para un caracter 'a', el resultado es %c\n", ft_toupper('a'));
	printf("Para un caracter 'b', el resultado es %c\n", ft_toupper('b'));
	printf("Para un caracter 'A', el resultado es %c\n", ft_toupper('A'));
	printf("Para un caracter '$', el resultado es %c\n", ft_toupper('$'));
	printf("\n");
	
	//ft_tolower
  printf("ft_tolower\n");
	printf("Esta funcion convierte un char mayuscula en minuscula.\n");
  printf("Para un caracter 'A', el resultado es %c\n", ft_tolower('A'));
  printf("Para un caracter 'B', el resultado es %c\n", ft_tolower('B'));
  printf("Para un caracter 'b', el resultado es %c\n", ft_tolower('b'));
  printf("Para un caracter '$', el resultado es %c\n", ft_tolower('$'));
	printf("\n");
	
	//ft_strchr
	printf("ft_strchr\n");
	printf("Esta funcion busca un char de izq a dch en un str y devulve\nsu posicion dentro del str.\n");
	const char *str_strchr = "Hola mundo";
	char look_for_char = 'm';
	printf("El str en el que buscar el char es: %s\n", str_strchr);
	printf("El char a buscar en el str es: %c\n", look_for_char);
	if (ft_strchr(str_strchr, look_for_char) != NULL)
		printf("El char '%c' se encontro en el str en la posicion %ld.\n", look_for_char, ((ft_strchr(str_strchr, look_for_char)) - str_strchr));
	else
		printf("El char '%c' no se encontro en el str.\n", look_for_char);
	printf("\n");		

	//ft_strrchr
	printf("ft_strrchr\n");
	printf("Esta funcion busca un char de dch a izq en un str y devulve\nsu posicion dentro del str.\n");
	const char *str_strrchr = "Hola mundo";
	char look_for_chr = 'd';
	printf("El str en el que buscar el char es: %s\n", str_strrchr);
	printf("El char a buscar en el str es: %c\n", look_for_chr);
	if (ft_strrchr(str_strrchr, look_for_chr) != NULL)
		printf("El char '%c' se encontro en el str en la posicion %ld.\n", look_for_chr, ((ft_strrchr(str_strrchr, look_for_chr)) - str_strrchr));
	else
		printf("El char '%c' no se encontro en el str.\n", look_for_chr);
	printf("\n");

	//ft_strncmp
	printf("ft_strncmp\n");
	const char *s1 = "Hola mundo";
	const char *s2 = "Hola mondo";
	printf("Esta funcion compara dos str una cantidad 'n' de caracteres, y devueve\nun entero que es la diferencia en ASCII de los caracteres que no coincidan.\n");
	printf("Al aplicar esta funcion, el resultado devuelto es %d.\n", ft_strncmp(s1, s2, 9));
	printf("%d es la diferencia en ASCII entre el primer caracter diferente de las cadenas\n%s y %s.\n", ft_strncmp(s1, s2, 9), s1, s2);
	printf("\n");
	
	//ft_memchr
	printf("ft_memchr\n");
	printf("Esta funcion busca un char en particular dentro de un str y devuelve un\npuntero a la primera ocurrencia de ese caracter dentro del str.\n");
	const char *str_memchr= "Hola mundo";
  int target = 'd'; // char  que queremos buscar en la cadena
  size_t n = 11; // Tamaño de la cadena, incluyendo el carácter nulo '\0'
  if (ft_memchr(str_memchr, target, n) != NULL)
  	printf("El char '%c' se encontró en la posición %ld del str %s.\n", target, (size_t)((char *)ft_memchr(str_memchr, target, n) - str_memchr), str_memchr);
  else
  	printf("El byte '%c' no se encontró en la cadena.\n", target);
	printf("\n");

	//ft_memcmp
	printf("ft_memcmp\n");
	printf("Esta funcion compara dos bloques de memoria una cantidad 'n' de caracteres, y devueve\nun entero que es la diferencia en ASCII de los caracteres que no coincidan.\n");
	char *s1_memcmp = "Hola mundo";
	char *s2_memcmp = "Hola mondo";
 	printf("Al aplicar esta funcion, el resultado devuelto es %d.\n", ft_memcmp(s1_memcmp, s2_memcmp, 10));
 	printf("%d es la diferencia en ASCII entre el primer caracter diferente de las cadenas\n%s y %s.\n", ft_memcmp(s1, s2, 9), s1, s2);
	printf("La diferencia entre ft_strncmp y ft_memcmp es que ft_strncmp compara\nstr y ft_memcmp compara bloques de memoria, por lo que te vale para comparar\ndiferentes tipos de datos.\n");
	printf("\n");
	
	//ft_strnstr
	printf("ft_strnstr\n");
	printf("Esta funcion busca una subcadena (needle) dentro de una cadena\nmas grande(haystack) y devulve su posicion.\n");
	const char *haystack = "Esto es una cadena de ejemplo";
	const char *needle = "emp";
	size_t total_len = ft_strlen(haystack);
	printf("Mi haystack es: '%s'.\n", haystack);
	printf("Mi needle es: '%s'.\n", needle);
	printf("Subcadena encontrada en la posicion %ld.\n", ft_strnstr(haystack, needle, total_len) - haystack);
	printf("\n");

	//ft_atoi
	printf("ft_atoi\n");
	printf("Esta funcion convierte un str a un int.\n");
	const char *str_atoi = "27031991";
	printf("El valor entero de la str %s es %d.\n", str_atoi, ft_atoi(str_atoi));
	printf("\n");

	//ft_calloc
	printf("ft_calloc\n");
	printf("Esta funcion sirve para asignar dinámicamente memoria en el montón\n(heap) e inicializarla con ceros. Esta funcion se utiliza comúnmente para asignar\nmemoria para arreglos de elementos del mismo tipo.\n");
	int *array_calloc;
	int n_calloc = 5;
	int i_calloc = 0;
	array_calloc = (int *)ft_calloc(n_calloc, sizeof(int));
	if (array_calloc == NULL)
	{
		printf("La asignacion de memoria ha fallado\n");
		return (1);
	}
	printf("Imprimimos los elementos del array (que deberian ser ceros).\n");
	while (i_calloc < n_calloc)
	{
		printf("%d ", array_calloc[i_calloc]);
		i_calloc++;
	}
	printf("\n");
	printf("Es importante liberar la memoria asignada con la funcion free.\n");
	free(array_calloc);
	printf("\n");

	//ft_strdup
	printf("ft_strdup\n");
	printf("Esta funcion se utiliza para duplicar una cadena de caracteres\n(string) dada. La función ft_strdup toma como argumento un puntero a una cadena de\ncaracteres (const char *s1) y devuelve un nuevo puntero a una cadena duplicada que es\nuna copia de la cadena original.\n");
	const char *original = "Hola mundo";
	char *duplicated = ft_strdup(original);
	if (duplicated == NULL)
	{
		printf("La asignacion de memoria ha fallado.\n");
		return (1);
	}
	printf("Cadena original: %s\n", original);
  printf("Cadena duplicada: %s\n", duplicated);
	printf("Es importante liberar la memoria asignada con la funcion free.\n");
	free(duplicated);
	printf("\n");

	//ft_substr
	printf("ft_substr\n");
	printf("Esta función se utiliza para crear una nueva cadena (un substring)\na partir de una cadena de entrada.\n");
	const char *input_substr = "Este es un ejemplo de cadena";
	printf("Ejemplo 1:\n");
	printf("Crear un substring desde el inicio de la cadena (posición 0) con\nlongitud 5.\n");
	char *substring1 = ft_substr(input_substr, 0, 5);
	printf("Substring 1: '%s'\n", substring1);
	printf("Es importante liberar la memoria asignada con la funcion free.\n");
	free(substring1);
	printf("Ejemplo 2:\n");
	printf("Crear un substring desde la posición 10 con longitud 8.\n");
	char *substring2 = ft_substr(input_substr, 10, 8);
	printf("Substring 2: '%s'\n", substring2);
	printf("Es importante liberar la memoria asignada con la funcion free.\n");
	free(substring2);
	printf("\n");

	//ft_strjoin
	printf("ft_strjoin\n");
	printf("Esta funcion toma dos cadenas de entrada, las concatena en una\nnueva cadena y devuelve esa nueva cadena. La función maneja correctamente los\ncasos en los que las cadenas de entrada son nulas.\n");
	const char *str1 = "Hola ";
	const char *str2 = "mundo";
	printf("Cadena 1: %s.\n", str1);
	printf("Cadena 2: %s.\n", str2);
	printf("Cadena concatenda: %s.\n", ft_strjoin(str1, str2));
	printf("\n");

	//ft_strtrim
	printf("ft_strtrim\n");
	printf("Esta funcion elimina los caracteres especificados en set del principio\ny el final de la cadena s1 y devuelve una nueva cadena que contiene la\nporción de s1 que no tiene esos caracteres. Esta función es útil para limpiar y\nrecortar cadenas de texto.\n");
	const char *original_str = "   Hola mundo   ";
	const char *chr_to_rem = " ";
	char *trimmed_str = ft_strtrim(original_str, chr_to_rem);
	printf("Str original: '%s'\n", original_str);
	printf("Str trimmed: '%s'\n", trimmed_str);
	printf("Es importante liberar la memoria asignada con la funcion free.\n");
	free(trimmed_str);
	printf("\n");

	//ft_split
	printf("ft_split\n");
	printf("Esta funcion se utiliza para dividir un str en 1 o mas substr a\npartir de un carácter delimitador 'c'. El resultado es un array de str que contienen\nlas subcadenas.\n");
	const char *input_str = "Hola,mundo,esto,es,una,prueba";
	char delimiter = ',';
	char **result_split = ft_split(input_str, delimiter);
	int i_split = 0;
	if (result_split == NULL)
	{
  	printf("No se pudo dividir la cadena.\n");
  	return 1;
	}
	printf("Str a dividir: '%s'\n", input_str);
	printf("Char delimitador: '%c'\n", delimiter);
	while (result_split[i_split] != NULL)
	{
		printf("Subcadena %d: %s\n", i_split + 1, result_split[i_split]);
		i_split++;
	}
	printf("Es importante liberar la memoria asignada con la funcion free.\n");
	while (result_split[i_split] != NULL)
  {
  	free(result_split[i_split]);
		i_split++;
  }
	free(result_split);
	printf("\n");

	//ft_itoa
	printf("ft_itoa\n");
	printf("convierte un número entero en su representación de cadena de\ncaracteres, maneja casos especiales y asigna memoria dinámica para\nla cadena resultante.\n");
	int num_itoa = 27031991;
	char *str_itoa;
	str_itoa = ft_itoa(num_itoa);
	if (str_itoa == NULL)
  {
		printf("Error al convertir el número a cadena.\n");
		return 1;
  }
	printf("Número: %d\n", num_itoa);
  printf("Cadena: %s\n", str_itoa);
	printf("Es importante liberar la memoria asignada con la funcion free.\n");
	free(str_itoa);
	printf("\n");
	
	//ft_strmapi
	printf("ft_strmapi\n");
	printf("Esta función toma una cadena de entrada s y una función f que toma\ndos argumentos (un índice y un carácter) y aplica esa función a cada carácter de\nla cadena. Luego, construye una nueva cadena con los resultados de esas\naplicaciones y devuelve esa nueva cadena. Esta función es útil cuando deseas aplicar una\noperación específica a cada carácter de una cadena y obtener una nueva cadena\ncomo resultado.\n");
	const char *original_mapi = "Hola mundo";
	char *result_mapi;
	printf("En este caso, aplicamos la funcion ft_toupper al str %s para ponerlo en mayuscula.\n", original_mapi);
	result_mapi = ft_strmapi(original_mapi, ft_toupper_wrapper);
	if (result_mapi != NULL)
  {
		printf("Str original: %s\n", original_mapi);
		printf("Str modificado: %s\n", result_mapi);
    // Liberar la memoria asignada a 'result' cuando ya no la necesites
		free(result_mapi);
	}
	else
		printf("Error: La asignación de memoria falló.\n");
	printf("\n");

	//ft_striteri
	printf("ft_striteri\n");
	printf("Esta funcion se utiliza para aplicar una función personalizada (f) a\ncada carácter de una cadena, permitiendo a la función personalizada conocer la\nposición (índice) de cada carácter en la cadena. Esto puede ser útil para\nrealizar operaciones específicas en cada carácter de la cadena o para realizar algún\ntipo de procesamiento en función de la posición de los caracteres.\n");
	char str_iteri[] = "Ejemplo";
	printf("Cadena original: %s\n", str_iteri);
	ft_striteri(str_iteri, print_index_and_char);
	printf("\n");

	//ft_putchar_fd
	printf("ft_putchar_fd\n");
	printf("Esta funcion se encarga de escribir un carácter en el descriptor de\narchivo especificado. Puedes usar esta función para escribir caracteres en\narchivos, en la salida estándar (por ejemplo, la consola) o en cualquier otro lugar\ndonde se utilicen descriptores de archivo.\n");
	char chr_fd = 'A';
	int stdout_fd = 1;
	ft_putchar_fd(chr_fd, stdout_fd);
	printf("\n");
	printf("Se ha escrito el carácter '%c' en la salida estándar.\n", chr_fd);
	printf("\n");

	//ft_putstr_fd
	printf("ft_putstr_fd\n");
	printf("Esta funcion es una forma de escribir una cadena de caracteres en\nun archivo o en una salida específica caracter por caracter. Puedes utilizarla\npara escribir cadenas en archivos o en cualquier otro lugar donde necesites\ncontrolar la escritura de caracteres individualmente.\n");
	char *str_putstr = "Hola mundo";
	ft_putstr_fd(str_putstr, stdout_fd);
	printf("\n");
	printf("Se ha escrito el str '%s' en la salida estándar.\n", str_putstr);
	printf("\n");

	//ft_putendl_fd
	printf("ft_putendl_fd\n");
	printf("Esta función toma una cadena de caracteres y la escribe en el\narchivo especificado (fd) carácter por carácter, seguida de un salto de línea\nal final. Es útil cuando se desea escribir una cadena con un formato específico en un\narchivo o en otro tipo de descriptor de archivo, como la salida estándar.\n");
	ft_putendl_fd(str_putstr, stdout_fd);
	printf("\n");
	printf("Se ha escrito el str '%s' en la salida estándar seguido de un salto de linea.\n", str_putstr);
	printf("\n");

	//ft_putnbr_fd
	printf("ft_putnbr_fd\n");
	printf("Esta función se utiliza para escribir números enteros en un\ndescriptor de archivo. Maneja números negativos, dígitos individuales y números con\nmúltiples dígitos utilizando una estrategia recursiva. El caso especial de\n-2147483648 se maneja explícitamente.\n");
	int num1 = 12345;
  	int num2 = -9876;
  	int num3 = 0;
  	int num4 = -2147483648;
	printf("\n");
  	ft_putnbr_fd(num1, stdout_fd);  // Escribir el número num1 en stdout
  	write(stdout_fd, "\n", 1);      // Nueva línea
  	ft_putnbr_fd(num2, stdout_fd);  // Escribir el número num2 en stdout
  	write(stdout_fd, "\n", 1);      // Nueva línea
  	ft_putnbr_fd(num3, stdout_fd);  // Escribir el número num3 en stdout
  	write(stdout_fd, "\n", 1);      // Nueva línea
  	ft_putnbr_fd(num4, stdout_fd);  // Escribir el número num4 en stdout
  	write(stdout_fd, "\n", 1);
	printf("\n");

	//ft_lstnew
	printf("ft_lstnew\n");
	printf("Esta función se utiliza para crear un nuevo nodo de una lista enlazada,\nasignando un valor content al nodo y asegurando que esté correctamente inicializado.\n");
	t_list *node = ft_lstnew("Hola mundo");
	if (node != NULL)
	{
		printf("Contenido de nodo: %s\n", (char*)node->content);
		free(node);
	}
	else
		printf("Error al crear el nodo.\n");
	printf("\n");

	//ft_lstadd_front
	printf("ft_lstadd_front\n");
	printf("Esta funcion toma una lista enlazada representada por un puntero a\npuntero t_list **lst y agrega un nuevo elemento t_list *new al principio de la lista.\nEsto se logra ajustando los punteros next y actualizando el puntero a la lista *lst.\nEsto es una operación común en la manipulación de listas enlazadas y se utiliza para\nagregar elementos al principio de la lista de manera eficiente.\n");
	printf("Creamos una lista vacia\n");
	t_list* list = NULL;
	printf("Creamos algunos elementos para la lista\n");
	t_list* element1 = malloc(sizeof(t_list));
	element1->content = (void *)(intptr_t)10;
	element1->next = NULL;
	t_list* element2 = malloc(sizeof(t_list));
	element2->content = (void *)(intptr_t)20;
	element2->next = NULL;
	printf("Agregar elemento 2 al principio de la lista\n");
	ft_lstadd_front(&list, element2);
	printf("Agregar elemento 1 al principio de la lista\n");
	ft_lstadd_front(&list, element1);
	printf("Imprimir la lista resultante\n");
	t_list* current = list;
	while (current != NULL)
	{
		printf("%d -> ", (int)(intptr_t)current->content);
		current = current->next;
	}
	printf("NULL\n");
	printf("Es impportante liberar la memoria de la lista al final\n");
	while (list != NULL)
	{
		t_list* temp = list;
		list = list->next;
		free(temp);
	}
	printf("\n");

	//ft_lstsize
	printf("ft_lstsize\n");
	printf("Esta función recorre una lista enlazada y cuenta cuántos elementos\ncontiene, devolviendo el resultado como un entero. Es una operación fundamental\ncuando se trabaja con listas enlazadas para determinar su longitud o tamaño.\n");
	printf("Creacion de una lista enlazada con algunos elementos de ejemplo\n");
	t_list *head = NULL;
	t_list *current_lstsize;
	int i_lstsize = 1;
	while (i_lstsize < 5)
	{
		printf("Crear un nuevo nodo\n");
		t_list *new_node = (t_list *)malloc(sizeof(t_list));
		new_node->content = (void *)&i_lstsize;
		new_node->next = NULL;
		printf("Insertar nuevo nodo al final de la lista\n");
		if (head == NULL)
		{
			head = new_node;
			current_lstsize = head;
		}
		else
		{
			current_lstsize->next = new_node;
			current_lstsize = new_node;
		}
		i_lstsize++;
	}
	int size_lstsize = ft_lstsize(head);
	printf("Tamaño de la lista: %d\n", size_lstsize);
	current_lstsize = head;
	while (current_lstsize != NULL)
	{
		t_list *temp = current_lstsize;
		current_lstsize = current_lstsize->next;
		free(temp);
	}
	printf("\n");

	//ft_lstlast
	printf("ft_lstlast\n");
	printf("Esta funcion recibe una lista enlazada como entrada y devuelve un\npuntero al último elemento de la lista, o un puntero nulo si la lista está vacía.\nEsta función es útil cuando se necesita acceder al último elemento de una lista\nenlazada sin recorrer toda la lista cada vez.\n");
	printf("Creamos una lista enlazada con 3 nodos\n");
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));
	t_list *current_last;
	node1->content = (void *)1;
	node2->content = (void *)2;
	node3->content = (void *)3;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	t_list *last_node = ft_lstlast(node1);
	printf("Imprimir el valor del ultimo nodo\n");
	if (last_node != NULL)
		printf("El ultimo nodo contiene el valor: %d\n", (int)last_node->content);
	else
		printf("La lista esta vacia, no hay ultimo nodo\n");
	printf("Es importante liberar la memoria de los nodos\n");
	free(node1);
	free(node2);
	free(node3);
	printf("\n");

	//ft_lstadd_back
	printf("ft_lstadd_back\n");
	printf("Esta funcion agrega un nuevo elemento al final de una lista enlazada. Si la lista\nestá vacía, simplemente coloca el nuevo elemento como el primer elemento de la\nlista. Si la lista no está vacía, recorre la lista para encontrar el último elemento\ny luego conecta el nuevo elemento al final de la lista.\n");
	printf("Inicializamos una lista vacia\n");
	t_list *my_list = NULL;
	int i_back = 1;
	while (i_back <= 5)
	{
		t_list *new_node = (t_list *)malloc(sizeof(t_list));
		new_node->content = (void *)(intptr_t)i_back;
		new_node->next = NULL;
		ft_lstadd_back(&my_list, new_node);
		i_back++;
	}
	printf("Imprimir los elementos de la lista\n");
	t_list *current_back = my_list;
	while(current_back != NULL)
	{
		printf("%d ", (int)(intptr_t)current_back->content);
		current_back = current_back->next;
	}
	printf("\n");
	t_list *last_node_back = my_list;
	while (last_node_back != NULL)
	{
		if (last_node_back->next == NULL)
		{
			printf("El último elemento añadido es: %d\n", (int)(intptr_t)last_node_back->content);
			break;
		}
		last_node_back = last_node_back->next;
	}
	t_list *current_back_last = my_list;
	while (current_back_last != NULL)
	{
		t_list *temp = current_back_last;
		current_back_last = current_back_last->next;
		free(temp);
	}
	printf("\n");

	//ft_lstdelone
	printf("ft_lstdelone\n");
	printf("Esta funcion elimina un elemento de una lista enlazada  y libera\nla memoria asociada tanto al contenido del elemento como al elemento en sí. La\nfunción de liberación personalizada se utiliza para garantizar que se maneje\nadecuadamente cualquier memoria asignada dinámicamente para el contenido del\nelemento.\n");
	printf("Creamos una lista enlazada con 3 nodos\n");
	t_list *node_del1 = malloc(sizeof(t_list));
	t_list *node_del2 = malloc(sizeof(t_list));
	t_list *node_del3 = malloc(sizeof(t_list));
	node_del1->content = malloc(sizeof(int));
    node_del2->content = malloc(sizeof(int));
    node_del3->content = malloc(sizeof(int));
	*(int*)node_del1->content = 1;
	*(int*)node_del2->content = 2;
	*(int*)node_del3->content = 3;
	node_del1->next = node_del2;
	node_del2->next = node_del3;
	node_del3->next = NULL;
	t_list *current_del = node_del1;
	while (current_del != NULL)
	{
		printf("Contenido del nodo: %d\n", *(int*)current_del->content);
		current_del = current_del->next;
	}
	ft_lstdelone(node_del2, free);
	printf("Lista despues de eliminar el nodo:\n");
	current_del = node_del1;
	while (current_del != NULL)
	{
		printf("Contenido del nodo: %d\n", *(int*)current_del->content);
		current_del = current_del->next;
	}
	printf("\n");

	//ft_lstclear
	printf("ft_lstclear\n");
	printf("Esta función se encarga de liberar la memoria de una lista enlazada\nsimple y sus elementos, utilizando la función del para personalizar la liberación\nde la memoria del contenido de cada nodo. Al final, la lista original queda vacía y\nel puntero a la lista apunta a NULL.\n");
	printf("Creamos una lista enlazada con 3 nodos\n");
	t_list *node_clear1 = malloc(sizeof(t_list));
	t_list *node_clear2 = malloc(sizeof(t_list));
	t_list *node_clear3 = malloc(sizeof(t_list));
	node_clear1->content = malloc(sizeof(int));
    node_clear2->content = malloc(sizeof(int));
    node_clear3->content = malloc(sizeof(int));
	*(int*)node_clear1->content = 1;
	*(int*)node_clear2->content = 2;
	*(int*)node_clear3->content = 3;
	node_clear1->next = node_clear2;
	node_clear2->next = node_clear3;
	node_clear3->next = NULL;
	t_list *current_clear = node_clear1;
	while (current_clear != NULL)
	{
		printf("Contenido del nodo: %d\n", *(int*)current_clear->content);
		current_clear = current_clear->next;
	}
	ft_lstclear(&node_clear1, free);
	if (node_clear1 == NULL)
        printf("La lista se ha eliminado y el puntero a la lista apunta a NULL.\n");
    else
        printf("Error: El puntero a la lista no apunta a NULL después de la eliminación.\n");
    if (node_clear1 != NULL && node_clear1->content != NULL)
        printf("Error: Intento de acceder al contenido del primer nodo después de la eliminación.\n");
    else
        printf("Intento de acceder al contenido del primer nodo ha fallado, como se esperaba.\n");
	printf("\n");

	//ft_lstiter
	printf("ft_lstiter\n");
	printf("Esta funcion se utiliza para aplicar una función proporcionada por el\nusuario a cada elemento de una lista enlazada, permitiendo realizar alguna\noperación en cada elemento de la lista de manera secuencial. Esto es útil en\nsituaciones donde se necesita procesar o manipular los elementos de la lista de\nmanera uniforme.\n");
	printf("Creamos una lista enlazada con 3 nodos\n");
	t_list *node_iter1 = malloc(sizeof(t_list));
	t_list *node_iter2 = malloc(sizeof(t_list));
	t_list *node_iter3 = malloc(sizeof(t_list));
	node_iter1->content = malloc(sizeof(int));
    node_iter2->content = malloc(sizeof(int));
    node_iter3->content = malloc(sizeof(int));
	*(int*)node_iter1->content = 1;
	*(int*)node_iter2->content = 2;
	*(int*)node_iter3->content = 3;
	node_iter1->next = node_iter2;
	node_iter2->next = node_iter3;
	node_iter3->next = NULL;
	printf("Elementos de la lista antes de la multiplicación:\n");
    t_list *current_iter = node_iter1;
    while (current_iter != NULL)
   	{
 		printf("Contenido del nodo: %d\n", *(int*)current_iter->content);
        current_iter = current_iter->next;
    }
	ft_lstiter(node_iter1, multiply_by_two);
	printf("Elementos de la lista después de la multiplicación:\n");
    current_iter = node_iter1;
    while (current_iter != NULL) 
	{
        printf("Contenido del nodo: %d\n", *(int*)current_iter->content);
        current_iter = current_iter->next;
    }
	while (node_iter1 != NULL) 
	{
        t_list *temp = node_iter1;
        node_iter1 = node_iter1->next;
        free(temp->content);
        free(temp);
    }
	printf("\n");

	//ft_lstmap
	printf("ft_lstmap\n");
	printf("Esta funcion mapea los elementos de una lista enlazada original a una\nnueva lista aplicando una función f a cada elemento, y permite especificar\nuna función del para liberar la memoria asociada a los elementos de la nueva lista\nen caso de error.\n");
	printf("Creamos una lista enlazada con 3 nodos\n");
	t_list *node_map1 = malloc(sizeof(t_list));
	t_list *node_map2 = malloc(sizeof(t_list));
	t_list *node_map3 = malloc(sizeof(t_list));
	node_map1->content = malloc(sizeof(int));
    node_map2->content = malloc(sizeof(int));
    node_map3->content = malloc(sizeof(int));
	*(int*)node_map1->content = 1;
	*(int*)node_map2->content = 2;
	*(int*)node_map3->content = 3;
	node_map1->next = node_map2;
	node_map2->next = node_map3;
	node_map3->next = NULL;
	t_list *new_list = ft_lstmap(node_map1, multiply_by_two_wrapper, free);
	t_list *current_map = new_list;
    while (current_map != NULL)
    {
        int *value = (int *)current_map->content;
        printf("Nuevo valor: %d\n", *value);
        current_map = current_map->next;
    }
	while (new_list != NULL)
    {
        t_list *temp = new_list;
        new_list = new_list->next;
        free(temp->content);
        free(temp);
    }
	printf("\n");
	printf("MUCHAS GRACIAS POR LLEGAR HASTA AQUI\n");
	printf("\n");
	return (0);
}
