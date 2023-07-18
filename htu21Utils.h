#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <i2c/smbus.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#define HTU21_RESET 0xfe
#define HTU21_TRIGGER_T_MEASURMENT 0xf3
#define HTU21_TRIGGER_H_MEASURMENT 0xf5
#define HTU21_ADDR 0x40
#define US_100_MS 100000

int htu21Init(int i2c_bus_number);

void htu21SoftReset(int fileInput);

float htu21TriggerTempMeasurment(int fileInput);

float htu21TriggerHumMeasurment(int fileInput);
