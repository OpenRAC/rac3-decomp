#include "common.h"

typedef int Quad_3B4FB0 __attribute__((mode(TI)));
typedef struct Vars_3B4FB0 {
    s32 w0;
    f32 f4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
} Vars_3B4FB0;
typedef struct Rec_3B4FB0 {
    u8 pad0[0x10];
    f32 e10[4];
    f32 e20[4];
    Quad_3B4FB0 pos;
    u8 pad40[0x40];
} Rec_3B4FB0;

/* localdecomp:start func_L11_003B4870 */
#include "vu0.h"

typedef struct Vars_3B4870 {
    s32 idx;
    f32 alpha;
    s32 count;
    s32 on;
    f32 angle;
    s32 snd;
    s32 total;
    u8 rgb[4];
    s32 pad20;
    s32 evOff;
    s32 evOn;
} Vars_3B4870;

typedef struct Snd_3B4870 {
    u8 pad0[0xD0];
    u8 active;
    u8 padD1[0xB];
    u8 *owner;
} Snd_3B4870;

extern u8 D_L11_001E15C0[];
extern u8 *D_L11_001DEF00;
__asm__(".extern D_L11_001DEF00, 16");
extern u8 D_001A4C60[];
extern u8 D_001A30B0[];
extern void func_L11_003B4FB0(void *);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L01_004561B8(void *);
extern void func_003A4F28(s32);
extern s32 func_L01_00456250(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00456500(void *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L03_003A51E0_003B4870(vu0_v4 *, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_0046B458(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern void func_L01_004048D0_003B4870(void *, void *);
extern void func_L03_003A5388_003B4870(void *);

void func_L11_003B4870(u8 *obj) {
    Vars_3B4870 *vars = *(Vars_3B4870 **)(obj + 0x68);
    s32 light;
    s32 dark;
    f32 fade;
    s32 n;
    vu0_v4 pos;
    vu0_v4 tgt;
    vu0_v4 vel;
    vu0_v4 r;

    dark = 0x80000000 | (vars->rgb[2] << 16) | (vars->rgb[1] << 8) | vars->rgb[0];
    light = 0x60000000 | ((vars->rgb[2] + 32) << 16) | ((vars->rgb[1] + 32) << 8) | (vars->rgb[0] + 32);
    if (obj[0x20] == 0) {
        func_L11_003B4FB0(obj);
    }
    if (obj[0x95] == 0) {
        return;
    }
    fade = 0.0f;
    if (obj[0x20] != 1) {
        f32 dist;
        vec_sub_ab(&pos, obj + 0x10, D_L11_001E15C0 + 0x140);
        dist = func_L01_0040E548(obj + 0x10, D_001A4C60);
        if (dist < 2304.0f) {
            u8 *hero = D_L11_001E15C0;
            if (*(f32 *)(hero + 0x160) * pos.x + *(f32 *)(hero + 0x164) * pos.y > 0.0f) {
                fade = 1.0f - (dist - 576.0f) / 1728.0f;
                /* MAX(MIN(fade, 1), 0), expanded */
                fade = ((fade > 1.0f ? 1.0f : fade) < 0.0f) ? 0.0f : (fade > 1.0f ? 1.0f : fade);
            }
        }
    }
    switch (obj[0x20]) {
    case 1:
        if (func_L01_004561B8(obj) != 0) {
            s32 h = vars->snd;
            if (h >= 0 && ((Snd_3B4870 *)(D_001A30B0 + h * 128))->owner == obj) {
                func_003A4F28(h);
            }
            vars->snd = -1;
        }
        if (vars->total == -1) {
            return;
        }
        vars->alpha = (vars->alpha - 0.1f < 0.0f) ? 0.0f : vars->alpha - 0.1f; /* MAX(alpha - 0.1, 0) */
        vars->count = 0;
        if (vars->on == 0 || func_L01_00456250(obj) == 0) {
            func_L01_004450F0(obj, 3, -1);
        }
        if (vars->evOff != -1 && func_L01_00456500(D_001A4C60, vars->evOff) != 0) {
            vars->on = 0;
            func_L01_004450F0(obj, 3, -1);
        }
        break;
    case 2:
        func_L01_004561B8(obj);
        {
            s32 h = vars->snd;
            if (h == -1 || ((Snd_3B4870 *)(D_001A30B0 + h * 128))->owner != obj) {
                vars->snd = func_003A52A0(1, 4, obj);
            }
        }
        vars->alpha = (vars->alpha + 0.05f > 1.0f) ? 1.0f : vars->alpha + 0.05f; /* MIN(alpha + 0.05, 1) */
        vars->count = vars->total;
        if (vars->on > 0 || func_L01_00456250(obj) > 0) {
            func_L01_004450F0(obj, 1, -1);
        }
        if (vars->evOn != -1 && func_L01_00456500(D_001A4C60, vars->evOn) != 0) {
            vars->on = 1;
            func_L01_004450F0(obj, 1, -1);
        }
        n = (s32)(fade * 10.0f);
        {
            s32 i;
            for (i = 0; i < n; i++) {
                f32 s;
                func_L03_003A51E0_003B4870(&pos, vars->idx);
                *(vu0_q *)&tgt = *(vu0_q *)(D_L11_001DEF00 + vars->idx * 128 + 0x30);
                vec_sub_ab(&r, &tgt, &pos);
                vel = r;
                s = func_003824E0(0.0f, 0.2f);
                func_0038CE20(&vel, &vel, s * func_003824E0(0.0f, 0.1f));
                s = func_003824E0(0.5f, 1.0f);
                func_L01_0046B458(&pos, 0x28, 0.1f, s, dark, 0, func_00382498(-10, 10), &vel, 0.0f, 0);
            }
        }
        break;
    case 3:
        if (func_L01_004561B8(obj) != 0) {
            s32 h = vars->snd;
            if (h >= 0) {
                if (h != -1) {
                    Snd_3B4870 *e = (Snd_3B4870 *)(D_001A30B0 + h * 128);
                    if (e->owner == obj && e->active != 0) {
                        func_003A4F28(h);
                    }
                }
                vars->snd = -1;
            }
            vars->snd = func_003A52A0(0, 0, obj);
        }
        vars->alpha = 0.0f;
        vars->count++;
        if (vars->count >= vars->total) {
            vars->snd = -1;
            func_L01_004450F0(obj, 2, -1);
        }
        if (vars->on > 0 || func_L01_00456250(obj) > 0) {
            s32 h = vars->snd;
            if (h >= 0) {
                if (h != -1) {
                    Snd_3B4870 *e = (Snd_3B4870 *)(D_001A30B0 + h * 128);
                    if (e->owner == obj && e->active != 0) {
                        func_003A4F28(h);
                    }
                }
                vars->snd = -1;
            }
            func_L01_004450F0(obj, 1, -1);
        }
        n = (s32)(fade * ((f32)(vars->count * 10) * 0.5f / (vars->total != 0 ? (f32)vars->total : 3.0f)));
        {
            s32 i;
            for (i = 0; i < n; i++) {
                s32 life;
                f32 s;
                func_L03_003A51E0_003B4870(&pos, vars->idx);
                qzero(&tgt);
                life = func_00382498(20, 30);
                s = func_003824E0(0.3f, 0.8f);
                func_L01_0046B458(&pos, life, 0.08f, s, light, 0, func_00382498(-6, 6), &tgt, 0.0f, 0);
            }
        }
        break;
    }
    vars->angle += 0.05235988f;
    if (vars->angle >= 3.1415927f) {
        vars->angle -= 6.2831855f;
    }
    if (vars->alpha > 0.0f) {
        func_L01_004048D0_003B4870(func_L03_003A5388_003B4870, obj);
        *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
    } else {
        *(s32 *)(obj + 0x98) = 0;
    }
}
/* localdecomp:end func_L11_003B4870 */
