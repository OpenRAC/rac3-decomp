#include "common.h"
/* localdecomp:start func_L41_00413C98 */
#include "vu0.h"
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0xF]; u8 b30; u8 p31[3]; u16 h34; u8 p36[0x32]; s32 *vars; u8 p6C[0x3C]; u8 bA8; } M_414548;
typedef struct { s32 w0; u8 p4[4]; s32 w8[4]; s32 w18; } V_414548;
typedef struct { s32 w0; s32 w4; u8 p8[2]; u8 bA; u8 bB; } ES_414548;
typedef struct { u8 p0[0xA]; u16 hA; u8 p0C[0x14]; ES_414548 s20; } E_414548;
typedef struct { u8 b[8]; } B8_414548;
typedef struct { u32 q[8]; } __attribute__((aligned(16))) Q_414548;
extern const Q_414548 D_L41_00247710_00413C98;
extern B8_414548 D_L41_002476F8_00413C98[];
extern B8_414548 D_L41_00247700[];
extern u8 *D_L41_002487DC;
__asm__(".extern D_L41_002487DC, 16");
extern u8 D_001A5E50[];
extern s32 D_L41_002476D0;
extern s32 D_L41_00240754;
extern s32 D_001A5F78[];
extern s32 D_L41_0024145C;
extern f32 D_L41_002476D4, D_L41_002476D8, D_L41_002476DC, D_L41_002476E8, D_L41_002476F0, D_L41_002476F4;
extern s32 D_L41_002476E0, D_L41_002476E4, D_L41_002476EC;
extern u8 D_L41_002440A0[8];
extern u8 *D_L41_00248880;
__asm__(".extern D_L41_00248880, 16");
__asm__(".extern D_L41_002476D0, 4");
__asm__(".extern D_L41_002476D4, 4");
__asm__(".extern D_L41_002476D8, 4");
__asm__(".extern D_L41_002476DC, 4");
__asm__(".extern D_L41_002476E0, 4");
__asm__(".extern D_L41_002476E4, 4");
__asm__(".extern D_L41_002476E8, 4");
__asm__(".extern D_L41_002476EC, 4");
__asm__(".extern D_L41_002476F0, 4");
__asm__(".extern D_L41_002476F4, 4");
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);
extern void func_L40_004C35D0(s32, s32, void *, s32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_L39_005B24C8(s32, s32);
extern f32 func_L39_005B2510(f32, f32);
extern void func_003888C8(void *, void *, void *);
extern u8 *func_L01_004633E8(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern void func_L41_0048F968(void *, void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);

void func_L41_00413C98(M_414548 *obj) {
    V_414548 *vars = (V_414548 *)obj->vars;
    B8_414548 b20 = D_L41_002476F8_00413C98[0];
    B8_414548 b30 = D_L41_00247700[0];
    Q_414548 q40 = D_L41_00247710_00413C98;
    s32 i;
    s32 j;
    if (obj->b20 == 0) {
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
        if (func_L01_00444358(obj, -1, 0)) {
            u8 *g = D_001A5E50;
            s32 idx[2];
            vars->w0 = *(s32 *)(g + 0x128) + D_L41_002476D0;
            idx[0] = ((u8 *)obj - D_L41_002487DC) >> 8 & 0xFF;
            idx[1] = vars->w0;
            if (*(s32 *)(g + 0x170) == 0) {
                func_0014AD08(g[0x7D4] | 0x40, *(s32 *)(g + 4), -1, D_L41_00240754, 8, idx);
            }
            obj->bA8 = 0xFF;
        }
    }
    if (vars->w0 >= 0 && vars->w0 < D_001A5F78[0]) {
        vu0_v4 v;
        vu0_v4 o;
        vu0_v4 t;
        if (D_L41_0024145C == 0x29) {
            func_L40_004C35D0(0x13, 0, obj, 0);
            func_L40_004C35D0(0x14, 0, obj, 0);
        }
        if (vars->w18 > 0) {
            func_003886E8(&o, D_L41_002440A0, D_L41_002476F0 * 0.0166666675f);
            i = 0;
            j = 0;
            while ((f32)i < D_L41_002476F4) {
                u8 *m = D_L41_00248880 + (vars->w8[j] << 7);
                s32 r = func_L39_005B24C8(D_L41_002476E0, D_L41_002476E4);
                E_414548 *e;
                t.x = func_L39_005B2510(-1.0f, 1.0f);
                t.y = func_L39_005B2510(-1.0f, 1.0f);
                t.z = func_L39_005B2510(-1.0f, 1.0f);
                func_003888C8(&v, &t, m);
                vec_add_ba(&v, &v, m + 0x30);
                e = (E_414548 *)func_L01_004633E8(&v, D_L41_002476D4, D_L41_002476D8, D_L41_002476DC, D_L41_002476E8 * 210000.0f, r, &o, D_L41_002476EC, 0);
                if (e) {
                    ES_414548 *s = &e->s20;
                    e->hA = 0x5A;
                    s->w4 = 2;
                    s->bA = 0x80;
                    s->bB = e->hA;
                }
                i++;
                j++;
                if (!(j < vars->w18)) {
                    j = 0;
                }
            }
        }
        func_L41_0048F968(obj, &q40, &b30, &b20, 0xFFFF, -1, -1, 1, 0xFFFF, 0xFF, 0);
        func_003BD360(obj);
    }
}
/* localdecomp:end func_L41_00413C98 */
