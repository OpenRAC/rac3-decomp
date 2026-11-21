#include "common.h"

/* NTSC-U counterpart of func_L04_004FE9E0 (src/levels/shared/L04_004FE9E0.c): 100 -> 120 */
/* localdecomp:start func_L04_004FA8C0 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x18];
    u8 *moby;          /* 0x18 */
    s32 count;         /* 0x1C */
    vu0_v4 pos;        /* 0x20 */
    u8 pad30[0x10];
    vu0_v4 normal;     /* 0x40 */
} S_4FE9E0_004FE9E0;

typedef struct {
    u8 pad0[0x80];
    vu0_v4 v80;        /* 0x80 */
    u8 pad90[0x20];
    vu0_v4 vB0;        /* 0xB0 */
    u8 padC0[0x1C4];
    f32 f284;          /* 0x284 */
    u8 pad288[0x38];
    vu0_v4 v2C0;       /* 0x2C0 */
    vu0_v4 v2D0;       /* 0x2D0 */
    vu0_v4 v2E0;       /* 0x2E0 */
    vu0_v4 v2F0;       /* 0x2F0 */
    vu0_v4 v300;       /* 0x300 */
    vu0_v4 v310;       /* 0x310 */
    f32 f320[2];       /* 0x320 */
    f32 f328[2];       /* 0x328 */
    f32 f330[2];       /* 0x330 */
    f32 f338;          /* 0x338 */
    f32 f33C;          /* 0x33C */
    f32 f340;          /* 0x340 */
    f32 f344;          /* 0x344 */
    f32 f348;          /* 0x348 */
    f32 f34C;          /* 0x34C */
    f32 f350;          /* 0x350 */
    f32 f354;          /* 0x354 */
    s32 i358;          /* 0x358 */
    u8 *p35C;          /* 0x35C */
    s32 i360;          /* 0x360 */
    u8 pad364[6];
    s16 h36A;          /* 0x36A */
    s16 h36C;          /* 0x36C */
    s16 h36E;          /* 0x36E */
    u8 pad370[0xFC];
    u8 b46C;           /* 0x46C */
    u8 pad46D[0x783];
    u8 *pBF0;          /* 0xBF0 */
    u8 padBF4[0x87C];
    s16 h1470;         /* 0x1470 */
    u8 pad1472[0xD];
    u8 b147F;          /* 0x147F */
    u8 pad1480[0x6F0];
    s32 i1B70;         /* 0x1B70 */
    u8 pad1B74[0xA4C];
    void *p25C0;       /* 0x25C0 */
    u8 pad25C4[8];
    s32 i25CC;         /* 0x25CC */
    u8 pad25D0[0x24];
    u8 b25F4;          /* 0x25F4 */
} H_4FE9E0_004FE9E0;

extern H_4FE9E0_004FE9E0 D_001A4BE0;
extern S_4FE9E0_004FE9E0 D_L04_001E9600_004FA8C0;
extern s32 D_001D545C;
extern s32 D_L04_001D673C_004FA8C0;

extern s32 func_L01_004E5540_004FA8C0(void);
extern void func_L01_004EB918_004FA8C0(vu0_v4 *out, vu0_v4 *low, s32 mode, f32 height, f32 depth);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_L01_003FC760_004FA8C0(void);
extern s32 func_003D00C0(void);
extern f32 func_003BE988(void *, void *);
extern s32 func_003BF5E0(void *);
extern u8 *func_0037E0B8(void *);
extern u8 *func_003BF7E8(u8 *);
extern f32 func_L01_0044E300_004FA8C0(void *);
extern f32 func_003887C8(void *, void *);
extern void func_0012FE98(void *, void *);
extern f32 func_L01_0050D870_004FA8C0(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388730(void *, void *);
extern s32 func_L01_004FC388_004FA8C0(s32, s32);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_004F02A0_004FA8C0(void *, void *);
extern void func_L01_0050D060_004FA8C0(void *target, f32 magnitude, f32 angle, s32 add_position, f32 height);

void func_L04_004FA8C0(void) {
    vu0_v4 low;
    vu0_v4 out;
    vu0_v4 d;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 e;
    vu0_v4 f;
    f32 dist;
    f32 scale;
    s32 st;
    s32 i;
    u8 *p;

    D_001A4BE0.h36E++;
    qzero(&D_001A4BE0.v2F0);
    D_001A4BE0.h36C++;
    D_001A4BE0.v2C0.z = 1.0f;
    D_001A4BE0.f33C = 32.0f;
    D_001A4BE0.v2C0.x = 0.0f;
    D_001A4BE0.v2C0.y = 0.0f;
    D_001A4BE0.f340 = 0.0f;
    D_001A4BE0.f338 = 0.0f;
    D_001A4BE0.h36A = 0;
    D_001A4BE0.p35C = 0;
    if (D_001A4BE0.i358 != 0) {
        D_001A4BE0.i358++;
    }
    dist = D_001A4BE0.f284 * 2.2f;
    if (D_001A4BE0.i25CC == 2) {
        dist = D_001A4BE0.f284 * 2.9f;
    }
    if (func_L01_004E5540_004FA8C0()) {
        dist = 0.0f;
    }
    func_L01_004EB918_004FA8C0(&out, &low, 1, dist, -48.0f);
    if (func_003CE740(&out, &low, 2, D_001A4BE0.p25C0, 0)) {
        D_001A4BE0.b147F = func_L01_003FC760_004FA8C0();
        if (D_L04_001E9600_004FA8C0.moby != 0) {
            D_001A4BE0.b147F = 0;
            if (D_001D545C == 2) {
                if (*(s16 *)(D_L04_001E9600_004FA8C0.moby + 0xAA) == 0x18C6) D_001A4BE0.b147F = 2;
                if (*(s16 *)(D_L04_001E9600_004FA8C0.moby + 0xAA) == 0x18AF) D_001A4BE0.b147F = 2;
            }
            if (D_001D545C == 5) {
                if (*(s16 *)(D_L04_001E9600_004FA8C0.moby + 0xAA) == 0x1607) D_001A4BE0.b147F = 2;
                if (*(s16 *)(D_L04_001E9600_004FA8C0.moby + 0xAA) == 0x1681) D_001A4BE0.b147F = 2;
                if (*(s16 *)(D_L04_001E9600_004FA8C0.moby + 0xAA) == 0x15F7) D_001A4BE0.b147F = 2;
                if (*(s16 *)(D_L04_001E9600_004FA8C0.moby + 0xAA) == 0x16BB) D_001A4BE0.b147F = 3;
            }
            if (D_001D545C == 8) {
                if (*(s16 *)(D_L04_001E9600_004FA8C0.moby + 0xAA) == 0x1A44) D_001A4BE0.b147F = 2;
            }
            if (D_001D545C == 10) {
                if (*(s16 *)(D_L04_001E9600_004FA8C0.moby + 0xAA) == 0x1645) D_001A4BE0.b147F = 3;
                if (*(s16 *)(D_L04_001E9600_004FA8C0.moby + 0xAA) == 0x162E) D_001A4BE0.b147F = 1;
            }
            if (D_001D545C == 21) {
                if (*(s16 *)(D_L04_001E9600_004FA8C0.moby + 0xAA) == 0x1BA9) D_001A4BE0.b147F = 3;
            }
        }
        D_001A4BE0.h1470 = func_003D00C0();
        if (D_001A4BE0.h1470 == 0) {
            D_001A4BE0.f350 = func_003BE988(&D_L04_001E9600_004FA8C0.pos, &D_001A4BE0.v2D0);
            if (D_001A4BE0.v80.z < D_001A4BE0.f350 && D_001A4BE0.i358 <= 0) {
                D_001A4BE0.i358 = 1;
            }
            if (!func_003CE740(&out, &low, 0x24, D_001A4BE0.p25C0, 0)) goto end;
            D_001A4BE0.b147F = func_L01_003FC760_004FA8C0();
        }
        if (D_001A4BE0.h1470 == 3) {
            D_001A4BE0.f354 = D_L04_001E9600_004FA8C0.pos.z;
            out.z = D_L04_001E9600_004FA8C0.pos.z - 0.01f;
            if (!func_003CE740(&out, &low, 4, D_001A4BE0.p25C0, 0)) goto end;
        }
        if (D_001A4BE0.h1470 == 11) {
            D_001A4BE0.f354 = D_L04_001E9600_004FA8C0.pos.z;
        } else {
            if (D_L04_001E9600_004FA8C0.moby != 0) {
                if (func_003BF5E0(D_L04_001E9600_004FA8C0.moby)) D_001A4BE0.h36A = 1;
                p = func_0037E0B8(D_L04_001E9600_004FA8C0.moby);
                if (p != 0 && (*(u16 *)(p + 0x1E) & 8)) D_001A4BE0.h36A = 1;
                p = func_003BF7E8(D_L04_001E9600_004FA8C0.moby);
                if (p != 0 && (*(s32 *)(p + 0x3C) & 8)) D_001A4BE0.h36A = 1;
            }
            if (D_L04_001E9600_004FA8C0.count > 0) {
                *(vu0_q *)&D_001A4BE0.v2F0 = *(vu0_q *)&D_L04_001E9600_004FA8C0.pos;
                D_001A4BE0.f338 = D_L04_001E9600_004FA8C0.pos.z;
                if (D_L04_001D673C_004FA8C0) {
                    D_001A4BE0.f338 = func_L01_0044E300_004FA8C0(&D_L04_001E9600_004FA8C0.pos);
                }
                D_001A4BE0.f33C = func_003887C8(&D_001A4BE0.v80, &D_001A4BE0.v2F0);
                D_001A4BE0.p35C = D_L04_001E9600_004FA8C0.moby;
                func_0012FE98(&D_001A4BE0.v2C0, &D_L04_001E9600_004FA8C0.normal);
                D_001A4BE0.f340 = func_L01_0050D870_004FA8C0(&D_L04_001E9600_004FA8C0.normal);
                D_001A4BE0.f34C = func_00388A28(D_L04_001E9600_004FA8C0.normal.x, D_L04_001E9600_004FA8C0.normal.y);
                vec_sub_ba(&d, &D_001A4BE0.v2F0, &D_001A4BE0.v80);
                if (0.0f < func_00388730(&d, &D_001A4BE0.v2C0)) {
                    D_001A4BE0.f33C = -D_001A4BE0.f33C;
                }
                if (D_001A4BE0.f33C < 0.02f) {
                    D_001A4BE0.h36C = 0;
                    if (D_001A4BE0.f340 <= 0.87266463f || D_001A4BE0.b25F4 != 0) {
                        D_001A4BE0.h36E = 0;
                        D_001A4BE0.pBF0 = D_L04_001E9600_004FA8C0.moby;
                    }
                }
            }
        }
    }
end:
    if (D_001A4BE0.v80.z > D_001A4BE0.f350) {
        D_001A4BE0.i358 = 0;
    }
    if (D_001A4BE0.h36E != 0) {
        D_001A4BE0.i360 = 0;
    } else {
        D_001A4BE0.i360++;
        D_001A4BE0.v300 = D_001A4BE0.v2F0;
        if (func_L01_004FC388_004FA8C0(0x38, 0x78) == 0) {
            D_001A4BE0.i1B70 = 0;
        }
    }
    qzero(&D_001A4BE0.v2E0);
    switch (D_001A4BE0.b25F4) {
    case 0:
        D_001A4BE0.v2E0.z = -1.0f;
        break;
    case 1:
        if (D_001A4BE0.v310.w != 0.0f) {
            func_003BEBF8(&D_001A4BE0.v310.w, 0.0f, 1.0f);
            *(vu0_q *)&D_001A4BE0.v2E0 = *(vu0_q *)&D_001A4BE0.v310;
            func_003886E8(&D_001A4BE0.v2C0, &D_001A4BE0.v2E0, -1.0f);
        } else {
            *(vu0_q *)&D_001A4BE0.v2E0 = *(vu0_q *)&D_001A4BE0.v2C0;
            func_003886E8(&D_001A4BE0.v2E0, &D_001A4BE0.v2E0, -1.0f);
        }
        break;
    case 2:
        scale = -1.0f;
        if (0.0f < D_001A4BE0.vB0.w) {
            scale = 1.0f;
        }
        vec_sub_ab(&D_001A4BE0.v2E0, &D_001A4BE0.vB0, &D_001A4BE0.v80);
        func_00388830(&D_001A4BE0.v2E0, &D_001A4BE0.v2E0, scale);
        break;
    }
    D_001A4BE0.f344 = 0.0f;
    D_001A4BE0.f348 = 0.0f;
    D_001A4BE0.f330[0] = 0.0f;
    D_001A4BE0.f330[1] = 0.0f;
    D_001A4BE0.f328[0] = 0.0f;
    D_001A4BE0.f328[1] = 0.0f;
    D_001A4BE0.f320[0] = 0.0f;
    D_001A4BE0.f320[1] = 0.0f;
    if (D_001A4BE0.f33C < 0.25f) {
        st = D_001A4BE0.i25CC;
        if (st == 0 || st == 12 || st == 9 || st == 7 || (st == 4 && D_001A4BE0.b46C != 0) || st == 1) {
            func_L01_004F02A0_004FA8C0(&D_001A4BE0.v2C0, &d);
            if (-0.7853982f < d.y && d.y < 0.7853982f) {
                D_001A4BE0.f344 = d.y;
            }
            if (-0.7853982f < d.x && d.x < 0.7853982f) {
                D_001A4BE0.f348 = d.x;
            }
            for (i = 0; i < 2; i++) {
                dist = 1.5707964f;
                if (i == 1) {
                    dist = -dist;
                }
                func_L01_0050D060_004FA8C0(&a, 0.2f, dist, 1, 0.45f);
                func_L01_0050D060_004FA8C0(&b, 0.2f, dist, 1, -0.45f);
                if (func_003CE740(&a, &b, 0x22, D_001A4BE0.p25C0, 0)) {
                    if (D_L04_001D673C_004FA8C0) {
                        D_001A4BE0.f320[i] = func_L01_0044E300_004FA8C0(&D_L04_001E9600_004FA8C0.pos) - func_L01_0044E300_004FA8C0(&D_001A4BE0.v2F0);
                    } else {
                        D_001A4BE0.f320[i] = D_L04_001E9600_004FA8C0.pos.z - D_001A4BE0.f338;
                    }
                    if (0.4f < fabs_asm(D_001A4BE0.f320[i])) {
                        D_001A4BE0.f320[i] = 0.0f;
                    }
                    func_0012FE98(&f, &D_L04_001E9600_004FA8C0.normal);
                    func_L01_004F02A0_004FA8C0(&f, &e);
                    if (-0.7853982f < e.y && e.y < 0.7853982f) {
                        D_001A4BE0.f328[i] = e.y;
                    }
                    if (-0.7853982f < e.x && e.x < 0.7853982f) {
                        D_001A4BE0.f330[i] = e.x;
                    }
                } else {
                    D_001A4BE0.f320[i] = 0.0f;
                    D_001A4BE0.f328[i] = D_001A4BE0.f344;
                    D_001A4BE0.f330[i] = D_001A4BE0.f348;
                }
            }
        }
    }
}
/* localdecomp:end func_L04_004FA8C0 */
