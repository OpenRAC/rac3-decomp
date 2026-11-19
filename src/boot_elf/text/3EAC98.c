#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003EAC98(u8 *p, f32 a, f32 b);
extern s32 func_003EADD0(u8 *p, s32 a, s32 b);
extern s32 func_003EAF08(u8 *p, s32 a);
extern s32 func_003EB028(u8 *p, f32 a, f32 b);
extern s32 func_003EB090(u8 *p, s32 a);
extern s32 func_003EB1B0(u8 *p, s32 a, s32 b);
extern s32 func_003EB2E8(u8 *p, s32 a, u8 *out);
extern s32 func_003EB420(u8 *p, s32 a, s32 b);
extern s32 func_003EB488(u8 *p, s32 a, s32 b);
extern s32 func_003EB5C0(u8 *p, f32 a, f32 b);
typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
/* --- end of declarations from other files --- */

/* localdecomp:start func_003EAC98 */
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
extern s32 D_001D9790[];
s32 func_003EAC98(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EAC98 */

/* localdecomp:start func_003EAD00 */
extern u8 D_001DAA09;
extern void *func_003EA0B0(HT_8 *, u32);
s32 func_003EAD00(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA0B0(t, key) != 0) return 0;
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
/* localdecomp:end func_003EAD00 */

/* localdecomp:start func_003EADD0 */
extern s32 D_001D9790_g;
extern void func_003EDF30();
s32 func_003EADD0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790_g)) {
        func_003EDF30(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EADD0 */

/* localdecomp:start func_003EAE38 */
extern u8 D_001DAA0A;
extern void *func_003EA130(HT_8 *, u32);
s32 func_003EAE38(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA130(t, key) != 0) return 0;
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
/* localdecomp:end func_003EAE38 */

/* localdecomp:start func_003EAF08 */
extern s32 D_001D9790_g;
s32 func_003EAF08(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790_g)) {
        *(s32 *)(p + 0x3C) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EAF08 */

/* localdecomp:start func_003EAF58 */
extern u8 D_001DAA12;
extern void *func_003EA540(HT_8 *, u32);
s32 func_003EAF58(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA540(t, key) != 0) return 0;
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
/* localdecomp:end func_003EAF58 */

/* localdecomp:start func_003EB028 */
extern s32 D_001D9790[];
s32 func_003EB028(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB028 */

/* localdecomp:start func_003EB090 */
extern s32 D_001D9790_g;
s32 func_003EB090(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790_g)) {
        *(s32 *)(p + 0x50) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB090 */

/* localdecomp:start func_003EB0E0 */
extern u8 D_001DAA14;
extern void *func_003EA640(HT_8 *, u32);
s32 func_003EB0E0(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA640(t, key) != 0) return 0;
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
/* localdecomp:end func_003EB0E0 */

/* localdecomp:start func_003EB1B0 */
extern s32 D_001D9790_g;
extern void func_003EDE88(void *, s32, s32);
s32 func_003EB1B0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790_g)) {
        func_003EDE88(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB1B0 */

/* localdecomp:start func_003EB218 */
extern u8 D_001DAA0E;
extern void *func_003EA340(HT_8 *, u32);
s32 func_003EB218(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA340(t, key) != 0) return 0;
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
/* localdecomp:end func_003EB218 */

/* localdecomp:start func_003EB2E8 */
extern s32 D_001D9790_g;
extern s32 func_003EDEB0();
s32 func_003EB2E8(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790_g)) {
        *out = func_003EDEB0(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB2E8 */

/* localdecomp:start func_003EB350 */
extern u8 D_001DAA0F;
extern void *func_003EA3C0(HT_8 *, u32);
s32 func_003EB350(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA3C0(t, key) != 0) return 0;
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
/* localdecomp:end func_003EB350 */

/* localdecomp:start func_003EB420 */
extern s32 D_001D9790_g;
extern void func_003EDEC0(void *, s32, s32);
s32 func_003EB420(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790_g)) {
        func_003EDEC0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB420 */

/* localdecomp:start func_003EB488 */
extern s32 D_001D9790_g;
extern void func_003EDEF8();
s32 func_003EB488(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790_g)) {
        func_003EDEF8(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB488 */

/* localdecomp:start func_003EB4F0 */
extern u8 D_001DAA10;
extern void *func_003EA440(HT_8 *, u32);
s32 func_003EB4F0(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA440(t, key) != 0) return 0;
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
/* localdecomp:end func_003EB4F0 */

/* localdecomp:start func_003EB5C0 */
extern s32 D_001D9790[];
s32 func_003EB5C0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB5C0 */
