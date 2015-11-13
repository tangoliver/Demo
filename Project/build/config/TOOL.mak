# 该文件用于定义编译工具

# 交叉编译定制
#ifneq ($(_LINUX), 1)
#	export CROSS_TOOLS := mipsel-linux-uclibc-
#endif


# 避免和环境变量冲突, 统一加上前缀
export MY_CC := $(CROSS_TOOLS)gcc
export MY_CXX := $(CROSS_TOOLS)g++
export MY_AR := $(CROSS_TOOLS)ar
export MY_LD := $(CROSS_TOOLS)ld
export MY_RANLIB := $(CROSS_TOOLS)ranlib
export MY_STRIP := $(CROSS_TOOLS)strip
