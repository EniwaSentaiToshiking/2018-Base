mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS += 

APPL_CXXOBJS += \
    SonarSensorDriver.o \
    ObjectDetecter.o \
    TouchSensorDriver.o \
    UI.o \
    ColorSensorDriver.o \
    WheelMotorDriver.o \
    ArmMotorDriver.o \
    TailMotorDriver.o \
    PID.o \
    PIDController.o \
    Filter.o \
    Localization.o \
    RunCommander.o \

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIR += \
    $(mkfile_path)/Detecters \
    $(mkfile_path)/Devices \
    $(mkfile_path)/UI \
    $(mkfile_path)/Utils \
    $(mkfile_path)/RunMethods \

INCLUDES += \
    -I$(mkfile_path)/Detecters \
    -I$(mkfile_path)/Devices \
    -I$(mkfile_path)/UI \
    -I$(mkfile_path)/Utils \
    -I$(mkfile_path)/RunMethods \
