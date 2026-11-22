#include "common.h"
#include "vu0.h"


typedef struct {
    u8 pad0[0x30];
    s32 mode;
    s32 timer;
    u8 pad38[0xC];
    s16 count;
    u8 pad46[0x1A0 - 0x46];
    u8 *mobys[6];
} G_4048B0;
typedef struct {
    s16 h0;
    s16 h2;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    s32 i14;
    s32 i18;
    s32 i1C;
} P_4048B0;
extern G_4048B0 D_L23_001E5E00;
extern u8 *D_L23_002389B0[];
extern s32 D_001D545C;
__asm__(".extern D_L23_001D6AB0, 4");
extern f32 D_L23_001D6AB0;
extern f32 D_L23_001D6AB4;
extern f32 D_L23_001D6AB8;
__asm__(".extern D_L23_001D6A90, 4");
extern P_4048B0 D_L23_001D6A90 __attribute__((section(".sdata")));
__asm__(".extern D_L23_001D6B90, 4");
extern u8 *D_L23_001D6B90;
__asm__(".extern D_L23_001D6B98, 8");
extern u8 D_L23_001D6B98[8];
__asm__(".extern D_L23_001D6BD8, 8");
extern u8 D_L23_001D6BD8[8];
extern f32 D_L23_001DF000;
extern f32 D_L23_001DEFF0;
extern void func_L01_00420D88(void);
extern void func_003A04A0(void *, s32);
extern void func_003A26D0(void *);
extern void func_L01_00402560(void *, void *);
extern void func_L01_0044EB38(void *, void *, s32, s32, f32);
extern void func_L01_00421438(void *);
extern void func_L01_00402498(void *, void *);
extern void func_L23_00403E30(void *);
extern void func_L23_00403FB8(void *);
extern void func_L23_00404070(void *);
extern void func_003BDA38(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern void *func_L01_00468DC0(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_L03_0040EE18(void *, s32);
extern void func_L10_00404678(void *);

/* localdecomp:start func_L23_004048B0 */
void func_L23_004048B0(void) {
    s32 i;
    u8 *o;
    s32 t;
    s32 i2;
    s32 k;
    u8 *a;
    u8 *b;
    P_4048B0 p;
    vu0_v4 v;
    f32 f;
    s32 r;

    func_L01_00420D88();
    for (i = 0; i < D_L23_001E5E00.count; i++) {
        o = D_L23_001E5E00.mobys[i];
        if (o != 0 && *(s16 *)(o + 0xAA) == 0xE29) {
            *(u16 *)(o + 0x34) |= 0x800;
        }
        if (*(s16 *)(o + 0xAA) == 0xD54) {
            o[0x63] = 0;
            for (i2 = 0; D_L23_002389B0[i2] != 0; i2++) {
                if (D_L23_002389B0[i2][0x63] != 0) {
                    D_L23_002389B0[i2][0x63] = 1;
                }
            }
            func_003A04A0(o, 0);
            func_L01_00402560(func_003A26D0, o);
        }
        if (o == 0) {
            continue;
        }
        t = *(s16 *)(o + 0xAA);
        if (t == 0xFA0) {
            if (*(u8 **)(o + 0x68) != 0) {
                func_L01_0044EB38(o, *(u8 **)(o + 0x68) + 0xC, 0x80AAAAD2, 0x80396464, 0.061086528f);
            }
        } else if (t == 0x1DEE || t == 0x19BC) {
            func_L01_0044EB38(o, &D_L23_001D6AB0, 0x80505080, 0x80404038, 0.031997703f);
        } else if (t == 0x1977) {
            func_L01_0044EB38(o, &D_L23_001D6AB4, 0x8080AAAA, 0x80464646, 0.03781547f);
        } else if (t == 0x1766) {
            func_L01_0044EB38(o, &D_L23_001D6AB8, 0x80AAAAFF, 0x80646496, 0.11053753f);
        } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
            func_L01_00402498(func_L01_00421438, o);
        }
    }
    if (D_001D545C == 0x17) {
        if (D_L23_001E5E00.mode == 0) {
            o = D_L23_001E5E00.mobys[3];
            if (o != 0) {
                func_L23_00403E30(o);
                func_L01_00402498(func_L23_00403FB8, o);
            }
            if (D_L23_001E5E00.timer >= 0x7D0 && D_L23_001E5E00.timer < 0x7EC) {
                a = D_L23_001E5E00.mobys[0];
                p = D_L23_001D6A90;
                p.h0 = 0x14;
                p.h2 = 0xF;
                p.f4 = 0.4f;
                p.f8 = 0.2f;
                p.f10 = 0.2f;
                p.i1C = 8;
                b = D_L23_001E5E00.mobys[1];
                func_003BDA38(a, 2, &D_L23_001DEFF0);
                func_003BDA38(b, 0, &D_L23_001DF000);
                for (k = 0; k < p.i1C; k++) {
                    if (!(k & 1)) {
                        qzero(&v);
                        vec_sub_ba(&v, &D_L23_001DF000, &D_L23_001DEFF0);
                        func_00388830(&v, &v, 0.0026666669f);
                        func_003BF6A8(&v, 0.004f);
                        f = func_0037E250(p.f8, p.f4);
                        r = func_0037E208(p.h2, p.h0);
                        func_L01_00468DC0(&D_L23_001DEFF0, &v, 0x80403080, f, r, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
                    }
                    qzero(&v);
                    vec_sub_ab(&v, &D_L23_001DEFF0, &D_L23_001DF000);
                    func_00388830(&v, &v, 0.0066666673f);
                    func_003BF6A8(&v, 0.010000001f);
                    f = func_0037E250(p.f8, p.f4);
                    r = func_0037E208(p.h2, p.h0);
                    func_L01_00468DC0(&D_L23_001DF000, &v, 0x80403080, f, r, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
                }
                func_L01_00402498(func_L23_00404070, a);
            }
            if (D_L23_001E5E00.timer >= 0x82A) {
                o = D_L23_001E5E00.mobys[5];
                if (o != 0) {
                    func_L03_0040EE18(o, 0);
                    func_L03_0040EE18(o, 1);
                }
            }
        } else if (D_L23_001E5E00.mode == 1) {
            D_L23_001D6B90 = D_L23_001D6B98;
            func_L10_00404678(D_L23_001D6BD8);
        }
    }
}
/* localdecomp:end func_L23_004048B0 */
