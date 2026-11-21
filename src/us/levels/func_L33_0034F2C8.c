#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L33_0034FEE8 (src/levels/33_vidcomic_2/L33_0034FC00.c): level data 0x40/0x80 higher, rate -1/180 for -0.008 */
/* localdecomp:start func_L33_0034F2C8 */
extern u8 *func_003BCFB0(s32, s32);
extern void func_L01_00452E70(u8 *, u8 *);
extern void func_003C2868(void *);
extern f32 func_0037E250(f32, f32);
extern f32 func_00389410(f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L03_0034A658(u8 *, s32, s32, f32, s32, void *);
extern s32 func_0039FE80(s32, s32, void *);
void func_L33_0034EDB8(u8 *, f32, f32, s32, s32, s32, f32, f32, f32);
extern void func_L31_003AA4A8(u8 *, u8 *);
void func_L33_0034EFE0(u8 *, u8 *);

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0034FEE8;

typedef struct {
    u8 obj[0x10];
    s32 val;
} E_0034FEE8;

extern E_0034FEE8 D_L33_001E1890 __attribute__((section(".sdata")));
extern E_0034FEE8 D_L33_001E18B0 __attribute__((section(".sdata")));
extern s32 D_L33_001DD810;
__asm__(".extern D_L33_001DD810, 4");
extern s32 D_L33_001DD814;
__asm__(".extern D_L33_001DD814, 4");
extern f32 D_L33_001DD81C;
__asm__(".extern D_L33_001DD81C, 4");
extern f32 D_L33_001DD820;
__asm__(".extern D_L33_001DD820, 4");
extern s32 D_L33_001DD838;
__asm__(".extern D_L33_001DD838, 4");
extern s32 D_L33_001DD83C;
__asm__(".extern D_L33_001DD83C, 4");
extern f32 D_L33_001DD84C;
__asm__(".extern D_L33_001DD84C, 4");
extern s32 D_L33_001DD850;
__asm__(".extern D_L33_001DD850, 4");
extern s32 D_L33_001DD864;
__asm__(".extern D_L33_001DD864, 4");
extern s32 D_L33_001DD868;
__asm__(".extern D_L33_001DD868, 4");
extern s32 D_L33_001DD86C;
__asm__(".extern D_L33_001DD86C, 4");
extern f32 D_L33_001DD87C;
__asm__(".extern D_L33_001DD87C, 4");
extern s32 D_L33_001DD880;
__asm__(".extern D_L33_001DD880, 4");

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

void *func_L33_0034F2C8(void *pos, void *src, void *owner, s32 flag, s32 snd, f32 alpha, f32 f1, f32 f2, f32 scale, f32 f3) {
    M_0034FEE8 *m;
    P_0034FEE8 *v;

    m = (M_0034FEE8 *)func_003BCFB0(0x174B, 0x80);
    if (m == 0) {
        return 0;
    }
    func_L01_00452E70((u8 *)m, 0);
    m->pos = *(V_0034FEE8 *)pos;
    func_003C2868(m);
    m->flags &= ~5;
    m->rotX = func_00389410(func_0037E250(-D_L33_001DD81C, D_L33_001DD81C));
    m->rotY = func_00389410(func_0037E250(0.0f, 6.2831855f));
    m->rotZ = func_00389410(func_0037E250(-D_L33_001DD820, D_L33_001DD820));
    m->scale = scale * *(f32 *)(m->pclass + 0x24);
    m->alpha = (s32)(alpha * 128.0f);
    if (m->alpha < 0x7F) {
        m->flags |= 8;
    }
    v = m->pvars;
    *(vu0_q *)v = *(vu0_q *)src;
    v->f14 = f1;
    v->f18 = D_L33_001DD814;
    v->owner = owner;
    v->f20 = f2;
    v->f24 = -1;
    v->f28 = f3;
    v->f3C = -1;
    m->f98 = 0;
    func_L01_00441FB8(m, 1, -1);
    if (D_L33_001DD810 == 0) {
        func_L03_0034A658(D_L33_001E1890.obj, D_L33_001DD838, D_L33_001DD83C, D_L33_001DD84C, D_L33_001DD850, (void *)func_L31_003AA4A8);
        func_L03_0034A658(D_L33_001E18B0.obj, D_L33_001DD868, D_L33_001DD86C, D_L33_001DD87C, D_L33_001DD880, (void *)func_L33_0034EFE0);
        D_L33_001DD810 = 1;
        D_L33_001E18B0.val = D_L33_001DD864;
    }
    if (flag) {
        func_L33_0034EDB8((u8 *)m, 0.5f, -0.00555555569f, 3, 5, 0x174B, 0.4f, 0.3f, 0.7f);
        func_L01_00441FB8(m, 2, -1);
    } else {
        if (snd) {
            func_0039FE80(0, 0, m);
        }
        func_L01_00441FB8(m, 1, -1);
    }
    return m;
}
/* localdecomp:end func_L33_0034F2C8 */
