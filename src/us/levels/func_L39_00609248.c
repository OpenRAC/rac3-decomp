#include "common.h"

/* NTSC-U counterpart of func_L39_0060B948 (src/levels/shared/L39_0060B948.c) */
/* localdecomp:start func_L39_00609248 */
#include "vu0.h"

typedef struct {
    s16 key;
    s16 mode;
    s32 idx;
    s32 a;
    s32 b;
} E_0060B948;

typedef struct {
    s32 f0;
    void (*f4)(s32, s32);
    s32 f8;
    s32 fC;
    void (*f10)(void);
    void (*f14)(void);
} F_0060B948;

typedef struct {
    u8 pad0[0x10];
    s32 f10;
} P_0060B948;

typedef struct {
    u8 pad0[0x228];
    f32 f228;
    f32 f22C;
    u8 pad1[0x238 - 0x230];
    f32 f238;
    f32 f23C;
    u8 pad2[0x250 - 0x240];
    s32 f250;
    s32 f254;
    s32 f258;
} Q_0060B948;

typedef struct {
    u8 pad0[0x20];
    s16 f20;
    s16 f22;
    u8 pad1[0x2C - 0x24];
    s16 f2C;
    s16 f2E;
    u8 pad2[0x64 - 0x30];
    s32 f64;
} R_0060B948;

__asm__(".extern D_L39_0024BC6C, 16");
__asm__(".extern D_L39_0024BC40, 16");
__asm__(".extern D_L39_0024145C, 16");
__asm__(".extern D_L39_00244000, 16");
__asm__(".extern D_L39_0024BB64, 16");
__asm__(".extern D_L39_0024BB65, 16");
__asm__(".extern D_L39_0024BB66, 16");
__asm__(".extern D_L39_0024BB68_00609248, 16");
__asm__(".extern D_L39_0024BB6C_00609248, 16");
__asm__(".extern D_L39_0024BB70_00609248, 16");
__asm__(".extern D_L39_0024BB74, 16");
__asm__(".extern D_L39_00240408_00609248, 16");
extern u8 D_L39_0025F680_00609248[];
extern P_0060B948 D_L39_0025F840;
extern R_0060B948 D_L39_001FC4C0;
extern s32 D_L39_001FE1A0[];
extern s32 D_L39_0024BC6C;
extern s32 D_L39_0024BC40;
extern s32 D_L39_0024145C;
extern s32 D_L39_00244000;
extern E_0060B948 D_L39_0049C2E8[];
extern F_0060B948 D_L39_0049C2A0[];
extern Q_0060B948 D_L39_0025D7C0;
extern u8 D_L39_0024BB64;
extern u8 D_L39_0024BB65;
extern u8 D_L39_0024BB66;
extern f32 D_L39_0024BB68_00609248;
extern f32 D_L39_0024BB6C_00609248;
extern f32 D_L39_0024BB70_00609248;
extern f32 D_L39_0024BB74;
extern f32 D_L39_0024E150[];
extern u8 D_L39_00269600[];
extern s32 D_L39_00240408_00609248;
extern u8 D_L39_002257E0[];

extern s32 D_001DA138_sda_00609248;
extern s32 D_001DA13C_sda_00609248;
extern s32 D_001DA11C_sda_00609248;
extern s32 D_001DA118_sda_00609248;
extern void (*D_001DA110_sda_00609248)(void);
extern void (*D_001DA104_sda_00609248)(s32, s32);
extern s32 D_001DA108_sda_00609248;
extern s32 D_001DA10C_sda_00609248;
extern void (*D_001DA114_sda_00609248)(void);

extern void func_00388440(void *, s32, s32);
extern void func_L39_005BD7D8(s32, s32, s32, s32, s32);
extern void func_L39_005BD4E8(void);
extern void func_001264E0(s32);
extern void func_00194CB8(s32, s32, s32, s32, s32);
extern void func_00194760(void);
extern s32 func_00193680(void);
extern void func_L39_005F1248(void);
extern void func_L39_005BFDC8(void);
extern void func_00193C70(s32);
extern void func_00193C40(void);
extern void func_0038DA28(s32, s32, s32);
extern void func_00195048(s32, void *);
extern s32 func_00195AE8(void);
extern void func_003B8BC8(void);
extern void func_L01_004CADA0_00609248(void);
extern void func_L39_00608E60(void);

s32 func_L39_00609248(void) {
    s32 i;
    E_0060B948 *e;
    F_0060B948 *g;
    s32 mode;
    s32 saved;
    s32 v;
    s32 key;
    s32 m;

    func_00388440(D_L39_0025F680_00609248, -1, 0x80);
    func_L39_005BD7D8(6, 2, 0, 0, 0);
    func_L39_005BD4E8();
    D_L39_0025F840.f10 |= 0x80000000;
    func_001264E0(0);
    func_00194CB8(2, 0, 0, 0, 0);
    func_00194760();
    func_00193680();
    func_L39_005F1248();
    func_L39_005BFDC8();
    D_L39_002257E0[7] = 1;
    for (i = 0; i < 6; i++) {
        if (D_L39_001FE1A0[0x24 + i] != 0) {
            func_00193C70(D_L39_001FE1A0[0x24 + i]);
            func_00193C40();
            D_L39_0024BC6C = 0;
            D_L39_001FE1A0[0x24 + i] = 0;
        }
    }
    D_L39_001FC4C0.f20 = 2;
    D_L39_001FC4C0.f2E = -1;
    D_L39_001FC4C0.f22 = -1;
    D_L39_001FC4C0.f2C = 0;
    D_L39_001FC4C0.f64 = -1;
    D_L39_00244000 = 0;
    key = D_L39_0024145C;
    m = D_L39_0024BC40;
    D_001DA138_sda_00609248 = key;
    D_001DA13C_sda_00609248 = m;
    e = D_L39_0049C2E8;
    i = 0;
    do {
        if (e->key == -1) {
            if (e->mode == m) break;
        }
        if (e->key == key) {
            if (e->mode == -1) break;
            if (e->mode == m) break;
        }
        i++;
        e++;
    } while (i < 17);
    mode = 2;
    D_001DA11C_sda_00609248 = 0;
    D_001DA118_sda_00609248 = 0;
    if (i < 17) {
        D_001DA11C_sda_00609248 = e->b;
        D_001DA118_sda_00609248 = e->a;
        mode = e->idx;
    }
    g = &D_L39_0049C2A0[mode];
    D_001DA110_sda_00609248 = func_L39_00608E60;
    D_001DA104_sda_00609248 = 0;
    D_001DA108_sda_00609248 = 0;
    D_001DA10C_sda_00609248 = 0;
    D_001DA114_sda_00609248 = 0;
    if (g->f4) D_001DA104_sda_00609248 = g->f4;
    if (g->f8) D_001DA108_sda_00609248 = g->f8;
    if (g->fC) D_001DA10C_sda_00609248 = g->fC;
    if (g->f10) D_001DA110_sda_00609248 = g->f10;
    if (g->f14) D_001DA114_sda_00609248 = g->f14;
    D_L39_0025D7C0.f22C = 524288.0f;
    D_L39_0025D7C0.f238 = 255.0f;
    D_L39_0025D7C0.f23C = 128.0f;
    D_L39_0025D7C0.f258 = 0x10;
    D_L39_0025D7C0.f250 = 0;
    D_L39_0025D7C0.f254 = 0;
    D_L39_0025D7C0.f228 = 0.0f;
    v = g->f0;
    D_L39_001FC4C0.f2E = v;
    D_L39_0024BB64 = D_L39_0025D7C0.f250;
    D_L39_0024BB65 = D_L39_0025D7C0.f254;
    D_L39_0024BB66 = D_L39_0025D7C0.f258;
    D_L39_0024BB68_00609248 = D_L39_0025D7C0.f228;
    D_L39_0024BB6C_00609248 = 524288.0f;
    D_L39_0024BB70_00609248 = 255.0f;
    D_L39_0024BB74 = 128.0f;
    func_0038DA28(0, 0, 0);
    saved = D_L39_0024BC40;
    D_L39_0025F840.f10 |= 0x80000000;
    qzero(D_L39_0024E150);
    D_L39_0024E150[2] = -1.0f;
    D_L39_0024145C = saved;
    D_L39_00240408_00609248 = 0;
    (&D_L39_00240408_00609248)[1] = 0;
    func_00195048(saved, D_L39_00269600);
    func_00195AE8();
    func_003B8BC8();
    func_L01_004CADA0_00609248();
    if (D_001DA104_sda_00609248 != 0) {
        D_001DA104_sda_00609248(D_001DA118_sda_00609248, D_001DA11C_sda_00609248);
    }
    return 1;
}
/* localdecomp:end func_L39_00609248 */
