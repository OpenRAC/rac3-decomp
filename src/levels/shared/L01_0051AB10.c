#include "common.h"

typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
typedef struct { u8 b[16]; } V16_003E6F50;


/* localdecomp:start func_L01_0051AB10 */
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E_0051AB10;

extern s32 func_L01_0051AB10(u8 *p, f32 a, f32 b);
extern s32 D_L01_001DC1E0_0051AB10[];

s32 func_L01_0051AB10(u8 *p, f32 a, f32 b) {
    if ((*(VT_E_0051AB10 **)(p + 8))->isA(p, D_L01_001DC1E0_0051AB10[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051AB10 */
