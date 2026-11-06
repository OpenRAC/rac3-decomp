#include "common.h"

/* localdecomp:start func_L01_0034DF10 */
void func_L01_0034DF10(char *object) {
    char *state = *(char **)(object + 0x68);
    s32 index;
    for (index = 0; index < 10; index++) {
        *(s32 *)(*(char **)(state + 0) + index * 16 + 0) = 0;
        *(s32 *)(*(char **)(state + 0) + index * 16 + 4) = 0;
        *(s32 *)(*(char **)(state + 0) + index * 16 + 8) = 0;
        *(f32 *)(*(char **)(state + 0) + index * 16 + 12) = 1.0f;
    }
    for (index = 0; index < 20; index++) {
        *(s32 *)(*(char **)(state + 4) + index * 16 + 0) = 0;
        *(s32 *)(*(char **)(state + 4) + index * 16 + 4) = 0;
        *(s32 *)(*(char **)(state + 4) + index * 16 + 8) = 0;
        *(f32 *)(*(char **)(state + 4) + index * 16 + 12) = 1.0f;
    }
    *(s32 *)(state + 0xC) = 0;
    *(s16 *)(state + 0x1C) = 6;
    *(s32 *)(state + 0x10) = 0;
    *(s32 *)(state + 0x14) = 0;
    *(s32 *)(state + 0x8) = 0;
}
/* localdecomp:end func_L01_0034DF10 */
