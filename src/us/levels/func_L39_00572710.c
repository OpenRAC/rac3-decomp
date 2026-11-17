#include "common.h"

typedef struct {
    u8 pad0[0x46];
    s16 timer;
    s16 age;
} Object_L39_00572710;

typedef struct {
    u8 pad0[0x1C];
    Object_L39_00572710 *object;
} Entry_L39_00572710;

/* localdecomp:start func_L39_00572710 */
extern Entry_L39_00572710 *D_L39_0024B950;
extern u8 *func_L39_00577EE8(s32, s32);

/* Looks up an object's age and timer from the entry chosen by func_L39_00577EE8(0, 0x21); returns 1
 * if age >= 0x97 (in mode 0 also requires the timer to be 0 or less), else 0. */
s32 func_L39_00572710(s32 mode) {
    u8 *current = func_L39_00577EE8(0, 0x21);
    s32 result = 0;
    s32 index = *(s16 *)(current + 0x84);
    Object_L39_00572710 *object = D_L39_0024B950[index].object;
    if (mode != 0) {
        if (object->age >= 0x97) {
            goto yes;
        }
        goto done;
    } else {
        if (object->age < 0x97) {
            goto done;
        }
        if (object->timer > 0) {
            goto done;
        }
    }
yes:
    result = 1;
done:
    return result;
}
/* localdecomp:end func_L39_00572710 */
