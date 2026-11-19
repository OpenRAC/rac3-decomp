#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_004FE9E0 */
typedef struct M_4FE9E0 {
    u8 pad0[0xAA];
    s16 fAA;
} M_4FE9E0;

typedef struct D_4FE9E0 {
    u8 pad0[0x18];
    M_4FE9E0 *f18;
    s32 f1C;
    vu0_v4 v20;
    u8 pad30[0x10];
    f32 f40;
    f32 f44;
    u8 pad48[0x8];
    u8 end;
} D_4FE9E0;

typedef struct H_4FE9E0 {
    u8 pad0[0x80];
    vu0_v4 v80;
    u8 pad90[0x20];
    vu0_v4 vB0;
    u8 padC0[0x1C4];
    f32 f284;
    u8 pad288[0x38];
    f32 f2C0;
    f32 f2C4;
    f32 f2C8;
    u8 pad2CC[0x4];
    f32 f2D0;
    u8 pad2D4[0xC];
    vu0_v4 v2E0;
    vu0_v4 v2F0;
    vu0_v4 v300;
    vu0_v4 v310;
    f32 f320[2];
    f32 f328[2];
    f32 f330[2];
    f32 f338;
    f32 f33C;
    f32 f340;
    f32 f344;
    f32 f348;
    f32 f34C;
    f32 f350;
    f32 f354;
    s32 f358;
    void * f35C;
    s32 f360;
    u8 pad364[0x6];
    s16 f36A;
    u16 f36C;
    u16 f36E;
    u8 pad370[0xFC];
    u8 f46C;
    u8 pad46D[0x783];
    M_4FE9E0 *fBF0;
    u8 padBF4[0x87C];
    s16 f1470;
    u8 pad1472[0xD];
    u8 f147F;
    u8 pad1480[0x6F0];
    s32 f1B70;
    u8 pad1B74[0xA4C];
    void * f25C0;
    u8 pad25C4[0x8];
    s32 f25CC;
    u8 pad25D0[0x24];
    u8 f25F4;
    u8 pad25F5[0xB];
    u8 end;
} H_4FE9E0;

extern H_4FE9E0 D_001A4BE0;
extern D_4FE9E0 D_L04_001E9580_004FE9E0;
extern s32 D_001D545C;
extern s32 D_001D673C;

extern s32 func_L01_004E9308(void);
extern void func_L01_004EF6F0(void *, void *, f32, f32, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003FE908(void);
extern s32 func_003D5630(void);
extern f32 func_003C3EC8(void *, void *);
extern s32 func_003C4B50(void *);
extern u8 *func_00382348(void *);
extern u8 *func_003C4D58(void *);
extern f32 func_L01_00451580(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0012FE98(void *, void *);
extern f32 func_L01_00511848(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CE68(void *, void *);
extern s32 func_L01_00500240(s32, s32);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004F40A8(void *, void *);
extern void func_L01_00511038(void *, f32, f32, f32, s32);

void func_L04_004FE9E0(void) {
    vu0_v4 s0;
    vu0_v4 s10;
    vu0_v4 s20;
    vu0_v4 s30;
    vu0_v4 s40;
    vu0_v4 s50;
    vu0_v4 s60;
    f32 sc;
    s32 i;
    f32 sg;
    vu0_v4 *q2f0;
    vu0_v4 *q2e0;

    D_001A4BE0.f36E = D_001A4BE0.f36E + 1;
    D_001A4BE0.f36C = D_001A4BE0.f36C + 1;
    qzero(&D_001A4BE0.v2F0);
    D_001A4BE0.f2C8 = 1.0f;
    D_001A4BE0.f33C = 32.0f;
    D_001A4BE0.f2C0 = 0.0f;
    D_001A4BE0.f2C4 = 0.0f;
    D_001A4BE0.f340 = 0.0f;
    D_001A4BE0.f338 = 0.0f;
    D_001A4BE0.f36A = 0;
    D_001A4BE0.f35C = 0;
    if (D_001A4BE0.f358 != 0) {
        D_001A4BE0.f358 = D_001A4BE0.f358 + 1;
    }
    sc = D_001A4BE0.f284 * 2.2f;
    if (D_001A4BE0.f25CC == 2) {
        sc = D_001A4BE0.f284 * 2.9f;
    }
    if (func_L01_004E9308() != 0) {
        sc = 0.0f;
    }
    func_L01_004EF6F0(&s10, &s0, sc, -48.0f, 1);
    if (func_003D3CB0(&s10, &s0, 2, D_001A4BE0.f25C0, 0) == 0) {
        goto tail;
    }
    D_001A4BE0.f147F = func_L01_003FE908();
    if (D_L04_001E9580_004FE9E0.f18 != 0) {
        D_001A4BE0.f147F = 0;
        if (D_001D545C == 2) {
            if (D_L04_001E9580_004FE9E0.f18->fAA == 0x18C6) {
                D_001A4BE0.f147F = 2;
            }
            if (D_L04_001E9580_004FE9E0.f18->fAA == 0x18AF) {
                D_001A4BE0.f147F = 2;
            }
        }
        if (D_001D545C == 5) {
            if (D_L04_001E9580_004FE9E0.f18->fAA == 0x1607) {
                D_001A4BE0.f147F = 2;
            }
            if (D_L04_001E9580_004FE9E0.f18->fAA == 0x1681) {
                D_001A4BE0.f147F = 2;
            }
            if (D_L04_001E9580_004FE9E0.f18->fAA == 0x15F7) {
                D_001A4BE0.f147F = 2;
            }
            if (D_L04_001E9580_004FE9E0.f18->fAA == 0x16BB) {
                D_001A4BE0.f147F = 3;
            }
        }
        if (D_001D545C == 8) {
            if (D_L04_001E9580_004FE9E0.f18->fAA == 0x1A44) {
                D_001A4BE0.f147F = 2;
            }
        }
        if (D_001D545C == 10) {
            if (D_L04_001E9580_004FE9E0.f18->fAA == 0x1645) {
                D_001A4BE0.f147F = 3;
            }
            if (D_L04_001E9580_004FE9E0.f18->fAA == 0x162E) {
                D_001A4BE0.f147F = 1;
            }
        }
        if (D_001D545C == 0x15) {
            if (D_L04_001E9580_004FE9E0.f18->fAA == 0x1BA9) {
                D_001A4BE0.f147F = 3;
            }
        }
    }
    D_001A4BE0.f1470 = func_003D5630();
    if (D_001A4BE0.f1470 == 0) {
        D_001A4BE0.f350 = func_003C3EC8(&D_L04_001E9580_004FE9E0.v20, &D_001A4BE0.f2D0);
        if (D_001A4BE0.v80.z < D_001A4BE0.f350) {
            if (D_001A4BE0.f358 <= 0) {
                D_001A4BE0.f358 = 1;
            }
        }
        if (func_003D3CB0(&s10, &s0, 0x24, D_001A4BE0.f25C0, 0) == 0) {
            goto tail;
        }
        D_001A4BE0.f147F = func_L01_003FE908();
    }
    if (D_001A4BE0.f1470 == 3) {
        D_001A4BE0.f354 = D_L04_001E9580_004FE9E0.v20.z;
        s10.z = D_L04_001E9580_004FE9E0.v20.z - 0.01f;
        if (func_003D3CB0(&s10, &s0, 4, D_001A4BE0.f25C0, 0) == 0) {
            goto tail;
        }
    }
    if (D_001A4BE0.f1470 == 0xB) {
        D_001A4BE0.f354 = D_L04_001E9580_004FE9E0.v20.z;
        goto tail;
    }
    if (D_L04_001E9580_004FE9E0.f18 != 0) {
        if (func_003C4B50(D_L04_001E9580_004FE9E0.f18) != 0) {
            D_001A4BE0.f36A = 1;
        }
        {
            u8 *r = func_00382348(D_L04_001E9580_004FE9E0.f18);
            if (r != 0 && (*(u16 *)(r + 0x1E) & 8) != 0) {
                D_001A4BE0.f36A = 1;
            }
        }
        {
            u8 *p = func_003C4D58(D_L04_001E9580_004FE9E0.f18);
            if (p != 0 && (*(u32 *)(p + 0x3C) & 8) != 0) {
                D_001A4BE0.f36A = 1;
            }
        }
    }
    if (D_L04_001E9580_004FE9E0.f1C > 0) {
        vu0_v4 *pos;
        q2f0 = &D_001A4BE0.v2F0;
        *q2f0 = D_L04_001E9580_004FE9E0.v20;
        D_001A4BE0.f338 = D_L04_001E9580_004FE9E0.v20.z;
        pos = &D_L04_001E9580_004FE9E0.v20;
        if (D_001D673C != 0) {
            D_001A4BE0.f338 = func_L01_00451580(pos);
        }
        D_001A4BE0.f33C = func_0038CF00(&D_001A4BE0.v80, &D_001A4BE0.v2F0);
        D_001A4BE0.f35C = D_L04_001E9580_004FE9E0.f18;
        func_0012FE98(&D_001A4BE0.f2C0, &D_L04_001E9580_004FE9E0.f40);
        D_001A4BE0.f340 = func_L01_00511848(&D_L04_001E9580_004FE9E0.f40);
        D_001A4BE0.f34C = func_0038D160(D_L04_001E9580_004FE9E0.f40, D_L04_001E9580_004FE9E0.f44);
        vec_sub_ba(&s20, &D_001A4BE0.v2F0, &D_001A4BE0.v80);
        if (func_0038CE68(&s20, &D_001A4BE0.f2C0) > 0.0f) {
            D_001A4BE0.f33C = -D_001A4BE0.f33C;
        }
        if (D_001A4BE0.f33C < 0.02f) {
            D_001A4BE0.f36C = 0;
            if (D_001A4BE0.f340 <= 0.87266463f || D_001A4BE0.f25F4 != 0) {
                D_001A4BE0.f36E = 0;
                D_001A4BE0.fBF0 = D_L04_001E9580_004FE9E0.f18;
            }
        }
    }
tail:
    if (D_001A4BE0.v80.z > D_001A4BE0.f350) {
        D_001A4BE0.f358 = 0;
    }
    if ((s16)D_001A4BE0.f36E != 0) {
        D_001A4BE0.f360 = 0;
    } else {
        D_001A4BE0.f360 = D_001A4BE0.f360 + 1;
        D_001A4BE0.v300 = D_001A4BE0.v2F0;
        if (func_L01_00500240(0x38, 0x64) == 0) {
            D_001A4BE0.f1B70 = 0;
        }
    }
    q2e0 = &D_001A4BE0.v2E0;
    qzero(q2e0);
    switch (D_001A4BE0.f25F4) {
    case 0:
        D_001A4BE0.v2E0.z = -1.0f;
        break;
    case 1:
        if (D_001A4BE0.v310.w != 0.0f) {
            func_003C4138(&D_001A4BE0.v310.w, 0.0f, 1.0f);
            *q2e0 = D_001A4BE0.v310;
            func_0038CE20(&D_001A4BE0.f2C0, &D_001A4BE0.v2E0, -1.0f);
        } else {
            *q2e0 = *(vu0_v4 *)&D_001A4BE0.f2C0;
            func_0038CE20(&D_001A4BE0.v2E0, &D_001A4BE0.v2E0, -1.0f);
        }
        break;
    case 2:
        sg = -1.0f;
        if (D_001A4BE0.vB0.w > 0.0f) {
            sg = 1.0f;
        }
        vec_sub_ab(&D_001A4BE0.v2E0, &D_001A4BE0.vB0, &D_001A4BE0.v80);
        func_0038CF68(&D_001A4BE0.v2E0, &D_001A4BE0.v2E0, sg);
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
        if (D_001A4BE0.f25CC == 0 || D_001A4BE0.f25CC == 12 || D_001A4BE0.f25CC == 9 || D_001A4BE0.f25CC == 7 || (D_001A4BE0.f25CC == 4 && D_001A4BE0.f46C != 0) || D_001A4BE0.f25CC == 1) {
            func_L01_004F40A8(&D_001A4BE0.f2C0, &s20);
            if (-0.785398185f < s20.y && s20.y < 0.785398185f) {
                D_001A4BE0.f344 = s20.y;
            }
            if (-0.785398185f < s20.x && s20.x < 0.785398185f) {
                D_001A4BE0.f348 = s20.x;
            }
            for (i = 0; i < 2; i++) {
                sc = 1.5707964f;
                if (i == 1) {
                    sc = -sc;
                }
                func_L01_00511038(&s30, 0.2f, sc, 0.45f, 1);
                func_L01_00511038(&s40, 0.2f, sc, -0.45f, 1);
                if (func_003D3CB0(&s30, &s40, 0x22, D_001A4BE0.f25C0, 0) != 0) {
                    if (D_001D673C != 0) {
                        D_001A4BE0.f320[i] = func_L01_00451580(&D_L04_001E9580_004FE9E0.v20) - func_L01_00451580(&D_001A4BE0.v2F0);
                    } else {
                        D_001A4BE0.f320[i] = D_L04_001E9580_004FE9E0.v20.z - D_001A4BE0.f338;
                    }
                    if (__builtin_fabsf(D_001A4BE0.f320[i]) > 0.4f) {
                        D_001A4BE0.f320[i] = 0.0f;
                    }
                    func_0012FE98(&s60, &D_L04_001E9580_004FE9E0.f40);
                    func_L01_004F40A8(&s60, &s50);
                    if (-0.785398185f < s50.y && s50.y < 0.785398185f) {
                        D_001A4BE0.f328[i] = s50.y;
                    }
                    if (-0.785398185f < s50.x && s50.x < 0.785398185f) {
                        D_001A4BE0.f330[i] = s50.x;
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
/* localdecomp:end func_L04_004FE9E0 */
