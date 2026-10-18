*Este proyecto ha sido creado como parte del currículo de 42 por felixrod.*

<div align="center">

# Libft — @42Barcelona

![42 Badge](https://img.shields.io/badge/42-Barcelona-000000?style=for-the-badge&logo=42&logoColor=white)
![C Badge](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Norminette Badge](https://img.shields.io/badge/Norminette-OK-brightgreen?style=for-the-badge)

<p align="center">
  <b>Mi primera librería en C: recreación de funciones de la libc, utilidades adicionales de cadenas y E/S, y listas enlazadas.</b>
</p>

</div>

---

## Índice

- [Descripción](#descripción)
- [Descripción detallada de la librería](#descripción-detallada-de-la-librería)
- [Instrucciones](#instrucciones)
- [Estructura del proyecto](#estructura-del-proyecto)
- [Recursos](#recursos)

---

## Descripción

**Libft** es el primer proyecto del cursus de 42. Consiste en reescribir desde cero un conjunto de funciones de la librería estándar de C (`<ctype.h>`, `<string.h>`, `<stdlib.h>`), añadir funciones propias de manipulación de cadenas y escritura en descriptores de archivo, e implementar una pequeña API de **listas enlazadas**.

El resultado es una librería estática, `libft.a`, que se reutiliza en los proyectos posteriores del cursus.

### Objetivos

* **Gestión de memoria dinámica:** uso correcto de `malloc` y `free`, y ausencia de *memory leaks* incluso cuando una reserva falla a mitad de una operación (`ft_split`, `ft_lstmap`).
* **Punteros:** aritmética de punteros, punteros dobles (`t_list **`) y punteros a función (`f`, `del`).
* **Estructuras de datos:** nodos enlazados reservados dinámicamente.
* **Organización de un proyecto en C:** `Makefile`, header único (`libft.h`) y cumplimiento de la Norma de 42.

---

## Descripción detallada de la librería

La librería contiene **43 funciones** repartidas en 3 bloques.

### 1. Funciones de la `libc` (23)

Reimplementaciones con el mismo prototipo y comportamiento que las originales (ver `man 3 <función>`).

| Función | Descripción |
| :--- | :--- |
| `ft_isalpha` / `ft_isdigit` / `ft_isalnum` | Comprueban si un carácter es alfabético, dígito o alfanumérico. |
| `ft_isascii` / `ft_isprint` | Comprueban si un carácter pertenece a ASCII (0–127) o es imprimible. |
| `ft_toupper` / `ft_tolower` | Convierten un carácter a mayúscula o minúscula. |
| `ft_strlen` | Devuelve la longitud de una cadena. |
| `ft_memset` / `ft_bzero` | Rellenan una zona de memoria con un byte dado o con ceros. |
| `ft_memcpy` | Copia `n` bytes entre zonas que **no** se solapan. |
| `ft_memmove` | Copia `n` bytes gestionando correctamente el solapamiento. |
| `ft_memchr` / `ft_memcmp` | Buscan un byte o comparan dos zonas de memoria de `n` bytes. |
| `ft_strlcpy` / `ft_strlcat` | Copian y concatenan cadenas limitando el tamaño del destino; siempre terminan en `'\0'`. |
| `ft_strchr` / `ft_strrchr` | Buscan la primera / última aparición de un carácter en una cadena. |
| `ft_strncmp` | Compara como máximo `n` caracteres de dos cadenas. |
| `ft_strnstr` | Busca una subcadena dentro de los primeros `len` bytes de otra. |
| `ft_atoi` | Convierte una cadena a `int`. |
| `ft_calloc` | Reserva memoria para un array y la inicializa a cero (con control de desbordamiento). |
| `ft_strdup` | Duplica una cadena en memoria nueva. |

### 2. Funciones adicionales (11)

No forman parte de la `libc` (o lo hacen de otra forma), pero resultan útiles en proyectos posteriores. Las que devuelven memoria nueva retornan `NULL` si la reserva falla.

| Función | Descripción |
| :--- | :--- |
| `ft_substr` | Devuelve una subcadena de `s` que empieza en `start` y mide como máximo `len`. |
| `ft_strjoin` | Devuelve una nueva cadena con la concatenación de `s1` y `s2`. |
| `ft_strtrim` | Elimina del principio y del final de `s1` los caracteres contenidos en `set`. |
| `ft_split` | Divide una cadena según el delimitador `c` y devuelve un array de cadenas terminado en `NULL`. |
| `ft_itoa` | Convierte un `int` a cadena (incluido `INT_MIN`). |
| `ft_strmapi` | Aplica `f(índice, carácter)` a cada carácter y devuelve una cadena nueva con el resultado. |
| `ft_striteri` | Aplica `f(índice, &carácter)` a cada carácter, modificando la cadena *in situ*. |
| `ft_putchar_fd` / `ft_putstr_fd` | Escriben un carácter o una cadena en el descriptor `fd`. |
| `ft_putendl_fd` / `ft_putnbr_fd` | Escriben una cadena seguida de `'\n'`, o un entero, en el descriptor `fd`. |

### 3. Listas enlazadas (9)

Todas trabajan sobre la estructura `t_list` definida en `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Función | Descripción |
| :--- | :--- |
| `ft_lstnew` | Crea un nodo nuevo con `content` y `next = NULL`. |
| `ft_lstadd_front` | Añade un nodo al principio de la lista. |
| `ft_lstadd_back` | Añade un nodo al final de la lista. |
| `ft_lstsize` | Devuelve el número de nodos de la lista. |
| `ft_lstlast` | Devuelve el último nodo de la lista. |
| `ft_lstdelone` | Libera el contenido de un nodo con `del` y después el propio nodo. |
| `ft_lstclear` | Libera todos los nodos de la lista y deja el puntero a `NULL`. |
| `ft_lstiter` | Aplica `f` al contenido de cada nodo. |
| `ft_lstmap` | Crea una lista nueva aplicando `f` a cada contenido; si falla una reserva, libera todo lo creado con `del` y devuelve `NULL`. |

---

## Instrucciones

### Requisitos

- Sistema tipo UNIX (Linux, macOS o WSL).
- Compilador de C (`cc`, `gcc` o `clang`).
- `make`.

### Compilación

Desde la raíz del repositorio:

```bash
make          # Compila todas las funciones y genera libft.a
make clean    # Elimina los ficheros objeto (.o)
make fclean   # Elimina los objetos y libft.a
make re       # fclean + make
```

Se compila con `cc -Wall -Wextra -Werror`, y la librería se empaqueta con `ar -rcs`.

### Uso en otro proyecto

1. Incluye la cabecera en tu código:

   ```c
   #include "libft.h"
   ```

2. Enlaza con `libft.a` al compilar, indicando dónde están el header (`-I`) y la librería (`-L`):

   ```bash
   cc -Wall -Wextra -Werror -I ruta/a/libft main.c -L ruta/a/libft -lft -o mi_programa
   ```

#### Ejemplo rápido

```c
#include "libft.h"

int	main(void)
{
	char	**words;
	int		i;

	words = ft_split("hola mundo desde libft", ' ');
	if (!words)
		return (1);
	i = 0;
	while (words[i])
	{
		ft_putendl_fd(words[i], 1);
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}
```

---

## Estructura del proyecto

```
libft/
├── Makefile
├── libft.h          # Prototipos, t_list y macros
├── ft_is*.c         # Clasificación de caracteres
├── ft_to*.c         # Conversión de caracteres
├── ft_mem*.c        # Memoria
├── ft_str*.c        # Cadenas
├── ft_put*_fd.c     # Escritura en descriptores
├── ft_lst*.c        # Listas enlazadas
└── ...              # ft_atoi, ft_itoa, ft_split, ft_calloc, ft_bzero, ft_substr
```

---

## Recursos

### Referencias y documentación

- [Linux man pages](https://man7.org/linux/man-pages/) — Referencia de las funciones de la `libc` (`man 3 strlcpy`, `man 3 memmove`, …) y de llamadas al sistema como `write`.
- [GeeksforGeeks: Linked List in C](https://www.geeksforgeeks.org/linked-list-set-1-introduction/) — Introducción visual a nodos y punteros.
- [Tutorialspoint: Pointer to Pointer](https://www.tutorialspoint.com/cprogramming/c_pointer_to_pointer.htm) — Punteros dobles en C.
- [Mis notas de estudio de 42 Barcelona](https://felixrodriguezg.github.io/rclone-oauth/notas/#/Barcelona42/A-Maze-ing/A-Maze-ing%20-%20%C3%8Dndice.md) — Apuntes personales sobre proyectos y conceptos del cursus.

### Uso de Inteligencia Artificial (IA)

Conforme a la normativa de 42, este es el uso que se ha hecho de herramientas de IA en el proyecto:

- **Para qué se ha usado:**
  - **Explicaciones conceptuales:** dudas sobre punteros dobles (`t_list **`) y el paso de punteros por referencia.
  - **Makefile:** ajuste del formato de `printf` para alinear la salida por consola.
  - **Documentación:** redacción, revisión y maquetación de este `README.md`.
- **Qué no se ha delegado:** toda la lógica de las funciones —gestión de memoria (`malloc`/`free`), punteros a función (`del`, `f`) y algoritmos como `ft_split` o `ft_lstmap`— ha sido pensada, escrita y probada por mí.
