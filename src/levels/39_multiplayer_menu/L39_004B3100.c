#include "common.h"

/* localdecomp:start func_L39_004B3100 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
} S_004B3100;
extern void func_0011D534(void *, s32, s32);
extern s32 func_00126260(void *);

s32 func_L39_004B3100(s32 a0, s32 a1, s32 a2)
{
    S_004B3100 s;
    func_0011D534(&s, 0, sizeof(s));
    s.f8 = a0;
    s.f4 = a1;
    s.f14 = a2;
    return func_00126260(&s);
}
/* localdecomp:end func_L39_004B3100 */

/* localdecomp:start func_L39_004B3160 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
} S_004B3160;
extern void func_0011D534(void *, s32, s32);
extern s32 func_00126060(void *);
extern s32 func_001271D0(s32, s32);
extern void func_00126070(s32);

s32 func_L39_004B3160(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    S_004B3160 s;
    s32 r, x;
    func_0011D534(&s, 0, 0x30);
    s.f4 = a0;
    s.f8 = a1;
    s.fC = a2;
    s.f10 = 0;
    s.f14 = a3;
    s.f20 = a5;
    r = func_00126060(&s);
    if (r <= 0) {
        return r;
    }
    x = func_001271D0(r, a4);
    if (x < 0) {
        func_00126070(r);
        return x;
    }
    return r;
}
/* localdecomp:end func_L39_004B3160 */
