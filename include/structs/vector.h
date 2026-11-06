#ifndef STRUCTS_VECTOR_H
#define STRUCTS_VECTOR_H

#include "common.h"

/* Four floats. The game keeps positions, velocities and matrix rows in 16-byte slots (x, y, z and
 * a w that is often unused); this type has 4-byte alignment, so a field of it lands exactly where
 * its offset says. */
typedef struct Vec4f {
    f32 x, y, z, w;
} Vec4f;

#endif /* STRUCTS_VECTOR_H */
