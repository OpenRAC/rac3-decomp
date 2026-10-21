#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void *func_003F2060();
extern void **func_003F25C0(void **);
typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
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
extern void func_003EF640();
typedef struct S_3E6CE8 S_3E6CE8;
typedef struct { u8 pad[0x10]; s32 (*fn)(S_3E6CE8 *, s32); } V_3E6CE8;
struct S_3E6CE8 { u8 pad[8]; V_3E6CE8 *vt; u8 p2[0x4A-0xC]; s16 h4A; };
extern s32 D_001D9760_003EC608;
extern void func_003EF570();
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
extern void func_003EF640(void *, s32, s32, s32, s32);
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
extern void func_003EE7C0(u8 *, f32, f32, f32, f32);
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
extern void func_003EE290();
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
extern s32 func_003E74D0();
typedef struct { s32 a[0x12]; s32 x48; } S_E8;
typedef struct { u8 p[0x2C]; S_E8 *x2C; } T_E8;
typedef struct { s32 *arr[16]; s32 x40, x44, x48, x4C, x50, x54; f32 x58, x5C; } O_3E89F0;
typedef struct { u8 p0[8]; void *f8; u8 p1[0x2C - 0xC]; O_3E89F0 *x2C; } T_3E89F0;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); } VT_3E89F0;
extern u8 D_001D9708[8];
void **func_003E7078(s32 *, s32);
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
extern void func_003EE290();
typedef struct { u8 b[16]; } B16_3E8C40;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3E8C40;
extern s32 func_0011A264(void *, s32, s32);
typedef struct O_3E8EC8 O_3E8EC8F;
typedef struct { u8 p0[0x20]; void (*f20)(O_3E8EC8F *, s32, f32 *, s32); } V_3E8EC8;
typedef struct { s32 *tbl[1]; } L_3E8EC8;
typedef struct { u8 p0[0x48]; s32 f48; } L2_3E8EC8;
typedef struct O_3E8EC8 { u8 p0[8]; V_3E8EC8 *f8; u8 pC[0x20]; struct { s32 *e[1]; u8 pad[0x44]; s32 n; } *f2C; } O_3E8EC8;
extern void func_003EE0A8();
extern s32 func_003EE548();
extern void func_003EE0F8(f32, f32, f32, f32);
extern void func_003EE038();
typedef struct { u8 b[16]; } B16_3E8FB0;
typedef struct { u8 p0[8]; s32 (**vt)(); } C_3E8FB0;
typedef struct { s32 *e[1]; u8 p0[0x40]; C_3E8FB0 *f44; s32 n; s32 p1; f32 f50, f54, f58, f5C; } S_3E8FB0;
typedef struct { u8 p0[0x2C]; S_3E8FB0 *f2C; } O_3E8FB0;
extern s32 func_003EDF90();
typedef struct { u8 b[16]; } B16_3E90C8;
typedef struct { s32 *e[1]; u8 p0[0x44]; s32 n; s32 p1; f32 f50, f54, f58, f5C; } S_3E90C8;
typedef struct { u8 p0[0x2C]; S_3E90C8 *f2C; } O_3E90C8;
extern void func_003EDFE8();
extern void func_003EDD40(void);
extern unsigned char D_001D9738[];
extern s32 D_001D9730_g;
extern s32 func_003EDF60(s32, s32);
extern s32 D_001D9730_g;
typedef struct { u8 b[16]; } B16_3E98B8;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3E98B8;
extern s32 func_0011A264(void *, s32, s32);
extern char D_001D9670[];
extern s32 func_003F2738();
extern void func_003EF570();
extern void func_003EF640(void *, s32, s32, s32, s32);
extern void func_003EDD40(void);
extern u8 D_001D9768[];
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
extern s32 D_001D9760_g;
extern s32 func_003EDF60(s32, s32);
extern s32 D_001D9760_g;
typedef struct { s32 f0; s32 *vt4; } OB_3EA078;
typedef struct { u8 p0[8]; s32 f8; s32 fC; } PP_3EA078;
typedef struct { u8 pad0[0x20]; f32 f20, f24; s32 f28; f32 f2C; u8 pad1[0x8]; s32 f38; u8 pad2[0x14]; OB_3EA078 *f50; } O_3EA078;
extern f32 D_001D9698;
extern f32 D_001D969C;
extern s32 func_003EDEB0();
extern unsigned long func_0039B088(s32);
extern void func_0038B500(s32, s32, s32, s32, s32, s32, s32, s32, f32, unsigned long, unsigned long);
typedef struct { u8 b[16]; } B16_3EA648;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3EA648;
extern s32 func_0011A264(void *, s32, s32);
extern char D_001D9670[];
extern s32 func_003F2738();
extern void func_003EDD40(void);
extern u8 D_001D9798[];
extern char D_001D9670[];
extern s32 func_003F2738();
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
extern S_3EB180 D_001DA938_003F0AC0[];
extern s32 *func_003E6FC0();
extern void *func_003EDD40_003F0AC0();
extern void **func_003E7078();
extern void func_003F0D38(void *, s32);
extern void func_003F0E78(u8 *, s32, f32, f32);
extern s32 func_003F0FA0(u8 *arg0, s32, s32);
extern void func_003F0E28(void *, f32);
extern void func_003F1090(void *, s32);
extern void func_003F0F28(u8 *p, s32 m, s32 on);
s32 *func_003E6FC0(s32 *);
void **func_003E7078(s32 *, s32);
void func_003F2738_003F0C98(void *);
extern u8 D_001D9670_003F0C98;
extern u8 D_001D97C8;
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003EB358;
extern S_001DA9B8_003EB358 D_001DA938[];
typedef struct { u8 pad[0x10]; s32 w10; u8 p2[0x48-0x14]; u16 h48; } Q_3EB440;
typedef struct { u8 pad[0x2C]; Q_3EB440 *q; u8 b30; u8 p3[3]; s32 w34; } S_3EB440;
extern void func_003F0D48();
void func_003F0F28_003F0FA0(void *, s32, s32);
extern void func_003EDF20(void *, f32, f32);
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
extern void func_0038E530(s32);
extern void func_003EE0A8(void *, f32 *);
extern void func_003F0F70(void *, s32 *, s32 *);
extern s32 func_003EDEB0(void *, s32);
extern void func_003915F0();
extern void func_003915D0();
extern void func_003910A8(void);
extern void func_00391088(void);
extern void func_003E7518(void);
extern long func_00389978(s32);
typedef struct { u8 b[16]; } B16_3EC3D0;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3EC3D0;
extern s32 func_0011A264(void *, s32, s32);

/* localdecomp:start func_003F1FB0 */
s32 func_003F1FB0(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))(*(u8 **)((u8 *)p + 0x2C) + 0x8);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003F1FB0 */

/* localdecomp:start func_003F1FE0 */
s32 func_003F1FE0(s32 p, s32 k) {
    if (k != 3) {
        return func_003EDF60(p, k);
    }
    return 1;
}
/* localdecomp:end func_003F1FE0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003F2010);

/* localdecomp:start func_003F2060 */
extern void func_003EDE88(void *, s32, s32);
extern void func_003EDD40(void);
extern u8 D_001D97F8[];
void *func_003F2060(void *arg0)
{
  func_003EDD40();
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
  func_003EDE88(arg0, 0x100, 1);
  return arg0;
}
/* localdecomp:end func_003F2060 */

/* localdecomp:start func_003F20E0 */
extern s32 D_001D97F0_g;
extern s32 func_003EDF60(s32, s32);
s32 func_003F20E0(s32 p, s32 k) {
    if (k != D_001D97F0_g) return func_003EDF60(p, k);
    return 1;
}
/* localdecomp:end func_003F20E0 */

/* localdecomp:start func_003F2110 */
extern s32 D_001D97F0_g;
s32 func_003F2110(void) {
    return D_001D97F0_g;
}
/* localdecomp:end func_003F2110 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003F2118);

/* localdecomp:start func_003F2158 */
typedef struct {
    void *vt0; void *vt4; s32 (**vt)(); u8 pad0[0x4]; f32 f10, f14, f18, f1C; u8 pad20[0x18]; s32 f38; f32 f3C; s32 f40; s32 f44;
} O_3EC7D8;
extern f32 D_001D9688[], D_001D968C[], D_001D9690_003F2158[], D_001D9694_003F2158[], D_001D9698_003F2158[], D_001D969C_003F2158[];
extern s32 func_003EDEB0();
extern void func_003EE0A8();
extern s32 func_003AC190();
extern void func_003AA6D8(void *, s32, f32, f32, f32, f32, f32);
void func_003F2158(O_3EC7D8 *o, s32 a) {
    f32 b[4];
    s32 p;
    f32 x, y;
    if (o->f44 == 0) return;
    o->vt[8](o, a, b, 1);
    if (func_003EDEB0(o, 0x100) != 0) {
        f32 x, y;
        f32 c;
        f32 d;
        f32 e;
        s32 fl;
        s32 k = o->f40;
        p = func_003AC190(o->f44, k);
        x = o->f10; y = o->f14; fl = o->f38; c = o->f18; d = o->f1C; e = o->f3C;
        if (p == 0) return;
        func_003AA6D8((void *)p, fl, (x + D_001D9690_003F2158[0]) * D_001D9698_003F2158[0], (y + D_001D9694_003F2158[0]) * D_001D969C_003F2158[0], c * D_001D9688[0], d * D_001D968C[0], e);
    } else {
        s32 k;
        f32 c;
        f32 d;
        f32 e;
        s32 fl;
        func_003EE0A8(o, b);
        x = b[0] + (b[2] - b[0]) * 0.5f;
        y = b[1] + (b[3] - b[1]) * 0.5f;
        k = o->f40;
        p = func_003AC190(o->f44, k);
        fl = o->f38; c = o->f18; d = o->f1C; e = o->f3C;
        if (p == 0) return;
        func_003AA6D8((void *)p, fl, (x + D_001D9690_003F2158[0]) * D_001D9698_003F2158[0], (y + D_001D9694_003F2158[0]) * D_001D969C_003F2158[0], c * D_001D9688[0], d * D_001D968C[0], e);
    }
}
/* localdecomp:end func_003F2158 */

typedef struct { u8 p0[0x10]; f32 f10; f32 f14; f32 f18; f32 f1C; u8 p1[0x1C]; f32 f3C; s32 f40; u8 *f44; } O_3EC960;
extern s32 func_003AC190(u8 *, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003F22E0);

/* localdecomp:start func_003F2500 */
s32 func_003F2500(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))((u8 *)p + 0x34);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003F2500 */

/* localdecomp:start func_003F2530 */
extern char D_001D9670[];
extern s32 func_003F2738();
void func_003F2530(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D9670; if (f & 1) func_003F2738(p); }
/* localdecomp:end func_003F2530 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003F2560);

/* localdecomp:start func_003F25A0 */
void func_003F25A0(s32 *p, s32 a, s32 b, s32 c) {
    p[1] = b;
    p[2] = c;
    p[3] = a;
    p[6] = 0;
    p[4] = 0;
    p[5] = 0;
}
/* localdecomp:end func_003F25A0 */

/* localdecomp:start func_003F25C0 */
extern u8 D_001D9840[];
void **func_003F25C0(void **p) { p[1] = 0; p[0] = D_001D9840; p[2] = 0; p[3] = 0; p[6] = 0; p[4] = 0; p[5] = 0; return p; }
/* localdecomp:end func_003F25C0 */
