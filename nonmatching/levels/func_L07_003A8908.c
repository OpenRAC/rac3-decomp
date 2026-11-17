/* NTSC-U draft (Claude wave C4): C of func_L07_003A7110, the NTSC-U twin of func_L07_003A8908, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L07_003A7110", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (0 diff) only with -mvu0-use-vf0-vf2 added (vec_add_ab / vec_sub_ba from vu0.h; with the PAL flags it does not compile: vf17 spilled; its PAL file has no vu0 flag; no div row needed). State machine over obj[0x20] 0..5 with a jump table (6 ...
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L07_003A8908 (src/levels/07_annihilation_nation/L07_003A46C8.c) */
/* localdecomp:start func_L07_003A7110 */
extern f32 D_001A4C64[];
extern u8 D_001A30B0[];
extern s32 func_L07_003B9310(u8 *, s32);
extern s32 func_L01_00452EC8(u8 *);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern s32 func_003883C8(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);
extern f32 func_003BEB48(f32, f32, f32);
extern f32 func_003BE6A8(f32, f32, f32);
extern void func_003886E8(f32 *, void *, f32);
extern void func_003BF838(void *, void *, void *, void *);

void func_L07_003A7110(u8 *obj) {
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
    if (func_L07_003B9310(c, obj[0x21]) == 0) {
        return;
    }
    h = *(s16 *)(s + 0xC6);
    *(vu0_q *)q = *(vu0_q *)(obj + 0x10);
    switch (obj[0x20]) {
    case 0:
        obj[0x30] = 0xFF;
        *(s32 *)(s + 0x6C) |= 0x10;
        func_L01_00441FB8(obj, 1, -1);
        break;
    case 1:
        if (func_L01_00452EC8(obj) != 0) {
            u8 *row = s + h * 2;
            u16 t = *(u16 *)(row + 0x70);
            *(u16 *)(s + 0xC4) = t;
            if ((s16)t == -1) {
                func_L01_00441FB8(obj, 6, -1);
                break;
            }
        }
        if (func_003883C8(s + 0xC4) != 0) {
            func_L01_00441FB8(obj, 3, -1);
        }
        break;
    case 2:
        if (func_L01_00452EC8(obj) != 0) {
            u8 *row = s + h * 2;
            *(u16 *)(s + 0xC4) = *(u16 *)(row + 0xB0);
        }
        if (func_003883C8(s + 0xC4) != 0 && D_001A4C64[0] < *(f32 *)(obj + 0x14) + 1.0f) {
            func_L01_00441FB8(obj, 3, -1);
        }
        break;
    case 3:
        if (func_L01_00452EC8(obj) != 0) {
            u8 *row = s + h * 2;
            u16 t = *(u16 *)(row + 0x80);
            id = *(s32 *)(s + 0xCC);
            *(u16 *)(s + 0xC4) = t;
            *(f32 *)(s + 0xC0) = 1.0f / (f32)(s16)t;
            if (id == -1) {
                *(s32 *)(s + 0xCC) = func_0039FE80(0, 4, obj);
            } else {
                e = (u8 *)((id << 7) + (s32)D_001A30B0);
                if (*(u8 **)(e + 0xDC) != obj || *(u8 *)(e + 0xD0) == 0) {
                    *(s32 *)(s + 0xCC) = func_0039FE80(0, 4, obj);
                }
            }
        }
        if (func_003883C8(s + 0xC4) != 0) {
            id = *(s32 *)(s + 0xCC);
            if (id != -1) {
                e = (u8 *)((id << 7) + (s32)D_001A30B0);
                if (*(u8 **)(e + 0xDC) == obj && *(u8 *)(e + 0xD0) != 0) {
                    func_0039FB08(id);
                }
            }
            *(s32 *)(s + 0xCC) = -1;
            func_L01_00441FB8(obj, 4, -1);
        }
        r = func_003BEB48(-8.5f, 0.0f, (f32)*(s16 *)(s + 0xC4) * *(f32 *)(s + 0xC0));
        func_003886E8(tmp, obj + 0xD0, r);
        vec_add_ab(obj + 0x10, s + 0xD0, tmp);
        break;
    case 4:
        if (func_L01_00452EC8(obj) != 0) {
            u8 *row = s + h * 2;
            *(u16 *)(s + 0xC4) = *(u16 *)(row + 0xA0);
        }
        if (func_003883C8(s + 0xC4) != 0) {
            func_L01_00441FB8(obj, 5, -1);
        }
        break;
    case 5:
        if (func_L01_00452EC8(obj) != 0) {
            u8 *row = s + h * 2;
            u16 t = *(u16 *)(row + 0x90);
            id = *(s32 *)(s + 0xCC);
            *(u16 *)(s + 0xC4) = t;
            *(f32 *)(s + 0xC0) = 1.0f / (f32)(s16)t;
            if (id == -1) {
                *(s32 *)(s + 0xCC) = func_0039FE80(1, 4, obj);
            } else {
                e = (u8 *)((id << 7) + (s32)D_001A30B0);
                if (*(u8 **)(e + 0xDC) != obj || *(u8 *)(e + 0xD0) == 0) {
                    *(s32 *)(s + 0xCC) = func_0039FE80(1, 4, obj);
                }
            }
        }
        if (func_003883C8(s + 0xC4) != 0) {
            id = *(s32 *)(s + 0xCC);
            if (id != -1) {
                e = (u8 *)((id << 7) + (s32)D_001A30B0);
                if (*(u8 **)(e + 0xDC) == obj && *(u8 *)(e + 0xD0) != 0) {
                    func_0039FB08(id);
                }
            }
            *(s32 *)(s + 0xCC) = -1;
            func_L01_00441FB8(obj, 2, -1);
        }
        r = func_003BE6A8(0.0f, -8.5f, (f32)*(s16 *)(s + 0xC4) * *(f32 *)(s + 0xC0));
        func_003886E8(tmp, obj + 0xD0, r);
        vec_add_ab(obj + 0x10, s + 0xD0, tmp);
        break;
    }
    vec_sub_ba(q, obj + 0x10, q);
    func_003BF838(s + 0x30, q, obj + 0xF0, obj + 0xF0);
}
/* localdecomp:end func_L07_003A7110 */
