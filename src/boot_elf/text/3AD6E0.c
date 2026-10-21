#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void * func_003AF470();
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003AEF00(void *, s32);
extern u8 *func_003AB5D0(u8 *);
extern void func_003AB2B8(void *, s32);
/* --- end of declarations from other files --- */

/* declarations of 3ACE50.c's earlier functions (tools/port_from_us.py) */
typedef struct { f32 x, y; } V2_003A7690;
typedef struct { s32 a, b, c, d, e, f; } T6_003A7690;
typedef struct {
    f32 *pos;        
    u8 pad4[4];
    u32 *color;      
    u32 *font;       
    u8 sub10[0x3C];  
    u8 sub4C[0x13C]; 
    s32 w;           
    s32 h;           
    s32 count;       
    u8 pad194[8];
    s32 xoff;        
    u8 pad1A0[4];
    s32 mode;        
    u8 pad1A8[8];
    f32 f1B0;        
    u8 pad1B4[4];
    s32 text[1];     
} O_003A7690;
extern V2_003A7690 D_001D8440[];
extern V2_003A7690 D_001D8448[];
extern f32 D_001D8450;
extern T6_003A7690 D_001D8458[];
extern T6_003A7690 D_001D8470[];
extern s32 D_001D55E8;
extern void func_0038C6F0_003ACFF0(s32, s32, s32, s32, s32, u32 *);
extern void func_003AB288(void *, f32, f32, f32, f32);
extern void func_003AB3B0(void *, f32, f32, f32, f32);
extern void func_003AB750(void *);
extern void func_0038E530(s32);
extern void func_0038EBC8_003ACFF0(unsigned long, s32, s32, f32, f32, f32, f32, s32, s32, unsigned long, f32, f32);
void func_003877A0();
void func_003ACFF0(void *);
void func_003AD628(void *);
typedef struct { u8 pad0[0xB0]; f32 fB0; } S_00225980_003A7CD0_003A7CD0;
extern S_00225980_003A7CD0_003A7CD0 D_00225900[];

LINKER_REMNANT("asm/boot_elf/remnants", func_003AD6E0);

/* localdecomp:start func_003AD7A8 */
void *func_003AD7A8(u8 *p) {
    s32 i;
    s32 *q = (s32 *)(p + 0x30);
    for (i = 3; i != -1; i--) {
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
        q += 4;
    }
    return p;
}
/* localdecomp:end func_003AD7A8 */

typedef struct { u8 p0[0x18]; f32 f18; s32 f1C; s32 f20; f32 f24; s8 b28; u8 p29[3]; s32 f2C; u8 p30[0x50]; s32 f80; s32 f84; } S_3A7E80;
extern u8 func_003AD8F0_003AD7E0[];
extern u8 func_003AD928_003AD7E0[];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AD7E0);

LINKER_REMNANT("asm/boot_elf/remnants", func_003AD898);

/* localdecomp:start func_003AD8A0 */
void func_003AD8A0(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x2C) = value;
}
/* localdecomp:end func_003AD8A0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AD8A8);

/* localdecomp:start func_003AD8B8 */
typedef struct {
    char pad_0[0x18];   /* Offset 0x00 down to 0x18 */
    f32 float_field;    /* Offset 0x18 - Targeted by lwc1/swc1 */
    char pad_1C[0xC];   /* Padding from 0x1C to 0x28 */
    char byte_flag;     /* Offset 0x28 - Targeted by sb $v0, 0x28($a0) */
} InitContext;

void func_003AD8B8(InitContext* ctx) {
    // 0: lui $at, 0x3f80
    // 4: mtc1 $at, $f1
    register f32 constant_one __asm__("$f1") = 1.0f;

    // FENCE 1: Blocks 'li $v0, 1' from climbing to offset 0:
    __asm__ __volatile__ ("");

    // 8: li $v0, 1
    ctx->byte_flag = 1;

    // c: lwc1 $f0, 0x18($a0)
    (void)((volatile InitContext*)ctx)->float_field;

    // MEMORY CLOBBER FENCE:
    // This tells ee-gcc that all previous memory actions (the lwc1 load) must be 
    // completely processed and finalized before any subsequent memory instructions 
    // are evaluated. This forces 'sb' perfectly down to offset 10:!
    __asm__ __volatile__ ("" : : : "memory");

    // 18: swc1 $f1, 0x18($a0)
    ctx->float_field = constant_one;
}
/* localdecomp:end func_003AD8B8 */

/* localdecomp:start func_003AD8D8 */
void func_003AD8D8(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x80) = value;
}
/* localdecomp:end func_003AD8D8 */

/* localdecomp:start func_003AD8E0 */
u8 func_003AD8E0(void *p, u8 value) {
    u8 old = *((u8 *)p + 0x28);
    *((u8 *)p + 0x28) = value;
    return old;
}
/* localdecomp:end func_003AD8E0 */

/* localdecomp:start func_003AD8F0 */
typedef struct { u8 pad[0x30]; f32 m[4][4]; f32 v[4]; } S_3A7F90;
void func_003AD8F0(S_3A7F90 *p, s32 i, f32 a, f32 b, f32 c, f32 d, f32 e) {
    p->m[i][0] = b;
    p->m[i][1] = c;
    p->m[i][2] = d;
    p->m[i][3] = e;
    p->v[i] = a;
}
/* localdecomp:end func_003AD8F0 */

/* localdecomp:start func_003AD928 */
typedef struct { f32 a[3]; f32 b[3]; } V_7FC8;
void func_003AD928(V_7FC8 *s, s32 i, f32 x, f32 y) {
    s->a[i] = x; s->b[i] = y;
}
/* localdecomp:end func_003AD928 */

/* localdecomp:start func_003AD940 */
void func_003AD940(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x84) = value;
}
/* localdecomp:end func_003AD940 */

/* localdecomp:start func_003AD948 */
void func_003AD948(u8 *p, s32 a) {
    *(s32 *)(p + 0x1C) = a;
    if (p[0x28] == 0) {
        if (a == 1) *(f32 *)(p + 0x18) = 0.0f;
        else *(f32 *)(p + 0x18) = 1.0f;
        p[0x28] = 1;
    }
}
/* localdecomp:end func_003AD948 */

/* localdecomp:start func_003AD988 */
void func_003AD988(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x20) = value;
}
/* localdecomp:end func_003AD988 */

/* localdecomp:start func_003AD990 */
void func_003AD990(void *p, f32 value) {
    *(f32 *)((u8 *)p + 0x24) = value;
}
/* localdecomp:end func_003AD990 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AD998);

/* Candidate for func_003AD9C0 (boot_elf, PAL retail).
   The two globals are declared with an incomplete array type: the compiler
   only puts a symbol in the small data section (and reaches it through $gp)
   when its size is known and small, so an array of unknown size is addressed
   with %hi/%lo, as retail does. */

/* localdecomp:start func_003AD9C0 */
extern s32 D_001D8118[];
extern s32 D_001D8100[];

u8 *func_003AD9C0(u8 *p) {
    u8 *q;
    u8 *a, *b, *c;
    s32 i;
    func_003AB5D0(p);
    func_003AB5D0(p + 0x3C);
    func_003AB5D0(p + 0x78);
    func_003ABD70(p + 0xD0);
    func_003ABAF0(p + 0x110);
    func_003AB5D0(p + 0x140);
    func_003AB5D0(p + 0x17C);
    func_003ABD70(p + 0x1D0);
    func_003ABAF0(p + 0x210);
    func_003AB5D0(p + 0x244);
    func_003AB5D0(p + 0x280);
    q = p + 0x2BC;
    for (i = 7; i != -1; i--) { func_003AB5D0(q); q += 0x3C; }
    func_003AB5D0(p + 0x49C);
    func_003AB5D0(p + 0x4D8);
    func_003AB5D0(p + 0x514);
    func_003AB5D0(p + 0x550);
    func_003AB5D0(p + 0x58C);
    func_003ABAF0(p + 0x5C8);
    func_003ABAF0(p + 0x5F8);
    func_003AB5D0(p + 0x628);
    q = p + 0x664;
    for (i = 7; i != -1; i--) { func_003ABAF0(q); q += 0x30; }
    func_003AD7A8(p + 0x7E8);
    func_003AD7A8(p + 0x870);
    func_003AD7A8(p + 0x8F8);
    func_003AD7A8(p + 0x980);
    func_003AD7A8(p + 0xA08);
    func_003AD7A8(p + 0xA90);
    func_003AAF20(p + 0xB18);
    *(u8 **)(p + 0xB18) = (u8 *)D_001D8118;
    func_003AAF20(p + 0xB1C);
    *(u8 **)(p + 0xB1C) = (u8 *)D_001D8100;
    return p;
}
/* localdecomp:end func_003AD9C0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003ADB88);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003ADB90);

/* localdecomp:start func_003AEF00 */

void func_003AEF00(void *arg0, s32 arg1) {
    void *temp_s0;
    void *temp_s1;
    void *temp_s2;
    void *temp_s3;
    void *temp_s4;
    void *temp_s5;

    (*(s32 *)((u8 *)(arg0) + 0xB38)) = arg1;
    if ((*(s32 *)((u8 *)(arg0) + 0xB3C)) != 0) {
        (*(s32 *)((u8 *)(arg0) + 0xB3C)) = 0;
        temp_s4 = arg0 + 0x7E8;
        func_003AB2B8(arg0 + 0x628, 0);
        temp_s5 = arg0 + 0x870;
        func_003AD948(temp_s4, 1);
        temp_s3 = arg0 + 0x8F8;
        func_003AD948(temp_s5, 1);
        temp_s2 = arg0 + 0x980;
        func_003AD948(temp_s3, 1);
        temp_s1 = arg0 + 0xA08;
        func_003AD948(temp_s2, 1);
        temp_s0 = arg0 + 0xA90;
        func_003AD948(temp_s1, 1);
        func_003AD948(temp_s0, 1);
        func_003AD8B8(temp_s4);
        func_003AD8B8(temp_s5);
        func_003AD8B8(temp_s3);
        func_003AD8B8(temp_s2);
        func_003AD8B8(temp_s1);
        func_003AD8B8(temp_s0);
    }
}
/* localdecomp:end func_003AEF00 */

/* Draft of func_003AEFF8 (from the US rac3-uya-decomp func_003AEE58), names moved to PAL
   addresses: the US symbol func_003829F8 is the PAL func_003829D8. */


/* localdecomp:start func_003AEFF8 */
typedef struct { u8 p0[0x1C4]; u32 f1C4; } S_3A9698;
extern S_3A9698 *D_001D52FC[];
extern s32 func_003829D8(s32, s32, s32, s32, s32, s32);
extern s32 *func_003AB270();
extern f32 *func_003AB748();
extern void func_003AB2B8();
void func_003AEFF8(u8 *base, s32 b, f32 f) {
    s32 *r;
    f32 *q;
    u8 *p;
    if ((D_001D52FC[0]->f1C4 & 0xF000) != 0) {
        func_003829D8(0, 0, 1, 0, 1, 0);
    }
    p = base + 0x628;
    r = func_003AB270(p);
    *r = func_003829D8(0x331465B7, 0x706EC8FF, 0x14, 0, 0, 0);
    q = func_003AB748(p);
    *q = f;
    func_003AB2B8(p, b);
}
/* localdecomp:end func_003AEFF8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AF0B8);

/* localdecomp:start func_003AF0C8 */
u8 *func_003AF0C8(u8 *p) {
    u8 *q; u8 *base; s32 i, j, k;
    base = p;
    for (j = 3; j != -1; j--) {
        q = base;
        for (k = 25; k != -1; k--) { func_003AB820(q); q += 0x3C; }
        base += 0x618;
    }
    func_003AB820(p + 0x1860);
    q = p + 0x18A0;
    for (i = 3; i != -1; i--) { func_003AD9C0(q); q += 0xB50; }
    func_003ABAF0(p + 0x45E0);
    q = p + 0x4610;
    for (i = 3; i != -1; i--) { func_003AC328(q); q += 0x230; }
    func_003AC328(p + 0x4ED0);
    return p;
}
/* localdecomp:end func_003AF0C8 */

extern u8 *D_001D5C78_003AF1F0;
extern s32 D_001D545C;
extern u8 D_001D8730[];
extern u8 D_001D8740[];
extern s32 func_003AC190();
extern void func_003AB858();
extern void func_003AC0D0();
extern void func_003ABF98();
extern void func_003ABFA0();
extern void func_003AB8E8();
extern void func_003AB900();
extern void func_003AC0E8();
extern void func_003AC0C8();
extern void func_003ADB90();
extern void func_003AC360();
extern void func_003ABB30();
extern f32 *func_003ABBD8();
typedef struct { u8 pad[0x5100]; s32 a[4]; s32 b[4]; } S_3A9890;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AF1F0);

LINKER_REMNANT("asm/boot_elf/remnants", func_003AF410);

/* localdecomp:start func_003AF420 */
extern void func_003ACF78(void *);
 
void func_003AF420(void *p, s32 i) {
    func_003ACF78((u8 *)p + (i * 0x230 + 0x4610));
}
/* localdecomp:end func_003AF420 */

/* localdecomp:start func_003AF448 */
extern void func_003AD630(void *);
 
void func_003AF448(void *p, s32 i) {
    func_003AD630((u8 *)p + (i * 0x230 + 0x4610));
}
/* localdecomp:end func_003AF448 */

extern void *func_003AC1E0(void *);
extern void func_00121760(void *, void *);
extern s32 func_003A2AF0();
extern void func_003AC1E8(void *, s32, void *, s32);
extern void func_0011F0A0(s32);
extern s32 func_003A2B50(s32);
extern void func_003AC0F0(void *);
extern void func_003AF1F0(void *, void *, void *);
extern s32 D_001D5C78;
extern u8 D_00160C40[];
typedef struct { u8 b[8]; } V8_3A9B10;
extern u8 D_001D8790[];
extern u8 D_001D8770[];
extern void func_11A264();
extern void func_121760();
extern void func_11F0A0();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AF470);

LINKER_REMNANT("asm/boot_elf/remnants", func_003AF648);
