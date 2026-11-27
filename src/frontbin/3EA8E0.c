#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003EA8E0(u8 *p, f32 a, f32 b);
extern s32 func_003EAA18(u8 *p, s32 a, s32 b);
extern s32 func_003EAB50(u8 *p, s32 a);
extern s32 func_003EAC70(u8 *p, f32 a, f32 b);
extern s32 func_003EACD8(u8 *p, s32 a);
extern s32 func_003EADF8(u8 *p, s32 a, s32 b);
extern s32 func_003EAF30(u8 *p, s32 a, u8 *out);
extern s32 func_003EB068(u8 *p, s32 a, s32 b);
extern s32 func_003EB0D0(u8 *p, s32 a, s32 b);
extern s32 func_003EB208(u8 *p, f32 a, f32 b);
typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
/* --- end of declarations from other files --- */

/* localdecomp:start func_003EA8E0 */
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
extern s32 D_001D9790[];
s32 func_003EA8E0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EA8E0 */

/* localdecomp:start func_003EA948 */
extern u8 D_001DAA09;
extern void *func_003E9CF8(HT_8 *, u32);
s32 func_003EA948(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E9CF8(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA09) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003EA948 */

/* localdecomp:start func_003EAA18 */
extern s32 D_001D9790_g;
extern void func_003EDB78();
s32 func_003EAA18(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790_g)) {
        func_003EDB78(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EAA18 */

/* localdecomp:start func_003EAA80 */
extern u8 D_001DAA0A;
extern void *func_003E9D78(HT_8 *, u32);
s32 func_003EAA80(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E9D78(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA0A) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003EAA80 */

/* localdecomp:start func_003EAB50 */
extern s32 D_001D9790_g;
s32 func_003EAB50(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790_g)) {
        *(s32 *)(p + 0x3C) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EAB50 */

/* localdecomp:start func_003EABA0 */
extern u8 D_001DAA12;
extern void *func_003EA188(HT_8 *, u32);
s32 func_003EABA0(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA188(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA12) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003EABA0 */

/* localdecomp:start func_003EAC70 */
extern s32 D_001D9790[];
s32 func_003EAC70(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EAC70 */

/* localdecomp:start func_003EACD8 */
extern s32 D_001D9790_g;
s32 func_003EACD8(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790_g)) {
        *(s32 *)(p + 0x50) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EACD8 */

/* localdecomp:start func_003EAD28 */
extern u8 D_001DAA14;
extern void *func_003EA288(HT_8 *, u32);
s32 func_003EAD28(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA288(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA14) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003EAD28 */

/* localdecomp:start func_003EADF8 */
extern s32 D_001D9790_g;
extern void func_003EDAD0(void *, s32, s32);
s32 func_003EADF8(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790_g)) {
        func_003EDAD0(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EADF8 */

/* localdecomp:start func_003EAE60 */
extern u8 D_001DAA0E;
extern void *func_003E9F88(HT_8 *, u32);
s32 func_003EAE60(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E9F88(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA0E) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003EAE60 */

/* localdecomp:start func_003EAF30 */
extern s32 D_001D9790_g;
extern s32 func_003EDAF8();
s32 func_003EAF30(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790_g)) {
        *out = func_003EDAF8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EAF30 */

/* localdecomp:start func_003EAF98 */
extern u8 D_001DAA0F;
extern void *func_003EA008(HT_8 *, u32);
s32 func_003EAF98(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA008(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA0F) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003EAF98 */

/* localdecomp:start func_003EB068 */
extern s32 D_001D9790_g;
extern void func_003EDB08(void *, s32, s32);
s32 func_003EB068(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790_g)) {
        func_003EDB08(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB068 */

/* localdecomp:start func_003EB0D0 */
extern s32 D_001D9790_g;
extern void func_003EDB40();
s32 func_003EB0D0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790_g)) {
        func_003EDB40(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB0D0 */

/* localdecomp:start func_003EB138 */
extern u8 D_001DAA10;
extern void *func_003EA088(HT_8 *, u32);
s32 func_003EB138(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA088(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA10) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003EB138 */

/* localdecomp:start func_003EB208 */
extern s32 D_001D9790[];
s32 func_003EB208(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB208 */
