#include "common.h"

/* localdecomp:start func_L39_0063A888 */
typedef int Q_0063A888 __attribute__((mode(TI)));
typedef struct V4_0063A888 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_0063A888;

typedef struct VT_0063A888 {
    u8 pad0[0x20];
    void (*f20)(void *);
} VT_0063A888;

extern Q_0063A888 D_L39_0025F760;
typedef struct Glob_0063A888 {
    u8 pad0[0xA4];
    u8 bA4[1];
} Glob_0063A888;

extern Glob_0063A888 D_001A5810;
extern void func_L39_0063ED28(void *);
extern void func_L39_0061D7F8(void *, void *);
extern void func_0038D308(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L39_00630548(void *);
extern void func_L39_0063AE10(u8 *);
extern void func_L39_0062B670(void *, s32, s32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L01_00412E70(void *, void *, f32, f32, u8 *);
extern void func_L39_00648258();
extern void func_L39_00672C00(void *, void *);

void func_L39_0063A888(u8 *g, u8 *obj, void *pos, void *rot, s32 id) {
    s32 saved[6];
    V4_0063A888 a;
    V4_0063A888 b;
    Q_0063A888 va, vb, vc;
    u8 *m;
    s32 i;
    V4_0063A888 *pa = &a;
    V4_0063A888 *pb = &b;
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
    (*(VT_0063A888 **)(g + 0x14))->f20(g);
    *(s32 *)(g + 0x2544) = id;
    func_L39_0063ED28(g);
    for (i = 0; i < 6; i++) {
        saved[i] = *(s32 *)(g + 0x478 + i * 0x50);
    }
    *(u8 **)(g + 0x2524) = obj;
    *(u16 *)(obj + 0x34) |= 8;
    func_L39_0061D7F8(g, obj);
    *(Q_0063A888 *)(*(u8 **)(g + 0x2524) + 0x10) = *(Q_0063A888 *)pos;
    *(Q_0063A888 *)(*(u8 **)(g + 0x2524) + 0xF0) = *(Q_0063A888 *)rot;
    *(Q_0063A888 *)(g + 0xA0) = *(Q_0063A888 *)pos;
    *(Q_0063A888 *)(g + 0xB0) = *(Q_0063A888 *)rot;
    m = *(u8 **)(g + 0x2524);
    func_0038D308(m + 0xC0, m + 0xF0);
    func_0038CF68(pb, *(u8 **)(g + 0x2524) + 0xE0, -3.0f);
    func_0038CF68(pa, *(u8 **)(g + 0x2524) + 0xE0, 1.0f);
    __asm__("lqc2 %0, %1" : "=j"(vc) : "m"(*(V4_0063A888 *)(g + 0xA0)));
    __asm__("lqc2 %0, %1" : "=j"(va) : "m"(a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vc));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(va) : "memory");
    __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(vb) : "j"(vb), "j"(vc));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(vb));
    if (func_003D3CB0(pa, pb, 2, *(u8 **)(g + 0x2524), 0)) {
        *(Q_0063A888 *)(g + 0xA0) = D_L39_0025F760;
    }
    *(u16 *)(*(u8 **)(g + 0x2524) + 0x34) |= 2;
    *(u8 **)(g + 0x424) = *(u8 **)(g + 0x2524);
    func_L39_00630548(g);
    func_L39_0063AE10(g);
    func_L39_0062B670(g, 0, 0);
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
    *(s32 *)(g + 0x10A0) = func_L39_005B43C8(0x96, 0xFA);
    *(s32 *)(g + 0x24AC) = 0;
    *(f32 *)(g + 0x10A4) = 0.007f;
    *(f32 *)(g + 0x10A8) = 0.3f;
    *(f32 *)(g + 0xFA0) = 1.16f;
    *(f32 *)(g + 0x2498) = 37.0f;
    *(f32 *)(g + 0x249C) = 13.0f;
    *(s32 *)(g + 0x24B4) = 11;
    func_L01_00412E70(col, pos2, *(f32 *)(g + 0xB8), 0.0f, *(u8 **)(g + 0x424));
    *(f32 *)(g + 0x132C) = 1.15f;
    if (g[0x1A14] != 0) {
        *(u8 **)(g + 0x1288) = g + 0x1100;
        *(u8 **)(g + 0x128C) = g + 0x1130;
    } else {
        *(u8 **)(g + 0x1288) = g + 0x20;
        *(u8 **)(g + 0x128C) = g + 0x60;
    }
    *(u16 *)(g + 0x1280) |= 1;
    *(void **)(g + 0x1284) = func_L39_00648258;
    *(s32 *)(g + 0x12CC) = g[0x24C9];
    *(s32 *)(g + 0x12D8) = *(s32 *)(g + 0x2544);
    *(u8 **)(g + 0x12D0) = g;
    if (D_001A5810.bA4[*(s32 *)(g + 0x2544)] == 1) {
        *(f32 *)(g + 0x1260) = -6.0f;
        *(f32 *)(g + 0x12C4) = 6.0f;
        *(s32 *)(g + 0x1268) = 0;
    }
    *(s8 *)(g + 0x24D8) = -1;
    func_L39_00672C00(ctl, g);
    *(s16 *)(g + 0x2480) = 1;
    *(s16 *)(g + 0x2510) = 4;
    *(s16 *)(g + 0x2512) = 15;
    g[0x250B] = 0xFF;
}
/* localdecomp:end func_L39_0063A888 */
