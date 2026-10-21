#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003F2738();
extern s32 func_003EDF90();
extern void func_003EE038();
extern s32 func_003EC0D8(void *, s32, void *);
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
extern s32 func_003EB628(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
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
extern s32 func_003EBE58(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
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
extern s32 func_003EC870(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
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
extern s32 func_003ECF58(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003ED030(u8 *p, f32 a, f32 b);
extern s32 func_003ED098(u8 *p, f32 a, f32 b);
extern s32 func_003ED100(u8 *p, s32 a, s32 b);
extern s32 func_003ED168(u8 *p, f32 a, f32 b);
extern s32 func_003ED1D0(u8 *p, s32 a);
extern s32 func_003ED220();
extern s32 func_003ED350(u8 *p, s32 a, s32 b);
extern s32 func_003ED3B8(u8 *p, s32 a, u8 *out);
extern s32 func_003ED420(u8 *p, s32 a, s32 b);
extern s32 func_003ED488(u8 *p, s32 a, s32 b);
extern s32 func_003ED4F0(u8 *p, f32 a, f32 b);
extern s32 func_003ED558(u8 *p, f32 a);
extern s32 func_003ED5B0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
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

typedef struct { u8 b[16]; } V16_func_003E5D08;
extern s32 D_001D9790_func_003E5D08;
extern V16_func_003E5D08 D_001D96C0_func_003E5D08;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EB628);

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

typedef struct { u8 b[16]; } V16_003E6538;
extern s32 D_001D97C0_003EBE58;
extern V16_003E6538 D_001D96C0;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EBE58);

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

typedef struct { u8 b[16]; } V16_003E6F50;
extern s32 D_001D9760_003EC870;
extern V16_003E6F50 D_001D96C0_003EC870;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EC870);

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

typedef struct { u8 b[16]; } V16_003E7638;
extern s32 D_001D9730_003ECF58;
extern V16_003E7638 D_001D96C0_003ECF58;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003ECF58);

/* localdecomp:start func_003ED030 */
extern s32 D_001D9730[];
s32 func_003ED030(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730[0])) {
        *(f32 *)(p + 0x34) = a;
        *(f32 *)(p + 0x38) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED030 */

/* localdecomp:start func_003ED098 */
extern s32 D_001D97F0[];
s32 func_003ED098(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED098 */

/* localdecomp:start func_003ED100 */
extern s32 D_001D97F0_g;
extern void func_003EDF30();
s32 func_003ED100(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        func_003EDF30(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED100 */

/* localdecomp:start func_003ED168 */
extern s32 D_001D97F0[];
s32 func_003ED168(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED168 */

/* localdecomp:start func_003ED1D0 */
extern s32 D_001D97F0_g;
s32 func_003ED1D0(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        *(s32 *)(p + 0x38) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED1D0 */

/* localdecomp:start func_003ED220 */
typedef struct { s32 pad[4]; s32 (*fn)(void *, s32); } V_3E7900;
typedef struct { s32 a, b; V_3E7900 *vt; u8 pad[0x34]; s32 c; s32 d; } S_3E7900;
extern s32 D_001D97F0_003ED220;
s32 func_003ED220(S_3E7900 *s, s32 b, s32 c) {
    if (s->vt->fn(s, D_001D97F0_003ED220) != 0) {
        s->d = b;
        s->c = c;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED220 */

/* localdecomp:start func_003ED280 */
extern u8 D_001DAA17;
extern void *func_003EA7C8(HT_8 *, u32);
s32 func_003ED280(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA7C8(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA17) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003ED280 */

/* localdecomp:start func_003ED350 */
extern s32 D_001D97F0_g;
extern void func_003EDE88(void *, s32, s32);
s32 func_003ED350(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        func_003EDE88(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED350 */

/* localdecomp:start func_003ED3B8 */
extern s32 D_001D97F0_g;
extern s32 func_003EDEB0();
s32 func_003ED3B8(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        *out = func_003EDEB0(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED3B8 */

/* localdecomp:start func_003ED420 */
extern s32 D_001D97F0_g;
extern void func_003EDEC0(void *, s32, s32);
s32 func_003ED420(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        func_003EDEC0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED420 */

/* localdecomp:start func_003ED488 */
extern s32 D_001D97F0_g;
extern void func_003EDEF8();
s32 func_003ED488(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        func_003EDEF8(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED488 */

/* localdecomp:start func_003ED4F0 */
extern s32 D_001D97F0[];
s32 func_003ED4F0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED4F0 */

/* localdecomp:start func_003ED558 */
extern s32 D_001D97F0[];
s32 func_003ED558(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0[0])) {
        *(f32 *)(p + 0x3C) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED558 */

typedef struct { u8 b[16]; } V16_003E7C90;
extern s32 D_001D97F0_003ED5B0;
extern V16_003E7C90 D_001D96C0_003ED5B0;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003ED5B0);

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

typedef struct { u8 p0[8]; void *f8; u8 pC[4]; s32 f10, f14, f18, f1C; f32 f20, f24; s32 f28; } O_3E8420;
extern u8 D_001D96D8[];
extern void **func_003E74A0();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EDD40);

LINKER_REMNANT("asm/boot_elf/remnants", func_003EDE80);

/* localdecomp:start func_003EDE88 */
void func_003EDE88(void *p, s32 mask, s32 set) {
    if (set != 0) {
        *(s32 *)((u8 *)p + 0xC) |= mask;
    } else {
        *(s32 *)((u8 *)p + 0xC) &= ~mask;
    }
}
/* localdecomp:end func_003EDE88 */

/* localdecomp:start func_003EDEB0 */
s32 func_003EDEB0(void *p, s32 mask) {
    return (*(s32 *)((u8 *)p + 0xC) & mask) != 0;
}
/* localdecomp:end func_003EDEB0 */

/* localdecomp:start func_003EDEC0 */
void func_003EDEC0(void *p, s32 a, s32 b) {
    *(u32 *)((u8 *)p + 0xC) = (((*(u32 *)((u8 *)p + 0xC) & ~0x600) | (a << 9)) & ~0x1800) | (b << 11);
}
/* localdecomp:end func_003EDEC0 */

/* localdecomp:start func_003EDEF8 */
void func_003EDEF8(void *p, s32 *a, s32 *b) {
    *a = (*(u32 *)((u8 *)p + 0xC) >> 9) & 3;
    *b = (*(u32 *)((u8 *)p + 0xC) >> 11) & 3;
}
/* localdecomp:end func_003EDEF8 */

/* localdecomp:start func_003EDF20 */
void func_003EDF20(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x10) = x;
    *(f32 *)((u8 *)p + 0x14) = y;
}
/* localdecomp:end func_003EDF20 */

/* localdecomp:start func_003EDF30 */
void func_003EDF30(void *a0, f32 *a1, f32 *a2) {
    *a1 = *(f32 *)((u8 *)a0 + 0x10);
    *a2 = *(f32 *)((u8 *)a0 + 0x14);
}
/* localdecomp:end func_003EDF30 */

/* localdecomp:start func_003EDF48 */
void func_003EDF48(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x18) = x;
    *(f32 *)((u8 *)p + 0x1C) = y;
}
/* localdecomp:end func_003EDF48 */

/* localdecomp:start func_003EDF58 */
s32 func_003EDF58(void) {
    return 1;
}
/* localdecomp:end func_003EDF58 */

/* localdecomp:start func_003EDF60 */
s32 func_003EDF60(s32 p, s32 k) {
    if (k == 1) {
        return 1;
    }
    return func_003E74B8(p, k);   /* defined earlier in text.c */
}
/* localdecomp:end func_003EDF60 */

/* localdecomp:start func_003EDF90 */
typedef struct V_3E8670 { u8 pad[0x14]; s32 (*fn)(void *, s32); } V_3E8670;
typedef struct { u8 pad[8]; V_3E8670 *vt; } O_3E8670;
extern s32 func_003EDEB0();
s32 func_003EDF90(O_3E8670 *a, s32 b) {
    if (func_003EDEB0(a, 1) != 0) return a->vt->fn(a, b);
    return 0;
}
/* localdecomp:end func_003EDF90 */

/* localdecomp:start func_003EDFE8 */
typedef struct { u8 pad[0x18]; void (*fn)(void *, s32); } V_3E86C8;
typedef struct { u8 pad[8]; V_3E86C8 *vt; } S_3E86C8;
extern s32 func_003EDEB0();
void func_003EDFE8(S_3E86C8 *a, s32 b) {
    if (func_003EDEB0(a, 1)) a->vt->fn(a, b);
}
/* localdecomp:end func_003EDFE8 */

/* localdecomp:start func_003EE038 */
extern void func_003E75D0(void);
extern void func_003E75F0(void);
extern s32 func_003EDEB0(void *, s32);
void func_003EE038(void *arg0, s32 arg1) {
    if (func_003EDEB0(arg0, 1) != 0) {
        (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x1C))(arg0, arg1);
    }
    if (func_003EDEB0(arg0, 0x4000) != 0) {
        func_003E75F0();
        func_003E75D0();
    }
}
/* localdecomp:end func_003EE038 */

/* localdecomp:start func_003EE0A8 */
s32 func_003EE0A8(void) {
}
/* localdecomp:end func_003EE0A8 */

/* localdecomp:start func_003EE0B0 */
extern char D_001D9670[];
void func_003EE0B0(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D9670; if (f & 1) func_003F2738(p); }
/* localdecomp:end func_003EE0B0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003EE0E0);
