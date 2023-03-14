//
// Created by Deea on 3/11/2023.
//

#ifndef LAB_2_4_VALIDATE_H
#define LAB_2_4_VALIDATE_H
#include <string.h>
#include "../model/electronic.h"
/*
 * validating electronic:
 *          -> id>0
 *          ->strlen(type)>0
 *          ->strlen(producer)>0
 *          ->strlen(model)>0
 *          ->price>0
 *          ->quantity>=0
 */
int validate(Electronic* electronic);

#endif //LAB_2_4_VALIDATE_H
