/* functional: medium. Builds and runs the same flow; 270 instructions differ (stack layout, scheduling). Blocks read against asm; locals laid out as one struct for the callee buffers. */
#include "common.h"
/* localdecomp:start func_L41_00414548 */
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0xF]; u8 b30; u8 p31[3]; u16 h34; u8 p36[0x32]; s32 *vars; u8 p6C[0x3C]; u8 bA8; } M_414548;
typedef struct { s32 w0; u8 p4[4]; s32 w8[4]; s32 w18; } V_414548;
typedef struct { u8 p0[0xA]; u16 hA; u8 p0C[0x14]; s32 w20; s32 w24; u8 p28[2]; u8 b2A; u8 b2B; } E_414548;
typedef struct { u8 b[8]; } B8_414548;
typedef struct { u32 q[4]; } Q_414548;
extern Q_414548 D_L41_00247590[2];
extern B8_414548 D_L41_00247578;
extern B8_414548 D_L41_00247580;
extern u8 *D_L41_0024865C;
extern u8 D_001A5CD0[];
extern s32 D_L41_00247550;
extern s32 D_002405D4;
extern s32 D_001A5DF8;
extern s32 D_001D5BCC_sda;
extern f32 D_L41_00247554, D_L41_00247558, D_L41_0024755C, D_L41_00247568, D_L41_00247570, D_L41_00247574;
extern s32 D_L41_00247560, D_L41_00247564, D_L41_0024756C;
extern u8 D_L41_00243F20[];
extern u8 *D_L41_00248700;
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);
extern void func_L40_004C5C78(s32, s32, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_0038D000(void *, void *, void *);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern void func_L41_00491978(void *, void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);

void func_L41_00414548(M_414548 *obj) {
    V_414548 *vars = (V_414548 *)obj->vars;
    Q_414548 q40[2];
    B8_414548 b20 = D_L41_00247578;
    B8_414548 b30 = D_L41_00247580;
    q40[0] = D_L41_00247590[0];
    q40[1] = D_L41_00247590[1];
    if (obj->b20 == 0) {
        s32 i;
        vars->w0 = -1;
        obj->b20 = 1;
        obj->b30 = 0xFF;
        obj->h34 |= 0x4000;
        vars->w18 = 0;
        for (i = 0; i < 4; i++) {
            if (vars->w8[i] > 0) {
                vars->w18++;
            }
        }
    }
    if (vars->w0 == -1) {
        if (func_L01_00447490(obj, -1, 0)) {
            u8 *tab = D_L41_0024865C;
            u8 *g = D_001A5CD0;
            s32 idx[2];
            idx[0] = ((u8 *)obj - tab) >> 8 & 0xFF;
            vars->w0 = *(s32 *)(g + 0x128) + D_L41_00247550;
            idx[1] = vars->w0;
            if (*(s32 *)(g + 0x170) == 0) {
                func_0014AD08(g[0x7D4] | 0x40, *(s32 *)(g + 4), -1, D_002405D4, 8, idx);
            }
            obj->bA8 = 0xFF;
        }
    }
    if (vars->w0 >= 0 && vars->w0 < D_001A5DF8) {
        struct { u8 v[16]; u8 o[16]; u8 t[16]; } L;
        if (D_001D5BCC_sda == 0x29) {
            func_L40_004C5C78(0x13, 0, obj, 0);
            func_L40_004C5C78(0x14, 0, obj, 0);
        }
        if (vars->w18 > 0) {
            s32 i = 0;
            s32 j = 0;
            func_0038CE20(L.o, D_L41_00243F20, D_L41_00247570 * 0.020000001f);
            while ((f32)i < D_L41_00247574) {
                u8 *m = D_L41_00248700 + (vars->w8[j] << 7);
                s32 r = func_L39_005B43C8(D_L41_00247560, D_L41_00247564);
                E_414548 *e;
                f32 *v = (f32 *)L.t;
                v[0] = func_L39_005B4410(-1.0f, 1.0f);
                v[1] = func_L39_005B4410(-1.0f, 1.0f);
                v[2] = func_L39_005B4410(-1.0f, 1.0f);
                func_0038D000(L.v, L.t, m);
                {
                    f32 *a = (f32 *)L.v;
                    f32 *b = (f32 *)(m + 0x30);
                    a[0] += b[0];
                    a[1] += b[1];
                    a[2] += b[2];
                }
                e = (E_414548 *)func_L01_004669B0(L.v, D_L41_00247554, D_L41_00247558, D_L41_0024755C, D_L41_00247568 * 210000.0f, r, L.o, D_L41_0024756C, 0);
                if (e) {
                    e->hA = 0x4B;
                    e->w24 = 2;
                    e->b2A = 0x80;
                    e->b2B = *(u8 *)((u8 *)e + 0xA);
                }
                i++;
                j++;
                if (!(j < vars->w18)) {
                    j = 0;
                }
            }
        }
        func_L41_00491978(obj, q40, &b30, &b20, 0xFFFF, -1, -1, 1, 0xFFFF, 0xFF, 0);
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L41_00414548 */
