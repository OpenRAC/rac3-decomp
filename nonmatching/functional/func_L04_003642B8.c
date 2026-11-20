/* functional: medium. Player/NPC state update: steers toward the nearest nav point, probes ground ahead, may start a drop/jump state (0x1B). The probe call is given the whole stack block (v, o, and the two quads retail builds at +0x20/+0x30: z=0.01 and z+3.0, left unchanged for the second probe); loop-invariant reloads differ from retail; 445 byte diffs at level_04. Callee roles guessed from names only. */
#include "common.h"
#include "vu0.h"
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C3938(void *, s32, s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004591B8(void *, void *, void *);
extern void func_L01_0045BD10(void *, f32);
extern void func_L01_00458F78(void *, void *, s32, s32);
extern void func_L01_0045A748(void *, void *);
extern void func_L01_0045D218(void *, void *);
extern u8 *D_L04_001DFE80;
extern vu0_q D_L04_001E95C0;
__asm__(".extern D_L04_001E95C0, 16");
extern f32 D_L04_001DD748;
__asm__(".extern D_L04_001DD748, 4");
extern f32 D_L04_001DD74C;
__asm__(".extern D_L04_001DD74C, 4");
extern s32 D_L04_001DD738;
__asm__(".extern D_L04_001DD738, 4");
extern f32 D_L04_001DD73C;
__asm__(".extern D_L04_001DD73C, 4");
extern s32 D_001D545C;

s32 func_L04_003642B8(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *row;
    u8 *e;
    s32 *list;
    s32 idx, n, i, state;
    f32 d1, d2, d3, g, h, ang;
    struct { vu0_v4 v, o, a, b, w; } k;
    vu0_q q;

    if (func_L01_004561B8(a0) != 0) {
        if (*(s32 *)(pv + 0x4E4) != 0 && (*(u16 *)(a0 + 0x34) & 0x100) != 0 && D_001D545C != 0x16) {
            func_003C48A8(a0 + 0xC0, a0 + 0xF0);
            *(u16 *)(a0 + 0x34) &= 0xFEFF;
        }
        if (a0[0x95] == 4 || (D_001D545C == 0x1D && *(s32 *)(pv + 0x4D8) != 0)) {
            idx = *(s32 *)(pv + 0x4D4);
        } else {
            idx = *(s32 *)(pv + 0x38C);
        }
        q = *(vu0_q *)(pv + 0x320);
        if (idx != -1) {
            row = D_L04_001DFA4C + idx * 0x30;
            if (*(s16 *)(row + 0x32) != 0) {
                list = *(s32 **)(row + 0x40);
                *(vu0_q *)(pv + 0x320) = *(vu0_q *)(D_L04_001DFE80 + (list[0] << 7) + 0x30);
                n = *(s16 *)(D_L04_001DFA4C + idx * 0x30 + 0x32);
                for (i = 0; i < n; i++) {
                    list = *(s32 **)(D_L04_001DFA4C + idx * 0x30 + 0x40);
                    e = D_L04_001DFE80 + (list[i] << 7);
                    d1 = func_0038CF38(e + 0x30, pv + 0x220);
                    d2 = func_0038CF38(pv + 0x320, pv + 0x220);
                    if (d2 < d1 || func_0038CF38(a0 + 0x10, pv + 0x320) < 2.0f) {
                        if (2.0f < func_0038CF38(a0 + 0x10, e + 0x30)) {
                            *(vu0_q *)(pv + 0x320) = *(vu0_q *)(e + 0x30);
                        }
                    }
                    n = *(s16 *)(D_L04_001DFA4C + idx * 0x30 + 0x32);
                }
            }
            q = *(vu0_q *)(pv + 0x320);
        }
        *(vu0_q *)&k.v = q;
        func_L01_004591B8(a0, &k.v, pv + 0x410);
        func_L01_0045BD78(a0, 0.0064000003f, 0.120000005f, 0.010053097f, 0.25132743f);
        if (a0[0x43] != 3) {
            func_003C3A10(a0, 3, 0, (func_00382498(4, 6) * 5 + 2) / 6);
        }
    }
    /* probe: ahead of the player along its heading */
    *(vu0_q *)&k.v = *(vu0_q *)(a0 + 0x10);
    k.o.x = func_0038D098(*(f32 *)(a0 + 0xF8));
    k.o.y = func_0038D0B0(*(f32 *)(a0 + 0xF8));
    k.o.z = 0.0f;
    k.v.x += k.o.x;
    k.v.y += k.o.y;
    k.v.z += k.o.z;
    *(vu0_q *)&k.b = *(vu0_q *)&k.v;
    *(vu0_q *)&k.a = *(vu0_q *)&k.v;
    k.a.z = 0.01f;
    k.b.z += 3.0f;
    g = func_003C3D30(&k.v, 0x22, 0, 0.5f);
    state = 0;
    if (g < *(f32 *)(a0 + 0x18)) {
        f32 dz = g - *(f32 *)(a0 + 0x18);
        if (*(f32 *)(pv + 0x7C) < (dz < 0.0f ? -dz : dz)) {
            k.o.x = func_0038D098(*(f32 *)(a0 + 0xF8)) * 3.0f;
            k.o.y = func_0038D0B0(*(f32 *)(a0 + 0xF8)) * 3.0f;
            k.o.z = 0.0f;
            *(vu0_q *)&k.v = *(vu0_q *)(a0 + 0x10);
            k.v.x += k.o.x;
            k.v.y += k.o.y;
            k.v.z += k.o.z;
            g = func_003C3D30(&k.v, 0x22, 0, 6.0f);
            h = *(f32 *)(a0 + 0x18) - 14.0f;
            *(vu0_q *)&k.w = D_L04_001E95C0;
            d1 = func_0038CED8(&k.w);
            ang = func_0038D160(k.w.z, d1);
            state = 2;
            if (h < g && ang < 1.2217305f) {
                state = 1;
            }
        }
    }
    if (state != 0 && D_001D545C != 0x16 && *(s32 *)(pv + 0x4E4) == 0) {
        f32 s = D_L04_001DD748 * 0.0200000014f;
        func_0038CE20(pv + 0x110, a0 + 0xC0, s);
        *(s32 *)(pv + 0x378) = 0;
        *(s32 *)(pv + 0x100) = 0;
        *(s32 *)(pv + 0xF8) = 0;
        *(s32 *)(pv + 0xFC) = 0;
        *(vu0_q *)(pv + 0xC0) = 0;
        *(s32 *)(pv + 0x148) = -1;
        *(f32 *)(pv + 0x120) = s;
        *(f32 *)(pv + 0x118) = D_L04_001DD74C * 0.0200000014f;
        *(f32 *)(pv + 0x37C) = 1.0f;
        func_L01_004450F0(a0, 0x1B, 8);
        func_003C3938(a0, D_L04_001DD738, (s32)D_L04_001DD73C);
        return 1;
    }
    if (func_0038CF38(a0 + 0x10, pv + 0x320) <= 0.5f) {
        if (*(s32 *)(pv + 0x308) != 0) {
            func_L01_0045BD10(a0, *(f32 *)(pv + 0x36C));
        }
        if (func_L04_00361D20(a0, pv) != 0) {
            func_L01_004450F0(a0, 0x12, -1);
        } else {
            func_L01_004450F0(a0, 0xD, -1);
        }
        return 1;
    }
    if (*(s32 *)(pv + 0x4E4) != 0) {
        func_L01_0045D218(a0, pv + 0x320);
    } else {
        func_L01_00458F78(a0, pv + 0x410, 0, 0);
        func_L01_0045A748(a0, pv + 0x410);
        if (*(f32 *)(pv + 0x120) < *(f32 *)(pv + 0x98) * 0.8f) {
            *(s32 *)(pv + 0x450) = *(s32 *)(pv + 0x450) + 1;
        }
    }
    return 0;
}
