#include "common.h"

/* NTSC-U counterpart of func_L39_0063A888 (src/levels/shared/L39_0063A888.c): 60 Hz timer range (180-300 frames against 150-250) */
/* localdecomp:start func_L39_00638040 */
typedef int Q_00638040 __attribute__((mode(TI)));
typedef struct V4_00638040 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00638040;

typedef struct VT_00638040 {
    u8 pad0[0x20];
    void (*f20)(void *);
} VT_00638040;

extern Q_00638040 D_L39_0025F860;
typedef struct Glob_00638040 {
    u8 pad0[0xA4];
    u8 bA4[1];
} Glob_00638040;

extern Glob_00638040 D_001A5990;
extern void func_L39_0063C4B8(void *);
extern void func_L39_0061B080(void *, void *);
extern void func_00388BD0(void *, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L39_0062DD00(void *);
extern void func_L39_006385C8(u8 *);
extern void func_L39_00628E98(void *, s32, s32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_L01_00410840(void *, void *, f32, f32, u8 *);
extern void func_L39_006459F8();
extern void func_L39_006702B0(void *, void *);

void func_L39_00638040(u8 *g, u8 *obj, void *pos, void *rot, s32 id) {
    s32 saved[6];
    V4_00638040 a;
    V4_00638040 b;
    Q_00638040 va, vb, vc;
    u8 *m;
    s32 i;
    V4_00638040 *pa = &a;
    V4_00638040 *pb = &b;
    u8 *col;
    u8 *pos2;
    u8 *ctl;
    s16 *ids;
    s32 *handles;

    for (i = 0; i < 6; i++) {
        saved[i] = *(s32 *)(g + 0x478 + i * 0x50);
    }
    if (obj == 0) {
        obj = *(u8 **)(g + 0x2524);
    }
    ids = (s16 *)(g + 0x1DB0);
    handles = (s32 *)(g + 0x2400);
    col = g + 0x11A0;
    pos2 = g + 0xA0;
    ctl = g + 0x1A40;
    (*(VT_00638040 **)(g + 0x14))->f20(g);
    *(s32 *)(g + 0x2544) = id;
    func_L39_0063C4B8(g);
    for (i = 0; i < 6; i++) {
        saved[i] = *(s32 *)(g + 0x478 + i * 0x50);
    }
    *(u8 **)(g + 0x2524) = obj;
    *(u16 *)(obj + 0x34) |= 8;
    func_L39_0061B080(g, obj);
    *(Q_00638040 *)(*(u8 **)(g + 0x2524) + 0x10) = *(Q_00638040 *)pos;
    *(Q_00638040 *)(*(u8 **)(g + 0x2524) + 0xF0) = *(Q_00638040 *)rot;
    *(Q_00638040 *)(g + 0xA0) = *(Q_00638040 *)pos;
    *(Q_00638040 *)(g + 0xB0) = *(Q_00638040 *)rot;
    m = *(u8 **)(g + 0x2524);
    func_00388BD0(m + 0xC0, m + 0xF0);
    func_00388830(pb, *(u8 **)(g + 0x2524) + 0xE0, -3.0f);
    func_00388830(pa, *(u8 **)(g + 0x2524) + 0xE0, 1.0f);
    __asm__("lqc2 %0, %1" : "=j"(vc) : "m"(*(V4_00638040 *)(g + 0xA0)));
    __asm__("lqc2 %0, %1" : "=j"(va) : "m"(a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vc));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(va) : "memory");
    __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(vb) : "j"(vb), "j"(vc));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(vb));
    if (func_003CE740(pa, pb, 2, *(u8 **)(g + 0x2524), 0)) {
        *(Q_00638040 *)(g + 0xA0) = D_L39_0025F860;
    }
    *(u16 *)(*(u8 **)(g + 0x2524) + 0x34) |= 2;
    *(u8 **)(g + 0x424) = *(u8 **)(g + 0x2524);
    func_L39_0062DD00(g);
    func_L39_006385C8(g);
    func_L39_00628E98(g, 0, 0);
    *(s8 *)(g + 0x2502) = -1;
    for (i = 0; i < 2; i++) {
        ids[i] = -1;
    }
    if (*(s32 *)(g + 0x18D0) == 0) {
        *(s32 *)(g + 0x18D0) = 1;
    }
    for (i = 0; i < 9; i++) {
        handles[i] = -1;
    }
    *(f32 *)(g + 0x2478) = 2.125f;
    *(f32 *)(g + 0x247C) = 1.25f;
    *(s32 *)(g + 0x10A0) = func_L39_005B24C8(0xB4, 0x12C);
    *(s32 *)(g + 0x24AC) = 0;
    *(f32 *)(g + 0x10A4) = 0.007f;
    *(f32 *)(g + 0x10A8) = 0.3f;
    *(f32 *)(g + 0xFA0) = 1.16f;
    *(f32 *)(g + 0x2498) = 37.0f;
    *(f32 *)(g + 0x249C) = 13.0f;
    *(s32 *)(g + 0x24B4) = 11;
    func_L01_00410840(col, pos2, *(f32 *)(g + 0xB8), 0.0f, *(u8 **)(g + 0x424));
    *(f32 *)(g + 0x132C) = 1.15f;
    if (g[0x1A14] != 0) {
        *(u8 **)(g + 0x1288) = g + 0x1100;
        *(u8 **)(g + 0x128C) = g + 0x1130;
    } else {
        *(u8 **)(g + 0x1288) = g + 0x20;
        *(u8 **)(g + 0x128C) = g + 0x60;
    }
    *(u16 *)(g + 0x1280) |= 1;
    *(void **)(g + 0x1284) = func_L39_006459F8;
    *(s32 *)(g + 0x12CC) = g[0x24C9];
    *(s32 *)(g + 0x12D8) = *(s32 *)(g + 0x2544);
    *(u8 **)(g + 0x12D0) = g;
    if (D_001A5990.bA4[*(s32 *)(g + 0x2544)] == 1) {
        *(f32 *)(g + 0x1260) = -6.0f;
        *(f32 *)(g + 0x12C4) = 6.0f;
        *(s32 *)(g + 0x1268) = 0;
    }
    *(s8 *)(g + 0x24D8) = -1;
    func_L39_006702B0(ctl, g);
    *(s16 *)(g + 0x2480) = 1;
    *(s16 *)(g + 0x2510) = 4;
    *(s16 *)(g + 0x2512) = 15;
    g[0x250B] = 0xFF;
}
/* localdecomp:end func_L39_00638040 */
