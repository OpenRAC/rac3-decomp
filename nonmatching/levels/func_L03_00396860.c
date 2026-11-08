/* near miss (level 3, Starship Phoenix): 157 differences (attempt interrupted by an API limit; eight variants measured at 157-160): the jump-table switch is written but far from retail in register allocation and scheduling; no variant came close, so it needs a fresh look */
#include "common.h"

/* localdecomp:start func_L03_00396860 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00396860;
typedef struct { s32 n; u8 pad[0xC]; V4_00396860 e[1]; } T_00396860;
typedef struct {
    u8 pad0[0xB4]; u8 *i_b4;
    u8 pad1[0x120 - 0xB8]; V4_00396860 v120; V4_00396860 v130;
    s32 idx; u8 pad144[4]; s32 idx148; s32 i14C; u8 pad150[8]; s32 idx158; s16 s15C; s16 s15E;
    u8 pad160[0x174 - 0x160]; u8 *p174; u8 b178; u8 b179; s16 s17A;
} S_00396860;
typedef struct {
    u8 pad0[0x10]; f32 x; f32 y; u8 pad18[8]; u8 st; u8 pad21[0x10]; u8 b31; u8 pad32[2]; u16 fl;
    u8 pad36[0xC]; u8 t42; u8 t43; u8 pad44[0x24]; S_00396860 *p; u8 pad6C[0x54];
    V4_00396860 vC0; u8 padD0[0x28]; f32 fF8;
} A_00396860;
typedef struct { u8 pad0[0x20]; u8 st; u8 pad21[0x10]; u8 b31; u8 pad32[2]; u16 fl; u8 pad36[0x32]; S_00396860 *p; u8 pad6C[0x100-0x6C]; } E_00396860;
extern E_00396860 *D_L03_001DF99C_00396860;
extern u8 *D_001DF99C_00396860_sda;
__asm__(".extern D_001DF99C_00396860_sda, 4");
extern s32 D_001D6694_sda;
__asm__(".extern D_001D6694_sda, 4");
extern T_00396860 *D_L03_0021D8C0[];
extern void func_L03_00396E00();
extern s32 func_L01_004BA800();
extern void func_L03_00396FF0();
extern s32 func_L01_0045A748();
extern s32 func_L03_00397260();
extern s32 func_L01_00446720();
extern void func_L03_00397138();
extern f32 func_L03_003971B0(void *);
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0045AA10(void *, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_003C3A10();
extern void func_L01_0045A9F0();
extern void func_L01_004450F0();
extern s32 func_0038CB00();
void func_L03_00396860(A_00396860 *a) {
    S_00396860 *s;
    s32 n;
    s32 fl;
    s32 v;
    T_00396860 *t;
    if (a->st == 0) func_L03_00396E00();
    if (a != 0 && a->st != 0xFE && a->st != 0xFD) {
        s = a->p;
        if (D_001D6694_sda == 2) {
            a->b31 = 0;
            a->fl |= 1;
            D_L03_001DF99C_00396860[s->idx].fl |= 1;
            D_L03_001DF99C_00396860[s->idx].b31 = 0;
            return;
        }
        if (func_L01_004BA800() == 0) {
            a->b31 = 1;
            a->fl &= ~1;
            D_L03_001DF99C_00396860[s->idx].fl &= ~1;
            D_L03_001DF99C_00396860[s->idx].b31 = 1;
        }
        if (a->fl & 2) return;
        func_L03_00396FF0(a);
        switch (a->st) {
        case 1:
            break;
        case 2:
            fl = func_L01_0045A748(a, &s->v120);
            func_L03_00397260(a);
            if (s->i_b4 != 0
                && (s->idx148 == -1 || s->i_b4 != D_001DF99C_00396860_sda + (s->idx148 << 8))
                && (s->idx158 == -1 || s->i_b4 != D_001DF99C_00396860_sda + (s->idx158 << 8))
                && func_L01_00446720() == 0) {
                s->p174 = s->i_b4;
                func_L03_00397138(a, 6, 0, 10);
                func_L01_004450F0(a, 5, -1);
                return;
            }
            if (fl & 0x80) {
                t = D_L03_0021D8C0[s->i14C];
                if ((s->s15C += s->s15E) >= t->n) {
                    s->s15E = -1;
                    s->s15C = (u16)t->n - 2;
                }
                if (s->s15C < 0) {
                    s->s15E = 1;
                    s->s15C = 1;
                }
                s->v120 = t->e[s->s15C];
                s->v130 = a->vC0;
                if (func_L03_003971B0(a) < 0.0f) {
                    func_L01_004450F0(a, 3, -1);
                    return;
                }
            }
            break;
        case 5:
            if (func_L01_0040E570(s->p174 + 0x10, &a->x) > 16.0f || func_L03_00397260(a) != 0) {
                func_L03_00397138(a, 2, 0, 8);
                func_L01_004450F0(a, 2, -1);
                return;
            }
            break;
        case 3:
            if (a->t42 == 2) {
                f32 f = func_0038D160(s->v120.x - a->x, s->v120.y - a->y);
                func_L01_0045AA10(a, f);
                if (func_0038DBA0(f, a->fF8) < 0.08726646f && a->t43 != 0) func_003C3A10(a, 0, 0, 7);
            } else {
                func_L01_0045A9F0(a);
            }
            if (func_L03_003971B0(a) >= 0.0f) {
                v = s->b179 != 0 ? 1 : -1;
                if (s->s15E != v) {
                    s->s17A = 0x2A;
                    func_L01_004450F0(a, 4, -1);
                    return;
                }
            } else {
                E_00396860 *e = D_L03_001DF99C_00396860 + s->idx148;
                if (e->st != 3) return;
                v = s->s15C < e->p->s15C ? 1 : -1;
                if (v != s->s15E) {
                    s->s15E = v;
                    t = D_L03_0021D8C0[s->i14C];
                    if ((s->s15C += v) >= t->n) {
                        s->s15E = -1;
                        s->s15C = (u16)t->n - 2;
                    }
                    if (s->s15C < 0) {
                        s->s15E = 1;
                        s->s15C = 1;
                    }
                    s->v120 = t->e[s->s15C];
                }
            }
            if (a->t43 != 2) func_003C3A10(a, 2, 0, 7);
            func_L01_004450F0(a, 2, -1);
            break;
        case 4:
            if (a->t42 == 2) {
                f32 f = func_0038D160(s->v120.x - a->x, s->v120.y - a->y);
                func_L01_0045AA10(a, f);
                if (func_0038DBA0(f, a->fF8) < 0.08726646f && a->t43 != 0) func_003C3A10(a, 0, 0, 7);
            } else {
                func_L01_0045A9F0(a);
            }
            if (func_0038CB00(&s->s17A) != 0) {
                if (a->t43 != 2) func_003C3A10(a, 2, 0, 7);
                func_L01_004450F0(a, 2, -1);
            }
            break;
        }
    }
}
/* localdecomp:end func_L03_00396860 */
