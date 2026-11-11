#include "common.h"

typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
typedef struct { u8 b[16]; } V16_003E6F50;

/* localdecomp:start func_L01_0051BBB8 */
extern s32 func_L01_0051BBB8(u8 *p, s32 a, s32 b);
extern void func_003EDAD0(void *, s32, s32);
extern s32 D_L01_001DC1B0;

s32 func_L01_0051BBB8(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC1B0)) {
        func_003EDAD0(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051BBB8 */

/* localdecomp:start func_L01_0051BC20 */
extern s32 func_L01_0051BC20(u8 *p, s32 a, u8 *out);
extern s32 func_003EDAF8();
extern s32 D_L01_001DC1B0_0051BC20;

s32 func_L01_0051BC20(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC1B0_0051BC20)) {
        *out = func_003EDAF8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051BC20 */

/* localdecomp:start func_L01_0051BC88 */
extern s32 func_L01_0051BC88(u8 *p, s32 a, s32 b);
extern void func_003EDB08_0051BC88();
extern s32 D_L01_001DC1B0_0051BC88;

s32 func_L01_0051BC88(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC1B0_0051BC88)) {
        func_003EDB08_0051BC88(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051BC88 */

/* localdecomp:start func_L01_0051BCF0 */
extern s32 func_L01_0051BCF0(u8 *p, s32 a, s32 b);
extern void func_003EDB40_0051BCF0();
extern s32 D_L01_001DC1B0_0051BCF0;

s32 func_L01_0051BCF0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC1B0_0051BCF0)) {
        func_003EDB40_0051BCF0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051BCF0 */
