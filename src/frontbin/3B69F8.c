#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_003A2750(s32);
extern void func_0038E150(s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003A2750();
extern s32 func_003B7F80(void);
extern s32 func_003E85A8();
extern s32 func_003E7A18(s32, s32);
extern s32 func_003B97B0(void);
extern s32 func_003B96D0(void);
extern s32 func_003B9700();
extern void func_003B96D8();
extern void func_003B9890(void);
extern s32 func_00381D40(void);
extern void func_003B98A0();
extern s32 func_003E7A18(s32 arg0, s32 arg1);
extern void func_003B8A38(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B69F8 */
extern void func_00392F60(s32);
extern void func_0039E5E0(s32);
extern void func_003BB1F0(s32);
extern s32 func_003BB3A8(s32);
extern s32 D_001D8AA0;
extern s32 D_001D8A9C;
extern s32 D_001D8AAC;
extern s32 D_001D8AB0;
extern s32 D_001D8AA4;
extern s32 D_001D8AA8;
extern u8 D_001D5BDC[];
extern u8 D_001D5BDC_003B69F8[];
void func_003B69F8(void) {
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_3;
    s32 temp_3_2;

    if (D_001D5BDC[0] != 0) {
        func_003BB1F0(0);
    }
    temp_2 = func_003BB3A8(1);
    D_001D8AA0 = temp_2;
    D_001D8A9C = (s32) ((temp_2 + 0xF) & 0xFFFFFFF0);
    if (D_001D5BDC_003B69F8[0] == 0) {
        temp_2_2 = func_003BB3A8(1);
        D_001D8AAC = temp_2_2;
        temp_3 = (temp_2_2 + 0xF) & 0xFFFFFFF0;
        D_001D8AB0 = temp_3;
        func_00392F60(temp_3);
        temp_2_3 = func_003BB3A8(1);
        D_001D8AA4 = temp_2_3;
        temp_3_2 = (temp_2_3 + 0xF) & 0xFFFFFFF0;
        D_001D8AA8 = temp_3_2;
        func_0039E5E0(temp_3_2);
    }
}
/* localdecomp:end func_003B69F8 */

/* localdecomp:start func_003B6A98 */
extern void func_003A5348(s32, s32, s32);
 
void func_003B6A98(void) {
    func_003A5348(5, 0, 0);
}
/* localdecomp:end func_003B6A98 */

typedef struct { u8 on; u8 pad[7]; } F;
typedef struct { void (*fn)(); s32 pad; } T;
extern s32 D_001D8A18_003B6AC0;
extern F D_001D8A48_003B6AC0[1];
extern T D_001D8A4C[1];
typedef struct { s32 a[7]; } R;
extern R D_142430[];
extern void func_003B6848();
extern void func_003B6910();
extern void func_003B6970();
extern void func_003B69B0();
INCLUDE_ASM("asm/nonmatchings/text", func_003B6AC0);

extern f32 D_001D8A68;
extern f32 D_001D8A6C;
extern f32 D_001D8A70;
extern f32 D_001D8A74;
extern f32 D_001D8A78;
extern f32 D_001D8A7C;
extern f32 D_001D8A80;
extern f32 D_001D8A84;
extern f32 D_001D8A88;
extern f32 D_001D8A8C;
extern f32 D_001D8A90;
extern f32 D_001D8A94;
extern f32 D_001D8A98;
extern f32 D_001D8AD0;
extern f32 D_001D8AD4;
extern f32 D_001D8AD8;
extern f32 D_001D8ADC;
extern f32 D_001D8AE0;
extern s32 D_001D8AC0[2];
extern void func_003BB180(void);
extern void func_003E9450();
extern s32 func_003BB118(u32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_003E7AC8(s32, s32);
extern s32 func_003E7928(s32, s32, s32);
extern s32 func_003E9138_003B6B90(s32, s32, f32, f32, f32, f32, s32);
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E7E48(s32, s32);
extern s32 func_003E8C68(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E8A58(s32, s32, s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8710(s32, s32);
extern s32 func_003E8348(s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003B6B90);

extern s32 D_001D8A18_003B7288;
extern s32 func_00381FF0();
extern s32 func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003B7288);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7390);

typedef struct { u8 p0[0x4954]; s32 f4954; u8 p4958[0x7080 - 0x4958]; u8 f7080[4]; } S_B22C0;
extern s32 D_001D8A20[2];
extern s32 D_001D8A30[2];
extern s32 D_001D8B38[2];
extern u8 D_001D5BDC_003B77A0;
extern S_B22C0 D_00160C40_003B77A0[];
extern s32 D_001D8A40;
extern s32 func_003BB3A8(s32);
extern void *func_003B5048(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
extern void *func_003B42F8(s32);
extern void func_003B7288(void);
extern void func_003B6B90(void);
extern void func_003B6AC0();
INCLUDE_ASM("asm/nonmatchings/text", func_003B77A0);

typedef struct { u8 p[0x1C4]; u32 f1C4; } P_3B23F8;
typedef struct { u8 on; u8 pad[7]; } F_3B23F8;
typedef struct { void (*fn)(); s32 pad; } T_3B23F8;
extern P_3B23F8 *D_001D52FC_003B78D8;
extern F_3B23F8 D_001D8A48_003B78D8[1];
extern T_3B23F8 D_001D8A4C_003B78D8[1];
extern s32 D_001D8AB4;
extern u8 D_001D5BDC_003B78D8;
extern u8 D_001D5BDD;
extern s32 func_003B4FD0_003B78D8(void);
extern s32 func_00381D08(s32);
extern s32 func_003B5028(void);
extern s32 func_00381CC0_003B78D8(void);
extern void func_003E83C8_003B78D8(s32);
extern void func_003E6FF8_003B78D8(s32);
extern s32 func_003E73B8(s32, f32, f32);
extern void func_003BB5D0();
extern void func_003BB590(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003B78D8);

/* localdecomp:start func_003B7B20 */
extern void func_003B6888(void);
extern void func_003B68B0(void);
extern void func_003B68E0(void);
extern s32 D_001D8A18;
extern s8 D_001D9FA0;
extern s32 D_001D8A40;
extern s32 D_001D4CE8[];
void func_003B7B20(void) {
    s32 t5 = D_001D8A18;
    s32 t4 = D_001D4CE8[0];
    D_001D9FA0 = (t5 == 1);
    if (t4 == 0xB || ((u32)(t4 - 6) < 2U && t5 == 1)) {
        func_003B6888();
    } else if ((u32)(t4 - 6) < 2U) {
        func_003B68B0();
    } else if (t4 == 0xE && t5 != 1 && (t5 == 0 || t5 == 3)) {
        func_003B68E0();
    }
    D_001D8A40 = 2;
}
/* localdecomp:end func_003B7B20 */

/* localdecomp:start func_003B7BC8 */
extern void func_003B6AC0(s32);
extern void func_003B7390(void);
extern void func_003B78D8(s32);
void func_003B7BC8(s32 a) {
    func_003B6AC0(a);
    func_003B7390();
    func_003B78D8(a);
}
/* localdecomp:end func_003B7BC8 */

/* localdecomp:start func_003B7C00 */
extern s32 D_001D8A40;
extern s32 D_001D4CE8[];
void func_003B7C00(void) {
    s32 temp_3;

    if (D_001D8A40 == 0) {
        temp_3 = D_001D4CE8[0];
        switch (temp_3) {                           /* irregular */
        case 18:
            /* fallthrough */
        case 1:
            func_003E7A18(0x4C003C, 1);
            func_003E7A18(0xD000B, 1);
            return;
        default:
            func_003E7A18(0x4C003C, 0);
            func_003E7A18(0xD000B, 0);
            D_001D8A40 = 1;
            break;
        }
    }
}
/* localdecomp:end func_003B7C00 */

extern s32 D_001D8A40;
extern u8 D_001D8AB8;
extern s32 D_001D4CE8_003B7C88;
extern void func_003B7B20_003B7C88();
extern void func_003B8430(void);
extern void func_003820B0(void);
extern s32 D_001D5B74;
extern u8 D_001D5BDC_003B7C88;
extern u8 D_001D5BDD;
extern void func_003820B8(void);
extern void *func_003B4FD0();
extern void *func_003B5028_003B7C88();
extern s32 *func_00381CC0();
extern s32 func_00381D08_003B7C88();
extern s32 func_003BB100(s32);
extern void func_00392DF0(s32, s32);
extern s32 func_003E83C8();
extern void func_003E6FF8(void *);
extern s32 func_003BB0C0(void);
extern void func_003BB0C8(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003B7C88);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C7E0);

/* localdecomp:start func_003B7E38 */
typedef struct { s32 p0; void *vt; } O_B2958;
extern s32 D_001D8AA0;
extern s32 D_001D8AA4;
extern s32 D_001D8AAC;
extern s32 D_001D8B38[2];
extern u8 D_001D5BDC[];
void func_003B7E38(void) {
    s32 i;
    s32 j;
    s32 *p;
    O_B2958 *o;
    func_003E85A8(0x10);
    func_003E85A8(0x11);
    for (i = 0; i < 4; i++) {
        o = (O_B2958 *)func_003B42F8(i);
        (*(void (**)(O_B2958 *))((u8 *)o->vt + 0xC))(o);
    }
    func_003A2750(1);
    func_003BB468(D_001D8AA0);
    for (j = 0; j < 4; j++) {
        func_003BB468(D_001D8B38[j]);
    }
    if (D_001D5BDC[0] == 0) {
        func_003BB468(D_001D8AAC);
        func_003BB468(D_001D8AA4);
    }
    func_0038E150(0);
    func_00392F60(0);
}
/* localdecomp:end func_003B7E38 */

/* localdecomp:start func_003B7F08 */
extern u8 D_001D5BDC[];

void func_003B7F08(void) {
    if (D_001D5BDC[0] == 0) {
        func_00381D38();
    }
}
/* localdecomp:end func_003B7F08 */

/* localdecomp:start func_003B7F30 */
extern u8 D_001D5BDC[];
extern s32 D_001D8A40_g;
extern void func_0038AE20(s32, s32, s32, s32);
extern void func_003B7FD8(void);
void func_003B7F30(void) {
    if (D_001D5BDC[0] == 0) func_00381D40();
    if (D_001D8A40_g != 0) {
        func_0038AE20(0, 0, 0, 0x30);
        func_003B7FD8();
    }
}
/* localdecomp:end func_003B7F30 */

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001DA1A0;
extern s32 D_001DA188[2];
extern void func_003B77A0();
extern void func_003B7C88();
INCLUDE_ASM("asm/nonmatchings/text", func_003B7F80);

typedef struct {
    s16 f0;
    u16 f2;
    s16 f4, f6, f8, fA, fC, fE;
    s16 f10;
    u16 f12;
    s16 f14, f16, f18, f1A;
} T_3B2AF8;
extern s32 D_001D4CE8_003B7FD8;
extern u8 D_001D9FA0_003B7FD8;
extern u8 D_001D5BDC_003B7FD8;
extern u8 D_001D5BDD;
extern u16 D_001D4BC4;
extern char D_001D8B48[];
extern char D_001D8B50[];
extern char D_00280AF0[];
extern char *func_00382088(s32);
extern s32 func_0011A264(void *, s32, s32);
extern void func_003AF408(void *, u32, void *, s32, s32, s32, s32, void *, void *, s32);
extern void func_11B2E8();
INCLUDE_ASM("asm/nonmatchings/text", func_003B7FD8);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C800);

typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, rest:21; } F_003B2F50;
typedef struct { u8 pad[0x1A4]; s32 f1A4; } P_003B2F50;
extern F_003B2F50 D_001D4CEC;
extern u8 D_001D9FA0_003B8430;
extern s32 D_001D8AA8;
extern u8 D_001D5BDC_003B8430;
extern s32 D_001D4CE8_003B8430;
extern P_003B2F50 *D_001D52FC_003B8430;
extern u8 D_001D5BDD;
extern void func_0039BFD8(void);
extern void func_0039BFF0(void);
extern void func_0039BE90(void);
extern void func_0039C220(s32);
extern void func_003C0CC0(void);
extern u8 func_0039BEA8(void);
extern void func_0039C060(void);
extern s32 func_0039BC70(s32, s32);
extern void func_003A8F50(void);
extern void func_003B6510();
extern s32 D_00142438[];
INCLUDE_ASM("asm/nonmatchings/text", func_003B8430);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C880);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8A38);

extern f32 D_001D8BA0, D_001D8BA4, D_001D8BA8, D_001D8BAC, D_001D8BB0, D_001D8BB4;
extern f32 D_001D8B60[2];
extern f32 D_001D8B64[];
extern f32 D_001D8B68[];
extern f32 D_001D8B6C[];
extern void func_003BAF90(s32, void *, void *);
extern s32 func_003B5060(s32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8B98(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E7E48(s32, s32);
extern s32 func_003E8348(s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003B9298);

/* localdecomp:start func_003B96C8 */
extern s32 D_001D8BC0;
void func_003B96C8(void) {
    D_001D8BC0 = 0;
}
/* localdecomp:end func_003B96C8 */

/* localdecomp:start func_003B96D0 */
extern s32 D_001D8BC0;
s32 func_003B96D0(void) {
    return D_001D8BC0;
}
/* localdecomp:end func_003B96D0 */

/* localdecomp:start func_003B96D8 */
extern s32 D_001D8BD4;
extern s32 D_001D8BD8;
void func_003B96D8(s32 a0, s32 a1) {
    D_001D8BD4 = 0x40;
    D_001D8BD8 = 0x10;
    if (a0 != 0xFFFF) {
        D_001D8BD4 = a0;
    }
    D_001D8BD8 = a1;
}
/* localdecomp:end func_003B96D8 */

/* localdecomp:start func_003B9700 */
extern void func_003B96C8(void);
extern void func_003B96D8(s32, s32);
extern void func_003B97A0(s32, s32);
extern s32 D_001D8BBC;
extern s32 D_001D8BB8;
extern s32 D_001D8BC4;
extern s32 D_001D8BC8;
extern s32 D_001D8BCC;
extern s8 D_001D8BD0;
s32 func_003B9700(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (D_001D8BBC != 1) {
        return 0;
    }
        D_001D8BBC = 0;
        func_003B96C8();
        D_001D8BB8 = arg0;
        D_001D8BC4 = arg1;
        D_001D8BC8 = arg2;
        D_001D8BCC = arg3;
        D_001D8BD0 = arg4;
        func_003B97A0(0x60, 0x1A0);
        func_003B96D8(0xFFFF, 0xFFFF);
    return 1;
}
/* localdecomp:end func_003B9700 */

extern s32 D_001D8BDC;
extern s32 D_001D8BE0;
/* localdecomp:start func_003B97A0 */
extern s32 D_001D8BDC;
extern s32 D_001D8BE0;
void func_003B97A0(s32 a, s32 b) { D_001D8BDC = a; D_001D8BE0 = b; }
/* localdecomp:end func_003B97A0 */

/* localdecomp:start func_003B97B0 */
extern void func_003820B0(void);
extern void func_003A5348(s32, s32, s32);
extern s32 D_001D8BBC;
extern s32 D_001D8BB8;
extern void * D_001D52FC;
extern void *D_001D52FC_003B97B0[];
extern s32 D_001D8BD4;
extern s32 D_001D8BC0;
extern s32 D_001D8BD8;
s32 func_003B97B0(void) {
    s32 t;
    s32 m;
    if (D_001D8BBC == 1) {
        return 0;
    }
    func_003820B0();
    t = D_001D8BB8;
    switch (t) {
    case 0:
        m = *(s32 *)((u8 *)D_001D52FC + 0x1C4);
        if (m & D_001D8BD4) {
            D_001D8BC0 = 1;
            D_001D8BBC = 1;
            func_003A5348(4, 0, 0);
        } else if (m & D_001D8BD8) {
            D_001D8BBC = 1;
            D_001D8BC0 = 2;
            func_003A5348(4, 0, 0);
        }
        break;
    case 1:
        if (*(s32 *)((u8 *)D_001D52FC_003B97B0[0] + 0x1C4) & D_001D8BD4) {
            D_001D8BC0 = t;
            func_003A5348(0x12, 0, 0);
            D_001D8BBC = t;
        }
        break;
    }
    return 1;
}
/* localdecomp:end func_003B97B0 */

/* localdecomp:start func_003B9890 */
extern s32 D_001D8BC0;
extern s32 D_001D8BBC;
void func_003B9890(void) {
    D_001D8BC0 = 0;
    D_001D8BBC = 1;
}
/* localdecomp:end func_003B9890 */

extern void func_0038E150(s32);
extern s32 func_00381FF0(s32);
extern void func_003910C0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_003AF408(void *, u32, void *, s32, s32, s32, s32, void *, void *, s32);
extern s32 D_001D8BBC;
extern s32 D_001D8BB8;
extern s32 D_001D8BC4;
extern s32 D_001D8BC8;
extern s32 D_001D8BCC;
extern s8 D_001D8BD0;
extern s32 D_001D8BDC;
extern s32 D_001D8BE0;
extern f32 D_001DA074;
extern s32 D_001DA070;
INCLUDE_ASM("asm/nonmatchings/text", func_003B98A0);

typedef struct { u8 p0[0x20]; s32 x[4]; s32 y[4]; s32 z[4]; } O_B45B0;
extern void func_003BABB0(s32 *arg0, float float1, float float2, float float3, float float4, float float5);
extern void func_003BABD0(void *, f32, f32, f32, f32);
extern void func_003BA4E0(void *, s32, f32, f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003B9A90);
