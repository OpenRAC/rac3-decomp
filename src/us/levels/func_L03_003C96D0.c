#include "common.h"

/* NTSC-U counterpart of func_L03_003CB5E0 (src/levels/03_starship_phoenix/L03_003CB5E0.c) */
/* localdecomp:start func_L03_003C96D0 */
typedef struct {
    u8 pad0[0x40];
    s32 f40;
    s32 f44;
    s32 f48;
    s32 p4C;
    s32 arr50[6];
    s32 arr68[6];
    s32 f80;
    s32 f84;
    u8 pad88[0xC];
    s32 f94;
} S_003CB5E0;
extern u8 D_001426E0[];
extern u8 D_001A4C60[];
extern s32 D_L03_001DE898;
__asm__(".extern D_L03_001DE898, 16");
extern s32 D_L03_001DEF68;
__asm__(".extern D_L03_001DEF68, 16");
extern s32 D_L03_001DEF30;
__asm__(".extern D_L03_001DEF30, 16");
extern s32 D_L03_001DEFA0;
__asm__(".extern D_L03_001DEFA0, 16");
extern s32 func_L01_004B6C68(void);
extern void func_L03_003C9E10(void *a0);
extern void func_L03_003C9AF8(void *a0);
extern s32 func_0037E0F0(void *, s32, s32);
extern s32 func_00388398(void *);
extern s32 func_0037E208(s32, s32);
extern s32 func_L03_003C9C28(s32 a0, s32 a1);
extern f32 func_00388960(f32);
extern f32 func_L01_00442070(f32);
extern void func_L03_003C9CE8(void *a0, f32 t);
extern void func_L03_003C9C98(void *a0);

void func_L03_003C96D0(void *a0) {
    S_003CB5E0 *s = *(S_003CB5E0 **)((u8 *)a0 + 0x68);
    s32 i;
    s32 n;
    s32 m;
    s32 st;
    if (func_L01_004B6C68() != 0) {
        if (s->f48 != 0) {
            func_L03_003C9E10(a0);
        }
        return;
    }
    func_L03_003C9AF8(a0);
    switch (*((u8 *)a0 + 0x20)) {
    case 0:
    case 1:
    case 2:
        break;
    case 3:
        if (func_0037E0F0(D_001A4C60, s->f44, 0) == 0 && func_00388398(&s->f40) != 0) {
            if (s->f94 != 0) {
                m = D_L03_001DE898;
                st = D_001426E0[0x77];
                do {
                    n = (D_001426E0[0x77] + 1) % 14;
                    D_001426E0[0x77] = n;
                    if (n == st) return;
                } while ((((m >> (&D_L03_001DEF68)[D_001426E0[0x77]]) ^ 1) & 1) != 0);
                s->f40 = func_0037E208(0xE10, 0x1518);
                s->f94 = 0;
                if ((&D_L03_001DEF30)[D_001426E0[0x77]] == 4) {
                    s->f40 = 0x140;
                } else if ((&D_L03_001DEF30)[D_001426E0[0x77]] == 7) {
                    s->f48 = 0xC8;
                    s->f40 = 0x28;
                }
            }
            if (func_L03_003C9C28((s32)a0, *(s32 *)((s32)s + ((&D_L03_001DEF30)[D_001426E0[0x77]] << 2))) != 0) {
                s->f94 = 1;
            }
        }
        if (func_00388398(&s->f48) == 0) {
            func_L03_003C9CE8(a0, func_L01_00442070((1.0f - func_00388960((f32)(s->f48 % 40) * 6.2831855f / 40.0f)) * 0.5f));
        }
        if (s->f48 == 1) {
            func_L03_003C9E10(a0);
        }
        break;
    case 4:
        for (i = 0; i < 6; i++) {
            if ((s->f84 >> i) & 1) {
                if (((s->f80 >> i) ^ 1) & 1) {
                    if (func_0037E0F0(D_001A4C60, s->arr68[i], 0) != 0) {
                        if (func_L03_003C9C28((s32)a0, s->arr50[(&D_L03_001DEFA0)[i]]) != 0) {
                            s->f80 |= 1 << i;
                        }
                    }
                }
            }
        }
        break;
    }
    func_L03_003C9C98(a0);
}
/* localdecomp:end func_L03_003C96D0 */
