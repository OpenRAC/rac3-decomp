#include "common.h"

/* localdecomp:start func_L30_00359058 */
typedef struct {
    u8 pad0[0xC];
    f32 fC;
    u8 pad10[0x10];
} E_00359058;

typedef struct {
    u8 pad0[0x40];
    E_00359058 e[16];
} V_00359058;

typedef struct {
    u8 pad0[0x20];
    u8 type;
    u8 pad21[0x47];
    V_00359058 *vars;
    u8 pad6C[0x94];
} M_00359058;

typedef struct {
    s32 m0;
    s32 m4;
    s32 m8;
    s32 mC;
    s32 m10;
    u8 pad14[0x2C];
    s32 f40;
    u8 pad44[0x5C];
    s32 timer;
    s32 state;
    s32 iA8;
    s32 iAC;
} P_00359058;

extern u8 D_001A4C60[];
typedef struct {
    u8 pad0[0x80];
    f32 f80;
    u8 pad84[0x6C];
    f32 fF0;
    u8 padF4[0xC];
    f32 f100;
    u8 pad104[0x1A34];
    s32 f1B38;
} H_00359058;

extern H_00359058 D_001A4BE0;
extern M_00359058 *D_L30_001DF71C;
extern M_00359058 *D_L30_001DF71C_00359058;
extern s32 D_L30_001DEAB0;
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern void func_L30_0034CDC0(f32 *, f32 *, f32 *, f32 *, f32);
extern s32 func_0038CAD0(void *);
extern void func_L30_004CF4B0(s32, s32);
extern void func_003C2880(void *);

void func_L30_00359058(u8 *a0) {
    P_00359058 *s0 = *(P_00359058 **)(a0 + 0x68);
    f32 v[2];

    if (func_00382380(D_001A4C60, s0->f40, 0) && ((D_001A4C60[0x1AB8] ^ 1) & 1) && s0->state == 0) {
        s0->state = 1;
        s0->timer = 0xF0;
        if (s0->m0 != -1) {
            func_L01_00456230(&D_L30_001DF71C[s0->m0], 1);
        }
        D_L30_001DF71C[s0->m8].vars->e[s0->iA8].fC = 1.0f;
        D_L30_001DF71C[s0->m8].vars->e[s0->iAC].fC = 0.0f;
        D_L30_001DF71C[s0->m8].vars->e[8].fC = 0.0f;
        D_L30_001DF71C[s0->m8].vars->e[14].fC = 0.0f;
        D_L30_001DEAB0 = 0;
    }
    if (s0->state == 1) {
        func_L30_0034CDC0(&v[0], &v[1], 0, 0, 0.9f);
        if (D_001A4BE0.f80 < v[0] || v[1] < D_001A4BE0.f80) {
            D_001A4BE0.f100 -= D_001A4BE0.fF0;
        }
        if (func_0038CAD0(&s0->timer)) {
            s0->state = 2;
            s0->timer = 600;
            if (s0->m4 != -1) {
                func_L01_00456230(&D_L30_001DF71C[s0->m4], 1);
            }
            func_L30_004CF4B0(0x9A, 1);
        }
    }
    if (s0->state == 2) {
        func_L30_0034CDC0(&v[0], &v[1], 0, 0, 0.9f);
        if (D_001A4BE0.f80 < v[0] || v[1] < D_001A4BE0.f80) {
            D_001A4BE0.f100 -= D_001A4BE0.fF0;
        }
        if (func_0038CAD0(&s0->timer)) {
            D_L30_001DF71C[s0->m8].vars->e[s0->iA8].fC = 0.0f;
            D_L30_001DF71C[s0->m8].vars->e[s0->iAC].fC = 1.0f;
            D_L30_001DF71C[s0->m8].vars->e[8].fC = 1.0f;
            D_L30_001DF71C[s0->m8].vars->e[14].fC = 1.0f;
            D_L30_001DEAB0 = 1;
            s0->state = 0;
            D_001A4BE0.f1B38 |= 1;
        }
    }
    if (s0->mC != 0 && D_L30_001DF71C_00359058[s0->mC].type == 0x42) {
        if (s0->m10 != 0 && D_L30_001DF71C_00359058[s0->m10].type < 0xFD) {
            func_003C2880(&D_L30_001DF71C_00359058[s0->m10]);
        }
    }
}
/* localdecomp:end func_L30_00359058 */
