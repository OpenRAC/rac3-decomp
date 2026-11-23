#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003EB7D0(u8 *p, s32 a);
extern s32 func_003EB8F8(u8 *p, f32 a, f32 b);
extern s32 func_003EB968(u8 *p, s32 a, s32 b);
extern s32 func_003EB9D0(u8 *p, s32 a);
extern s32 func_003EBA28(u8 *p, s32 a, s16 b, s16 c, s32 d);
extern s32 func_003EBB88(u8 *p, f32 a, f32 b);
extern s32 func_003EBBF8(u8 *p, s32 a);
extern s32 func_003EBC50(u8 *p, s32 a, s32 b);
extern s32 func_003EBCB8(u8 *p, s32 a, u8 *out);
extern s32 func_003EBD20(u8 *p, s32 a, s32 b);
extern s32 func_003EBD88(u8 *p, s32 a, s32 b);
extern s32 func_003EBDF0(u8 *p, f32 a, f32 b);
typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
/* --- end of declarations from other files --- */

/* declarations of 3EAC98.c's earlier functions */
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
extern s32 D_001D9790_g;
extern void func_003EDF30();
extern void func_003EDE88(void *, s32, s32);
extern s32 func_003EDEB0();
extern void func_003EDEC0(void *, s32, s32);
extern void func_003EDEF8();

/* localdecomp:start func_003EB700 */
extern u8 D_001DAA11;
extern void *func_003EA4C0(HT_8 *, u32);
s32 func_003EB700(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA4C0(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA11) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003EB700 */

/* localdecomp:start func_003EB7D0 */
extern s32 D_001D9790_g;
s32 func_003EB7D0(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790_g)) {
        *(s32 *)(p + 0x58) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB7D0 */

/* localdecomp:start func_003EB820 */
typedef struct {
    u8 pad0[4];
    s32 count;
    struct {
        u32 key;
        void *value;
    } entries[3];
} Table_003E5F00;

extern u8 D_001DAA15;
extern void *func_003EA6C0(void *, u32);

s32 func_003EB820(Table_003E5F00 *input_table, u32 input_key, void *input_value) {
    register Table_003E5F00 *table __asm__("$17") = input_table;
    register u32 key __asm__("$16") = input_key;
    register void *value __asm__("$18") = input_value;

    if (table->count < 3 && func_003EA6C0(table, key) == 0) {
        register s32 iteration __asm__("$8") = 0;
        register s32 divisor __asm__("$6") = 3;
        register s32 parity __asm__("$11") = key & 1;
        register u8 *value_base __asm__("$9") = (u8 *)table + 0xC;
        register void *sentinel __asm__("$12") = &D_001DAA15;
        register u8 *key_base __asm__("$10") = (u8 *)table + 8;
        register s32 offset __asm__("$7") = 0;

        do {
            register s32 slot __asm__("$3") = ((key % divisor) + offset) % divisor;
            register s32 byte_offset __asm__("$2") = slot << 3;
            register void **selected __asm__("$5") = (void **)(value_base + byte_offset);
            register void *current __asm__("$4") = *selected;
            register s32 next_offset __asm__("$3");

            __asm__ volatile("" : "+r"(selected));
            if (current == 0) {
                goto found;
            }
            if (current != sentinel) {
                goto next;
            }
found:
            *selected = value;
            *(u32 *)(key_base + byte_offset) = key;
            table->count++;
            return 1;
next:
            iteration++;
            next_offset = offset + 1;
            offset = parity + next_offset;
        } while (iteration < 3);
    }
    return 0;
}
/* localdecomp:end func_003EB820 */

/* localdecomp:start func_003EB8F8 */
extern s32 D_001D97C0[];
extern void func_003EDF20(void *, f32, f32);
s32 func_003EB8F8(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0[0])) {
        func_003EDF20(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB8F8 */

/* localdecomp:start func_003EB968 */
extern s32 D_001D97C0_g;
extern void func_003EDF30();
s32 func_003EB968(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        func_003EDF30(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB968 */

/* localdecomp:start func_003EB9D0 */
extern s32 D_001D97C0_g;
extern void func_003F0D80();
s32 func_003EB9D0(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        func_003F0D80(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB9D0 */

/* localdecomp:start func_003EBA28 */
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
extern s32 D_001D97C0_003EBA28;
extern void func_003F0E00(void *, s32, s16, s16, s32);
s32 func_003EBA28(u8 *p, s32 a, s16 b, s16 c, s32 d) {
    if ((*(VT_3E6108 **)(p + 8))->isA(p, D_001D97C0_003EBA28)) {
        func_003F0E00(p, a, b, c, d);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBA28 */

/* localdecomp:start func_003EBAB8 */
extern u8 D_001DAA13;
extern void *func_003EA5C0(HT_8 *, u32);
s32 func_003EBAB8(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA5C0(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA13) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003EBAB8 */

/* localdecomp:start func_003EBB88 */
extern s32 D_001D97C0[];
extern void func_003EDF48(void *, f32, f32);
s32 func_003EBB88(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0[0])) {
        func_003EDF48(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBB88 */

/* localdecomp:start func_003EBBF8 */
extern s32 D_001D97C0_g;
extern void func_003F0D38(void *, s32);
s32 func_003EBBF8(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        func_003F0D38(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBBF8 */

/* localdecomp:start func_003EBC50 */
extern s32 D_001D97C0_g;
extern void func_003EDE88(void *, s32, s32);
s32 func_003EBC50(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        func_003EDE88(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBC50 */

/* localdecomp:start func_003EBCB8 */
extern s32 D_001D97C0_g;
extern s32 func_003EDEB0();
s32 func_003EBCB8(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        *out = func_003EDEB0(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBCB8 */

/* localdecomp:start func_003EBD20 */
extern s32 D_001D97C0_g;
extern void func_003EDEC0(void *, s32, s32);
s32 func_003EBD20(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        func_003EDEC0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBD20 */

/* localdecomp:start func_003EBD88 */
extern s32 D_001D97C0_g;
extern void func_003EDEF8();
s32 func_003EBD88(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        func_003EDEF8(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBD88 */

/* localdecomp:start func_003EBDF0 */
extern s32 D_001D97C0[];
s32 func_003EBDF0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBDF0 */
