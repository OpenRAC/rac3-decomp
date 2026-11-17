#include "common.h"

typedef struct { u8 pad0[0x68]; struct { u8 pad[4]; s32 idx; } *p68; } O_B;

/* declared by functions of L07_003C0710.c, which this file was cut from */
extern u8 D_001426E0[];
typedef struct { u8 pad0[4]; s16 h4; u8 pad6[0x1E]; } E_003C0ED8;
extern E_003C0ED8 D_L07_002BC920[];
extern s32 func_L07_003C1360(s32);

/* localdecomp:start func_L07_003C1360 */
typedef struct {
    u8 pad0[8];
    s32 i8;
    u8 padC[0x18];
} E_003C1360;

extern u8 D_001426E0[];
extern s32 func_L01_0041A4F0(void);

s32 func_L07_003C1360(s32 arg0) {
    f32 f;
    s32 v;

    f = (f32)((E_003C1360 *)D_L07_002BC920)[arg0].i8;
    v = D_001426E0[arg0 + 0x8E];
    if (v >= 2) {
        f *= 0.1f;
    } else if (v == 1) {
        f *= 0.33f;
    }
    if (func_L01_0041A4F0()) {
        f *= 10.0f;
    }
    return (s32)(f * 0.02f + 0.5f) * 50;
}
/* localdecomp:end func_L07_003C1360 */
