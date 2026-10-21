#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_0011A264();
extern s32 func_00392F00();
extern s32 func_00393058();
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 38E1F8.c's earlier functions (tools/port_from_us.py) */
typedef struct { s16 x; s16 y; } P_3896E8;
typedef struct {
    u8 n0; u8 n1; u8 p2[0x2E];
    u8 k30[0x10];
    u8 k40[0x10];
    P_3896E8 pt[0x10];
    s32 o90[0x10];
    s32 oD0[0x10];
} T_3896E8;
extern T_3896E8 *D_001D55D0_0038E2B0[2];
extern s32 D_001D9BC8_0038E2B0;
extern s32 D_001D5B34;
extern u8 *D_001D5B38;
extern u8 *D_001D5B3C;
extern s32 D_001D5B30;
extern s32 D_001D55E8;
extern s32 D_0031CFD0_0038E2B0[][16];
extern s32 D_0031CF50_0038E2B0[][16];
extern s32 func_0038A028(s32 a, s32 b);
extern s32 func_00389EF0(s32, s32, s32, s32);
extern u8 D_00144440[];
extern u8 D_00143E40[];
extern u8 D_0014A840[];
extern u8 D_0014A240[];
extern void func_0038E1F8(s32, void *, void *);
extern s32 D_001D9BC8[];
extern s32 D_001D9BC8[];
extern s32 D_001D5B34;
extern s32 D_001D55D0[];
extern s32 D_001D55D8[];
extern s32 D_001D55E0[];
extern s32 D_001D55C0;
extern s32 D_001D55C4_0038E530;
extern s32 D_001D55C8;
extern u8 D_0031CF50[];
extern u8 D_0031CFD0[];
extern u8 *D_001D5B38;
extern u8 *D_001D5B3C;
extern s32 D_001D55E8;
extern s32 *D_001D55C4[];
typedef struct { u32 w0; u32 w4; } E_3899B8;
extern E_3899B8 *D_001D55C4_0038E5C8;
extern u8 D_001D5B42;
typedef struct { u32 w0; u32 w4; } E_389B98;
extern s32 D_001D55C8;
extern s32 *D_001D55C4[];
extern s32 func_0038E488(u8 *p, s32 off, s32 *out);
typedef struct { u32 w0; u32 w4; } E_389D18;
typedef struct { s16 ch; s8 adj; u8 end; } K_389D18;
typedef struct { s16 h0, h2, h4, h6, h8, hA, hC, hE, h10; u16 h12; s16 h14, h16; } B_38BB50;
typedef struct { u32 w0, w1; } G_38BB50;
extern s32 D_001D5B94;
extern u8 D_001D5B41;
extern s32 D_001D5B48[2];
extern s32 D_001D5B5C[];
extern s32 D_001D4BC0[];
extern s32 D_001D4BC4[];
extern void func_003A98B8(s32, s32, s32, s32);
extern s32 func_0038E488(u8 *p, s32 off, s32 *out);
extern s32 func_0038E928_00390768(u8 *, s32, f32);
extern void func_0038EBC8_00390768(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
extern void func_0038E928();
extern void func_0038E5C8(void);
extern void func_0038E7A0();
extern void func_0038E7A0();
extern void func_0038E928();
extern void func_0038E928();
extern void func_0038E928();
extern void func_0038EBC8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
extern void func_0038E928();
extern s32 D_001D55E8;
extern void func_0038E530(s32);
extern void func_0038EBC8_00391240(s32, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32);
extern s32 func_0038E928_00391240(s32, s32, f32);
extern void func_0038EBC8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
extern s32 D_001D55E8;
extern void func_0038E530(s32);
extern void func_0038EBC8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
extern s32 D_001D55E8;
extern void func_0038E530(s32);
extern void func_00390768();
extern f32 func_00390FD8(s32, s32, s32, f32);
extern void func_0038EBC8_00391620(s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, unsigned long, f32);
extern void func_0038E2B0();
extern f32 func_00390FD8();
extern s32 D_00143950[];
extern s32 D_001D5520;
extern void func_12A950(void);
extern void func_12BEE8(s32, s32, s32, s32);
extern s32 D_001D4D08[];
extern s32 D_001D4D0C[];
extern s32 D_001D4D10[];
extern s32 D_001D4D14[];
extern s32 D_001D4D18[];
extern s32 D_001D4D1C[];
extern s32 D_001D4CF8[];
extern s32 D_001D4D08_003917E8;
extern s32 D_001D4D0C_003917E8;
extern void func_00391778(void);
typedef struct {
    u8 p0[0x150];
    s16 h150, h152, h154, h156, h158, h15A;
} E_38CC68;
extern unsigned long D_001D0560[];
extern E_38CC68 *D_001D4CF8_00391880;
extern u8 D_001439FD[];
extern s32 D_001D5520;
typedef int Q_38CE40 __attribute__((mode(TI)));
typedef struct { unsigned long v : 9; unsigned long r : 55; } FB_38CE40;
typedef struct {
    unsigned long dx : 12;
    unsigned long dy : 11;
    unsigned long magh : 4;
    unsigned long magv : 2;
    unsigned long p0 : 3;
    unsigned long dw : 12;
    unsigned long dh : 11;
    unsigned long p1 : 9;
} DI_38CE40;
typedef struct {
    unsigned long nloop : 15;
    unsigned long eop : 1;
    unsigned long p0 : 16;
    unsigned long id : 14;
    unsigned long pre : 1;
    unsigned long prim : 11;
    unsigned long flg : 2;
    unsigned long nreg : 4;
    unsigned long regs0 : 4;
    unsigned long regs : 60;
} GT_38CE40;
typedef struct {
    u8 p0[0x10];
    FB_38CE40 q10;
    DI_38CE40 q18;
    u8 p20[0x10];
    GT_38CE40 t30;
    FB_38CE40 q40;
    unsigned long q48;
    unsigned long q50;
    u8 p58[0x68];
    GT_38CE40 tC0;
    FB_38CE40 qD0;
    unsigned long qD8;
    unsigned long qE0;
    u8 pE8[0x68];
    s16 h150, h152, h154, h156, h158, h15A, h15C, h15E;
    s16 h160, h162, h164, h166, h168, h16A, h16C, h16E;
    s32 w170;
} E_38CE40;
extern E_38CE40 D_001CFEC0_00391A58[];
extern E_38CE40 *D_001D4CF8_00391A58;
extern s32 D_001A1ED0_00391A58[];
extern s32 D_001D5520;
extern u8 D_001D551D;
extern s32 D_001D4D08_00391A58;
extern s32 D_001D4D0C_00391A58;
extern s32 D_001D4D10_00391A58;
extern s32 D_001D4D14_00391A58;
extern s32 D_001D4D18_00391A58;
extern s32 D_001D4D1C_00391A58;
extern s32 D_001D4D20_00391A58;
extern s32 D_001D4D24_00391A58;
extern s32 D_001D4D28_00391A58;
extern s32 D_001D4D2C_00391A58;
extern s32 D_001D4D30_00391A58;
extern s32 D_001D4D34_00391A58;
extern unsigned long D_001D02D0_00391A58[];
extern unsigned long D_001D0070_00391A58[];
extern unsigned long D_001D07B0_00391A58[];
extern unsigned long D_001D0900_00391A58[];
extern unsigned long D_00141850_00391A58[];
extern unsigned long D_00141990_00391A58[];
extern unsigned long D_00141AD0_00391A58[];
extern unsigned long D_00141DC0_00391A58[];
extern unsigned long D_001420B0_00391A58[];
extern void func_0012C138(void *, s32, s16, s16, s16, s16);
extern void func_0012C638(s32, s32, s32, s32, s32, s32);
extern void func_00391778(void);
extern void func_00391880(s32, s32);
extern void func_0038D068();
extern void func_11F0A0(s32);
extern unsigned long D_001D07E8[];
extern void func_12C4B0(s32);
extern s32 D_001D4CF8[];
extern u32 *D_001DA050;
extern s32 D_001D4CF8_00392698;
extern void func_12C820(s32);
extern u32 *D_001DA050;
extern u8 D_1D07B0[], D_1D0900[];
extern u32 *D_001DA050;
extern s32 D_001D4CF8_003927B0;
typedef struct { unsigned long lo : 9; unsigned long hi : 55; } BF_38DC08;
typedef struct { u8 p0[0x160]; s16 h160; s16 h162; s16 h164; s16 h166; u8 p168[4]; u16 h16C; s16 h16E; } S_38DC08;
extern S_38DC08 D_001CFEC0_00392820[];
extern s32 D_001DA050_00392820;
extern long D_001D4C30;
extern void func_0038CF80();
extern void func_0012C638(s32, s32, s32, s32, s32, s32);
extern u32 *D_001DA050;
extern u8 D_001D0070[];
extern u32 *D_001DA050;
extern u8 D_001D7370[];
extern u8 D_001D7390[];
extern u8 D_001D02D0[];
extern u8 D_001D7300[];
extern u32 *D_001DA050_00392C48;
extern void func_003A97F8(s32, unsigned long);

/* localdecomp:start func_00392DF8 */
extern s32 D_001D5C78;
s32 func_00392DF8(void) { s32 v = D_001D5C78; if (v != 0) return v + 0x7090; return 0; }
/* localdecomp:end func_00392DF8 */

/* localdecomp:start func_00392E18 */
void *func_00392E18(p) u8 *p; {  /* K&R: a later caller uses an unprototyped call */
    void *r;
    *(s32 *)(p + 0x58) = 0; *(s32 *)(p + 0x5C) = 0; *(s32 *)(p + 0x60) = 0;
    r = ((void *(*)(void *, s32, s32))func_0011A264)(p + 8, 0xCD, 0x50);
    p[0x6C] = 0; *(s32 *)(p + 0x68) = 1;
    return r;
}
/* localdecomp:end func_00392E18 */

typedef struct { s32 a, b; } E_38E;
typedef struct { u8 pad[8]; E_38E e[10]; s32 f58, f5C, f60, f64, f68; u8 f6C; } S_38E;
/* localdecomp:start func_00392E60 */
s32 func_00392E60(S_38E *p, s32 *a, s32 *b) {
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
/* localdecomp:end func_00392E60 */

/* localdecomp:start func_00392F00 */
s32 func_00392F00(S_38E *p, s32 v) {
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
/* localdecomp:end func_00392F00 */

/* localdecomp:start func_00392F78 */
extern void *func_00392E18();
 
void func_00392F78(s32 *p) {
    func_00392E18();
}
/* localdecomp:end func_00392F78 */

extern s32 func_0039F308();
typedef struct { u8 p0[8]; struct { s32 id; s32 x; } e[10]; s32 head; s32 tail; } S_E380;
extern u8 D_00142BA0[];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00392F98);

/* localdecomp:start func_00393028 */
extern void func_00392F98(s32 *);
extern void func_00392F78(s32 *);
void func_00393028(s32 *p) {
    func_00392F98(p);
    *p = 0;
    func_00392F78(p);
}
/* localdecomp:end func_00393028 */

typedef struct {
    u8 pad0[0x60];
    s32 active;
    u8 flag64;
    u8 pad65[3];
    s32 mode68;
    u8 flag6C;
} Object_0038E440;
extern s32 D_001D5B94;
extern s32 func_003A12C0(s32, s32, s32, s32, u8 *);
/* localdecomp:start func_00393058 */
s32 func_00393058(Object_0038E440 *object) {
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
    func_00392E60(object, &values[0], &values[1]);

    mode = 1;
    if ((u32)(D_001D5B94 - 1) < 2) {
        mode = 2;
    }
    object->mode68 = mode;

    if (values[1] == 0) {
        result = func_003A12C0(1, mode, 0, values[0], 0);
    } else if (values[1] == 1) {
        result = func_003A12C0(2, mode, values[0], 0, 0);
    }
    if (result < 0) {
        func_00392F78((s32 *)object);
    }
    return result == 0;
inactive:
    return 0;
}
/* localdecomp:end func_00393058 */

/* localdecomp:start func_00393120 */
extern s32 func_0039F308();

void func_00393120(s32 *input_ptr) {
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
            func_0039F308();
        }
        value = *value_ptr;
    }

evaluate:
    if (value == 0xD && *(u8 *)0x1D5587 == 0) {
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
/* localdecomp:end func_00393120 */

typedef struct { u8 pad[0x18]; s16 h18; u8 pad2[0x17C - 0x1A]; s32 x17C; } S_38E5B8;
extern S_38E5B8 D_00142430_003931D0[];
extern s32 D_001D5B74;
extern s32 D_001D9D04;
extern s32 D_001D545C;
extern s32 D_001D4CF0;
extern s32 D_001D4CEC_003931D0;
extern void func_0039F008(s32, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003931D0);

LINKER_REMNANT("asm/boot_elf/remnants", func_003932A0);

/* localdecomp:start func_003932D0 */
extern u8 D_001D551C;
void func_003932D0(void) {
    D_001D551C = 0;
}
/* localdecomp:end func_003932D0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003932D8);

extern u8 D_001D5BDC;
extern s32 D_001D5C90;
extern s32 D_0022758C;
extern s32 D_001DA058;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003932E8);

/* localdecomp:start func_00393340 */
extern s32 D_001D5C90;
void func_00393340(s32 a) {
    D_001D5C90 = a;
}
/* localdecomp:end func_00393340 */

/* localdecomp:start func_00393348 */
typedef struct LookupEntry_38E730 {
    u16 key;
    u8 reserved[6];
} LookupEntry_38E730;
extern LookupEntry_38E730 *D_001D9EA4_00393348[];
s32 func_00393348(s32 key) {
    LookupEntry_38E730 *entry = *D_001D9EA4_00393348;
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
/* localdecomp:end func_00393348 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003933A0);

/* localdecomp:start func_003933B0 */
typedef struct { u8 p0[0x14]; s32 a[8]; s32 b[16]; s32 c[1]; } S_0038E798;
typedef struct { u32 w; u32 x; } E_0038E798;
extern S_0038E798 *D_001D9EA0_003933B0[];
extern E_0038E798 *D_001D9EAC_003933B0[];
extern E_0038E798 *D_001D9EB0_003933B0[];
void func_003933B0(s32 n, s32 size) {
    s32 i;
    s32 j;
    s32 end;
    if (D_001D9EA0_003933B0[0]->c[n] == 0) {
        size = (size + 0xF) & 0xFFFFFFF0;
        D_001D9EA0_003933B0[0]->c[n] = size;
        i = (n != 0) ? D_001D9EA0_003933B0[0]->a[n - 1] : 0;
        end = D_001D9EA0_003933B0[0]->a[n];
        for (j = i; j < end; j++) {
            D_001D9EB0_003933B0[0][j].w &= 0x7FFFFFFF;
            D_001D9EB0_003933B0[0][j].w += size;
        }
        i = (n != 0) ? D_001D9EA0_003933B0[0]->b[n - 1] : 0;
        end = D_001D9EA0_003933B0[0]->b[n];
        for (j = i; j < end; j++) {
            D_001D9EAC_003933B0[0][j].w &= 0x7FFFFFFF;
            D_001D9EAC_003933B0[0][j].w += size;
        }
    }
}
/* localdecomp:end func_003933B0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00393510);

/* localdecomp:start func_00393518 */
extern u32 D_001D5D50;
u32 func_00393518(void) {
    u32 v = D_001D5D50;
    u32 r = 0;
    if (v <= 0x1CFFFF) r = (0x1D0000 - v) >> 2;
    return r;
}
/* localdecomp:end func_00393518 */

typedef struct { u8 p0[0x14]; s32 a[8]; s32 b[16]; s32 c[1]; } S_38E930;
typedef struct { u32 w0; u16 h4; u8 b6; u8 b7; } E_38E930;
extern S_38E930 * volatile D_001D9EA0_00393548;
extern E_38E930 *D_001D9EAC_00393548;
extern volatile s32 D_001A1F08_00393548[];
extern void func_003933B0_00393548();
extern void func_00397D60(s32, s32, s32, s32, s32, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00393548);

extern s32 D_00227600[];
extern s32 D_001D9E98;
extern s32 D_001D9E9C;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00393670);

/* localdecomp:start func_003936A0 */
__asm__(".extern D_001D9E98, 16");
__asm__(".extern D_001D9E9C, 16");
s32 func_003936A0(s32 size) {
    register s32 amount __asm__("$16") = size;
    register s32 current __asm__("$4");
    register s32 result __asm__("$2");
    if (D_001D9E98 == 0) {
        func_00393670();
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
/* localdecomp:end func_003936A0 */
TEXT_PADDING(2);

typedef struct { s32 f0; s32 f4; u8 p8[0x18]; s32 f20; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; u8 p3C[0x28]; s32 f64; s32 f68; u8 p6C[4]; s32 f70; u8 p74[8]; s32 f7C; u8 p80[0x10]; } S_EB;
extern S_EB D_00331AE0_00393728[];
extern s32 D_001D5B94_00393728;
extern s32 D_001D9E88_00393728;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00393728);

/* localdecomp:start func_00393830 */
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
extern void func_00393918();
void func_00393830(S_38EC18 *p) {
    func_00393918(p, p->a20);
    p->v4 = p->a24;
    p->v14 = p->a34;
    p->v18 = p->a38;
    p->vC = p->a2C;
    p->v8 = p->a28;
    p->f10 = p->a30;
    if (p->f10) p->f10(p);
    p->x68 = 0;
}
/* localdecomp:end func_00393830 */

typedef struct { s32 pad0; s32 f4; s32 pad8[7]; s32 f24; s32 pad28[15]; s32 id; s32 f68; s32 pad6C[9]; } S_38ED78;
extern S_38ED78 D_00331AE0[];
extern void func_00393728();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00393898);

/* localdecomp:start func_00393918 */
typedef struct { u16 x0; u16 x2; u16 x4; u8 x6; u8 x7; } E_38ED00;
typedef struct { s32 x0; u8 pad[0x3C]; s16 x40; u8 x42; u8 x43; s32 x44; } S_38ED00;
extern E_38ED00 *D_001D9EA4[];
s32 func_00393348(s32);
void func_00393918(S_38ED00 *d, s32 a) {
    s32 i = func_00393348(a);
    if (i < 0) i = 0;
    d->x0 = D_001D9EA4[0][i].x0;
    d->x40 = i;
    d->x42 = D_001D9EA4[0][i].x6;
    d->x44 = D_001D9EA4[0][i].x4;

}
/* localdecomp:end func_00393918 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00393990);

/* localdecomp:start func_00393A00 */
typedef struct { u8 pad[0x58]; s32 w; s32 h; union { s32 flags; u8 c; } u; } S_38EDE8;
s32 func_00393A00(S_38EDE8 *p, s32 *x, s32 *y) {
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
/* localdecomp:end func_00393A00 */

typedef struct { u8 p0[0x58]; s32 f58; s32 f5C; u32 f60; u8 p64[0x18]; s32 f7C; } S_38EE58;
extern f32 D_00332230[];
extern f32 D_00332290[];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00393A70);

/* localdecomp:start func_00393BE8 */
typedef struct { u8 p0[8]; s32 f8; s32 *fC; u8 p1[0x48]; s32 f58; s32 f5C; s32 f60; u8 p2[0x10]; s32 f74; s32 f78; } S;
void func_00393BE8(void *arg) {
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
/* localdecomp:end func_00393BE8 */

/* US draft of func_00393CD8 (rac3-uya-decomp func_00393C18, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_00393CD8 */
extern void func_00393BE8(void *);
 
void func_00393CD8(void *p) {
    *(s32 *)((u8 *)p + 0x7C) = 0xB4;
    *(s16 *)((u8 *)p + 0x48) = 0;
    *(s16 *)((u8 *)p + 0x4A) = 0;
    func_00393BE8(p);
}
/* localdecomp:end func_00393CD8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00393D08);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00393D10);

typedef struct { u8 p0[8]; s32 f8; s32 *fC; u8 p10[0x5C]; s32 f6C; u8 b70[4]; s32 f74; s32 f78; s32 f7C; } S_38F0F8;
extern s32 func_003967B0();

LINKER_REMNANT("asm/boot_elf/remnants", func_00393ED0);

typedef struct { u8 pad[0x38]; u16 h38; u8 pad2[0xF0 - 0x3A]; } S_38F310;
typedef struct { s32 w0; u8 pad[0x14]; s32 w18; } D_393F38;
extern s32 D_001D9EE8_00393F38;
extern s32 *D_001D9EF0_00393F38;
extern s32 D_001D5D40;
extern s32 D_001D5CAC;
extern s32 D_1D4C60[2];
extern s32 D_1D4C80[2];
extern u8 D_001425C0[];
extern S_38F310 D_001DAA40_00393F38[];
extern D_393F38 D_00331990[];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00393F38);

/* func_00393FC8 (PAL): US draft of rac3-uya-decomp func_00393EF8, names moved to PAL addresses.
   The only PAL change is the last constant: w78 = 25 (0x19) instead of the US 30 (0x1e). */


/* localdecomp:start func_00393FC8 */
typedef struct { u8 pad[0x48]; s16 h48; s16 h4A; u8 p2[0x58-0x4C]; s32 w58; s32 w5C; u8 p3[0x70-0x60]; s32 w70; s32 w74; s32 w78; } S_38F3A0;
extern void func_00393F38(s32);
void func_00393FC8(S_38F3A0 *p) {
    func_00393F38(0);
    p->w58 = 0xD2; p->w5C = 0xC8; p->w74 = -2; p->w78 = 25; p->h48 = 0; p->h4A = 0; p->w70 = 0;
}
/* localdecomp:end func_00393FC8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00394020);

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
extern s32 D_001D9EE8_00393F50;
extern s32 D_001D9EF0_00393F50;
extern volatile s32 D_001D5D00;
extern volatile s32 D_001D5D04;
extern volatile s32 D_001D5D08;
extern volatile s32 D_001D5D0C;
extern u8 D_1425C0[];
extern T_38F3F8 D_001DAA40_00393F50[];
extern s16 D_001CCFD4[];
extern u8 D_1A4BE0[];
extern u8 D_1A7C10[];
extern s32 D_1427F0[];
extern u32 D_001D4C38;
extern s32 D_001D9F2C;
extern s32 D_001D9F30;
extern s32 D_001D9F28;
extern s32 D_001D9BC8_00393F50;
extern s32 func_003E41A8(void);
extern void func_003E41C0(void);
extern void func_003E4178(void);
extern void func_00398070(void);
extern s32 func_00398088(void);
extern void func_00398068(void);
extern void func_00398060(void);
extern void func_003AEF00(void *, s32);
extern s32 func_003A3FB8(s32, s32);
extern s32 func_003A5748(s32, s32, s32);
extern s32 func_0038CEE0(void *);
extern f32 func_0038D540(f32, f32);
extern f32 func_0038DEE0(f32, f32);
extern f32 func_0038DF80(f32, f32);
extern f32 func_0038DF28(f32);
extern void func_003A2958(void);
extern s32 func_0039AFE8(s32);
extern void func_0039AE18(s32);
extern void func_00381BB8(s32);
extern void func_00381C80(s32);
extern s32 func_00393898(s32);
#define ROW_38F3F8 ((E_38F3F8 *)((s32 *)D_001D9EF0_00393F50)[D_001D5CAC])
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00394A00);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C0D0);

/* US draft of func_00395328 (rac3-uya-decomp func_00395240, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_00395328 */
extern s32 D_001D9EE8[];
extern s32 D_001D9EF0[];
extern s32 D_001D5D38;
extern s32 D_001D5CAC;
void func_00395328(u8 *p) {
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
/* localdecomp:end func_00395328 */

typedef struct { u8 p0[0x64]; s32 f64; u8 p68[4]; s32 f6C; u8 b70[4]; s32 f74; s32 f78; s32 f7C; } S_390730;
typedef struct { u8 p0[0x148]; f32 f148; f32 f14C; u8 p150[0x70]; s32 f1C0; s32 f1C4; s32 f1C8; s32 f1CC; } P_390730;
typedef struct { u8 p0[8]; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; } T_390730;
typedef struct { u8 p0[0x286C]; s32 f286C; } G_390730;
extern P_390730 *D_001D52FC_00395370;
extern s16 D_001D9EB4;
extern s16 D_001D9EB8;
extern s16 D_001D9EBA;
extern s16 D_001D9EBC;
extern s32 D_001D9EE8_00395370;
extern s32 D_001D9EF0_00395370;
extern s32 D_001D9BC8_00395370;
extern volatile s32 D_001D5D20;
extern volatile s32 D_001D5D24;
extern volatile s32 D_001D5D28;
extern volatile s32 D_001D5D2C;
extern s32 D_001D9F28;
extern s32 D_001D9F2C;
extern s32 D_001D9F30;
extern u8 D_00143A06[];
extern G_390730 D_001A4BE0_00395370;
extern void func_003E41C0(void);
extern f32 func_0038D540(f32, f32);
extern s32 func_003A5748(s32, s32, s32);
extern void func_003E4178(void);
extern s32 func_00393898(s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00395370);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00395858);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C0F0);

LINKER_REMNANT("asm/boot_elf/remnants", func_00396620);
