# 该文件用于定义build的配置

# 此处定义不同模块的路径地址 --- bin
export MOD_BIN_COROUTINE_DIR := $(PJ_SRC_APP_DIR)/coroutine
export MOD_BIN_CALC_DIR :=  $(PJ_SRC_APP_DIR)/calc

# 此处定义不同模块的路径地址 --- lib
export MOD_LIB_CO_DIR := $(PJ_SRC_LIB_DIR)/libco
export MOD_LIB_LOG_DIR := $(PJ_SRC_LIB_DIR)/liblog

# 此处定义build的路径地址 --- bin
export BUILD_BIN_COROUTINE_DIR := $(MOD_BIN_COROUTINE_DIR)/build
export BUILD_BIN_CACL_DIR := $(MOD_BIN_CALC_DIR)/build

# 此处定义build的路径地址 --- lib
export BUILD_LIB_CO_DIR := $(MOD_LIB_CO_DIR)/build
export BUILD_LIB_LOG_DIR := $(MOD_LIB_LOG_DIR)/build


# 注意路径引用的先后顺序
export BUILD_DIRS_APP := $(BUILD_BIN_MAIN_DIR)
export BUILD_DIRS_LIB := $(BUILD_LIB_LOG_DIR) $(BUILD_LIB_CO_DIR) 
export BUILD_DIRS := $(BUILD_DIRS_LIB) $(BUILD_DIRS_APP)
