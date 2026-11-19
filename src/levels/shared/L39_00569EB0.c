#include "common.h"

/* declared by functions of L39_00569868.c, which this file was cut from */
typedef int q128_00569868 __attribute__((mode(TI)));
typedef struct { u8 pad[1120]; } Entry_00569868;
extern Entry_00569868 D_L39_0024DE80[];
extern void func_L01_003E4828(Entry_00569868 *entry, q128_00569868 *target, f32 height, s32 from_ground);
extern s32 func_0038CB00(u8 *);

/* localdecomp:start func_L39_00569EB0 */
/* the follow point's vertical update by its mode; the twin of story func_L01_003E4F20 */
#include "vu0.h"

typedef int q_00569EB0 __attribute__((mode(TI)));

typedef struct {
    q_00569EB0 pos;             /* +0x00 */
    q_00569EB0 height;          /* +0x10 */
    q_00569EB0 height_start;    /* +0x20 */
    q_00569EB0 rise_target;     /* +0x30 */
    u8 pad40[0x60 - 0x40];
    q_00569EB0 x60;             /* +0x60 */
    u8 pad70[0xD0 - 0x70];
    f32 fD0;
    u8 padD4[0xE4 - 0xD4];
    u8 mode;                    /* +0xE4 */
    u8 old_mode;
    s16 blend_frames;           /* +0xE6 */
    f32 blend_rate;             /* +0xE8 */
    f32 rise_rate;              /* +0xEC */
    f32 rise_height;            /* +0xF0 */
    s16 rise_frames;            /* +0xF4 */
    u8 padF6;
    u8 rise_tick;               /* +0xF7 */
    u8 padF8[0x10E - 0xF8];
    u8 b10E;
    s8 c10F;
} V_00569EB0;

typedef struct {
    u8 pad0[0x20];
    s16 view_ease_frames;
    u8 pad22[0x44 - 0x22];
    f32 view_ease_rate;
    u8 pad48[0x60 - 0x48];
    V_00569EB0 v;
} F_00569EB0;

typedef struct {
    q_00569EB0 position;
    u8 pad10[0x30 - 0x10];
    u8 x30[0x10];
    q_00569EB0 view_from;
    u8 pad50[0x70 - 0x50];
    F_00569EB0 *follow;
    u8 pad74[0x94 - 0x74];
    s32 player;
} C_00569EB0;

typedef struct {
    u8 pad0[0x100];
    s32 state;
    u8 pad104[0x114 - 0x104];
    f32 f114;
    u8 pad118[0x120 - 0x118];
    s16 h120;
    s16 h122;
    s16 h124;
    u8 pad126[0x128 - 0x126];
    s16 h128;
    u8 b12A;
} H_00569EB0;

typedef struct {
    q_00569EB0 x00;
    q_00569EB0 x10;
    q_00569EB0 x20;
    q_00569EB0 up;
} M_00569EB0;

typedef struct {
    u8 pad0[0x60];
    M_00569EB0 m;
    u8 padA0[0x150 - 0xA0];
    H_00569EB0 hero;
    u8 pad[0x460 - 0x150 - sizeof(H_00569EB0)];
} E_00569EB0;

__asm__(".extern D_L39_002429BC, 16");
extern s32 D_L39_002429BC;
extern s32 D_L39_0024B688;
__asm__(".extern D_L39_0024B688, 4");
extern s32 D_L39_0024B680;
__asm__(".extern D_L39_0024B680, 4");
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_L01_003E4028(void *, void *);
extern f32 func_L01_003E4428(void *, f32);
extern s32 func_L01_003E4198(void *, void *, s32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);

void func_L39_00569EB0(C_00569EB0 *cam, q_00569EB0 *out) {
    F_00569EB0 *follow = cam->follow;
    V_00569EB0 *v = &follow->v;
    E_00569EB0 *entry = &((E_00569EB0 *)D_L39_0024DE80)[cam->player];
    H_00569EB0 *hero = &entry->hero;
    M_00569EB0 *m = &entry->m;
    vu0_v4 target[2];   /* the follow point, then the hero's point */
    s32 flag;
    f32 dot;
    f32 angle;

    if (func_0038CE68(&m->x20, &m->up) < 0.999f || D_L39_002429BC != 0) {
        v->b10E = 1;
        if (D_L39_002429BC != 0) {
            v->c10F = (D_L39_0024B688 * 5 + 2) / 6;
        } else if (v->c10F <= 0) {
            v->c10F = (D_L39_0024B680 * 5 + 2) / 6;
        } else {
            v->c10F += 2;
            if (v->c10F > (D_L39_0024B680 * 5 + 2) / 6) {
                v->c10F = (D_L39_0024B680 * 5 + 2) / 6;
            }
        }
    }
    if (hero->h124 != 0 || D_L39_002429BC != 0 || (v->b10E != 0 && hero->h122 != 0)) {
        dot = func_0038CE68(v, &m->up);
        func_0038CE20(&v->height, &m->up, dot);
        v->height_start = v->height;
        *out = v->height;
        if (v->mode == 5 || v->mode == 6 || v->mode == 7 || v->mode == 3) {
            func_L01_003E4828((Entry_00569868 *)entry, &v->rise_target, 1.5f, 1);
        }
    }
    func_L01_003E4028(cam, &target[0]);
    if (hero->state == 0x76) {
        func_0038CE20(out, &m->up, func_0038CE68(v, &m->up));
        vec_sub_ab(v, v, out);
        func_0038CE20(out, &m->up, func_0038CE68(&m->up, &v->x60));
        v->height = *out;
        if (v->mode != 11) {
            v->mode = 11;
            cam->view_from = cam->position;
            {
                F_00569EB0 *f = cam->follow;
                f->view_ease_frames = 75;
                f->view_ease_rate = 1.0f / f->view_ease_frames;
            }
        }
        return;
    }
    switch (v->mode) {
    case 2:
        if (hero->state == 0x11 ||
            (hero->b12A != 0 && hero->f114 > 0.2f &&
             ((angle = func_L01_003E4428(cam, v->fD0)) < -0.01f || angle > 1.5707964f))) {
            v->mode = 1;
            v->blend_frames = 10;
            v->blend_rate = 1.0f / v->blend_frames;
        }
        flag = 0;
        if (hero->h120 != 0 && (hero->b12A == 0 || hero->h128 >= 16)) {
            flag = 1;
        } else if (func_L01_003E4198(entry, &target[1], 1) != 1) {
            flag = 1;
        } else if (func_0038CE68(&target[1], &m->up) < func_0038CEA8(&v->height)) {
            flag = 1;
        }
        if (flag) {
            *out = v->height;
            dot = func_0038CE68(&target[0], &m->up);
            func_0038CE20(&target[1], &m->up, dot);
            vec_sub_ab(v, &target[0], &target[1]);
        } else {
            func_L01_003E4198(entry, &target[1], 1);
            func_0038CE20(out, &m->up, func_0038CE68(&target[1], &m->up));
            vec_sub_ab(v, &target[1], out);
        }
        break;
    case 3:
    case 5:
    case 6:
    case 7:
        func_0038CDF8(&v->height, &v->rise_target, &v->height_start, v->rise_frames * v->rise_rate);
        if (v->rise_tick == 0 && func_L01_003FB640(cam->x30, 0x12, 0, 0.2f)) {
            v->rise_tick = 1;
            v->rise_target = v->height;
        }
        *out = v->height;
        dot = func_0038CE68(&target[0], &m->up);
        func_0038CE20(&target[1], &m->up, dot);
        vec_sub_ab(v, &target[0], &target[1]);
        if (func_0038CB00((u8 *)&v->rise_frames)) {
            if (v->mode == 9) {
                v->mode = 10;
                v->rise_frames = 25;
                v->height_start = v->height;
                func_0038CE20(&target[1], &m->up, v->rise_height);
                vec_sub_ab(&v->rise_target, &v->height_start, &target[1]);
            } else if (v->mode == 6) {
                v->mode = 7;
                v->rise_frames = 29;
                v->rise_target = v->height_start;
                v->height_start = v->height;
            } else {
                v->mode = 4;
                v->blend_frames = 20;
                v->blend_rate = 1.0f / v->blend_frames;
            }
        }
        break;
    case 8:
        *out = v->height;
        dot = func_0038CE68(&target[0], &m->up);
        func_0038CE20(&target[1], &m->up, dot);
        vec_sub_ab(v, &target[0], &target[1]);
        break;
    case 9:
    case 10:
        func_0038CE20(out, &m->up, func_0038CE68(&target[0], &m->up));
        vec_sub_ab(v, &target[0], out);
        func_0038CDF8(out, out, &v->height_start, 0.5f);
        break;
    default:
        func_0038CE20(out, &m->up, func_0038CE68(&target[0], &m->up));
        vec_sub_ab(v, &target[0], out);
        break;
    }
}
/* localdecomp:end func_L39_00569EB0 */
