#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_0032ADD0);

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
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_32B290;
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
    char pad0[0x10];
    vu0_v4 pos;
} S_32B630;
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
