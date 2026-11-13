#include "common.h"

/* NTSC-U counterpart of func_L27_003A3098 (src/levels/27_aquatos_base/L27_003A1250.c): 250 -> 300; 226 -> 271 */
/* localdecomp:start func_L27_003A1820 */
typedef struct { u8 p0[8]; s32 f8; u8 pC[4]; s32 f10; s32 f14; s32 f18; s32 f1C; s32 f20; u8 p24[0x48]; s32 f6C; } S_3098_D;
typedef struct { u8 p0[0x68]; S_3098_D *f68; u8 p6C[0x29]; u8 b95; } S_3098_O;
typedef struct { u8 pad[0xAA]; s16 hAA; } S_3098_M;
typedef struct { u8 pad[0x2540]; S_3098_M *f2540; } S_3098_G;
typedef struct { u8 pad[0xD0]; u8 bD0; u8 padD1[0xB]; void *fDC; } S_3098_E;
typedef struct { u8 pad[0x34]; u16 h34; u8 pad36[0x42]; u32 f78; } S_3098_T;
extern S_3098_G D_001A4C60;
extern u8 D_001A30B0[];
extern u8 *D_L27_001DED1C_003A1820;
__asm__(".extern D_L27_001DED1C_003A1820, 16");
extern s16 *D_L27_0021B7E0_003A1820[];
extern s32 D_001DED58_sda_003A1820;
__asm__(".extern D_001DED58_sda_003A1820, 4");
extern s32 func_L01_00453210(void *, s32);
extern void func_0038CAD0(void *);
extern void func_L01_00402498(void *, void *);
extern void func_003A4F28(s32);
extern s32 func_L01_004A73F8(s32, s32, void *, s32);
extern void func_L27_003A1C20(void);

void func_L27_003A1820(S_3098_O *self) {
    S_3098_D *d = self->f68;
    s16 *q;
    u32 c;
    s32 flag;
    if (d->f6C != 0) {
        d->f18 = 1;
    } else if (self->b95 == 2) {
        d->f18 = 0;
    } else {
        s32 v = 0;
        if (func_L01_00453210(&D_001A4C60, d->f8) == 0) {
            v = D_001A4C60.f2540->hAA != 0x1A4E;
        }
        d->f18 = v;
    }
    if (d->f18 != 0 && d->f6C == 0) {
        func_0038CAD0(&d->f14);
        if (d->f14 <= 0) {
            d->f6C = 1;
        } else if (d->f14 >= 0x10F) {
            return;
        }
    } else {
        d->f14 = 0x12C;
    }
    if (d->f18 != 0) {
        flag = d->f1C == 0;
        c = 0x7F2020FF;
        func_L01_00402498(func_L27_003A1C20, self);
    } else {
        flag = d->f1C;
        c = 0x7F000040;
    }
    if (flag == 0) return;
    d->f1C = d->f18;
    if (d->f18 != 0) {
        if (d->f20 != -1) {
            S_3098_E *e = (S_3098_E *)(D_001A30B0 + (d->f20 << 7));
            if (e->fDC == (void *)self && e->bD0 != 0) func_003A4F28(d->f20);
        }
        d->f20 = -1;
        d->f20 = func_L01_004A73F8(0x10, 4, self, 0);
    } else {
        if (d->f20 != -1) {
            S_3098_E *e = (S_3098_E *)(D_001A30B0 + (d->f20 << 7));
            if (e->fDC == (void *)self && e->bD0 != 0) func_003A4F28(d->f20);
        }
        d->f20 = -1;
    }
    q = D_L27_0021B7E0_003A1820[d->f10];
    while ((d->f10 & 0xFF) != 0xFF && d->f10 <= D_001DED58_sda_003A1820 && q != 0 && (q[-1] >= 0 || q == D_L27_0021B7E0_003A1820[d->f10])) {
        S_3098_T *t = (S_3098_T *)(D_L27_001DED1C_003A1820 + ((*(u16 *)q & 0x7FFF) << 8));
        if (t == 0) break;
        t->h34 |= 0x10;
        t->f78 = c;
        q++;
    }
}
/* localdecomp:end func_L27_003A1820 */
