/* functional: high. Same behaviour; remaining diffs are s16 store ordering and address-add operand order. Uses local inline VU0 asm (file flags lack -mvu0-use-vf0-vf2). */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L07_003A8908 */
extern f32 D_001A4C64[];
extern u8 D_001A30B0[];
static __inline__ void add_ab_003A8908(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void sub_ba_003A8908(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
void func_L07_003A8908(u8 *obj) {
    extern s32 func_L07_003BAC00(u8 *, s32);
    extern s32 func_L01_004561B8(u8 *);
    extern void func_L01_004450F0(u8 *, s32, s32);
    extern s32 func_0038CB00(void *);
    extern s32 func_003A52A0(s32, s32, void *);
    extern void func_003A4F28(s32);
    extern f32 func_003C4088(f32, f32, f32);
    extern f32 func_003C3BE8(f32, f32, f32);
    extern void func_0038CE20(f32 *, void *, f32);
    extern void func_003C4DA8(void *, void *, void *, void *);
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *c = *(u8 **)(s + 0xC8);
    f32 q[4];
    f32 tmp[4];
    s32 h;
    s32 id;
    u8 *e;
    f32 r;

    if (c == 0) {
        return;
    }
    if (func_L07_003BAC00(c, obj[0x21]) == 0) {
        return;
    }
    h = *(s16 *)(s + 0xC6);
    *(vu0_q *)q = *(vu0_q *)(obj + 0x10);
    switch (obj[0x20]) {
    case 0:
        obj[0x30] = 0xFF;
        *(s32 *)(s + 0x6C) |= 0x10;
        func_L01_004450F0(obj, 1, -1);
        break;
    case 1:
        if (func_L01_004561B8(obj) != 0) {
            u16 t = *(u16 *)(s + h * 2 + 0x70);
            *(u16 *)(s + 0xC4) = t;
            if ((s16)t == -1) {
                func_L01_004450F0(obj, 6, -1);
                break;
            }
        }
        if (func_0038CB00(s + 0xC4) != 0) {
            func_L01_004450F0(obj, 3, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(obj) != 0) {
            *(u16 *)(s + 0xC4) = *(u16 *)(s + h * 2 + 0xB0);
        }
        if (func_0038CB00(s + 0xC4) != 0 && D_001A4C64[0] < *(f32 *)(obj + 0x14) + 1.0f) {
            func_L01_004450F0(obj, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(obj) != 0) {
            s16 t = (*(s16 *)(s + h * 2 + 0x80) * 5 + 2) / 6;
            id = *(s32 *)(s + 0xCC);
            *(s16 *)(s + 0xC4) = t;
            *(f32 *)(s + 0xC0) = 1.0f / (f32)t;
            if (id == -1) {
                *(s32 *)(s + 0xCC) = func_003A52A0(0, 4, obj);
            } else {
                e = (u8 *)((id << 7) + (s32)D_001A30B0);
                if (*(u8 **)(e + 0xDC) != obj || *(u8 *)(e + 0xD0) == 0) {
                    *(s32 *)(s + 0xCC) = func_003A52A0(0, 4, obj);
                }
            }
        }
        if (func_0038CB00(s + 0xC4) != 0) {
            id = *(s32 *)(s + 0xCC);
            if (id != -1) {
                e = (u8 *)((id << 7) + (s32)D_001A30B0);
                if (*(u8 **)(e + 0xDC) == obj && *(u8 *)(e + 0xD0) != 0) {
                    func_003A4F28(id);
                }
            }
            *(s32 *)(s + 0xCC) = -1;
            func_L01_004450F0(obj, 4, -1);
        }
        r = func_003C4088(-8.5f, 0.0f, (f32)*(s16 *)(s + 0xC4) * *(f32 *)(s + 0xC0));
        func_0038CE20(tmp, obj + 0xD0, r);
        add_ab_003A8908(obj + 0x10, s + 0xD0, tmp);
        break;
    case 4:
        if (func_L01_004561B8(obj) != 0) {
            *(s16 *)(s + 0xC4) = (*(s16 *)(s + h * 2 + 0xA0) * 5 + 2) / 6;
        }
        if (func_0038CB00(s + 0xC4) != 0) {
            func_L01_004450F0(obj, 5, -1);
        }
        break;
    case 5:
        if (func_L01_004561B8(obj) != 0) {
            s16 t = (*(s16 *)(s + h * 2 + 0x90) * 5 + 2) / 6;
            id = *(s32 *)(s + 0xCC);
            *(s16 *)(s + 0xC4) = t;
            *(f32 *)(s + 0xC0) = 1.0f / (f32)t;
            if (id == -1) {
                *(s32 *)(s + 0xCC) = func_003A52A0(1, 4, obj);
            } else {
                e = (u8 *)((id << 7) + (s32)D_001A30B0);
                if (*(u8 **)(e + 0xDC) != obj || *(u8 *)(e + 0xD0) == 0) {
                    *(s32 *)(s + 0xCC) = func_003A52A0(1, 4, obj);
                }
            }
        }
        if (func_0038CB00(s + 0xC4) != 0) {
            id = *(s32 *)(s + 0xCC);
            if (id != -1) {
                e = (u8 *)((id << 7) + (s32)D_001A30B0);
                if (*(u8 **)(e + 0xDC) == obj && *(u8 *)(e + 0xD0) != 0) {
                    func_003A4F28(id);
                }
            }
            *(s32 *)(s + 0xCC) = -1;
            func_L01_004450F0(obj, 2, -1);
        }
        r = func_003C3BE8(0.0f, -8.5f, (f32)*(s16 *)(s + 0xC4) * *(f32 *)(s + 0xC0));
        func_0038CE20(tmp, obj + 0xD0, r);
        add_ab_003A8908(obj + 0x10, s + 0xD0, tmp);
        break;
    }
    sub_ba_003A8908(q, obj + 0x10, q);
    func_003C4DA8(s + 0x30, q, obj + 0xF0, obj + 0xF0);
}
/* localdecomp:end func_L07_003A8908 */
