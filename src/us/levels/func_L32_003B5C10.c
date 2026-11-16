#include "common.h"

/* NTSC-U counterpart of func_L32_003B7610 (src/levels/32_vidcomic_4/L32_003B7190.c) */
extern void func_L01_00441FB8(void *, s32, s32);
s32 func_0039FE80(s32, s32, void *);
void func_L01_00441FB8(void *, s32, s32);
#include "vu0.h"
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_L01_0032FE90_003B5C10(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

/* localdecomp:start func_L32_003B5C10 */
#include "vu0.h"
typedef struct {
    s32 count;
    s32 end;
    s32 start;
    s32 id;
    u8 pad[0x200];
} E_003B7610;

typedef struct {
    u8 pad0[0x80];
    E_003B7610 e[4];
    s32 slot[4];
    s32 f8D0;
    s32 f8D4;
    f32 f8D8;
    f32 f8DC;
    f32 f8E0;
    f32 f8E4;
    s32 f8E8;
    f32 f8EC;
    f32 f8F0;
} V_003B7610;

extern void *func_L31_0034D450(void *, s32, s32, s32, s32);
extern void func_L01_004A6DF8(void *, s32);
extern s32 func_L01_00452EC8(void *);
extern void func_L32_003B61B8(u8 *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E0F0(void *, s32, s32);
extern s32 func_L01_00452F60(void *);
extern u8 *func_L32_003B6908(u8 *, f32, f32);
extern s32 func_L01_0044AF40(void *, f32);
extern void func_003888C8(void *, void *, void *);
extern f32 func_003BEB48(f32, f32, f32);
extern s32 func_L32_0039E650(void *, void *, s32, f32 *, f32 *);
extern void func_L32_003B6768(u8 *, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern f32 func_L01_00436500(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L32_003B6080(u8 *);
extern u8 D_001A4C60[];
extern s32 D_L32_001DEFB0;
__asm__(".extern D_L32_001DEFB0, 4");
extern f32 D_L32_001DEFB4;
__asm__(".extern D_L32_001DEFB4, 4");
extern f32 D_L32_001DEFB8;
__asm__(".extern D_L32_001DEFB8, 4");
extern f32 D_L32_001DEFBC;
__asm__(".extern D_L32_001DEFBC, 4");
extern f32 D_L32_001DEFC0;
__asm__(".extern D_L32_001DEFC0, 4");
extern f32 D_L32_001DEFC4;
__asm__(".extern D_L32_001DEFC4, 4");

void func_L32_003B5C10(u8 *a0) {
    V_003B7610 *v = *(V_003B7610 **)(a0 + 0x68);
    f32 vec[4] __attribute__((aligned(16)));
    f32 fa0;
    f32 fa4;
    s32 frame;
    s32 found;
    s32 i;
    s32 j;
    f32 t;

    switch (a0[0x20]) {
    case 0x42:
        if (func_L01_00452EC8(a0)) {
            func_L01_0032FE90_003B5C10(a0 + 0x10, 0, 25, 20, 20, 20, 45, 1, 0.9f, 0.0f, 0.0f, 2.0f,
                              1, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L31_0034D450(a0 + 0x10, 3, 10, 0, 0xF0);
            *(s32 *)(a0 + 0x98) = 0;
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
            func_L01_004A6DF8(a0, 1);
        }
        break;
    case 0:
        func_L32_003B61B8(a0);
        func_L01_00441FB8(a0, 1, -1);
        break;
    case 1:
        v->f8E8++;
        frame = v->f8E8 % v->f8D4;
        found = 0;
        if (func_0037E0F0(D_001A4C60, v->f8D0, 0) != 0 && func_L01_00452F60(a0) == 0) {
            for (i = 0; i < 4; i++) {
                if (v->e[i].id != -1 && v->e[i].start <= frame && frame <= v->e[i].end) {
                    s32 *slots = v->slot;
                    s32 *slot = &slots[i];
                    if (*slot == 0) {
                        *slot = (s32)func_L32_003B6908(a0 + 0x10, v->f8EC, v->f8F0);
                    }
                    if (func_L01_0044AF40(a0, D_L32_001DEFC0)) {
                        f32 *pv = vec;
                        t = (f32)(frame - v->e[i].start) / (f32)(v->e[i].end - v->e[i].start);
                        qzero(vec);
                        vec[2] = D_L32_001DEFC4;
                        func_003888C8(pv, pv, a0 + 0xC0);
                        vec_add_ab(vec, vec, a0 + 0x10);
                        fa4 = func_003BEB48(v->f8DC, v->f8D8, t);
                        fa0 = func_003BEB48(v->f8E4, v->f8E0, t);
                        for (j = 0; j < v->e[i].count; j++) {
                            s32 r = func_L32_0039E650(vec, &v->e[i], 1, &fa0, &fa4);
                            if (slots[i] != 0) {
                                func_L32_003B6768((u8 *)slots[i], r);
                            }
                        }
                        func_0039FE80(0, 0, a0);
                    }
                    found = 1;
                } else {
                    s32 *slots = v->slot;
                    s32 *slot = &slots[i];
                    if (*slot != 0) {
                        *(s32 *)(*(u8 **)((u8 *)*slot + 0x68) + 0x88) = 0;
                        *slot = 0;
                    }
                }
            }
        } else {
            v->f8E8 = 0;
        }
        if (found) {
            if (a0[0x43] != 1 || D_L32_001DEFB4 <= func_L01_00436500(a0)) {
                func_003BE4F0(a0, 1, (s32)D_L32_001DEFBC, D_L32_001DEFB0);
            }
            *(f32 *)(a0 + 0x48) = D_L32_001DEFB8;
        } else {
            if (a0[0x43] != 0) {
                func_003BE4F0(a0, 0, 0, D_L32_001DEFB0);
            }
            *(f32 *)(a0 + 0x48) = 1.0f;
        }
        break;
    }
    func_L32_003B6080(a0);
}
/* localdecomp:end func_L32_003B5C10 */
