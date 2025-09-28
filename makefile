# --- Directorios ---
SRC_DIR := ./src
INC_DIR := ./inc
OUT_DIR := ./build
OBJ_DIR := $(OUT_DIR)/obj

# --- Archivos ---
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Objetivo por defecto
.DEFAULT_GOAL := all

# Incluir dependencias generadas (-MMD)
-include $(patsubst %.o,%.d,$(OBJ_FILES))

# --- Reglas ---

# Compilar todo y enlazar se elimina de all @mkdir -p $(OUT_DIR)
all: $(OBJ_FILES)
	@echo Enlazando $@
	@gcc $(OBJ_FILES) -o $(OUT_DIR)/app.elf

# Compilar cada .c -> .o (y generar .d)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Compilando $@
	@mkdir -p $(OBJ_DIR)
	@gcc -o $@ -c $< -I $(INC_DIR) -MMD -Wall -Wextra -pedantic -Werror

# Limpiar carpeta build
clean:
	@rm -r $(OUT_DIR)
