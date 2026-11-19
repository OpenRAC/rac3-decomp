#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003EBD20(void *, s32, void *);
extern s32 func_003EBB78(u8 *p, f32 a, f32 b);
extern s32 func_003EBCC0(u8 *p, f32 a);
extern s32 func_003EBDF8(u8 *p, f32 a);
extern s32 func_003EBE58(u8 *p, f32 a, f32 b);
extern s32 func_003EBEC8(u8 *p, s32 a);
extern s32 func_003EBFF0(u8 *p, s32 a, s32 b);
extern s32 func_003EC058(u8 *p, s32 a);
extern s32 func_003EC0B0(u8 *p, f32 a, f32 b);
extern s32 func_003EC118(u8 *p, s32 a, s32 b);
extern s32 func_003EC180(u8 *p, f32 a, f32 b);
extern s32 func_003EC1E8();
extern s32 func_003EC250();
extern s32 func_003EC2B0(u8 *p, s32 a, s32 b);
extern s32 func_003EC318(u8 *p, s32 a, u8 *out);
extern s32 func_003EC380(u8 *p, s32 a, s32 b);
extern s32 func_003EC3E8(u8 *p, s32 a, s32 b);
extern s32 func_003EC450(u8 *p, f32 a, f32 b);
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
extern s32 D_001D97C0[];
extern s32 D_001D97C0_g;

/* localdecomp:start func_003EBB78 */
extern s32 D_001D97C0[];
extern void func_003F0AC0(u8 *, s32, f32, f32);
s32 func_003EBB78(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0[0])) {
        func_003F0AC0(p, 1, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBB78 */

/* localdecomp:start func_003EBBE8 */
typedef struct {
    u8 pad0[4];
    s32 count;
    struct { u32 key; void *value; } entries[3];
} Table_003E6680;

extern u8 D_001DAA0B;
extern void *func_003E9DF8(void *, u32);

s32 func_003EBBE8(Table_003E6680 *input_table, u32 input_key, void *input_value) {
    register Table_003E6680 *table __asm__("$17") = input_table;
    register u32 key __asm__("$16") = input_key;
    register void *value __asm__("$18") = input_value;

    if (table->count < 3 && func_003E9DF8(table, key) == 0) {
        register s32 iteration __asm__("$8") = 0;
        register s32 divisor __asm__("$6") = 3;
        register s32 parity __asm__("$11") = key & 1;
        register u8 *value_base __asm__("$9") = (u8 *)table + 0xC;
        register void *sentinel __asm__("$12") = &D_001DAA0B;
        register u8 *key_base __asm__("$10") = (u8 *)table + 8;
        register s32 offset __asm__("$7") = 0;

        do {
            register s32 slot __asm__("$3") = ((key % divisor) + offset) % divisor;
            register s32 byte_offset __asm__("$2") = slot << 3;
            register void **selected __asm__("$5") = (void **)(value_base + byte_offset);
            register void *current __asm__("$4") = *selected;
            register s32 next_offset __asm__("$3");

            __asm__ volatile("" : "+r"(selected));
            if (current == 0) goto found;
            if (current != sentinel) goto next;
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
/* localdecomp:end func_003EBBE8 */

/* localdecomp:start func_003EBCC0 */
extern s32 D_001D97C0[];
extern void func_003F0A30(void *, f32);
s32 func_003EBCC0(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0[0])) {
        func_003F0A30(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBCC0 */

/* localdecomp:start func_003EBD20 */
extern s32 D_001DAA0C_003EBD20;
__asm__(".extern D_001DAA0C_003EBD20, 4");
typedef struct { s32 key; s32 val; } E;
typedef struct { s32 pad; s32 n; E e[3]; } T;
extern s32 func_003E9E80();
s32 func_003EBD20(void *pp, s32 k, void *v) {
    T *p = pp;
    if (p->n < 3) {
        if (func_003E9E80() == 0) {
            s32 i;
            for (i = 0; i < 3; i++) {
                s32 t = (u32)k % 3; s32 b = k & 1;
                s32 idx = (u32)(t + i * (b + 1)) % 3;
                if (p->e[idx].val == 0 || p->e[idx].val == (s32)&D_001DAA0C_003EBD20) {
                    p->e[idx].val = (s32)v;
                    p->e[idx].key = k;
                    p->n++;
                    return 1;
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_003EBD20 */

/* localdecomp:start func_003EBDF8 */
extern s32 D_001D97C0[];
extern void func_003F0A70(void *, f32);
s32 func_003EBDF8(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0[0])) {
        func_003F0A70(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBDF8 */

/* localdecomp:start func_003EBE58 */
extern s32 D_001D97C0[];
extern void func_003F0AC0(u8 *, s32, f32, f32);
s32 func_003EBE58(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0[0])) {
        func_003F0AC0(p, 1, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBE58 */

/* localdecomp:start func_003EBEC8 */
extern s32 D_001D97C0_g;
extern s32 func_003F0A88();
s32 func_003EBEC8(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        func_003F0A88(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBEC8 */

/* localdecomp:start func_003EBF20 */
extern u8 D_001DAA19;
extern void *func_003EA510(HT_8 *, u32);
s32 func_003EBF20(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA510(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA19) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003EBF20 */

/* localdecomp:start func_003EBFF0 */
extern s32 D_001D97C0_g;
extern s32 func_003F0AA0();
s32 func_003EBFF0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        func_003F0AA0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBFF0 */

/* localdecomp:start func_003EC058 */
extern s32 D_001D97C0_g;
extern void func_003F0CD8(void *, s32);
s32 func_003EC058(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        func_003F0CD8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC058 */

/* localdecomp:start func_003EC0B0 */
extern s32 D_001D9760[];
s32 func_003EC0B0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9760[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC0B0 */

/* localdecomp:start func_003EC118 */
extern s32 D_001D9760_g;
extern void func_003EDB78();
s32 func_003EC118(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9760_g)) {
        func_003EDB78(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC118 */

/* localdecomp:start func_003EC180 */
extern s32 D_001D9760[];
s32 func_003EC180(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9760[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC180 */

/* localdecomp:start func_003EC1E8 */
typedef struct V_3E6C80 { u8 pad[0x10]; s32 (*fn)(void *, s32); } V_3E6C80;
typedef struct { u8 pad[8]; V_3E6C80 *vt; } O_3E6C80;
extern s32 D_001D9760_003EC1E8;
extern void func_003EF288();
s32 func_003EC1E8(O_3E6C80 *a, s32 b) {
    if (a->vt->fn(a, D_001D9760_003EC1E8) != 0) {
        func_003EF288(a, b, b, b, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC1E8 */

/* localdecomp:start func_003EC250 */
typedef struct S_3E6CE8 S_3E6CE8;
typedef struct { u8 pad[0x10]; s32 (*fn)(S_3E6CE8 *, s32); } V_3E6CE8;
struct S_3E6CE8 { u8 pad[8]; V_3E6CE8 *vt; u8 p2[0x4A-0xC]; s16 h4A; };
extern s32 D_001D9760_003EC250;
extern void func_003EF1B8();
s32 func_003EC250(S_3E6CE8 *p, s32 b) {
    s32 r;
    if (!p->vt->fn(p, D_001D9760_003EC250)) r = 0; else {
        func_003EF1B8(p, b);
        p->h4A = 0;
        r = 1;
    }
    return r;
}
/* localdecomp:end func_003EC250 */

/* localdecomp:start func_003EC2B0 */
extern s32 D_001D9760_g;
extern void func_003EDAD0(void *, s32, s32);
s32 func_003EC2B0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9760_g)) {
        func_003EDAD0(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC2B0 */

/* localdecomp:start func_003EC318 */
extern s32 D_001D9760_g;
extern s32 func_003EDAF8();
s32 func_003EC318(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9760_g)) {
        *out = func_003EDAF8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC318 */

/* localdecomp:start func_003EC380 */
extern s32 D_001D9760_g;
extern void func_003EDB08(void *, s32, s32);
s32 func_003EC380(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9760_g)) {
        func_003EDB08(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC380 */

/* localdecomp:start func_003EC3E8 */
extern s32 D_001D9760_g;
extern void func_003EDB40();
s32 func_003EC3E8(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9760_g)) {
        func_003EDB40(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC3E8 */

/* localdecomp:start func_003EC450 */
extern s32 D_001D9760[];
s32 func_003EC450(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9760[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC450 */
