#include "common.h"
#include "vu0.h"

typedef struct {
    char pad0[0x10];
    vu0_v4 pos;
} S_32B630;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_32B290;
typedef struct {
    s32 ids[5];
    s32 w14;
    u8 b18;
    u8 b19;
    u8 pad1A[6];
    vu0_v4 v20;
    vu0_v4 v30;
} St_0032A4B0;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 v10;
    u8 b20;
    u8 pad21[0x13];
    u16 h34;
    u8 pad36[0x32];
    St_0032A4B0 *p68;
} Obj_0032A4B0;

/* localdecomp:start func_L05_0032ADD0 */
/* PAL port of the NTSC-U match src/us/levels/func_L05_0032A4B0.c */
#include "vu0.h"


extern u8 *D_L05_001DFB9C;
__asm__(".extern D_L05_001DFB9C, 4");
extern u8 *D_L05_001DFC80;
__asm__(".extern D_L05_001DFC80, 4");
extern vu0_v4 D_L05_001E2700;
extern void func_L05_0032B230(void *);
extern s32 func_L01_00456250(void *);
extern void func_L05_0032B630(S_32B630 *p);
extern void func_L01_00456230(void *, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_004450F0(s32, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_L05_0032B290(u8 *a0, u8 *obj, V4_32B290 *v, f32 angle);
extern void func_L05_0032B320(u8 *a0, s32 a1, s32 a2);
extern void func_003C2880(void *);

void func_L05_0032ADD0(Obj_0032A4B0 *a) {
    St_0032A4B0 *s;
    vu0_v4 w0;
    vu0_v4 w10;
    vu0_v4 w20;
    vu0_v4 w30;
    u8 *ent;
    u8 *child;
    f32 k;
    s32 i;
    s32 j;

    s = a->p68;
    func_L05_0032B230(a);
    switch (a->b20) {
    case 0:
        break;
    case 1:
        if (func_L01_00456250(a) != 0) {
            for (i = 0; i < 5; i++) {
                if (s->ids[i] != -1) {
                    child = D_L05_001DFB9C;
                    child += s->ids[i] << 8;
                    *(u16 *)(child + 0x34) |= 0x100;
                    func_L05_0032B630(child);
                    func_L01_00456230(child, 1);
                }
            }
            func_003A52A0(1, 0, a);
            func_L01_004450F0(a, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(a) != 0 && s->w14 != -1) {
            ent = (u8 *)((s->w14 << 7) + (s32)D_L05_001DFC80);
            vec_sub_ba(&s->v20, ent + 0x30, (u8 *)a + 0x10);
            s->v20.z = 0.0f;
            func_0038CF68(&s->v20, &s->v20, 1.0f);
            vec_sub_ba(&w0, &D_L05_001E2700, (u8 *)a + 0x10);
            w0.z = 0.0f;
            func_0038CF68(&w0, &w0, 1.0f);
            if (0.707f < func_0038CE68(&s->v20, &w0)) {
                func_0038CE90(&w10, &w0, &s->v20);
                w20 = (vu0_v4){0.0f, 0.0f, 0.0f, 0.0f};
                w20.z = 1.0f;
                if (0.0f < w10.z) {
                    func_0038CE90(&w30, &w20, &w0);
                } else {
                    func_0038CE90(&w30, &w0, &w20);
                }
                vec_add_ab(&s->v20, &w30, &w0);
            }
            func_0038CF68(&s->v20, &s->v20, 0.13000001f);
            func_0038CE90(&s->v30, &s->v20, (u8 *)a + 0xE0);
        }
        if (s->b18 != 0) {
        w10 = (vu0_v4){0.0f, 0.0f, 0.0f, 0.0f};
        k = 0.03316126f;
        w10.x = s->v20.x;
        w10.y = s->v20.y;
        w0 = w10;
        w10 = s->v20;
        if (15.5f < a->v10.z) {
            func_L05_0032B290(a, a, &w10, k);
            if (a->v10.z <= 19.5f && !(s->b19 & 0x20)) {
                func_L05_0032B320(a, a, 5);
            }
        }
        for (j = 0; j < 5; j++) {
            vec_add_ab(&w10, &w10, &w0);
            k = k * 0.85f;
            if (s->ids[j] != -1) {
                child = D_L05_001DFB9C + (s->ids[j] << 8);
                if (*(f32 *)(child + 0x18) <= 19.5f && (((s->b19 >> j) ^ 1) & 1)) {
                    func_L05_0032B320(a, child, j);
                }
                if (*(f32 *)(child + 0x18) <= 15.5f) {
                    if ((s->b19 >> j) & 1) {
                        s->b18 = s->b18 & ~(1 << j);
                        func_003C2880(child);
                    }
                } else {
                    func_L05_0032B290(a, child, &w10, k);
                }
            }
        }
        s->v20.z = s->v20.z - 0.00392f;
        s->v20.x = s->v20.x * 0.976f;
        s->v20.y = s->v20.y * 0.976f;
        if (s->v20.z < -0.19f) {
            s->v20.z = -0.19f;
        }
        } else {
            func_L01_004450F0(a, 3, -1);
        }
        break;
    case 3:
        func_003C2880(a);
        break;
    }
}
/* localdecomp:end func_L05_0032ADD0 */

/* localdecomp:start func_L05_0032B230 */
void func_L01_004450F0(s32, s32, s32);
void func_L05_0032B230(void *arg0) {
    s32 var_a1;
    s8 *var_v1;
    void *temp_a2;

    temp_a2 = *(void **)((u8 *)arg0 + 0x68);
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        var_a1 = 5;
        var_v1 = temp_a2 + 0x1F;
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | 0x100);
        do {
            *var_v1 = 0;
            var_a1 -= 1;
            var_v1 -= 1;
        } while (var_a1 >= 0);
        *(s8 *)((u8 *)temp_a2 + 0x18) = 0x1F;
        func_L01_004450F0((s32) arg0, 1, -1);
    }
}
/* localdecomp:end func_L05_0032B230 */

/* localdecomp:start func_L05_0032B290 */
typedef int Q_32B290 __attribute__((mode(TI)));
extern void func_0038D890(void *, void *, void *, f32);

void func_L05_0032B290(u8 *a0, u8 *obj, V4_32B290 *v, f32 angle) {
    u8 *axis = *(u8 **)(a0 + 0x68) + 0x30;
    Q_32B290 x, y, r;
    func_0038D890(obj + 0xC0, obj + 0xC0, axis, angle);
    func_0038D890(obj + 0xD0, obj + 0xD0, axis, angle);
    func_0038D890(obj + 0xE0, obj + 0xE0, axis, angle);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*v));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_32B290 *)(obj + 0x10)));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_32B290 *)(obj + 0x10)) : "j"(r));
}
/* localdecomp:end func_L05_0032B290 */

/* localdecomp:start func_L05_0032B320 */
extern s32 func_L01_004AAC98(s32, s32, s32, s32);
void func_L05_0032B3B8(u8 *);

void func_L05_0032B320(u8 *a0, s32 a1, s32 a2) {
    u8 *p;
    u8 *q;
    u8 b;

    p = *(u8 **)(a0 + 0x68);
    b = *(p + a2 + 0x1A);
    if (b >= 3) {
        p[0x19] |= 1 << a2;
    } else {
        if (b == 0) {
            func_L01_004AAC98(0, 0, a1, *(s16 *)(a0 + 0xAA));
        }
        func_L05_0032B3B8((u8 *)a1);
    }
    q = p + 0x1A;
    q[a2] += 1;
}
/* localdecomp:end func_L05_0032B320 */

/* localdecomp:start func_L05_0032B3B8 */
#include "vu0.h"
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern void func_003C4C18(void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L05_0046CA50(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32);

void func_L05_0032B3B8(u8 *o) {
    vu0_v4 v;
    vu0_v4 vel;
    vu0_v4 pos;
    vu0_v4 *pp;
    vu0_v4 *vp;
    s32 n;
    s32 cnt;
    s32 sgn;
    s32 big;
    s32 cnt2;
    s32 col;
    s32 a;
    f32 sp;
    f32 r;
    f32 f;

    *(vu0_q *)&v = *(vu0_q *)(o + 0xE0);
    func_0038CF68(&v, &v, 1.2f);
    vec_add_ba(&v, o + 0x10, &v);
    n = func_00382498(0x50, 0x6E);
    if (n > 0) {
        cnt = n;
        vp = &vel;
        pp = &pos;
        do {
            sgn = 1;
            big = 0;
            sp = func_003824E0(4.0f, 15.0f) * 0.020000001f;
            r = func_00382538();
            func_00382760(vp, sp, r, func_003824E0(0.5235988f, 1.5707964f));
            *(vu0_q *)&pos = *(vu0_q *)(o + 0xE0);
            func_0038CF68(pp, pp, func_003824E0(0.0f, 4.0f));
            func_003C4C18(pp, 0.5f);
            vec_add_ba(&pos, o + 0x10, &pos);
            pos.z -= 0.5f;
            cnt2 = (vel.z + vel.z) / 0.005f;
            if (func_00382468(2) != 0) {
                sgn = -1;
            }
            if (func_00382468(3) == 0) {
                big = func_00382498(1, 3);
            }
            a = 0x7F;
            col = 0x806060;
            f = func_003824E0(0.1f, 0.7f) * 210000.0f;
            if (big != 0) {
                f *= 0.5f;
                a = 0x60;
                col = 0x606060;
            }
            func_L05_0046CA50(pp, vp, cnt2, col, sgn, a, a, f, 21000.0f, 0.005f, big, 0);
            cnt--;
        } while (cnt != 0);
    }
}
/* localdecomp:end func_L05_0032B3B8 */

/* localdecomp:start func_L05_0032B630 */
#include "vu0.h"
typedef struct {
    char pad0[0x5C];
    u8 *f5C;
} S_220758_32B630;
extern S_220758_32B630 D_L05_00220758;
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_003C4C18(void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L05_0032B630(S_32B630 *p) {
    vu0_v4 a;
    vu0_v4 b;
    s32 n;
    s32 cnt;
    f32 s;
    s32 r;
    u8 *q;
    n = func_00382498(12, 15);
    if (n > 0) {
        cnt = n;
        do {
            a = p->pos;
            func_003C4C18(&a, 1.85f);
            vec_sub_ba(&b, &a, &p->pos);
            func_0038CF68(&b, &b, 0.0400000028f);
            func_003C4C18(&b, 0.0060000005f);
            a.z = 20.85f;
            s = func_003824E0(1.0f, 2.0f) * 210000.0f;
            r = (func_00382498(35, 60) * 5 + 2) / 6;
            q = func_L01_0046FB40(&a, &b, r, 0x40B4B4B4, func_00382468(2) != 0 ? 1 : -1, 12, 0, 0, s, s * 0.5f, 0.003f);
            if (q != 0) {
                q[2] = *D_L05_00220758.f5C;
                q[3] = 0x44;
            }
            cnt--;
        } while (cnt != 0);
    }
}
/* localdecomp:end func_L05_0032B630 */
