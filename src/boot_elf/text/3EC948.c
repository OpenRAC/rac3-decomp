#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003EC948(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_003ECAA0(u8 *p, f32 a);
extern s32 func_003ECBC8(u8 *p, f32 a, f32 b);
extern s32 func_003ECC30(u8 *p, s32 a, s32 b);
extern s32 func_003ECC98(u8 *p, f32 a, f32 b);
extern s32 func_003ECD00(u8 *p, s32 a);
extern s32 func_003ECD50(u8 *p, s32 a, s32 b);
extern s32 func_003ECDB8(u8 *p, s32 a, u8 *out);
extern s32 func_003ECE20(u8 *p, s32 a, s32 b);
extern s32 func_003ECE88(u8 *p, s32 a, s32 b);
extern s32 func_003ECEF0(u8 *p, f32 a, f32 b);
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
extern s32 D_001D9760[];
extern void func_003EF640();

/* localdecomp:start func_003EC948 */
extern void func_003EF640(void *, s32, s32, s32, s32);
extern s32 D_001D9760_003EC948;
s32 func_003EC948(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D9760_003EC948) != 0) {
        func_003EF640(arg0, arg1, arg2, arg3, arg4);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC948 */

/* localdecomp:start func_003EC9D0 */
extern u8 D_001DAA16;
extern void *func_003EA748(HT_8 *, u32);
s32 func_003EC9D0(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA748(t, key) != 0) return 0;
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
/* localdecomp:end func_003EC9D0 */

/* localdecomp:start func_003ECAA0 */
extern s32 D_001D9760[];
s32 func_003ECAA0(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9760[0])) {
        *(f32 *)(p + 0x2C) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECAA0 */

/* localdecomp:start func_003ECAF8 */
extern u8 D_001DAA0D;
extern void *func_003EA2C0(HT_8 *, u32);
s32 func_003ECAF8(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA2C0(t, key) != 0) return 0;
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
/* localdecomp:end func_003ECAF8 */

/* localdecomp:start func_003ECBC8 */
extern s32 D_001D9730[];
s32 func_003ECBC8(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECBC8 */

/* localdecomp:start func_003ECC30 */
extern s32 D_001D9730_g;
extern void func_003EDF30();
s32 func_003ECC30(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730_g)) {
        func_003EDF30(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECC30 */

/* localdecomp:start func_003ECC98 */
extern s32 D_001D9730[];
s32 func_003ECC98(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECC98 */

/* localdecomp:start func_003ECD00 */
extern s32 D_001D9730_g;
s32 func_003ECD00(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730_g)) {
        *(s32 *)(p + 0x30) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECD00 */

/* localdecomp:start func_003ECD50 */
extern s32 D_001D9730_g;
extern void func_003EDE88(void *, s32, s32);
s32 func_003ECD50(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730_g)) {
        func_003EDE88(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECD50 */

/* localdecomp:start func_003ECDB8 */
extern s32 D_001D9730_g;
extern s32 func_003EDEB0();
s32 func_003ECDB8(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730_g)) {
        *out = func_003EDEB0(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECDB8 */

/* localdecomp:start func_003ECE20 */
extern s32 D_001D9730_g;
extern void func_003EDEC0(void *, s32, s32);
s32 func_003ECE20(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730_g)) {
        func_003EDEC0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECE20 */

/* localdecomp:start func_003ECE88 */
extern s32 D_001D9730_g;
extern void func_003EDEF8();
s32 func_003ECE88(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730_g)) {
        func_003EDEF8(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECE88 */

/* localdecomp:start func_003ECEF0 */
extern s32 D_001D9730[];
s32 func_003ECEF0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECEF0 */
