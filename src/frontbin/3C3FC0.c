#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_003C47E8(void *, void *);
extern void func_003C47E8();
extern void func_003C4840(f32 *, void *, f32);
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0038CC88_00391678(void *, void *, s32) __asm__("func_0038CC88");
extern f32 func_003C41A0(f32 *, f32 *, f32, f32, f32, f32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003C3FC0 */
extern s32 func_0038D688();
extern void func_0038D750(void *, s32, f32);
void func_003C3FC0(s32 *arg0, void *arg1) {
    s32 spv[12];

    func_0038D750(&spv[8], 0, (*(f32 *)((u8 *)arg1 + 0)));
    func_0038D750(&spv[4], 1, (*(f32 *)((u8 *)arg1 + 4)));
    func_0038D750(spv, 2, (*(f32 *)((u8 *)arg1 + 8)));
    ((s32 (*)())func_0038D688)(arg0, &spv[8], &spv[4]);
    ((s32 (*)())func_0038D688)(arg0, arg0, spv);
}
/* localdecomp:end func_003C3FC0 */

LINKER_REMNANT("asm/remnants", func_003C4058);

/* localdecomp:start func_003C4088 */
f32 func_003C4088(f32 a, f32 b, f32 t) {
    return a + (b - a) * t;
}
/* localdecomp:end func_003C4088 */

/* localdecomp:start func_003C4098 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) Vector_003BEB58;
extern f32 func_003C4088(f32, f32, f32);
void func_003C4098(Vector_003BEB58 *output, Vector_003BEB58 first, Vector_003BEB58 second, f32 fraction) {
    output->x = func_003C4088(first.x, second.x, fraction);
    output->y = func_003C4088(first.y, second.y, fraction);
    output->z = func_003C4088(first.z, second.z, fraction);
    output->w = func_003C4088(first.w, second.w, fraction);
}
/* localdecomp:end func_003C4098 */

LINKER_REMNANT("asm/remnants", func_003C4130);

/* localdecomp:start func_003C4138 */
#include "vu0.h"
f32 func_003C4138(f32 *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f1;
    f32 var_f0;
    f32 var_f13;

    var_f13 = fparg1;
    var_f0 = fparg0 - *arg0;
    if ((var_f13 < var_f0) || (var_f13 = -var_f13, (var_f0 < var_f13))) {
        var_f0 = var_f13;
    }
    temp_f1 = *arg0 + var_f0;
    *arg0 = temp_f1;
    { f32 r; r = fabs_asm(fparg0 - temp_f1); return r; }
}
/* localdecomp:end func_003C4138 */

LINKER_REMNANT("asm/remnants", func_003C4188);

/* localdecomp:start func_003C41A0 */
#include "vu0.h"
f32 func_003C41A0(f32 *pos, f32 *vel, f32 target, f32 maxv, f32 acc, f32 lim) {
    f32 d = target - *pos;
    f32 v;
    if (*vel == 0.0f && d == 0.0f) return 0.0f;
    v = *vel;
    if (0.0f <= v * d) {
        f32 stop = v * v / acc * 0.5f;
        if (__builtin_fabsf(d) < stop) {
            if (stop < __builtin_fabsf(d) + __builtin_fabsf(v)) {
                v = acc;
                func_003C4138(vel, 0.0f, v);
            } else {
                v = acc * 1.1f;
                func_003C4138(vel, 0.0f, v);
            }
        } else {
            f32 s = sqrt_asm((acc + acc) * d);
            if (lim < s) s = lim;
            v = maxv;
            if (d < 0.0f) {
                func_003C4138(vel, -s, v);
            } else {
                func_003C4138(vel, s, v);
            }
        }
        if (__builtin_fabsf(*vel) < __builtin_fabsf(d)) {
            *pos = *pos + *vel;
            return *vel;
        }
        *pos = target;
        return d;
    } else {
        if (v < 0.0f) v = v + acc;
        else v = v - acc;
        *vel = v;
        *pos = *pos + v;
        return *vel;
    }
}
/* localdecomp:end func_003C41A0 */

LINKER_REMNANT("asm/remnants", func_003C4348);

/* localdecomp:start func_003C4360 */
#include "vu0.h"
void func_003C4360(f32 *vel, f32 d, f32 maxv, f32 acc, f32 lim) {
    f32 v;
    if (d == 0.0f && *vel == 0.0f) return;
    if (0.0f <= *vel * d && d != 0.0f) {
        f32 stop;
        stop = *vel * *vel / acc * 0.5f;
        v = *vel;
        if (__builtin_fabsf(d) < stop) {
            if (stop < __builtin_fabsf(d) + __builtin_fabsf(v)) {
                v = acc;
                func_003C4138(vel, 0.0f, v);
            } else {
                v = acc * 1.1f;
                func_003C4138(vel, 0.0f, v);
            }
        } else {
            f32 s;
            s = sqrt_asm((acc + acc) * d);
            if (lim < s) s = lim;
            v = maxv;
            if (d < 0.0f) {
                func_003C4138(vel, -s, v);
            } else {
                func_003C4138(vel, s, v);
            }
        }
        if (__builtin_fabsf(*vel) < __builtin_fabsf(d)) return;
        *vel = d;
    } else {
        v = *vel;
        if (v < 0.0f) v = v + acc;
        else v = v - acc;
        *vel = v;
        if (d < 0.0f && v < d) *vel = d;
        else if (0.0f < d && d < *vel) *vel = d;
    }
}
/* localdecomp:end func_003C4360 */
TEXT_PADDING(2);

LINKER_REMNANT("asm/remnants", func_003C4538);

INCLUDE_ASM("asm/nonmatchings/text", func_003C4598);

typedef struct { s32 v[3]; } N3_3BF058;
extern N3_3BF058 D_001D9118;
/* localdecomp:start func_003C45A0 */
/* func_003C45A0: the boot_elf twin func_003C4958 renamed. Only the nops before its two sqrt.s and two
   div.s differ (row 2 2 2 0, as the twin's boot_elf row: the compiler already gives the last div.s its 2 nops): DIVS. */
#include "vu0.h"
/* from boot_elf twin func_003C4958 */
void func_003C45A0(void *out, void *in) {
    N3_3BF058 next = D_001D9118;
    f32 m[3][3];
    f32 *q = out;
    f32 *a = in;
    f32 trace = a[0] + a[5] + a[10];
    f32 s;
    s32 i,j,k;
    if (trace > 0.0f) {
        s = sqrt_asm(trace+1.0f);
        q[3] = s*0.5f;
        s = 0.5f/s;
        q[0] = (a[9]-a[6])*s;
        q[1] = (a[2]-a[8])*s;
        q[2] = (a[4]-a[1])*s;
    } else {
        m[0][0]=a[0]; m[0][1]=a[1]; m[0][2]=a[2];
        m[1][0]=a[4]; m[1][1]=a[5]; m[1][2]=a[6];
        m[2][0]=a[8]; m[2][1]=a[9]; m[2][2]=a[10];
        i=0;
        if (a[0]<a[5]) i=1;
        if (m[i][i]<a[10]) i=2;
        j=next.v[i]; k=next.v[j];
        s=sqrt_asm(m[i][i]-(m[j][j]+m[k][k])+1.0f);
        q[i]=s*0.5f;
        if (s!=0.0f) s=0.5f/s;
        q[3]=(m[k][j]-m[j][k])*s;
        q[j]=(m[j][i]+m[i][j])*s;
        q[k]=(m[k][i]+m[i][k])*s;
    }
}
/* localdecomp:end func_003C45A0 */

/* localdecomp:start func_003C47E8 */
extern void func_0038D570(void *, void *);
extern void func_003C45A0(void *, void *);
extern void func_0038D590(void *, void *);
void func_003C47E8(void *a, void *b) {
    u8 m[0x40];
    func_0038D570(m, b);
    func_003C45A0(a, m);
    func_0038D590(b, m);
}
/* localdecomp:end func_003C47E8 */

LINKER_REMNANT("asm/remnants", func_003C4838);

/* localdecomp:start func_003C4840 */
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038CE20(f32 *, void *, f32);
void func_003C4840(f32 *q, void *axis, f32 angle) {
    f32 h = angle * 0.5f;
    func_0038CE20(q, axis, func_0038D0B0(h));
    q[3] = func_0038D098(h);
}
/* localdecomp:end func_003C4840 */
