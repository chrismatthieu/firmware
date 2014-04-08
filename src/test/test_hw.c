#include "hw.h"
#include "tessel.h"
#include "tm.h"

static const int SPI_SS = E_G1;

void test_hw_spi (void)
{
	TM_DEBUG("HEY NOW");
	hw_spi_initialize(TESSEL_SPI_0, 100000, HW_SPI_MASTER, HW_SPI_LOW, HW_SPI_FIRST, HW_SPI_FRAME_NORMAL);
	hw_digital_write(SPI_SS, 1);

	hw_digital_write(LED1, 1);

	hw_wait_ms(5000);

	while (1) {
		// enable slave select
		hw_digital_write(SPI_SS, 0);
		hw_digital_write(LED2, 1);
		// hw_digital_write(SPI_SS, 0);

		// send test string
		const char * p = "Hello, world! This is a very long string that I'm sending over SPI.\n";
		hw_spi_send(TESSEL_SPI_0, (uint8_t*) p, strlen(p));

		// disable slave select
		hw_digital_write(SPI_SS, 1);
		hw_digital_write(LED2, 0);

		// delay for 1 second
		hw_wait_ms(1000);
	}
}