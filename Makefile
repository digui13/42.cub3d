#################################################################################################
# 										VARIABLES												#
#################################################################################################

#	MAKEFLAGS += --silent									# Silent the output makefile default msgs

# Executable name
EXEC_NAME					=	cub3d

# Compiler program
COMP						=	gcc

#############################
#			FLAGS			#
#############################
# Warnings that are risky or suggest there may have been an error
WAR_F						=	-Wall -Wextra -Werror

# Detect memory access error such as use-after-free and memory leaks
SAN_F						=	-g -fsanitize=address

# Add the directory incs to the list of directories to be searched for header files during preprocessing.
INC_F						=	-I incs

# Change the name of output file
OUT_F						=	-o

# Compile or assemble the source files, but do not link
CPL_F						=	-c

#MLX_FLAGS 			=		-Imlx -lmlx -framework OpenGL -framework AppKit

#############################
#			LIBRARY			#
#############################
# The archive library is a collection of files, typically object files, replaces or adds file to archive. If archive does not exist, ar creates
AR							=	ar rc

#############################
#		FOLDER COMMANDS		#
#############################
# Force create directory
CREATE_DIR					=	mkdir -p

# Force delete directory
RM_RF						=	rm -rf

#############################
#			FOLDERS			#
#############################

# Source directory
SRC_DIR						=	srcs

# Object directory
OBJ_DIR						=	objs

# Include directory
INC_DIR						=	incs

# Library directory
LIB_DIR						=	libs

# All directories
ALL_DIRS					=	$(OBJ_DIR) \
								$(LIB_DIR)

#############################
#			FILES			#
#############################

# Source files
SRC_FILES					=	main.c 									\
								$(SRC_DIR)/check_file.c					\
								$(SRC_DIR)/check.c						\
								$(SRC_DIR)/clean.c						\
								$(SRC_DIR)/end.c						\
								$(SRC_DIR)/freesafe.c					\
								$(SRC_DIR)/initialize.c					\
								$(SRC_DIR)/my_funcs.c					\
								$(SRC_DIR)/reading.c					\
								$(SRC_DIR)/set_orientations.c			\
								$(SRC_DIR)/utils.c						\
								$(SRC_DIR)/utils.c						\
								$(SRC_DIR)/gnl/get_next_line_utils.c	\
								$(SRC_DIR)/gnl/get_next_line.c


# Header files
HDR_FILES					=	$(INC_DIR)\cub3d.h 		\
								$(INC_DIR)\functions.h 	\
								$(INC_DIR)\macros.h 	\
								$(INC_DIR)\structs.h

# Lib files
LIB_FILE					=	$(EXEC_NAME).a

# Object files
OBJ_FILES					=	$(SRC_FILES:%.c=$(OBJ_DIR)/%.o) $(SRC_FILES:srcs/%.c=$(OBJ_DIR)/srcs/%.o) $(SRC_FILES:srcs/gnl/%.c=$(OBJ_DIR)/srcs/gnl/%.o)

#################################################################################################
# 										RULES/TARGETS											#
#################################################################################################

# all
all: $(EXEC_NAME)

# Compile C Files to Object Files
# $< = first dependece
# $@ = value of rule/target
$(OBJ_DIR)/%.o: %.c
	${COMP} $(WAR_F) $(SAN_F) $(INC_F) $(CPL_F) $< $(OUT_F) $@

# Build Project
$(EXEC_NAME): $(ALL_DIRS) ${OBJ_FILES}
	${AR} $(LIB_DIR)/${LIB_FILE} ${OBJ_FILES}
	${COMP} $(WAR_F) $(SAN_F) $(LIB_DIR)/${LIB_FILE} $(OUT_F) $(EXEC_NAME)

# Clean Project
clean:
					${RM_RF} ${OBJ_DIR}
					${RM_RF} $(EXEC_NAME)

fclean:				clean
					${RM_RF} $(LIB_DIR)

# Clean and Build Project
re:					fclean all

# All directories
# Rule/target doesnt exist? then execute (works like that for anyone)
$(ALL_DIRS):
	$(CREATE_DIR) $(OBJ_DIR)
	$(CREATE_DIR) $(OBJ_DIR)/$(SRC_DIR)
	$(CREATE_DIR) $(OBJ_DIR)/$(SRC_DIR)/gnl
	$(CREATE_DIR) $(LIB_DIR)

# Phony (reserve the "key" names to avoid conflits)
.PHONY:				all clean fclean re