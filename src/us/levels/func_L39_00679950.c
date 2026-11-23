#include "common.h"

/* NTSC-U counterpart of func_L39_0067C408 (src/levels/39_multiplayer_menu/L39_0067C408.c) */
/* localdecomp:start func_L39_00679950 */
typedef struct G_0067C408 {
    u8 _p0[0x11];
    u8 name[0x83];
    s32 f94;
    u8 b98;
    u8 _p1[4];
    u8 b9D;
} G_0067C408;
typedef struct P_0067C408 {
    u8 _p0[0x70];
    s32 w70;
    u8 _p1[4];
    s32 w78;
    u8 _p2[0xF4];
    s32 w170;
    s32 w174;
    u8 _p3[8];
    u8 b180;
    u8 _p4;
    u8 name[0x142];
    s32 w2C4;
    u8 _p5[0x1C];
    u8 b2E4;
    u8 b2E5;
} P_0067C408;
typedef struct R_0067C408 {
    u8 _p0[0x30];
    u8 *f30;
    u8 _p1[8];
    s32 f3C;
    u8 _p2[0xC];
    s32 *f4C;
    G_0067C408 *f50;
} R_0067C408;
typedef struct Q_0067C408 {
    u8 _p0[0x284];
    s32 f284;
} Q_0067C408;

extern s32 D_L39_002403FC_00679950;
__asm__(".extern D_L39_002403FC_00679950, 16");
extern s32 D_L39_00240400_00679950;
__asm__(".extern D_L39_00240400_00679950, 16");
extern s32 D_L39_002415C0;
__asm__(".extern D_L39_002415C0, 16");
extern s32 D_L39_0024145C;
__asm__(".extern D_L39_0024145C, 16");
extern s32 *D_L39_002412A0;
__asm__(".extern D_L39_002412A0, 16");
extern void *D_L39_002417C0;
__asm__(".extern D_L39_002417C0, 16");
extern u8 D_L39_00235B60[];
extern Q_0067C408 *D_L39_00247A74_00679950;
extern R_0067C408 *D_L39_0024D860;
__asm__(".extern D_L39_0024D860, 16");
extern P_0067C408 D_001A5E50;
extern R_0067C408 *D_001E1FD0_sda;
void func_L39_0067C0E0(void);
void func_0038DA28(s32, s32, s32);
void func_L39_006D4D60(s32, s32);
void func_L39_0067E8D8(void);
void func_L39_00683310(s32, s32);
void func_L01_0047D2B0(s32);
void func_L39_0067A1F8(void);
void func_L39_00679F90(void);
void func_L39_0067A008(void);
void func_001954A8(void *);
s32 func_001954C0(void *);
void func_L39_006D6228(R_0067C408 *);
s32 func_L39_0067A388(G_0067C408 *);
void func_L39_006DA120(G_0067C408 *);
void func_L39_005D8290(s32);
void func_L39_005DDEA8(s32);
void func_L39_005D4DF0(s32);
void func_L39_00674AE0(void);
void func_L39_005D6848(void);
void func_L39_00683528(void);
void func_L39_006A5070(void);
void func_00199190(void);
void func_L39_006D1928(s32);
void *func_001206F4(void *, void *);

void func_L39_00679950(void) {
    s32 mode;
    s32 t;
    s32 c1;
    s32 c7;
    s32 c8;
    s32 w1;
    s32 w2;
    s32 size;
    s32 base;
    s32 i;
    P_0067C408 *p;
    P_0067C408 *p1;
    P_0067C408 *p7;
    P_0067C408 *p8;
    G_0067C408 *g;
    R_0067C408 *r;
    u8 ta;
    u8 ta1;

    size = 0xC8000;
    func_L39_0067C0E0();
    func_0038DA28(0, 0, 0);
    base = D_L39_002403FC_00679950;
    t = D_L39_00240400_00679950 - base;
    t -= size;
    mode = D_L39_002415C0;
    D_L39_002415C0 = -1;
    func_L39_006D4D60(base, 0xC8000);
    func_L39_0067E8D8();
    func_L39_00683310(D_L39_002403FC_00679950 + size, t);
    func_L01_0047D2B0(10);
    switch (mode) {
    case 0:
        D_L39_00247A74_00679950->f284 = 0x18;
        func_001954A8(func_L39_0067A1F8);
        func_001954C0(func_L39_0067A1F8);
        break;
    case 1:
        D_L39_00247A74_00679950->f284 = 0;
        func_001954A8(func_L39_00679F90);
        func_001954C0(func_L39_00679F90);
        p1 = &D_001A5E50;
        if (p1->w174 == 0) {
            if (p1->b2E4 == 0) {
                func_L39_006D6228(D_001E1FD0_sda);
            }
            if (p1->b2E5 != 0) {
                g = D_001E1FD0_sda->f50;
                ta1 = p1->b180;
                c1 = p1->w2C4;
                g->b9D = p1->b2E5;
                g->b98 = ta1;
                func_001206F4(g->name, (char *)p1->name);
                g->f94 = c1;
                if (func_L39_0067A388(g)) {
                    func_L39_006DA120(g);
                }
            }
            func_001954A8(func_L39_0067A008);
            func_001954C0(func_L39_0067A008);
        } else {
            func_001954A8(func_L39_0067A1F8);
            func_001954C0(func_L39_0067A1F8);
        }
        break;
    case 2:
        D_L39_00247A74_00679950->f284 = 0;
        func_001954A8(func_L39_0067A008);
        func_001954C0(func_L39_0067A008);
        break;
    case 4:
    case 6:
    case 9:
        if (D_L39_0024145C != 0x27) {
            for (i = 0; i < *D_L39_002412A0; i++) {
                func_L39_005D8290(i);
                func_L39_005DDEA8(i);
                func_L39_005D4DF0(i);
            }
            func_L39_00674AE0();
            func_L39_005D6848();
        }
        if (mode == 4) {
            D_L39_00247A74_00679950->f284 = 0x12;
        }
        if (mode == 9) {
            D_L39_00247A74_00679950->f284 = 0x19;
        }
        p = &D_001A5E50;
        func_001954A8(func_L39_00679F90);
        func_001954C0(func_L39_00679F90);
        func_L39_00683528();
        p->w170 = 0;
        if (D_L39_002417C0 == D_L39_00235B60) {
            D_L39_002417C0 = 0;
        }
        func_001954A8(func_L39_0067A008);
        func_001954C0(func_L39_0067A008);
        if (mode == 6) {
            r = D_001E1FD0_sda;
            w1 = p->w78;
            *r->f4C = w1;
            p->w78 = w1;
            w2 = p->w70;
            *(s32 *)(r->f30 + 0x28) = w2;
            p->w70 = w2;
            func_L39_006A5070();
            return;
        }
        if (mode == 4) {
            return;
        }
        func_00199190();
        if (p->w174 != 0) {
            D_L39_00247A74_00679950->f284 = 0x15;
        } else {
            func_L39_006D1928(D_L39_0024D860->f3C);
        }
        return;
    case 3:
    case 5:
        if (D_L39_0024145C != 0x27) {
            for (i = 0; i < *D_L39_002412A0; i++) {
                func_L39_005D8290(i);
                func_L39_005DDEA8(i);
                func_L39_005D4DF0(i);
            }
            func_L39_00674AE0();
            func_L39_005D6848();
        }
        if (mode == 5) {
            func_L39_006A5070();
        } else {
            D_L39_00247A74_00679950->f284 = 0x12;
        }
        func_001954A8(func_L39_0067A1F8);
        func_001954C0(func_L39_0067A1F8);
        break;
    case 8:
        p8 = &D_001A5E50;
        g = D_L39_0024D860->f50;
        ta = p8->b180;
        c8 = p8->w2C4;
        g->b9D = p8->b2E5;
        g->b98 = ta;
        func_001206F4(g->name, (char *)p8->name);
        g->f94 = c8;
        if (func_L39_0067A388(g)) {
            func_L39_006DA120(g);
        }
        D_L39_00247A74_00679950->f284 = 0x1D;
        func_001954A8(func_L39_0067A008);
        func_001954C0(func_L39_0067A008);
        break;
    case 7:
        p7 = &D_001A5E50;
        g = D_L39_0024D860->f50;
        ta = p7->b180;
        c7 = p7->w2C4;
        g->b9D = p7->b2E5;
        g->b98 = ta;
        func_001206F4(g->name, (char *)p7->name);
        g->f94 = c7;
        if (func_L39_0067A388(g)) {
            func_L39_006DA120(g);
        }
        D_L39_00247A74_00679950->f284 = 0x1D;
        func_001954A8(func_L39_0067A1F8);
        func_001954C0(func_L39_0067A1F8);
        return;
    default:
        return;
    }
}
/* localdecomp:end func_L39_00679950 */
