

#ifndef GIROUETTE_H
#define GIROUETTE_H


#include "stm32f103xb.h"

void initGirouette(void);
void enableGirouette(void);
void diableGirouette(void);
int GetAngle(void);

#endif
