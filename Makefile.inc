mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS += 

APPL_CXXOBJS += \
    SonarSensorDriver.o \
    ObjectDetecter.o \

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIR += \
    $(mkfile_path)/Detecters \
    $(mkfile_path)/Devices \

INCLUDES += \
    -I$(mkfile_path)/Detecters \
    -I$(mkfile_path)/Devices \
