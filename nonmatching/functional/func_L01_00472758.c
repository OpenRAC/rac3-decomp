/* functional: high. Needs vu0.h (included by the file); structure-field order verified vs the .s. */
/* localdecomp:start func_L01_00472758 */
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    s32 w0C;
    u8 b10;
    u8 b11;
    u8 b12;
    u8 b13;
    u8 b14;
    u8 b15;
    u8 b16;
    u8 b17;
    f32 f18;
    f32 f1C;
} P_00472758;

typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    s16 hA;
    f32 fC;
    vu0_v4 pos;
    P_00472758 p;
} O_00472758;

extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_L01_004451A0(f32);

void func_L01_00472758(O_00472758 *o) {
    P_00472758 *p;
    vu0_v4 v;
    vu0_v4 tmp;
    f32 fa;
    f32 fb;
    f32 fc;
    f32 fd;
    f32 t;
    f32 f;

    p = &o->p;
    fa = (f32)p->b15 * 0.0078125f;
    fb = (f32)p->b14 * 0.0078125f;
    fc = (f32)p->b16 * 0.0078125f;
    fd = (f32)p->b17 * 0.0078125f;
    v.x = p->f0;
    v.y = p->f4;
    v.z = p->f8;
    v.w = 0.0f;
    func_L01_004CAB30(&o->pos, &o->pos);
    t = 1.0f - (f32)o->hA / (f32)p->b11;
    if ((p->b13 & 1) == 0) {
        o->w4 = func_0038DBD8(0x103080, p->w0C, t) | (p->b12 << 24);
        fc = fa + (fc - fa) * t;
        o->fC = p->f18 + (p->f1C - p->f18) * t;
    } else {
        f = func_L01_004451A0(t);
        o->w4 = p->w0C | ((s32)((f32)p->b12 - (f32)p->b12 * f) << 24);
    }
    if ((p->b13 & 2) == 0) {
        fd = fd + fc;
        func_0038CE20(&tmp, &v, fc);
        vec_add_ab(&o->pos, &o->pos, &tmp);
        if (fd <= fb) {
            p->b17 = (s32)(fd * 128.0f);
        } else {
            p->b13 = p->b13 | 2;
            func_0038CE20(&tmp, &v, fb - fd);
            vec_add_ba(&o->pos, &o->pos, &tmp);
        }
    }
    o->b8 = o->b8 + p->b10;
    if (func_0038CB00(&o->hA) != 0) {
        if ((p->b13 & 1) == 0) {
            p->b13 = p->b13 | 1;
            p->b11 = 17;
            o->hA = 17;
        } else {
            func_003CD250((Obj *)o);
        }
    }
}
/* localdecomp:end func_L01_00472758 */
