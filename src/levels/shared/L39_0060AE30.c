#include "common.h"

/* localdecomp:start func_L39_0060AE30 */
#include "vu0.h"
__asm__(".extern D_L39_002402F4, 16");
__asm__(".extern D_L39_0024C188, 16");
__asm__(".extern D_L39_0024C190, 16");
__asm__(".extern D_L39_0024BA64, 16");
__asm__(".extern D_L39_0024BA65, 16");
__asm__(".extern D_L39_0024BA66, 16");
__asm__(".extern D_L39_0024BA68, 16");
__asm__(".extern D_L39_0024BA6C, 16");
__asm__(".extern D_L39_0024BA70, 16");
__asm__(".extern D_L39_0024BA74, 16");
__asm__(".extern D_L39_0024C9D0, 16");
__asm__(".extern D_L39_0024BF90, 16");
__asm__(".extern D_L39_0024C198, 16");
__asm__(".extern D_001D4BE0_sda, 4");
__asm__(".extern D_001DA124_sda, 4");
__asm__(".extern D_001DA128_sda, 4");
__asm__(".extern D_001DA130_sda, 4");
typedef struct {
    s32 f0; s32 f4; s32 f8; u8 pC[4]; s32 f10; s32 f14; s32 f18; s32 f1C; s32 f20; s32 f24; s32 f28; u8 p2C[4];
    s32 f30; u8 p34[4]; s32 f38; s32 f3C; s32 f40; s32 f44; s32 f48; s32 f4C; s32 f50; s32 f54; s32 f58;
    s32 f5C; s32 f60; s32 f64; s32 f68; u8 p6C[0x28]; s32 f94; s32 f98;
} Hdr_0060AE30;
typedef struct { s32 f0; u16 f4; u8 p6[0xA]; } Tex_0060AE30;
typedef struct { s32 f0; s32 f4; s32 f8; u8 pC[4]; u8 f10[0x10]; } Obj_0060AE30;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 f24; } Env_0060AE30;

extern f32 D_L39_0024B9D0[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B9D0, 16");
extern s32 D_L39_0024B9D8[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B9D8, 16");
extern s32 D_001D4BE0_sda;
extern s32 D_L39_002402F4;
extern s32 D_L39_0025F680[];
typedef struct { u8 p0[0x20]; s32 f20; u8 p24[0x10]; s32 f34; } G_001FC450_0060AE30;
extern G_001FC450_0060AE30 D_001FC450;
typedef struct { u8 p0[0x2E]; s16 f2E; u8 p30[8]; unsigned long f38; } G_001FC340_0060AE30;
extern G_001FC340_0060AE30 D_001FC340;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1288[0x30]; struct { s32 a; s32 b; } f12B8[1]; } G_001F0A00_0060AE30;
extern G_001F0A00_0060AE30 D_001F0A00;
extern s32 D_001DA124_sda;
extern s32 D_001DA128_sda;
extern s32 D_001DA130_sda;
extern s32 D_L39_00274830[];
extern unsigned long D_L39_00268A40[];
extern u8 D_L39_00242D50[];
extern s32 D_L39_0024BF40;
extern s32 D_L39_0024BF4C;
extern s32 D_L39_0024BA04;
extern s32 D_L39_00275030[];
extern unsigned long D_L39_0024BDF0[];
extern u8 D_L39_002667C0[];
extern u8 D_L39_002668C0[];
extern u8 D_L39_002663C0[];
extern u8 D_L39_00243EA0[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_00243EA0, 16");
extern u8 D_L39_00295FC0[];
extern s32 D_L39_0024CAD8;
typedef struct { s32 f0; s32 f4; } P_0060AE30;
extern P_0060AE30 D_L39_0024C188;
extern P_0060AE30 D_L39_0024C190;
extern u8 D_L39_0025D6C0[];
extern u8 D_L39_0024BA64;
extern u8 D_L39_0024BA65;
extern u8 D_L39_0024BA66;
extern f32 D_L39_0024BA68;
extern f32 D_L39_0024BA6C;
extern f32 D_L39_0024BA70;
extern f32 D_L39_0024BA74;
extern s32 D_L39_0024E2D0[];
extern f32 D_L39_0024C9D0;
extern s32 D_L39_0024BF90;
extern s32 D_L39_0024C198;

extern void func_L39_0059DDB0(void);
extern void func_00387268(void);
extern void func_L39_005872D8(void);
extern void func_003A9108(void);
extern s32 func_001959F8(void);
extern void func_L39_005C2A40(s32, s32, s32);
extern void func_L39_0058A5D0(s32);
extern void func_00194A38(s32);
extern void func_001264E0(s32);
extern s32 func_003A0760(s32, s32);
extern void func_L39_0059FC80(s32, s32, s32, s32);
extern void func_00398668(s32);
extern void func_00399D68(s32, s32, void *, s32);
extern void func_L39_005A0DB0(s32, s32);
extern void func_00398498(s32, s32, s32, s32);
extern void func_003985B8(s32, s32);
extern void func_0038CBA0(void *, s32);
extern void func_0038CD28(void *, void *, s32);
extern void func_00392260(s32, s32, s32);
extern void func_003864C0(s32);
extern void func_00387EF0(void);

void func_L39_0060AE30(s32 a0, s32 a1) {
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
            D_L39_0024B9D0[k] = 1.0f;
            D_L39_0024B9D8[k] = 0;
        }
    }
    D_L39_0024CAD8 = 0x100000;
    func_L39_0059DDB0();
    D_L39_002402F4 = D_001D4BE0_sda = D_001FC450.f20;
    func_00387268();
    func_L39_005872D8();
    func_003A9108();
    func_001959F8();
    func_L39_005C2A40(D_L39_0025F680[6] + 0x400000,
                      D_001F0A00.f12B8[D_001FC340.f2E].a + D_001F0A00.f1284, D_001F0A00.f12B8[D_001FC340.f2E].b);
    func_001959F8();
    func_L39_0058A5D0(5);
    func_001959F8();
    func_00194A38(0);
    func_001959F8();
    func_001264E0(0);
    base = func_003A0760(D_L39_0025F680[6] + 0x400000, D_L39_0025F680[6]);
    func_001264E0(0);
    func_001959F8();
    h = (Hdr_0060AE30 *)D_L39_0025F680[6];
    buf = (s32)h + base;
    data = (s32)h + h->f8;
    lights = (s32)h + h->f4;
    tex = data + h->f5C;
    D_L39_0025F680[0x12] = buf;
    D_001DA124_sda = h->f0;
    func_L39_0059FC80(lights, h->f10, 0, (s32)h + h->f14);
    if (D_001DA124_sda & 4) {
        Tex_0060AE30 *t = (Tex_0060AE30 *)((s32)h + h->f3C);
        s32 n = h->f38;
        D_L39_0024BF4C = n;
        for (i = 0; i < n; i++) {
            m = tex + t[i].f0;
            D_L39_00274830[i] = m + ((30 - plzcw_asm(t[i].f4)) << 28);
        }
    }
    if (D_001DA124_sda & 1) {
        func_00398668(data + h->f24);
    }
    func_001959F8();
    if (D_001DA124_sda & 4) {
        Obj_0060AE30 *o = (Obj_0060AE30 *)((s32)h + h->f30);
        D_L39_0024BF40 = 0;
        for (i = 0; i < h->f28; i++, o++) {
            m = 0;
            if (o->f0 != 0) {
                m = data + o->f0;
            }
            if (o->f4 == 0xD54) {
                continue;
            }
            if (o->f8 != 0) {
                D_L39_00268A40[1] = 0xFFA0000000E0;
                D_L39_00268A40[0] = D_001FC340.f38;
                D_L39_00268A40[2] = 0x0040000400004000;
                func_00399D68(m, 0, D_L39_00242D50, o->f4);
                D_L39_00275030[D_L39_0024BF40 - 1] = 0xFFFC0000;
            } else {
                func_00399D68(m, (s32)h + h->f3C, o->f10, o->f4);
            }
        }
    }
    func_001959F8();
    if (D_001DA124_sda & 2) {
        s32 x = data + h->f18;
        D_L39_0025F680[7] = x;
        func_L39_005A0DB0(x, (s32)h + h->f20);
    }
    if (D_001DA124_sda & 0x10) {
        func_00398498((s32)h + h->f40, data + h->f60, (s32)h + h->f48, h->f44);
    }
    D_L39_0024BA04 = data + h->f64;
    func_003985B8((s32)h + h->f50, h->f4C);
    {
        unsigned long t, u;
        s32 hi;
        m = (u32)(D_001FC450.f34 + (h->f54 << 2)) >> 8;
        hi = (u32)(D_001FC450.f20 + h->f58) >> 8;
        t = (unsigned long)m | 0x1DB08000;
        u = ((unsigned long)hi << 37) | ((unsigned long)0xB800 << 19);
        D_L39_0024BDF0[0] = (t | u) | ((unsigned long)-1 << 63);
        D_L39_0024BDF0[1] = 0xFFA0000000E0;
        D_L39_0024BDF0[2] = 0x0040000400004000;
    }
    func_0038CBA0(D_L39_002667C0, 0x100);
    func_0038CBA0(D_L39_002668C0, 0x180);
    func_0038CBA0(D_L39_002663C0, 0x400);
    func_0038CD28(D_L39_002663C0, D_L39_00243EA0, 0x40);
    if (D_001DA124_sda & 8) {
        D_L39_0024CAD8 -= 0x60000;
        D_001DA128_sda = h->f68;
    }
    buf += 0x400;
    D_L39_0025F680[0x19] = buf;
    D_L39_0024C188.f0 = buf;
    buf += 0x20000;
    D_L39_0024C190.f0 = -1;
    D_L39_0024C188.f4 = 0;
    D_L39_0024C190.f4 = 0;
    func_0038CBA0(D_L39_00295FC0, 0x200);
    D_001DA130_sda = h->f98;
    if (h->f94 != 0) {
        Env_0060AE30 *s = (Env_0060AE30 *)((s32)h + h->f94);
        u8 *b = D_L39_0025D6C0;
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
        D_L39_0024BA66 = b[0x258];
        D_L39_0024BA64 = b[0x250];
        D_L39_0024BA65 = b[0x254];
        D_L39_0024BA68 = *(f32 *)(b + 0x228);
        D_L39_0024BA6C = *(f32 *)(b + 0x22C);
        D_L39_0024BA70 = *(f32 *)(b + 0x238);
        D_L39_0024BA74 = *(f32 *)(b + 0x23C);
        func_00392260(*(s32 *)(b + 0x25C), *(s32 *)(b + 0x260), *(s32 *)(b + 0x264));
        D_L39_0024E2D0[0] = 0;
        func_003864C0(0);
    }
    func_00387EF0();
    D_L39_0025F680[0x1A] = buf;
    D_L39_0024C9D0 = 983040.0f;
    D_L39_0024BF90 = 0x3C0;
    D_L39_0024C198 = 0x7D0000;
}
/* localdecomp:end func_L39_0060AE30 */
