/* functional: high. PAL near-miss draft re-read against PAL asm (state switch 1-4, orbit offset from the hero position D_001A4C60, constants, callees, trailing effect calls) and matches; only the VU block scheduling differs. */
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
            __asm__("lqc2 vf2, %1\n lqc2 vf1, %2\n vadd.xyz vf2, vf2, vf1\n sqc2 vf2, %0" : "=m"(*(V_003E2B80 *)(p+0x220)) : "m"(D_001A4C60), "m"(a) : "vf1", "vf2");
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
