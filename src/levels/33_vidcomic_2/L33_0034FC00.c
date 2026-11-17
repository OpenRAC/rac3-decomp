#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L33_0034FC00);

/* localdecomp:start func_L33_0034FEE8 */
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_003C7DD8(void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern s32 func_003A52A0(s32, s32, void *);
void func_L33_0034F9D8(u8 *, f32, f32, s32, s32, s32, f32, f32, f32);
extern void func_L31_003ABD70(u8 *, u8 *);
void func_L33_0034FC00(u8 *, u8 *);

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0034FEE8;

typedef struct {
    u8 obj[0x10];
    s32 val;
} E_0034FEE8;

extern E_0034FEE8 D_L33_001E1810 __attribute__((section(".sdata")));
extern E_0034FEE8 D_L33_001E1830 __attribute__((section(".sdata")));
extern s32 D_L33_001DD7D0;
__asm__(".extern D_L33_001DD7D0, 4");
extern s32 D_L33_001DD7D4;
__asm__(".extern D_L33_001DD7D4, 4");
extern f32 D_L33_001DD7DC;
__asm__(".extern D_L33_001DD7DC, 4");
extern f32 D_L33_001DD7E0;
__asm__(".extern D_L33_001DD7E0, 4");
extern s32 D_L33_001DD7F8;
__asm__(".extern D_L33_001DD7F8, 4");
extern s32 D_L33_001DD7FC;
__asm__(".extern D_L33_001DD7FC, 4");
extern f32 D_L33_001DD80C;
__asm__(".extern D_L33_001DD80C, 4");
extern s32 D_L33_001DD810;
__asm__(".extern D_L33_001DD810, 4");
extern s32 D_L33_001DD824;
__asm__(".extern D_L33_001DD824, 4");
extern s32 D_L33_001DD828;
__asm__(".extern D_L33_001DD828, 4");
extern s32 D_L33_001DD82C;
__asm__(".extern D_L33_001DD82C, 4");
extern f32 D_L33_001DD83C;
__asm__(".extern D_L33_001DD83C, 4");
extern s32 D_L33_001DD840;
__asm__(".extern D_L33_001DD840, 4");

typedef struct {
    V_0034FEE8 src;
    u8 pad10[4];
    f32 f14;
    s32 f18;
    void *owner;
    f32 f20;
    s32 f24;
    f32 f28;
    u8 pad2C[0x10];
    s32 f3C;
} P_0034FEE8;

typedef struct {
    u8 pad0[0x10];
    V_0034FEE8 pos;
    u8 pad20[3];
    u8 alpha;
    u8 *pclass;
    u8 pad28[4];
    f32 scale;
    u8 pad30[4];
    u16 flags;
    u8 pad36[0x68 - 0x36];
    P_0034FEE8 *pvars;
    u8 pad6C[0x98 - 0x6C];
    s32 f98;
    u8 pad9C[0xF0 - 0x9C];
    f32 rotX;
    f32 rotY;
    f32 rotZ;
} M_0034FEE8;

void *func_L33_0034FEE8(void *pos, void *src, void *owner, s32 flag, s32 snd, f32 alpha, f32 f1, f32 f2, f32 scale, f32 f3) {
    M_0034FEE8 *m;
    P_0034FEE8 *v;

    m = (M_0034FEE8 *)func_003C24B0(0x174B, 0x80);
    if (m == 0) {
        return 0;
    }
    func_L01_00456160((u8 *)m, 0);
    m->pos = *(V_0034FEE8 *)pos;
    func_003C7DD8(m);
    m->flags &= ~5;
    m->rotX = func_0038DB48(func_003824E0(-D_L33_001DD7DC, D_L33_001DD7DC));
    m->rotY = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
    m->rotZ = func_0038DB48(func_003824E0(-D_L33_001DD7E0, D_L33_001DD7E0));
    m->scale = scale * *(f32 *)(m->pclass + 0x24);
    m->alpha = (s32)(alpha * 128.0f);
    if (m->alpha < 0x7F) {
        m->flags |= 8;
    }
    v = m->pvars;
    *(vu0_q *)v = *(vu0_q *)src;
    v->f14 = f1;
    v->f18 = D_L33_001DD7D4;
    v->owner = owner;
    v->f20 = f2;
    v->f24 = -1;
    v->f28 = f3;
    v->f3C = -1;
    m->f98 = 0;
    func_L01_004450F0(m, 1, -1);
    if (D_L33_001DD7D0 == 0) {
        func_L03_0034B218(D_L33_001E1810.obj, D_L33_001DD7F8, D_L33_001DD7FC, D_L33_001DD80C, D_L33_001DD810, (void *)func_L31_003ABD70);
        func_L03_0034B218(D_L33_001E1830.obj, D_L33_001DD828, D_L33_001DD82C, D_L33_001DD83C, D_L33_001DD840, (void *)func_L33_0034FC00);
        D_L33_001DD7D0 = 1;
        D_L33_001E1830.val = D_L33_001DD824;
    }
    if (flag) {
        func_L33_0034F9D8((u8 *)m, 0.5f, -0.008f, 3, 5, 0x174B, 0.4f, 0.3f, 0.7f);
        func_L01_004450F0(m, 2, -1);
    } else {
        if (snd) {
            func_003A52A0(0, 0, m);
        }
        func_L01_004450F0(m, 1, -1);
    }
    return m;
}
/* localdecomp:end func_L33_0034FEE8 */
