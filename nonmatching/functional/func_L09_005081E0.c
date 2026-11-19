/* functional: medium. Transcribed block by block from the PAL asm (no draft existed); compiles with -mvu0-use-vf0-vf2 and its 31 callee addresses appear in retail order. Byte diff is large (619 words) as expected for a 2.7 KB first transcription. func_0012FE98 is the second entry (vector normalise) of the hand-written func_0012FE78. All H+off fields are D_001A4BE0 hero/aim-state offsets, unnamed. Unrun-block risk: delay-slot likely branches were re-read by hand. */
/* localdecomp:start func_L09_005081E0 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
extern char D_001A4BE0[];
extern char D_001E98C0[];
extern char D_001E98E0[];
extern char D_001E9900[];
extern s32 D_001D545C;
extern s32 D_001D673C;
extern s32 func_L01_004E9308(void);
extern void func_L01_004EF6F0(void *, void *, s32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern u8 func_L01_003FE908(void);
extern s16 func_003D5630(void);
extern f32 func_003C3EC8(void *, void *);
extern s32 func_003C4B50(void *);
extern s32 func_00382348(void *);
extern u8 *func_003C4D58(void *);
extern f32 func_L01_00451580(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0012FE98(void *, void *);
extern f32 func_L01_00511848(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CE68(void *, void *);
extern s32 func_L01_00500240(s32, s32);
extern void func_003C4138(void *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004F40A8(void *, void *);
extern void func_L01_00511038(void *, s32, f32, f32, f32);

void func_L09_005081E0(void) {
    char *H = D_001A4BE0;
    char *G = D_001E98C0;
    f32 v0[4];
    f32 v10[4];
    f32 v20[4];
    f32 v30[4];
    f32 v40[4];
    f32 v50[4];
    f32 v60[4];
    f32 s;
    f32 x;
    f32 y;
    s32 st;
    s32 g;
    s32 old;
    s32 ang;
    s32 i;
    s32 skip;
    u8 *obj;
    f32 *pa;
    f32 *pb;
    f32 *pc;
    f32 lim;
    f32 a;

    *(s32 *)(H + 0x2F0) = 0;
    *(s32 *)(H + 0x2F4) = 0;
    *(s32 *)(H + 0x2F8) = 0;
    *(s32 *)(H + 0x2FC) = 0;
    *(u16 *)(H + 0x36E) += 1;
    *(u16 *)(H + 0x36C) += 1;
    *(f32 *)(H + 0x2C8) = 1.0f;
    *(f32 *)(H + 0x33C) = 32.0f;
    *(s32 *)(H + 0x2C0) = 0;
    *(s32 *)(H + 0x2C4) = 0;
    *(s32 *)(H + 0x340) = 0;
    *(s32 *)(H + 0x338) = 0;
    *(s16 *)(H + 0x36A) = 0;
    old = *(s32 *)(H + 0x358);
    *(s32 *)(H + 0x35C) = 0;
    if (old != 0) {
        *(s32 *)(H + 0x358) = old + 1;
    }
    s = *(f32 *)(H + 0x284) * 2.2f;
    if (*(s32 *)(H + 0x25CC) == 2) {
        s = *(f32 *)(H + 0x284) * 2.9f;
    }
    if (func_L01_004E9308() != 0) {
        s = 0.0f;
    }
    func_L01_004EF6F0(v10, v0, 1, s, -48.0f);
    if (func_003D3CB0(v10, v0, 2, *(s32 *)(H + 0x25C0), 0) == 0) {
        goto tail;
    }
    *(u8 *)(H + 0x147F) = func_L01_003FE908();
    if (*(s32 *)(G + 0x18) != 0) {
        g = D_001D545C;
        *(u8 *)(H + 0x147F) = 0;
        if (g == 2) {
            if (*(s16 *)(*(u8 **)(G + 0x18) + 0xAA) == 0x18C6) {
                *(u8 *)(H + 0x147F) = 2;
            }
            if (*(s16 *)(*(u8 **)(G + 0x18) + 0xAA) == 0x18AF) {
                *(u8 *)(H + 0x147F) = 2;
            }
        }
        g = D_001D545C;
        if (g == 5) {
            if (*(s16 *)(*(u8 **)(G + 0x18) + 0xAA) == 0x1607) {
                *(u8 *)(H + 0x147F) = 2;
            }
            if (*(s16 *)(*(u8 **)(G + 0x18) + 0xAA) == 0x1681) {
                *(u8 *)(H + 0x147F) = 2;
            }
            if (*(s16 *)(*(u8 **)(G + 0x18) + 0xAA) == 0x15F7) {
                *(u8 *)(H + 0x147F) = 2;
            }
            if (*(s16 *)(*(u8 **)(G + 0x18) + 0xAA) == 0x16BB) {
                *(u8 *)(H + 0x147F) = 3;
            }
            g = D_001D545C;
        }
        if (g == 8) {
            if (*(s16 *)(*(u8 **)(G + 0x18) + 0xAA) == 0x1A44) {
                *(u8 *)(H + 0x147F) = 2;
            }
            g = D_001D545C;
        }
        if (g == 10) {
            if (*(s16 *)(*(u8 **)(G + 0x18) + 0xAA) == 0x1645) {
                *(u8 *)(H + 0x147F) = 3;
            }
            if (*(s16 *)(*(u8 **)(G + 0x18) + 0xAA) == 0x162E) {
                *(u8 *)(H + 0x147F) = 1;
            }
            g = D_001D545C;
        }
        if (g == 0x15) {
            if (*(s16 *)(*(u8 **)(G + 0x18) + 0xAA) == 0x1BA9) {
                *(u8 *)(H + 0x147F) = 3;
            }
        }
    }
    st = func_003D5630();
    *(s16 *)(H + 0x1470) = st;
    if (st == 0) {
        x = func_003C3EC8(D_001E98E0, H + 0x2D0);
        *(f32 *)(H + 0x350) = x;
        if (*(f32 *)(H + 0x88) < x) {
            if (*(s32 *)(H + 0x358) <= 0) {
                *(s32 *)(H + 0x358) = 1;
            }
        }
        if (func_003D3CB0(v10, v0, 0x24, *(s32 *)(H + 0x25C0), 0) == 0) {
            goto tail;
        }
        *(u8 *)(H + 0x147F) = func_L01_003FE908();
    }
    st = *(s16 *)(H + 0x1470);
    if (st == 0xD) {
        x = *(f32 *)(G + 0x28);
        v0[2] = x - 0.01f;
        *(f32 *)(H + 0x350) = x;
        if (func_003D3CB0(v10, v0, 4, *(s32 *)(H + 0x25C0), 0) == 0) {
            goto tail;
        }
        st = *(s16 *)(H + 0x1470);
    }
    if (st == 3) {
        x = *(f32 *)(G + 0x28);
        v0[2] = x - 0.01f;
        *(f32 *)(H + 0x354) = x;
        if (func_003D3CB0(v10, v0, 4, *(s32 *)(H + 0x25C0), 0) == 0) {
            goto tail;
        }
        st = *(s16 *)(H + 0x1470);
    }
    if (st == 0xB) {
        *(f32 *)(H + 0x354) = *(f32 *)(G + 0x28);
        goto tail;
    }
    if (*(s32 *)(G + 0x18) != 0) {
        if (func_003C4B50(*(void **)(G + 0x18)) != 0) {
            *(s16 *)(H + 0x36A) = 1;
        }
        if (func_00382348(*(void **)(G + 0x18)) != 0) {
            if (*(u16 *)(G + 0x1E) & 8) {
                *(s16 *)(H + 0x36A) = 1;
            }
        }
        obj = func_003C4D58(*(void **)(G + 0x18));
        if (obj != 0) {
            if (*(s32 *)(obj + 0x3C) & 8) {
                *(s16 *)(H + 0x36A) = 1;
            }
        }
    }
    if (*(s32 *)(G + 0x1C) > 0) {
        *(u128_t *)(H + 0x2F0) = *(u128_t *)(G + 0x20);
        *(f32 *)(H + 0x338) = *(f32 *)(G + 0x28);
        if (D_001D673C != 0) {
            *(f32 *)(H + 0x338) = func_L01_00451580(G + 0x20);
        }
        *(f32 *)(H + 0x33C) = func_0038CF00(H + 0x80, H + 0x2F0);
        *(s32 *)(H + 0x35C) = *(s32 *)(G + 0x18);
        func_0012FE98(H + 0x2C0, G + 0x40);
        x = func_L01_00511848(G + 0x40);
        *(f32 *)(H + 0x340) = x;
        *(f32 *)(H + 0x34C) = func_0038D160(*(f32 *)(G + 0x40), *(f32 *)(G + 0x44));
        vec_sub_ab(v20, H + 0x2F0, H + 0x80);
        if (0.0f < func_0038CE68(v20, H + 0x2C0)) {
            *(f32 *)(H + 0x33C) = -*(f32 *)(H + 0x33C);
        }
        if (*(f32 *)(H + 0x33C) < 0.02f) {
            *(s16 *)(H + 0x36C) = 0;
            if (*(f32 *)(H + 0x340) <= 0.8726646f || *(u8 *)(H + 0x25F4) != 0) {
                *(s16 *)(H + 0x36E) = 0;
                *(s32 *)(H + 0xBF0) = *(s32 *)(G + 0x18);
            } else {
                goto after;
            }
        }
    }
tail:
after:
    if (*(f32 *)(H + 0x350) < *(f32 *)(H + 0x88)) {
        *(s32 *)(H + 0x358) = 0;
    }
    if (*(s16 *)(H + 0x36E) == 0) {
        *(s32 *)(H + 0x360) = *(s32 *)(H + 0x360) + 1;
        *(u128_t *)(H + 0x300) = *(u128_t *)(H + 0x2F0);
        if (func_L01_00500240(0x38, 0x64) == 0) {
            *(s32 *)(H + 0x1B70) = 0;
        }
    } else {
        *(s32 *)(H + 0x360) = 0;
    }
    *(s32 *)(H + 0x2E0) = 0;
    *(s32 *)(H + 0x2E4) = 0;
    *(s32 *)(H + 0x2E8) = 0;
    *(s32 *)(H + 0x2EC) = 0;
    switch (*(u8 *)(H + 0x25F4)) {
    case 0:
        *(f32 *)(H + 0x2E8) = -1.0f;
        break;
    case 1:
        if (*(f32 *)(H + 0x31C) != 0.0f) {
            func_003C4138(H + 0x31C, 0.0f, 1.0f);
            *(u128_t *)(H + 0x2E0) = *(u128_t *)(H + 0x310);
            func_0038CE20(H + 0x2C0, H + 0x2E0, -1.0f);
        } else {
            *(u128_t *)(H + 0x2E0) = *(u128_t *)(H + 0x2C0);
            func_0038CE20(H + 0x2E0, H + 0x2E0, -1.0f);
        }
        break;
    case 2:
        y = -1.0f;
        if (0.0f < *(f32 *)(H + 0xBC)) {
            y = 1.0f;
        }
        vec_sub_ab(H + 0x2E0, H + 0xB0, H + 0x80);
        func_0038CF68(H + 0x2E0, H + 0x2E0, y);
        break;
    }
    *(s32 *)(H + 0x344) = 0;
    *(s32 *)(H + 0x348) = 0;
    *(s32 *)(H + 0x330) = 0;
    *(s32 *)(H + 0x334) = 0;
    *(s32 *)(H + 0x328) = 0;
    *(s32 *)(H + 0x32C) = 0;
    *(s32 *)(H + 0x320) = 0;
    *(s32 *)(H + 0x324) = 0;
    if (!(*(f32 *)(H + 0x33C) < 0.25f)) {
        return;
    }
    st = *(s32 *)(H + 0x25CC);
    if (st == 0 || st == 0xC || st == 9 || st == 7) {
        /* fall to the shared body */
    } else if (st == 4) {
        if (*(u8 *)(H + 0x46C) == 0) {
            return;
        }
    } else if (st != 1) {
        return;
    }
    func_L01_004F40A8(H + 0x2C0, v20);
    if (-0.7853982f < v20[1]) {
        if (v20[1] < 0.7853982f) {
            *(f32 *)(H + 0x344) = v20[1];
        }
    }
    if (-0.7853982f < v20[0]) {
        if (v20[0] < 0.7853982f) {
            *(f32 *)(H + 0x348) = v20[0];
        }
    }
    pa = (f32 *)(H + 0x320);
    pb = (f32 *)(H + 0x328);
    pc = (f32 *)(H + 0x330);
    for (i = 0; i < 2; i++) {
        a = 1.5707964f;
        if (i == 1) {
            a = -a;
        }
        func_L01_00511038(v30, 1, 0.2f, a, 0.45f);
        func_L01_00511038(v40, 1, 0.2f, a, -0.45f);
        if (func_003D3CB0(v30, v40, 0x22, *(s32 *)(H + 0x25C0), 0) != 0) {
            if (D_001D673C != 0) {
                x = func_L01_00451580(D_001E98E0);
                *pa = x - func_L01_00451580(H + 0x2F0);
            } else {
                *pa = *(f32 *)(G + 0x28) - *(f32 *)(H + 0x338);
            }
            lim = *pa;
            if (0.4f < __builtin_fabsf(lim)) {
                *pa = 0.0f;
            }
            func_0012FE98(v60, D_001E9900);
            func_L01_004F40A8(v60, v50);
            if (-0.7853982f < v50[1]) {
                if (v50[1] < 0.7853982f) {
                    *pb = v50[1];
                }
            }
            if (-0.7853982f < v50[0]) {
                if (v50[0] < 0.7853982f) {
                    *pc = v50[0];
                }
            }
        } else {
            *(s32 *)pa = 0;
            *pb = *(f32 *)(H + 0x344);
            *pc = *(f32 *)(H + 0x348);
        }
        pa++;
        pb++;
        pc++;
    }
}
/* localdecomp:end func_L09_005081E0 */
