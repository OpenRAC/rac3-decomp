#include "common.h"

/* localdecomp:start func_L39_005517C8 */
#include "vu0.h"
typedef int Q_5517C8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_5517C8;
typedef struct {
    V4_5517C8 out;
    V4_5517C8 pos;
    f32 angle;
    f32 len;
    u8 pad28[8];
} Rec_5517C8;

extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4840(f32 *q, void *axis, f32 angle);
extern void func_0038D850(void *out, void *a, void *b);

void func_L39_005517C8(u8 *base, s32 index) {
    Rec_5517C8 *rec = (Rec_5517C8 *)base;
    V4_5517C8 up;
    V4_5517C8 a;
    V4_5517C8 d;
    V4_5517C8 q;

    *(Q_5517C8 *)&up = 0;
    up.z = 1.0f;
    if ((f32)index == 0.0f || __builtin_fabsf(rec[index].angle) < 0.00001f) {
        func_0038CE20(&a, &up, rec[index].len);
    } else {
        vec_sub_ba(&d, &rec[index].pos, &rec[index - 1].pos);
        func_0038CF68(&q, &d, 1.0f);
        func_003C4840((f32 *)&q, &q, rec[index].angle);
        func_0038D850(&a, &up, &q);
        func_0038CE20(&a, &a, rec[index].len);
    }
    vec_add_ba(&rec[index].out, &rec[index].pos, &a);
    rec[index].out.w = 0.15f;
}
/* localdecomp:end func_L39_005517C8 */
