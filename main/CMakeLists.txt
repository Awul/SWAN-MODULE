idf_component_register(
    SRCS "main.c"
    INCLUDE_DIRS "."
    REQUIRES i2c_bus driver veml7700 sht40 im72d128 wifi_manager swan_mqtt_client json_payload)

