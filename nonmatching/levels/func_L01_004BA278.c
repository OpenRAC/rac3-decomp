/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_004B66E0, the NTSC-U twin of func_L01_004BA278, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_004BA278.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_004BA278 (src/levels/shared/L01_004BA278.c) */
/* localdecomp:start func_L01_004B66E0 */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

typedef struct Ent_004B66E0 {
    u8 pad0[0xC];
    f32 fC;
    u8 pad10[0x24];
    u16 h34;
    u8 pad36[0xA];
    u8 b40;
    u8 b41;
    u8 pad42[2];
    f32 f44;
    u8 pad48[0x19];
    u8 b61;
    u8 pad62;
    u8 b63;
    u8 pad64[4];
    u8 *p68;
    u8 pad6C[3];
    u8 b6F;
    u8 pad70[0x3A];
    s16 hAA;
    u8 padAC[8];
    s16 hB4;
    u8 padB6[0x3A];
} Ent_004B66E0;

typedef struct S_004B66E0 {
    u8 pad0[0x34];
    s32 w34;
    s32 w38;
    s32 w3C;
    s16 h40;
    u8 pad42[2];
    s16 h44;
    u8 pad46[2];
    s16 h48;
    u8 pad4A[0x60 - 0x4A];
    s8 b60;
    u8 pad61[0x1A0 - 0x61];
    Ent_004B66E0 *ents[8];
} S_004B66E0;

extern S_004B66E0 D_L01_001E6E00;
extern u8 D_L01_001EA840[];
extern f32 D_L01_001DF9D0;
extern f32 D_001DF9D0_sda;
extern u32 D_001D4D40;
extern u32 D_001D4D40_sda;
extern u8 *D_001D52FC_sda;
extern s32 D_00143950;
extern s16 D_001CCFD4;
__asm__(".extern D_L01_001DF9D0, 16");
__asm__(".extern D_001DF9D0_sda, 4");
__asm__(".extern D_001D4D40, 16");
__asm__(".extern D_001D4D40_sda, 4");
__asm__(".extern D_001D52FC_sda, 4");
__asm__(".extern D_00143950, 16");
__asm__(".extern D_001CCFD4, 16");
extern void func_0038E410(void *);
extern s32 func_0038E440(void *);
extern void func_0039BF98(s32, s32);
extern void func_003DFFD0(void);
extern void func_L01_00420CD8(void);
extern void func_003C7AE8(void);
extern void func_L01_004A76F0(void);
extern void func_L01_004DE348(void);
extern void func_003C7DE0(void);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_0039C710(void);
extern void func_0039D6C8(s32);
extern void func_00395648(void);
extern void func_L01_004296B0(s32);
extern s32 func_003E0190(void);
extern void func_003BD490(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_003C26C8(void *);
extern f32 func_003887C8(void *, void *);
extern void func_003886C0(void *, void *, void *, f32);
extern void func_L01_00444188(void *);
extern void func_L01_0050EA58(void *, s32);
extern void func_L01_004DEBC0(void *);
extern void func_L01_004214C0(void);
extern void func_0039EE68(void);
extern void func_003CB5B0(void);
extern void func_L01_00437AB8(void);
extern void func_003E0068(void);

void func_L01_004B66E0(void) {
    s32 flagA;
    s32 flagB;
    s32 v;
    s32 i;
    s32 r;
    Ent_004B66E0 *e;
    u8 *tbl;
    f32 f20;
    f32 f21;
    u8 L[0x20] __attribute__((aligned(16)));

    if (D_L01_001E6E00.b60 == 0) {
        if (D_L01_001E6E00.h40 == 0) {
            func_0038E410(D_L01_001EA840);
            D_L01_001E6E00.b60 = 1;
            func_0039BF98(0, 0);
            return;
        }
        if (D_L01_001E6E00.h40 < D_L01_001E6E00.w34 + 0xF) {
            D_L01_001DF9D0 = (f32)(D_L01_001E6E00.w34 - (D_L01_001E6E00.h40 - 0xF)) * 0.06666667f;
        }
        func_003DFFD0();
        func_L01_00420CD8();
        func_003C7AE8();
        func_L01_004A76F0();
        func_L01_004DE348();
        func_003C7DE0();
        D_L01_001E6E00.w34 = D_L01_001E6E00.w34 + 1;
        D_L01_001E6E00.w38 = D_L01_001E6E00.w38 + 1;
        if (D_L01_001E6E00.w34 < 0x1E) {
            func_003BEBF8(&D_L01_001DF9D0, 0.0f, 0.04f);
            if (1.0f < D_L01_001DF9D0) {
                D_001DF9D0_sda = 1.0f;
            }
        }
        if (!(D_L01_001E6E00.w34 < D_L01_001E6E00.h48)) {
            func_0039C710();
        }
        flagA = 0;
        flagB = !(D_L01_001E6E00.w34 < D_L01_001E6E00.h40);
        if (!(D_L01_001E6E00.w34 < 0x12)) {
            if (D_L01_001DF9D0 == 0.0f) {
                v = D_001D4D40_sda;
                if (!(v & 0x80)) {
                    v = v & ~0xC0;
                    if (v != 2) {
                        if (v == 0 && (*(s32 *)(D_001D52FC_sda + 0x1A4) & 0x9FF) != 0) {
                            flagA = 1;
                        } else {
                            flagA = (*(s32 *)(D_001D52FC_sda + 0x1A4) & 0x800) != 0;
                        }
                    }
                }
            }
        }
        if (flagA != 0) {
            D_001D4D40 = D_001D4D40_sda & ~0x80;
            D_L01_001EA840[0x64] = 1;
            func_0038E410(D_L01_001EA840);
            D_L01_001E6E00.b60 = 1;
            func_0039BF98(0, 0);
        } else if (flagB != 0) {
            D_L01_001E6E00.b60 = 1;
            D_001D4D40_sda = D_001D4D40_sda & ~0x80;
            if (func_0038E440(D_L01_001EA840) == 0) {
                func_0039BF98(0, 0);
            }
        } else {
            if (!(D_L01_001E6E00.w38 < (D_00143950 ? 0x50 : 0x60))) {
                D_L01_001E6E00.w3C = D_L01_001E6E00.w3C + 1;
                if (D_001CCFD4 != 0) {
                    func_0039D6C8(1);
                }
                func_00395648();
                func_L01_004296B0(D_L01_001E6E00.w3C + 1);
            }
            r = func_003E0190();
            i = 0;
            if (D_L01_001E6E00.h44 > 0) {
                do {
                    e = D_L01_001E6E00.ents[i];
                    v = D_L01_001E6E00.w38 >> 1;
                    e->b41 = v + 1;
                    e->b40 = v;
                    func_003BD490(e);
                    e->f44 = (f32)(D_L01_001E6E00.w38 & 1) * 0.5f;
                    if (r != 0) {
                        if ((D_L01_001E6E00.w38 & 1) != 0 && e->hB4 == 0) {
                            e->f44 = 1.0f;
                        }
                    }
                    tbl = e->p68;
                    func_003886E8(L, tbl + (e->b40 << 4), 1.0f - e->f44);
                    func_003886E8(L + 0x10, tbl + (e->b41 << 4), e->f44);
                    vec_add_ab((u8 *)e + 0x10, L, L + 0x10);
                    e->b61 = 0xFF;
                    func_003C26C8(e);
                    if (e->b63 != 0) {
                        if (D_L01_001E6E00.w3C == 0) {
                            *(u128_t *)((u8 *)e + 0xF0) = *(u128_t *)e;
                            e->h34 = e->h34 | 0x100;
                        } else if (D_L01_001E6E00.w38 < 0x10) {
                            f21 = func_003887C8(e, (u8 *)e + 0xF0);
                            if (f21 < 10.0f) {
                                f20 = (f32)D_L01_001E6E00.w38 * 0.0625f;
                                func_003886C0(e, (u8 *)e + 0xF0, e, f20);
                                e->fC = e->fC + f21 * (1.0f - f20);
                            }
                        } else {
                            *(u128_t *)((u8 *)e + 0xF0) = *(u128_t *)e;
                            e->h34 = e->h34 | 0x100;
                        }
                    }
                    if (e->b6F != 0) {
                        func_L01_00444188(e);
                    }
                    if (e->hAA == 0 || e->hAA == 0xF6B) {
                        func_L01_0050EA58(e, 0);
                    }
                    if (e->hAA == 10 || e->hAA == 0x19C9 || e->hAA == 0x1159 || e->hAA == 0x1F6B || e->hAA == 0x57 || e->hAA == 0x259 || e->hAA == 0x1F6B) {
                        func_L01_004DEBC0(e);
                    }
                    i++;
                } while (i < D_L01_001E6E00.h44);
            }
        }
        func_L01_004214C0();
        func_0039EE68();
        func_003CB5B0();
        func_L01_00437AB8();
        func_003E0068();
    }
}
/* localdecomp:end func_L01_004B66E0 */
