#include "common.h"

typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;

typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_0051C650;

/* localdecomp:start func_L01_0051C5E8 */
extern s32 func_L01_0051C5E8(u8 *p, f32 a, f32 b);

extern s32 D_L01_001DC240_0051C5E8[];
s32 func_L01_0051C5E8(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC240_0051C5E8[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051C5E8 */

/* localdecomp:start func_L01_0051C650 */
extern s32 D_L01_001DC240_0051C650;
extern void func_003EDB78();
extern s32 func_L01_0051C650(u8 *p, s32 a, s32 b);

s32 func_L01_0051C650(u8 *p, s32 a, s32 b) {
    if ((*(VT_0051C650 **)(p + 8))->isA(p, D_L01_001DC240_0051C650)) {
        func_003EDB78(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051C650 */

/* localdecomp:start func_L01_0051C6B8 */
extern s32 func_L01_0051C6B8(u8 *p, f32 a, f32 b);
extern s32 D_L01_001DC240_0051C6B8[];

s32 func_L01_0051C6B8(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC240_0051C6B8[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051C6B8 */
