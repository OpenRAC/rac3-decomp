/* PAL near miss (sonnet-w4): 0 words differ (MATCH) with the file flags plus -mvu0-use-vf0-vf2 (check.py --flags="-O2 -G8 -fopt-stack -mno-check-zero-division -mvu0-use-vf0-vf2"); with the current line in config/levels/text_parts.txt (no vf2) the j-form asm fails to compile. Needs -mvu0-use-vf0-vf2 added to L07_003E2B80.c line, then integrate in src. */
#include "common.h"
typedef int Q_003E2B80 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003E2B80;
extern V_003E2B80 D_001A4C60;
extern f32 D_L07_001E1ED8[];
extern void func_L01_004450F0(u8 *, s32, s32);
void func_L07_003E2B80(u8 *m) {
    void func_L07_003E2DB0(u8 *);
    extern void func_L07_003E2EC8(u8 *);
    void func_L07_003E2F48(u8 *, void *);
    extern void func_L07_003E31F8(u8 *);
    s32 func_00382380(void *, s32, s32);
    f32 func_0038DB00(f32, f32);
    f32 func_0038DAB8(f32, f32);
    f32 func_0038D098(f32);
    f32 func_0038D0B0(f32);
    void func_L07_003E3050(u8 *, void *, f32);
    void func_L07_003E3220(u8 *);
    void func_L01_0044E850(u8 *, void *, s32, f32, f32);
    void func_L07_003E3388(u8 *, s32);
    u8 *p;
    V_003E2B80 a, b;
    f32 angle;
    if (m[0x20] == 0) func_L07_003E2DB0(m);
    func_L07_003E2EC8(m);
    if (m[0x31] || (u32)(m[0x20]-3) < 2) {
        p = *(u8 **)(m+0x68);
        switch (m[0x20]) {
        case 1: break;
        case 2:
            func_L07_003E2F48(m,m+0x10);
            func_L07_003E31F8(m);
            if (func_00382380(&D_001A4C60,*(s32 *)(p+0x258),0)) func_L01_004450F0(m,3,-1);
            break;
        case 3:
            angle = func_0038DB00(D_L07_001E1ED8[0],*(f32 *)(p+0x260)*0.017453292f);
            { f32 delta = angle * *(f32 *)(p+0x26C);
            angle = func_0038DAB8(*(f32 *)(p+0x260)*0.017453292f,delta); }
            *(Q_003E2B80 *)&b = 0;
            b.x = *(f32 *)(p+0x264) * func_0038D098(angle);
            b.y = *(f32 *)(p+0x264) * func_0038D0B0(angle);
            b.z = *(f32 *)(p+0x268);
            *(Q_003E2B80 *)&a = *(Q_003E2B80 *)&b;
            { Q_003E2B80 x, y, r;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001A4C60));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(y), "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(*(V_003E2B80 *)(p+0x220)) : "j"(r)); }
            func_L07_003E2F48(m,p+0x220);
            func_L07_003E3050(m,p+0xD0,*(f32 *)(p+0xE4));
            if (!func_00382380(&D_001A4C60,*(s32 *)(p+0x258),0)) func_L01_004450F0(m,2,-1);
            break;
        case 4:
            func_L07_003E3220(m);
            break;
        }
        func_L01_0044E850(m,p+0x120,0,0.0432f,0.43200004f);
        func_L01_0044E850(m,p+0x1A0,1,0.0432f,0.43200004f);
        func_L07_003E3388(m,2);
        func_L07_003E3388(m,3);
    }
}
/* localdecomp:end func_L07_003E2B80 */
