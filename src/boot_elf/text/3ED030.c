#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003ED030(u8 *p, f32 a, f32 b);
extern s32 func_003ED098(u8 *p, f32 a, f32 b);
extern s32 func_003ED100(u8 *p, s32 a, s32 b);
extern s32 func_003ED168(u8 *p, f32 a, f32 b);
extern s32 func_003ED1D0(u8 *p, s32 a);
extern s32 func_003ED220();
extern s32 func_003ED350(u8 *p, s32 a, s32 b);
extern s32 func_003ED3B8(u8 *p, s32 a, u8 *out);
extern s32 func_003ED420(u8 *p, s32 a, s32 b);
extern s32 func_003ED488(u8 *p, s32 a, s32 b);
extern s32 func_003ED4F0(u8 *p, f32 a, f32 b);
extern s32 func_003ED558(u8 *p, f32 a);
typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
/* --- end of declarations from other files --- */

/* declarations of 3EAC98.c's earlier functions */
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
extern void func_003EDF30();
extern void func_003EDE88(void *, s32, s32);
extern s32 func_003EDEB0();
extern void func_003EDEC0(void *, s32, s32);
extern void func_003EDEF8();
extern s32 D_001D9730[];

/* localdecomp:start func_003ED030 */
extern s32 D_001D9730[];
s32 func_003ED030(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730[0])) {
        *(f32 *)(p + 0x34) = a;
        *(f32 *)(p + 0x38) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED030 */

/* localdecomp:start func_003ED098 */
extern s32 D_001D97F0[];
s32 func_003ED098(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED098 */

/* localdecomp:start func_003ED100 */
extern s32 D_001D97F0_g;
extern void func_003EDF30();
s32 func_003ED100(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        func_003EDF30(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED100 */

/* localdecomp:start func_003ED168 */
extern s32 D_001D97F0[];
s32 func_003ED168(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED168 */

/* localdecomp:start func_003ED1D0 */
extern s32 D_001D97F0_g;
s32 func_003ED1D0(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        *(s32 *)(p + 0x38) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED1D0 */

/* localdecomp:start func_003ED220 */
typedef struct { s32 pad[4]; s32 (*fn)(void *, s32); } V_3E7900;
typedef struct { s32 a, b; V_3E7900 *vt; u8 pad[0x34]; s32 c; s32 d; } S_3E7900;
extern s32 D_001D97F0_003ED220;
s32 func_003ED220(S_3E7900 *s, s32 b, s32 c) {
    if (s->vt->fn(s, D_001D97F0_003ED220) != 0) {
        s->d = b;
        s->c = c;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED220 */

/* localdecomp:start func_003ED280 */
extern u8 D_001DAA17;
extern void *func_003EA7C8(HT_8 *, u32);
s32 func_003ED280(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA7C8(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA17) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003ED280 */

/* localdecomp:start func_003ED350 */
extern s32 D_001D97F0_g;
extern void func_003EDE88(void *, s32, s32);
s32 func_003ED350(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        func_003EDE88(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED350 */

/* localdecomp:start func_003ED3B8 */
extern s32 D_001D97F0_g;
extern s32 func_003EDEB0();
s32 func_003ED3B8(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        *out = func_003EDEB0(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED3B8 */

/* localdecomp:start func_003ED420 */
extern s32 D_001D97F0_g;
extern void func_003EDEC0(void *, s32, s32);
s32 func_003ED420(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        func_003EDEC0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED420 */

/* localdecomp:start func_003ED488 */
extern s32 D_001D97F0_g;
extern void func_003EDEF8();
s32 func_003ED488(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        func_003EDEF8(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED488 */

/* localdecomp:start func_003ED4F0 */
extern s32 D_001D97F0[];
s32 func_003ED4F0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED4F0 */

/* localdecomp:start func_003ED558 */
extern s32 D_001D97F0[];
s32 func_003ED558(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0[0])) {
        *(f32 *)(p + 0x3C) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED558 */
