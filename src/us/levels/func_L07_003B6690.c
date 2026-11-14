#include "common.h"

/* localdecomp:start func_L07_003B6690 */
typedef struct {
    u8 pad_00[0x30];
    f32 f30;
    s16 h34;
    u8 pad_36[0x11];
    u8 b47;
    u8 pad_48[0x16];
    u8 b5E;
    u8 pad_5F;
    u8 b60;
    u8 pad_61[0x11F];
    s16 h180;
    u8 pad_182[5];
    u8 b187;
    u8 pad_188[8];
    s32 w190;
    u8 pad_194[0x9C];
    s32 f230;
    u8 pad_234[0x48];
    s32 w27C;
    s32 w280;
    u8 pad_284[4];
    s32 w288;
    u8 pad_28C[0xA];
    u8 b296;
    u8 pad_297[2];
    u8 b299;
    u8 pad_29A[2];
    s16 h29C;
    s16 h29E;
    u8 pad_2A0[4];
    s32 w2A4;
} Sub_3B6690;

typedef struct {
    u8 pad_00[0x144];
    u8 *w144;
    s32 w148;
} Pool_3B6690;

extern u8 *D_L07_001DF41C_003B6690;
__asm__(".extern D_L07_001DF41C_003B6690, 16");
extern Pool_3B6690 D_L07_001E1EC0_003B6690;
__asm__(".extern D_L07_001E1EC0_003B6690, 16");

extern u8 *func_L01_00444358(void *, s32, s32);
extern f32 func_L01_004443B0(void *, void *);
extern void func_L01_004568F8(void *, s32, f32);
extern void func_003BF4F8(void *, void *);
extern void func_L01_004479A8(void *, void *);
extern void func_L01_0044B598(void *, s32);
extern void func_L07_003A5CA8(s32, s32, s32);
extern void func_L07_003B6DA0(void *, s32);
extern void func_L07_003A0BC0(s32, void *, s32, s32);
extern void func_L07_00330E70(void *);
extern void func_L01_00479140(s32, s32, s32, f32);
extern void func_L01_004538E0(void *, s32);
extern s32 func_L07_003335E0(s32);
extern void func_L01_004539A8(f32, f32, f32, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L07_003B6F80(void *);
extern s32 func_L01_00452F60(void *);
extern s32 func_0037E1D8(s32);
extern void func_L01_00452F40(void *, s32);
extern s32 func_003883C8(void *);
extern void func_L07_0044F0E8(void *, s32, void *, f32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);

void func_L07_003B6690(u8 *obj) {
    Sub_3B6690 *s = *(Sub_3B6690 **)(obj + 0x68);
    u8 *t;
    u8 *hit;
    f32 f20;
    s32 pool;

    if (obj[0x20] == 1) {
        return;
    }
    t = func_L01_00444358(obj, -1, 0);
    f20 = func_L01_004443B0(obj, t);
    obj[0xA8] = 0xFF;
    if ((*(u16 *)(obj + 0x34) & 0x4000) != 0 && 0.0f < f20) {
        if (t != 0 && *(u8 **)(t + 0x20) != 0 && *(s16 *)(*(u8 **)(t + 0x20) + 0xAA) == 0x1A1C) {
            f20 = 1.0f;
        }
        s->f30 = s->f30 - f20;
        func_L01_004568F8(obj, s->b47, f20);
        s->b187 = 0xFF;
        func_003BF4F8(obj, (u8 *)s + 0x180);
        if ((f32)s->h34 * 0.1f <= f20) {
            hit = D_L07_001DF41C_003B6690 + (s->w280 << 8);
            if (hit[0xBC] == 0) {
                hit[0xBC] = 2;
            }
        }
    }
    func_L01_004479A8(obj, (u8 *)s + 0x180);
    if (s->h180 == 0) {
        func_L01_0044B598(obj, s->w2A4);
    }
    if (s->b296 == 0) {
        if (s->f30 < (f32)s->h34 * 0.65f) {
            func_L07_003A5CA8(s->w288, 0, 0xA);
            func_L07_003B6DA0(obj, 0xD);
            s->b296 = 1;
            s->f30 = (f32)s->h34 * 0.65f;
            D_L07_001DF41C_003B6690[(s->w280 << 8) + 0xBC] = 3;
        }
    } else if (s->b296 == 1) {
        if (s->f30 < (f32)s->h34 * 0.3f) {
            func_L07_003A5CA8(s->w288, 0, 0xA);
            s->b296 = 2;
            s->f30 = (f32)s->h34 * 0.3f;
            D_L07_001DF41C_003B6690[(s->w280 << 8) + 0xBC] = 4;
            func_L07_003A0BC0(0xA, obj, 0, 0x78);
        }
    }
    if (s->f30 <= 0.0f) {
        s->b299 = 0;
        func_L07_003A5CA8(s->w288, 0, 0xA);
        func_L07_003B6DA0(obj, 0x11);
        return;
    }
    if (s->b5E != 0) {
        func_L07_00330E70(obj);
        s->b5E = 0;
        return;
    }
    if (s->b60 != 0) {
        func_L07_00330E70(obj);
        s->b60 = 0;
        return;
    }
    if (s->b299 != 0) {
        if (D_L07_001E1EC0_003B6690.w144 != obj && D_L07_001E1EC0_003B6690.w144 == 0) {
            D_L07_001E1EC0_003B6690.w144 = obj;
            D_L07_001E1EC0_003B6690.w148 = 0;
        }
    } else {
        if (D_L07_001E1EC0_003B6690.w144 == obj) {
            D_L07_001E1EC0_003B6690.w144 = 0;
        }
    }
    func_L01_00479140(3, 2, D_L07_001E1EC0_003B6690.w144 != obj, s->f30 / (f32)s->h34);
    func_L01_004538E0(obj, 3);
    pool = func_L07_003335E0(s->w190);
    func_L01_004539A8(0.0f, 0.0f, 1.0f, obj, pool, 0, 0, 0, 0, 1, 0, 0, 0);
    func_L07_003B6F80(obj);
    if (func_L01_00452F60(obj) != 0) {
        if (s->h29E == 0) {
            hit = D_L07_001DF41C_003B6690 + (s->w280 << 8);
            if (hit[0xBC] == 0) {
                hit[0xBC] = 1;
            }
            if (func_0037E1D8(2) != 0) {
                func_L07_003A0BC0(0, obj, 0, 0x78);
            } else {
                func_L07_003A0BC0(1, obj, 0, 0x78);
            }
            s->h29E = 0x4B0;
        }
        func_L01_00452F40(obj, 0);
    }
    func_003883C8(&s->h29C);
    func_L07_0044F0E8(obj, 4, &s->f230, 2.5f);
    if (func_L01_0040C018(&D_L07_001E1EC0_003B6690, obj + 0x10) < 5625.0f) {
        func_L01_00444188(obj);
        obj[0x6F] = 0x46;
    }
}
/* localdecomp:end func_L07_003B6690 */
