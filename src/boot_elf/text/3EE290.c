#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003EE310();
extern void *func_003EF4C8();
extern void *func_003F02D0();
void func_003F0250(void *, s32);
extern void func_003F03A0(void *p, f32, f32);
extern void func_003F0358(u8 *p, u8, s32);
extern void func_003EE518(void *p, s32, s32);
typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
extern void *func_003EEB18();
extern void func_003EE7C0(u8 *, f32, f32, f32, f32);
extern void func_003EE290();
/* --- end of declarations from other files --- */

/* declarations of 3EAB38.c's earlier functions (tools/port_from_us.py) */
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
extern s32 D_001D9790[];
extern u8 D_001DAA09;
extern void *func_003EA0B0(HT_8 *, u32);
extern s32 D_001D9790_g;
extern void func_003EDF30();
extern u8 D_001DAA0A;
extern void *func_003EA130(HT_8 *, u32);
extern s32 D_001D9790_g;
extern u8 D_001DAA12;
extern void *func_003EA540(HT_8 *, u32);
extern s32 D_001D9790[];
extern s32 D_001D9790_g;
extern u8 D_001DAA14;
extern void *func_003EA640(HT_8 *, u32);
extern s32 D_001D9790_g;
extern void func_003EDE88(void *, s32, s32);
extern u8 D_001DAA0E;
extern void *func_003EA340(HT_8 *, u32);
extern s32 D_001D9790_g;
extern s32 func_003EDEB0();
extern u8 D_001DAA0F;
extern void *func_003EA3C0(HT_8 *, u32);
extern s32 D_001D9790_g;
extern void func_003EDEC0(void *, s32, s32);
extern s32 D_001D9790_g;
extern void func_003EDEF8();
extern u8 D_001DAA10;
extern void *func_003EA440(HT_8 *, u32);
extern s32 D_001D9790[];
typedef struct { u8 b[16]; } V16_func_003E5D08;
extern s32 D_001D9790_func_003E5D08;
extern V16_func_003E5D08 D_001D96C0_func_003E5D08;
extern u8 D_001DAA11;
extern void *func_003EA4C0(HT_8 *, u32);
extern s32 D_001D9790_g;
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
extern s32 D_001D97C0[];
extern void func_003EDF20(void *, f32, f32);
extern s32 D_001D97C0_g;
extern void func_003EDF30();
extern s32 D_001D97C0_g;
extern void func_003F0D80();
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
extern s32 D_001D97C0_003EBA28;
extern void func_003F0E00(void *, s32, s16, s16, s32);
extern u8 D_001DAA13;
extern void *func_003EA5C0(HT_8 *, u32);
extern s32 D_001D97C0[];
extern void func_003EDF48(void *, f32, f32);
extern s32 D_001D97C0_g;
extern void func_003F0D38(void *, s32);
extern s32 D_001D97C0_g;
extern void func_003EDE88(void *, s32, s32);
extern s32 D_001D97C0_g;
extern s32 func_003EDEB0();
extern s32 D_001D97C0_g;
extern void func_003EDEC0(void *, s32, s32);
extern s32 D_001D97C0_g;
extern void func_003EDEF8();
extern s32 D_001D97C0[];
typedef struct { u8 b[16]; } V16_003E6538;
extern s32 D_001D97C0_003EBE58;
extern V16_003E6538 D_001D96C0;
extern s32 D_001D97C0[];
extern void func_003F0E78(u8 *, s32, f32, f32);
typedef struct {
    u8 pad0[4];
    s32 count;
    struct { u32 key; void *value; } entries[3];
} Table_003E6680;
extern u8 D_001DAA0B;
extern void *func_003EA1B0(void *, u32);
extern s32 D_001D97C0[];
extern void func_003F0DE8(void *, f32);
extern s32 D_001DAA0C_003EC0D8;
typedef struct { s32 key; s32 val; } E;
typedef struct { s32 pad; s32 n; E e[3]; } T;
extern s32 func_003EA238();
extern s32 D_001D97C0[];
extern void func_003F0E28(void *, f32);
extern s32 D_001D97C0[];
extern void func_003F0E78(u8 *, s32, f32, f32);
extern s32 D_001D97C0_g;
extern s32 func_003F0E40();
extern u8 D_001DAA19;
extern void *func_003EA8C8(HT_8 *, u32);
extern s32 D_001D97C0_g;
extern s32 func_003F0E58();
extern s32 D_001D97C0_g;
extern void func_003F1090(void *, s32);
extern s32 D_001D9760[];
extern s32 D_001D9760_g;
extern void func_003EDF30();
extern s32 D_001D9760[];
typedef struct V_3E6C80 { u8 pad[0x10]; s32 (*fn)(void *, s32); } V_3E6C80;
typedef struct { u8 pad[8]; V_3E6C80 *vt; } O_3E6C80;
extern s32 D_001D9760_003EC5A0;
typedef struct S_3E6CE8 S_3E6CE8;
typedef struct { u8 pad[0x10]; s32 (*fn)(S_3E6CE8 *, s32); } V_3E6CE8;
struct S_3E6CE8 { u8 pad[8]; V_3E6CE8 *vt; u8 p2[0x4A-0xC]; s16 h4A; };
extern s32 D_001D9760_003EC608;
extern s32 D_001D9760_g;
extern void func_003EDE88(void *, s32, s32);
extern s32 D_001D9760_g;
extern s32 func_003EDEB0();
extern s32 D_001D9760_g;
extern void func_003EDEC0(void *, s32, s32);
extern s32 D_001D9760_g;
extern void func_003EDEF8();
extern s32 D_001D9760[];
typedef struct { u8 b[16]; } V16_003E6F50;
extern s32 D_001D9760_003EC870;
extern V16_003E6F50 D_001D96C0_003EC870;
extern s32 D_001D9760_003EC948;
extern u8 D_001DAA16;
extern void *func_003EA748(HT_8 *, u32);
extern s32 D_001D9760[];
extern u8 D_001DAA0D;
extern void *func_003EA2C0(HT_8 *, u32);
extern s32 D_001D9730[];
extern s32 D_001D9730_g;
extern void func_003EDF30();
extern s32 D_001D9730[];
extern s32 D_001D9730_g;
extern s32 D_001D9730_g;
extern void func_003EDE88(void *, s32, s32);
extern s32 D_001D9730_g;
extern s32 func_003EDEB0();
extern s32 D_001D9730_g;
extern void func_003EDEC0(void *, s32, s32);
extern s32 D_001D9730_g;
extern void func_003EDEF8();
extern s32 D_001D9730[];
typedef struct { u8 b[16]; } V16_003E7638;
extern s32 D_001D9730_003ECF58;
extern V16_003E7638 D_001D96C0_003ECF58;
extern s32 D_001D9730[];
extern s32 D_001D97F0[];
extern s32 D_001D97F0_g;
extern void func_003EDF30();
extern s32 D_001D97F0[];
extern s32 D_001D97F0_g;
typedef struct { s32 pad[4]; s32 (*fn)(void *, s32); } V_3E7900;
typedef struct { s32 a, b; V_3E7900 *vt; u8 pad[0x34]; s32 c; s32 d; } S_3E7900;
extern s32 D_001D97F0_003ED220;
extern u8 D_001DAA17;
extern void *func_003EA7C8(HT_8 *, u32);
extern s32 D_001D97F0_g;
extern void func_003EDE88(void *, s32, s32);
extern s32 D_001D97F0_g;
extern s32 func_003EDEB0();
extern s32 D_001D97F0_g;
extern void func_003EDEC0(void *, s32, s32);
extern s32 D_001D97F0_g;
extern void func_003EDEF8();
extern s32 D_001D97F0[];
extern s32 D_001D97F0[];
typedef struct { u8 b[16]; } V16_003E7C90;
extern s32 D_001D97F0_003ED5B0;
extern V16_003E7C90 D_001D96C0_003ED5B0;
extern s32 D_001D9700[];
extern u8 D_001DAA18;
extern void *func_003EA848(HT_8 *, u32);
typedef struct S_3E7EC8 S_3E7EC8;
typedef struct { u8 pad[0x10]; s32 (*f10)(S_3E7EC8 *, s32); } V_3E7EC8;
struct S_3E7EC8 { u8 pad[8]; V_3E7EC8 *vt; };
extern s32 D_001D9700_003ED7E8;
extern s32 func_003EE158(S_3E7EC8 *a, s32 b);
typedef struct { s32 pad[4]; s32 (*fn)(void *, void *); } V_3E7F20;
typedef struct { s32 a, b; V_3E7F20 *vt; } S_3E7F20;
extern void *D_001D9700_003ED840[];
extern u8 D_001DAA1A;
extern void *func_003EA948(HT_8 *, u32);
extern s32 D_001D9700_g;
extern void func_003EDE88(void *, s32, s32);
extern s32 D_001D9700_g;
extern s32 func_003EDEB0();
extern s32 D_001D9700_g;
extern void func_003EDEC0(void *, s32, s32);
extern s32 D_001D9700_g;
extern void func_003EDEF8();
extern s32 D_001D9700[];
extern s32 D_001D9700[];
extern void func_003EDF20(void *, f32, f32);
extern s32 D_001D9700_g;
extern void func_003EDF30();
extern s32 D_001D9700[];
extern void func_003EDF48(void *, f32, f32);
typedef struct { u8 p0[8]; void *f8; u8 pC[4]; s32 f10, f14, f18, f1C; f32 f20, f24; s32 f28; } O_3E8420;
extern u8 D_001D96D8[];
extern void **func_003E74A0();
extern void func_003EDE88(void *, s32, s32);
extern void func_003EDEC0(void *, s32, s32);
extern void func_003EDF20(void *, f32, f32);
extern void func_003EDF48(void *, f32, f32);
typedef struct V_3E8670 { u8 pad[0x14]; s32 (*fn)(void *, s32); } V_3E8670;
typedef struct { u8 pad[8]; V_3E8670 *vt; } O_3E8670;
extern s32 func_003EDEB0();
typedef struct { u8 pad[0x18]; void (*fn)(void *, s32); } V_3E86C8;
typedef struct { u8 pad[8]; V_3E86C8 *vt; } S_3E86C8;
extern s32 func_003EDEB0();
extern void func_003E75D0(void);
extern void func_003E75F0(void);
extern s32 func_003EDEB0(void *, s32);
extern char D_001D9670[];
extern f32 D_001D9698;
extern f32 D_001D969C;
extern void func_003A98B8(s32, s32, s32, s32);
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E8838;
typedef struct { s32 *e[16]; s32 pad[2]; s32 n; } O_003E8838;
typedef struct { u8 p0[0x2C]; O_003E8838 *x2C; } T_003E8838;
extern S_003E8838 D_001DA938_003EE158[];
extern s32 *func_003E6FC0();
extern s32 func_003E71A0();
extern s32 func_003E6730();
extern s32 D_001D96D0;
extern s32 func_003E74D0();
extern void func_003E74C0();

/* localdecomp:start func_003EE290 */
extern s32 func_003E74D0();
typedef struct { s32 a[0x12]; s32 x48; } S_E8;
typedef struct { u8 p[0x2C]; S_E8 *x2C; } T_E8;
void func_003EE290(T_E8 *a0) {
    s32 i;
    for (i = 0; i < a0->x2C->x48; i++) {
        s32 *p = (s32 *)((u8 *)(i << 2) + (s32)a0->x2C);
        if (*p != 0) {
            func_003E74D0(*p);
        }
        *p = 0;
    }
}
/* localdecomp:end func_003EE290 */

typedef struct { s32 *arr[16]; s32 x40, x44, x48, x4C, x50, x54; f32 x58, x5C; } O_3E89F0;
typedef struct { u8 p0[8]; void *f8; u8 p1[0x2C - 0xC]; O_3E89F0 *x2C; } T_3E89F0;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); } VT_3E89F0;
extern u8 D_001D9708[8];
void **func_003E7078(s32 *, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EE310);

typedef struct { s32 *arr[16]; s32 x40; s32 x44; } O_3E8AD0;
typedef struct { u8 p0[8]; void *f8; u8 p1[0x2C - 0xC]; O_3E8AD0 *x2C; } T_3E8AD0;
typedef struct { u8 p0[4]; s32 f4; } S_3E8AD0;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); s32 (*fC)(); } VT_3E8AD0;
extern u8 D_001D9708[8];
extern u8 D_001D9670_003EE3F0[8];
extern S_3E8AD0 D_001DA938_003EE3F0[];
extern s32 *func_003E6FC0();
extern s32 **func_003E7078_003EE3F0();
extern s32 func_003E74D0();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EE3F0);

/* localdecomp:start func_003EE518 */
void func_003EE518(void *p, s32 m, s32 set) {
    if (set != 0) {
        *(*(u8 **)((u8 *)p + 0x2C) + 0x4C) |= m;
    } else {
        *(*(u8 **)((u8 *)p + 0x2C) + 0x4C) &= ~m;
    }
}
/* localdecomp:end func_003EE518 */

/* localdecomp:start func_003EE548 */
s32 func_003EE548(void *a0, s32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    return (*(u8 *)((u8 *)p + 0x4c) & a1) != 0;
}
/* localdecomp:end func_003EE548 */

typedef struct { u8 b[16]; } B16_3E8C40;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3E8C40;
extern s32 func_0011A264(void *, s32, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EE560);
TEXT_PADDING(2);

/* localdecomp:start func_003EE7C0 */
void func_003EE7C0(u8 *p, f32 a, f32 b, f32 c, f32 d) {
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x50) = a;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x58) = b;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x54) = c;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x5C) = d;
}
/* localdecomp:end func_003EE7C0 */

/* localdecomp:start func_003EE7E8 */
typedef struct O_3E8EC8 O_3E8EC8F;
typedef struct { u8 p0[0x20]; void (*f20)(O_3E8EC8F *, s32, f32 *, s32); } V_3E8EC8;
typedef struct { s32 *tbl[1]; } L_3E8EC8;
typedef struct { u8 p0[0x48]; s32 f48; } L2_3E8EC8;
typedef struct O_3E8EC8 { u8 p0[8]; V_3E8EC8 *f8; u8 pC[0x20]; struct { s32 *e[1]; u8 pad[0x44]; s32 n; } *f2C; } O_3E8EC8;
extern void func_003EE0A8();
extern s32 func_003EE548();
extern void func_003EE0F8(f32, f32, f32, f32);
extern void func_003EE038();
void func_003EE7E8(O_3E8EC8 *self, s32 b) {
    f32 v[4];
    s32 i;
    self->f8->f20(self, b, v, 1);
    func_003EE0A8(self, v);
    if (func_003EE548(self, 1)) {
        func_003EE0F8(v[0], v[1], v[2], v[3]);
    }
    for (i = 0; i < self->f2C->n; i++) {
        func_003EE038(((s32 **)self->f2C)[i], b);
    }
    if (func_003EE548(self, 1)) {
        func_003EE0F8(0.0f, 0.0f, 1.0f, 1.0f);
    }
}
/* localdecomp:end func_003EE7E8 */

/* localdecomp:start func_003EE8D0 */
typedef struct { u8 b[16]; } B16_3E8FB0;
typedef struct { u8 p0[8]; s32 (**vt)(); } C_3E8FB0;
typedef struct { s32 *e[1]; u8 p0[0x40]; C_3E8FB0 *f44; s32 n; s32 p1; f32 f50, f54, f58, f5C; } S_3E8FB0;
typedef struct { u8 p0[0x2C]; S_3E8FB0 *f2C; } O_3E8FB0;
extern s32 func_003EDF90();
s32 func_003EE8D0(O_3E8FB0 *self, f32 *b) {
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
            func_003EDF90(((s32 **)self->f2C)[i], b);
        }
    }
    return 1;
}
/* localdecomp:end func_003EE8D0 */

/* localdecomp:start func_003EE9E8 */
typedef struct { u8 b[16]; } B16_3E90C8;
typedef struct { s32 *e[1]; u8 p0[0x44]; s32 n; s32 p1; f32 f50, f54, f58, f5C; } S_3E90C8;
typedef struct { u8 p0[0x2C]; S_3E90C8 *f2C; } O_3E90C8;
extern void func_003EDFE8();
void func_003EE9E8(O_3E90C8 *self, f32 *b) {
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
        func_003EDFE8(((s32 **)self->f2C)[i], b);
    }
}
/* localdecomp:end func_003EE9E8 */

/* localdecomp:start func_003EEAD8 */
s32 func_003EEAD8(void) {
    return 7;
}
/* localdecomp:end func_003EEAD8 */

/* localdecomp:start func_003EEAE0 */
s32 func_003EEAE0(s32 p, s32 k) {
    if (k == 7) {
        return 1;
    }
    return func_003EDF60(p, k);
}
/* localdecomp:end func_003EEAE0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003EEB10);

extern void func_003EDD40(void);
extern unsigned char D_001D9738[];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EEB18);

/* localdecomp:start func_003EEB80 */
extern s32 D_001D9730_g;
extern s32 func_003EDF60(s32, s32);
s32 func_003EEB80(s32 p, s32 k) {
    if (k != D_001D9730_g) return func_003EDF60(p, k);
    return 1;
}
/* localdecomp:end func_003EEB80 */

/* localdecomp:start func_003EEBB0 */
extern s32 D_001D9730_g;
s32 func_003EEBB0(void) { return D_001D9730_g; }
/* localdecomp:end func_003EEBB0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EEBB8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EEBF8);

typedef struct { u8 b[16]; } B16_3E98B8;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3E98B8;
extern s32 func_0011A264(void *, s32, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EF1D8);

/* localdecomp:start func_003EF438 */
s32 func_003EF438(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))((u8 *)p + 0x2C);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003EF438 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003EF468);

/* localdecomp:start func_003EF470 */
extern char D_001D9670[];
extern s32 func_003F2738();
void func_003EF470(u8 *p, s32 f) {
    *(void **)(p + 8) = D_001D9670;
    if (f & 1) func_003F2738(p);
}
/* localdecomp:end func_003EF470 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003EF4A0);

/* localdecomp:start func_003EF4C8 */
extern void func_003EF570();
extern void func_003EF640(void *, s32, s32, s32, s32);
extern void func_003EDD40(void);
extern u8 D_001D9768[];
void *func_003EF4C8(void *arg0)
{
  void **new_var;
  func_003EDD40();
  *((s32 *) (((u8 *) arg0) + 0x2C)) = 0;
  *((s32 **) (((u8 *) arg0) + 8)) = D_001D9768;
  *((s32 *) (((u8 *) arg0) + 0x30)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x38)) = 0x80808080;
  *((s32 *) (((u8 *) arg0) + 0x3C)) = 0x80808080;
  *((s32 *) (((u8 *) arg0) + 0x40)) = 0x80808080;
  *((s32 *) (((u8 *) arg0) + 0x44)) = 0x80808080;
  func_003EF640(arg0, 0x80F00000, 0x80F00000, 0x80F00000, 0x80F00000);
  *((s32 *) (((u8 *) arg0) + 0x50)) = 0;
  *((f32 *) (((u8 *) arg0) + 0x18)) = 0.5f;
  *((f32 *) (((u8 *) arg0) + 0x1C)) = 0.5f;
  func_003EF570(arg0, 0);
  new_var = &arg0;
  *((s8 *) (((u8 *) (*new_var)) + 0x4C)) = 0xA;
  *((s16 *) (((u8 *) (*new_var)) + 0x4A)) = 0;
  *((s32 *) (((u8 *) (*new_var)) + 0x34)) = 0;
  *((s8 *) (((u8 *) (*new_var)) + 0x4E)) = 0;
  *((s8 *) (((u8 *) (*new_var)) + 0x4D)) = 0;
  return *new_var;
}
/* localdecomp:end func_003EF4C8 */

/* localdecomp:start func_003EF570 */
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

void func_003EF570(S_003E9C50 *arg0, s32 arg1) {
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
/* localdecomp:end func_003EF570 */

/* localdecomp:start func_003EF608 */
extern s32 D_001D9760_g;
extern s32 func_003EDF60(s32, s32);
s32 func_003EF608(s32 p, s32 k) {
    if (k != D_001D9760_g) return func_003EDF60(p, k);
    return 1;
}
/* localdecomp:end func_003EF608 */

/* localdecomp:start func_003EF638 */
extern s32 D_001D9760_g;
s32 func_003EF638(void) {
    return D_001D9760_g;
}
/* localdecomp:end func_003EF638 */

/* localdecomp:start func_003EF640 */
void func_003EF640(void *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    *(s32 *)((u8 *)a0 + 0x38) = a1;
    *(s32 *)((u8 *)a0 + 0x3c) = a2;
    *(s32 *)((u8 *)a0 + 0x40) = a3;
    *(s32 *)((u8 *)a0 + 0x44) = a4;
}
/* localdecomp:end func_003EF640 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EF658);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EF698);

typedef struct { s32 f0; s32 *vt4; } OB_3EA078;
typedef struct { u8 p0[8]; s32 f8; s32 fC; } PP_3EA078;
typedef struct { u8 pad0[0x20]; f32 f20, f24; s32 f28; f32 f2C; u8 pad1[0x8]; s32 f38; u8 pad2[0x14]; OB_3EA078 *f50; } O_3EA078;
extern f32 D_001D9698;
extern f32 D_001D969C;
extern s32 func_003EDEB0();
extern unsigned long func_0039B088(s32);
extern void func_0038B500(s32, s32, s32, s32, s32, s32, s32, s32, f32, unsigned long, unsigned long);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EF998);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EFBB0);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031CC60);

typedef struct { u8 b[16]; } B16_3EA648;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3EA648;
extern s32 func_0011A264(void *, s32, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EFF68);

/* localdecomp:start func_003F01C8 */
s32 func_003F01C8(void *arg0, s32 arg1) {
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
/* localdecomp:end func_003F01C8 */

/* localdecomp:start func_003F0250 */
void func_003F0250(void *p, s32 v) {
    *((u8 *)p + 0x4C) = v;
    if ((u8)v == 0) {
        *((u8 *)p + 0x4C) = 1;
    }
}
/* localdecomp:end func_003F0250 */

/* localdecomp:start func_003F0270 */
extern char D_001D9670[];
extern s32 func_003F2738();
void func_003F0270(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D9670; if (f & 1) func_003F2738(p); }
/* localdecomp:end func_003F0270 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003F02A0);

/* localdecomp:start func_003F02C8 */
s32 func_003F02C8(void) {
    return 2;
}
/* localdecomp:end func_003F02C8 */

/* localdecomp:start func_003F02D0 */
extern void func_003EDD40(void);
extern u8 D_001D9798[];
void *func_003F02D0(void *arg0) {
    func_003EDD40();
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
/* localdecomp:end func_003F02D0 */

/* localdecomp:start func_003F0358 */
void func_003F0358(u8 *p, u8 m, s32 set) {
    if (set != 0) {
        p[0x44] |= m;
    } else {
        p[0x44] &= ~m;
    }
}
/* localdecomp:end func_003F0358 */

/* localdecomp:start func_003F0388 */
s32 func_003F0388(void *a0, s32 a1) {
    s32 b = a1 & 0xff;
    return (*(u8 *)((u8 *)a0 + 0x44) & b) != 0;
}
/* localdecomp:end func_003F0388 */

/* localdecomp:start func_003F03A0 */
void func_003F03A0(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x48) = x;
    *(f32 *)((u8 *)p + 0x4C) = y;
}
/* localdecomp:end func_003F03A0 */
