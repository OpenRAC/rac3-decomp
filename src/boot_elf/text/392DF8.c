#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_0011A264();
extern s32 func_00392F00();
extern s32 func_00393058();
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
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
/* localdecomp:start func_00392F98 */
/* the copy of func_00392BB8 */
extern s32 func_0039F308();
typedef struct { u8 p0[8]; struct { s32 id; s32 x; } e[10]; s32 head; s32 tail; } S_E380_00392F98;
extern u8 D_00142BA0[];
void func_00392F98(s32 *arg) {
    S_E380_00392F98 *s = (S_E380_00392F98 *)arg;
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
    func_0039F308();
}
/* localdecomp:end func_00392F98 */

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
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern u8 D_001D5587_00393120;
__asm__(".extern D_001D5587_00393120, 16");
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
    if (value == 0xD && D_001D5587_00393120 == 0) {
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
