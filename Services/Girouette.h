

#ifndef GIROUETTE_H
#define GIROUETTE_H


#include "stm32f103xb.h"

static int INITIALANGLE = 0x011B;
void initGirouette(void);
void enableGirouette(void);
void diableGirouette(void);
int GetAngle(void);
void setIndex(void);

#endif
