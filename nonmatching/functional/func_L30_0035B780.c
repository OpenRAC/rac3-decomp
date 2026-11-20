/* functional: medium. Straight-line HUD update written from the PAL asm block by block (every gp slot, constant, widget id and call order read from it); 598 diff words from scheduling and the reload of the hero base only (609 vs 656 rows: retail does not share some address and (1.0 - x) sub-expressions). func_0011B2E8 is the game sprintf; the format strings D_L30_001DDC68/70/78 are not decoded (see notes). */
__asm__(".extern D_L30_001DDC44, 4");
extern s32 D_L30_001DDC44;
__asm__(".extern D_L30_001DDB54, 4");
extern s32 D_L30_001DDB54;
__asm__(".extern D_L30_001DDB1C, 4");
extern s32 D_L30_001DDB1C;
__asm__(".extern D_L30_001DDB20, 4");
extern s32 D_L30_001DDB20;
__asm__(".extern D_L30_001DDB18, 4");
extern s32 D_L30_001DDB18;
__asm__(".extern D_L30_001DDB8C, 4");
extern s32 D_L30_001DDB8C;
__asm__(".extern D_L30_001DDBC0, 4");
extern s32 D_L30_001DDBC0;
__asm__(".extern D_L30_001DDBCC, 4");
extern s32 D_L30_001DDBCC;
__asm__(".extern D_L30_001DDBC4, 4");
extern s32 D_L30_001DDBC4;
__asm__(".extern D_L30_001DDBD0, 4");
extern s32 D_L30_001DDBD0;
__asm__(".extern D_L30_001DDBC8, 4");
extern s32 D_L30_001DDBC8;
__asm__(".extern D_L30_001DDBD4, 4");
extern s32 D_L30_001DDBD4;
__asm__(".extern D_L30_001DDBEC, 4");
extern s32 D_L30_001DDBEC;
__asm__(".extern D_L30_001DDBF0, 4");
extern s32 D_L30_001DDBF0;
__asm__(".extern D_L30_001DDB28, 4");
extern s32 D_L30_001DDB28;
__asm__(".extern D_L30_001DDB14, 4");
extern s32 D_L30_001DDB14;
__asm__(".extern D_L30_001DDB24, 4");
extern s32 D_L30_001DDB24;
__asm__(".extern D_L30_001DDB10, 4");
extern s32 D_L30_001DDB10;
__asm__(".extern D_L30_001DDB50, 4");
extern f32 D_L30_001DDB50;
__asm__(".extern D_L30_001DDB6C, 4");
extern f32 D_L30_001DDB6C;
__asm__(".extern D_L30_001DDB70, 4");
extern f32 D_L30_001DDB70;
__asm__(".extern D_L30_001DDB4C, 4");
extern f32 D_L30_001DDB4C;
__asm__(".extern D_L30_001DDB30, 4");
extern f32 D_L30_001DDB30;
__asm__(".extern D_L30_001DDB2C, 4");
extern f32 D_L30_001DDB2C;
__asm__(".extern D_L30_001DDB48, 4");
extern f32 D_L30_001DDB48;
__asm__(".extern D_L30_001DDB40, 4");
extern f32 D_L30_001DDB40;
__asm__(".extern D_L30_001DDB3C, 4");
extern f32 D_L30_001DDB3C;
__asm__(".extern D_L30_001DDB44, 4");
extern f32 D_L30_001DDB44;
__asm__(".extern D_L30_001DDAD8, 4");
extern f32 D_L30_001DDAD8;
__asm__(".extern D_L30_001DDB60, 4");
extern f32 D_L30_001DDB60;
__asm__(".extern D_L30_001DDB58, 4");
extern f32 D_L30_001DDB58;
__asm__(".extern D_L30_001DDB88, 4");
extern f32 D_L30_001DDB88;
__asm__(".extern D_L30_001DDBAC, 4");
extern f32 D_L30_001DDBAC;
__asm__(".extern D_L30_001DDBB0, 4");
extern f32 D_L30_001DDBB0;
__asm__(".extern D_L30_001DDB9C, 4");
extern f32 D_L30_001DDB9C;
__asm__(".extern D_L30_001DDB7C, 4");
extern f32 D_L30_001DDB7C;
__asm__(".extern D_L30_001DDBE4, 4");
extern f32 D_L30_001DDBE4;
__asm__(".extern D_L30_001DDBDC, 4");
extern f32 D_L30_001DDBDC;
__asm__(".extern D_L30_001DDBF4, 4");
extern f32 D_L30_001DDBF4;
__asm__(".extern D_L30_001DDC00, 4");
extern f32 D_L30_001DDC00;
__asm__(".extern D_L30_001DDC14, 4");
extern f32 D_L30_001DDC14;
__asm__(".extern D_L30_001DDC04, 4");
extern f32 D_L30_001DDC04;
extern char D_L30_001DDC68[];
extern char D_L30_001DDC70[];
extern char D_L30_001DDC78[];
extern char D_L30_001E1460[];
extern char D_L30_001E1468[];
extern char D_L30_001E1470[];
extern char D_L30_001E1478[];
extern f32 D_L30_001E1410;
extern f32 D_L30_001E1414;
extern f32 D_L30_001E1418;
extern f32 D_L30_001E141C;
extern f32 D_L30_001E1420;
extern f32 D_L30_001E1424;
extern u8 D_001A4BE0[];
extern int func_0011B2E8(char *, char *, ...);
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_00516FD8(s32, char *);
extern s32 func_L01_005170B8(s32, u32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_L01_00517340(s32, s32, s32, s32, s32);
extern s32 func_L01_00516558(s32, f32 *, f32 *);
extern s32 func_0038CAD0(void *);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L30_0034CA78(void);
extern void func_L30_0035ADB8(void);
extern s32 func_L30_00358360(void *);
typedef struct {
    u8 p0[0xE4]; s32 xE4; s32 xE8;
    u8 pEC[0x110 - 0xEC]; s32 x110; s32 x114; s32 x118; s32 x11C;
    s32 x120; s32 x124; s32 x128; s32 x12C;
} V_35B780;

void func_L30_0035B780(u8 *self) {
    V_35B780 *v = *(V_35B780 **)(self + 0x68);
    f32 r, ratio;
    s32 col, col2, n, i, s, t, a4, a5;
    f32 pos[2];

    func_L01_00516AA0(0x100012, 1, 1);
    if (D_L30_001DDC44 != 0) {
        ((void (*)(void *))func_L30_0035ADB8)(self);
    }
    if (v->x128 != *(s32 *)(D_001A4BE0 + 0x1B08)) {
        v->x128 = *(s32 *)(D_001A4BE0 + 0x1B08);
        v->x12C = D_L30_001DDB54;
    }
    if (*(s32 *)(D_001A4BE0 + 0x1B04) == 0) {
        func_L01_00516AA0(0x100013, 1, 0);
    } else {
        s32 kind;
        func_L01_00516AA0(0x100013, 1, 1);
        r = func_0038D0B0((f32)v->x12C * 1.5707964f / (f32)D_L30_001DDB54);
        col = func_0038DBD8(D_L30_001DDB1C, D_L30_001DDB20, r);
        func_0011B2E8(D_L30_001E1460, D_L30_001DDC68, *(s32 *)(D_001A4BE0 + 0x1B08));
        func_L01_00516FD8(0x100019, D_L30_001E1460);
        func_L01_005170B8(0x100019, col);
        func_L01_00517538(0x100019, D_L30_001DDB6C + D_L30_001DDB50 * r, D_L30_001DDB70 + D_L30_001DDB50 * r);
        kind = *(s32 *)(D_001A4BE0 + 0x1B04);
        if (kind == 1) {
            func_L01_00516470(0x100015, D_L30_001DDB2C + D_L30_001DDB4C * 0.5f + D_L30_001DDB40,
                              (1.0f - D_L30_001DDB30) - D_L30_001DDB48 * 0.5f);
            func_L01_00517538(0x100015, D_L30_001DDB3C + (D_L30_001DDB44 - D_L30_001DDB3C) * r,
                              D_L30_001DDAD8 * (D_L30_001DDB3C + (D_L30_001DDB44 - D_L30_001DDB3C) * r));
            func_L01_00517190(0x100015, 0xED94);
        } else if (kind == 2) {
            func_L01_00516470(0x100015, D_L30_001DDB2C + D_L30_001DDB4C * 0.5f,
                              (1.0f - D_L30_001DDB30) - D_L30_001DDB48 * 0.5f);
            func_L01_00517538(0x100015, D_L30_001DDB60 + (D_L30_001DDB44 - D_L30_001DDB60) * r,
                              D_L30_001DDAD8 * (D_L30_001DDB60 + (D_L30_001DDB44 - D_L30_001DDB60) * r));
            func_L01_00517190(0x100015, 0xED97);
        } else if (kind == 3) {
            func_L01_00516470(0x100015, D_L30_001DDB2C + D_L30_001DDB4C * 0.5f,
                              (1.0f - D_L30_001DDB30) - D_L30_001DDB48 * 0.5f);
            func_L01_00517538(0x100015, D_L30_001DDB60 + (D_L30_001DDB44 - D_L30_001DDB60) * r,
                              D_L30_001DDAD8 * (D_L30_001DDB60 + (D_L30_001DDB44 - D_L30_001DDB60) * r));
            func_L01_00517190(0x100015, 0xED96);
        } else if (kind == 4) {
            func_L01_00516470(0x100015, D_L30_001DDB2C + D_L30_001DDB4C * 0.5f + D_L30_001DDB58,
                              (1.0f - D_L30_001DDB30) - D_L30_001DDB48 * 0.5f);
            func_L01_00517538(0x100015, D_L30_001DDB60 + (D_L30_001DDB44 - D_L30_001DDB60) * r,
                              D_L30_001DDAD8 * (D_L30_001DDB60 + (D_L30_001DDB44 - D_L30_001DDB60) * r));
            func_L01_00517190(0x100015, 0xED95);
        }
    }
    func_0038CAD0(&v->x12C);
    if (v->xE4 != v->x120) {
        v->x120 = v->xE4;
        v->x124 = D_L30_001DDB8C;
    }
    r = func_0038D0B0((f32)v->x124 * 1.5707964f / (f32)D_L30_001DDB8C);
    col = func_0038DBD8(D_L30_001DDB1C, D_L30_001DDB18, r);
    func_0011B2E8(D_L30_001E1468, D_L30_001DDC68, v->xE4);
    func_L01_00516FD8(0x100021, D_L30_001E1468);
    func_L01_005170B8(0x100021, col);
    func_L01_00517538(0x100021, D_L30_001DDBAC + D_L30_001DDB88 * r, D_L30_001DDBB0 + D_L30_001DDB88 * r);
    func_0011B2E8(D_L30_001E1470, D_L30_001DDC68, v->xE8);
    func_L01_00516FD8(0x100022, D_L30_001E1470);
    func_L01_005170B8(0x100022, col);
    func_L01_00517538(0x100022, D_L30_001DDBAC + D_L30_001DDB88 * r, D_L30_001DDBB0 + D_L30_001DDB88 * r);
    func_L01_00517538(0x10001C, D_L30_001DDB9C + (D_L30_001DDB7C - D_L30_001DDB9C) * r,
                      D_L30_001DDAD8 * (D_L30_001DDB9C + (D_L30_001DDB7C - D_L30_001DDB9C) * r));
    func_0038CAD0(&v->x124);
    if (D_L30_001E1414 <= 0.0f) {
        func_L01_00516AA0(0x100023, 1, 0);
    } else {
        func_L01_00516AA0(0x100023, 1, 1);
        func_L01_00517538(0x100026, D_L30_001E1410 * D_L30_001DDBE4 / D_L30_001E1414, D_L30_001DDBDC);
        col = func_0038DBD8(D_L30_001DDBC0, D_L30_001DDBCC, D_L30_001E1410 / D_L30_001E1414);
        func_L01_00517340(0x100026, col, D_L30_001DDBC0, col, D_L30_001DDBC0);
        func_L01_00517538(0x100027, D_L30_001E1418 * D_L30_001DDBE4 / D_L30_001E141C, D_L30_001DDBDC);
        col = func_0038DBD8(D_L30_001DDBC4, D_L30_001DDBD0, D_L30_001E1418 / D_L30_001E141C);
        func_L01_00517340(0x100027, col, D_L30_001DDBC4, col, D_L30_001DDBC4);
        func_L01_00517538(0x100028, D_L30_001E1420 * D_L30_001DDBE4 / D_L30_001E1424, D_L30_001DDBDC);
        col = func_0038DBD8(D_L30_001DDBC8, D_L30_001DDBD4, D_L30_001E1420 / D_L30_001E1424);
        func_L01_00517340(0x100028, col, D_L30_001DDBC8, col, D_L30_001DDBC8);
    }
    n = func_L30_0034CA78() + 5;
    ratio = (f32)*(s32 *)(D_001A4BE0 + 0x2850)
            / ((f32)func_L30_0034CA78() * 20.0f + 100.0f);
    col2 = func_0038DBD8(D_L30_001DDBEC, D_L30_001DDBF0, ratio);
    i = 0;
    do {
        func_L01_00516AA0(0x10002E + i, 1, i < n);
        i++;
    } while (i < 10);
    func_L01_00516558(0x100038, &pos[0], &pos[1]);
    func_L01_00516470(0x100038, D_L30_001DDB2C + D_L30_001DDBF4 + D_L30_001DDC00 + (f32)n * D_L30_001DDC14, pos[1]);
    func_L01_00517538(0x10002D, (f32)*(s32 *)(D_001A4BE0 + 0x2850) / 200.0f * 10.0f * D_L30_001DDC14, D_L30_001DDC04);
    func_L01_00517340(0x10002D, D_L30_001DDBEC, col2, D_L30_001DDBEC, col2);
    if (ratio > 0.8f) {
        i = 0xED8E;
    } else if (ratio > 0.6f) {
        i = 0xED8F;
    } else if (ratio > 0.4f) {
        i = 0xED90;
    } else if (ratio > 0.2f) {
        i = 0xED91;
    } else {
        i = 0xED92;
    }
    func_L01_00517190(0x10002B, i);
    s = func_L30_00358360(self);
    t = s / 50;
    if (t < v->x11C) {
        a4 = D_L30_001DDB28;
        a5 = D_L30_001DDB1C;
        ratio = (f32)(v->x11C - t) / (f32)v->x11C;
    } else if (t < v->x118) {
        a4 = D_L30_001DDB14;
        a5 = D_L30_001DDB28;
        ratio = (f32)(v->x118 - t) / (f32)(v->x118 - v->x11C);
    } else if (t < v->x114) {
        a4 = D_L30_001DDB24;
        a5 = D_L30_001DDB14;
        ratio = (f32)(v->x114 - t) / (f32)(v->x114 - v->x118);
    } else if (t < v->x110) {
        a4 = D_L30_001DDB10;
        a5 = D_L30_001DDB24;
        ratio = (f32)(v->x110 - t) / (f32)(v->x110 - v->x114);
    } else {
        a4 = D_L30_001DDB20;
        a5 = D_L30_001DDB10;
        ratio = (f32)(0x258 - t) / (f32)(0x258 - v->x110);
    }
    func_L01_005170B8(0x10003D, func_0038DBD8(a4, a5, ratio));
    if (s > 0x8C9E) {
        func_0011B2E8(D_L30_001E1478, D_L30_001DDC78);
    } else {
        func_0011B2E8(D_L30_001E1478, D_L30_001DDC70, s / 3000, (s / 50) % 60);
    }
    func_L01_00516FD8(0x10003D, D_L30_001E1478);
}
