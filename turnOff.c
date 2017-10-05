#include <stdio.h>
#include <bcm2835.h>

#define GREEN1 RPI_GPIO_P1_07
#define YELLOW1 RPI_GPIO_P1_11
#define RED1 RPI_GPIO_P1_15

#define GREEN2 RPI_V2_GPIO_P1_29
#define YELLOW2 RPI_V2_GPIO_P1_33
#define RED2 RPI_V2_GPIO_P1_37


int main(int argc, char **argv)
{
	if(!bcm2835_init()){
		return 1;
	}
	
	bcm2835_gpio_fsel(GREEN1, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(YELLOW1, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(RED1, BCM2835_GPIO_FSEL_OUTP);
	
	bcm2835_gpio_fsel(GREEN2, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(YELLOW2, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(RED2, BCM2835_GPIO_FSEL_OUTP);
	
	bcm2835_gpio_clr(GREEN1);
	bcm2835_gpio_clr(YELLOW1);
	bcm2835_gpio_clr(RED1);
	bcm2835_gpio_clr(GREEN2);
	bcm2835_gpio_clr(YELLOW2);
	bcm2835_gpio_clr(RED2);

	return 0;
}

