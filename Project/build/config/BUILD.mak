# ���ļ����ڶ���build������

# �˴����岻ͬģ���·����ַ --- bin
export MOD_BIN_ROUTINE_DIR := $(PJ_SRC_APP_DIR)/coroutine

# �˴����岻ͬģ���·����ַ --- lib
export MOD_LIB_CO_DIR := $(PJ_SRC_LIB_DIR)/libco
export MOD_LIB_LOG_DIR := $(PJ_SRC_LIB_DIR)/liblog

# �˴�����build��·����ַ --- bin
export BUILD_BIN_COROUTINE_DIR := $(MOD_BIN_ROUTINE_DIR)/build

# �˴�����build��·����ַ --- lib
export BUILD_LIB_CO_DIR := $(MOD_LIB_CO_DIR)/build
export BUILD_LIB_LOG_DIR := $(MOD_LIB_LOG_DIR)/build


# ע��·�����õ��Ⱥ�˳��
export BUILD_DIRS_APP := $(BUILD_BIN_MAIN_DIR)
export BUILD_DIRS_LIB := $(BUILD_LIB_LOG_DIR) $(BUILD_LIB_CO_DIR) 
export BUILD_DIRS := $(BUILD_DIRS_LIB) $(BUILD_DIRS_APP)
