#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003ED2D0(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern s32 func_003ED430();
extern s32 func_003ED488();
extern s32 func_003ED5A8(u8 *p, s32 a, s32 b);
extern s32 func_003ED610(u8 *p, s32 a, u8 *out);
extern s32 func_003ED678(u8 *p, s32 a, s32 b);
extern s32 func_003ED6E0(u8 *p, s32 a, s32 b);
extern s32 func_003ED748(u8 *p, f32 a, f32 b);
extern s32 func_003ED7B0(u8 *p, f32 a, f32 b);
extern s32 func_003ED820(u8 *p, s32 a, s32 b);
extern s32 func_003ED888(u8 *p, f32 a, f32 b);
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
extern void func_003EDB68(void *, f32, f32);
extern void func_003EDB90(void *, f32, f32);

/* localdecomp:start func_003ED2D0 */
extern void func_003EE408(u8 *, f32, f32, f32, f32);
extern s32 D_001D9700[];
s32 func_003ED2D0(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D9700[0]) != 0) {
        func_003EE408((u8 *)arg0, fparg0, fparg1, fparg2, fparg3);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED2D0 */

/* localdecomp:start func_003ED360 */
extern u8 D_001DAA18;
extern void *func_003EA490(HT_8 *, u32);
s32 func_003ED360(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA490(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA18) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003ED360 */

/* localdecomp:start func_003ED430 */
typedef struct S_3E7EC8 S_3E7EC8;
typedef struct { u8 pad[0x10]; s32 (*f10)(S_3E7EC8 *, s32); } V_3E7EC8;
struct S_3E7EC8 { u8 pad[8]; V_3E7EC8 *vt; };
extern s32 D_001D9700_003ED430;
extern s32 func_003EDDA0(S_3E7EC8 *a, s32 b);
s32 func_003ED430(S_3E7EC8 *a, s32 b) {
    if (a->vt->f10(a, D_001D9700_003ED430)) return func_003EDDA0(a, b);
    return 0;
}
/* localdecomp:end func_003ED430 */

/* localdecomp:start func_003ED488 */
typedef struct { s32 pad[4]; s32 (*fn)(void *, void *); } V_3E7F20;
typedef struct { s32 a, b; V_3E7F20 *vt; } S_3E7F20;
extern void *D_001D9700_003ED488[];
extern void func_003EDED8();
s32 func_003ED488(S_3E7F20 *s) {
    if (s->vt->fn(s, D_001D9700_003ED488[0]) == 0) return 0;
    func_003EDED8(s);
    return 1;
}
/* localdecomp:end func_003ED488 */

/* localdecomp:start func_003ED4D8 */
extern u8 D_001DAA1A;
extern void *func_003EA590(HT_8 *, u32);
s32 func_003ED4D8(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA590(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA1A) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003ED4D8 */

/* localdecomp:start func_003ED5A8 */
extern s32 D_001D9700_g;
extern void func_003EDAD0(void *, s32, s32);
s32 func_003ED5A8(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700_g)) {
        func_003EDAD0(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED5A8 */

/* localdecomp:start func_003ED610 */
extern s32 D_001D9700_g;
extern s32 func_003EDAF8();
s32 func_003ED610(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700_g)) {
        *out = func_003EDAF8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED610 */

/* localdecomp:start func_003ED678 */
extern s32 D_001D9700_g;
extern void func_003EDB08(void *, s32, s32);
s32 func_003ED678(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700_g)) {
        func_003EDB08(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED678 */

/* localdecomp:start func_003ED6E0 */
extern s32 D_001D9700_g;
extern void func_003EDB40();
s32 func_003ED6E0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700_g)) {
        func_003EDB40(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED6E0 */

/* localdecomp:start func_003ED748 */
extern s32 D_001D9700[];
s32 func_003ED748(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED748 */

/* localdecomp:start func_003ED7B0 */
extern s32 D_001D9700[];
extern void func_003EDB68(void *, f32, f32);
s32 func_003ED7B0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700[0])) {
        func_003EDB68(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED7B0 */

/* localdecomp:start func_003ED820 */
extern s32 D_001D9700_g;
extern void func_003EDB78();
s32 func_003ED820(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700_g)) {
        func_003EDB78(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED820 */

/* localdecomp:start func_003ED888 */
extern s32 D_001D9700[];
extern void func_003EDB90(void *, f32, f32);
s32 func_003ED888(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700[0])) {
        func_003EDB90(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED888 */

LINKER_REMNANT("asm/remnants", func_003ED8F8);
