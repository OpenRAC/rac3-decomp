#include "common.h"

/* localdecomp:start func_L39_006B4F50 */
typedef struct V_006B4F50 {
    char _p0[0x14];
    s32 (*f14)(void *, s32);
    char _p1[0x4C];
    s32 (*f64)(void *);
    char _p2[0x20];
    void (*f88)(void *, s32);
    s32 (*f8C)(void *);
} V_006B4F50;
typedef struct C_006B4F50 {
    char _p0[0x60];
    V_006B4F50 *f60;
} C_006B4F50;
typedef struct S_006B4F50 {
    char _p0[0x118];
    C_006B4F50 *f118;
    C_006B4F50 *f11C;
    char _p1[8];
    C_006B4F50 *f128;
    char _p2[8];
    C_006B4F50 *f134;
    char _p3[0x158];
    s32 f290;
    char _p4[0x20];
    s32 f2B4;
    s32 f2B8;
} S_006B4F50;
typedef struct { char _p0[8]; s32 f8; char _pC[4]; s32 f10; } S_Hd;
typedef struct { char _p0[0x1A0]; u32 f1A0; } S_Pd;

extern S_Hd D_001A4560;
extern s32 D_001DDA08_sda;
__asm__(".extern D_001DDA08_sda, 4");
extern s32 D_001DDA04_sda;
__asm__(".extern D_001DDA04_sda, 4");
extern s32 D_001DDA34_sda;
__asm__(".extern D_001DDA34_sda, 4");
extern S_Pd *D_001D5A54_sda_006B4F50;
__asm__(".extern D_001D5A54_sda_006B4F50, 4");
extern u8 D_L39_0037C948[];
extern void func_L39_006B6298(void *);
extern void func_L39_006B5AE0(void *);
extern s32 func_L39_00688350(void *, s32);
extern void func_L39_00685798(s32, s32, s32);
extern s32 func_L39_006B4E28(void *);
extern s32 func_L39_006B4C30(void *);
extern s32 func_L39_006B4EE8(void *);
extern s32 func_L39_006B4B08(void *);

s32 func_L39_006B4F50(S_006B4F50 *o, s32 *ev) {
    s32 a1;
    s32 s1;
    s32 s2;
    if ((D_001DDA08_sda != 0 && D_001A4560.f8 == 2) || (D_001A4560.f8 == 2 && D_001A4560.f10 != 0)) {
        D_001DDA08_sda = 0;
        D_001DDA34_sda = 7;
        return 1;
    }
    if (D_001DDA04_sda != -1 && (D_001D5A54_sda_006B4F50->f1A0 & 1)) {
        func_L39_006B6298(o);
        func_L39_006B5AE0(o);
        return 1;
    }
    if (o->f2B4 != -2) o->f2B4 = 0;
    if (o->f2B8 != -2) o->f2B8 = 0;
    if (D_001DDA04_sda != -1) {
        if (D_L39_0037C948[D_001DDA04_sda * 0x1F0 + 0x50] & 0x80) o->f2B4 = -2;
        if (D_L39_0037C948[D_001DDA04_sda * 0x1F0 + 0x50] & 0x40) o->f2B8 = -2;
    }
    if (o->f290 == 6) {
        a1 = o->f128->f60->f8C(o->f128);
        if ((u32)(*ev - 3) < 2 || *ev == 7) {
            if (*ev == 3) {
                a1--;
                if (a1 < 0) a1 = (o->f2B4 == -2) ? 0x15 : 0x14;
                if (a1 == 0x12) {
                    if (o->f2B8 != -2) a1 = 0x11;
                }
            } else if (*ev == 4 || *ev == 7) {
                a1++;
                if (a1 == 0x12) {
                    if (o->f2B8 != -2) a1 = 0x13;
                }
                if (a1 == 0x15) {
                    if (o->f2B4 != -2) a1 = 0x16;
                }
                if (a1 >= 0x16) a1 = 0;
            }
            o->f128->f60->f88(o->f128, a1);
            func_L39_006B5AE0(o);
            return 1;
        }
    }
    func_L39_006B5AE0(o);
    s2 = func_L39_00688350(o, *ev);
    s1 = o->f290;
    if (s1 == 7) {
        s2 = o->f134->f60->f14(o->f134, *ev);
        if (*ev == s1 || *ev == 3 || *ev == 4) func_L39_00685798(3, 0, 0);
    }
    switch (*ev) {
    case 7:
        if (func_L39_006B4E28(o) != 0) return 1;
        break;
    case 6:
        if (func_L39_006B4C30(o) != 0) return 1;
        s2 = 1;
        break;
    case 5:
        if (func_L39_006B4EE8(o) != 0) return 1;
        break;
    case 3:
    case 4:
        if (o->f290 != 2) return 1;
        if (o->f118->f60->f64(o->f118) != 0) o->f11C->f60->f14(o->f11C, 7);
        break;
    }
    if (func_L39_006B4B08(o) != 0) return 1;
    return s2 != 0;
}
/* localdecomp:end func_L39_006B4F50 */
