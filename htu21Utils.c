#include "htu21Utils.h"

int htu21Init(int i2c_bus_number)
{
        int file;
        int adapter_nr = i2c_bus_number; /* probably dynamically determined */
        char filename[20];

        snprintf(filename, 19, "/dev/i2c-%d", adapter_nr);
        file = open(filename, O_RDWR);
        if (file < 0) {
                printf("ERROR HANDLING; you can check errno to see what went wrong");
                exit(1);
        }

        int addr = HTU21_ADDR;

        if (ioctl(file, I2C_SLAVE, addr) < 0)
        {
                printf("ERROR HANDLING; you can check errno to see what went wrong");
                exit(1);
        }

        return file;
}

void htu21SoftReset(int fileInput)
{
        i2c_smbus_write_byte(fileInput,HTU21_RESET);
        usleep(US_100_MS);
}

float htu21TriggerTempMeasurment(int fileInput)
{
        char buf[20];
        buf[0] = HTU21_TRIGGER_T_MEASURMENT;
        int bytesWrote = write(fileInput, buf, 1);
        if (bytesWrote != 1)
        {
                printf("ERROR HANDLING: I2C transaction failed; %d\n", bytesWrote);
                return 1;
        }
        usleep(US_100_MS);
        if(read(fileInput, buf,2)!=2)
        {
                printf("echec");
                return -1;
        }
        else
        {
                uint16_t raw= (buf[0]<<8)|buf[1];
                float mesure = -46.85f + 175.72f * ((float)raw/(float)65536);
                return mesure;
        }
}


float htu21TriggerHumMeasurment(int fileInput)
{
        char buf[20];
        buf[0] = HTU21_TRIGGER_H_MEASURMENT;
        int bytesWrote = write(fileInput, buf, 1);
        if (bytesWrote != 1)
        {
                printf("ERROR HANDLING: I2C transaction failed; %d\n", bytesWrote);
                return 1;
        }
        usleep(US_100_MS);
        if(read(fileInput, buf,2)!=2)
        {
                printf("echec");
                return -1;
        }
        else
        {
                uint16_t raw= (buf[0]<<8)|buf[1];
                float mesure = -6.0f + 125.0f * ((float)raw/(float)65536);
                return mesure;
        }
}
