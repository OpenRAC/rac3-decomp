/* functional: medium. Init of the scripted prop: searches the slot list for the neighbouring object by chain index (3 passes), spawns two child objects (func_003C24B0 + func_L04_003E2390). VU0 vadd replaced by float adds (file's flags lack the VU0 option). Struct offsets and constants checked vs asm; 287 diffs. */
#include "common.h"
#include "vu0.h"
extern void func_L01_00456230(void *, s32);
extern u8 *func_L01_0043B548(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern u8 *func_003C24B0(s32, s32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D308(void *, void *);
extern void func_003C7C38(void *);
extern f32 func_0038DAB8(f32, f32);
extern u8 *func_L04_003E2390(u8 *, void *, void *, s32, s32, f32, f32, f32);
extern s16 *D_L04_0021C9A0[];
extern u8 *D_L04_001DFD9C;
extern s32 D_L04_001DFDD8;
extern u8 D_L04_001DEB10[];
__asm__(".extern D_L04_001DEB10, 16");
extern u8 D_L04_001DEB20[];
__asm__(".extern D_L04_001DEB20, 16");

s32 func_L04_003D0C40(u8 *a0, u8 *pv) {
    u8 *c;
    u8 *ch;
    u8 *cv;
    u8 *o;
    u8 *r2;
    s16 *p;
    s32 idx, v, want, pass;
    vu0_v4 sp[2];
    f32 ang;

    func_L01_00456230(a0, 0);
    pv[0x38] = 1;
    *(s32 *)(pv + 0xA4) = -1;
    if (*(s32 *)(pv + 0x70) > 0) {
        c = func_L01_0043B548(0x19E1, 0x6C);
        *(s32 *)(pv + 0x70) = -1;
        pv[0x7E] = 4;
        (*(void (**)(u8 *))c)(a0);
        return 0;
    }
    *(s32 *)(pv + 0x94) = 0;
    v = *(s32 *)(pv + 0x90);
    idx = a0[0x21];
    if (v == -1) {
        want = 1;
        pass = 1;
    } else if (v >= -1) {
        want = v + 1;
        pass = 2;
    } else {
        pass = 0;
        want = 0;
    }
    while (pass != 0) {
        p = D_L04_0021C9A0[idx];
        while (idx != 0xFF && idx <= D_L04_001DFDD8 && p != 0 && (p[-1] >= 0 || p == D_L04_0021C9A0[idx])) {
            o = D_L04_001DFD9C + ((*(u16 *)p & 0x7FFF) << 8);
            if (o == 0) break;
            if (*(s32 *)(*(u8 **)(o + 0x68) + 0x90) == want) {
                *(u8 **)(pv + 0x94) = o;
                break;
            }
            p++;
        }
        if (pass == 2 && *(s32 *)(pv + 0x94) == 0) {
            want = -2;
            pass = 1;
        } else {
            pass = 0;
        }
    }
    v = *(s32 *)(pv + 0x90);
    if ((u32)(v + 2) < 2) {
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004AA7E8(a0, 1);
        *(s32 *)(pv + 0x9C) = 0;
        *(s32 *)(pv + 0xA0) = 0;
    } else {
        u8 *k = *(u8 **)(a0 + 0x24);
        u16 fl = *(u16 *)(a0 + 0x34) & 0xFFBE;
        *(u16 *)(a0 + 0x34) = fl;
        *(u16 *)(a0 + 0x34) = fl | (*(u16 *)(k + 0x44) & 0x1000);
        *(s32 *)(a0 + 0x98) = *(s32 *)(k + 0x10);
        ch = func_003C24B0(0xB57, 0xA0);
        *(u8 **)(pv + 0x9C) = ch;
        ch[0x30] = a0[0x30];
        *(u16 *)(ch + 0x32) = *(u16 *)(a0 + 0x32);
        cv = *(u8 **)(ch + 0x68);
        *(f32 *)(cv + 0x68) = 1.0f;
        *(s32 *)(cv + 0x90) = -1;
        *(s32 *)(cv + 0x74) = -1;
        *(f32 *)(cv + 0x70) = 3.5f;
        *(s32 *)(cv + 0x60) = *(s32 *)(pv + 0x98);
        *(s32 *)(cv + 0x6C) = 0;
        func_0038D000(ch + 0x10, D_L04_001DEB10, a0 + 0xC0);
        ((vu0_v4 *)(ch + 0x10))->x += ((vu0_v4 *)(a0 + 0x10))->x;
        ((vu0_v4 *)(ch + 0x10))->y += ((vu0_v4 *)(a0 + 0x10))->y;
        ((vu0_v4 *)(ch + 0x10))->z += ((vu0_v4 *)(a0 + 0x10))->z;
        *(vu0_q *)(ch + 0xF0) = *(vu0_q *)(a0 + 0xF0);
        func_0038D308(ch + 0xC0, ch + 0xF0);
        *(s32 *)(cv + 0x40) = 0;
        *(f32 *)(cv + 0x7C) = *(f32 *)(ch + 0x18);
        func_L01_00456230(ch, 0);
        ch[0x20] = 6;
        func_003C7C38(ch);
        func_0038D000(&sp[0], D_L04_001DEB20, a0 + 0xC0);
        sp[0].x += ((vu0_v4 *)(a0 + 0x10))->x;
        sp[0].y += ((vu0_v4 *)(a0 + 0x10))->y;
        sp[0].z += ((vu0_v4 *)(a0 + 0x10))->z;
        *(vu0_q *)&sp[1] = *(vu0_q *)(a0 + 0xF0);
        ang = func_0038DAB8(sp[1].z, 3.1415927f);
        sp[0].z = ang;
        r2 = func_L04_003E2390(a0, &sp[0], &sp[1], *(s32 *)(pv + 0x80), *(s32 *)(pv + 0x88),
                               *(f32 *)(pv + 0x84), *(f32 *)(pv + 0x8C), (f32)pv[0x44]);
        *(u8 **)(pv + 0xA0) = r2;
        r2[0x30] = a0[0x30];
        *(u16 *)(r2 + 0x32) = *(u16 *)(a0 + 0x32);
        func_003C7C38(r2);
    }
    if (*(s32 *)(pv + 0x90) == -3) {
        func_L01_004450F0(a0, 2, -1);
    } else {
        func_L01_004450F0(a0, 1, -1);
    }
    return 1;
}
