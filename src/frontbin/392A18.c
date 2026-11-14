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

extern s32 func_0039EF28();
typedef struct { u8 p0[8]; struct { s32 id; s32 x; } e[10]; s32 head; s32 tail; } S_E380;
extern u8 D_00142BA0[];
INCLUDE_ASM("asm/nonmatchings/text", func_00392BB8);

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
    register s32 result __asm__("$17");
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

typedef struct { u8 pad[0x18]; s16 h18; u8 pad2[0x17C - 0x1A]; s32 x17C; } S_38E5B8;
extern S_38E5B8 D_00142430_00392DF0[];
extern s32 D_001D5B74;
extern s32 D_001D9D04;
extern s32 D_001D545C;
extern s32 D_001D4CF0;
extern s32 D_001D4CEC_00392DF0;
extern void func_0039EC28(s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00392DF0);

LINKER_REMNANT("asm/remnants", func_00392EC0);

/* localdecomp:start func_00392EF0 */
extern u8 D_001D551C;
void func_00392EF0(void) {
    D_001D551C = 0;
}
/* localdecomp:end func_00392EF0 */

LINKER_REMNANT("asm/remnants", func_00392EF8);

extern u8 D_001D5BDC;
extern s32 D_001D5C90;
extern s32 D_0022758C;
extern s32 D_001DA058;
INCLUDE_ASM("asm/nonmatchings/text", func_00392F08);

/* localdecomp:start func_00392F60 */
extern s32 D_001D5C90;
void func_00392F60(s32 a) {
    D_001D5C90 = a;
}
/* localdecomp:end func_00392F60 */

/* localdecomp:start func_00392F68 */
typedef struct LookupEntry_38E730 {
    u16 key;
    u8 reserved[6];
} LookupEntry_38E730;
extern LookupEntry_38E730 *D_001D9EA4_00392F68[];
s32 func_00392F68(s32 key) {
    LookupEntry_38E730 *entry = *D_001D9EA4_00392F68;
    s32 index = 0;
    if (entry->key != 0xFFFF && entry->key != key) {
        LookupEntry_38E730 *cursor = entry;
        s32 current;
        for (;;) {
            cursor++;
            current = cursor->key;
            index++;
            if (current == 0xFFFF || current == key) break;
        }
    }
    return index <= 0x3FF ? index : -1;
}
/* localdecomp:end func_00392F68 */

LINKER_REMNANT("asm/remnants", func_00392FC0);

/* localdecomp:start func_00392FD0 */
typedef struct { u8 p0[0x14]; s32 a[8]; s32 b[16]; s32 c[1]; } S_0038E798;
typedef struct { u32 w; u32 x; } E_0038E798;
extern S_0038E798 *D_001D9EA0_00392FD0[];
extern E_0038E798 *D_001D9EAC_00392FD0[];
extern E_0038E798 *D_001D9EB0_00392FD0[];
void func_00392FD0(s32 n, s32 size) {
    s32 i;
    s32 j;
    s32 end;
    if (D_001D9EA0_00392FD0[0]->c[n] == 0) {
        size = (size + 0xF) & 0xFFFFFFF0;
        D_001D9EA0_00392FD0[0]->c[n] = size;
        i = (n != 0) ? D_001D9EA0_00392FD0[0]->a[n - 1] : 0;
        end = D_001D9EA0_00392FD0[0]->a[n];
        for (j = i; j < end; j++) {
            D_001D9EB0_00392FD0[0][j].w &= 0x7FFFFFFF;
            D_001D9EB0_00392FD0[0][j].w += size;
        }
        i = (n != 0) ? D_001D9EA0_00392FD0[0]->b[n - 1] : 0;
        end = D_001D9EA0_00392FD0[0]->b[n];
        for (j = i; j < end; j++) {
            D_001D9EAC_00392FD0[0][j].w &= 0x7FFFFFFF;
            D_001D9EAC_00392FD0[0][j].w += size;
        }
    }
}
/* localdecomp:end func_00392FD0 */

LINKER_REMNANT("asm/remnants", func_00393130);

/* localdecomp:start func_00393138 */
extern u32 D_001D5D50;
u32 func_00393138(void) {
    u32 v = D_001D5D50;
    u32 r = 0;
    if (v <= 0x1CFFFF) r = (0x1D0000 - v) >> 2;
    return r;
}
/* localdecomp:end func_00393138 */

typedef struct { u8 p0[0x14]; s32 a[8]; s32 b[16]; s32 c[1]; } S_38E930;
typedef struct { u32 w0; u16 h4; u8 b6; u8 b7; } E_38E930;
extern S_38E930 * volatile D_001D9EA0_00393168;
extern E_38E930 *D_001D9EAC_00393168;
extern volatile s32 D_001A1F08_00393168[];
extern void func_00392FD0_00393168();
extern void func_00397980(s32, s32, s32, s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00393168);

extern s32 D_00227600[];
extern s32 D_001D9E98;
extern s32 D_001D9E9C;
INCLUDE_ASM("asm/nonmatchings/text", func_00393290);

/* localdecomp:start func_003932C0 */
__asm__(".extern D_001D9E98, 16");
__asm__(".extern D_001D9E9C, 16");
s32 func_003932C0(s32 size) {
    register s32 amount __asm__("$16") = size;
    register s32 current __asm__("$4");
    register s32 result __asm__("$2");
    if (D_001D9E98 == 0) {
        func_00393290();
    }
    result = D_001D9E9C;
    current = D_001D9E98;
    if (amount > result - current) {
        goto failure;
    }
    {
        register u32 mask __asm__("$3") = 0xfffffff0U;
        register s32 rounded __asm__("$5") = amount + 0xF;
        result = current;
        amount = rounded & mask;
        current += amount;
        D_001D9E98 = current;
        __asm__ volatile("" : : : "memory");
    }
    goto done;
failure:
    result = 0;
    __asm__ volatile("");
done:
    return result;
}
/* localdecomp:end func_003932C0 */
TEXT_PADDING(2);

typedef struct { s32 f0; s32 f4; u8 p8[0x18]; s32 f20; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; u8 p3C[0x28]; s32 f64; s32 f68; u8 p6C[4]; s32 f70; u8 p74[8]; s32 f7C; u8 p80[0x10]; } S_EB;
extern S_EB D_00331AE0_00393348[];
extern s32 D_001D5B94_00393348;
extern s32 D_001D9E88_00393348;
INCLUDE_ASM("asm/nonmatchings/text", func_00393348);

/* localdecomp:start func_00393450 */
typedef struct S_38EC18 {
    s32 pad0;
    s32 v4, v8, vC;
    void (*f10)(struct S_38EC18 *);
    s32 v14, v18, pad1C;
    s32 a20, a24, a28, a2C;
    void (*a30)(struct S_38EC18 *);
    s32 a34, a38;
    s32 pad3C[11];
    s32 x68;
} S_38EC18;
extern void func_00393538();
void func_00393450(S_38EC18 *p) {
    func_00393538(p, p->a20);
    p->v4 = p->a24;
    p->v14 = p->a34;
    p->v18 = p->a38;
    p->vC = p->a2C;
    p->v8 = p->a28;
    p->f10 = p->a30;
    if (p->f10) p->f10(p);
    p->x68 = 0;
}
/* localdecomp:end func_00393450 */

typedef struct { s32 pad0; s32 f4; s32 pad8[7]; s32 f24; s32 pad28[15]; s32 id; s32 f68; s32 pad6C[9]; } S_38ED78;
extern S_38ED78 D_00331AE0[];
extern void func_00393348();
INCLUDE_ASM("asm/nonmatchings/text", func_003934B8);

/* localdecomp:start func_00393538 */
typedef struct { u16 x0; u16 x2; u16 x4; u8 x6; u8 x7; } E_38ED00;
typedef struct { s32 x0; u8 pad[0x3C]; s16 x40; u8 x42; u8 x43; s32 x44; } S_38ED00;
extern E_38ED00 *D_001D9EA4[];
s32 func_00392F68(s32);
void func_00393538(S_38ED00 *d, s32 a) {
    s32 i = func_00392F68(a);
    if (i < 0) i = 0;
    d->x0 = D_001D9EA4[0][i].x0;
    d->x40 = i;
    d->x42 = D_001D9EA4[0][i].x6;
    d->x44 = D_001D9EA4[0][i].x4;

}
/* localdecomp:end func_00393538 */

INCLUDE_ASM("asm/nonmatchings/text", func_003935B0);

/* localdecomp:start func_00393620 */
typedef struct { u8 pad[0x58]; s32 w; s32 h; union { s32 flags; u8 c; } u; } S_38EDE8;
s32 func_00393620(S_38EDE8 *p, s32 *x, s32 *y) {
    s32 w = p->w;
    s32 h = p->h;
    if ((p->u.c ^ 1) & 1) {
        if (!(p->u.flags & 2)) *y -= h >> 1;
    }
    if (!(p->u.flags & 4)) {
        if (p->u.flags & 8) *x -= w;
        else *x -= w >> 1;
    }
    return 0;
}
/* localdecomp:end func_00393620 */

typedef struct { u8 p0[0x58]; s32 f58; s32 f5C; u32 f60; u8 p64[0x18]; s32 f7C; } S_38EE58;
extern f32 D_00332230[];
extern f32 D_00332290[];
INCLUDE_ASM("asm/nonmatchings/text", func_00393690);

/* localdecomp:start func_00393808 */
typedef struct { u8 p0[8]; s32 f8; s32 *fC; u8 p1[0x48]; s32 f58; s32 f5C; s32 f60; u8 p2[0x10]; s32 f74; s32 f78; } S;
void func_00393808(void *arg) {
    S *s = (S *)arg;
    s32 *q;
    s32 n, x, a, t;
    q = s->fC;
    if (q != 0 && ((s32)q & 3) == 0) {
        s->f78 = *q;
        if (s->f8 < s->f78) s->f78 = s->f8;
        s->f74 = s->f78;
    } else {
        s->f78 = 99999;
        s->f74 = 99999;
    }
    n = 0;
    x = s->f8;
    a = s->f60;
    t = s->f5C;
    if (x >= 10) {
        do { x /= 10; n++; } while (x >= 10);
    }
    if ((a & 3) == 0 && (a & 0xC) != 0) {
        s->f5C = t + (n + 1) * 12;
        if (s->f58 < 0xE) s->f58 = 0xE;
    } else {
        if (t < 12) s->f5C = 12;
        s->f58 = s->f58 + (n + 1) * 14;
    }
}
/* localdecomp:end func_00393808 */

/* US draft of func_003938F8 (rac3-uya-decomp func_0038F0C0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003938F8 */
extern void func_00393808(void *);
 
void func_003938F8(void *p) {
    *(s32 *)((u8 *)p + 0x7C) = 0xB4;
    *(s16 *)((u8 *)p + 0x48) = 0;
    *(s16 *)((u8 *)p + 0x4A) = 0;
    func_00393808(p);
}
/* localdecomp:end func_003938F8 */

LINKER_REMNANT("asm/remnants", func_00393928);

INCLUDE_ASM("asm/nonmatchings/text", func_00393930);

typedef struct { u8 p0[8]; s32 f8; s32 *fC; u8 p10[0x5C]; s32 f6C; u8 b70[4]; s32 f74; s32 f78; s32 f7C; } S_38F0F8;
extern s32 func_003963D0();

LINKER_REMNANT("asm/remnants", func_00393AF0);

typedef struct { u8 pad[0x38]; u16 h38; u8 pad2[0xF0 - 0x3A]; } S_38F310;
typedef struct { s32 w0; u8 pad[0x14]; s32 w18; } D_393B58;
extern s32 D_001D9EE8_00393B58;
extern s32 *D_001D9EF0_00393B58;
extern s32 D_001D5D40;
extern s32 D_001D5CAC;
extern s32 D_1D4C60[2];
extern s32 D_1D4C80[2];
extern u8 D_001425C0[];
extern S_38F310 D_001DAA40_00393B58[];
extern D_393B58 D_00331990[];
INCLUDE_ASM("asm/nonmatchings/text", func_00393B58);

/* US draft of func_00393BE8 (rac3-uya-decomp func_0038F3A0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_00393BE8 */
typedef struct { u8 pad[0x48]; s16 h48; s16 h4A; u8 p2[0x58-0x4C]; s32 w58; s32 w5C; u8 p3[0x70-0x60]; s32 w70; s32 w74; s32 w78; } S_38F3A0;
extern void func_00393B58(s32);
void func_00393BE8(S_38F3A0 *p) {
    func_00393B58(0);
    p->w58 = 0xD2; p->w5C = 0xC8; p->w74 = -2; p->w78 = 25; p->h48 = 0; p->h4A = 0; p->w70 = 0;
}
/* localdecomp:end func_00393BE8 */

INCLUDE_ASM("asm/nonmatchings/text", func_00393C40);

typedef struct {
    u8 pad0[0x64];
    s32 f64;
    u8 pad68[4];
    s32 f6C;
    u8 st[4];
    s32 f74;
    s32 f78;
    s32 f7C;
} O_38F3F8;
typedef struct {
    u8 pad0[0x148];
    f32 f148;
    f32 f14C;
    u8 pad150[0x1C0 - 0x150];
    s32 f1C0;
    volatile s32 f1C4;
    u8 pad1C8[4];
    s32 f1CC;
    u8 pad1D0[8];
    s32 f1D8;
} PAD_38F3F8;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
} E_38F3F8;
typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x84 - 0x14];
    u16 f84;
    u8 pad86[4];
    u16 f8A;
    u8 pad8C[0xF0 - 0x8C];
} T_38F3F8;
typedef struct { u8 pad[0xB6]; u8 b; } B6_38F3F8;
typedef struct { u8 pad0[0x1228]; s32 f1228; u8 pad122C[0x25F8 - 0x122C]; s32 f25F8; } W_38F3F8;
typedef struct { u8 pad0[0xF0]; u16 fF0; u8 padF2[2]; u32 fF4; s32 fF8; } X_38F3F8;
extern s32 D_0031D050[];
extern u8 D_00143950_b[];
extern s32 D_001D5C98;
extern s32 D_001D5D5C;
extern u8 D_001D5D58;
extern f32 D_001D5D54;
extern s32 D_001D5CAC;
extern PAD_38F3F8 *D_001D52FC;
extern u8 D_1A745E[];
extern s32 D_001D9EE8_0038F3F8;
extern s32 D_001D9EF0_0038F3F8;
extern volatile s32 D_001D5D00;
extern volatile s32 D_001D5D04;
extern volatile s32 D_001D5D08;
extern volatile s32 D_001D5D0C;
extern u8 D_1425C0[];
extern T_38F3F8 D_001DAA40_0038F3F8[];
extern s16 D_001CCFD4[];
extern u8 D_1A4BE0[];
extern u8 D_1A7C10[];
extern s32 D_1427F0[];
extern u32 D_001D4C38;
extern s32 D_001D9F2C;
extern s32 D_001D9F30;
extern s32 D_001D9F28;
extern s32 D_001D9BC8_0038F3F8;
extern s32 func_003E3DF0(void);
extern void func_003E3E08(void);
extern void func_003E3DC0(void);
extern void func_003AEB48(void *, s32);
extern s32 func_003A3BB8(s32, s32);
extern s32 func_003A5348(s32, s32, s32);
extern s32 func_0038CB00(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DB48(f32);
extern void func_003A2558(void);
extern s32 func_0039AC08(s32);
extern void func_0039AA38(s32);
extern void func_00381CA8(s32);
extern void func_00381D70(s32);
extern s32 func_003934B8(s32);
#define ROW_38F3F8 ((E_38F3F8 *)((s32 *)D_001D9EF0_0038F3F8)[D_001D5CAC])
INCLUDE_ASM("asm/nonmatchings/text", func_00394620);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C0A0);

/* US draft of func_00394F48 (rac3-uya-decomp func_003906E8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_00394F48 */
extern s32 D_001D9EE8[];
extern s32 D_001D9EF0[];
extern s32 D_001D5D38;
extern s32 D_001D5CAC;
void func_00394F48(u8 *p) {
    D_001D9EE8[0] = 4;
    D_001D9EF0[0] = (s32)&D_001D5D38;
    *(s32 *)(p + 0x58) = 0xD2;
    *(s32 *)(p + 0x5C) = 0xC8;
    *(s32 *)(p + 0x74) = -2;
    *(s16 *)(p + 0x48) = 0;
    *(s16 *)(p + 0x4A) = 0;
    *(s32 *)(p + 0x78) = 0x19;
    D_001D5CAC = 0;
}
/* localdecomp:end func_00394F48 */

typedef struct { u8 p0[0x64]; s32 f64; u8 p68[4]; s32 f6C; u8 b70[4]; s32 f74; s32 f78; s32 f7C; } S_390730;
typedef struct { u8 p0[0x148]; f32 f148; f32 f14C; u8 p150[0x70]; s32 f1C0; s32 f1C4; s32 f1C8; s32 f1CC; } P_390730;
typedef struct { u8 p0[8]; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; } T_390730;
typedef struct { u8 p0[0x286C]; s32 f286C; } G_390730;
extern P_390730 *D_001D52FC_00394F90;
extern s16 D_001D9EB4;
extern s16 D_001D9EB8;
extern s16 D_001D9EBA;
extern s16 D_001D9EBC;
extern s32 D_001D9EE8_00394F90;
extern s32 D_001D9EF0_00394F90;
extern s32 D_001D9BC8_00394F90;
extern volatile s32 D_001D5D20;
extern volatile s32 D_001D5D24;
extern volatile s32 D_001D5D28;
extern volatile s32 D_001D5D2C;
extern s32 D_001D9F28;
extern s32 D_001D9F2C;
extern s32 D_001D9F30;
extern u8 D_00143A06[];
extern G_390730 D_001A4BE0_00394F90;
extern void func_003E3E08(void);
extern f32 func_0038D160(f32, f32);
extern s32 func_003A5348(s32, s32, s32);
extern void func_003E3DC0(void);
extern s32 func_003934B8(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00394F90);

INCLUDE_ASM("asm/nonmatchings/text", func_00395478);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C0C0);

LINKER_REMNANT("asm/remnants", func_00396240);

typedef struct { u8 p0[8]; s32 w8; u8 pC[0x44]; s32 w50; s32 w54; s32 w58; s32 w5C; u8 p60[0xC]; s32 w6C; u8 p70[4]; s32 w74; } O_91A18;
extern void func_00396C60();
extern void func_003970D8();
extern void func_00393690();
extern s16 D_001A666A[];
INCLUDE_ASM("asm/nonmatchings/text", func_00396278);

/* PAL candidate for func_00396390 (frontbin).
   Same shape as the US draft; the constant stored at offset 0x7C is 0x82 in PAL
   retail (0x96 in the US build). */

/* localdecomp:start func_00396390 */
extern void func_00393808(void *);
 
void func_00396390(void *p) {
    *(s32 *)((u8 *)p + 0x7C) = 0x82;
    *(s32 *)((u8 *)p + 0x58) = 0x20;
    *(s32 *)((u8 *)p + 0x5C) = 0x20;
    func_00393808(p);
}
/* localdecomp:end func_00396390 */

/* localdecomp:start func_003963C0 */
s32 func_003963C0(void) {
    return 0;
}
/* localdecomp:end func_003963C0 */

LINKER_REMNANT("asm/remnants", func_003963C8);
