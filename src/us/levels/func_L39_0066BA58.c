#include "common.h"

/* NTSC-U counterpart of func_L39_0066E378 (src/levels/shared/L39_0066E378.c) */
/* localdecomp:start func_L39_0066BA58 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0066E378;

typedef struct {
    V_0066E378 r[4];
} M_0066E378;

typedef struct {
    u8 pad0[0x10];
    V_0066E378 pos;
    u8 pad20[0xC0 - 0x20];
    M_0066E378 mat;
} Mo_0066E378;

extern void func_003888C8(void *, void *, void *);
extern void func_003BD9A0(void *, s32, void *);
extern void func_003BDA38(void *, s32, void *);
extern u8 *func_0037E0B8(void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388770(void *);
extern void func_0037E4B8(void *, f32, f32, f32);
/* the spawn call: ABI-identical to the callee's (.., s32, u32, f32, f32); with the colour last the
   colour load is scheduled after the float arguments, as in retail */
extern u8 *func_L07_003C9438(void *, void *, void *, s32, void *, s32, f32, f32, u32);
extern void func_L39_005FBF00(void *, void *, void *, void *, void *, f32, f32, f32, f32);
extern u8 *func_L39_0054CB98(s32, void *, void *, s32, s32, s32);
extern s32 func_L39_005F0CE0(s32, s32, void *);
extern u8 *func_L39_0061B038(void *);
extern u8 *func_L39_00665D48(void *);
extern void func_L39_00544EB0(void *, void *, s32);
extern void func_L39_00544D38(void *, void *, s32);
extern void func_L39_0052C920(void *, void *, s32, s32, s32, s32);
extern V_0066E378 D_L39_0024AD00_0066BA58[] __attribute__((section(".sdata")));
extern f32 D_L39_0024ACE4_0066BA58;
extern f32 D_L39_0024ACEC_0066BA58;
extern s32 D_L39_0024ACF0_0066BA58;
extern s32 D_L39_0024ACF4_0066BA58;
extern f32 D_L39_0024AC4C;
__asm__(".extern D_L39_0024AC4C, 4");

void func_L39_0066BA58(void *a0, u8 *moby, u8 *target) {
    V_0066E378 tgt;
    V_0066E378 v10;
    V_0066E378 out;
    V_0066E378 v30;
    V_0066E378 v40;
    M_0066E378 mat;
    Mo_0066E378 mo;
    V_0066E378 v190;
    V_0066E378 v1A0;
    s32 flags;
    u8 *p;
    void *list;
    s32 id;
    f32 len;

    id = -1;
    p = *(u8 **)(moby + 0x4C);
    list = *(void **)(p + 0x450);
    qzero(&v10);
    v10.x = 1.0f;
    flags = 0x80000000;
    func_003888C8(&v10, &v10, p + 0x20);
    if (list == 0) {
        return;
    }
    switch ((s16)*(u16 *)(moby + 0x34)) {
    case 5: {
        u8 *g = *(u8 **)(p + 0x2528);

        if (g == 0) {
            break;
        }
        func_003BD9A0(*(void **)(g + 0x2D0), 2, &mat);
        mo.pos = *(V_0066E378 *)(moby + 0x10);
        tgt = mat.r[3];
        mo.mat = mat;
        func_L39_005FBF00(0, &out, &tgt, &mo, &mo, 0.0f, 0.0f, 0.78333336f, 0.0055555557f);
        *(u8 **)(moby + 0x28) = func_L39_0054CB98(*(s32 *)(*(u8 **)(p + 0x2528) + 0x2D0), &tgt, &out,
                                                  *(s32 *)(moby + 0x58), *(s32 *)(p + 0x2524), (s32)p);
        func_L39_005F0CE0(0, 0, list);
        break;
    }
    case 6: {
        u8 *g = *(u8 **)(p + 0x2528);
        u8 *q;
        u8 *r;

        if (g == 0) {
            break;
        }
        q = *(u8 **)(g + 0x2D8);
        if (q != 0) {
            id = *(s32 *)(q + 0x2544);
        }
        func_003888C8(&v30, &D_L39_0024AD00_0066BA58[*(u8 *)(g + 0x2FE)], *(u8 **)(g + 0x2D0) + 0xC0);
        vec_add_ab(&v30, &v30, *(u8 **)(*(u8 **)(p + 0x2528) + 0x2D0) + 0x10);
        if (target != 0) {
            u8 *sz;
            u8 *t;
            u8 *x;

            len = 0.1f;
            sz = func_0037E0B8(target);
            if (sz != 0) {
                len = *(f32 *)(sz + 0x10);
            }
            func_003886E8(&v190, target + 0xE0, len);
            vec_add_ba(&v190, target + 0x10, &v190);
            vec_sub_ab(&v40, &v190, &v30);
            len = func_00388770(&v40);
            qzero(&v1A0);
            t = func_L39_0061B038(target);
            x = 0;
            if (t != 0 && !(t[3] & 0xF)) {
                x = t;
            }
            if (x != 0) {
                v1A0 = *(V_0066E378 *)(x + 0x140);
            } else if (*(s16 *)(target + 0xAA) == 0x107C) {
                v1A0 = *(V_0066E378 *)(func_L39_00665D48(target) + 0x270);
            }
            if (0.0f < len) {
                func_003886E8(&v1A0, &v1A0, D_L39_0024AC4C / len);
                func_003886E8(&v40, &v40, (*(f32 *)(*(u8 **)(p + 0x2528) + 0x310) + 1.5000001f) / len);
            } else {
                func_003886E8(&v1A0, &v1A0, D_L39_0024AC4C);
                func_003886E8(&v40, &v40, *(f32 *)(*(u8 **)(p + 0x2528) + 0x310) + 1.5000001f);
            }
            vec_add_ab(&v40, &v40, &v1A0);
        } else {
            u8 *h = *(u8 **)(p + 0x2528);
            u8 *m = *(u8 **)(h + 0x2D0);

            func_0037E4B8(&v40, *(f32 *)(h + 0x310) + 1.5000001f, *(f32 *)(m + 0xF8), -(*(f32 *)(m + 0xF4) + 0.03f));
        }
        func_L39_005F0CE0(3, 0, *(void **)(*(u8 **)(p + 0x2528) + 0x2D0));
        r = func_L07_003C9438(&v30, &v40, *(void **)(*(u8 **)(p + 0x2528) + 0x2D0), 1, &flags, id,
                              4.0f, D_L39_0024ACE4_0066BA58, *(u32 *)(moby + 0x58));
        *(u8 **)(moby + 0x28) = r;
        if (r != 0) {
            s32 n = D_L39_0024ACF0_0066BA58;

            *(s32 *)(r + 0x90) = *(s32 *)p;
            *(s32 *)(*(u8 **)(*(u8 **)(moby + 0x28) + 0x68) + 0x24) = n;
            *(f32 *)(*(u8 **)(*(u8 **)(moby + 0x28) + 0x68) + 0x28) = 1.0f / (f32)n;
        }
        *(u8 *)(*(u8 **)(p + 0x2528) + 0x2FE) ^= 1;
        break;
    }
    case 7: {
        u8 *g = *(u8 **)(p + 0x2528);
        u8 *q;
        u8 *r;

        if (g == 0) {
            break;
        }
        q = *(u8 **)(g + 0x2DC);
        if (q != 0) {
            id = *(s32 *)(q + 0x2544);
        }
        func_003BDA38(*(void **)(g + 0x2D0), *(u8 *)(g + 0x2FF) ? 0x12 : 0x11, &v30);
        if (target != 0) {
            u8 *sz;
            u8 *t;
            u8 *x;

            len = 0.1f;
            sz = func_0037E0B8(target);
            if (sz != 0) {
                len = *(f32 *)(sz + 0x10);
            }
            func_003886E8(&v190, target + 0xE0, len);
            vec_add_ba(&v190, target + 0x10, &v190);
            vec_sub_ab(&v40, &v190, &v30);
            len = func_00388770(&v40);
            qzero(&v1A0);
            t = func_L39_0061B038(target);
            x = 0;
            if (t != 0 && !(t[3] & 0xF)) {
                x = t;
            }
            if (x != 0) {
                v1A0 = *(V_0066E378 *)(x + 0x140);
            } else if (*(s16 *)(target + 0xAA) == 0x107C) {
                v1A0 = *(V_0066E378 *)(func_L39_00665D48(target) + 0x270);
            }
            if (0.0f < len) {
                func_003886E8(&v1A0, &v1A0, D_L39_0024AC4C / len);
                func_003886E8(&v40, &v40, (*(f32 *)(*(u8 **)(p + 0x2528) + 0x310) + 1.5000001f) / len);
            } else {
                func_003886E8(&v1A0, &v1A0, D_L39_0024AC4C);
                func_003886E8(&v40, &v40, *(f32 *)(*(u8 **)(p + 0x2528) + 0x310) + 1.5000001f);
            }
            vec_add_ab(&v40, &v40, &v1A0);
        } else {
            v40 = *(V_0066E378 *)(moby + 0x10);
        }
        func_L39_005F0CE0(3, 0, *(void **)(*(u8 **)(p + 0x2528) + 0x2D0));
        r = func_L07_003C9438(&v30, &v40, *(void **)(*(u8 **)(p + 0x2528) + 0x2D0), 1, &flags, id,
                              4.0f, D_L39_0024ACEC_0066BA58, *(u32 *)(moby + 0x58));
        *(u8 **)(moby + 0x28) = r;
        if (r != 0) {
            s32 n = D_L39_0024ACF4_0066BA58;

            *(s32 *)(r + 0x90) = *(s32 *)p;
            *(s32 *)(*(u8 **)(*(u8 **)(moby + 0x28) + 0x68) + 0x24) = n;
            *(f32 *)(*(u8 **)(*(u8 **)(moby + 0x28) + 0x68) + 0x28) = 1.0f / (f32)n;
        }
        *(u8 *)(*(u8 **)(p + 0x2528) + 0x2FF) ^= 1;
        break;
    }
    case 8:
        if (*(u8 **)(p + 0x2528) != 0) {
            func_L39_00544EB0(*(void **)(*(u8 **)(p + 0x2528) + 0x2D0), moby + 0x10, *(s32 *)(moby + 0x58));
        }
        break;
    case 9:
        if (*(u8 **)(p + 0x2528) != 0) {
            func_L39_00544D38(*(void **)(*(u8 **)(p + 0x2528) + 0x2D0), moby + 0x10, *(s32 *)(moby + 0x58));
        }
        break;
    case 10:
    case 11:
        if (*(u8 **)(p + 0x2528) != 0) {
            func_L39_0052C920(*(void **)(*(u8 **)(p + 0x2528) + 0x2D0), moby + 0x10, *(s32 *)(moby + 0x58),
                              (s16)*(u16 *)(moby + 0x34), *(s32 *)(p + 0x2548), *(s32 *)p);
        }
        break;
    }
}
/* localdecomp:end func_L39_0066BA58 */
