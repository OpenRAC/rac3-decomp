#include "common.h"

typedef struct {
    f32 f0;
    s32 f4;
} S_003CD938;

INCLUDE_ASM("asm/levels", func_L07_003CC2B0);

/* localdecomp:start func_L07_003CCAF0 */
typedef int Quad_3CCAF0 __attribute__((mode(TI)));
typedef struct Obj_3CCAF0 {
    u8 pad0[0x10];
    Quad_3CCAF0 pos;
    u8 pad20[0x68 - 0x20];
    u8 *vars;
    u8 pad6C[0xF0 - 0x6C];
    Quad_3CCAF0 qF0;
} Obj_3CCAF0;
typedef struct Vars_3CCAF0 {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0x44 - 0x36];
    u8 b44, b45, b46;
    u8 pad47[0x150 - 0x47];
    f32 f150, f154, f158, f15C, f160;
    u8 pad164[0x17C - 0x164];
    f32 f17C, f180, f184;
    u8 pad188[0x280 - 0x188];
    Quad_3CCAF0 q280;
    Quad_3CCAF0 q290;
    u8 pad2A0[0x400 - 0x2A0];
    s32 w400;
    u8 pad404[0x40C - 0x404];
    s32 w40C;
} Vars_3CCAF0;
extern void func_L01_00445F40(void *, s32);
extern s32 func_L07_003C1AF8(void);
extern f32 func_L07_003C1B40(s32);
extern void func_L01_00446058(void *, s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L07_003CCDF8(void *);

void func_L07_003CCAF0(Obj_3CCAF0 *obj) {
    Vars_3CCAF0 *vars = (Vars_3CCAF0 *)obj->vars;
    u8 *p;
    u8 *q;
    s32 height;
    s32 k;
    f32 scale;

    func_L01_00445F40(obj, 0x1769);
    k = func_L07_003C1AF8();
    p = (u8 *)vars + 0x30;
    scale = func_L07_003C1B40(k);
    height = (f32)vars->h34 * scale;
    *(s16 *)(p + 4) = height;
    vars->f30 = (f32)(s16)height;
    p[0x14] = (f32)vars->b44 * scale;
    p[0x15] = (f32)vars->b45 * scale;
    p[0x16] = (f32)vars->b46 * scale;
    if (k == 1) {
        func_L01_00446058(obj, 0x1D8B, 0x1769);
    }
    q = (u8 *)vars + 0x70;
    p[0x28] = 0x14;
    p[0x2A] = 0xE;
    *(f32 *)(p + 0x10) = 1.25f;
    p[9] = 0;
    p[0xF] = 0;
    *(f32 *)(q + 0x30) = 0.5f;
    *(f32 *)(q + 0x34) = 0.5f;
    *(f32 *)(q + 0x3C) = 0.15f;
    q[0x48] = 0xFF;
    q[0x10] = 2;
    if (vars->w40C != -1) {
        q[0x7B] = 0x1A;
        q[0x11] = 0x12;
        q[0x78] = 0;
        q[0x6C] = 0;
        q[0x6D] = 0;
        q[0x12] = 0x12;
        q[0x79] = 0;
        q[0x6E] = 0;
        q[0x6F] = 0;
    }
    vars->f150 = 0.65f;
    vars->f154 = 0.15f;
    vars->f158 = 0.5f;
    vars->f15C = 1.5f;
    vars->f160 = 1.48352981f;
    vars->f180 = 0.34906584f;
    vars->f17C = 0.00392000005f;
    vars->f184 = 0.2f;
    func_L01_0045BD78(obj, 0.00320000015f, 0.0500000045f, 0.00502654864f, 0.125663713f);
    vars->w400 = 0;
    vars->q280 = obj->pos;
    vars->q290 = obj->qF0;
    func_L07_003CCDF8(obj);
}
/* localdecomp:end func_L07_003CCAF0 */

/* localdecomp:start func_L07_003CCD40 */
typedef int Q_003CCD40 __attribute__((mode(TI)));
void func_L07_003CCD40(u8 *m,s32 which) {
    extern void func_L07_003BB1A8(u8 *);
    extern void func_L07_003CD2E8(void *,s32);
    u8 *d=*(u8 **)(m+0x68);
    u8 *object;
    if(*(u8 *)((s32)d+which+0x2a0)) {
        func_L07_003BB1A8(m);
        object=*(u8 **)(m+0x24);
        *(f32 *)(m+0x2c)=*(f32 *)(object+0x24);
        *(Q_003CCD40 *)(m+0x10)=*(Q_003CCD40 *)(d+0x280);
        *(Q_003CCD40 *)(m+0xf0)=*(Q_003CCD40 *)(d+0x290);
        *(u16 *)(m+0x34)&=0xfffd;
        if(*(s32 *)(d+0x428)!=-1) {
            func_L07_003CD2E8(m,3);
        } else {
            *(u16 *)(m+0x34)&=0xffbe;
            *(u16 *)(m+0x34)|=*(u16 *)(object+0x44)&0x1000;
            *(s32 *)(m+0x98)=*(s32 *)(object+0x10);
            func_L07_003CD2E8(m,5);
        }
    }
}
/* localdecomp:end func_L07_003CCD40 */

/* localdecomp:start func_L07_003CCDF8 */
void func_L07_003BB1F0();
void func_L07_003CD2E8(void *, s32);

void func_L07_003CCDF8(void *arg0) {
    void *temp_s1;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    func_L07_003BB1F0();
    *(s32 *)((u8 *)temp_s1 + 0x414) = 0;
    *(s8 *)((u8 *)temp_s1 + 0x406) = 0;
    *(s8 *)((u8 *)temp_s1 + 0x404) = 0;
    *(s8 *)((u8 *)temp_s1 + 0x405) = 0;
    *(s8 *)((u8 *)temp_s1 + 0x407) = 0;
    *(s32 *)((u8 *)temp_s1 + 0x410) = 0;
    *(s32 *)((u8 *)temp_s1 + 0x418) = -1;
    func_L07_003CD2E8(arg0, 0x19);
}
/* localdecomp:end func_L07_003CCDF8 */

/* localdecomp:start func_L07_003CCE58 */
s32 func_L07_003CCE58(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x20)) == 0x19;
}
/* localdecomp:end func_L07_003CCE58 */

/* localdecomp:start func_L07_003CCE68 */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

extern void func_L07_003CE940(void *);
extern void func_L07_003CD2E8(void *, s32);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L01_004443E8(void *, s32, s32);
extern void func_L07_003CCDF8(void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00404808(void *, void *);
extern void func_L07_003CE3A8();
extern void func_L07_004522E8(void *, s32, void *, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
extern u8 D_L07_001E1EC0[];

void func_L07_003CCE68(u8 *obj) {
    u8 *p;
    f32 pos[4] __attribute__((aligned(16)));
    f32 t;

    p = *(u8 **)(obj + 0x68);
    if (obj[0x20] == 1) {
        return;
    }
    if (obj[0x20] >= 0xC) {
        if (*(s16 *)(p + 0x144) != 1) {
            func_L07_003CE940(obj);
            func_L07_003CD2E8(obj, 5);
        }
    }
    if (func_L01_00452FB0(obj, p + 0x70, 0, 0, 0) != 0) {
        p[0x407] = 0;
        func_L07_003CE940(obj);
    }
    if (*(f32 *)(p + 0x30) <= 0.0f) {
        *(u128_t *)pos = *(u128_t *)(obj + 0x10);
        pos[2] = pos[2] + *(f32 *)(p + 0x40);
        func_L01_003303B8(pos, 0, 0xA, 5, 4, 0xA, 0xF, 0, 0.5f, 0.0f, 0.0f, 2.0f, 0, 0, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L01_00451FE0(obj, 0x3FFF, D_L07_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_004443E8(obj, 0, 3);
        func_L07_003CCDF8(obj);
        func_003A52A0(9, 0, obj);
        return;
    }
    if (*(s32 *)(p + 0x228) == 1 || *(s32 *)(p + 0x228) == 0xB) {
        qzero(pos);
        func_L01_00446A70(obj, obj, 0x10000, pos, pos, (f32)*(s16 *)(p + 0x34));
    } else if (p[0x5E] != 0 || p[0x60] != 0 || p[0x3E] == 2) {
        func_L01_004443E8(obj, 0, 3);
        func_L07_003CCDF8(obj);
        return;
    }
    func_L01_00452860(obj, p + 0x30, 0);
    if (p[0x5F] != 0) {
        func_L01_00456BD0(obj, 5);
        if (obj[0x20] == 5) {
            func_L01_00456C98(obj, *(s32 *)(p + 0x2B0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2B4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(obj, *(s32 *)(p + 0x2B8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2BC), 10.0f, 1.0f);
        }
    } else {
        func_L01_00456BD0(obj, 3);
        if (obj[0x20] == 5) {
            func_L01_00456C98(obj, *(s32 *)(p + 0x2B0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2B4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(obj, *(s32 *)(p + 0x2B8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2BC), 10.0f, 1.0f);
        }
    }
    t = *(f32 *)(p + 0x400) - -0.120000005f;
    *(f32 *)(p + 0x400) = t;
    if (t < 0.0f) {
        *(f32 *)(p + 0x400) = t + 1.0f;
    }
    func_L01_00404808(func_L07_003CE3A8, obj);
    func_L07_004522E8(obj, 0xA, p + 0x240, 2.5f);
    if (obj[0x31] != 0) {
        if (func_L01_0040E548(D_L07_001E1EC0, obj + 0x10) < 576.0f) {
            func_L01_004472C0(obj);
            obj[0x6F] = 0x16;
        }
    }
}
/* localdecomp:end func_L07_003CCE68 */
