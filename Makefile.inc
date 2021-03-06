mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=

APPL_CXXOBJS += \
    ObjectDetecter.o \
    GrayLineDetecter.o \
    PointDetecter.o \
    DistanceDetecter.o \
    DirectionDetecter.o \
    ColorDetecter.o \
    BlackLineDetecter.o \
    BrightnessDetecter.o \
    ClockDetecter.o \
    AdaptiveDirectionDetecter.o \
    GotAnswerDetecter.o \
    SonarSensorDriver.o \
    TouchSensorDriver.o \
    ColorSensorDriver.o \
    WheelMotorDriver.o \
    ArmMotorDriver.o \
    TailMotorDriver.o \
    RunCommander.o \
    ArmCommander.o \
    TailCommander.o \
    WheelInfo.o \
    Localization.o \
    CourceMonitor.o \
    Lot.o \
    SpeedCal.o \
    UI.o \
    PID.o \
    PIDController.o \
    Filter.o \
    Logger.o \
    RunStatus.o \
    CourseRun.o \
    Parking.o \
    Stop.o \
    Wait.o \
    RunStyle.o \
    LineTrace.o \
    Grid.o \
    Straight.o \
    Turning.o \
    Spin.o \
    Clothoid.o \
    RunPattern.o \
    RunManager.o \
    AIRun.o \
    AnalogLog.o \
    DigitalLog.o \
    AIAnswer.o \
    Dijkstra.o \
    Game.o \
    AiBlockMove.o \
    Block.o \
    Answer.o \

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIR += \
    $(mkfile_path)/Detecters \
    $(mkfile_path)/Devices \
    $(mkfile_path)/Observer \
    $(mkfile_path)/UI \
    $(mkfile_path)/Utils \
    $(mkfile_path)/RunStyles \
    $(mkfile_path)/RunMethods \
    $(mkfile_path)/RunMethods/Commanders \
    $(mkfile_path)/RunMethods/Status \
    $(mkfile_path)/AI \

INCLUDES += \
    -I$(mkfile_path)/Detecters \
    -I$(mkfile_path)/Devices \
    -I$(mkfile_path)/Observer \
    -I$(mkfile_path)/UI \
    -I$(mkfile_path)/Utils \
    -I$(mkfile_path)/RunStyles \
    -I$(mkfile_path)/RunMethods \
    -I$(mkfile_path)/RunMethods/Commanders \
    -I$(mkfile_path)/RunMethods/Status \
    -I$(mkfile_path)/AI \
