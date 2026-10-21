#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_0044CCC0);

INCLUDE_ASM("asm/levels", func_L01_0044CCC8);

/* localdecomp:start func_L01_0044CD60 */
typedef struct {
    u8 pad0[8];
    s32 w8;
    u8 padC[4];
    s32 w10;
    u8 pad14[0xF0 - 0x14];
} S_449AE8;

extern u8 D_001425C0[];
extern S_449AE8 D_L01_002C5600[];
extern s16 D_001CCFD4[];
extern s32 D_001A71D8[];
extern s32 D_001A71DC[];
extern s32 D_001A71E0[];
extern s32 D_001A71E4[];
extern s32 func_0039AC08(s32);
extern void func_0039AA38(s32);
extern void func_L01_005078C0(s32);

s32 func_L01_0044CD60(s32 id) {
    s32 ret;
    s32 st;
    u8 *ip;
    S_449AE8 *tbl;
    S_449AE8 *e;

    ip = D_001425C0 + id;
    tbl = D_L01_002C5600;
    ret = 0;
    e = tbl + *ip;
    st = e->w8;
    if (st == 0) {
        if (func_0039AC08(e->w10) != 0 || D_001CCFD4[0] == 0) {
            D_001A71D8[0] = id;
            func_L01_005078C0(id);
            if (func_0039AC08((tbl + *ip)->w10) == 0) {
                func_0039AA38((tbl + *ip)->w10);
            }
            ret = 1;
        }
    } else if (st == 3) {
        D_001A71E4[0] = id;
        ret = 1;
    } else if (st == 2) {
        D_001A71E0[0] = id;
        ret = 1;
    } else if (st == 1) {
        D_001A71DC[0] = id;
        ret = 1;
    }
    return ret;
}
/* localdecomp:end func_L01_0044CD60 */

INCLUDE_ASM("asm/levels", func_L01_0044CE88);

INCLUDE_ASM("asm/levels", func_L01_0044D360);

/* localdecomp:start func_L01_0044DF00 */
extern s32 D_00143950[];
extern f32 D_001D5308;
extern f32 D_001D530C;
extern f32 D_001D5310;
extern f32 D_001D5314;
extern f32 D_001D5318;
extern f32 D_001D531C;
extern s32 D_001D5320;
extern f32 D_001D5324;

void func_L01_0044DF00(s32 a0) {
    if (a0 == 0) {
        D_00143950[0] = 0;
        D_001D5308 = 1.0f;
        D_001D530C = 1.0f;
        D_001D5310 = 1.0f;
        D_001D5314 = 0.0166666675f;
        D_001D5318 = 0.000277777785f;
        D_001D531C = 4.62962953e-06f;
        D_001D5320 = 5;
        D_001D5324 = 0.0166666675f;
    } else {
        D_00143950[0] = 1;
        D_001D5308 = 1.20000005f;
        D_001D530C = 1.44000006f;
        D_001D5310 = 0.833333313f;
        D_001D5314 = 0.0200000014f;
        D_001D5318 = 0.000400000019f;
        D_001D531C = 7.99999998e-06f;
        D_001D5320 = 6;
        D_001D5324 = 0.0199999996f;
    }
}
/* localdecomp:end func_L01_0044DF00 */

LINKER_REMNANT("asm/levels", func_L01_0044E020);
