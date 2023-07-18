#include "htu21Utils.h"

int main()
{
	int adapter_nr = 1; /* probably dynamically determined */
	int file = htu21Init(adapter_nr);
	htu21SoftReset(file);
	float Temp = htu21TriggerTempMeasurment(file);
	float relHum = htu21TriggerHumMeasurment(file);
	printf("il fait %.1fC, l'humidite relative est de %.1f%%RH\n", Temp, relHum);
	return 0;
}
