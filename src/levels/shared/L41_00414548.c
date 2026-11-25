#include "common.h"

/* localdecomp:start func_L41_00414548 */
#include "vu0.h"
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0xF]; u8 b30; u8 p31[3]; u16 h34; u8 p36[0x32]; s32 *vars; u8 p6C[0x3C]; u8 bA8; } M_414548;
typedef struct { s32 w0; u8 p4[4]; s32 w8[4]; s32 w18; } V_414548;
typedef struct { s32 w0; s32 w4; u8 p8[2]; u8 bA; u8 bB; } ES_414548;
typedef struct { u8 p0[0xA]; u16 hA; u8 p0C[0x14]; ES_414548 s20; } E_414548;
typedef struct { u8 b[8]; } B8_414548;
typedef struct { u32 q[8]; } __attribute__((aligned(16))) Q_414548;
extern const Q_414548 D_L41_00247590;
extern B8_414548 D_L41_00247578[];
extern B8_414548 D_L41_00247580[];
extern u8 *D_L41_0024865C;
__asm__(".extern D_L41_0024865C, 16");
extern u8 D_001A5CD0[];
extern s32 D_L41_00247550;
extern s32 D_002405D4;
extern s32 D_001A5DF8[];
extern s32 D_001D5BCC_sda;
extern f32 D_L41_00247554, D_L41_00247558, D_L41_0024755C, D_L41_00247568, D_L41_00247570, D_L41_00247574;
extern s32 D_L41_00247560, D_L41_00247564, D_L41_0024756C;
extern u8 D_L41_00243F20[8];
extern u8 *D_L41_00248700;
__asm__(".extern D_L41_00248700, 16");
__asm__(".extern D_L41_00247550, 4");
__asm__(".extern D_L41_00247554, 4");
__asm__(".extern D_L41_00247558, 4");
__asm__(".extern D_L41_0024755C, 4");
__asm__(".extern D_L41_00247560, 4");
__asm__(".extern D_L41_00247564, 4");
__asm__(".extern D_L41_00247568, 4");
__asm__(".extern D_L41_0024756C, 4");
__asm__(".extern D_L41_00247570, 4");
__asm__(".extern D_L41_00247574, 4");
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
    B8_414548 b20 = D_L41_00247578[0];
    B8_414548 b30 = D_L41_00247580[0];
    Q_414548 q40 = D_L41_00247590;
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
        if (func_L01_00447490(obj, -1, 0)) {
            u8 *g = D_001A5CD0;
            s32 idx[2];
            vars->w0 = *(s32 *)(g + 0x128) + D_L41_00247550;
            idx[0] = ((u8 *)obj - D_L41_0024865C) >> 8 & 0xFF;
            idx[1] = vars->w0;
            if (*(s32 *)(g + 0x170) == 0) {
                func_0014AD08(g[0x7D4] | 0x40, *(s32 *)(g + 4), -1, D_002405D4, 8, idx);
            }
            obj->bA8 = 0xFF;
        }
    }
    if (vars->w0 >= 0 && vars->w0 < D_001A5DF8[0]) {
        vu0_v4 v;
        vu0_v4 o;
        vu0_v4 t;
        if (D_001D5BCC_sda == 0x29) {
            func_L40_004C5C78(0x13, 0, obj, 0);
            func_L40_004C5C78(0x14, 0, obj, 0);
        }
        if (vars->w18 > 0) {
            func_0038CE20(&o, D_L41_00243F20, D_L41_00247570 * 0.020000001f);
            i = 0;
            j = 0;
            while ((f32)i < D_L41_00247574) {
                u8 *m = D_L41_00248700 + (vars->w8[j] << 7);
                s32 r = func_L39_005B43C8(D_L41_00247560, D_L41_00247564);
                E_414548 *e;
                t.x = func_L39_005B4410(-1.0f, 1.0f);
                t.y = func_L39_005B4410(-1.0f, 1.0f);
                t.z = func_L39_005B4410(-1.0f, 1.0f);
                func_0038D000(&v, &t, m);
                vec_add_ba(&v, &v, m + 0x30);
                e = (E_414548 *)func_L01_004669B0(&v, D_L41_00247554, D_L41_00247558, D_L41_0024755C, D_L41_00247568 * 210000.0f, r, &o, D_L41_0024756C, 0);
                if (e) {
                    ES_414548 *s = &e->s20;
                    e->hA = 0x4B;
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
        func_L41_00491978(obj, &q40, &b30, &b20, 0xFFFF, -1, -1, 1, 0xFFFF, 0xFF, 0);
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L41_00414548 */
