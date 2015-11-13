# 该文件为总的Makefile文件

PWD := $(shell pwd)
export PJ_DIR := $(PWD)/..

include ./config/OS.mak
include ./config/TOOL.mak
include ./config/PATH.mak
include ./config/BUILD.mak


#######################################################################
#all modules build 
#######################################################################
.PHONY: all $(BUILD_DIRS) clean

all: app lib

all_clean: app_clean lib_clean

#######################################################################
#app modules build 
#######################################################################
app: coroutine

app_clean: coroutine_clean

coroutine: 
	@$(MAKE) --directory=$(BUILD_BIN_COROUTINE_DIR)
coroutine_clean:
	@$(MAKE) --directory=$(BUILD_BIN_COROUTINE_DIR) clean

#######################################################################
#lib modules build 
#######################################################################
lib: liblog libco

lib_clean: libco_clean liblog_clean

liblog: 
	@$(MAKE) --directory=$(BUILD_LIB_LOG_DIR)
liblog_clean: 
	@$(MAKE) --directory=$(BUILD_LIB_LOG_DIR) clean 

libco: 
	@$(MAKE) --directory=$(BUILD_LIB_CO_DIR)
libco_clean: 
	@$(MAKE) --directory=$(BUILD_LIB_CO_DIR) clean