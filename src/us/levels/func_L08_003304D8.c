#include "common.h"

/* NTSC-U counterpart of func_L08_00330F68 (src/levels/08_aquatos/L08_00330F68.c) */
/* localdecomp:start func_L08_003304D8 */
/* func_L08_003304D8 (4364 bytes, level 08 only). Drafts by opus-d, finisher3 and r0; finished by b3.
   Needs "-mvu0-use-vf0-vf2 ... @ps2as" on this file and divs_nops "func_L08_003304D8 2 0".
   - Block-scoped hero pointers keep %hi(D_001A4BE0) in $fp (GCSE copy of the HIGH).
   - func_L01_00452F40 and func_L01_0050DAC0 take fewer arguments: retail leaves the compare's -1 / 0x66 in place.
   - D_L08_001DCE88 is a small-data array: D_L08_001DCE88[1..3] are symbol+offset loads that gcc counts as two
     instructions (kept out of delay slots), [0] is a $gp load in the jal slot.
   - The "moving" chain in the first block is an else-if chain (more refs, so moving gets $s5).
   - The second block re-tests the seat condition inside its then-arm (retail's doubled bc1f). */
#include "vu0.h"

extern u8 D_001A4BE0[];
extern u8 D_001A30B0[];
extern u8 D_001BBC40[];
extern s32 D_001D545C;
extern s32 D_00142C34[];
extern u8 D_00142BA0[];
extern u8 *D_L08_001DF21C_003304D8;
extern vu0_q *D_L08_0021D140[];
__asm__(".extern D_L08_001DCE98, 4");
__asm__(".extern D_L08_001DF300, 4");
extern f32 D_L08_001DCE98;
__asm__(".extern D_L08_001DCE88, 16");
extern s32 D_L08_001DCE88[] __attribute__((section(".sdata")));
extern u8 *D_L08_001DF300;

extern void func_L01_003EAB30(s32);
extern s32 func_L01_003EAB60(s32);
extern void func_L02_003C3A40(s32);
extern s32 func_00388398(void *);
extern f32 func_00388800(void *, void *);
extern void func_00388830(f32, void *, void *);
extern f32 func_00388978(f32);
extern f32 func_00389380(f32, f32);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_L01_0040D068(s32, s32);
extern void func_L08_0040FEF0(s32, s32, s32, s32);
extern u8 *func_003BCFB0(s32, s32);
extern void func_003C26C8(u8 *);
extern void func_L01_004405F4(u8 *);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_L01_00445758(f32, f32, f32, f32, void *, void *, s32);
extern void func_003BF838(void *, void *, void *, void *);
extern void func_L01_00452E70(u8 *, u8 *);
extern void func_L01_00452F40(u8 *, s32);
extern u8 *func_L01_00458650(u8 *);
extern void func_0039FB08(s32);
extern s32 func_0039FE80(s32, s32, u8 *);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L08_004D8D78(s32, s32);
extern void func_L01_0050DA68(void *, f32, s32);
extern s32 func_L01_0050DAC0(void);


static inline void func_L08_00330F68_prompt(u8 *a0, u8 *pv) {
    if ((*(s16 *)(pv + 0x9C)) == 0) {
        u8 *hero = D_001A4BE0;
        if ((*(s32 *)(hero + 0x25C4)) != 0x66) {
            u8 *pos = a0 + 0x10;
            func_L01_0050DA68(pos, func_00389380((*(f32 *)(a0 + 0xF8)), 1.5707964f), 1);
        } else if (func_L01_0050DAC0()) {
            (*(s16 *)(pv + 0x9C)) = 1;
        }
    } else {
        u8 *hero = D_001A4BE0;
        (*(s16 *)(hero + 0x212)) = 3;
        (*(s16 *)(hero + 0x1E0)) = 0x1E;
        if ((*(s32 *)(hero + 0x360)) == 0) {
            func_L08_004D8D78(0x74, 1);
        }
    }
}

static inline void func_L08_00330F68_ride(u8 *a0, u8 *pv, s32 hud) {
    u8 *snd;
    (*(s32 *)(pv + 0x74)) = 0;
    (*(f32 *)(pv + 0x84)) = (*(f32 *)(pv + 0x70)) * 0.01666666753590107f;
    if ((*(s32 *)(pv + 0x78)) != -1 && (*(s16 *)(a0 + 0xB2)) != 0xAD && (*(s16 *)(a0 + 0xB2)) != 0xAE) {
        if (hud) {
            u8 *hero = D_001A4BE0;
            (*(s16 *)(hero + 0x212)) = 3;
        }
        if ((*(s32 *)(pv + 0x80)) == -1 || (snd = (D_001A30B0 + (((*(s32 *)(pv + 0x80))) << 7)), *(u8 **)(snd + 0xDC) != a0) || snd[0xD0] == 0) {
            (*(s32 *)(pv + 0x80)) = func_0039FE80(0, 4, a0);
        }
        func_L01_00441FB8(a0, 2, -1);
        if ((*(s32 *)(pv + 0x88)) != -1) {
            (*(u8 * *)(pv + 0x90)) = D_L08_001DF300 + ((*(s32 *)(pv + 0x88)) << 7);
        } else {
            (*(u8 * *)(pv + 0x90)) = 0;
        }
        if ((*(f32 *)(a0 + 0x18)) < 425.0f) {
            (*(s32 *)(pv + 0x74)) = *(s32 *)D_L08_0021D140[(*(s32 *)(pv + 0x78))] - 1;
            func_L01_00441FB8(a0, 3, -1);
            if ((*(s32 *)(pv + 0x8C)) != -1) {
                (*(u8 * *)(pv + 0x90)) = D_L08_001DF300 + ((*(s32 *)(pv + 0x8C)) << 7);
            } else {
                (*(u8 * *)(pv + 0x90)) = 0;
            }
        }
    } else if ((*(s32 *)(pv + 0x78)) != 0 && (u16)(*(s16 *)(a0 + 0xB2)) - 0xAD < 2U) {
        if (hud) {
            u8 *hero = D_001A4BE0;
            (*(s16 *)(hero + 0x212)) = 3;
        }
        if ((*(s32 *)(pv + 0x80)) == -1 || (snd = (D_001A30B0 + (((*(s32 *)(pv + 0x80))) << 7)), *(u8 **)(snd + 0xDC) != a0) || snd[0xD0] == 0) {
            (*(s32 *)(pv + 0x80)) = func_0039FE80(0, 4, a0);
        }
        func_L01_00441FB8(a0, 2, -1);
        if ((*(s32 *)(pv + 0x88)) != -1) {
            (*(u8 * *)(pv + 0x90)) = D_L08_001DF300 + ((*(s32 *)(pv + 0x88)) << 7);
        } else {
            (*(u8 * *)(pv + 0x90)) = 0;
        }
        if ((*(f32 *)(a0 + 0x18)) > 425.0f) {
            (*(s32 *)(pv + 0x74)) = *(s32 *)D_L08_0021D140[(*(s32 *)(pv + 0x78))] - 1;
            func_L01_00441FB8(a0, 3, -1);
            if ((*(s32 *)(pv + 0x8C)) != -1) {
                (*(u8 * *)(pv + 0x90)) = D_L08_001DF300 + ((*(s32 *)(pv + 0x8C)) << 7);
            } else {
                (*(u8 * *)(pv + 0x90)) = 0;
            }
        }
    }
}

void func_L08_003304D8(u8 *a0) {
    vu0_v4 saved;
    vu0_v4 savedRot;
    vu0_v4 v;
    vu0_v4 v2;
    u8 *pv;
    u8 *hero;
    u8 *snd;
    vu0_q *path;
    u8 *t;
    u8 *o;
    u8 *t2;
    u8 *o2;
    s32 moving;
    s32 c;
    s32 a;
    f32 f;

    saved = (*(vu0_v4 *)(a0 + 0x10));
    pv = (*(u8 * *)(a0 + 0x68));
    savedRot = (*(vu0_v4 *)(a0 + 0xF0));
    switch ((*(u8 *)(a0 + 0x20))) {
    case 0:
        if ((*(s32 *)(pv + 0xA4)) != -1) {
            func_L02_003C3A40((*(s32 *)(pv + 0xA4)));
        }
        (*(s16 *)(a0 + 0x32)) = 0xFF;
        if ((*(f32 *)(D_001A4BE0 + 0x88)) < 425.0f && (*(s32 *)(pv + 0x78)) != -1 && (*(s16 *)(a0 + 0xB2)) != 0xAD && (*(s16 *)(a0 + 0xB2)) != 0xAE) {
            vu0_q *p0 = D_L08_0021D140[(*(s32 *)(pv + 0x78))];
            (*(vu0_q *)(a0 + 0x10)) = p0[*(s32 *)p0];
        }
        (*(u8 *)(a0 + 0x30)) = 0xFF;
        func_L01_00441FB8(a0, 1, -1);
        (*(u8 * *)(pv + 0x7C)) = func_003BCFB0(0x1A89, 0x80);
        func_L01_00452E70((*(u8 * *)(pv + 0x7C)), a0);
        *(f32 *)((*(u8 * *)(pv + 0x7C)) + 0x2C) = *(f32 *)(*(u8 **)((*(u8 * *)(pv + 0x7C)) + 0x24) + 0x24) * ((*(f32 *)(a0 + 0x2C)) / *(f32 *)((*(u8 * *)(a0 + 0x24)) + 0x24));
        *(vu0_q *)((*(u8 * *)(pv + 0x7C)) + 0x10) = (*(vu0_q *)(a0 + 0x10));
        (*(f32 *)(pv + 0x70)) = 16.0f;
        (*(s32 *)(pv + 0xB4)) = (*(s32 *)(pv + 0xAC));
        if ((*(u8 *)(a0 + 0xB0)) != 0xFF && (D_001BBC40[(*(u8 *)(a0 + 0xB0)) + D_001D545C * 16] & 0x80)) {
            (*(s16 *)(pv + 0x9E)) = 1;
        }
        break;
    case 1:
        moving = 0;
        {
        u8 *hero = D_001A4BE0;
        if ((*(u8 * *)(hero + 0x35C)) == a0 && (func_00388800(a0 + 0x10, hero + 0x80) < 0.75f || (*(u8 *)(a0 + 0xBC)) != 0) && (*(s32 *)(hero + 0x360)) != 0) {
            (*(u8 *)(a0 + 0xBC)) = 1;
            (*(s32 *)(pv + 0xB4)) = (*(s32 *)(pv + 0xA8));
            if (((*(s32 *)(pv + 0x98)) != -1 && (*(s16 *)(pv + 0x9E)) == 0) || ((D_00142C34[0] & 0x200000) && (*(s32 *)(pv + 0x98)) != -1)) {
                func_L01_00452F40(a0, 1);
                t = D_L08_001DF21C_003304D8 + ((*(s32 *)(pv + 0x98)) << 8);
                o = func_L01_00458650(t);
                if (o == 0) {
                    moving = 1;
                } else {
                u8 *gs = D_00142BA0;
                if (*(s32 *)(gs + 0x94) & 0x200000) {
                    moving = 1;
                } else if (D_L08_001DCE98 < func_00388800(a0 + 0x10, t + 0x10)) {
                    moving = 1;
                } else if (((*(u8 **)(o + 0x88) == a0 && *(s16 *)(o + 0xC0) != 0) || (*(s32 *)(gs + 0x94) & 0x200000)) && *(f32 *)(o + 0xB0) < 0.1f) {
                    moving = 1;
                }
                }
                if (!moving) {
                    func_L08_00330F68_prompt(a0, pv);
                }
            } else {
                moving = 1;
            }
            if (moving) {
                u8 *hero = D_001A4BE0;
                (*(s16 *)(hero + 0x212)) = 3;
                (*(s16 *)(hero + 0x1E0)) = 0x1E;
                if (fabs_asm(*(f32 *)((*(u8 * *)(pv + 0x7C)) + 0x18) - (*(f32 *)(a0 + 0x18))) > 1.0f) {
                    *(f32 *)((*(u8 * *)(pv + 0x7C)) + 0x18) = (*(f32 *)(a0 + 0x18)) + 1.0f;
                }
                *(f32 *)((*(u8 * *)(pv + 0x7C)) + 0x18) += 0.10000000894069672f;
                (*(u16 *)(a0 + 0x96))++;
                if ((*(s32 *)(hero + 0x360)) == 0) {
                    func_L08_004D8D78(0x74, 1);
                }
            }
        }
        }
        if ((*(u16 *)(a0 + 0x96)) >= 11) {
        u8 *hero = D_001A4BE0;
        if ((*(u8 * *)(hero + 0x35C)) == a0 && (*(s32 *)(hero + 0x360)) != 0) {
            if (((*(s32 *)(pv + 0x98)) != -1 && (*(s16 *)(pv + 0x9E)) == 0) || ((D_00142C34[0] & 0x200000) && (*(s32 *)(pv + 0x98)) != -1)) {
                func_L01_00452F40(a0, 1);
                t2 = D_L08_001DF21C_003304D8 + ((*(s32 *)(pv + 0x98)) << 8);
                o2 = func_L01_00458650(t2);
                if (o2 == 0 || (*(u8 **)(o2 + 0x88) == a0 && *(s16 *)(o2 + 0xC0) != 0 && *(f32 *)(o2 + 0xB0) < 0.1f)) {
                    if (o2 == 0 || *(f32 *)(o2 + 0xB0) < 0.1f) {
                        moving = 1;
                        (*(s16 *)(pv + 0x9E)) = 1;
                    }
                } else if (D_L08_001DCE98 < func_00388800(a0 + 0x10, t2 + 0x10)) {
                    moving = 1;
                }
                if (!moving) {
                    func_L08_00330F68_prompt(a0, pv);
                }
            } else {
                moving = 1;
            }
            if (moving) {
                if ((*(s32 *)(pv + 0xA4)) != -1 && (*(s32 *)(pv + 0x78)) != -1 && (*(s16 *)(a0 + 0xB2)) != 0xAD && (*(s16 *)(a0 + 0xB2)) != 0xAE && (*(f32 *)(a0 + 0x18)) > 425.0f) {
                    func_L08_0040FEF0(D_L08_001DCE88[0], D_L08_001DCE88[1], D_L08_001DCE88[2], D_L08_001DCE88[3]);
                    func_L01_003EAB30((*(s32 *)(pv + 0xA4)));
                }
                if (func_00388800(a0 + 0x10, D_001A4BE0 + 0x80) < 10.0f) {
                    func_L08_004D8D78(0, 1);
                }
                func_L08_00330F68_ride(a0, pv, 1);
            }
        }
        }
        {
        u8 *hero = D_001A4BE0;
        if (fabs_asm((*(f32 *)(hero + 0x88)) - (*(f32 *)(a0 + 0x18))) > 50.0f) {
            func_L08_00330F68_ride(a0, pv, 0);
        }
        }
        break;
    case 2:
        hero = D_001A4BE0;
        if ((*(u8 * *)(hero + 0x35C)) == a0) {
            (*(s16 *)(hero + 0x1E0)) = 2;
            (*(s16 *)(hero + 0x212)) = 3;
        }
        path = D_L08_0021D140[(*(s32 *)(pv + 0x78))];
        if ((*(s32 *)(pv + 0xA4)) != -1 && (*(s32 *)(pv + 0xBC)) == 0 && func_L01_003EAB60((*(s32 *)(pv + 0xA4)))) {
            (*(vu0_q *)(a0 + 0x10)) = path[*(s32 *)path - 7];
            (*(s32 *)(pv + 0x74)) = *(s32 *)path - 7;
            func_L01_004F12C0(a0 + 0x10, hero + 0x90, 0, 1);
            (*(s32 *)(pv + 0xBC)) = 1;
        }
        if ((*(s32 *)(pv + 0x74)) >= *(s32 *)path) {
            (*(s32 *)(pv + 0xBC)) = 0;
            if ((*(s32 *)(pv + 0x80)) != -1 && (snd = (D_001A30B0 + (((*(s32 *)(pv + 0x80))) << 7)), *(u8 **)(snd + 0xDC) == a0) && snd[0xD0] != 0) {
                func_0039FB08((*(s32 *)(pv + 0x80)));
            }
            (*(s32 *)(pv + 0x80)) = -1;
            func_L01_00441FB8(a0, 4, -1);
        } else {
            if ((*(u8 * *)(pv + 0x90)) != 0) {
                func_L01_00445758(*(f32 *)((*(u8 * *)(pv + 0x90)) + 0x78), 4.363323387224227e-05f, 4.848136813961901e-05f, 0.005817764438688755f, a0 + 0xF8, pv + 0x94, 0);
            }
            *(vu0_q *)((*(u8 * *)(pv + 0x7C)) + 0xF0) = (*(vu0_q *)(a0 + 0xF0));
            v = *(vu0_v4 *)&path[(*(s32 *)(pv + 0x74)) + 1];
            vec_sub_ba(&v2, &v, a0 + 0x10);
            func_00388830((*(f32 *)(pv + 0x84)), &v2, &v2);
            vec_add_ab(a0 + 0x10, a0 + 0x10, &v2);
            *(vu0_q *)((*(u8 * *)(pv + 0x7C)) + 0x10) = (*(vu0_q *)(a0 + 0x10));
            *(f32 *)((*(u8 * *)(pv + 0x7C)) + 0x18) += 1.0f;
            if (func_00388800(a0 + 0x10, &v) < 0.5f) {
                (*(s32 *)(pv + 0x74))++;
            }
            if ((*(s32 *)(pv + 0x74)) >= *(s32 *)path - 6 && (*(f32 *)(pv + 0x84)) >= 0.05000000447034836f) {
                (*(f32 *)(pv + 0x84)) -= 0.002222222276031971f;
            }
            func_L01_004405F4(a0);
        }
        break;
    case 3:
        {
        u8 *hero = D_001A4BE0;
        if ((*(u8 * *)(hero + 0x35C)) == a0) {
            (*(s16 *)(hero + 0x1E0)) = 2;
            (*(s16 *)(hero + 0x212)) = 3;
        }
        }
        path = D_L08_0021D140[(*(s32 *)(pv + 0x78))];
        if ((*(s32 *)(pv + 0x74)) < 0) {
            if ((*(s32 *)(pv + 0x80)) != -1 && (snd = (D_001A30B0 + (((*(s32 *)(pv + 0x80))) << 7)), *(u8 **)(snd + 0xDC) == a0) && snd[0xD0] != 0) {
                func_0039FB08((*(s32 *)(pv + 0x80)));
            }
            (*(s32 *)(pv + 0x80)) = -1;
            func_L01_00441FB8(a0, 4, -1);
        } else {
            if ((*(u8 * *)(pv + 0x90)) != 0) {
                func_L01_00445758(*(f32 *)((*(u8 * *)(pv + 0x90)) + 0x78), 4.363323387224227e-05f, 4.848136813961901e-05f, 0.005817764438688755f, a0 + 0xF8, pv + 0x94, 0);
            }
            *(vu0_q *)((*(u8 * *)(pv + 0x7C)) + 0xF0) = (*(vu0_q *)(a0 + 0xF0));
            v = *(vu0_v4 *)&path[(*(s32 *)(pv + 0x74)) + 1];
            vec_sub_ba(&v2, &v, a0 + 0x10);
            func_00388830((*(f32 *)(pv + 0x84)), &v2, &v2);
            vec_add_ab(a0 + 0x10, a0 + 0x10, &v2);
            *(vu0_q *)((*(u8 * *)(pv + 0x7C)) + 0x10) = (*(vu0_q *)(a0 + 0x10));
            *(f32 *)((*(u8 * *)(pv + 0x7C)) + 0x18) += 1.0f;
            if (func_00388800(a0 + 0x10, &v) < 0.5f) {
                (*(s32 *)(pv + 0x74))--;
            }
            if ((*(s32 *)(pv + 0x74)) < 7 && (*(f32 *)(pv + 0x84)) >= 0.05000000447034836f) {
                (*(f32 *)(pv + 0x84)) -= 0.002222222276031971f;
            }
            func_L01_004405F4(a0);
        }
        break;
    case 4:
        (*(s32 *)(pv + 0xB4)) = (*(s32 *)(pv + 0xAC));
        *(f32 *)((*(u8 * *)(pv + 0x7C)) + 0x18) -= 0.10000000894069672f;
        if (++(*(u16 *)(a0 + 0x96)) >= 11) {
            if (func_00388800(a0 + 0x10, D_001A4BE0 + 0x80) < 10.0f) {
                func_L08_004D8D78(0, 1);
            }
            func_L01_00441FB8(a0, 5, -1);
        }
        break;
    case 5:
        if ((*(u8 * *)(D_001A4BE0 + 0x35C)) != a0) {
            if ((*(s32 *)(pv + 0xA4)) != -1) {
                func_L02_003C3A40((*(s32 *)(pv + 0xA4)));
            }
            (*(u8 *)(a0 + 0xBC)) = 0;
            (*(s16 *)(pv + 0x9C)) = 0;
            func_L01_00441FB8(a0, 1, -1);
        }
        break;
    }
    func_003C26C8((*(u8 * *)(pv + 0x7C)));
    vec_sub_ba(&v, a0 + 0x10, &saved);
    func_003BF838(pv + 0x30, &v, &savedRot, a0 + 0xF0);
    if ((*(s32 *)(pv + 0xB4)) == (*(s32 *)(pv + 0xA8))) {
        (*(f32 *)(pv + 0xB8)) += 0.03f;
        if ((*(f32 *)(pv + 0xB8)) > 1.0f) {
            (*(f32 *)(pv + 0xB8)) = 1.0f;
        }
    } else {
        (*(f32 *)(pv + 0xB8)) -= 0.03f;
        if ((*(f32 *)(pv + 0xB8)) < 0.0f) {
            (*(f32 *)(pv + 0xB8)) = 0.0f;
        }
    }
    c = func_003894A0((*(s32 *)(pv + 0xAC)), (*(s32 *)(pv + 0xA8)), (*(f32 *)(pv + 0xB8)));
    if (func_00388398(pv + 0xB0)) {
        (*(s32 *)(pv + 0xB0)) = 60;
    }
    f = func_00388978((f32)(*(s32 *)(pv + 0xB0)) * 6.2831855f / 60.0f) * 0.5f + 0.5f;
    a = func_L01_0040D068(c, 0x80B0B0B0);
    (*(s32 *)(a0 + 0x78)) = func_003894A0(a, func_L01_0040D068(c, 0x80505050), f);
}
/* localdecomp:end func_L08_003304D8 */
