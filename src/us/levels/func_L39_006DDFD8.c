#include "common.h"

/* NTSC-U counterpart of func_L39_006E0B38 (src/levels/39_multiplayer_menu/L39_006E0730.c) */
extern u8 D_001A5E50[];
extern void *D_001E1FD0_sda;
extern s32 func_L39_006D46C0(s32, s32, s32, s32 *);
extern void func_L39_006D46A0(s32, s32, s32 *);

/* localdecomp:start func_L39_006DDFD8 */
typedef struct {
    char _p0[0xC];
    s32 fC;
    char _p10[0x88 - 0x10];
    f32 f88[3];
    f32 f94;
    f32 f98[3];
    f32 fA4;
    char _pA8[0x170 - 0xA8];
    s32 f170;
} S_006E0B38;
typedef struct {
    char _p0[0x30];
    s32 *f30;
    char _p34[0x44 - 0x34];
    s32 f44;
} G_006E0B38;

s32 func_00197640(s32);
void func_001967F0(f32 *, s32);
f32 func_L39_006DE498(s32, f32 *);
void func_L39_006DCC00(s32 *, s32, f32);
void func_L39_006DE5A8(void);
void func_L39_006DC298(void);
extern s32 D_L39_001FE174 __attribute__((section(".data")));
extern f32 D_001A6BD8 __attribute__((section(".data")));
typedef void (*F_006E0B38)(f32 *, f32 *, s32, s32, s32, s32, s32);
extern F_006E0B38 D_001DE958_sda[2];

void func_L39_006DDFD8(void) {
    s32 buf[100];
    s32 total;
    s32 num;
    s32 key;
    s32 out;
    f32 a;
    f32 b;
    S_006E0B38 *p;
    G_006E0B38 *g;
    s32 n;
    s32 idx;
    s32 e;

    p = (S_006E0B38 *)D_001A5E50;
    n = p->fC;
    total = 0;
    num = 0;
    key = -1;
    out = -1;

    idx = func_00197640(D_L39_001FE174);
    if (p->f170 != 0) {
        return;
    }
    func_L39_006DD5F0(&total, &num, &key, &out);
    if (func_L39_006DD6C0(total, num, n) == 0) {
        return;
    }
    g = D_001E1FD0_sda;
    e = g->f44;
    if (func_L39_006D46C0(e, *g->f30, 0, buf) == 0) {
        return;
    }
    func_L39_006DC298();
    D_001DE958_sda[idx](&a, &b, total, num, key, out, idx);
    p->f88[idx] = a;
    p->f98[idx] = b;
    p->f94 = func_L39_006DE498(3, p->f88);
    p->fA4 = func_L39_006DE498(3, p->f98);
    func_L39_006DCC00(buf, key, a);
    func_001967F0(p->f88, 1);
    ((s32 (*)(s32, s32, s32 *))func_L39_006D46A0)(e, 0, buf);
    if (D_001A6BD8 > 0.0f) {
        func_L39_006DE5A8();
    }
}
/* localdecomp:end func_L39_006DDFD8 */
