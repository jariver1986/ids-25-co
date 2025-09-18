# Trabajo Práctico Número 4

## 📖 Uso del repositorio

Este repositorio utiliza [pre-commit](https://pre-commit.com) para validaciones de formato.  
Para trabajar con el mismo debe tener instalado:

1. [pre-commit](https://pre-commit.com/#install)
2. gcc / make
3. (opcional) doxygen para documentación

---

### 🔹 Instalación de pre-commit
Después de clonar el repositorio, ejecute:

```bash
pre-commit install


## 📌 Pasos principales para estructurar el proyecto

1️⃣ **Crear el repositorio** en GitHub.  
2️⃣ **Clonar el repositorio** en la PC y configurar la rama `main`.  
3️⃣ **Organizar carpetas**: `src/` (código fuente), `inc/` (headers), `build/` (binarios).  
4️⃣ **Agregar `README.md`** con la descripción y el uso.  
5️⃣ **Crear `.gitignore`** para ignorar binarios y archivos temporales.  
6️⃣ **Configurar `.clang-format`** ✨ para mantener un estilo de código uniforme.  
7️⃣ **Instalar y configurar `pre-commit`** 🔒 para validaciones automáticas antes de cada commit.  
8️⃣ **Crear un `makefile`** 🛠 con reglas para compilar (`make`), limpiar (`make clean`), formatear (`make format`) y documentar (`make doc`).  
9️⃣ **Agregar código base** en `src/` y cabeceras en `inc/`.  
🔟 **Probar la compilación** con `make` y ejecutar el binario en `build/`.  
1️⃣1️⃣ **Instalar y configurar Doxygen** 📚 para generar documentación (`make doc`).  
1️⃣2️⃣ **Subir los cambios** al repositorio con:  
```bash
git add .
git commit -m "estructura inicial"
git push
