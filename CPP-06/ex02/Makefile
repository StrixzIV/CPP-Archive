CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SOURCE_PATH = 
INCLUDE_PATH = 
BUILD_PATH = build

CXXFILES = main.cpp

NAME = dyn_cast

SOURCES := $(addprefix $(SOURCE_PATH), $(CXXFILES))
OBJS = $(SOURCES:.cpp=.o)
OBJS_BUILD = $(addprefix $(BUILD_PATH)/, $(OBJS))

all: $(BUILD_PATH) $(NAME)

$(BUILD_PATH):
	@mkdir -p build

$(BUILD_PATH)/%.o: %.cpp Makefile
	@$(CXX) $(CXXFLAGS) -o $@ -c $< && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS_BUILD)
	@$(CXX) $(OBJS_BUILD) -o $(NAME) && printf "Linking: $(notdir $@)\n"

clean:
	rm -rf build

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
