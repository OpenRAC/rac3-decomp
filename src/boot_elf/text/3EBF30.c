#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003EC0D8(void *, s32, void *);
extern s32 func_003EBF30(u8 *p, f32 a, f32 b);
extern s32 func_003EC078(u8 *p, f32 a);
extern s32 func_003EC1B0(u8 *p, f32 a);
extern s32 func_003EC210(u8 *p, f32 a, f32 b);
extern s32 func_003EC280(u8 *p, s32 a);
extern s32 func_003EC3A8(u8 *p, s32 a, s32 b);
extern s32 func_003EC410(u8 *p, s32 a);
extern s32 func_003EC468(u8 *p, f32 a, f32 b);
extern s32 func_003EC4D0(u8 *p, s32 a, s32 b);
extern s32 func_003EC538(u8 *p, f32 a, f32 b);
extern s32 func_003EC5A0();
extern s32 func_003EC608();
extern s32 func_003EC668(u8 *p, s32 a, s32 b);
extern s32 func_003EC6D0(u8 *p, s32 a, u8 *out);
extern s32 func_003EC738(u8 *p, s32 a, s32 b);
extern s32 func_003EC7A0(u8 *p, s32 a, s32 b);
extern s32 func_003EC808(u8 *p, f32 a, f32 b);
typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
/* --- end of declarations from other files --- */

/* localdecomp:start func_003EBF30 */
extern s32 D_001D97C0[];
extern void func_003F0E78(u8 *, s32, f32, f32);
s32 func_003EBF30(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0[0])) {
        func_003F0E78(p, 1, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBF30 */

/* localdecomp:start func_003EBFA0 */
typedef struct {
    u8 pad0[4];
    s32 count;
    struct { u32 key; void *value; } entries[3];
} Table_003E6680;

extern u8 D_001DAA0B;
extern void *func_003EA1B0(void *, u32);

s32 func_003EBFA0(Table_003E6680 *input_table, u32 input_key, void *input_value) {
    register Table_003E6680 *table __asm__("$17") = input_table;
    register u32 key __asm__("$16") = input_key;
    register void *value __asm__("$18") = input_value;

    if (table->count < 3 && func_003EA1B0(table, key) == 0) {
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
/* localdecomp:end func_003EBFA0 */

/* localdecomp:start func_003EC078 */
extern s32 D_001D97C0[];
extern void func_003F0DE8(void *, f32);
s32 func_003EC078(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0[0])) {
        func_003F0DE8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC078 */

/* localdecomp:start func_003EC0D8 */
extern s32 D_001DAA0C_003EC0D8;
__asm__(".extern D_001DAA0C_003EC0D8, 4");
typedef struct { s32 key; s32 val; } E;
typedef struct { s32 pad; s32 n; E e[3]; } T;
extern s32 func_003EA238();
s32 func_003EC0D8(void *pp, s32 k, void *v) {
    T *p = pp;
    if (p->n < 3) {
        if (func_003EA238() == 0) {
            s32 i;
            for (i = 0; i < 3; i++) {
                s32 t = (u32)k % 3; s32 b = k & 1;
                s32 idx = (u32)(t + i * (b + 1)) % 3;
                if (p->e[idx].val == 0 || p->e[idx].val == (s32)&D_001DAA0C_003EC0D8) {
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
/* localdecomp:end func_003EC0D8 */

/* localdecomp:start func_003EC1B0 */
extern s32 D_001D97C0[];
extern void func_003F0E28(void *, f32);
s32 func_003EC1B0(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0[0])) {
        func_003F0E28(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC1B0 */

/* localdecomp:start func_003EC210 */
extern s32 D_001D97C0[];
extern void func_003F0E78(u8 *, s32, f32, f32);
s32 func_003EC210(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0[0])) {
        func_003F0E78(p, 1, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC210 */

/* localdecomp:start func_003EC280 */
extern s32 D_001D97C0_g;
extern s32 func_003F0E40();
s32 func_003EC280(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        func_003F0E40(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC280 */

/* localdecomp:start func_003EC2D8 */
extern u8 D_001DAA19;
extern void *func_003EA8C8(HT_8 *, u32);
s32 func_003EC2D8(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA8C8(t, key) != 0) return 0;
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
/* localdecomp:end func_003EC2D8 */

/* localdecomp:start func_003EC3A8 */
extern s32 D_001D97C0_g;
extern s32 func_003F0E58();
s32 func_003EC3A8(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        func_003F0E58(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC3A8 */

/* localdecomp:start func_003EC410 */
extern s32 D_001D97C0_g;
extern void func_003F1090(void *, s32);
s32 func_003EC410(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97C0_g)) {
        func_003F1090(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC410 */

/* localdecomp:start func_003EC468 */
extern s32 D_001D9760[];
s32 func_003EC468(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9760[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC468 */

/* localdecomp:start func_003EC4D0 */
extern s32 D_001D9760_g;
extern void func_003EDF30();
s32 func_003EC4D0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9760_g)) {
        func_003EDF30(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC4D0 */

/* localdecomp:start func_003EC538 */
extern s32 D_001D9760[];
s32 func_003EC538(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9760[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC538 */

/* localdecomp:start func_003EC5A0 */
typedef struct V_3E6C80 { u8 pad[0x10]; s32 (*fn)(void *, s32); } V_3E6C80;
typedef struct { u8 pad[8]; V_3E6C80 *vt; } O_3E6C80;
extern s32 D_001D9760_003EC5A0;
extern void func_003EF640();
s32 func_003EC5A0(O_3E6C80 *a, s32 b) {
    if (a->vt->fn(a, D_001D9760_003EC5A0) != 0) {
        func_003EF640(a, b, b, b, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC5A0 */

/* localdecomp:start func_003EC608 */
typedef struct S_3E6CE8 S_3E6CE8;
typedef struct { u8 pad[0x10]; s32 (*fn)(S_3E6CE8 *, s32); } V_3E6CE8;
struct S_3E6CE8 { u8 pad[8]; V_3E6CE8 *vt; u8 p2[0x4A-0xC]; s16 h4A; };
extern s32 D_001D9760_003EC608;
extern void func_003EF570();
s32 func_003EC608(S_3E6CE8 *p, s32 b) {
    s32 r;
    if (!p->vt->fn(p, D_001D9760_003EC608)) r = 0; else {
        func_003EF570(p, b);
        p->h4A = 0;
        r = 1;
    }
    return r;
}
/* localdecomp:end func_003EC608 */

/* localdecomp:start func_003EC668 */
extern s32 D_001D9760_g;
extern void func_003EDE88(void *, s32, s32);
s32 func_003EC668(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9760_g)) {
        func_003EDE88(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC668 */

/* localdecomp:start func_003EC6D0 */
extern s32 D_001D9760_g;
extern s32 func_003EDEB0();
s32 func_003EC6D0(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9760_g)) {
        *out = func_003EDEB0(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC6D0 */

/* localdecomp:start func_003EC738 */
extern s32 D_001D9760_g;
extern void func_003EDEC0(void *, s32, s32);
s32 func_003EC738(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9760_g)) {
        func_003EDEC0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC738 */

/* localdecomp:start func_003EC7A0 */
extern s32 D_001D9760_g;
extern void func_003EDEF8();
s32 func_003EC7A0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9760_g)) {
        func_003EDEF8(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC7A0 */

/* localdecomp:start func_003EC808 */
extern s32 D_001D9760[];
s32 func_003EC808(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9760[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC808 */
