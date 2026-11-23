#include "common.h"

/* localdecomp:start func_L39_0060B948 */
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

__asm__(".extern D_L39_0024BB6C, 16");
__asm__(".extern D_L39_0024BB40, 16");
__asm__(".extern D_002412DC, 16");
__asm__(".extern D_L39_00243E90, 16");
__asm__(".extern D_L39_0024BA64, 16");
__asm__(".extern D_L39_0024BA65, 16");
__asm__(".extern D_L39_0024BA66, 16");
__asm__(".extern D_L39_0024BA68, 16");
__asm__(".extern D_L39_0024BA6C, 16");
__asm__(".extern D_L39_0024BA70, 16");
__asm__(".extern D_L39_0024BA74, 16");
__asm__(".extern D_00240288, 16");
extern u8 D_L39_0025F580[];
extern P_0060B948 D_L39_0025F740;
extern R_0060B948 D_001FC340;
extern s32 D_001FE020[];
extern s32 D_L39_0024BB6C;
extern s32 D_L39_0024BB40;
extern s32 D_002412DC;
extern s32 D_L39_00243E90;
extern E_0060B948 D_L39_0049C228[];
extern F_0060B948 D_L39_0049C1E0[];
extern Q_0060B948 D_L39_0025D6C0;
extern u8 D_L39_0024BA64;
extern u8 D_L39_0024BA65;
extern u8 D_L39_0024BA66;
extern f32 D_L39_0024BA68;
extern f32 D_L39_0024BA6C;
extern f32 D_L39_0024BA70;
extern f32 D_L39_0024BA74;
extern f32 D_L39_0024E050[];
extern u8 D_L39_00269500[];
extern s32 D_00240288;
extern u8 D_00225660[];

extern s32 D_001DA138_sda;
extern s32 D_001DA13C_sda;
extern s32 D_001DA11C_sda;
extern s32 D_001DA118_sda;
extern void (*D_001DA110_sda)(void);
extern void (*D_001DA104_sda)(s32, s32);
extern s32 D_001DA108_sda;
extern s32 D_001DA10C_sda;
extern void (*D_001DA114_sda)(void);

extern void func_0038CB78(void *, s32, s32);
extern void func_L39_005BF798(s32, s32, s32, s32, s32);
extern void func_L39_005BF490(void);
extern void func_001264E0(s32);
extern void func_00194BC8(s32, s32, s32, s32, s32);
extern void func_00194670(void);
extern s32 func_00193590(void);
extern void func_L39_005F3948(void);
extern void func_L39_005C1E10(void);
extern void func_00193B80(s32);
extern void func_00193B50(void);
extern void func_00392260(s32, s32, s32);
extern void func_00194F58(s32, void *);
extern s32 func_001959F8(void);
extern void func_003BE0C0(void);
extern void func_L01_004CEA60_0060B948(void);
extern void func_L39_0060B560(void);

s32 func_L39_0060B948(void) {
    s32 i;
    E_0060B948 *e;
    F_0060B948 *g;
    s32 mode;
    s32 saved;
    s32 v;
    s32 key;
    s32 m;

    func_0038CB78(D_L39_0025F580, -1, 0x80);
    func_L39_005BF798(6, 2, 0, 0, 0);
    func_L39_005BF490();
    D_L39_0025F740.f10 |= 0x80000000;
    func_001264E0(0);
    func_00194BC8(2, 0, 0, 0, 0);
    func_00194670();
    func_00193590();
    func_L39_005F3948();
    func_L39_005C1E10();
    D_00225660[7] = 1;
    for (i = 0; i < 6; i++) {
        if (D_001FE020[0x24 + i] != 0) {
            func_00193B80(D_001FE020[0x24 + i]);
            func_00193B50();
            D_L39_0024BB6C = 0;
            D_001FE020[0x24 + i] = 0;
        }
    }
    D_001FC340.f20 = 2;
    D_001FC340.f2E = -1;
    D_001FC340.f22 = -1;
    D_001FC340.f2C = 0;
    D_001FC340.f64 = -1;
    D_L39_00243E90 = 0;
    key = D_002412DC;
    m = D_L39_0024BB40;
    D_001DA138_sda = key;
    D_001DA13C_sda = m;
    e = D_L39_0049C228;
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
    D_001DA11C_sda = 0;
    D_001DA118_sda = 0;
    if (i < 17) {
        D_001DA11C_sda = e->b;
        D_001DA118_sda = e->a;
        mode = e->idx;
    }
    g = &D_L39_0049C1E0[mode];
    D_001DA110_sda = func_L39_0060B560;
    D_001DA104_sda = 0;
    D_001DA108_sda = 0;
    D_001DA10C_sda = 0;
    D_001DA114_sda = 0;
    if (g->f4) D_001DA104_sda = g->f4;
    if (g->f8) D_001DA108_sda = g->f8;
    if (g->fC) D_001DA10C_sda = g->fC;
    if (g->f10) D_001DA110_sda = g->f10;
    if (g->f14) D_001DA114_sda = g->f14;
    D_L39_0025D6C0.f22C = 524288.0f;
    D_L39_0025D6C0.f238 = 255.0f;
    D_L39_0025D6C0.f23C = 128.0f;
    D_L39_0025D6C0.f258 = 0x10;
    D_L39_0025D6C0.f250 = 0;
    D_L39_0025D6C0.f254 = 0;
    D_L39_0025D6C0.f228 = 0.0f;
    v = g->f0;
    D_001FC340.f2E = v;
    D_L39_0024BA64 = D_L39_0025D6C0.f250;
    D_L39_0024BA65 = D_L39_0025D6C0.f254;
    D_L39_0024BA66 = D_L39_0025D6C0.f258;
    D_L39_0024BA68 = D_L39_0025D6C0.f228;
    D_L39_0024BA6C = 524288.0f;
    D_L39_0024BA70 = 255.0f;
    D_L39_0024BA74 = 128.0f;
    func_00392260(0, 0, 0);
    saved = D_L39_0024BB40;
    D_L39_0025F740.f10 |= 0x80000000;
    qzero(D_L39_0024E050);
    D_L39_0024E050[2] = -1.0f;
    D_002412DC = saved;
    D_00240288 = 0;
    (&D_00240288)[1] = 0;
    func_00194F58(saved, D_L39_00269500);
    func_001959F8();
    func_003BE0C0();
    func_L01_004CEA60_0060B948();
    if (D_001DA104_sda != 0) {
        D_001DA104_sda(D_001DA118_sda, D_001DA11C_sda);
    }
    return 1;
}
/* localdecomp:end func_L39_0060B948 */

/* localdecomp:start func_L39_0060BCC0 */
extern u8 D_001DA121_sda;
extern void (*D_001DA114_sda)(void);
extern s32 D_L39_0024CC40;
__asm__(".extern D_L39_0024CC40, 4");
extern s32 D_00240288;
__asm__(".extern D_00240288, 16");
extern s32 D_001A43E0[];
extern u8 D_00225660[];
extern void func_001264E0(s32);
extern s32 func_00139E08(s32);
extern s32 func_001959F8(void);
extern void func_L39_005A61D8(void);
extern void func_L39_005A5010(void);
extern s32 func_L39_005A4058(void);
extern void func_00193B80(s32);
extern s32 func_00193590(void);
extern void func_00193B50(void);
extern s32 func_00194B88(s32);
extern s32 func_00194A38(s32);
extern void func_L39_005FD6F8(void);
extern void func_00387EF0(void);

void func_L39_0060BCC0(void) {
    (&D_00240288)[1] = 0;
    if (D_001DA121_sda == 0) {
        do {
            func_001264E0(0);
            func_00139E08(0);
            func_001959F8();
            func_L39_005A61D8();
            func_L39_005A5010();
        } while (!(D_001DA121_sda = func_L39_005A4058() != 0));
    }
    while (D_001A43E0[0x57] != 2 || D_001A43E0[0x59] >= 0) {
        func_001264E0(0);
        func_00139E08(0);
        func_L39_005A61D8();
        func_L39_005A5010();
        func_001959F8();
    }
    if (D_L39_0024CC40 != 0) {
        func_00193B80(D_L39_0024CC40);
    }
    while (func_00193590() != 0) {
        func_001959F8();
    }
    func_00193B50();
    func_00194B88(0);
    func_00194A38(0);
    func_00194A38(0);
    D_00225660[7] = 0;
    func_L39_005FD6F8();
    if (D_001DA114_sda != 0) {
        D_001DA114_sda();
    }
    func_00387EF0();
}
/* localdecomp:end func_L39_0060BCC0 */

/* localdecomp:start func_L39_0060BE00 */
__asm__(".extern D_L39_0024B9C8, 16");
__asm__(".extern D_L39_0024B9C8_b, 4");
__asm__(".extern D_L39_0024BB40, 16");
__asm__(".extern D_L39_00243E90, 16");
__asm__(".extern D_00240288, 16");
extern s32 D_L39_0024B9C8;
extern s32 D_L39_0024B9C8_b;
extern s32 D_L39_0024BB40;
extern s32 D_L39_00243E90;
extern s32 D_00240288;
extern u8 D_001DA120_sda;
extern u8 D_001DA121_sda;
extern u8 D_001DA144_sda;
extern f32 D_001DA140_sda;
extern s32 D_L39_0024BB94;

extern s32 func_001959F8(void);
extern void func_L39_0060B750(void);
extern s32 func_L39_0060B948(void);
extern void func_00387EF0(void);
extern void func_L01_00461818(void);
extern s32 func_L39_0060B4C8(s32);
extern void func_00387218(void);
extern void func_L39_0060B428(void);
extern void func_L39_005A61D8(void);
extern void func_L39_005A5010(void);
extern void func_003A92F0(s32);
extern s32 func_00139E08(s32);
extern s32 func_L39_005A4058(void);
extern void func_L39_005FCDF8(void);
extern void func_003A9150(void);
extern void func_003923D0(void);
extern void func_003BE200(void);
extern void func_00392748(s32);
extern void func_L39_00597E70(void);
extern void func_00392350(s32);
extern void func_L39_0058A5D0(s32);
extern void func_L39_0060BCC0(void);

s32 func_L39_0060BE00(void) {
    s32 done;

    func_001959F8();
    if (D_L39_0024BB40 < 0) {
        func_L39_0060B750();
        return 1;
    }
    done = 0;
    func_001959F8();
    func_L39_0060B948();
    func_001959F8();
    D_001DA120_sda = 0;
    D_001DA121_sda = 0;
    while (1) {
        func_L39_005FCDF8();
        func_003A9150();
        func_003923D0();
        if (D_001DA144_sda != 0) {
            func_003BE200();
        } else {
            func_00392748(1);
        }
        func_L39_00597E70();
        func_00392350(0);
        if (done != 0) {
            break;
        }
        func_00387EF0();
        func_L01_00461818();
        func_001959F8();
        done = func_L39_0060B4C8(D_001DA120_sda);
        D_L39_0024BB94 = 0;
        func_00387218();
        func_L39_0060B428();
        func_L39_005A61D8();
        func_L39_005A5010();
        func_003A92F0(1);
        func_00139E08(0);
        D_L39_0024B9C8_b = D_L39_0024B9C8 + 1;
        if (D_L39_00243E90 == 0) {
            D_001DA121_sda = func_L39_005A4058() != 0;
        }
        D_001DA120_sda = D_00240288 >= 2;
    }
    func_003A92F0(1);
    func_00139E08(0);
    if (D_001DA140_sda > 0.0f) {
        func_L39_0058A5D0(2);
    }
    func_L39_0060BCC0();
    return 1;
}
/* localdecomp:end func_L39_0060BE00 */

LINKER_REMNANT("asm/levels", func_L39_0060BF90);
