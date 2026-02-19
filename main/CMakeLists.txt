idf_component_register(
    SRCS "main.c"
    INCLUDE_DIRS "."
    REQUIRES i2c_bus driver veml7700 )

