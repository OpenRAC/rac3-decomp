/* functional: medium. 262 byte diffs are codegen/stack layout; the 0x90-byte quad descriptor (verts 0x40, colours 0x10, UVs 0x20, GS regs 0x70..0x88) and the 4x4 matrix at +0x90 are laid out as retail; GS-register values and constants read straight from the asm. */
#include "common.h"
extern f32 D_001DFDF4_sda;
__asm__(".extern D_001DFDF4_sda, 4");
extern s32 D_001DFDF0_sda;
__asm__(".extern D_001DFDF0_sda, 4");
extern s32 D_001DFE00_sda;
__asm__(".extern D_001DFE00_sda, 4");
extern f32 D_001DFDF8_sda;
__asm__(".extern D_001DFDF8_sda, 4");
extern f32 D_001DFDFC_sda;
__asm__(".extern D_001DFDFC_sda, 4");
extern s32 D_00241118[];
extern f32 D_0024DE80[];
extern f32 D_00472610[];
extern f32 D_003CD7A0[];
extern u8 D_00473830[];
extern s16 D_00474740[];
extern f32 D_00474140[];
long func_L39_00589890(s32);
void func_003A9440(s32, unsigned long);
void func_0038CF68(void *, void *, f32);
void func_0038CE20(void *, void *, f32);
void func_0038CE90(void *, void *, void *);
void func_0038C750(void);
void func_0038D028(void *, void *, void *);
void func_003D3A24(s32, void *, void *, void *, s32);
void func_003D2DA0(void *, void *, s32);

void func_L39_005640A0(u8 *obj) {
    u8 *st = *(u8 **)(obj + 0x68);
    u8 quad[0x90];
    f32 m[4][4];
    f32 d[4];
    f32 e[4];
    f32 tmp[4];
    s32 cols[290];
    s32 c;
    s32 i, j, k;
    f32 f21, f22;
    f32 *tv;
    f32 *uv;

    *(long *)(quad + 0x78) = func_L39_00589890(D_001DFDF0_sda);
    *(long *)(quad + 0x80) = 0xFF9000000260L;
    *(long *)(quad + 0x88) = 0x8000000044L;
    *(long *)(quad + 0x70) = 0;
    func_003A9440(0x47, 0x53001);
    m[3][0] = *(f32 *)(st + 0x30);
    m[3][1] = *(f32 *)(st + 0x34);
    m[3][2] = *(f32 *)(st + 0x38);
    m[3][3] = 1.0f;
    tv = D_0024DE80 + D_00241118[0] * 0x118;
    d[0] = tv[0] - m[3][0];
    d[1] = tv[1] - m[3][1];
    d[2] = tv[2] - m[3][2];
    d[3] = tv[3];
    func_0038CF68(m[0], d, 1.0f);
    func_0038CE20(e, *(u8 **)(st + 0x40) + 0x250, -1.0f);
    func_0038CE90(m[1], m[0], e);
    func_0038CF68(m[1], m[1], 1.0f);
    func_0038CE90(m[2], m[1], m[0]);
    func_0038CE20(m[0], m[0], D_001DFDF4_sda);
    func_0038CE20(m[1], m[1], D_001DFDF4_sda);
    func_0038CE20(m[2], m[2], D_001DFDF4_sda);
    c = D_001DFE00_sda | *(s32 *)(st + 0x8);
    *(s32 *)(quad + 0x40) = c;
    *(s32 *)(quad + 0x4C) = c;
    *(s32 *)(quad + 0x48) = c;
    *(s32 *)(quad + 0x44) = c;
    func_003A9440(6, func_L39_00589890(D_001DFDF0_sda));
    func_003A9440(0x42, 0x8000000044UL);
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(0x4A, 0);
    func_0038C750();
    for (k = 0; k < 290; k++) {
        func_0038D028(tmp, D_00472610 + k * 4, m);
        D_003CD7A0[k * 3 + 0] = tmp[0];
        D_003CD7A0[k * 3 + 1] = tmp[1];
        D_003CD7A0[k * 3 + 2] = tmp[2];
        cols[k] = *(s32 *)(quad + 0x40);
    }
    func_003D3A24(0x94, D_003CD7A0, cols, D_00473830, 1);
    func_003D3A24(0x6D, (u8 *)D_003CD7A0 + 0x6D8, &cols[146], D_00473830 + 0x490, 1);
    func_003D3A24(0x24, (u8 *)D_003CD7A0 + 0xBE8, &cols[254], D_00473830 + 0x7F0, 1);
    *(long *)(quad + 0x78) = func_L39_00589890(0xB);
    *(long *)(quad + 0x88) = 0x8000000048L;
    f21 = D_001DFDF8_sda;
    c = *(s32 *)(st + 0x8) | 0x40000000;
    f22 = f21 * D_001DFDFC_sda;
    *(s32 *)(quad + 0x4C) = 0;
    *(s32 *)(quad + 0x40) = c;
    *(s32 *)(quad + 0x44) = c;
    *(s32 *)(quad + 0x48) = 0;
    for (i = 0; i < 32; i++) {
        for (j = 0; j < 4; j++) {
            s32 idx = D_00474740[i * 4 + j];
            func_0038CE20(quad + j * 0x10, D_00474140 + idx * 4, j < 2 ? f22 : f21);
        }
        uv = (f32 *)(quad + 0x50);
        uv[0] = 0.5f;
        uv[1] = 0.5f;
        uv[2] = 0.5f;
        uv[3] = 0.5f;
        uv[4] = 0.5f;
        uv[5] = 1.0f;
        uv[6] = 0.5f;
        uv[7] = 1.0f;
        func_003D2DA0(quad, m, 0);
    }
}
