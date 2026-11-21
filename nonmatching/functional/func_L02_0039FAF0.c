/* functional: high. Written from PAL asm incl. the 5-entry jump table jtbl_002BCC60 (obj[0x20]=1..5; 1 does nothing). Floats checked against hex constants. VU0 vadd.xyz written as plain adds (xyz = v + m->pos, w = v.w) because this file's flags have no vu0 flag. Remaining diffs are layout only. */
#include "vu0.h"
extern M39E3B8 *D_L02_001DE99C[];
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern s32 func_L01_0044C108(void *);
extern void func_L02_003A0030(u8 *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L02_00335DB0(void *);
extern void func_L02_003A0158(s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L02_003A0C18(void *);
extern void func_L02_003A0058(u8 *, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00404808(void *, void *);
extern void func_L02_003A0498(u8 *);
extern s32 func_00382468(s32);
extern s32 func_L01_004561B8(void *);
extern void func_L02_003A0978(u8 *);
extern s32 func_L02_003A02D8(u8 *, s32);

void func_L02_0039FAF0(u8 *obj) {
    u8 *st;
    u8 *m;
    s32 idx;
    vu0_v4 v;

    if (func_L01_0044C108(obj + 0x10) == 0) return;
    func_L02_003A0030(obj);
    st = *(u8 **)(obj + 0x68);
    if (*(s32 *)(st + 0x1C) >= 0) {
        m = (u8 *)D_L02_001DE99C[0] + (*(s32 *)(st + 0x1C) << 8);
        func_0038D000(&v, st + 0x20, m + 0xC0);
        /* retail: lqc2/vadd.xyz/sqc2: xyz = v + m->pos, w = v.w */
        ((f32 *)(obj + 0x10))[0] = v.x + ((f32 *)(m + 0x10))[0];
        ((f32 *)(obj + 0x10))[1] = v.y + ((f32 *)(m + 0x10))[1];
        ((f32 *)(obj + 0x10))[2] = v.z + ((f32 *)(m + 0x10))[2];
        ((f32 *)(obj + 0x10))[3] = v.w;
        *(u16 *)(obj + 0x34) |= 0x100;
        *(vu0_v4 *)(obj + 0xC0) = *(vu0_v4 *)(m + 0xC0);
        *(vu0_v4 *)(obj + 0xD0) = *(vu0_v4 *)(m + 0xD0);
        *(vu0_v4 *)(obj + 0xE0) = *(vu0_v4 *)(m + 0xE0);
    }
    switch (obj[0x95]) {
    case 2:
        if (obj[0x60] & 2) {
            idx = st[0x18] ? *(s32 *)(st + 4) : *(s32 *)(st + 0);
            m = (u8 *)D_L02_001DE99C[0] + (idx << 8);
            func_L02_00335DB0(m);
            func_L02_003A0158(st[0x18] ? *(s32 *)(st + 4) : *(s32 *)(st + 0), 2);
            *(vu0_v4 *)(m + 0x10) = *(vu0_v4 *)(obj + 0x10);
            *(f32 *)(m + 0x18) += -1.1f;
            if (obj[0x43] != 2) func_003C3A10(obj, 2, 0, 0);
            func_L01_004450F0(obj, 2, 3);
        }
        break;
    case 1:
        if (st[0x17] != 0 && obj[0x31] == 0) {
            if (st[0x19] == 0 ||
                (D_001BBC40[obj[0xB0] + D_001D545C * 16] & 0x80) == 0) {
                func_L02_003A02D8(obj, 0);
            }
        }
        break;
    case 3:
        if (obj[0x60] & 2) {
            if (obj[0x43] != 0) func_003C3A10(obj, 0, 0, 0);
            obj[0x95] = 1;
        }
        break;
    }
    switch (obj[0x20]) {
    case 2:
        *(f32 *)(st + 0x10) = func_0038DAB8(*(f32 *)(st + 0x10), 0.06283185631f);
        *(f32 *)(st + 8) += 0.03f;
        if (1.0f <= *(f32 *)(st + 8)) *(f32 *)(st + 8) = 1.0f;
        if (*(f32 *)(st + 8) > 0.5f) {
            *(f32 *)(st + 0xC) += 0.06f;
            if (1.0f <= *(f32 *)(st + 0xC)) {
                *(f32 *)(st + 0xC) = 1.0f;
                func_L02_003A0C18(obj);
                func_L01_004450F0(obj, 3, -1);
            }
        }
        func_L02_003A0058(obj, st[0x18] ? *(s32 *)(st + 4) : *(s32 *)(st + 0),
                          1.0f, 0.1f, 1.0f, 3.0f, -0.55f, 3.0f, *(f32 *)(st + 8));
        func_L01_00404808(func_L02_003A0498, obj);
        if (func_00382468(3) == 0) func_L02_003A0978(obj);
        break;
    case 3:
        if (func_L01_004561B8(obj) != 0) *(f32 *)(st + 8) = 0.0f;
        *(f32 *)(st + 8) += 0.18f;
        if (1.0f <= *(f32 *)(st + 8)) {
            *(f32 *)(st + 8) = 1.0f;
            func_L01_004450F0(obj, 4, -1);
        }
        func_L02_003A0058(obj, st[0x18] ? *(s32 *)(st + 4) : *(s32 *)(st + 0),
                          0.1f, 2.0f, 3.0f, 0.5f, 3.0f, 3.0f, *(f32 *)(st + 8));
        break;
    case 4:
        if (func_L01_004561B8(obj) != 0) *(f32 *)(st + 8) = 0.0f;
        *(f32 *)(st + 8) += 0.096f;
        if (1.0f <= *(f32 *)(st + 8)) {
            func_L02_003A0158(st[0x18] ? *(s32 *)(st + 4) : *(s32 *)(st + 0), 0);
            *(f32 *)(st + 8) = 1.0f;
            func_L01_004450F0(obj, 5, -1);
        }
        func_L02_003A0058(obj, st[0x18] ? *(s32 *)(st + 4) : *(s32 *)(st + 0),
                          2.0f, 1.0f, 0.5f, 1.0f, 3.0f, 3.0f, *(f32 *)(st + 8));
        break;
    case 5:
        m = (u8 *)D_L02_001DE99C[0] + ((st[0x18] ? *(s32 *)(st + 4) : *(s32 *)(st + 0)) << 8);
        if (fabs_asm(*(f32 *)(m + 0x18) - *(f32 *)(obj + 0x18)) < 0.1f) {
            if (*(s32 *)(st + 0x1C) >= 0) {
                *(s32 *)(*(u8 **)(m + 0x68) + 0xDC) = 0;
            } else {
                *(s32 *)(*(u8 **)(m + 0x68) + 0xDC) = 2;
            }
            func_L01_004450F0(obj, 1, -1);
        }
        break;
    }
}
