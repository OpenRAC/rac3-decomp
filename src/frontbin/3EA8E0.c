#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003F2380();
extern s32 func_003EDF58();
extern void *func_003F1CA8();
extern void *func_003EF110();
extern void *func_003EFF18();
extern s32 func_003EDBD8();
extern void func_003EDC80();
extern void **func_003F2208(void **);
void func_003EFE98(void *, s32);
extern void func_003EFFE8(void *p, f32, f32);
extern void func_003EFFA0(u8 *p, u8, s32);
extern void func_003EE160(void *p, s32, s32);
extern s32 func_003F0BE8(u8 *arg0, s32, s32);
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
extern void *func_003EE760();
extern void *func_003F0708();
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

typedef struct { u8 p0[8]; void *f8; u8 pC[4]; s32 f10, f14, f18, f1C; f32 f20, f24; s32 f28; } O_3E8420;
extern u8 D_001D96D8[];
extern void **func_003E70E8();
INCLUDE_ASM("asm/nonmatchings/text", func_003ED988);

LINKER_REMNANT("asm/remnants", func_003EDAC8);

/* localdecomp:start func_003EDAD0 */
void func_003EDAD0(void *p, s32 mask, s32 set) {
    if (set != 0) {
        *(s32 *)((u8 *)p + 0xC) |= mask;
    } else {
        *(s32 *)((u8 *)p + 0xC) &= ~mask;
    }
}
/* localdecomp:end func_003EDAD0 */

/* localdecomp:start func_003EDAF8 */
s32 func_003EDAF8(void *p, s32 mask) {
    return (*(s32 *)((u8 *)p + 0xC) & mask) != 0;
}
/* localdecomp:end func_003EDAF8 */

/* localdecomp:start func_003EDB08 */
void func_003EDB08(void *p, s32 a, s32 b) {
    *(u32 *)((u8 *)p + 0xC) = (((*(u32 *)((u8 *)p + 0xC) & ~0x600) | (a << 9)) & ~0x1800) | (b << 11);
}
/* localdecomp:end func_003EDB08 */

/* localdecomp:start func_003EDB40 */
void func_003EDB40(void *p, s32 *a, s32 *b) {
    *a = (*(u32 *)((u8 *)p + 0xC) >> 9) & 3;
    *b = (*(u32 *)((u8 *)p + 0xC) >> 11) & 3;
}
/* localdecomp:end func_003EDB40 */

/* localdecomp:start func_003EDB68 */
void func_003EDB68(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x10) = x;
    *(f32 *)((u8 *)p + 0x14) = y;
}
/* localdecomp:end func_003EDB68 */

/* localdecomp:start func_003EDB78 */
void func_003EDB78(void *a0, f32 *a1, f32 *a2) {
    *a1 = *(f32 *)((u8 *)a0 + 0x10);
    *a2 = *(f32 *)((u8 *)a0 + 0x14);
}
/* localdecomp:end func_003EDB78 */

/* localdecomp:start func_003EDB90 */
void func_003EDB90(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x18) = x;
    *(f32 *)((u8 *)p + 0x1C) = y;
}
/* localdecomp:end func_003EDB90 */

/* localdecomp:start func_003EDBA0 */
s32 func_003EDBA0(void) {
    return 1;
}
/* localdecomp:end func_003EDBA0 */

/* localdecomp:start func_003EDBA8 */
s32 func_003EDBA8(s32 p, s32 k) {
    if (k == 1) {
        return 1;
    }
    return func_003E7100(p, k);   /* defined earlier in text.c */
}
/* localdecomp:end func_003EDBA8 */

/* localdecomp:start func_003EDBD8 */
typedef struct V_3E8670 { u8 pad[0x14]; s32 (*fn)(void *, s32); } V_3E8670;
typedef struct { u8 pad[8]; V_3E8670 *vt; } O_3E8670;
extern s32 func_003EDAF8();
s32 func_003EDBD8(O_3E8670 *a, s32 b) {
    if (func_003EDAF8(a, 1) != 0) return a->vt->fn(a, b);
    return 0;
}
/* localdecomp:end func_003EDBD8 */

/* localdecomp:start func_003EDC30 */
typedef struct { u8 pad[0x18]; void (*fn)(void *, s32); } V_3E86C8;
typedef struct { u8 pad[8]; V_3E86C8 *vt; } S_3E86C8;
extern s32 func_003EDAF8();
void func_003EDC30(S_3E86C8 *a, s32 b) {
    if (func_003EDAF8(a, 1)) a->vt->fn(a, b);
}
/* localdecomp:end func_003EDC30 */

/* localdecomp:start func_003EDC80 */
extern void func_003E7218(void);
extern void func_003E7238(void);
extern s32 func_003EDAF8(void *, s32);
void func_003EDC80(void *arg0, s32 arg1) {
    if (func_003EDAF8(arg0, 1) != 0) {
        (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x1C))(arg0, arg1);
    }
    if (func_003EDAF8(arg0, 0x4000) != 0) {
        func_003E7238();
        func_003E7218();
    }
}
/* localdecomp:end func_003EDC80 */

/* localdecomp:start func_003EDCF0 */
void func_003EDCF0(void *a, f32 *b) {
}
/* localdecomp:end func_003EDCF0 */

/* localdecomp:start func_003EDCF8 */
extern char D_001D9670[];
void func_003EDCF8(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D9670; if (f & 1) func_003F2380(p); }
/* localdecomp:end func_003EDCF8 */

LINKER_REMNANT("asm/remnants", func_003EDD28);

extern f32 D_001D9698;
extern f32 D_001D969C;
extern void func_003A9500(s32, s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003EDD40);

typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E8838;
typedef struct { s32 *e[16]; s32 pad[2]; s32 n; } O_003E8838;
typedef struct { u8 p0[0x2C]; O_003E8838 *x2C; } T_003E8838;
extern S_003E8838 D_001DA938_003EDDA0[];
extern s32 *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E6378();
extern s32 D_001D96D0;
extern s32 func_003E7118();
extern void func_003E7108();
INCLUDE_ASM("asm/nonmatchings/text", func_003EDDA0);

/* localdecomp:start func_003EDED8 */
extern s32 func_003E7118();
typedef struct { s32 a[0x12]; s32 x48; } S_E8;
typedef struct { u8 p[0x2C]; S_E8 *x2C; } T_E8;
void func_003EDED8(T_E8 *a0) {
    s32 i;
    for (i = 0; i < a0->x2C->x48; i++) {
        s32 *p = (s32 *)((u8 *)(i << 2) + (s32)a0->x2C);
        if (*p != 0) {
            func_003E7118(*p);
        }
        *p = 0;
    }
}
/* localdecomp:end func_003EDED8 */

typedef struct { s32 *arr[16]; s32 x40, x44, x48, x4C, x50, x54; f32 x58, x5C; } O_3E89F0;
typedef struct { u8 p0[8]; void *f8; u8 p1[0x2C - 0xC]; O_3E89F0 *x2C; } T_3E89F0;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); } VT_3E89F0;
extern u8 D_001D9708[8];
void **func_003E6CC0(s32 *, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003EDF58);

typedef struct { s32 *arr[16]; s32 x40; s32 x44; } O_3E8AD0;
typedef struct { u8 p0[8]; void *f8; u8 p1[0x2C - 0xC]; O_3E8AD0 *x2C; } T_3E8AD0;
typedef struct { u8 p0[4]; s32 f4; } S_3E8AD0;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); s32 (*fC)(); } VT_3E8AD0;
extern u8 D_001D9708[8];
extern u8 D_001D9670_003EE038[8];
extern S_3E8AD0 D_001DA938_003EE038[];
extern s32 *func_003E6C08();
extern s32 **func_003E6CC0_003EE038();
extern s32 func_003E7118();
INCLUDE_ASM("asm/nonmatchings/text", func_003EE038);

/* localdecomp:start func_003EE160 */
void func_003EE160(void *p, s32 m, s32 set) {
    if (set != 0) {
        *(*(u8 **)((u8 *)p + 0x2C) + 0x4C) |= m;
    } else {
        *(*(u8 **)((u8 *)p + 0x2C) + 0x4C) &= ~m;
    }
}
/* localdecomp:end func_003EE160 */

/* localdecomp:start func_003EE190 */
s32 func_003EE190(void *a0, s32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    return (*(u8 *)((u8 *)p + 0x4c) & a1) != 0;
}
/* localdecomp:end func_003EE190 */

typedef struct { u8 b[16]; } B16_3E8C40;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3E8C40;
extern s32 func_0011A264(void *, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003EE1A8);
TEXT_PADDING(2);

/* localdecomp:start func_003EE408 */
void func_003EE408(u8 *p, f32 a, f32 b, f32 c, f32 d) {
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x50) = a;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x58) = b;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x54) = c;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x5C) = d;
}
/* localdecomp:end func_003EE408 */

typedef struct O_3E8EC8 O_3E8EC8F;
typedef struct { u8 p0[0x20]; void (*f20)(O_3E8EC8F *, s32, f32 *, s32); } V_3E8EC8;
typedef struct { s32 *tbl[1]; } L_3E8EC8;
typedef struct { u8 p0[0x48]; s32 f48; } L2_3E8EC8;
typedef struct O_3E8EC8 { u8 p0[8]; V_3E8EC8 *f8; u8 pC[0x20]; struct { s32 *e[1]; u8 pad[0x44]; s32 n; } *f2C; } O_3E8EC8;
extern void func_003EDCF0();
extern void func_003EDD40(f32, f32, f32, f32);
/* localdecomp:start func_003EE430 */
extern s32 func_003EE190();
void func_003EE430(O_3E8EC8 *self, s32 b) {
    f32 v[4];
    s32 i;
    self->f8->f20(self, b, v, 1);
    func_003EDCF0(self, v);
    if (func_003EE190(self, 1)) {
        func_003EDD40(v[0], v[1], v[2], v[3]);
    }
    for (i = 0; i < self->f2C->n; i++) {
        func_003EDC80(((s32 **)self->f2C)[i], b);
    }
    if (func_003EE190(self, 1)) {
        func_003EDD40(0.0f, 0.0f, 1.0f, 1.0f);
    }
}
/* localdecomp:end func_003EE430 */

/* localdecomp:start func_003EE518 */
typedef struct { u8 b[16]; } B16_3E8FB0;
typedef struct { u8 p0[8]; s32 (**vt)(); } C_3E8FB0;
typedef struct { s32 *e[1]; u8 p0[0x40]; C_3E8FB0 *f44; s32 n; s32 p1; f32 f50, f54, f58, f5C; } S_3E8FB0;
typedef struct { u8 p0[0x2C]; S_3E8FB0 *f2C; } O_3E8FB0;
extern s32 func_003EDBD8();
s32 func_003EE518(O_3E8FB0 *self, f32 *b) {
    B16_3E8FB0 t;
    S_3E8FB0 *s;
    f32 dx, dy;
    s32 i;
    s = self->f2C;
    t = *(B16_3E8FB0 *)b;
    dx = b[2] - b[0];
    dy = b[3] - b[1];
    ((f32 *)&t)[0] = dx * s->f50 + b[0];
    ((f32 *)&t)[1] = dy * s->f54 + b[1];
    ((f32 *)&t)[2] = dx * s->f58 + b[0];
    ((f32 *)&t)[3] = dy * s->f5C + b[1];
    if (s->f44 != 0) {
        ((s32 (*)())(s->f44->vt[0x14 / 4]))(s->f44, &t, s);
    } else {
        for (i = 0; i < self->f2C->n; i++) {
            func_003EDBD8(((s32 **)self->f2C)[i], b);
        }
    }
    return 1;
}
/* localdecomp:end func_003EE518 */

/* localdecomp:start func_003EE630 */
typedef struct { u8 b[16]; } B16_3E90C8;
typedef struct { s32 *e[1]; u8 p0[0x44]; s32 n; s32 p1; f32 f50, f54, f58, f5C; } S_3E90C8;
typedef struct { u8 p0[0x2C]; S_3E90C8 *f2C; } O_3E90C8;
extern void func_003EDC30();
void func_003EE630(O_3E90C8 *self, f32 *b) {
    B16_3E90C8 t;
    S_3E90C8 *s;
    f32 dx, dy;
    s32 i;
    s = self->f2C;
    t = *(B16_3E90C8 *)b;
    dx = b[2] - b[0];
    dy = b[3] - b[1];
    ((f32 *)&t)[0] = dx * s->f50 + b[0];
    ((f32 *)&t)[1] = dy * s->f54 + b[1];
    ((f32 *)&t)[2] = dx * s->f58 + b[0];
    ((f32 *)&t)[3] = dy * s->f5C + b[1];
    for (i = 0; i < self->f2C->n; i++) {
        func_003EDC30(((s32 **)self->f2C)[i], b);
    }
}
/* localdecomp:end func_003EE630 */

/* localdecomp:start func_003EE720 */
s32 func_003EE720(void) {
    return 7;
}
/* localdecomp:end func_003EE720 */

/* localdecomp:start func_003EE728 */
s32 func_003EE728(s32 p, s32 k) {
    if (k == 7) {
        return 1;
    }
    return func_003EDBA8(p, k);
}
/* localdecomp:end func_003EE728 */

LINKER_REMNANT("asm/remnants", func_003EE758);

extern void func_003ED988(void);
extern unsigned char D_001D9738[];
INCLUDE_ASM("asm/nonmatchings/text", func_003EE760);

/* localdecomp:start func_003EE7C8 */
extern s32 D_001D9730_g;
extern s32 func_003EDBA8(s32, s32);
s32 func_003EE7C8(s32 p, s32 k) {
    if (k != D_001D9730_g) return func_003EDBA8(p, k);
    return 1;
}
/* localdecomp:end func_003EE7C8 */

/* localdecomp:start func_003EE7F8 */
extern s32 D_001D9730_g;
s32 func_003EE7F8(void) { return D_001D9730_g; }
/* localdecomp:end func_003EE7F8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003EE800);

INCLUDE_ASM("asm/nonmatchings/text", func_003EE840);

typedef struct { u8 b[16]; } B16_3E98B8;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3E98B8;
extern s32 func_0011A264(void *, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003EEE20);

/* localdecomp:start func_003EF080 */
s32 func_003EF080(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))((u8 *)p + 0x2C);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003EF080 */

LINKER_REMNANT("asm/remnants", func_003EF0B0);

/* localdecomp:start func_003EF0B8 */
extern char D_001D9670[];
extern s32 func_003F2380();
void func_003EF0B8(u8 *p, s32 f) {
    *(void **)(p + 8) = D_001D9670;
    if (f & 1) func_003F2380(p);
}
/* localdecomp:end func_003EF0B8 */

LINKER_REMNANT("asm/remnants", func_003EF0E8);

/* localdecomp:start func_003EF110 */
extern void func_003EF1B8();
extern void func_003EF288(void *, s32, s32, s32, s32);
extern void func_003ED988(void);
extern u8 D_001D9768[];
void *func_003EF110(void *arg0)
{
  void **new_var;
  func_003ED988();
  *((s32 *) (((u8 *) arg0) + 0x2C)) = 0;
  *((s32 **) (((u8 *) arg0) + 8)) = D_001D9768;
  *((s32 *) (((u8 *) arg0) + 0x30)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x38)) = 0x80808080;
  *((s32 *) (((u8 *) arg0) + 0x3C)) = 0x80808080;
  *((s32 *) (((u8 *) arg0) + 0x40)) = 0x80808080;
  *((s32 *) (((u8 *) arg0) + 0x44)) = 0x80808080;
  func_003EF288(arg0, 0x80F00000, 0x80F00000, 0x80F00000, 0x80F00000);
  *((s32 *) (((u8 *) arg0) + 0x50)) = 0;
  *((f32 *) (((u8 *) arg0) + 0x18)) = 0.5f;
  *((f32 *) (((u8 *) arg0) + 0x1C)) = 0.5f;
  func_003EF1B8(arg0, 0);
  new_var = &arg0;
  *((s8 *) (((u8 *) (*new_var)) + 0x4C)) = 0xA;
  *((s16 *) (((u8 *) (*new_var)) + 0x4A)) = 0;
  *((s32 *) (((u8 *) (*new_var)) + 0x34)) = 0;
  *((s8 *) (((u8 *) (*new_var)) + 0x4E)) = 0;
  *((s8 *) (((u8 *) (*new_var)) + 0x4D)) = 0;
  return *new_var;
}
/* localdecomp:end func_003EF110 */

/* localdecomp:start func_003EF1B8 */
typedef struct S_003E9C50_obj S_003E9C50_obj;
typedef struct {
    u8 pad0[8];
    void (*f8)(S_003E9C50_obj *, s32);
    void (*fC)(S_003E9C50_obj *);
} S_003E9C50_vt;
struct S_003E9C50_obj { s32 f0; S_003E9C50_vt *vt; };
typedef struct {
    u8 pad0[0xC]; s32 fC; u8 pad10[0x38]; u16 f48; u8 pad4A[4]; s8 f4E; u8 pad4F; S_003E9C50_obj *f50;
} S_003E9C50;

void func_003EF1B8(S_003E9C50 *arg0, s32 arg1) {
    S_003E9C50_obj *o;

    if (arg0->f48 != arg1) {
        arg0->f48 = arg1;
        if ((u16)arg1 != 0) {
            o = arg0->f50;
            if (o != 0) {
                if ((o->f0 ^ 4) == 0) {
                    o->vt->fC(o);
                }
                if (arg0->fC & 0x8000) {
                    arg0->f4E = 4;
                    return;
                }
                arg0->f50->vt->f8(arg0->f50, arg1 - 1);
            }
        }
    }
}
/* localdecomp:end func_003EF1B8 */

/* localdecomp:start func_003EF250 */
extern s32 D_001D9760_g;
extern s32 func_003EDBA8(s32, s32);
s32 func_003EF250(s32 p, s32 k) {
    if (k != D_001D9760_g) return func_003EDBA8(p, k);
    return 1;
}
/* localdecomp:end func_003EF250 */

/* localdecomp:start func_003EF280 */
extern s32 D_001D9760_g;
s32 func_003EF280(void) {
    return D_001D9760_g;
}
/* localdecomp:end func_003EF280 */

/* localdecomp:start func_003EF288 */
void func_003EF288(void *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    *(s32 *)((u8 *)a0 + 0x38) = a1;
    *(s32 *)((u8 *)a0 + 0x3c) = a2;
    *(s32 *)((u8 *)a0 + 0x40) = a3;
    *(s32 *)((u8 *)a0 + 0x44) = a4;
}
/* localdecomp:end func_003EF288 */

INCLUDE_ASM("asm/nonmatchings/text", func_003EF2A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003EF2E0);

typedef struct { s32 f0; s32 *vt4; } OB_3EA078;
typedef struct { u8 p0[8]; s32 f8; s32 fC; } PP_3EA078;
typedef struct { u8 pad0[0x20]; f32 f20, f24; s32 f28; f32 f2C; u8 pad1[0x8]; s32 f38; u8 pad2[0x14]; OB_3EA078 *f50; } O_3EA078;
extern f32 D_001D9698;
extern f32 D_001D969C;
extern unsigned long func_0039ACA8(s32);
extern void func_0038B120(s32, s32, s32, s32, s32, s32, s32, s32, f32, unsigned long, unsigned long);
INCLUDE_ASM("asm/nonmatchings/text", func_003EF5E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003EF7F8);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031CC30);

typedef struct { u8 b[16]; } B16_3EA648;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3EA648;
extern s32 func_0011A264(void *, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003EFBB0);

/* localdecomp:start func_003EFE10 */
s32 func_003EFE10(void *arg0, s32 arg1) {
    s32 (*temp_v0)(s32);
    s32 temp_v1;
    void *temp_a0;

    if ((*(u16 *)((u8 *)(arg0) + 0x48)) != 0) {
        temp_a0 = (*(void **)((u8 *)(arg0) + 0x50));
        if ((temp_a0 != 0) && ((temp_v1 = (*(s32 *)((u8 *)(temp_a0) + 0)), ((temp_v1 ^ 1) == 0)) || ((temp_v1 ^ 8) == 0))) {
            (*(s32 (**)(void *, s32))((u8 *)((*(void **)((u8 *)(temp_a0) + 4))) + 8))(temp_a0, (*(u16 *)((u8 *)(arg0) + 0x48)) - 1);
        }
    }
    temp_v0 = (*(s32 (**)(s32))((u8 *)(arg0) + 0x34));
    if (temp_v0 != 0) {
        temp_v0(arg1);
    }
    return 0;
}
/* localdecomp:end func_003EFE10 */

/* localdecomp:start func_003EFE98 */
void func_003EFE98(void *p, s32 v) {
    *((u8 *)p + 0x4C) = v;
    if ((u8)v == 0) {
        *((u8 *)p + 0x4C) = 1;
    }
}
/* localdecomp:end func_003EFE98 */

/* localdecomp:start func_003EFEB8 */
extern char D_001D9670[];
extern s32 func_003F2380();
void func_003EFEB8(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D9670; if (f & 1) func_003F2380(p); }
/* localdecomp:end func_003EFEB8 */

LINKER_REMNANT("asm/remnants", func_003EFEE8);

/* localdecomp:start func_003EFF10 */
s32 func_003EFF10(void) {
    return 2;
}
/* localdecomp:end func_003EFF10 */

/* localdecomp:start func_003EFF18 */
extern void func_003ED988(void);
extern u8 D_001D9798[];
void *func_003EFF18(void *arg0) {
    func_003ED988();
    (*(s32 **)((u8 *)arg0 + 8)) = D_001D9798;
    (*(s32 *)((u8 *)arg0 + 0x50)) = 0x80808080;
    (*(s8 *)((u8 *)arg0 + 0x54)) = 0x10;
    (*(s32 *)((u8 *)arg0 + 0x2C)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x30)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x38)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x3C)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x40)) = 0;
    (*(s8 *)((u8 *)arg0 + 0x44)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x48)) = 0;
    (*(f32 *)((u8 *)arg0 + 0x4C)) = 1.0f;
    (*(s32 *)((u8 *)arg0 + 0x34)) = 0;
    (*(f32 *)((u8 *)arg0 + 0x5C)) = 1.0f;
    (*(f32 *)((u8 *)arg0 + 0x60)) = 1.0f;
    (*(s32 *)((u8 *)arg0 + 0x58)) = 2;
    return arg0;
}
/* localdecomp:end func_003EFF18 */

/* localdecomp:start func_003EFFA0 */
void func_003EFFA0(u8 *p, u8 m, s32 set) {
    if (set != 0) {
        p[0x44] |= m;
    } else {
        p[0x44] &= ~m;
    }
}
/* localdecomp:end func_003EFFA0 */

/* localdecomp:start func_003EFFD0 */
s32 func_003EFFD0(void *a0, s32 a1) {
    s32 b = a1 & 0xff;
    return (*(u8 *)((u8 *)a0 + 0x44) & b) != 0;
}
/* localdecomp:end func_003EFFD0 */

/* localdecomp:start func_003EFFE8 */
void func_003EFFE8(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x48) = x;
    *(f32 *)((u8 *)p + 0x4C) = y;
}
/* localdecomp:end func_003EFFE8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003EFFF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003F0038);

typedef struct {
    void *vt0; void *vt4; s32 (**vt)(); u8 pad0[0x4]; f32 f10, f14, f18, f1C, f20, f24; u32 f28; u8 pad2[0xC]; s32 f38; s32 f3C; u32 f40; u32 f44; u8 pad3[0x4]; u32 f4C; u32 f50; u8 pad4[0x8]; f32 f5C; f32 f60;
} O_3EAAD0;
extern f32 D_001D9698;
extern f32 D_001D969C;
extern f32 D_001D96B4;
extern void func_003EDCF0();
extern void func_0038E7E8_003EAAD0(unsigned long, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003F0210);

/* localdecomp:start func_003F0658 */
s32 func_003F0658(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))((u8 *)p + 0x34);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003F0658 */

/* localdecomp:start func_003F0688 */
s32 func_003F0688(s32 p, s32 k) {
    if (k != 2) {
        return func_003EDBA8(p, k);
    }
    return 1;
}
/* localdecomp:end func_003F0688 */

/* localdecomp:start func_003F06B8 */
extern char D_001D9670[];
extern s32 func_003F2380();
void func_003F06B8(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D9670; if (f & 1) func_003F2380(p); }
/* localdecomp:end func_003F06B8 */

LINKER_REMNANT("asm/remnants", func_003F06E8);

/* localdecomp:start func_003F0700 */
s32 func_003F0700(void) {
    return 3;
}
/* localdecomp:end func_003F0700 */

typedef struct {
    s32 f0, f4, f8, fC, f10, f14;
    s16 f18, f1A;
    s32 f1C;
    u8 f20;
    s16 f22;
    f32 f24, f28;
    s32 f2C, f30;
    u32 f34, f38;
    s32 f3C, f40, f44;
    u8 p48[2];
    u8 f4A;
    u8 p4B[0x56 - 0x4B];
    s16 f56;
    u8 p58;
    u8 f59, f5A;
} O_3EB180;
typedef struct { u8 p0[8]; void *f8; u8 pC[0x2C - 0xC]; O_3EB180 *f2C; u8 f30; s32 f34; } T_3EB180;
typedef struct { s32 f0; s32 f4; } S_3EB180;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); } VT_3EB180;
extern u8 D_001D97C8;
extern S_3EB180 D_001DA938_003F0708[];
extern s32 *func_003E6C08();
extern void *func_003ED988_003F0708();
extern void **func_003E6CC0();
INCLUDE_ASM("asm/nonmatchings/text", func_003F0708);

s32 *func_003E6C08(s32 *);
void **func_003E6CC0(s32 *, s32);
void func_003F2380_003F08E0(void *);
extern u8 D_001D9670_003F08E0;
extern u8 D_001D97C8;
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003EB358;
extern S_001DA9B8_003EB358 D_001DA938[];
INCLUDE_ASM("asm/nonmatchings/text", func_003F08E0);

/* localdecomp:start func_003F0980 */
void func_003F0980(void *p, s32 value) {
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x34) = value;
}
/* localdecomp:end func_003F0980 */

/* localdecomp:start func_003F0990 */
void func_003F0990(u8 *p) {
    u8 *q;
    s32 v;
    (*(u8 **)(p + 0x2C))[0x59] = 0;
    q = *(u8 **)(p + 0x2C);
    v = 0;
    if (*(u16 *)(q + 0x48) & 8) v = *(u16 *)(q + 0x4C);
    *(s16 *)(q + 0x56) = v;
    (*(u8 **)(p + 0x2C))[0x5A] = 0;
    *(s32 *)(*(u8 **)(p + 0x2C) + 0x40) = 0;
}
/* localdecomp:end func_003F0990 */

/* localdecomp:start func_003F09C8 */
typedef struct { u8 pad[0x10]; s32 w10; u8 p2[0x48-0x14]; u16 h48; } Q_3EB440;
typedef struct { u8 pad[0x2C]; Q_3EB440 *q; u8 b30; u8 p3[3]; s32 w34; } S_3EB440;
extern void func_003F0990();
void func_003F09C8(S_3EB440 *p, s32 b) {
    Q_3EB440 *q = p->q;
    if (q->w10 != b && (q->h48 & 0x20)) {
        func_003F0990((u8 *)p);
        p->b30 = 0;
        p->w34 = 0;
    }
    p->q->w10 = b;
}
/* localdecomp:end func_003F09C8 */

/* localdecomp:start func_003F0A30 */
void func_003F0A30(void *a0, f32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(f32 *)((u8 *)p + 0x28) = a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003F0A30 */

/* localdecomp:start func_003F0A48 */
void func_003F0A48(void *p, s32 a, s16 b, s16 c, s32 d) {
    *(s16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x18) = b;
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x14) = a;
    *(s16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x1A) = c;
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x38) = d;
}
/* localdecomp:end func_003F0A48 */

/* localdecomp:start func_003F0A70 */
void func_003F0A70(void *a0, f32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(f32 *)((u8 *)p + 0x44) = a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003F0A70 */

/* localdecomp:start func_003F0A88 */
s32 func_003F0A88(void *a0, f32 *a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *a1 = *(f32 *)((u8 *)p + 0x44);
    return 1;
}
/* localdecomp:end func_003F0A88 */

/* localdecomp:start func_003F0AA0 */
s32 func_003F0AA0(u32 a0, u32 a1, u32 a2) {
    u32 ptr;

    ptr = *(u32 *)(a0 + 0x2C);
    *(float *)(a1 + 0x00) = *(float *)(ptr + 0x2C);

    ptr = *(u32 *)(a0 + 0x2C);
    *(float *)(a2 + 0x00) = *(float *)(ptr + 0x30);

    return 1;
}
/* localdecomp:end func_003F0AA0 */

/* localdecomp:start func_003F0AC0 */
void func_003F0AC0(u8 *p, s32 a, f32 x, f32 y) {
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x3C) = x;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x40) = y;
    *(s16 *)(*(u8 **)(p + 0x2C) + 0x56) = 0;
    {
        u8 *q = *(u8 **)(p + 0x2C);
        if (a != 0) q[0x59] = 0;
        else q[0x59] = 1;
    }
    p[0x30] = 0;
    *(s32 *)(p + 0x34) = 0;
}
/* localdecomp:end func_003F0AC0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003F0B00);

/* localdecomp:start func_003F0B20 */
void func_003F0B20(T_3EB180 *p, s32 a) {
    *(u16 *)((u8 *)p->f2C + 0x4C) = (a * 5 + 2) / 6;
}
/* localdecomp:end func_003F0B20 */

/* localdecomp:start func_003F0B48 */
/* func_003F0B48 */

void func_003F0B48(u8 *p, s32 a) {
    *(s16 *)(*(u8 **)(p + 0x2C) + 0x54) = (a * 5 + 2) / 6;
}
/* localdecomp:end func_003F0B48 */

/* localdecomp:start func_003F0B70 */
void func_003F0B70(u8 *p, s32 m, s32 on) {
    if (on) *(u16 *)(*(u8 **)(p + 0x2C) + 0x48) |= m;
    else *(u16 *)(*(u8 **)(p + 0x2C) + 0x48) &= ~m;
    p[0x30] = 0;
    *(s32 *)(p + 0x34) = 0;
}
/* localdecomp:end func_003F0B70 */

LINKER_REMNANT("asm/remnants", func_003F0BB0);

/* localdecomp:start func_003F0BB8 */
void func_003F0BB8(void *p, s32 *a, s32 *b) {
    *a = *(u16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x48) & 1;
    *b = ((*(u16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x48) >> 1) ^ 1) & 1;
}
/* localdecomp:end func_003F0BB8 */

/* localdecomp:start func_003F0BE8 */
void func_003F0B70_003F0BE8(void *, s32, s32);

s32 func_003F0BE8(u8 *arg0, s32 arg1, s32 arg2) {
    s32 a = 0;
    s32 ok = 1;
    s32 b = 0;

    if (arg1 != 0) {
        if (arg1 == 1) {
            a = 1;
        } else {
            ok = 0;
        }
    }
    if (arg2 == 0) {
        b = 1;
    } else if (arg2 != 1) {
        ok = 0;
    }
    func_003F0B70_003F0BE8(arg0, 1, a);
    func_003F0B70_003F0BE8(arg0, 2, b);
    *(s8 *)(arg0 + 0x30) = 0;
    *(s32 *)(arg0 + 0x34) = 0;
    return ok;
}
/* localdecomp:end func_003F0BE8 */

/* localdecomp:start func_003F0C78 */
extern void func_003EDB68(void *, f32, f32);
void func_003F0C78(u8 *object, f32 *bounds) {
    register f32 x __asm__("$f12") = bounds[0];
    register f32 half __asm__("$f2") = 0.5f;
    register f32 temp __asm__("$f1") = bounds[2];
    register f32 y __asm__("$f13") = bounds[1];
    register f32 other __asm__("$f0") = bounds[3];
    temp -= x;
    other -= y;
    temp *= half;
    x += temp;
    temp = other * half;
    y += temp;
    func_003EDB68(object, x, y);
    *(volatile s32 *)(object + 0x34) = 0;
    *(volatile u8 *)(object + 0x30) = 0;
}
/* localdecomp:end func_003F0C78 */

/* localdecomp:start func_003F0CD8 */
void func_003F0CD8(void *a0, s32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(u8 *)((u8 *)p + 0x58) = (u8)a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003F0CD8 */

typedef struct {
    u8 p00[0x10];
    s32 f10;
    s32 f14;
    s16 h18;
    s16 h1A;
    u8 p1C[0xC];
    f32 f28;
    f32 f2C;
    f32 f30;
    u32 f34;
    u32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
    u16 h48;
    u16 p4A;
    u16 h4C;
    u16 p4E;
    f32 f50;
    u16 h54;
    u16 h56;
    u8 b58;
    u8 b59;
    u8 b5A;
} P_3EB728;
typedef struct {
    u8 p00[0x20];
    void (*f20)(void *, s32, f32 *, s32);
} VT_3EB728;
typedef struct {
    u8 p00[8];
    VT_3EB728 *vt;
    u8 p0C[0x14];
    f32 f20;
    f32 f24;
    u32 f28;
    P_3EB728 *p;
    u8 b30;
    u8 p31[3];
    f32 f34;
} O_3EB728;
typedef struct {
    s16 y0, y1, x0, x1, tx, ty, w, h, f30, flags, f34, f36, f38, f3A;
} Desc_3EB728;
extern f32 D_001D9690;
extern f32 D_001D9694;
extern f32 D_001D9698;
extern f32 D_001D969C;
extern s32 D_001D55C4;
extern s32 D_003357E0[];
extern void func_0038E150(s32);
extern void func_003EDCF0(void *, f32 *);
extern void func_00391210();
extern void func_003911F0();
extern void func_00390CC8(void);
extern void func_00390CA8(void);
extern void func_003E7160(void);
extern long func_00389598(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003F0CF0);

typedef struct { u8 b[16]; } B16_3EC3D0;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3EC3D0;
extern s32 func_0011A264(void *, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003F1998);

/* localdecomp:start func_003F1BF8 */
s32 func_003F1BF8(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))(*(u8 **)((u8 *)p + 0x2C) + 0x8);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003F1BF8 */

/* localdecomp:start func_003F1C28 */
s32 func_003F1C28(s32 p, s32 k) {
    if (k != 3) {
        return func_003EDBA8(p, k);
    }
    return 1;
}
/* localdecomp:end func_003F1C28 */

LINKER_REMNANT("asm/remnants", func_003F1C58);

/* localdecomp:start func_003F1CA8 */
extern void func_003EDAD0(void *, s32, s32);
extern void func_003ED988(void);
extern u8 D_001D97F8[];
void *func_003F1CA8(void *arg0)
{
  func_003ED988();
  *((s32 *) (((u8 *) arg0) + 0x2C)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x30)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x44)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x40)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x34)) = 0;
  *((s32 **) (((u8 *) arg0) + 8)) = D_001D97F8;
  *((f32 *) (((u8 *) arg0) + 0x14)) = (*((f32 *) (((u8 *) arg0) + 0x10)) = 0.5f);
  *((s32 *) (((u8 *) arg0) + 0x38)) = 0x60F00000;
  *((f32 *) (((u8 *) arg0) + 0x18)) = 1.0f;
  *((f32 *) (((u8 *) arg0) + 0x1C)) = 1.0f;
  func_003EDAD0(arg0, 0x100, 1);
  return arg0;
}
/* localdecomp:end func_003F1CA8 */

/* localdecomp:start func_003F1D28 */
extern s32 D_001D97F0_g;
extern s32 func_003EDBA8(s32, s32);
s32 func_003F1D28(s32 p, s32 k) {
    if (k != D_001D97F0_g) return func_003EDBA8(p, k);
    return 1;
}
/* localdecomp:end func_003F1D28 */

/* localdecomp:start func_003F1D58 */
extern s32 D_001D97F0_g;
s32 func_003F1D58(void) {
    return D_001D97F0_g;
}
/* localdecomp:end func_003F1D58 */

INCLUDE_ASM("asm/nonmatchings/text", func_003F1D60);

/* localdecomp:start func_003F1DA0 */
typedef struct {
    void *vt0; void *vt4; s32 (**vt)(); u8 pad0[0x4]; f32 f10, f14, f18, f1C; u8 pad20[0x18]; s32 f38; f32 f3C; s32 f40; s32 f44;
} O_3EC7D8;
extern f32 D_001D9688[], D_001D968C[], D_001D9690_003F1DA0[], D_001D9694_003F1DA0[], D_001D9698_003F1DA0[], D_001D969C_003F1DA0[];
extern s32 func_003EDAF8();
extern void func_003EDCF0();
extern s32 func_003ABDD8();
extern void func_003AA320(void *, s32, f32, f32, f32, f32, f32);
void func_003F1DA0(O_3EC7D8 *o, s32 a) {
    f32 b[4];
    s32 p;
    f32 x, y;
    if (o->f44 == 0) return;
    o->vt[8](o, a, b, 1);
    if (func_003EDAF8(o, 0x100) != 0) {
        f32 x, y;
        f32 c;
        f32 d;
        f32 e;
        s32 fl;
        s32 k = o->f40;
        p = func_003ABDD8(o->f44, k);
        x = o->f10; y = o->f14; fl = o->f38; c = o->f18; d = o->f1C; e = o->f3C;
        if (p == 0) return;
        func_003AA320((void *)p, fl, (x + D_001D9690_003F1DA0[0]) * D_001D9698_003F1DA0[0], (y + D_001D9694_003F1DA0[0]) * D_001D969C_003F1DA0[0], c * D_001D9688[0], d * D_001D968C[0], e);
    } else {
        s32 k;
        f32 c;
        f32 d;
        f32 e;
        s32 fl;
        func_003EDCF0(o, b);
        x = b[0] + (b[2] - b[0]) * 0.5f;
        y = b[1] + (b[3] - b[1]) * 0.5f;
        k = o->f40;
        p = func_003ABDD8(o->f44, k);
        fl = o->f38; c = o->f18; d = o->f1C; e = o->f3C;
        if (p == 0) return;
        func_003AA320((void *)p, fl, (x + D_001D9690_003F1DA0[0]) * D_001D9698_003F1DA0[0], (y + D_001D9694_003F1DA0[0]) * D_001D969C_003F1DA0[0], c * D_001D9688[0], d * D_001D968C[0], e);
    }
}
/* localdecomp:end func_003F1DA0 */

typedef struct { u8 p0[0x10]; f32 f10; f32 f14; f32 f18; f32 f1C; u8 p1[0x1C]; f32 f3C; s32 f40; u8 *f44; } O_3EC960;
extern s32 func_003ABDD8(u8 *, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003F1F28);

/* localdecomp:start func_003F2148 */
s32 func_003F2148(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))((u8 *)p + 0x34);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003F2148 */

/* localdecomp:start func_003F2178 */
extern char D_001D9670[];
extern s32 func_003F2380();
void func_003F2178(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D9670; if (f & 1) func_003F2380(p); }
/* localdecomp:end func_003F2178 */

LINKER_REMNANT("asm/remnants", func_003F21A8);

/* localdecomp:start func_003F21E8 */
void func_003F21E8(s32 *p, s32 a, s32 b, s32 c) {
    p[1] = b;
    p[2] = c;
    p[3] = a;
    p[6] = 0;
    p[4] = 0;
    p[5] = 0;
}
/* localdecomp:end func_003F21E8 */

/* localdecomp:start func_003F2208 */
extern u8 D_001D9840[];
void **func_003F2208(void **p) { p[1] = 0; p[0] = D_001D9840; p[2] = 0; p[3] = 0; p[6] = 0; p[4] = 0; p[5] = 0; return p; }
/* localdecomp:end func_003F2208 */
