#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3C4D90.c's earlier functions (tools/port_from_us.py) */
extern s32 func_003C4EF8_003C4F08(s16);
extern u32 D_001DA49C[];
extern u32 D_001DA4A4[];
extern f32 func_0038D288(s32 a);
extern void func_0038D348(s32 a, s32 b, f32 x);
extern f32 func_003828C0(f32, f32);
extern void func_0038D348(s32 a, s32 b, f32 x);
typedef int u128_3BF838 __attribute__((mode(TI)));
typedef struct { u128_3BF838 r[4]; } M_3BF838;
extern void func_0038D708();
extern void func_0038D990();
extern void func_0038DA20();
extern void func_003C4C60();
extern s32 func_0038D438(f32 *);
typedef struct { u8 pad[0x40]; } M_3BFAF8;
void func_0038D990(M_3BFAF8 *, void *);
void func_0038D3E0(void *, void *, M_3BFAF8 *);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BFBA8;
typedef int Q_3BFBA8 __attribute__((mode(TI)));
extern f32 D_001D5C00;
extern void func_0038D200(f32 *, void *, f32);

/* localdecomp:start func_003C5538 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BFC18;
typedef int Q_3BFC18 __attribute__((mode(TI)));
extern s32 D_001D5BEC_003C5538;
extern s32 D_001D5BF0;
typedef struct { u8 p0[0xB0]; V4_3BFC18 v; } S_3BFC18;
extern S_3BFC18 D_001A4BE0;
extern void func_0038D200(f32 *, void *, f32);
extern void func_003C54C8(void *, void *, s32);
void func_003C5538(void *a, f32 *out, s32 flag) {
    if (D_001D5BEC_003C5538 == 0) {
        Q_3BFC18 r;
        __asm__("vmr32.xyzw %0, $vf0" : "=j"(r));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3BFC18 *)out) : "j"(r));
    } else if (D_001D5BF0 != 0) {
        func_003C54C8(a, out, 1);
    } else {
        Q_3BFC18 p, q, r;
        S_3BFC18 *d = &D_001A4BE0;
        f32 s = 1.0f;
        if (d->v.w > 0.0f) {
            s = -1.0f;
        }
        __asm__("lqc2 %0, %1" : "=j"(p) : "m"(*(V4_3BFC18 *)a));
        __asm__("lqc2 %0, %1" : "=j"(q) : "m"(d->v));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(q), "j"(p));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3BFC18 *)out) : "j"(r));
        ((void (*)(void *, void *, f32))func_0038D348)(out, out, s);
    }
    if (flag == 0) {
        func_0038D200(out, out, -1.0f);
    }
}
/* localdecomp:end func_003C5538 */
