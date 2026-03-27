/***************************************************************************/
/***************************************************************************/
/***********************    Author  : Golden        ************************/
/***********************    Layer   : APP           ************************/
/***********************    SWC     : GPS_Example   ************************/
/***********************    Version : 1.00          ************************/
/***********************    Date    : 22/07/2025    ************************/
/***************************************************************************/
/***************************************************************************/

#include "STD_TYPES.h"
#include "GPS_interface.h"
#include "UART_interface.h"

int main(void)
{
	u8 status;
	u8 sats;
	float32 lat, lon, alt, spd;
	u8 h, m, s;

	UART_INTI();

	/* Initialize GPS driver */
	status = GPS_voidInit();
	if (!status) {
		/* Initialization failed: handle error (blink LED) */
		while (1) {
			/* Error loop */
		}
	}

	while (1)
	{
		/* Update GPS data: reads and parses new NMEA sentences */
		if (GPS_voidUpdate())
		{
			/* Retrieve parsed values */
			sats = GPS_u8GetSatelliteCount();
			lat  = GPS_f32GetLatitude();
			lon  = GPS_f32GetLongitude();
			alt  = GPS_f32GetAltitude();
			spd  = GPS_f32GetSpeed();
			GPS_u8GetUTCTime(&h, &m, &s);

			if (sats < 4)
			{
				/* Not enough satellites: maybe signal poor, wait */
				continue;
			}

			/* Use location:  if lat > threshold, take action */
			if (lat > 30.0f)
			{
				// doSomething();
			}

			/* Use time: schedule event at specific UTC hour */
			if (h == 12 && m == 0)
			{
				// triggerNoonEvent();
			}

			/* Use speed: if moving too fast, warn */
			if (spd > 20.0f)
			{
				// alarmHighSpeed();
			}

			/* Use altitude: detect landing */
			if (alt < 5.0f)
			{
				// landingSequence();
			}
		}

		/* Other main loop tasks... */
	}

	return 0;
}
