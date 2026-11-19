/* functional: high. Per-tick update of a falling/bouncing particle (object +0x10 pos, +0x20 velocity block); same reads/writes/calls/order as retail; the VU0 vadd.xyz and quad copies are written in plain C (w carried from the first operand as retail's vadd does). */
/* localdecomp:start func_L39_005C94D0 */
typedef struct { f32 x, y, z, w; } L39V4_5C94D0;
typedef struct {
    f32 x0, x4, x8, xC;
    f32 f10, f14, f18, f1C;
} L39Vel_5C94D0;
typedef struct {
    u8 p0[4];
    s32 f4;
    u8 b8;
    u8 p9;
    u8 pA[2];
    f32 fC;
    f32 pos[4] __attribute__((aligned(16)));
    L39Vel_5C94D0 v;
} L39Obj_5C94D0;

extern L39V4_5C94D0 D_L39_0025F760;
extern s32 D_L39_002429BC;
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L39_005BC330(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_0038CB00(void *);
extern void func_003CD250(void *);
extern s32 func_L01_00448CC0(f32, f32, f32, f32);

void func_L39_005C94D0(L39Obj_5C94D0 *o) {
    L39Vel_5C94D0 *v;
    f32 a, b, c, k;
    s32 neg;
    L39V4_5C94D0 newpos __attribute__((aligned(16)));
    L39V4_5C94D0 tmp __attribute__((aligned(16)));

    if (o == 0) {
        return;
    }
    v = &o->v;
    a = v->f10;
    b = v->f14;
    c = v->f18;
    neg = 0;
    if (a < 0.0f || b < 0.0f || c < 0.0f) {
        a = -a;
        neg = 1;
        b = -b;
        c = -c;
    }
    o->pos[2] = o->pos[2] - v->xC;
    v->f1C = v->f1C + 0.0f;
    o->fC = o->fC + -120.00001f;
    newpos.x = o->pos[0] + v->x0;
    newpos.y = o->pos[1] + v->x4;
    newpos.z = o->pos[2] + v->x8;
    newpos.w = o->pos[3];
    if (v->x0 != 0.0f || v->x4 != 0.0f || v->x8 != 0.0f) {
        if (func_003D3CB0(o->pos, &newpos, 6, 0, 0) != 0) {
            *(L39V4_5C94D0 *)o->pos = D_L39_0025F760;
            *(L39V4_5C94D0 *)v = (L39V4_5C94D0){0.0f, 0.0f, 0.0f, 0.0f};
            o->fC = o->fC + o->fC;
        } else {
            *(L39V4_5C94D0 *)o->pos = newpos;
            if (D_L39_002429BC != 0) {
                f32 s;
                func_L39_005BC330(o->pos, &tmp, 0);
                k = v->xC;
                if (k == 0.0f) {
                    s = 0.009072f;
                } else {
                    s = -k;
                }
                func_0038CE20(&tmp, &tmp, s);
                v->x0 = v->x0 + tmp.x;
                v->x4 = v->x4 + tmp.y;
                v->x8 = v->x8 + tmp.z;
            } else {
                k = v->xC;
                if (k == 0.0f) {
                    v->x8 = v->x8 + -0.009072f;
                } else {
                    v->x8 = v->x8 + k;
                }
            }
        }
    }
    if (v->f1C <= 0.0f || func_0038CB00((u8 *)o + 0xA) != 0 || o->fC < 0.0f || newpos.x < 0.01f ||
        newpos.y < 0.01f || newpos.z < 0.01f) {
        func_003CD250(o);
        return;
    }
    if (neg == 0) {
        a += -0.012f;
        if (a < 0.0f) {
            a = 0.0f;
        }
        b += -0.036012f;
        if (b < 0.0f) {
            b = 0.0f;
        }
    } else {
        b += -0.012f;
        if (b < 0.0f) {
            b = 0.0f;
        }
        a += -0.036012f;
        if (a < 0.0f) {
            a = 0.0f;
        }
    }
    c += -0.06f;
    if (c < 0.0f) {
        c = 0.0f;
    }
    v->f1C = v->f1C + 0.0f;
    if (v->f1C < 0.0f) {
        v->f1C = 0.0f;
    }
    o->f4 = func_L01_00448CC0(a, b, c, v->f1C);
    if (neg > 0) {
        v->f10 = -a;
        v->f14 = -b;
        v->f18 = -c;
    } else {
        v->f10 = a;
        v->f14 = b;
        v->f18 = c;
    }
    o->b8 = o->b8 - 1;
}
/* localdecomp:end func_L39_005C94D0 */
