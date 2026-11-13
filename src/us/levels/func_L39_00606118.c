#include "common.h"

/* NTSC-U counterpart of func_L39_00608818 (src/levels/shared/L39_006086F8.c) */
/* localdecomp:start func_L39_00606118 */
extern s32 func_003B0470_00606118();
extern s32 func_003B0530_00606118();
typedef struct { s32 x0; u8 p4[0x30]; s32 x34; s32 x38; s32 x3C; s32 x40; s32 x44; s32 x48; s32 x4C; s32 x50; s32 x54; s32 x58; } Type1;
extern u32 func_00194E90();

/* from rac4-decomp's func_004EFE28, renamed */
void func_L39_00606118(s32 *arg0) {
    Type1 *o = (Type1 *)arg0;
    s32 s0, s1, s2, s3;
    s32 n = 0;
    s32 var1, pos;
    s32 v, sz, mod, len, var2;
    s32 t;
    switch (o->x0) {
    case 1:
        s0 = o->x48 + o->x50 % o->x4C;
        s1 = o->x4C - o->x50;
        s2 = 0;
        s3 = 0;
        break;
    case 2:
        t = func_00194E90() & 0xFFFFFF;
        func_003B0470_00606118(&s0, &s1, &s2, &s3, o, t - o->x48);
        break;
    case 3:
        return;
    }
    v = o->x3C;
    sz = v / 1024 * 1024;
    mod = (o->x38 - v + o->x40) % o->x40;
    len = o->x40 - mod;
    if (sz < len) len = sz;
    var2 = sz - len;
    var1 = o->x34;
    pos = var1 + mod;
    if (s1 + s3 >= 0x400 && len + var2 >= 0x400) {
        n = func_003B0530_00606118(o, s0, s1, s2, s3, pos, len, var1, var2);
    }
    o->x3C -= n;
    o->x50 += n;
    o->x58 = (o->x58 + n) % o->x4C;
}
/* localdecomp:end func_L39_00606118 */
