#include <stdio.h>
#include <bcm2835.h>
#include <pthread.h>
#include <unistd.h>

#define GREEN1 RPI_GPIO_P1_07
#define YELLOW1 RPI_GPIO_P1_11
#define RED1 RPI_GPIO_P1_15

#define GREEN2 RPI_V2_GPIO_P1_29
#define YELLOW2 RPI_V2_GPIO_P1_33
#define RED2 RPI_V2_GPIO_P1_37


void *lightOne(void*arg){
	unsigned int delay = 1000;
	unsigned int fiveDelay = 5000;
	unsigned int fourDelay = 4000;
	
	while(1){
		bcm2835_gpio_set(GREEN1);
		bcm2835_delay(fourDelay);
		bcm2835_gpio_clr(GREEN1);
		bcm2835_gpio_set(YELLOW1);
		bcm2835_delay(delay);
		bcm2835_gpio_clr(YELLOW1);
		bcm2835_gpio_set(RED1);
		bcm2835_delay(fiveDelay);
		bcm2835_gpio_clr(RED1);
	}
	pthread_exit(0);
}

void *lightTwo(void*arg){
	unsigned int delay = 1000;
	unsigned int fiveDelay = 5000;
	unsigned int fourDelay = 4000;
	
	while(1){
		bcm2835_gpio_set(RED2);
		bcm2835_delay(fiveDelay);
		bcm2835_gpio_clr(RED2);
		bcm2835_gpio_set(GREEN2);
		bcm2835_delay(fourDelay);
		bcm2835_gpio_clr(GREEN2);
		bcm2835_gpio_set(YELLOW2);
		bcm2835_delay(delay);
		bcm2835_gpio_clr(YELLOW2);
	}
	pthread_exit(0);
}

int main(int argc, char **argv)
{
	if(!bcm2835_init()){
		return 1;
	}
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

	
	pthread_t lightA;
	pthread_attr_t attrA;
	pthread_attr_init(&attrA);
	
	pthread_t lightB;
	pthread_attr_t attrB;
	pthread_attr_init(&attrB);
	
	if(pthread_create(&lightA, &attrA, lightOne, NULL)){
		printf("ERROR");
		return 1;
	}
	
	if(pthread_create(&lightB, &attrB, lightTwo, NULL)){
		printf("ERROR");
		return 1;
	}
	
	
	pthread_join(lightA, NULL);
	pthread_join(lightB, NULL);

	return 0;
}

