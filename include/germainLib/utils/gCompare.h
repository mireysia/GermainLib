#ifndef __G_COMPARE_H__
#define __G_COMPARE_H__

#include <stdbool.h>

#include "gElement.h"

typedef bool (*compare)( gElement_t one, gElement_t two);

#endif