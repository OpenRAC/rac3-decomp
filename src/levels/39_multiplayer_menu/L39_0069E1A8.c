#include "common.h"

/* localdecomp:start func_L39_0069E1A8 */
void func_L39_0069E1A8(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x2C8) = arg1;
}
/* localdecomp:end func_L39_0069E1A8 */

INCLUDE_ASM("asm/levels", func_L39_0069E1B0);

LINKER_REMNANT("asm/levels", func_L39_0069E5B8);

INCLUDE_ASM("asm/levels", func_L39_0069E5C0);

/* localdecomp:start func_L39_0069E740 */
extern u8 D_L39_0047D310[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_0069E740(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047D310;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_0069E740 */

/* localdecomp:start func_L39_0069E768 */
extern f32 D_001DCCA4_sda;
extern f32 D_001DCCA8_sda;
extern f32 D_001DCCAC_sda;
extern f32 D_001DCCB0_sda;
extern f32 D_001DCCB4_sda;
extern void func_L39_00688460(void *a0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, void *p1, void *p2, void *p3, void *p4, void *p5);

void func_L39_0069E768(void *a0)
{
    s32 v[4];
    func_L39_00688460(a0, D_001DCCA4_sda, D_001DCCA8_sda, D_001DCCAC_sda, D_001DCCB0_sda, D_001DCCB4_sda, v, v, v, v, v);
}
/* localdecomp:end func_L39_0069E768 */

/* localdecomp:start func_L39_0069E7A8 */
extern f32 D_001DCCB8_sda;
extern f32 D_001DCCBC_sda;
extern f32 D_001DCCC0_sda;
extern f32 D_001DCCC4_sda;
extern f32 D_001DCCC8_sda;
extern f32 D_001DCCCC_sda;
extern f32 D_001DCCD0_sda;
extern f32 D_001DCCD4_sda;
extern f32 D_001DCCD8_sda;
void func_L39_0067F100(s32);
void func_L39_0068AAB8(void *);
void func_L39_0068A4A8(void *, s32, s32, s32, f32, f32, f32, f32);
void func_L39_00689F00(void *, s32, s32, f32, f32, f32, f32, f32, f32, s32);
void func_L39_0068B2F8(void *, s32, s32);

typedef struct V_0069E7A8 V_0069E7A8;
typedef struct O_0069E7A8 {
    u8 pad[0x60];
    V_0069E7A8 *vt;
} O_0069E7A8;
struct V_0069E7A8 {
    u8 pad[0x1C];
    void (*f1C)(O_0069E7A8 *, s32, s32);
    u8 pad20[0x20];
    void (*f40)(O_0069E7A8 *, s32);
    void (*f44)(O_0069E7A8 *, s32, f32, f32);
    u8 pad48[4];
    void (*f4C)(O_0069E7A8 *, s32, s32);
};

void func_L39_0069E7A8(u8 *p) {
    O_0069E7A8 **objs;
    s32 i;
    f32 w;
    f32 x0;
    f32 x1;

    i = 1;
    func_L39_0067F100(0x2E0000);
    objs = (O_0069E7A8 **)(p + 0x110);
    func_L39_0068AAB8(p);
    w = D_001DCCC4_sda - D_001DCCC8_sda;
    x0 = D_001DCCBC_sda + w * 0.0f * 0.5f;
    x1 = D_001DCCBC_sda + w * 0.5f;
    func_L39_0068A4A8(p, 0, 1, 0x332299DE, D_001DCCB8_sda, x0 + D_001DCCCC_sda, x1 - x0, D_001DCCC0_sda - D_001DCCC8_sda);
    func_L39_00689F00(p, 0, 3, 1.5f, 1.5f, D_001DCCC0_sda - D_001DCCC8_sda, D_001DCCD0_sda, D_001DCCD4_sda, D_001DCCD8_sda, 3);
    do {
        (*objs)->vt->f40(*objs, 0);
        (*objs)->vt->f4C(*objs, 0x40, 1);
        (*objs)->vt->f44(*objs, 1, D_001DCCC0_sda - (D_001DCCC8_sda + D_001DCCC8_sda), 0.0f);
        (*objs)->vt->f1C(*objs, 3, 0);
        objs++;
    } while (--i >= 0);
    *(s32 *)(p + 0x2A8) = -1;
    func_L39_0068B2F8(p, 0, 0);
}
/* localdecomp:end func_L39_0069E7A8 */

/* localdecomp:start func_L39_0069E920 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_0069E920(void *);

extern void func_L39_0067F168();
void func_L39_0069E920(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_0069E920 */

/* localdecomp:start func_L39_0069E950 */
__asm__(".extern D_L39_00247914, 16");
extern u8 *D_L39_00247914;
extern s32 D_001A43E8[];
extern f32 D_001DCCDC_sda;
extern f32 D_001DCCB8_sda;
void func_L39_006B7E90(s32 a, s32 b, s32 c, s32 d, s32 e);
s32 func_L39_00688340(s32, s32, s32);
s32 func_L39_0068AEF8(void *, s32);
void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);

typedef struct V_0069E950 V_0069E950;
typedef struct O_0069E950 {
    u8 pad[0x60];
    V_0069E950 *vt;
} O_0069E950;
struct V_0069E950 {
    u8 pad[0x30];
    void (*get)(O_0069E950 *, s32 *, f32 *);
};

typedef struct P_0069E950 {
    u8 pad0[0x110];
    O_0069E950 *objs[0x60];
    s32 x290;
    u8 pad294[0x14];
    s32 x2A8;
    u8 x2AC;
} P_0069E950;

s32 func_L39_0069E950(P_0069E950 *p, s32 arg1) {
    s32 a;
    f32 b;
    s32 idx;
    s32 sel;

    func_L39_006B7E90(1, 0, 0x190, 0, 0x82);
    if (arg1 == 7) {
        p->x2A8 = p->x290;
        *(s32 *)(D_L39_00247914 + 0x284) = 0x2C;
        return 1;
    }
    if ((u32)(arg1 - 3) < 2) {
        func_L39_00688340(3, 0, 0);
    }
    if (func_L39_0068AEF8(p, arg1)) {
        return 1;
    }
    if (p->x2AC && D_001A43E8[0] != 2) {
        p->x2A8 = 3;
        *(s32 *)(D_L39_00247914 + 0x284) = 0x2C;
        return 1;
    }
    idx = p->x290;
    if (idx >= 0) {
        O_0069E950 *o = p->objs[idx];
        o->vt->get(o, &a, &b);
        sel = p->x290 == 0 ? 2 : 0;
        if (p->x290 == 1) {
            sel |= 1;
        }
        func_L39_0068A2D0(p, sel, 3, 3, D_001DCCB8_sda, b + D_001DCCDC_sda);
    }
    return 0;
}
/* localdecomp:end func_L39_0069E950 */
