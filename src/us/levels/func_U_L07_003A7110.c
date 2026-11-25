#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L07_003A8908. */
/* localdecomp:start func_U_L07_003A7110 */
extern f32 D_001A4C64[];
extern u8 D_001A30B0[];
extern s32 func_U_003B9310(u8 *, s32);
extern s32 func_U_00453488(u8 *);
extern void func_U_00442528(void *, s32, s32);
extern s32 func_U_0040C3D0(void *);
extern s32 func_U_004A60E0(s32, s32, void *);
extern void func_U_004A5D68(s32);
extern f32 func_U_004458D0(f32, f32, f32);
extern f32 func_U_00442700(f32, f32, f32);
extern void func_U_0040C7A0(f32 *, void *, f32);
extern void func_U_0044A2D0(void *, void *, void *, void *);

void func_U_L07_003A7110(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *c = *(u8 **)(s + 0xC8);
    f32 q[4] __attribute__((aligned(16)));
    f32 tmp[4] __attribute__((aligned(16)));
    s32 h;
    s32 id;
    u8 *e;
    f32 r;

    if (c == 0) {
        return;
    }
    if (func_U_003B9310(c, obj[0x21]) == 0) {
        return;
    }
    h = *(s16 *)(s + 0xC6);
    *(vu0_q *)q = *(vu0_q *)(obj + 0x10);
    switch (obj[0x20]) {
    case 0:
        obj[0x30] = 0xFF;
        *(s32 *)(s + 0x6C) |= 0x10;
        func_U_00442528(obj, 1, -1);
        break;
    case 1:
        if (func_U_00453488(obj) != 0) {
            u8 *row = s + h * 2;
            u16 t = *(u16 *)(row + 0x70);
            *(u16 *)(s + 0xC4) = t;
            if ((s16)t == -1) {
                func_U_00442528(obj, 6, -1);
                break;
            }
        }
        if (func_U_0040C3D0(s + 0xC4) != 0) {
            func_U_00442528(obj, 3, -1);
        }
        break;
    case 2:
        if (func_U_00453488(obj) != 0) {
            u8 *row = s + h * 2;
            *(u16 *)(s + 0xC4) = *(u16 *)(row + 0xB0);
        }
        if (func_U_0040C3D0(s + 0xC4) != 0 && D_001A4C64[0] < *(f32 *)(obj + 0x14) + 1.0f) {
            func_U_00442528(obj, 3, -1);
        }
        break;
    case 3:
        if (func_U_00453488(obj) != 0) {
            u8 *row = s + h * 2;
            u16 t = *(u16 *)(row + 0x80);
            id = *(s32 *)(s + 0xCC);
            *(u16 *)(s + 0xC4) = t;
            *(f32 *)(s + 0xC0) = 1.0f / (f32)(s16)t;
            if (id == -1 ||
                (e = (u8 *)((id << 7) + (s32)D_001A30B0),
                 *(u8 **)(e + 0xDC) != obj || e[0xD0] == 0)) {
                *(s32 *)(s + 0xCC) = func_U_004A60E0(0, 4, obj);
            }
        }
        if (func_U_0040C3D0(s + 0xC4) != 0) {
            s32 release_id = *(s32 *)(s + 0xCC);
            if (release_id != -1) {
                u8 *entry = (u8 *)((release_id << 7) + (s32)D_001A30B0);
                if (*(u8 **)(entry + 0xDC) == obj && entry[0xD0] != 0) {
                    func_U_004A5D68(release_id);
                }
            }
            *(s32 *)(s + 0xCC) = -1;
            func_U_00442528(obj, 4, -1);
        }
        r = func_U_004458D0(-8.5f, 0.0f, (f32)*(s16 *)(s + 0xC4) * *(f32 *)(s + 0xC0));
        goto apply_offset;
    case 4:
        if (func_U_00453488(obj) != 0) {
            u8 *row = s + h * 2;
            *(u16 *)(s + 0xC4) = *(u16 *)(row + 0xA0);
        }
        if (func_U_0040C3D0(s + 0xC4) != 0) {
            func_U_00442528(obj, 5, -1);
        }
        break;
    case 5:
        if (func_U_00453488(obj) != 0) {
            u8 *row = s + h * 2;
            u16 t = *(u16 *)(row + 0x90);
            id = *(s32 *)(s + 0xCC);
            *(u16 *)(s + 0xC4) = t;
            *(f32 *)(s + 0xC0) = 1.0f / (f32)(s16)t;
            if (id == -1 ||
                (e = (u8 *)((id << 7) + (s32)D_001A30B0),
                 *(u8 **)(e + 0xDC) != obj || e[0xD0] == 0)) {
                *(s32 *)(s + 0xCC) = func_U_004A60E0(1, 4, obj);
            }
        }
        if (func_U_0040C3D0(s + 0xC4) != 0) {
            s32 release_id = *(s32 *)(s + 0xCC);
            if (release_id != -1) {
                u8 *entry = (u8 *)((release_id << 7) + (s32)D_001A30B0);
                if (*(u8 **)(entry + 0xDC) == obj && entry[0xD0] != 0) {
                    func_U_004A5D68(release_id);
                }
            }
            *(s32 *)(s + 0xCC) = -1;
            func_U_00442528(obj, 2, -1);
        }
        r = func_U_00442700(0.0f, -8.5f, (f32)*(s16 *)(s + 0xC4) * *(f32 *)(s + 0xC0));
apply_offset:
        func_U_0040C7A0(tmp, obj + 0xD0, r);
        vec_add_ab(obj + 0x10, s + 0xD0, tmp);
        break;
    }
    vec_sub_ba(q, obj + 0x10, q);
    func_U_0044A2D0(s + 0x30, q, obj + 0xF0, obj + 0xF0);
}
/* localdecomp:end func_U_L07_003A7110 */
