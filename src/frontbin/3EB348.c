#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003EB418(u8 *p, s32 a);
extern s32 func_003EB540(u8 *p, f32 a, f32 b);
extern s32 func_003EB5B0(u8 *p, s32 a, s32 b);
extern s32 func_003EB618(u8 *p, s32 a);
extern s32 func_003EB670(u8 *p, s32 a, s16 b, s16 c, s32 d);
extern s32 func_003EB7D0(u8 *p, f32 a, f32 b);
extern s32 func_003EB840(u8 *p, s32 a);
extern s32 func_003EB898(u8 *p, s32 a, s32 b);
extern s32 func_003EB900(u8 *p, s32 a, u8 *out);
extern s32 func_003EB968(u8 *p, s32 a, s32 b);
extern s32 func_003EB9D0(u8 *p, s32 a, s32 b);
extern s32 func_003EBA38(u8 *p, f32 a, f32 b);
typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
/* --- end of declarations from other files --- */

/* declarations of 3EA8E0.c's earlier functions */
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
extern s32 D_001D9790_g;
extern void func_003EDB78();
extern void func_003EDAD0(void *, s32, s32);
extern s32 func_003EDAF8();
extern void func_003EDB08(void *, s32, s32);
extern void func_003EDB40();

/* localdecomp:start func_003EB348 */
extern u8 D_001DAA11;
extern void *func_003EA108(HT_8 *, u32);
s32 func_003EB348(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA108(t, key) != 0) return 0;
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
/* localdecomp:end func_003EB348 */

/* localdecomp:start func_003EB418 */
extern s32 D_001D9790_g;
s32 func_003EB418(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9790_g)) {
        *(s32 *)(p + 0x58) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB418 */

/* localdecomp:start func_003EB468 */
typedef struct {
    u8 pad0[4];
    s32 count;
    struct {
        u32 key;
        void *value;
    } entries[3];
} Table_003E5F00;

extern u8 D_001DAA15;
extern void *func_003EA308(void *, u32);

s32 func_003EB468(Table_003E5F00 *input_table, u32 input_key, void *input_value) {
    register Table_003E5F00 *table __asm__("$17") = input_table;
    register u32 key __asm__("$16") = input_key;
    register void *value __asm__("$18") = input_value;

    if (table->count < 3 && func_003EA308(table, key) == 0) {
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
/* localdecomp:end func_003EB468 */

/* localdecomp:start func_003EB540 */
extern s32 D_001D97C0[];
extern void func_003EDB68(void *, f32, f32);
s32 func_003EB540(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0[0])) {
        func_003EDB68(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB540 */

/* localdecomp:start func_003EB5B0 */
extern s32 D_001D97C0_g;
extern void func_003EDB78();
s32 func_003EB5B0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        func_003EDB78(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB5B0 */

/* localdecomp:start func_003EB618 */
extern s32 D_001D97C0_g;
extern void func_003F09C8();
s32 func_003EB618(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        func_003F09C8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB618 */

/* localdecomp:start func_003EB670 */
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
extern s32 D_001D97C0_003EB670;
extern void func_003F0A48(void *, s32, s16, s16, s32);
s32 func_003EB670(u8 *p, s32 a, s16 b, s16 c, s32 d) {
    if ((*(VT_3E6108 **)(p + 8))->isA(p, D_001D97C0_003EB670)) {
        func_003F0A48(p, a, b, c, d);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB670 */

/* localdecomp:start func_003EB700 */
extern u8 D_001DAA13;
extern void *func_003EA208(HT_8 *, u32);
s32 func_003EB700(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA208(t, key) != 0) return 0;
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
/* localdecomp:end func_003EB700 */

/* localdecomp:start func_003EB7D0 */
extern s32 D_001D97C0[];
extern void func_003EDB90(void *, f32, f32);
s32 func_003EB7D0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0[0])) {
        func_003EDB90(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB7D0 */

/* localdecomp:start func_003EB840 */
extern s32 D_001D97C0_g;
extern void func_003F0980(void *, s32);
s32 func_003EB840(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        func_003F0980(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB840 */

/* localdecomp:start func_003EB898 */
extern s32 D_001D97C0_g;
extern void func_003EDAD0(void *, s32, s32);
s32 func_003EB898(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        func_003EDAD0(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB898 */

/* localdecomp:start func_003EB900 */
extern s32 D_001D97C0_g;
extern s32 func_003EDAF8();
s32 func_003EB900(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        *out = func_003EDAF8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB900 */

/* localdecomp:start func_003EB968 */
extern s32 D_001D97C0_g;
extern void func_003EDB08(void *, s32, s32);
s32 func_003EB968(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        func_003EDB08(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB968 */

/* localdecomp:start func_003EB9D0 */
extern s32 D_001D97C0_g;
extern void func_003EDB40();
s32 func_003EB9D0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        func_003EDB40(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB9D0 */

/* localdecomp:start func_003EBA38 */
extern s32 D_001D97C0[];
s32 func_003EBA38(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBA38 */
