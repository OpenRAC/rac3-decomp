#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    u8 *object;
} Entry_L39_005726D0;

/* localdecomp:start func_L39_005726D0 */
extern Entry_L39_005726D0 *D_L39_0024B950;
extern u8 *func_L39_00577EE8(s32, s32);

/* Looks up an object with func_L39_00577EE8(0, 0x21) and sets field 0x46 of its table item to 30. */
void func_L39_005726D0(void) {
    u8 *object = func_L39_00577EE8(0, 0x21);
    s32 index = *(s16 *)(object + 0x84);
    u8 *item = D_L39_0024B950[index].object;
    *(s16 *)(item + 0x46) = 30;
}
/* localdecomp:end func_L39_005726D0 */
