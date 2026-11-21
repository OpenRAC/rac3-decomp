#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003ED688(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern s32 func_003ED7E8();
extern s32 func_003ED840();
extern s32 func_003ED960(u8 *p, s32 a, s32 b);
extern s32 func_003ED9C8(u8 *p, s32 a, u8 *out);
extern s32 func_003EDA30(u8 *p, s32 a, s32 b);
extern s32 func_003EDA98(u8 *p, s32 a, s32 b);
extern s32 func_003EDB00(u8 *p, f32 a, f32 b);
extern s32 func_003EDB68(u8 *p, f32 a, f32 b);
extern s32 func_003EDBD8(u8 *p, s32 a, s32 b);
extern s32 func_003EDC40(u8 *p, f32 a, f32 b);
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
extern void func_003EDF20(void *, f32, f32);
extern void func_003EDF48(void *, f32, f32);

/* localdecomp:start func_003ED688 */
extern void func_003EE7C0(u8 *, f32, f32, f32, f32);
extern s32 D_001D9700[];
s32 func_003ED688(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D9700[0]) != 0) {
        func_003EE7C0((u8 *)arg0, fparg0, fparg1, fparg2, fparg3);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED688 */

/* localdecomp:start func_003ED718 */
extern u8 D_001DAA18;
extern void *func_003EA848(HT_8 *, u32);
s32 func_003ED718(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA848(t, key) != 0) return 0;
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
/* localdecomp:end func_003ED718 */

/* localdecomp:start func_003ED7E8 */
typedef struct S_3E7EC8 S_3E7EC8;
typedef struct { u8 pad[0x10]; s32 (*f10)(S_3E7EC8 *, s32); } V_3E7EC8;
struct S_3E7EC8 { u8 pad[8]; V_3E7EC8 *vt; };
extern s32 D_001D9700_003ED7E8;
extern s32 func_003EE158(S_3E7EC8 *a, s32 b);
s32 func_003ED7E8(S_3E7EC8 *a, s32 b) {
    if (a->vt->f10(a, D_001D9700_003ED7E8)) return func_003EE158(a, b);
    return 0;
}
/* localdecomp:end func_003ED7E8 */

/* localdecomp:start func_003ED840 */
typedef struct { s32 pad[4]; s32 (*fn)(void *, void *); } V_3E7F20;
typedef struct { s32 a, b; V_3E7F20 *vt; } S_3E7F20;
extern void *D_001D9700_003ED840[];
extern void func_003EE290();
s32 func_003ED840(S_3E7F20 *s) {
    if (s->vt->fn(s, D_001D9700_003ED840[0]) == 0) return 0;
    func_003EE290(s);
    return 1;
}
/* localdecomp:end func_003ED840 */

/* localdecomp:start func_003ED890 */
extern u8 D_001DAA1A;
extern void *func_003EA948(HT_8 *, u32);
s32 func_003ED890(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA948(t, key) != 0) return 0;
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
/* localdecomp:end func_003ED890 */

/* localdecomp:start func_003ED960 */
extern s32 D_001D9700_g;
extern void func_003EDE88(void *, s32, s32);
s32 func_003ED960(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700_g)) {
        func_003EDE88(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED960 */

/* localdecomp:start func_003ED9C8 */
extern s32 D_001D9700_g;
extern s32 func_003EDEB0();
s32 func_003ED9C8(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700_g)) {
        *out = func_003EDEB0(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED9C8 */

/* localdecomp:start func_003EDA30 */
extern s32 D_001D9700_g;
extern void func_003EDEC0(void *, s32, s32);
s32 func_003EDA30(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700_g)) {
        func_003EDEC0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EDA30 */

/* localdecomp:start func_003EDA98 */
extern s32 D_001D9700_g;
extern void func_003EDEF8();
s32 func_003EDA98(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700_g)) {
        func_003EDEF8(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EDA98 */

/* localdecomp:start func_003EDB00 */
extern s32 D_001D9700[];
s32 func_003EDB00(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EDB00 */

/* localdecomp:start func_003EDB68 */
extern s32 D_001D9700[];
extern void func_003EDF20(void *, f32, f32);
s32 func_003EDB68(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700[0])) {
        func_003EDF20(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EDB68 */

/* localdecomp:start func_003EDBD8 */
extern s32 D_001D9700_g;
extern void func_003EDF30();
s32 func_003EDBD8(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700_g)) {
        func_003EDF30(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EDBD8 */

/* localdecomp:start func_003EDC40 */
extern s32 D_001D9700[];
extern void func_003EDF48(void *, f32, f32);
s32 func_003EDC40(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700[0])) {
        func_003EDF48(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EDC40 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003EDCB0);
