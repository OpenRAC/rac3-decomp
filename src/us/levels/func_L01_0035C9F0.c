#include "common.h"

/* NTSC-U counterpart of func_L01_0035D738 (src/levels/shared/L01_0035C8D0.c) */
typedef int s128 __attribute__((mode(TI)));
extern f32 func_00388770(void *);
extern u8 D_001A4BE0[];
extern f32 func_00388770(void *);

/* localdecomp:start func_L01_0035C9F0 */
typedef struct {
    u8 a;
    u8 b;
    u8 pad[0xEE];
} Row_0035D738;

typedef struct {
    u8 pad0[0x20];
    s32 timer;   /* 0x20 */
    s32 w24;     /* 0x24 */
    s32 armed;   /* 0x28 */
    u8 pad2C[4];
    s32 delay;   /* 0x30 */
} Vars_0035D738;

typedef struct {
    u8 pad0[0x1210];
    s32 f1210;
    u8 pad1[0x16B0 - 0x1214];
    s32 f16B0;
    u8 pad2[0x25C4 - 0x16B4];
    s32 f25C4;
    u8 pad3[0x25ED - 0x25C8];
    u8 b25ED;
    u8 pad4[0x28BC - 0x25EE];
    s32 f28BC;
} G_0035D738;

extern u8 *D_001D52FC;
extern u8 D_00142617[];
extern Row_0035D738 D_L01_002C5640[];
extern f32 D_L01_002F4DBC[];
extern s32 D_L01_001DD728;

extern void func_003BDA38(void *, s32, void *);
extern void func_L01_004C3888(void *out, void *in, s32 a, s32 b, f32 c, f32 d, f32 e, f32 f);
extern s32 func_L01_004C3E68(f32 h, void *a, void *b, void *c, void *d, void *e, s32 f, s32 g);
extern s32 func_00388398(void *);
extern s32 func_L01_0050DA08(s32 item);
extern void func_L01_004E6A08(s32);
extern void func_0039FE80(s32, s32, void *);
extern s32 func_L01_0050D8F8(s32, s32);
extern s32 func_L01_003C15A8(void);
extern u8 *func_L01_003C0F78(void *, void *);
extern u8 D_001A4C60[];
extern void func_00388830(void *, void *, f32);
extern u8 *func_L01_0035D178(s128 *pos, s128 *velocity);
extern void func_L01_004E6CB0(void);
extern void func_L01_0035CDA0(u8 *glove);
extern void func_L01_004026A0_0035C9F0(void *, void *);

/* agents_glove_update: the Agents of Doom glove's update */
void func_L01_0035C9F0(u8 *glove)
{
    Vars_0035D738 *vars = *(Vars_0035D738 **)(glove + 0x68);
    f32 v[8];
    f32 *pos;
    f32 speed;
    s32 ready;
    s32 level;
    s32 i;
    u8 *pod;

    func_003BDA38(glove, 0, &v[0]);
    pos = &v[4];
    speed = 4.5f;
    if ((*(G_0035D738 *)&D_001A4BE0).f16B0 == 2) {
        speed = 11.0f;
    }
    func_L01_004C3888(pos, &v[0], 0, 0, 1.5f, speed, 0.25f, 0.0030555557f);
    ready = 1;
    vars->w24 = func_L01_004C3E68(0.0030555557f, &v[0], pos, vars, (u8 *)vars + 0x10, glove, 0, (s32)((u8 *)vars + 0x2C));
    if ((*(G_0035D738 *)&D_001A4BE0).f25C4 == 0x1D) {
        if (func_00388398(&(*(G_0035D738 *)&D_001A4BE0).f28BC) == 0) {
            ready = 0;
        }
    } else {
        (*(G_0035D738 *)&D_001A4BE0).f28BC = 0x28;
    }
    level = (D_L01_002C5640 + D_00142617[0])->b;
    if (glove[0x31] != 0) {
        D_L01_002F4DBC[0] = 0.1f;
    }
    func_00388398(&vars->delay);
    switch (glove[0x20]) {
    case 0:
        glove[0x20] = 1;
        vars->armed = 1;
        vars->w24 = 0;
    case 1:
        if (((*(s32 *)(D_001D52FC + 0x1A4) & (*(G_0035D738 *)&D_001A4BE0).f1210) ||
             ((*(s32 *)(D_001D52FC + 0x1A4) & 8) && (*(G_0035D738 *)&D_001A4BE0).f25C4 == 0x1D)) &&
            (*(G_0035D738 *)&D_001A4BE0).b25ED == 0 && ready && vars->armed != 0 && D_L01_001DD728 < 8 && vars->delay == 0) {
            if (func_L01_0050DA08(-1)) {
                func_L01_004E6A08(-1);
                glove[0x20] = 2;
                vars->timer = 0x14;
                vars->delay = 0x2D;
            } else {
                func_0039FE80(0, 0, glove);
            }
        } else if (!func_L01_0050DA08(-1) || D_L01_001DD728 >= 8) {
            if (*(s32 *)(D_001D52FC + 0x1A4) & (*(G_0035D738 *)&D_001A4BE0).f1210) {
                func_0039FE80(0, 0, glove);
            }
        }
        break;
    case 2:
        if (func_00388398(&vars->timer)) {
            func_L01_0050D8F8(-1, 1);
            if (level >= 3 && func_L01_003C15A8()) {
                for (i = 3; i >= 0; i--) {
                    if (func_L01_003C15A8()) {
                        func_L01_003C0F78(glove, D_001A4C60);
                        D_L01_001DD728++;
                    }
                }
                func_L01_004E6CB0();
                glove[0x20] = 3;
                vars->timer = 10;
            } else {
                if (func_00388770(pos) > 0.33333334f) {
                    func_00388830(pos, pos, 0.33333334f);
                }
                pod = func_L01_0035D178((s128 *)&v[0], (s128 *)pos);
                *(u8 **)(pod + 0xB8) = glove;
                func_L01_004E6CB0();
                glove[0x20] = 3;
                vars->timer = 10;
            }
        }
        break;
    case 3:
        if (func_00388398(&vars->timer)) {
            glove[0x20] = 1;
        }
        break;
    }
    func_L01_004026A0_0035C9F0(func_L01_0035CDA0, glove);
}
/* localdecomp:end func_L01_0035C9F0 */
