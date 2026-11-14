/* NTSC-U draft (2026-11-14, Claude worker): C of func_L32_00334220, the NTSC-U twin of func_L32_00334BD0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division -mvu0-use-vf0-vf2 @ps2as" (src/levels/shared/L32_00334BD0.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L32_00334BD0 (src/levels/shared/L32_00334BD0.c) */
/* localdecomp:start func_L32_00334220 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_L32_00334220;

typedef struct {
    u8 pad00[0x6C];
    s32 f6C;
    V4_L32_00334220 v70;
    u8 pad80[0x10];
    s32 f90;
    s32 f94;
    s32 f98;
    f32 f9C;
    s32 fA0;
    f32 fA4;
    f32 fA8;
    s32 fAC;
} Vars_L32_00334220;

typedef struct {
    u8 pad00[0x80];
    f32 f80;
    f32 f84;
    f32 f88;
} Hero_L32_00334220;

extern Hero_L32_00334220 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern u8 D_001BBE90[];
extern u8 D_001BBC40[];
extern u8 D_001A30B0[];
typedef struct {
    u8 pad[0x464];
    u8 spent[1];
} S_L32_00236080;
extern S_L32_00236080 D_L32_00236080;
__asm__(".extern D_L32_00236080, 16");

extern s32 func_L05_003286E8(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_004A6D20(void *, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);
extern s32 func_L01_00452EC8(void *);
extern f32 func_003887C8(void *, void *);
extern s32 func_0037E0F0(void *, s32, s32);
extern void func_003BF838(void *, void *, void *, void *);
extern f32 func_003BEC60(void *, void *, f32, f32, f32, f32);

void func_L32_00334220(u8 *a0) {
    Vars_L32_00334220 *p;
    V4_L32_00334220 s0v;
    V4_L32_00334220 s1v;
    V4_L32_00334220 d;
    u8 *pos;
    u8 *e;
    s32 idx;
    s32 b;
    u16 id;

    pos = a0 + 0x10;
    s0v = *(V4_L32_00334220 *)pos;
    s1v = *(V4_L32_00334220 *)(a0 + 0xF0);
    p = *(Vars_L32_00334220 **)(a0 + 0x68);
    switch (a0[0x20]) {
    case 0:
        p->f6C |= 1;
        p->fAC = 0;
        p->v70 = *(V4_L32_00334220 *)(a0 + 0x10);
        a0[0x20] = 1;
        if (p->fA0 == 0) {
            p->fA4 = *(f32 *)((u8 *)p + 0x78);
            p->fA8 = p->f9C;
            p->f90 = 0;
        } else {
            p->f90 = 1;
            p->fA4 = p->f9C;
            p->fA8 = *(f32 *)((u8 *)p + 0x78);
        }
        p->f94 = 0;
        p->f98 = -1;
        break;
    case 1:
        if (func_L05_003286E8(a0) != 0) {
            p->fAC = 1;
            if (*(u16 *)(a0 + 0xB2) & 1) {
                e = &D_001BBE90[(*(s16 *)(a0 + 0xB2) >> 1) + (D_001D545C_sda << 10)];
                if (((*e >> 4) & 7) != 7) {
                    *e += 0x10;
                }
            } else {
                e = &D_001BBE90[(*(s16 *)(a0 + 0xB2) >> 1) + (D_001D545C_sda << 10)];
                if ((*e & 7) != 7) {
                    *e += 1;
                }
            }
            if (p->f90 == 0) {
                func_L01_00441FB8(a0, 3, -1);
                if (func_L01_004A6D20(a0, p->f98) == 0) {
                    p->f98 = func_0039FE80(0, 4, a0);
                }
            } else {
                func_L01_00441FB8(a0, 2, -1);
                if (func_L01_004A6D20(a0, p->f98) == 0) {
                    p->f98 = func_0039FE80(0, 4, a0);
                }
            }
        }
        if (fabs_asm(*(f32 *)(a0 + 0x18) - D_001A4BE0.f88) > 3.0f && p->f90 == 0 && D_001A4BE0.f88 < *(f32 *)(a0 + 0x18)) {
            if (p->fAC != 1) {
                if ((D_001BBC40[a0[0xB0] + (D_001D545C_sda << 4)] & 0x80) == 0) {
                    id = *(u16 *)(a0 + 0xB2);
                    if (D_L32_00236080.spent[(s16)id] == 0) {
                        b = D_001BBE90[((s16)id >> 1) + (D_001D545C_sda << 10)];
                        if (id & 1) {
                            if (((b >> 4) & 7) != 0) {
                                goto snd1;
                            }
                            goto second;
                        } else {
                            if ((b & 7) == 0) {
                                goto second;
                            }
                        }
                    }
                }
            }
        snd1:
            if (func_L01_004A6D20(a0, p->f98) == 0) {
                p->f98 = func_0039FE80(0, 4, a0);
            }
            func_L01_00441FB8(a0, 3, -1);
            break;
        }
    second:
        if (fabs_asm(*(f32 *)(a0 + 0x18) - D_001A4BE0.f88) > 3.0f && p->f90 == 1 && *(f32 *)(a0 + 0x18) < D_001A4BE0.f88) {
            if (p->fAC != 1) {
                if ((D_001BBC40[a0[0xB0] + (D_001D545C_sda << 4)] & 0x80) == 0) {
                    id = *(u16 *)(a0 + 0xB2);
                    if (D_L32_00236080.spent[(s16)id] == 0) {
                        b = D_001BBE90[((s16)id >> 1) + (D_001D545C_sda << 10)];
                        if (id & 1) {
                            if (((b >> 4) & 7) != 0) {
                                goto snd2;
                            }
                            break;
                        } else {
                            if ((b & 7) == 0) {
                                break;
                            }
                        }
                    }
                }
            }
        snd2:
            if (func_L01_004A6D20(a0, p->f98) == 0) {
                p->f98 = func_0039FE80(0, 4, a0);
            }
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 2:
        d = s0v;
        d.z = p->fA4;
        if (func_003887C8(pos, &d) > 0.04f) {
            func_003BEC60(a0 + 0x18, (u8 *)p + 0xB0, d.z, 0.0019444445f, 0.0016666667f, 0.10000001f);
            p->f94 = p->f94 + 1;
        } else if (func_L05_003286E8(a0) == 0) {
            p->f90 = 0;
            idx = p->f98;
            if (idx != -1) {
                e = D_001A30B0 + (idx << 7);
                if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                    func_0039FB08(idx);
                }
            }
            p->f98 = -1;
            func_L01_00441FB8(a0, 1, -1);
            *(V4_L32_00334220 *)(a0 + 0x10) = d;
            p->f94 = 0;
        } else {
            idx = p->f98;
            if (idx != -1) {
                e = D_001A30B0 + (idx << 7);
                if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                    func_0039FB08(idx);
                }
            }
            p->f98 = -1;
        }
        break;
    case 3:
        func_L01_00452EC8(a0);
        if (p->fA8 < *(f32 *)(a0 + 0x18)) {
            if (*(f32 *)(a0 + 0x18) - D_001A4BE0.f88 < 2.8f && D_001A4BE0.f88 < *(f32 *)(a0 + 0x18)) {
                if (func_0037E0F0(&D_001A4BE0.f80, *(s32 *)((u8 *)p + 0xB4), 0) == 0) {
                    func_003BEC60(a0 + 0x18, (u8 *)p + 0xB0, p->fA8, 0.0019444445f, 0.0016666667f, 0.10000001f);
                    p->f94 = p->f94 + 1;
                }
            } else {
                func_003BEC60(a0 + 0x18, (u8 *)p + 0xB0, p->fA8, 0.0019444445f, 0.0016666667f, 0.10000001f);
                p->f94 = p->f94 + 1;
            }
        } else if (func_L05_003286E8(a0) == 0 && *(f32 *)(a0 + 0x18) <= p->fA8) {
            p->f90 = 1;
            idx = p->f98;
            if (idx != -1) {
                e = D_001A30B0 + (idx << 7);
                if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                    func_0039FB08(idx);
                }
            }
            p->f98 = -1;
            func_L01_00441FB8(a0, 1, -1);
            p->f94 = 0;
        } else {
            idx = p->f98;
            if (idx != -1) {
                e = D_001A30B0 + (idx << 7);
                if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                    func_0039FB08(idx);
                }
            }
            p->f98 = -1;
        }
        break;
    }
    vec_sub_ba(&d, a0 + 0x10, &s0v);
    func_003BF838((u8 *)p + 0x30, &d, &s1v, a0 + 0xF0);
}
/* localdecomp:end func_L32_00334220 */
