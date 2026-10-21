/* US draft of func_003C56E0 (rac3-uya-decomp func_003C0188, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003C56E0 */
/* VU0 j-form: each VU0 instruction is a separate non-volatile __asm__ using the "j" (VU0
   register) constraint, which needs -mvu0-use-vf0-vfN. The original build used N = 2 on every
   file (tools/text_parts.txt carries -mvu0-use-vf0-vf2 on every line); see Matching-Patterns,
   "VU0 j-form: one asm statement per instruction". */
typedef struct {
    u8 p0[7]; u8 f7; u8 p8[9]; u8 f11; u8 f12; u8 p13; u8 f14; u8 p15; u8 f16; u8 f17; u8 p18[4];
    f32 f1C; f32 f20; f32 f24; f32 f28; f32 f2C; f32 f30; f32 f34; u16 f38; u8 p3A[0x12];
    f32 f4C; f32 f50; f32 f54; u8 p58[8]; f32 f60; f32 f64; u8 p68[4]; s8 f6C; s8 f6D; s8 f6E; s8 f6F;
    u8 p70[2]; s8 f72; s8 f73; u8 p74[2]; u8 f76; u8 p77; u8 f78; u8 f79; u8 f7A; u8 p7B[5];
    f32 f80; f32 f84; f32 f88; u8 p8C[4]; f32 f90; f32 f94;
} E_3C0188;
typedef struct { u8 p0[0x1C]; f32 *f1C; } T_3C0188;
typedef struct {
    u8 p0[0x34]; u16 f34; u8 p36[0xE]; f32 f44; u8 p48[4]; f32 f4C; u8 p50[0x18]; T_3C0188 *f68; u8 p6C[0x2C]; s32 f98;
} O_3C0188;

extern s32 D_001D5BEC_003C56E0;
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_003C4E80(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_003C6368(void *, f32 *, f32 *, f32, f32, f32);
extern f32 func_0038CED8(f32 *);
extern f32 func_003C50E8(s32, s32, s32);
extern s32 func_003C6068();
extern void func_003C62C8();
extern void func_003BF4F8();
extern f32 func_0038D160(f32, f32);
extern void func_0038DAB8(f32, f32);
extern void func_0038CFB8(void);

typedef struct { f32 x, y, z, w; } V4_3C0188;
typedef int Q_3C0188 __attribute__((mode(TI)));
s32 func_003C56E0(O_3C0188 *obj, E_3C0188 *e, f32 *v, s32 mode, s32 idx) {
    u8 cc[2];
    f32 m30[4] __attribute__((aligned(16)));
    f32 m40[4] __attribute__((aligned(16)));
    f32 m50[4] __attribute__((aligned(16)));
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 ee;
    f32 f;
    f32 g;
    s32 k;
    s32 ok;
    f32 *t;

    t = obj->f68->f1C;
    if (idx != -1) {
        k = idx;
    }
    c = e->f24;
    d = e->f28;
    a = e->f1C;
    b = e->f20;
    g = e->f2C;
    if (t != 0) {
        e->f30 = *t;
        e->f34 = *t;
    }
    e->f14 = 0;
    ok = 1;
    switch (mode) {
    case 1:
    default:
        ok = 0;
        e->f7 = 0xFF;
        break;
    case 2:
        e->f7 = 0xFF;
        if (idx != -1) {
            func_003C62C8(obj, idx, &a, &b, &c, &d, &ee, &f, &g, &e->f78);
            func_003BE4F0(obj, idx, e->f78, 3);
            obj->f44 = obj->f4C;
        } else if (func_003C6068((void *)obj, 0, &k, &a, &b, &c, &d, &ee, &f, &g, &e->f78)) {
            func_003BE4F0(obj, k, e->f78, 3);
            obj->f44 = obj->f4C;
        } else if (!func_003C6068((void *)obj, 1, &k, &a, &b, &c, &d, &ee, &f, &g, &e->f78)) {
            if (e->f11 != 0xFF) {
                a *= 0.5f;
                b *= 0.5f;
                ee = e->f6C;
                f = e->f6D;
                func_003BE4F0(obj, e->f11, e->f78, 3);
                obj->f44 = obj->f4C;
            } else {
                ok = 0;
            }
        }
        break;
    case 3:
        e->f7 = 0xFF;
        if (idx != -1) {
            func_003C62C8(obj, idx, &a, &b, &c, &d, &ee, &f, &g, &e->f79);
            func_003BE4F0(obj, idx, e->f79, 3);
            obj->f44 = obj->f4C;
        } else if (func_003C6068((void *)obj, 1, &k, &a, &b, &c, &d, &ee, &f, &g, &e->f79)) {
            func_003BE4F0(obj, k, e->f79, 3);
            obj->f44 = obj->f4C;
        } else if (func_003C6068((void *)obj, 0, &k, &a, &b, &c, &d, &ee, &f, &g, &e->f79)) {
            func_003BE4F0(obj, k, e->f79, 3);
            obj->f44 = obj->f4C;
        } else if (e->f12 != 0xFF) {
            a *= 0.75f;
            b *= 0.75f;
            ee = e->f6E;
            f = e->f6F;
            func_003BE4F0(obj, e->f12, e->f79, 3);
            obj->f44 = obj->f4C;
        } else {
            ok = 0;
        }
        break;
    case 6:
        e->f7 = 0xFF;
        if (idx != -1) {
            func_003C62C8(obj, idx, &a, &b, &c, &d, &ee, &f, &g, &cc[0]);
            func_003BE4F0(obj, k, 0, 3);
            obj->f44 = obj->f4C;
        } else if (func_003C6068((void *)obj, 5, &k, &a, &b, &c, &d, &ee, &f, &g, &cc[0])) {
            func_003BE4F0(obj, k, 0, 3);
            obj->f44 = obj->f4C;
        } else {
            ok = 0;
        }
        break;
    case 4:
        e->f7 = 0xFF;
        e->f38 |= 1;
        obj->f98 = 0;
        obj->f34 &= 0xEFFF;
        if (idx != -1) {
            func_003C62C8(obj, idx, &a, &b, &c, &d, &ee, &f, &g, &e->f7A);
            func_003BE4F0(obj, k, e->f7A, 3);
            obj->f44 = obj->f4C;
        } else if (func_003C6068((void *)obj, 3, &k, &a, &b, &c, &d, &ee, &f, &g, &e->f7A)) {
            func_003BE4F0(obj, k, e->f7A, 3);
            obj->f44 = obj->f4C;
        } else if (e->f16 != 0xFF) {
            ee = e->f72;
            f = e->f73;
            func_003BE4F0(obj, e->f16, e->f7A, 3);
            obj->f44 = obj->f4C;
        } else {
            ok = 0;
        }
        break;
    case 5:
        e->f7 = 0xFF;
        e->f38 |= 2;
        obj->f98 = 0;
        obj->f34 &= 0xEFFF;
        if (idx != -1) {
            func_003C62C8(obj, idx, &a, &b, &c, &d, &ee, &f, &g, &cc[1]);
            func_003BE4F0(obj, k, 0, 3);
            obj->f44 = obj->f4C;
        } else if (func_003C6068((void *)obj, 4, &k, &a, &b, &c, &d, &ee, &f, &g, &cc[1])) {
            func_003BE4F0(obj, k, 0, 3);
            obj->f44 = obj->f4C;
        } else if (e->f17 != 0xFF) {
            a *= 1.5f;
            b *= 1.5f;
            ee = e->f72;
            f = e->f73;
            func_003BE4F0(obj, e->f17, 0, 3);
            obj->f44 = obj->f4C;
        } else {
            ok = 0;
        }
        e->f90 = 0.104719765f;
        e->f94 = 0.41887906f;
        break;
    }
    func_003BF4F8((s32)obj, (void *)e);
    if (ok) {
        if (mode != 1) {
            if (D_001D5BEC_003C56E0 != 0) {
                f32 s = func_003C50E8((s32)obj, (s32)v, 0);
                if (s < 1.0f) s = 1.0f;
                func_003C5180_003C5278((u8 *)obj + 0x10, m30, 0);
                func_0038CF68((s32)m50, (s32)v, -1.0f);
                func_003C4E80(m50, &e->f64);
                {
                    f32 t = func_0038CE68(m30, v);
                    func_0038CF68((s32)m40, (s32)m30, t);
                }
                {
                    Q_3C0188 x, y;
                    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3C0188 *)v));
                    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3C0188 *)m40));
                    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                    __asm__("sqc2 %1, %0" : "=m"(*(V4_3C0188 *)v) : "j"(x));
                }
                if (func_0038CEA8((s32)v) < 1.0f) {
                    func_0038CF68((s32)v, (s32)v, 1.0f);
                }
                func_0038CE20(&e->f80, v, a);
                func_0038CF68((s32)m40, (s32)m30, -b * s);
                {
                    Q_3C0188 x, y;
                    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3C0188 *)&e->f80));
                    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3C0188 *)m40));
                    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                    __asm__("sqc2 %1, %0" : "=m"(*(V4_3C0188 *)&e->f80) : "j"(x));
                }
            } else {
                func_003C6368(obj, v, v, 5.0f, 0.7853982f, 4.0f);
                if (func_0038CED8(v) < 1.0f) {
                    ((void (*)(f32 *, f32 *, f32))func_0038CFB8)(v, v, 1.0f);
                }
                if (v[2] < 1.0f) {
                    v[2] = 1.0f;
                }
                e->f80 = v[0] * a;
                e->f84 = v[1] * a;
                e->f88 = v[2] * b;
                e->f64 = ((f32 (*)(f32, f32))func_0038DAB8)(func_0038D160(v[0], v[1]), 3.1415901f);
            }
            if (e->f76 != 0 && mode < 4) {
                e->f4C = 0.0f;
                e->f50 = 0.0f;
                e->f54 = -1.0f;
                e->f60 = -1.0f;
            } else {
                e->f54 = ee;
                e->f60 = f;
                e->f4C = c;
                e->f50 = d;
                e->f2C = g;
            }
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003C56E0 */
