#include "common.h"

/* NTSC-U counterpart of func_L07_003E2B80. */

/* localdecomp:start func_U_L07_003E0D90 */
typedef int Q_003E2B80 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003E2B80;
extern V_003E2B80 D_001A4C60;
extern f32 D_U_001E1ED8[];
extern void func_U_00442528(u8 *, s32, s32);
void func_U_L07_003E0D90(u8 *m) {
    void func_U_003E0FC0(u8 *);
    extern void func_U_003E10D8(u8 *);
    extern void func_U_003E1158(u8 *, void *);
    extern void func_U_003E1408(u8 *);
    s32 func_U_00440CD0(void *, s32, s32);
    f32 func_U_0040D820(f32, f32);
    f32 func_U_0040D7D8(f32, f32);
    f32 func_U_0040CCD8(f32);
    f32 func_U_0040CCF0(f32);
    void func_U_003E1260(u8 *, void *, f32);
    void func_U_003E1430(u8 *);
    void func_U_0044BF10(u8 *, void *, s32, f32, f32);
    extern void func_U_003E1598(u8 *, s32);
    u8 *p;
    V_003E2B80 a, b;
    f32 angle;
    if (m[0x20] == 0) func_U_003E0FC0(m);
    func_U_003E10D8(m);
    if (m[0x31] || (u32)(m[0x20]-3) < 2) {
        p = *(u8 **)(m+0x68);
        switch (m[0x20]) {
        case 1: break;
        case 2:
            func_U_003E1158(m,m+0x10);
            func_U_003E1408(m);
            if (func_U_00440CD0(&D_001A4C60,*(s32 *)(p+0x258),0)) func_U_00442528(m,3,-1);
            break;
        case 3:
            angle = func_U_0040D820(D_U_001E1ED8[0],*(f32 *)(p+0x260)*0.017453292f);
            { f32 delta = angle * *(f32 *)(p+0x26C);
            angle = func_U_0040D7D8(*(f32 *)(p+0x260)*0.017453292f,delta); }
            *(Q_003E2B80 *)&b = 0;
            b.x = *(f32 *)(p+0x264) * func_U_0040CCD8(angle);
            b.y = *(f32 *)(p+0x264) * func_U_0040CCF0(angle);
            b.z = *(f32 *)(p+0x268);
            *(Q_003E2B80 *)&a = *(Q_003E2B80 *)&b;
            { Q_003E2B80 x, y, r;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001A4C60));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(y), "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(*(V_003E2B80 *)(p+0x220)) : "j"(r)); }
            func_U_003E1158(m,p+0x220);
            func_U_003E1260(m,p+0xD0,*(f32 *)(p+0xE4));
            if (!func_U_00440CD0(&D_001A4C60,*(s32 *)(p+0x258),0)) func_U_00442528(m,2,-1);
            break;
        case 4:
            func_U_003E1430(m);
            break;
        }
        func_U_0044BF10(m,p+0x120,0,0.03f,0.3f);
        func_U_0044BF10(m,p+0x1A0,1,0.03f,0.3f);
        func_U_003E1598(m,2);
        func_U_003E1598(m,3);
    }
}
/* localdecomp:end func_U_L07_003E0D90 */
