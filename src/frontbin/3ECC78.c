#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003ECC78(u8 *p, f32 a, f32 b);
extern s32 func_003ECCE0(u8 *p, f32 a, f32 b);
extern s32 func_003ECD48(u8 *p, s32 a, s32 b);
extern s32 func_003ECDB0(u8 *p, f32 a, f32 b);
extern s32 func_003ECE18(u8 *p, s32 a);
extern s32 func_003ECE68();
extern s32 func_003ECF98(u8 *p, s32 a, s32 b);
extern s32 func_003ED000(u8 *p, s32 a, u8 *out);
extern s32 func_003ED068(u8 *p, s32 a, s32 b);
extern s32 func_003ED0D0(u8 *p, s32 a, s32 b);
extern s32 func_003ED138(u8 *p, f32 a, f32 b);
extern s32 func_003ED1A0(u8 *p, f32 a);
typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
/* --- end of declarations from other files --- */

/* declarations of 3EA8E0.c's earlier functions */
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
extern void func_003EDB78();
extern void func_003EDAD0(void *, s32, s32);
extern s32 func_003EDAF8();
extern void func_003EDB08(void *, s32, s32);
extern void func_003EDB40();
extern s32 D_001D9730[];

/* localdecomp:start func_003ECC78 */
extern s32 D_001D9730[];
s32 func_003ECC78(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730[0])) {
        *(f32 *)(p + 0x34) = a;
        *(f32 *)(p + 0x38) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECC78 */

/* localdecomp:start func_003ECCE0 */
extern s32 D_001D97F0[];
s32 func_003ECCE0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECCE0 */

/* localdecomp:start func_003ECD48 */
extern s32 D_001D97F0_g;
extern void func_003EDB78();
s32 func_003ECD48(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        func_003EDB78(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECD48 */

/* localdecomp:start func_003ECDB0 */
extern s32 D_001D97F0[];
s32 func_003ECDB0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECDB0 */

/* localdecomp:start func_003ECE18 */
extern s32 D_001D97F0_g;
s32 func_003ECE18(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        *(s32 *)(p + 0x38) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECE18 */

/* localdecomp:start func_003ECE68 */
typedef struct { s32 pad[4]; s32 (*fn)(void *, s32); } V_3E7900;
typedef struct { s32 a, b; V_3E7900 *vt; u8 pad[0x34]; s32 c; s32 d; } S_3E7900;
extern s32 D_001D97F0_003ECE68;
s32 func_003ECE68(S_3E7900 *s, s32 b, s32 c) {
    if (s->vt->fn(s, D_001D97F0_003ECE68) != 0) {
        s->d = b;
        s->c = c;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECE68 */

/* localdecomp:start func_003ECEC8 */
extern u8 D_001DAA17;
extern void *func_003EA410(HT_8 *, u32);
s32 func_003ECEC8(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA410(t, key) != 0) return 0;
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
/* localdecomp:end func_003ECEC8 */

/* localdecomp:start func_003ECF98 */
extern s32 D_001D97F0_g;
extern void func_003EDAD0(void *, s32, s32);
s32 func_003ECF98(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        func_003EDAD0(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECF98 */

/* localdecomp:start func_003ED000 */
extern s32 D_001D97F0_g;
extern s32 func_003EDAF8();
s32 func_003ED000(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        *out = func_003EDAF8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED000 */

/* localdecomp:start func_003ED068 */
extern s32 D_001D97F0_g;
extern void func_003EDB08(void *, s32, s32);
s32 func_003ED068(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        func_003EDB08(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED068 */

/* localdecomp:start func_003ED0D0 */
extern s32 D_001D97F0_g;
extern void func_003EDB40();
s32 func_003ED0D0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        func_003EDB40(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED0D0 */

/* localdecomp:start func_003ED138 */
extern s32 D_001D97F0[];
s32 func_003ED138(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED138 */

/* localdecomp:start func_003ED1A0 */
extern s32 D_001D97F0[];
s32 func_003ED1A0(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0[0])) {
        *(f32 *)(p + 0x3C) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED1A0 */
