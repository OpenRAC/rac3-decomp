/* functional: medium. Draws a two-pass ribbon/beam (quad strip) from a joint of the object to its target while spawning sparks; vector values kept as quads like retail, dead stores to a local position (0x120 slot in retail) kept as an unused local */
#include "vu0.h"
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern long func_L39_00589890(s32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DB48(f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern u8 *D_002968EC[];

typedef struct {
    f32 pos[4][4];
    u32 rgba[4];
    f32 uv[4][2];
    unsigned long count;
    unsigned long tex;
    unsigned long tex0;
    unsigned long alpha;
} Quad_0052A2B8;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; } Ref_0052A2B8;
typedef struct { u8 pad0[0x23A0]; vu0_v4 tgt; } Tgt_0052A2B8;
typedef struct {
    u8 pad0[0x14]; Ref_0052A2B8 *x14; f32 x18; f32 x1C; f32 x20; Tgt_0052A2B8 *x24;
    f32 x28; s32 x2C; u32 x30;
} M_0052A2B8;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x68 - 0x20]; M_0052A2B8 *x68; } O_0052A2B8;

void func_L39_0052A2B8(O_0052A2B8 *o) {
    Quad_0052A2B8 q __attribute__((aligned(16)));
    vu0_v4 a __attribute__((aligned(16)));      /* current point (sp+0x90) */
    vu0_v4 cur __attribute__((aligned(16)));    /* sp+0xA0 */
    vu0_v4 joint __attribute__((aligned(16)));  /* sp+0xB0 */
    vu0_v4 d __attribute__((aligned(16)));      /* sp+0xC0 */
    vu0_v4 f __attribute__((aligned(16)));      /* sp+0xD0 */
    vu0_v4 g __attribute__((aligned(16)));      /* sp+0xE0 */
    vu0_v4 e __attribute__((aligned(16)));      /* sp+0xF0 */
    vu0_v4 h __attribute__((aligned(16)));      /* sp+0x100 */
    vu0_v4 w __attribute__((aligned(16)));      /* sp+0x110 */
    f32 p[3];
    f32 vel[3];
    M_0052A2B8 *m;
    Tgt_0052A2B8 *t;
    f32 width, ang, sz, len, prog, step, k, s, k2, speed, scale;
    s32 i, n, cnt;
    u8 *r;

    if (o == 0 || (m = o->x68) == 0) {
        return;
    }
    t = m->x24;
    m->x28 += 0.2f;
    if (3.0f <= m->x28) {
        m->x28 = 0;
    }
    for (i = 0; i < 2; i++) {
        if (i == 1) {
            m->x2C = 0xE;
            m->x30 = 0x3020FF20;
            width = 0.11f;
        } else {
            m->x2C = 0x45;
            m->x30 = 0x80208040;
            width = 0.05f;
        }
        q.tex = func_L39_00589890(m->x2C);
        q.rgba[0] = m->x30;
        q.rgba[1] = m->x30;
        q.rgba[2] = m->x30;
        q.rgba[3] = m->x30;
        q.count = 0;
        q.tex0 = (0xFF90L << 32) | 0x260;
        q.alpha = (0xFF00L << 24) | 0x44;
        q.uv[0][0] = m->x28 + 0.0f;
        q.uv[0][1] = 0.0f;
        q.uv[1][0] = m->x28 + 1.0f;
        q.uv[1][1] = 0.0f;
        q.uv[2][0] = m->x28 + 0.0f;
        q.uv[2][1] = 1.0f;
        q.uv[3][0] = m->x28 + 1.0f;
        q.uv[3][1] = 1.0f;
        func_003C2F58(o, 1, &joint);
        *(vu0_q *)&a = *(vu0_q *)&m->x14->pos;
        *(vu0_q *)&cur = *(vu0_q *)&a;
        ang = func_0038D160(t->tgt.x - o->pos.x, t->tgt.y - o->pos.y);
        n = (s32)func_L39_005B4468(2.0f, 5.0f);
        p[0] = o->pos.x + func_L39_005B4410(-0.01f, 0.01f);
        p[1] = o->pos.y + func_L39_005B4410(-0.01f, 0.01f);
        p[2] = o->pos.z + func_L39_005B4410(-0.01f, 0.01f);
        scale = func_L39_005B4410(0.4f, 0.6f);
        sz = func_L39_005B4410(4.5f, 6.0f);
        sz = sz * 0.020000001f;
        ang = func_0038DAB8(ang, func_L39_005B4468(0.0f, 1.3962634f));
        vel[0] = func_0038D098(ang) * sz;
        vel[1] = func_0038D0B0(ang) * sz;
        vel[2] = 0.0f;
        vel[2] = func_L39_005B4410(0.0f, 0.5f) * 0.020000001f;
        cnt = func_L39_005B43C8(15, 25);
        func_L01_004713C8(&a, vel, (cnt * 5 + 2) / 6, 0x40FF7F, n, 0x7F, 0x7F, scale * 210000.0f, 2100.0f, 0.00640000030f, 6);
        n = -(n * 2);
        cnt = func_L39_005B43C8(15, 25);
        scale = scale * 3.0f;
        r = func_L01_004713C8(&a, vel, (cnt * 5 + 2) / 6, 0xFF20, n, 0x30, 0x30, scale * 210000.0f, 4200.0f, 0.00640000030f, 0);
        if (r != 0) {
            r[2] = *D_002968EC[0];
        }
        func_003D9508(&a, 0x31, 0x2F208040, 1, 0.25f, 0.125f, 0.0f);
        prog = 0.0f;
        func_003D9508(&a, 0x31, 0x2F208040, 1, 0.4f, 0.124f, 0.0f);
        func_003D9508(&a, 0xB, 0x2F007F00, 1, 0.55f, 0.123f, 0.0f);
        vec_sub_ab(&d, &joint, &a);
        len = func_0038CEA8(&d);
        *(vu0_q *)&e = *(vu0_q *)&d;
        e.z -= 0.1f;
        func_0038CE90(&f, &d, &e);
        func_0038CE90(&g, &d, &f);
        *(vu0_q *)&q.pos[0] = *(vu0_q *)&a;
        *(vu0_q *)&q.pos[2] = *(vu0_q *)&a;
        q.pos[2][2] += width;
        q.pos[0][2] -= width;
        k = func_0038D098(func_0038DB48(m->x18));
        if (prog < len) {
            do {
                step = 0.4f;
                if (len - prog < step) {
                    step = len - prog;
                }
                prog += step;
                s = prog * 3.1415927f;
                k2 = func_0038D0B0(s / len);
                s = func_0038D0B0(func_0038DB48(s / m->x1C)) * k2;
                s = s * k;
                func_0038CF68(&d, &d, step);
                s = s * m->x20;
                vec_add_ba(&cur, &cur, &d);
                *(vu0_q *)&q.pos[3] = *(vu0_q *)&cur;
                *(vu0_q *)&q.pos[1] = *(vu0_q *)&cur;
                vec_sub_ab(&h, &t->tgt, &cur);
                func_0038CE90(&w, &h, &d);
                func_0038CF68(&w, &w, width);
                vec_add_ab(&q.pos[1], &q.pos[1], &w);
                func_0038CF68(&e, &f, s);
                vec_sub_ab(&q.pos[3], &q.pos[3], &w);
                vec_add_ab(&q.pos[1], &q.pos[1], &e);
                vec_add_ab(&q.pos[3], &q.pos[3], &e);
                func_003D2DA0(&q, 0, 1);
                *(vu0_q *)&a = *(vu0_q *)&cur;
                *(vu0_q *)&q.pos[0] = *(vu0_q *)&q.pos[1];
                *(vu0_q *)&q.pos[2] = *(vu0_q *)&q.pos[3];
            } while (prog < len);
        }
    }
}
