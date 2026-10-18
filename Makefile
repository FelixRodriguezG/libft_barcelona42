# ==============================================================================
# 1. NOMBRE DEL BINARIO O LIBRERÍA
# ==============================================================================

NAME        = libft.a

# ==============================================================================
# 2. HERRAMIENTAS Y BANDERAS
# ==============================================================================

SHELL     := /bin/bash
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I.
AR          = ar -rcs
RM          = rm -f
HEADER      = libft.h

# ==============================================================================
# 3. PALETA DE COLORES ANSI (Optimizada para fondo oscuro)
# ==============================================================================

DEF_COLOR   = \033[0m
GRAY        = \033[38;2;128;128;128m
RED         = \033[38;2;255;85;85m
GREEN       = \033[38;2;80;250;123m
YELLOW      = \033[38;2;255;215;0m
BLUE        = \033[38;2;97;175;239m
MAGENTA     = \033[38;2;189;147;249m
CYAN        = \033[38;2;139;233;253m
WHITE       = \033[38;2;255;255;255m

# ==============================================================================
# 4. ARCHIVOS FUENTE Y OBJETOS
# ==============================================================================

# Libc - Verificación y Conversión de Caracteres
SRC_CHARS   = ft_isalnum.c     ft_isalpha.c     ft_isascii.c    ft_isdigit.c   \
              ft_isprint.c     ft_tolower.c     ft_toupper.c

# Libc - Gestión de Memoria
SRC_MEM     = ft_bzero.c       ft_calloc.c      ft_memchr.c     ft_memcmp.c    \
              ft_memcpy.c      ft_memmove.c     ft_memset.c

# Libc - Manipulación de Cadenas (Básicas y Conversión)
SRC_STR     = ft_atoi.c        ft_strchr.c      ft_strdup.c     ft_strlcat.c   \
              ft_strlcpy.c     ft_strlen.c      ft_strncmp.c    ft_strnstr.c   \
              ft_strrchr.c

# Funciones Adicionales (Asignación y Manipulación de Cadenas)
SRC_ADD     = ft_itoa.c        ft_split.c       ft_strjoin.c    ft_strtrim.c   \
              ft_substr.c	   ft_strmapi.c	    ft_striteri.c   ft_putstr_fd.c \
              ft_putchar_fd.c  ft_putnbr_fd.c   ft_putendl_fd.c

# Manipulacion de Listas
SRC_LSTS	= ft_lstnew.c		ft_lstadd_front.c		ft_lstsize.c           \
			  ft_lstlast.c		ft_lstadd_back.c		ft_lstdelone.c         \
			  ft_lstclear.c		ft_lstiter.c			ft_lstmap.c

# Variable con todos los SRC_
SRC_FILES   = $(SRC_CHARS) $(SRC_MEM) $(SRC_STR) $(SRC_ADD) $(SRC_LSTS)

OBJS        = $(SRC_FILES:.c=.o)

# Lista de ejecutables de test a borrar
TEST_BINS  = $(SRC_FILES:ft_%.c=test_%)

# ============================================================================== 
# 5. REGLAS PRINCIPALES
# ==============================================================================
 
all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^
	@printf "	$(GREEN)─────────────────────────────────────────$(DEF_COLOR)\n"
	@printf "	$(GREEN) ✔ Librería $(CYAN)%-10s$(GREEN) creada con éxito!$(DEF_COLOR)\n" "$(NAME)"
	@printf "	$(GREEN)─────────────────────────────────────────$(DEF_COLOR)\n"

%.o: %.c $(HEADER)
	@printf "$(CYAN)⚙  %-16s$(DEF_COLOR) %-20s $(CYAN)->$(DEF_COLOR) $(GREEN)%s$(DEF_COLOR)\n" "[COMPILANDO]" "$<" "$@"
	@$(CC) $(CFLAGS) -c $< -o $@

# ==============================================================================
# 6. TESTS UNITARIOS SIMPLIFICADOS (ej: make test_atoi)
# ==============================================================================

test_%: ft_%.c $(NAME)
	@$(CC) $(CFLAGS) -I. $< -L. -lft -o $@ 2>.test_err.log || { \
		if grep -q "main" .test_err.log; then \
			printf "$(YELLOW)---------------------------------------------------------------------\n"; \
			printf "⚠️  $(YELLOW)Reminder: $(WHITE)Descomenta $(YELLOW)main()$(DEF_COLOR) $(WHITE)en $(YELLOW)%s$(DEF_COLOR) $(WHITE)para ejecutar el test$(DEF_COLOR) ⚠️\n" "$<"; \
			printf "$(YELLOW)---------------------------------------------------------------------\n$(DEF_COLOR)"; \
		else \
			printf "$(RED)❌ Error de compilación en %s:$(DEF_COLOR)\n" "$<"; \
			cat .test_err.log; \
		fi; \
		$(RM) .test_err.log; \
		exit 1; \
	}; \
	$(RM) .test_err.log
	@./$@

# ==============================================================================
# 7. REGLAS DE LIMPIEZA ALINEADAS EN COLUMNAS
# ==============================================================================

clean:
	@$(RM) $(OBJS)
	@printf "$(RED)	%-20s$(DEF_COLOR) - Objetos temporales (.o) eliminados.\n" "[LIMPIANDO]"

tclean:
	@$(RM) $(TEST_BINS) .test_err.log
	@printf "$(RED)	%-20s$(DEF_COLOR) - Ejecutables de prueba eliminados.\n" "[LIMPIANDO TESTS]"

fclean: clean tclean
	@$(RM) $(NAME)
	@printf "$(RED)	%-20s$(DEF_COLOR) - Librería $(CYAN)%s$(DEF_COLOR) eliminada.\n" "[LIMPIANDO TODO]" "$(NAME)"

re: fclean
	@printf "$(YELLOW)	%-20s$(DEF_COLOR) - Recompilando todo el proyecto...\n\n" "[RECOMPILANDO]"
	@$(MAKE) all

.PHONY: all clean fclean re tclean
