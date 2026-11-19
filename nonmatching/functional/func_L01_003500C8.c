/* functional: medium-high. Compiles in context, not exact (295 diff: branch layout and register use; the plain-C xyz add stands in for retail's vadd.xyz, w untouched). Offsets, constants and callees re-read against retail; D_L01_001DD450/460/468/470 are read-only tables copied to locals as retail does; call arguments to func_L01_0046C470 follow the L03 prototype (float arg in f12, 60 and rnd in the int slots). Unsure only of the exact meaning of the two tables of two floats. */
#include "vu0.h"
extern s32 D_L01_001DD450[];
extern f32 D_L01_001DD460[];
extern f32 D_L01_001DD468[];
extern f32 D_L01_001DD470[];
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern void func_003A52A0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D308(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_L01_0044E820(void *, s32);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_003C2880(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
void func_L01_003500C8(u8 *obj) {
    u8 *v = *(u8 **)(obj + 0x68);
    u8 *m;
    s32 A[4];
    f32 T1[2];
    f32 T2[2];
    f32 T3[4];
    f32 pos[4] __attribute__((aligned(16)));
    f32 out[4] __attribute__((aligned(16)));
    s32 i, par, col;
    f32 e, sz, r;
    if (obj[0x20] == 0) {
        func_003A52A0(func_00382468(2), 0, obj);
        m = *(u8 **)(v + 8);
        *(u16 *)(m + 0x34) &= 0xFFBE;
        m = *(u8 **)(v + 8);
        *(u16 *)(m + 0x34) |= *(u16 *)(*(u8 **)(m + 0x24) + 0x44) & 0x1000;
        m = *(u8 **)(v + 8);
        *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
        m = *(u8 **)(v + 8);
        *(u16 *)(m + 0x34) |= 0x100;
        m = *(u8 **)(v + 8);
        func_0038CF68(m + 0xC0, m + 0xC0, 0.1f);
        m = *(u8 **)(v + 8);
        func_0038CF68(m + 0xD0, m + 0xD0, 0.1f);
        A[0] = D_L01_001DD450[0]; A[1] = D_L01_001DD450[1];
        A[2] = D_L01_001DD450[2]; A[3] = D_L01_001DD450[3];
        T1[0] = D_L01_001DD460[0]; T1[1] = D_L01_001DD460[1];
        T2[0] = D_L01_001DD468[0]; T2[1] = D_L01_001DD468[1];
        T3[0] = D_L01_001DD470[0]; T3[1] = D_L01_001DD470[1];
        T3[2] = D_L01_001DD470[2]; T3[3] = D_L01_001DD470[3];
        if (v[0xD] == 0) *(s32 *)v = 0;
        else *(f32 *)v = 1.0f;
        if (v[0xC] == 0) {
            for (i = 0; i < 30; i++) {
                par = i & 1;
                m = *(u8 **)(v + 8);
                func_L01_00443B88(pos, 0.0f, T2[par] * (f32)(s32)(s8)v[0xE]);
                pos[0] = pos[0] + *(f32 *)(m + 0x10);
                pos[1] = pos[1] + *(f32 *)(m + 0x14);
                pos[2] = pos[2] + *(f32 *)(m + 0x18);
                pos[2] = pos[2] + func_003824E0(0.0f, (f32)(s32)(s8)v[0xE] * 2.0f);
                col = func_0038DBD8(A[par * 2], A[par * 2 + 1], func_003824E0(0.0f, 1.0f));
                sz = T1[par] * (f32)(s32)(s8)v[0xE];
                *(vu0_q *)out = 0;
                r = func_003824E0(T3[par * 2], T3[par * 2 + 1]);
                out[2] = r * (f32)(s32)(s8)v[0xE] * 0.02f;
                func_L01_0046C470(pos, out, col, sz, 60, func_00382468(0xFF) & 0xFF, 0, v[0xF], 0);
            }
        }
        func_L01_004450F0(obj, 1, -1);
    } else if (obj[0x20] == 1) {
        m = *(u8 **)(v + 8);
        m[0x23] = (s32)(*(f32 *)v * 127.0f);
        func_L01_0044E820(*(u8 **)(v + 8), func_0038DBD8(0xF0FF2000, *(s32 *)(v + 4), *(f32 *)v));
        m = *(u8 **)(v + 8);
        func_0038D308(m + 0xC0, m + 0xF0);
        m = *(u8 **)(v + 8);
        func_0038CF68(m + 0xC0, m + 0xC0, *(f32 *)v);
        m = *(u8 **)(v + 8);
        func_0038CF68(m + 0xD0, m + 0xD0, *(f32 *)v);
        if (v[0xD] == 0) {
            func_003C4138((f32 *)v, 1.0f, 0.04f);
            if (*(f32 *)v == 1.0f) {
                m = *(u8 **)(v + 8);
                *(u16 *)(m + 0x34) &= 0xFEFF;
                m = *(u8 **)(v + 8);
                *(u16 *)(m + 0x34) &= 0xFFFD;
                func_L01_0044E820(*(u8 **)(v + 8), *(s32 *)(v + 4));
                func_003C2880(obj);
            }
        } else {
            func_003C4138((f32 *)v, 0.0f, 0.1f);
            if (*(f32 *)v == 0.0f) {
                m = *(u8 **)(v + 8);
                *(u16 *)(m + 0x34) &= 0xFEFF;
                m = *(u8 **)(v + 8);
                *(u16 *)(m + 0x34) &= 0xFFFD;
                func_L01_0044E820(*(u8 **)(v + 8), *(s32 *)(v + 4));
                m = *(u8 **)(v + 8);
                *(u16 *)(m + 0x34) |= 1;
                (*(u8 **)(v + 8))[0x31] = 0;
                func_003C2880(obj);
            }
        }
    }
}
