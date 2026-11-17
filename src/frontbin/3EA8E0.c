#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003EBD20(void *, s32, void *);
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
extern s32 func_003EB270(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
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
extern s32 func_003EBAA0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
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
extern s32 func_003EC4B8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
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
extern s32 func_003ECBA0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003ECC78(u8 *p, f32 a, f32 b);
extern s32 func_003ECCE0(u8 *p, f32 a, f32 b);
extern s32 func_003ECD48(u8 *p, s32 a, s32 b);
extern s32 func_003ECDB0(u8 *p, f32 a, f32 b);
extern s32 func_003ECE18(u8 *p, s32 a);
extern s32 func_003ECE68();
extern s32 func_003ECF98(u8 *p, s32 a, s32 b);
extern s32 func_003ED000(u8 *p, s32 a, u8 *out);
extern s32 func_003ED068(u8 *p, s32 a, s32 b);
extern s32 func_003ED0D0(u8 *p, s32 a, s32 b);
extern s32 func_003ED138(u8 *p, f32 a, f32 b);
extern s32 func_003ED1A0(u8 *p, f32 a);
extern s32 func_003ED1F8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003ED2D0(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern s32 func_003ED430();
extern s32 func_003ED488();
extern s32 func_003ED5A8(u8 *p, s32 a, s32 b);
extern s32 func_003ED610(u8 *p, s32 a, u8 *out);
extern s32 func_003ED678(u8 *p, s32 a, s32 b);
extern s32 func_003ED6E0(u8 *p, s32 a, s32 b);
extern s32 func_003ED748(u8 *p, f32 a, f32 b);
extern s32 func_003ED7B0(u8 *p, f32 a, f32 b);
extern s32 func_003ED820(u8 *p, s32 a, s32 b);
extern s32 func_003ED888(u8 *p, f32 a, f32 b);
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

typedef struct { u8 b[16]; } V16_func_003E5D08;
extern s32 D_001D9790_func_003EB270;
extern V16_func_003E5D08 D_001D96C0_func_003EB270;
INCLUDE_ASM("asm/nonmatchings/text", func_003EB270);

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

typedef struct { u8 b[16]; } V16_003E6538;
extern s32 D_001D97C0_003EBAA0;
extern V16_003E6538 D_001D96C0;
INCLUDE_ASM("asm/nonmatchings/text", func_003EBAA0);

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

typedef struct { u8 b[16]; } V16_003E6F50;
extern s32 D_001D9760_003EC4B8;
extern V16_003E6F50 D_001D96C0_003EC4B8;
INCLUDE_ASM("asm/nonmatchings/text", func_003EC4B8);

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

typedef struct { u8 b[16]; } V16_003E7638;
extern s32 D_001D9730_003ECBA0;
extern V16_003E7638 D_001D96C0_003ECBA0;
INCLUDE_ASM("asm/nonmatchings/text", func_003ECBA0);

/* localdecomp:start func_003ECC78 */
extern s32 D_001D9730[];
s32 func_003ECC78(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9730[0])) {
        *(f32 *)(p + 0x34) = a;
        *(f32 *)(p + 0x38) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECC78 */

/* localdecomp:start func_003ECCE0 */
extern s32 D_001D97F0[];
s32 func_003ECCE0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECCE0 */

/* localdecomp:start func_003ECD48 */
extern s32 D_001D97F0_g;
extern void func_003EDB78();
s32 func_003ECD48(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        func_003EDB78(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECD48 */

/* localdecomp:start func_003ECDB0 */
extern s32 D_001D97F0[];
s32 func_003ECDB0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECDB0 */

/* localdecomp:start func_003ECE18 */
extern s32 D_001D97F0_g;
s32 func_003ECE18(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        *(s32 *)(p + 0x38) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECE18 */

/* localdecomp:start func_003ECE68 */
typedef struct { s32 pad[4]; s32 (*fn)(void *, s32); } V_3E7900;
typedef struct { s32 a, b; V_3E7900 *vt; u8 pad[0x34]; s32 c; s32 d; } S_3E7900;
extern s32 D_001D97F0_003ECE68;
s32 func_003ECE68(S_3E7900 *s, s32 b, s32 c) {
    if (s->vt->fn(s, D_001D97F0_003ECE68) != 0) {
        s->d = b;
        s->c = c;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECE68 */

/* localdecomp:start func_003ECEC8 */
extern u8 D_001DAA17;
extern void *func_003EA410(HT_8 *, u32);
s32 func_003ECEC8(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA410(t, key) != 0) return 0;
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
/* localdecomp:end func_003ECEC8 */

/* localdecomp:start func_003ECF98 */
extern s32 D_001D97F0_g;
extern void func_003EDAD0(void *, s32, s32);
s32 func_003ECF98(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        func_003EDAD0(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECF98 */

/* localdecomp:start func_003ED000 */
extern s32 D_001D97F0_g;
extern s32 func_003EDAF8();
s32 func_003ED000(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        *out = func_003EDAF8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED000 */

/* localdecomp:start func_003ED068 */
extern s32 D_001D97F0_g;
extern void func_003EDB08(void *, s32, s32);
s32 func_003ED068(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        func_003EDB08(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED068 */

/* localdecomp:start func_003ED0D0 */
extern s32 D_001D97F0_g;
extern void func_003EDB40();
s32 func_003ED0D0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0_g)) {
        func_003EDB40(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED0D0 */

/* localdecomp:start func_003ED138 */
extern s32 D_001D97F0[];
s32 func_003ED138(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED138 */

/* localdecomp:start func_003ED1A0 */
extern s32 D_001D97F0[];
s32 func_003ED1A0(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97F0[0])) {
        *(f32 *)(p + 0x3C) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED1A0 */

typedef struct { u8 b[16]; } V16_003E7C90;
extern s32 D_001D97F0_003ED1F8;
extern V16_003E7C90 D_001D96C0_003ED1F8;
INCLUDE_ASM("asm/nonmatchings/text", func_003ED1F8);

/* localdecomp:start func_003ED2D0 */
extern void func_003EE408(u8 *, f32, f32, f32, f32);
extern s32 D_001D9700[];
s32 func_003ED2D0(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D9700[0]) != 0) {
        func_003EE408((u8 *)arg0, fparg0, fparg1, fparg2, fparg3);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED2D0 */

/* localdecomp:start func_003ED360 */
extern u8 D_001DAA18;
extern void *func_003EA490(HT_8 *, u32);
s32 func_003ED360(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA490(t, key) != 0) return 0;
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
/* localdecomp:end func_003ED360 */

/* localdecomp:start func_003ED430 */
typedef struct S_3E7EC8 S_3E7EC8;
typedef struct { u8 pad[0x10]; s32 (*f10)(S_3E7EC8 *, s32); } V_3E7EC8;
struct S_3E7EC8 { u8 pad[8]; V_3E7EC8 *vt; };
extern s32 D_001D9700_003ED430;
extern s32 func_003EDDA0(S_3E7EC8 *a, s32 b);
s32 func_003ED430(S_3E7EC8 *a, s32 b) {
    if (a->vt->f10(a, D_001D9700_003ED430)) return func_003EDDA0(a, b);
    return 0;
}
/* localdecomp:end func_003ED430 */

/* localdecomp:start func_003ED488 */
typedef struct { s32 pad[4]; s32 (*fn)(void *, void *); } V_3E7F20;
typedef struct { s32 a, b; V_3E7F20 *vt; } S_3E7F20;
extern void *D_001D9700_003ED488[];
extern void func_003EDED8();
s32 func_003ED488(S_3E7F20 *s) {
    if (s->vt->fn(s, D_001D9700_003ED488[0]) == 0) return 0;
    func_003EDED8(s);
    return 1;
}
/* localdecomp:end func_003ED488 */

/* localdecomp:start func_003ED4D8 */
extern u8 D_001DAA1A;
extern void *func_003EA590(HT_8 *, u32);
s32 func_003ED4D8(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA590(t, key) != 0) return 0;
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
/* localdecomp:end func_003ED4D8 */

/* localdecomp:start func_003ED5A8 */
extern s32 D_001D9700_g;
extern void func_003EDAD0(void *, s32, s32);
s32 func_003ED5A8(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700_g)) {
        func_003EDAD0(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED5A8 */

/* localdecomp:start func_003ED610 */
extern s32 D_001D9700_g;
extern s32 func_003EDAF8();
s32 func_003ED610(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700_g)) {
        *out = func_003EDAF8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED610 */

/* localdecomp:start func_003ED678 */
extern s32 D_001D9700_g;
extern void func_003EDB08(void *, s32, s32);
s32 func_003ED678(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700_g)) {
        func_003EDB08(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED678 */

/* localdecomp:start func_003ED6E0 */
extern s32 D_001D9700_g;
extern void func_003EDB40();
s32 func_003ED6E0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700_g)) {
        func_003EDB40(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED6E0 */

/* localdecomp:start func_003ED748 */
extern s32 D_001D9700[];
s32 func_003ED748(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED748 */

/* localdecomp:start func_003ED7B0 */
extern s32 D_001D9700[];
extern void func_003EDB68(void *, f32, f32);
s32 func_003ED7B0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700[0])) {
        func_003EDB68(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED7B0 */

/* localdecomp:start func_003ED820 */
extern s32 D_001D9700_g;
extern void func_003EDB78();
s32 func_003ED820(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700_g)) {
        func_003EDB78(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED820 */

/* localdecomp:start func_003ED888 */
extern s32 D_001D9700[];
extern void func_003EDB90(void *, f32, f32);
s32 func_003ED888(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9700[0])) {
        func_003EDB90(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED888 */

LINKER_REMNANT("asm/remnants", func_003ED8F8);
