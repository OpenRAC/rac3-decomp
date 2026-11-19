#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003EC590(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_003EC6E8(u8 *p, f32 a);
extern s32 func_003EC810(u8 *p, f32 a, f32 b);
extern s32 func_003EC878(u8 *p, s32 a, s32 b);
extern s32 func_003EC8E0(u8 *p, f32 a, f32 b);
extern s32 func_003EC948(u8 *p, s32 a);
extern s32 func_003EC998(u8 *p, s32 a, s32 b);
extern s32 func_003ECA00(u8 *p, s32 a, u8 *out);
extern s32 func_003ECA68(u8 *p, s32 a, s32 b);
extern s32 func_003ECAD0(u8 *p, s32 a, s32 b);
extern s32 func_003ECB38(u8 *p, f32 a, f32 b);
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
extern s32 D_001D9760[];
extern void func_003EF288();

/* localdecomp:start func_003EC590 */
extern void func_003EF288(void *, s32, s32, s32, s32);
extern s32 D_001D9760_003EC590;
s32 func_003EC590(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D9760_003EC590) != 0) {
        func_003EF288(arg0, arg1, arg2, arg3, arg4);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC590 */

/* localdecomp:start func_003EC618 */
extern u8 D_001DAA16;
extern void *func_003EA390(HT_8 *, u32);
s32 func_003EC618(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA390(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA16) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003EC618 */

/* localdecomp:start func_003EC6E8 */
extern s32 D_001D9760[];
s32 func_003EC6E8(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9760[0])) {
        *(f32 *)(p + 0x2C) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC6E8 */

/* localdecomp:start func_003EC740 */
extern u8 D_001DAA0D;
extern void *func_003E9F08(HT_8 *, u32);
s32 func_003EC740(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E9F08(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA0D) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003EC740 */

/* localdecomp:start func_003EC810 */
extern s32 D_001D9730[];
s32 func_003EC810(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC810 */

/* localdecomp:start func_003EC878 */
extern s32 D_001D9730_g;
extern void func_003EDB78();
s32 func_003EC878(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730_g)) {
        func_003EDB78(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC878 */

/* localdecomp:start func_003EC8E0 */
extern s32 D_001D9730[];
s32 func_003EC8E0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC8E0 */

/* localdecomp:start func_003EC948 */
extern s32 D_001D9730_g;
s32 func_003EC948(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730_g)) {
        *(s32 *)(p + 0x30) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC948 */

/* localdecomp:start func_003EC998 */
extern s32 D_001D9730_g;
extern void func_003EDAD0(void *, s32, s32);
s32 func_003EC998(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730_g)) {
        func_003EDAD0(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC998 */

/* localdecomp:start func_003ECA00 */
extern s32 D_001D9730_g;
extern s32 func_003EDAF8();
s32 func_003ECA00(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730_g)) {
        *out = func_003EDAF8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECA00 */

/* localdecomp:start func_003ECA68 */
extern s32 D_001D9730_g;
extern void func_003EDB08(void *, s32, s32);
s32 func_003ECA68(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730_g)) {
        func_003EDB08(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECA68 */

/* localdecomp:start func_003ECAD0 */
extern s32 D_001D9730_g;
extern void func_003EDB40();
s32 func_003ECAD0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730_g)) {
        func_003EDB40(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECAD0 */

/* localdecomp:start func_003ECB38 */
extern s32 D_001D9730[];
s32 func_003ECB38(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECB38 */
