#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0037E620 */
extern f32 func_0038DAB8(f32, f32);
extern u8 D_L01_001E1D70[8];
extern u8 D_L01_002B3AC0[];
extern void func_L01_0040B858(void *beam, void *numbers);

void func_L01_0037E620(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    *(f32 *)(s + 0x30) = func_0038DAB8(*(f32 *)(s + 0x30), 0.017453292f);
    func_L01_0040B858(D_L01_001E1D70, D_L01_002B3AC0);
}
/* localdecomp:end func_L01_0037E620 */

/* localdecomp:start func_L01_0037E670 */
typedef struct { u8 pad_0; u8 kind; u8 pad_2[0xEE]; } Row_0037E670;
typedef struct { u8 pad[0x160]; u8 *p160; u8 pad2[8]; u8 *p16C; } T_0037E670;
extern u8 D_001425C0[];
extern Row_0037E670 D_L01_002C5600[];
extern T_0037E670 D_L01_00221098;
extern u8 D_L01_001E1D80[8];
extern u8 D_L01_001D66B0;
extern f32 func_L01_004439C0(f32, f32);
extern s32 func_L01_00443978(s32, s32);
extern void func_L01_0040E398(void *, void *, void *, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);

void func_L01_0037E670(void) {
    f32 v[4];
    u32 colour;
    s32 i;
    s32 life;
    s32 spin;
    f32 s1;
    u8 *p;
    Row_0037E670 *row;
    Row_0037E670 *r;

    r = &D_L01_002C5600[D_001425C0[0x6F]];
    colour = 0x40FF20;
    if (r->kind == 1)
        colour = 0x404040;
    if (r->kind == 2)
        colour = 0x4080FF;
    if (r->kind == 3)
        colour = 0x404040;
    if (r->kind >= 4)
        colour = 0x808080;
    for (i = 0x27; i >= 0; i--) {
        func_L01_0040E398(v, D_L01_001E1D70, D_L01_001E1D80, func_L01_004439C0(0.0f, 0.75f));
        life = (func_L01_00443978(10, 15) * 5 + 2) / 6;
        spin = func_L01_00443978(-5, 5);
        s1 = func_L01_004439C0(0.125f, 0.5f) * 210000.0f;
        p = func_L01_004713C8(v, &D_L01_001D66B0, life, colour, spin, 0x2F, 0, s1,
                              func_L01_004439C0(0.35f, 0.75f) * 210000.0f, 0.0f, 0);
        if (p) {
            p[2] = D_L01_00221098.p160[0];
            row = &D_L01_002C5600[D_001425C0[0x6F]];
            if (row->kind == 1)
                p[2] = D_L01_00221098.p16C[1];
            row = &D_L01_002C5600[D_001425C0[0x6F]];
            if (row->kind == 2)
                p[2] = D_L01_00221098.p160[0];
            row = &D_L01_002C5600[D_001425C0[0x6F]];
            if (row->kind == 3)
                p[2] = D_L01_00221098.p16C[3];
            if (D_L01_002C5600[D_001425C0[0x6F]].kind >= 4)
                p[2] = D_L01_00221098.p16C[3];
        }
    }
}
/* localdecomp:end func_L01_0037E670 */
