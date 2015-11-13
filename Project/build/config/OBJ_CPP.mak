
OBJS:=$(patsubst %.cpp,$(MOD_OBJ_DIR)/%.o,$(wildcard *.cpp))

.PHONY: all clean

all: check $(OBJS)

check:
	chmod 777 -R $(MOD_DIR)

$(MOD_OBJ_DIR)/%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(GFLAG) $(OFLAG) -o $@  -c $<

clean: check
	-rm $(MOD_OBJ_DIR)*
