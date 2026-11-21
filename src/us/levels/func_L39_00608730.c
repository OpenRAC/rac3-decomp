#include "common.h"

/* NTSC-U counterpart of func_L39_0060AE30 (src/levels/shared/L39_0060AE30.c): 5 -> 6 */
/* localdecomp:start func_L39_00608730 */
#include "vu0.h"
__asm__(".extern D_L39_00240474, 16");
__asm__(".extern D_L39_0024C288_00608730, 16");
__asm__(".extern D_L39_0024C290, 16");
__asm__(".extern D_L39_0024BB64, 16");
__asm__(".extern D_L39_0024BB65, 16");
__asm__(".extern D_L39_0024BB66, 16");
__asm__(".extern D_L39_0024BB68_00608730, 16");
__asm__(".extern D_L39_0024BB6C_00608730, 16");
__asm__(".extern D_L39_0024BB70_00608730, 16");
__asm__(".extern D_L39_0024BB74, 16");
__asm__(".extern D_L39_0024CAD0_00608730, 16");
__asm__(".extern D_L39_0024C090, 16");
__asm__(".extern D_L39_0024C298, 16");
__asm__(".extern D_001D4BE0_sda_00608730, 4");
__asm__(".extern D_001DA124_sda_00608730, 4");
__asm__(".extern D_001DA128_sda_00608730, 4");
__asm__(".extern D_001DA130_sda_00608730, 4");
typedef struct {
    s32 f0; s32 f4; s32 f8; u8 pC[4]; s32 f10; s32 f14; s32 f18; s32 f1C; s32 f20; s32 f24; s32 f28; u8 p2C[4];
    s32 f30; u8 p34[4]; s32 f38; s32 f3C; s32 f40; s32 f44; s32 f48; s32 f4C; s32 f50; s32 f54; s32 f58;
    s32 f5C; s32 f60; s32 f64; s32 f68; u8 p6C[0x28]; s32 f94; s32 f98;
} Hdr_0060AE30;
typedef struct { s32 f0; u16 f4; u8 p6[0xA]; } Tex_0060AE30;
typedef struct { s32 f0; s32 f4; s32 f8; u8 pC[4]; u8 f10[0x10]; } Obj_0060AE30;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 f24; } Env_0060AE30;

extern f32 D_L39_0024BAD0[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024BAD0, 16");
extern s32 D_L39_0024BAD8_00608730[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024BAD8_00608730, 16");
extern s32 D_001D4BE0_sda_00608730;
extern s32 D_L39_00240474;
extern s32 D_L39_0025F780_00608730[];
typedef struct { u8 p0[0x20]; s32 f20; u8 p24[0x10]; s32 f34; } G_001FC450_0060AE30;
extern G_001FC450_0060AE30 D_L39_001FC5D0;
typedef struct { u8 p0[0x2E]; s16 f2E; u8 p30[8]; unsigned long f38; } G_001FC340_0060AE30;
extern G_001FC340_0060AE30 D_L39_001FC4C0;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1288[0x30]; struct { s32 a; s32 b; } f12B8[1]; } G_001F0A00_0060AE30;
extern G_001F0A00_0060AE30 D_L39_001F0B80;
extern s32 D_001DA124_sda_00608730;
extern s32 D_001DA128_sda_00608730;
extern s32 D_001DA130_sda_00608730;
extern s32 D_L39_00274930[];
extern unsigned long D_L39_00268B40[];
extern u8 D_L39_00242E90[];
extern s32 D_L39_0024C040_00608730;
extern s32 D_L39_0024C04C;
extern s32 D_L39_0024BB04;
extern s32 D_L39_00275130[];
extern unsigned long D_L39_0024BEF0[];
extern u8 D_L39_002668C0_00608730[];
extern u8 D_L39_002669C0[];
extern u8 D_L39_002664C0[];
extern u8 D_L39_00244010[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_00244010, 16");
extern u8 D_L39_002960C0[];
extern s32 D_L39_0024CBD8_00608730;
typedef struct { s32 f0; s32 f4; } P_0060AE30;
extern P_0060AE30 D_L39_0024C288_00608730;
extern P_0060AE30 D_L39_0024C290;
extern u8 D_L39_0025D7C0[];
extern u8 D_L39_0024BB64;
extern u8 D_L39_0024BB65;
extern u8 D_L39_0024BB66;
extern f32 D_L39_0024BB68_00608730;
extern f32 D_L39_0024BB6C_00608730;
extern f32 D_L39_0024BB70_00608730;
extern f32 D_L39_0024BB74;
extern s32 D_L39_0024E3D0[];
extern f32 D_L39_0024CAD0_00608730;
extern s32 D_L39_0024C090;
extern s32 D_L39_0024C298;

extern void func_L39_0059C958(void);
extern void func_00382F90(void);
extern void func_L39_00586568(void);
extern void func_003A3BB8(void);
extern s32 func_00195AE8(void);
extern void func_L39_005C09F8(s32, s32, s32);
extern void func_L39_00589460(s32);
extern void func_00194B28(s32);
extern void func_001264E0(s32);
extern s32 func_0039B760(s32, s32);
extern void func_L39_0059E018(s32, s32, s32, s32);
extern void func_00393878(s32);
extern void func_00394F78(s32, s32, void *, s32);
extern void func_L39_0059F148(s32, s32);
extern void func_003936A8(s32, s32, s32, s32);
extern void func_003937C8(s32, s32);
extern void func_00388468(void *, s32);
extern void func_003885F0(void *, void *, s32);
extern void func_0038DA28(s32, s32, s32);
extern void func_003821E8(s32);
extern void func_00383848(void);

void func_L39_00608730(s32 a0, s32 a1) {
    s32 i;
    s32 base;
    s32 buf;
    Hdr_0060AE30 *h;
    s32 data;
    s32 tex;
    s32 m;
    s32 lights;

    {
        s32 k;
        for (k = 0; k < 1; k++) {
            D_L39_0024BAD0[k] = 1.0f;
            D_L39_0024BAD8_00608730[k] = 0;
        }
    }
    D_L39_0024CBD8_00608730 = 0x100000;
    func_L39_0059C958();
    D_L39_00240474 = D_001D4BE0_sda_00608730 = D_L39_001FC5D0.f20;
    func_00382F90();
    func_L39_00586568();
    func_003A3BB8();
    func_00195AE8();
    func_L39_005C09F8(D_L39_0025F780_00608730[6] + 0x400000,
                      D_L39_001F0B80.f12B8[D_L39_001FC4C0.f2E].a + D_L39_001F0B80.f1284, D_L39_001F0B80.f12B8[D_L39_001FC4C0.f2E].b);
    func_00195AE8();
    func_L39_00589460(6);
    func_00195AE8();
    func_00194B28(0);
    func_00195AE8();
    func_001264E0(0);
    base = func_0039B760(D_L39_0025F780_00608730[6] + 0x400000, D_L39_0025F780_00608730[6]);
    func_001264E0(0);
    func_00195AE8();
    h = (Hdr_0060AE30 *)D_L39_0025F780_00608730[6];
    buf = (s32)h + base;
    data = (s32)h + h->f8;
    lights = (s32)h + h->f4;
    tex = data + h->f5C;
    D_L39_0025F780_00608730[0x12] = buf;
    D_001DA124_sda_00608730 = h->f0;
    func_L39_0059E018(lights, h->f10, 0, (s32)h + h->f14);
    if (D_001DA124_sda_00608730 & 4) {
        Tex_0060AE30 *t = (Tex_0060AE30 *)((s32)h + h->f3C);
        s32 n = h->f38;
        D_L39_0024C04C = n;
        for (i = 0; i < n; i++) {
            m = tex + t[i].f0;
            D_L39_00274930[i] = m + ((30 - plzcw_asm(t[i].f4)) << 28);
        }
    }
    if (D_001DA124_sda_00608730 & 1) {
        func_00393878(data + h->f24);
    }
    func_00195AE8();
    if (D_001DA124_sda_00608730 & 4) {
        Obj_0060AE30 *o = (Obj_0060AE30 *)((s32)h + h->f30);
        D_L39_0024C040_00608730 = 0;
        for (i = 0; i < h->f28; i++, o++) {
            m = 0;
            if (o->f0 != 0) {
                m = data + o->f0;
            }
            if (o->f4 == 0xD54) {
                continue;
            }
            if (o->f8 != 0) {
                D_L39_00268B40[1] = 0xFFA0000000E0;
                D_L39_00268B40[0] = D_L39_001FC4C0.f38;
                D_L39_00268B40[2] = 0x0040000400004000;
                func_00394F78(m, 0, D_L39_00242E90, o->f4);
                D_L39_00275130[D_L39_0024C040_00608730 - 1] = 0xFFFC0000;
            } else {
                func_00394F78(m, (s32)h + h->f3C, o->f10, o->f4);
            }
        }
    }
    func_00195AE8();
    if (D_001DA124_sda_00608730 & 2) {
        s32 x = data + h->f18;
        D_L39_0025F780_00608730[7] = x;
        func_L39_0059F148(x, (s32)h + h->f20);
    }
    if (D_001DA124_sda_00608730 & 0x10) {
        func_003936A8((s32)h + h->f40, data + h->f60, (s32)h + h->f48, h->f44);
    }
    D_L39_0024BB04 = data + h->f64;
    func_003937C8((s32)h + h->f50, h->f4C);
    {
        unsigned long t, u;
        s32 hi;
        m = (u32)(D_L39_001FC5D0.f34 + (h->f54 << 2)) >> 8;
        hi = (u32)(D_L39_001FC5D0.f20 + h->f58) >> 8;
        t = (unsigned long)m | 0x1DB08000;
        u = ((unsigned long)hi << 37) | ((unsigned long)0xB800 << 19);
        D_L39_0024BEF0[0] = (t | u) | ((unsigned long)-1 << 63);
        D_L39_0024BEF0[1] = 0xFFA0000000E0;
        D_L39_0024BEF0[2] = 0x0040000400004000;
    }
    func_00388468(D_L39_002668C0_00608730, 0x100);
    func_00388468(D_L39_002669C0, 0x180);
    func_00388468(D_L39_002664C0, 0x400);
    func_003885F0(D_L39_002664C0, D_L39_00244010, 0x40);
    if (D_001DA124_sda_00608730 & 8) {
        D_L39_0024CBD8_00608730 -= 0x60000;
        D_001DA128_sda_00608730 = h->f68;
    }
    buf += 0x400;
    D_L39_0025F780_00608730[0x19] = buf;
    D_L39_0024C288_00608730.f0 = buf;
    buf += 0x20000;
    D_L39_0024C290.f0 = -1;
    D_L39_0024C288_00608730.f4 = 0;
    D_L39_0024C290.f4 = 0;
    func_00388468(D_L39_002960C0, 0x200);
    D_001DA130_sda_00608730 = h->f98;
    if (h->f94 != 0) {
        Env_0060AE30 *s = (Env_0060AE30 *)((s32)h + h->f94);
        u8 *b = D_L39_0025D7C0;
        *(s32 *)(b + 0x25C) = s->f0;
        *(s32 *)(b + 0x260) = s->f4;
        *(s32 *)(b + 0x264) = s->f8;
        *(s32 *)(b + 0x250) = s->fC;
        *(s32 *)(b + 0x254) = s->f10;
        *(s32 *)(b + 0x258) = s->f14;
        *(f32 *)(b + 0x228) = s->f18;
        *(f32 *)(b + 0x22C) = s->f1C;
        *(f32 *)(b + 0x238) = s->f20;
        *(f32 *)(b + 0x23C) = s->f24;
        D_L39_0024BB66 = b[0x258];
        D_L39_0024BB64 = b[0x250];
        D_L39_0024BB65 = b[0x254];
        D_L39_0024BB68_00608730 = *(f32 *)(b + 0x228);
        D_L39_0024BB6C_00608730 = *(f32 *)(b + 0x22C);
        D_L39_0024BB70_00608730 = *(f32 *)(b + 0x238);
        D_L39_0024BB74 = *(f32 *)(b + 0x23C);
        func_0038DA28(*(s32 *)(b + 0x25C), *(s32 *)(b + 0x260), *(s32 *)(b + 0x264));
        D_L39_0024E3D0[0] = 0;
        func_003821E8(0);
    }
    func_00383848();
    D_L39_0025F780_00608730[0x1A] = buf;
    D_L39_0024CAD0_00608730 = 983040.0f;
    D_L39_0024C090 = 0x3C0;
    D_L39_0024C298 = 0x7D0000;
}
/* localdecomp:end func_L39_00608730 */
