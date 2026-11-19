/* functional: high. Per-frame update of a multiplayer-menu object that owns a damage/shield meter (state at object[0x68]): re-rolls a target at random intervals, tracks the nearest hittable thing, drains the meter (state+0x30) when the target stays in range, and when the meter is empty plays the destruction effect (burst via func_L01_003303B8, sound via func_L39_005F33E0, a spark vector via func_L39_005F3718), switches the object to mode 7 and frees it. Always returns 0. Written from the PAL disassembly; the argument lists of the two big effect calls are copied from the stack/register setup. */
#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0055E2E0;

extern s32 D_0024112C;
extern f32 D_L39_00352940[];
extern s32 D_L39_00242930;
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_0055DC90(void *, void *);
extern s32 func_L39_0055FF88(void *);
extern u32 func_L39_0055FC98(u8 *, s32);
extern void func_L39_0055DBE8(s32, s32);
extern void func_L01_0044ABD0(void *, void *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern f32 func_L01_004474E8(void *, void *);
extern u8 *func_L39_0061CEA0(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_003C4A40(void *, void *);
extern s32 func_L39_005BE900(void *, s32, f32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                             s32, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L39_005F3718(s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L39_0055DCB8(void *);
extern void func_L39_0055DC30(void *);

s32 func_L39_0055E2E0(u8 *self, s32 a1) {
    u8 *st = *(u8 **)(self + 0x68);
    u8 *p;
    u8 *r;
    u8 *v;
    u8 *st70;
    V_0055E2E0 sph;
    V_0055E2E0 spark;
    f32 left;
    f32 g;
    f32 lim;
    f32 f20;
    s32 flag;
    s32 id;
    s32 h;

    if (a1 != 0) {
        return 0;
    }
    if (*(s32 *)(st + 0x204) != 0) {
        return 0;
    }
    st70 = st + 0x70;
    if (*(s32 *)(st + 0x224) < D_0024112C) {
        if ((D_0024112C & 7) == (((s32)self >> 8) & 7)) {
            id = func_L39_005B4398(0xF);
            *(s32 *)(st + 0x224) = D_0024112C + id + 0x1E;
            if (func_L39_0055DC90(self, st70) == 0) {
                if (*(s32 *)(st + 0x200) != -1) {
                    id = func_L39_0055FF88(self);
                } else {
                    id = func_L39_0055FC98(self, 0);
                }
                if (id != *(s32 *)(st + 0x200)) {
                    func_L39_0055DBE8((s32)self, id);
                }
            }
        }
    }
    func_L01_0044ABD0(self, st70);
    p = func_L01_00447490(self, 0x10000, 0);
    left = func_L01_004474E8(self, p);
    if (p == 0) {
        return 0;
    }
    id = *(s32 *)(st + 0x22C);
    if (id >= 0) {
        g = D_L39_00352940[id + 0x7E] * 0.7f;
    } else {
        g = 0.0f;
    }
    g = left * g;
    left = left - g;
    if (*(s32 *)(p + 0x20) != 0) {
        if (*(f32 *)(st + 0x30) != 0.0f) {
            r = func_L39_0061CEA0(*(void **)(p + 0x20));
            if (r != 0) {
                if ((*(s32 (**)(void *, s32))(*(u8 **)(r + 0x14) + 0x1C))(r, *(s32 *)(st + 0x22C)) == 0) {
                    flag = 1;
                    v = (u8 *)(*(s32 (**)(void *))(*(u8 **)(r + 0x14) + 0x10))(r);
                    if (*(s32 *)(st + 0x230) != 0 && v != 0) {
                        f20 = *(f32 *)(st + 0x25C);
                        lim = *(f32 *)(st + 0x250);
                        if (f20 < lim) {
                            f20 = lim;
                        }
                        f20 = f20 * f20;
                        if (f20 < func_L01_0040E548(v + 0x10, self + 0x10)) {
                            flag = 0;
                        }
                    }
                    if (flag != 0) {
                        f20 = *(f32 *)(st + 0x30) - left;
                        if (!(0.0f < f20)) {
                            f20 = 0.0f;
                        }
                        *(f32 *)(st + 0x30) = f20;
                        st[0x77] = 0xC8;
                        func_003C4A40(self, st70);
                    }
                }
            }
        }
        if (*(s32 *)(p + 0x20) != 0) {
            if (*(f32 *)(st + 0x30) == 0.0f) {
                sph = *(V_0055E2E0 *)(self + 0x10);
                sph.w = 3.5f;
                if (func_L39_005BE900(&sph, 0, (f32)self[0x30]) != -1) {
                    func_L01_003303B8(self + 0x10, 0, 5, 5, 5, 5, 5, 0, 0.75f, 0.0f, 0.0f, 2.0f,
                                      0, 1, 1, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                                      0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                    func_L01_00451FE0(self, 0x1F, &D_L39_00242930, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f,
                                      0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
                    if (*(s32 *)(st + 0x230) != 0) {
                        h = func_L39_005F33E0(1, 0, self);
                    } else {
                        h = func_L39_005F33E0(5, 0, self);
                    }
                    spark.x = 0.0f;
                    spark.y = 0.0f;
                    spark.z = 1.0f;
                    spark.w = 0.0f;
                    func_L39_005F3718(h, &spark);
                }
                func_L01_004450F0(self, 7, -1);
                if (func_L39_0055DCB8(self) == 0) {
                    func_L39_0055DC30(self);
                }
            }
        }
    }
    self[0xA8] = 0xFF;
    return 0;
}
