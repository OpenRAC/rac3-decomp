#include "common.h"

/* NTSC-U counterpart of func_L23_003A31D8 (src/levels/23_holostar_studios_clank/L23_003A2068.c): 60 Hz timers (600/1200, 1800 for 500/1000, 1500) */
/* localdecomp:start func_L23_003A1A20 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0xC]; s32 iC; u8 pad10[0x1C - 0x10]; s32 i1C; f32 f20; f32 f24;
    u8 pad28[0x44 - 0x28]; s32 i44; u8 pad48[0x50 - 0x48]; s32 i50; s32 i54; s32 i58; s32 i5C;
    u8 pad60[0x68 - 0x60]; s32 i68; u8 pad6C[4]; f32 pos[4];
    u8 pad80[0x90 - 0x80]; s32 i90; s32 i94; s32 i98; u8 pad9C[0xD0 - 0x9C]; s32 iD0[36];
    s32 i160; s32 i164; s32 i168; s32 i16C;
} Vars_003A31D8;
typedef struct { u8 pad[0x24]; s32 i24; u8 pad28[0x6C - 0x28]; s32 i6C; u8 pad70[6]; s16 h76; u8 pad78[0x94 - 0x78]; s32 i94; s16 h98; u8 pad9A[4]; s16 h9E; } G_003A31D8;
extern u8 D_001A4C60[];
extern u8 *D_L23_001DF1DC;
__asm__(".extern D_L23_001DF1DC, 16");
extern G_003A31D8 D_001CCFD0;
extern s32 func_0037E0F0(void *, s32, s32);
extern s32 func_L01_00442998(s32, s32, s32);
extern f32 func_L01_0040C040(void *, void *);
extern s32 func_00388398(void *);
extern s32 func_0037E208(s32, s32);
extern void func_0039DAE0(s32, s32);
extern void func_0039C710(void);

void func_L23_003A1A20(u8 *a0)
{
    Vars_003A31D8 *v = *(Vars_003A31D8 **)(a0 + 0x68);
    s32 r;
    s32 t;
    f32 d;

    if (a0[0x95] == 1) {
        if (v->i164 == 0x12) {
            if (v->i168 != 1 && v->i164 != 1) v->i160 = 1;
            v->i164 = -1;
        }
        if ((u32)(v->i164 - 0x1D) < 5) {
            if (v->i168 != 0 && v->i164 != 0) v->i160 = 0;
            v->i164 = -1;
        }
        if (v->i50 >= 0 && func_0037E0F0(D_001A4C60, v->i50, 0) != 0) {
            if (v->i168 != 2 && v->i164 != 2) v->i160 = 2;
            v->i50 = -1;
        }
        if (v->i54 >= 0 && func_0037E0F0(D_001A4C60, v->i54, 0) != 0) {
            if (v->i168 != 3 && v->i164 != 3) v->i160 = 3;
            v->i54 = -1;
        }
        if (v->i58 >= 0 && func_0037E0F0(D_001A4C60, v->i58, 0) != 0 && func_L01_00442998(v->i94, -1, 0) == 0) {
            if (v->i168 != 7 && v->i164 != 7) v->i160 = 7;
            v->i58 = -1;
        }
        if (v->i5C >= 0 && func_0037E0F0(D_001A4C60, v->i5C, 0) != 0) {
            if (v->i168 != 0x14 && v->i164 != 0x14) v->i160 = 0x14;
            v->i5C = -1;
        }
        if (v->i98 >= 0 && func_L01_00442998(v->i98, -1, 0) == 0) {
            if (v->i168 != 6 && v->i164 != 6) v->i160 = 6;
            v->i98 = -1;
        }
        if (v->i90 >= 0 && func_L01_00442998(v->i90, -1, 0) == 0) {
            if (v->i168 != 0x1C && v->i164 != 0x1C) v->i160 = 0x1C;
            v->i90 = -1;
        }
        if (func_L01_0040C040(D_001A4C60, v->pos) > 2.0f) {
            *(u128_t *)v->pos = *(u128_t *)D_001A4C60;
            v->i68 = func_0037E208(600, 1200);
        } else if (func_00388398(&v->i68) != 0) {
            r = func_0037E208(0xE, 0xF);
            if (r != v->i168 && r != v->i164) v->i160 = r;
            v->i68 = 1800;
        }
        if (v->i44 >= 0 && func_0037E0F0(D_001A4C60, v->i44, 0) != 0) {
            if (v->i168 != 0x17 && v->i164 != 0x17) v->i160 = 0x17;
            v->i44 = -1;
        }
    } else if (a0[0x95] == 2) {
        if (v->i164 == 0x10) {
            if (v->i168 != 1 && v->i164 != 1) v->i160 = 1;
            v->i164 = -1;
        }
        if ((u32)(v->i164 - 0x1D) < 5) {
            if (v->i168 != 0 && v->i164 != 0) v->i160 = 0;
            v->i164 = -1;
        }
        t = *(s32 *)(*(u8 **)(D_L23_001DF1DC + v->iC * 0x100 + 0x68) + 0x390);
        if (t != v->i16C) {
            if (t == 2) {
                if (v->i168 != 4 && v->i164 != 4) v->i160 = 4;
            }
            if (t == 3) {
                if (v->i168 != 0x11 && v->i164 != 0x11) v->i160 = 0x11;
            }
            if (t == 5) {
                if (v->i168 != 5 && v->i164 != 5) v->i160 = 5;
            }
            if (t == 7) {
                if (v->i168 != 0x13 && v->i164 != 0x13) v->i160 = 0x13;
            }
            v->i16C = t;
        }
        if (v->f24 <= 0.0f) {
            if (v->i168 != 0x1B && v->i164 != 0x1B) v->i160 = 0x1B;
        } else {
            d = v->f24 - v->f20;
            if (d > 0.5f && v->i1C < 5) {
                if (v->i168 != 0x1A && v->i164 != 0x1A) v->i160 = 0x1A;
                v->i1C = 5;
            } else if (d > 0.4f && v->i1C < 4) {
                if (v->i168 != 0x16 && v->i164 != 0x16) v->i160 = 0x16;
                v->i1C = 4;
            } else if (d > 0.3f && v->i1C < 3) {
                if (v->i168 != 0x15 && v->i164 != 0x15) v->i160 = 0x15;
                v->i1C = 3;
            } else if (d > 0.2f && v->i1C < 2) {
                if (v->i168 != 0x19 && v->i164 != 0x19) v->i160 = 0x19;
                v->i1C = 4;
            } else if (d > 0.4f && v->i1C < 1) {
                if (v->i168 != 0x18 && v->i164 != 0x18) v->i160 = 0x18;
                v->i1C = 1;
            }
        }
    }
    if (D_001CCFD0.i6C == 0 && D_001CCFD0.i24 == -1 && D_001CCFD0.i94 == 0) {
        if (v->i168 >= 0) {
            v->i164 = v->i168;
            v->i168 = -1;
        }
        t = v->i160;
        if (t >= 0) {
            v->i160 = -1;
            v->i168 = t;
            func_0039DAE0((v->iD0[t] & 0x3FFF) + 6000, 0);
        }
    }
    if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) {
        func_0039C710();
    }
}
/* localdecomp:end func_L23_003A1A20 */
