#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_00392B20();
extern s32 func_00392C78();
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


/* localdecomp:start func_00392A18 */
extern s32 D_001D5C78;
s32 func_00392A18(void) { s32 v = D_001D5C78; if (v != 0) return v + 0x7090; return 0; }
/* localdecomp:end func_00392A18 */

/* localdecomp:start func_00392A38 */
void *func_00392A38(p) u8 *p; {  /* K&R: a later caller uses an unprototyped call */
    void *r;
    *(s32 *)(p + 0x58) = 0; *(s32 *)(p + 0x5C) = 0; *(s32 *)(p + 0x60) = 0;
    r = ((void *(*)(void *, s32, s32))func_0011A264)(p + 8, 0xCD, 0x50);
    p[0x6C] = 0; *(s32 *)(p + 0x68) = 1;
    return r;
}
/* localdecomp:end func_00392A38 */

typedef struct { s32 a, b; } E_38E;
typedef struct { u8 pad[8]; E_38E e[10]; s32 f58, f5C, f60, f64, f68; u8 f6C; } S_38E;
/* localdecomp:start func_00392A80 */
s32 func_00392A80(S_38E *p, s32 *a, s32 *b) {
    s32 i;
    if (p->f60 == 0) return 0;
    if (--p->f60 == 0) p->f6C = 0;
    *a = p->e[p->f5C].a;
    *b = p->e[p->f5C].b;
    p->e[p->f5C].a = -1;
    p->e[p->f5C].b = -1;
    i = p->f5C + 1;
    if (i == 10) i = 0;
    p->f5C = i;
    return 1;
}
/* localdecomp:end func_00392A80 */

/* localdecomp:start func_00392B20 */
s32 func_00392B20(S_38E *p, s32 v) {
    s32 i, n;
    if (p->f60 == 10 || p->f6C != 0) return 0;
    p->e[p->f58].a = v;
    p->e[p->f58].b = v >= 100;
    i = p->f58 + 1;
    n = p->f60 + 1;
    if (i == 10) i = 0;
    p->f60 = n;
    p->f58 = i;
    return 1;
}
/* localdecomp:end func_00392B20 */

/* localdecomp:start func_00392B98 */
extern void *func_00392A38();
 
void func_00392B98(s32 *p) {
    func_00392A38();
}
/* localdecomp:end func_00392B98 */

/* localdecomp:start func_00392BB8 */
extern s32 func_0039EF28();
typedef struct { u8 p0[8]; struct { s32 id; s32 x; } e[10]; s32 head; s32 tail; } S_E380;
extern u8 D_00142BA0[];
void func_00392BB8(s32 *arg) {
    S_E380 *s = (S_E380 *)arg;
    s32 i = s->tail;
    if (i != s->head) {
        do {
            s32 v = s->e[i].id;
            if (v >= 0) {
                u32 *p = (u32 *)(D_00142BA0 + (((u32)v >> 2) << 2));
                *p |= 1 << (v & 0x1F);
            }
            i = (i + 1 != 10) ? i + 1 : 0;
        } while (i != s->head);
    }
    func_0039EF28();
}
/* localdecomp:end func_00392BB8 */

/* localdecomp:start func_00392C48 */
extern void func_00392BB8(s32 *);
extern void func_00392B98(s32 *);
void func_00392C48(s32 *p) {
    func_00392BB8(p);
    *p = 0;
    func_00392B98(p);
}
/* localdecomp:end func_00392C48 */

typedef struct {
    u8 pad0[0x60];
    s32 active;
    u8 flag64;
    u8 pad65[3];
    s32 mode68;
    u8 flag6C;
} Object_0038E440;
extern s32 D_001D5B94;
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
/* localdecomp:start func_00392C78 */
s32 func_00392C78(Object_0038E440 *object) {
    register s32 result;
    s32 values[2];
    s32 mode;

    if (object->active == 0) {
        goto inactive;
    }
    object->flag64 = 0;
    object->flag6C = 1;
    values[0] = 0;
    result = 0;
    values[1] = 0;
    func_00392A80(object, &values[0], &values[1]);

    mode = 1;
    if ((u32)(D_001D5B94 - 1) < 2) {
        mode = 2;
    }
    object->mode68 = mode;

    if (values[1] == 0) {
        result = func_003A0EC0(1, mode, 0, values[0], 0);
    } else if (values[1] == 1) {
        result = func_003A0EC0(2, mode, values[0], 0, 0);
    }
    if (result < 0) {
        func_00392B98((s32 *)object);
    }
    return result == 0;
inactive:
    return 0;
}
/* localdecomp:end func_00392C78 */

/* localdecomp:start func_00392D40 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern u8 D_001D5587_00392D40;
__asm__(".extern D_001D5587_00392D40, 16");
extern s32 func_0039EF28();

void func_00392D40(s32 *input_ptr) {
    s32 *value_ptr = input_ptr;
    register u8 *page_temp __asm__("$2") = (u8 *)0x140000;
    register u8 *page __asm__("$17");
    register u8 *late_base __asm__("$3");
    register s32 output __asm__("$2");
    u8 *base;
    u8 flags;
    s32 value;

    __asm__ volatile("" : "+r"(page_temp));
    base = page_temp + 0x26E0;
    page = page_temp;
    flags = base[0x82];

    if ((flags & 1) == 0) {
        value = *value_ptr;
    } else {
        if (base[0x14] != 0) {
            value = *value_ptr;
            if (value == 3) {
                goto evaluate;
            }
            base[0x82] = flags & 0xFE;
            func_0039EF28();
        }
        value = *value_ptr;
    }

evaluate:
    if (value == 0xD && D_001D5587_00392D40 == 0) {
        output = 0x17;
    } else {
        if (value != 3) {
            return;
        }
        late_base = page + 0x26E0;
        __asm__ volatile("" : "+r"(late_base));
        if ((late_base[0x82] & 1) == 0) {
            return;
        }
        output = 6;
    }
    *value_ptr = output;
}
/* localdecomp:end func_00392D40 */
