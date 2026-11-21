#include "common.h"

/* NTSC-U counterpart of func_L06_00356C80 (src/levels/shared/L06_00356C80.c): the four func_L01_00458A70 rates for 60 Hz */
/* localdecomp:start func_L06_00355F80 */
#include "vu0.h"

typedef struct {
    u8 pad_0[0xA4];
    f32 fA4;                   /* 0xA4 */
    u8 pad_A8[0x104 - 0xA8];
    s32 i104;                  /* 0x104 */
    s32 i108;                  /* 0x108 */
    u8 pad_10C[0x13C - 0x10C];
    f32 f13C;                  /* 0x13C */
    u8 pad_140[0x220 - 0x140];
    vu0_v4 home;               /* 0x220 */
    u8 pad_230[0x260 - 0x230];
    u8 *p260;                  /* 0x260 */
    u8 pad_264[0x340 - 0x264];
    s32 i340;                  /* 0x340 */
    s32 seg;                   /* 0x344 */
    f32 t;                     /* 0x348 */
    f32 speed;                 /* 0x34C */
    u8 pad_350[0x358 - 0x350];
    s32 *spline;               /* 0x358 */
    u8 pad_35C[0x364 - 0x35C];
    s32 i364;                  /* 0x364 */
    f32 f368;                  /* 0x368 */
    s32 i36C;                  /* 0x36C */
    u8 pad_370[0x384 - 0x370];
    s32 i384;                  /* 0x384 */
    u8 pad_388[0x394 - 0x388];
    s32 stuck;                 /* 0x394 */
    u8 pad_398[0x4A0 - 0x398];
    vu0_v4 end;                /* 0x4A0 */
} Vars_00355F80;
typedef struct {
    u8 pad_0[0x10];
    vu0_v4 pos;                /* 0x10 */
    u8 pad_20[0x43 - 0x20];
    u8 b43;                    /* 0x43 */
    u8 pad_44[0x48 - 0x44];
    f32 f48;                   /* 0x48 */
    u8 pad_4C[0x68 - 0x4C];
    Vars_00355F80 *vars;         /* 0x68 */
    u8 pad_6C[0x95 - 0x6C];
    u8 b95;                    /* 0x95 */
} Moby_00355F80;

extern int func_L01_00452EC8_00355F80(u8 *);
extern void func_L01_00472C40_00355F80(s32 *, f32 *, s32 *, f32 *, s32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_L06_00352120_00355F80(Vars_00355F80 *, s32, s32, void *);
extern void func_003886C0(void *, void *, void *, f32);
extern f32 func_00388800(void *, void *);
extern void func_L06_00457BC0_00355F80(void *, void *, void *, void *);
extern f32 func_L06_00457C58_00355F80(void *, s32, f32, s32, f32);
extern void func_L06_00350AC8_00355F80(u8 *, u8 *, s32);
extern f32 func_00388730(void *, void *);
extern void func_L01_00458A70_00355F80(void *, f32, f32, f32, f32);
extern void func_L06_00350D70_00355F80(u8 *, u8 *, s32);
extern f32 func_00388A28(f32 a, f32 b);
extern f32 func_00389380(f32, f32);
extern void func_L01_00457590_00355F80(void *, void *, f32);
extern f32 func_L01_0040C040_00355F80(void *, void *);
extern void func_L01_00441FB8_00355F80(u8 *, int, int);
extern void func_L06_00352510_00355F80(void *, s32 *, s32, f32);
extern int func_L06_003502D8_00355F80(u8 *, u8 *, u8 *);
extern s32 func_L06_00350528_00355F80(u8 *, u8 *);
extern void func_L06_00350D10_00355F80(u8 *, u8 *, s32);
extern void func_L06_00350C38_00355F80(u8 *, u8 *, int, int, int);

s32 func_L06_00355F80(Moby_00355F80 *moby)
{
    Vars_00355F80 *vars = moby->vars;
    vu0_v4 dir;
    vu0_v4 pt;
    vu0_v4 near;
    vu0_v4 ahead;
    vu0_v4 start;
    vu0_v4 to_pt;
    vu0_v4 to_home;
    s32 seg;
    f32 t;
    f32 lim;
    f32 f;
    f32 dot;
    f32 mix;
    f32 step;
    f32 here;
    f32 speed;

    start = moby->pos;
    if (func_L01_00452EC8_00355F80((u8 *)moby))
        vars->stuck = 0;
    if (vars->speed < 0.0f) {
        lim = -5.0f;
        if (lim < vars->speed)
            lim = vars->speed;
    } else {
        lim = 5.0f;
        if (vars->speed < lim)
            lim = vars->speed;
    }
    seg = vars->seg;
    t = vars->t;
    func_L01_00472C40_00355F80(vars->spline, &pt.x, &seg, &t, vars->i340, lim);
    vec_sub_ab(&dir, &pt, &moby->pos);
    dir.z = 0.0f;
    func_00388830(&dir, &dir, 1.0f);
    if (func_L06_00352120_00355F80(vars, 0.0f <= vars->speed, seg, &near)) {
        pt = near;
    } else if (vars->i36C != 0) {
        f = fabs_asm(vars->speed);
        if (f < 20.0f) {
            if (f < 10.0f) {
                pt = vars->end;
            } else {
                mix = (f - 10.0f) / 10.0f;
                if (1.0f < mix)
                    mix = 1.0f;
                else if (mix < 0.0f)
                    mix = 0.0f;
                func_003886C0(&pt, &vars->end, &pt, mix);
                if (func_00388800(&moby->pos, &pt) < 0.75f) {
                    pt = vars->end;
                    func_L06_00457BC0_00355F80(vars->spline, &moby->pos, &vars->seg, &vars->t);
                    vars->speed = func_L06_00457C58_00355F80(vars->spline, vars->seg, vars->t, vars->i364, vars->f368);
                }
            }
        }
    }
    if (moby->b95 == 4) {
        func_L06_00350AC8_00355F80((u8 *)moby, (u8 *)vars, 0x14);
    } else if (vars->i384 != 0) {
        vec_sub_ab(&to_pt, &pt, &moby->pos);
        func_00388830(&to_pt, &to_pt, 1.0f);
        vec_sub_ab(&to_home, &vars->home, &moby->pos);
        func_00388830(&to_home, &to_home, 1.0f);
        dot = func_00388730(&to_pt, &to_home);
        if (moby->b43 == 0x14) {
            if (dot < -0.20000000298023224f)
                func_L06_00350AC8_00355F80((u8 *)moby, (u8 *)vars, 0x15);
        } else if (moby->b43 == 0x15) {
            if (0.10000000149011612f < dot)
                func_L06_00350AC8_00355F80((u8 *)moby, (u8 *)vars, 0x14);
        } else if (dot < 0.20000000298023224f) {
            func_L06_00350AC8_00355F80((u8 *)moby, (u8 *)vars, 0x15);
        } else {
            func_L06_00350AC8_00355F80((u8 *)moby, (u8 *)vars, 0x14);
        }
    } else if (moby->b43 != 5) {
        func_L01_00458A70_00355F80(moby, 0.004166666883975267f, 0.1666666716337204f, 0.0069813174195587635f,
                          0.20943953096866608f);
        func_L06_00350D70_00355F80((u8 *)moby, (u8 *)vars, 5);
    }
    if (moby->b43 == 0x15)
        f = func_00389380(func_00388A28(pt.x - moby->pos.x, pt.y - moby->pos.y), 3.1415927410125732f);
    else
        f = func_00388A28(pt.x - moby->pos.x, pt.y - moby->pos.y);
    func_L01_00457590_00355F80(moby, &pt, f);
    *(f32 *)(vars->p260 + 0x48) = moby->f48;
    if (vars->i104 & 4)
        moby->pos.z += 0.009999999776482582f;
    if (func_L01_0040C040_00355F80(&start, &moby->pos) < 9.999999747378752e-05f)
        vars->stuck++;
    else
        vars->stuck = 0;
    if (((vars->i104 & 0xF) && (vars->i108 & 0xF)) || vars->stuck >= 0x2E) {
        if (vars->f13C < 1.0f) {
            if (0.0f < vars->speed)
                vars->speed = 0.375f;
            else
                vars->speed = -0.375f;
            vars->f13C = 0.0f;
        } else {
            func_L01_00441FB8_00355F80((u8 *)moby, 8, -1);
            return 1;
        }
    }
    func_L06_00352510_00355F80(&ahead, vars->spline, vars->seg, vars->t);
    here = func_00388730(&moby->pos, &dir);
    step = here - func_00388730(&ahead, &dir);
    if (0.0f <= step) {
        speed = vars->speed;
        if (0.0f < speed) {
            speed = speed - step;
            vars->speed = speed;
            if (speed < 0.375f)
                vars->speed = 0.375f;
        } else {
            speed = speed + step;
            vars->speed = speed;
            if (-0.375f < speed)
                vars->speed = -0.375f;
            step = -step;
        }
        func_L01_00472C40_00355F80(vars->spline, &pt.x, &vars->seg, &vars->t, vars->i340, step);
    }
    if (vars->i384 != 0)
        func_L06_003502D8_00355F80((u8 *)moby, (u8 *)vars, (u8 *)&vars->home);
    else
        func_L06_00350528_00355F80((u8 *)moby, (u8 *)vars);
    if (vars->f13C < vars->fA4) {
        if (0.0f < vars->speed) {
            if (0.0f < vars->t) {
                vars->seg++;
                if (*vars->spline - 1 < vars->seg)
                    vars->seg = *vars->spline - 1;
                vars->t = 0.0f;
            }
        } else if (0.0f < vars->t) {
            vars->seg--;
            if (vars->seg < 0)
                vars->seg = 0;
            vars->t = 0.0f;
        }
        func_L01_00441FB8_00355F80((u8 *)moby, 3, -1);
        if (vars->i384 != 0)
            func_L06_00350D10_00355F80((u8 *)moby, (u8 *)vars, 10);
        else
            func_L06_00350C38_00355F80((u8 *)moby, (u8 *)vars, 2, 0, 10);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00355F80 */
