#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 39A9A8.c's earlier functions (tools/port_from_us.py) */
extern void func_0038CF58(void *, s32, s32);
extern u8 D_0016C690[];
extern s32 D_001D600C;
typedef struct { u8 pad[0x34]; s32 arr[8]; } T_00395958;
extern T_00395958 D_0016C690_0039AB28;
typedef struct { s32 f0; s32 f4; } S_00395958;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } E_003959A8;
typedef struct { u8 pad[0x458C]; s32 g458C; E_003959A8 el[0x30]; } S_003959A8;
typedef struct { s32 w0; s32 w4; s32 w8; s32 wC; } L_003959A8;
typedef struct { s32 f0; s32 f4; u8 *f8; } A_003959A8;
extern S_003959A8 D_160C40_0039AB78;
extern void func_0039AB28();
extern void func_11F0A0();
extern s32 func_11F1E0();
extern s32 func_11F1C0();
extern s32 func_003A2A30();
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } E_00395AC8;
typedef struct { u8 pad[0x458C]; s32 g458C; E_00395AC8 el[0x30]; } S_00395AC8;
extern S_00395AC8 D_160C40_0039AC98;
typedef struct { u8 pad[0x34]; s32 f34[3]; } T_00395AC8;
extern T_00395AC8 D_16C690_0039AC98;
extern s32 D_001D6000_0039AC98;
extern u8 D_001D6004_0039AC98;
extern u8 D_001D6008_0039AC98;
extern s32 func_003A2A30();
extern void func_0039AB28();
extern void func_0039AB78();
typedef struct { s32 k; u8 pad[0x10]; } E_395BC0;
typedef struct { u8 pad[0x4590]; E_395BC0 e[0x30]; } S_395BC0;
typedef struct { u8 d[0xC800]; } B_395BC0;
typedef struct { u8 pad[0x34]; s32 f34[3]; B_395BC0 blk[1]; } S_395BC0b;
extern S_395BC0 D_160C40_0039AD90;
extern S_395BC0b D_16C690_0039AD90;
typedef struct { u8 pad[0x10]; s32 f10; u8 pad2[0xDC]; } E_395C48;
typedef struct { s32 id; s32 pad[4]; } F_395C48;
typedef struct { u8 pad[0x4590]; F_395C48 e[0x30]; } S_395C48;
typedef struct { u8 pad[0x34]; s32 v[3]; } T_395C48;
typedef struct { u8 pad[0x25F8]; s32 f25F8; u8 pad2[0x18]; s32 f2614; } A_395C48;
extern A_395C48 D_1A4BE0;
extern u8 D_001425C0[];
extern s32 D_00142674[];
extern s16 D_001CCFD4[];
extern E_395C48 D_001DAA40[];
extern S_395C48 D_160C40_0039AE18;
extern T_395C48 D_16C690_0039AE18;
extern s32 func_0039AFE8(s32);
typedef struct { s32 id; s32 pad[4]; } E_395E18;
typedef struct { u8 pad[0x4590]; E_395E18 e[0x30]; } S_395E18;
typedef struct { u8 pad[0x34]; s32 v[3]; } T_395E18;
extern S_395E18 D_160C40[];
extern T_395E18 D_16C690[];
typedef struct { u8 *data; u8 *clut; u8 pad8[0xC]; s32 f14; u8 pad18[0x34]; s32 tw; s32 th; u8 pad54[4]; } T_395EB8;
typedef struct { u8 *data; s16 f4; s16 f6; u8 *clut; u8 tw; u8 th; s16 fE; } E_395EB8;
extern s32 D_001D4BB0;
extern s32 D_001D9BFC;
extern E_395EB8 D_00225C00[];
typedef struct { u8 p0[8]; s32 f8; u8 pC[4]; s32 f10; u8 p14[0x10]; s32 f24; u8 p28[0x144]; s32 f16C; } S_395FF0;
extern S_395FF0 D_00142430_0039B1C0[];
extern u8 D_001D9FA8_0039B1C0;
extern s32 D_001D4CE8_g_00395FF0;
extern s32 D_001D4CE8_0039B1C0;
extern volatile s32 D_001D4CEC_0039B1C0;
extern s32 D_001D9FA4_g_00395FF0;
extern s32 D_001D9FA4;
extern void (*D_003322F8[])(void);
typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad1[0x150];
    s32 f164;
    s32 f168;
    u8 pad2[0x10];
    s32 f17c;
} S_142430;
extern S_142430 D_00142430;
extern s32 D_001D4CE8[];
typedef struct { 
    u8 pad[0x10]; 
    s32 f10; 
    u8 pad2[0x150]; 
    s32 f164; 
    s32 f168; 
    u8 pad3[0x10]; 
    s32 f17C; 
} S_142430x;
extern S_142430x D_142430;
extern s32 D_001D4CE8_g;
typedef struct { u8 p0[8]; s32 f8; u8 pC[4]; s32 f10; u8 p14[0x168]; s32 f17C; } S_142430_00396120;
extern S_142430_00396120 D_142430_0039B2F0;
extern s32 D_001D4CE8_00396122;
extern s32 D_001D4CEC_00396122;
extern s32 D_001D4CE8_0039B2F0;
extern s32 D_001D4CEC_0039B2F0;
extern s32 D_001D4CE8_0039B418;
extern s32 (*D_001D6300_0039B418)();
typedef struct { u8 pad0[0x16C]; s32 f16C; u8 pad170[0xC]; s32 f17C; } S_00142430_00396248_00396248;
extern S_00142430_00396248_00396248 D_00142430_0039B418[];
extern u8 D_001D4CEC_0039B468;
extern s32 D_001D4CE8_0039B468;
extern S_142430x D_142430;
extern s32 D_001D4CE8_g;
extern S_142430x D_142430;
extern s32 D_001D4CE8_g;
extern s32 D_00142430_0039B4E0[];
extern s32 D_001D4CE8_0039B4E0;
extern s32 D_001D4CEC_0039B4E0;
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, rest:17; } F_4CEC;
extern F_4CEC D_001D4CEC_f;
extern s32 D_00142438[];
extern u8 D_001D5BDD;
extern s32 D_001D4CE8_g;
extern s32 D_00142430_0039B598[];
extern s32 D_001D4CE8_0039B598;
extern s32 D_001D4CEC_0039B598;
extern u8 D_001D5BDC;
extern void func_0039C408(void);
extern S_142430x D_142430;
extern s32 D_001D4CE8_g;
typedef struct { u8 pad[0x15C]; s32 x15C; s32 x160; s32 x164; s32 x168; s32 x16C; } S_396488;
extern S_396488 D_00142430_0039B658[];
extern s32 D_001D4CEC_0039B658;
extern s32 D_001D4CE8_0039B658;
extern s32 D_00142438[];
extern s32 D_001D4CEC_0039B6B8;
extern s32 D_001D4CE8_0039B6B8;
typedef struct { u32 b0:11; u32 f11:1; u32 rest:20; } S_396538;
extern s32 D_00142430_0039B708[];
extern s32 D_001D4CE8_0039B708;
extern union { s32 i; S_396538 b; } D_001D4CEC_0039B708;
typedef struct { u8 p0[8]; s32 f8; s32 fC; u8 p10[8]; s16 h18; u8 p1A[6]; s32 f20; u8 p24[0x15C - 0x24]; s32 f15C; u8 p160[4]; s32 f164; u8 p168[4]; s32 f16C; } S_396590;
extern S_396590 D_00142430_0039B760[];
extern s32 D_001D4CE8_0039B760;
typedef struct { u8 pad0[0x10]; s32 x10; u8 pad[0x15C-0x14]; s32 x15C; s32 x160; s32 x164; s32 x168; s32 x16C; } S_396628;
extern S_396628 D_00142430_0039B7F8[];
extern s32 D_001D4CEC_0039B7F8;
extern s32 D_001D4CE8_0039B7F8;
typedef struct { u8 p0[8]; s32 f8; s32 fC; u8 p10[8]; s16 f18; u8 p1A[2]; s32 f1C; s32 f20; u8 p24[0x138]; s32 f15C; u8 p160[4]; s32 f164; u8 p168[4]; s32 f16C; } S_142430_00396680;
extern S_142430_00396680 D_142430_0039B850;
extern s32 D_001D4CEC_00396682;
extern s32 D_001D4CEC_0039B850;
extern s32 D_001D4CE8_0039B850;
extern void (*D_001D6304_0039B850)(void);
extern s32 D_001D62F0_0039B850;
extern s32 D_00142438[];
extern s32 D_001D4CE8_g;
extern s32 D_001D4CEC_g;
extern s32 D_00142438[];
extern s32 D_001D4CEC_0039B990;
extern s32 D_001D4CE8_0039B990;
extern u8 D_001D5BDC;
typedef struct { u8 pad[0x15C]; s32 x15C; s32 x160; s32 x164; s32 x168; s32 x16C; } S_396830;
extern S_396830 D_00142430_0039BA00[];
extern s32 D_001D4CEC_0039BA00;
extern s32 D_001D4CE8_0039BA00;
typedef struct { u8 pad[0x18]; s16 f18; u8 padA[0x12E]; s32 f148; u8 padB[0x10]; s32 f15C; u8 pad2[4]; s32 f164; u8 pad3[4]; s32 f16C; } S_396890;
extern S_396890 D_142430_0039BA60;
extern s32 D_001D4CEC_0039BA60;
extern s32 D_001D4CE8_0039BA60;
typedef struct { u8 pad[0x18]; u16 h18; u8 pad2[0x15C - 0x1A]; s32 x15C; s32 pad4; s32 x164; } S_3968F8;
extern S_3968F8 D_00142430_0039BAC8[];
extern void (*D_001D62F4_0039BAC8)(void);
extern u16 D_001D6308;
extern s32 D_001D4CE8_0039BAC8;
extern s32 D_001D4CEC_0039BAC8;
extern void func_0039C408(void);
typedef struct { u8 pad[0x18]; u16 h18; u8 pad2[0x148 - 0x1A]; s32 x148; u8 pad3[0x10]; s32 x15C; s32 pad4; s32 x164; } S_3969B8;
extern S_3969B8 D_00142430_0039BB88[];
extern void (*D_001D62FC)(void);
extern u16 D_001D6308;
extern s32 D_001D4CE8_0039BB88;
typedef struct { u8 pad[8]; s32 f8; u8 pad2[0x170]; s32 f17C; } S_142430_396A28;
extern S_142430_396A28 D_142430_0039BBF8;
extern s32 D_001D4CE8_0039BBF8;
extern s32 D_001D4CEC_0039BBF8;
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];
extern void (*D_001D6304)(void);
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];
extern s32 D_00142438[];
extern s32 D_001D4CE8_0039BD20;
extern void (*D_001D6300)(void);
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];
typedef struct { u8 pad[0x15C]; s32 f15C; u8 pad2[4]; s32 f164; u8 pad3[4]; s32 f16C; } S_396BC0;
extern S_396BC0 D_142430_0039BD90;
extern s32 D_001D4CEC_0039BD90;
extern s32 D_001D4CE8_0039BD90;
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];

/* localdecomp:start func_0039BE18 */
__asm__(".extern D_001D62F8, 4");
typedef struct { u8 pad0[0x24]; s32 f24; u8 pad28[0x15C - 0x28]; s32 f15C; s32 pad160; s32 f164; s32 pad168; s32 f16C; u8 pad170[0xC]; s32 f17C; } S_00396C48;
extern S_00396C48 D_00142430_0039BE18[];
extern void (*D_001D62F8)();
extern s32 D_001D4CE8_0039BE18;
extern s32 D_001D4CEC_0039BE18;
void func_0039BE18(void) {
    S_00396C48 *p = D_00142430_0039BE18;
    s32 v = D_001D4CEC_0039BE18 & ~2;
    D_001D4CEC_0039BE18 = v;
    if (p->f15C == 2) {
        if (p->f164 < 0) {
            if (p->f16C != 0 || p->f24 != 0) {
                p->f17C = 0;
                D_001D4CEC_0039BE18 = v | 0x440;
                D_001D4CE8_0039BE18 = 0x18;
            } else {
                p->f17C = 1;
                D_001D4CE8_0039BE18 = 1;
            }
            if (D_001D62F8 != 0) {
                D_001D62F8();
                D_001D62F8 = 0;
            }
        }
    }
}
/* localdecomp:end func_0039BE18 */

/* localdecomp:start func_0039BEB8 */
typedef struct { u8 p0[8]; s32 f8; u8 p1[4]; s32 f10; u8 p2[0x15C-0x14]; s32 f15C; u8 p3[4]; s32 f164; u8 p4[4]; s32 f16C; u8 p5[0x17C-0x170]; s32 f17C; } S_396CE8;
extern S_396CE8 D_142430_0039BEB8[];
extern s32 D_001D4CE8_0039BEB8;
extern s32 D_001D4CEC_0039BEB8;
#define P D_142430_0039BEB8[0]
void func_0039BEB8(void) {
    if (P.f15C != 2) return; if (P.f164 >= 0) return; if (P.f16C != 0 || (P.f8 == 2 && P.f10 != 0)) { P.f17C = 0; D_001D4CE8_0039BEB8 = 3; D_001D4CEC_0039BEB8 = (D_001D4CEC_0039BEB8 & 0x40) | 1; } else { P.f17C = 1; D_001D4CE8_0039BEB8 = 1; }
}
/* localdecomp:end func_0039BEB8 */

/* localdecomp:start func_0039BF40 */
typedef struct { u32 b0:5; u32 f5:1; u32 b6:7; u32 f13:1; u32 rest:18; } S_396D70;
extern s32 D_00142438[];
extern s32 D_001D4CE8_0039BF40;
extern union { s32 i; S_396D70 b; } D_001D4CEC_0039BF40;
void func_0039BF40(void) {
    if (D_00142438[0] != 2) { D_001D4CE8_0039BF40 = 4; return; }
    if (D_001D4CEC_0039BF40.i & 0x2020) {
        D_001D4CE8_0039BF40 = 7;
        D_001D4CEC_0039BF40.b.f5 = 0;
        D_001D4CEC_0039BF40.b.f13 = 0;
    }
}
/* localdecomp:end func_0039BF40 */

/* localdecomp:start func_0039BF98 */
typedef struct { char pad0[8]; s32 x8; } S_396DC8;
extern S_396DC8 D_00142430_0039BF98;
extern s32 D_001D4CE8_0039BF98;
extern s32 D_001D4CEC_0039BF98;
void func_0039BF98(void) {
    s32 v;
    if (D_00142430_0039BF98.x8 != 2) { D_001D4CE8_0039BF98 = 4; return; }
    if (D_001D4CEC_0039BF98 & 0x2020) {
        D_001D4CE8_0039BF98 = 0xE;
        D_001D4CEC_0039BF98 &= ~0x20;
        D_001D4CEC_0039BF98 &= ~0x2000;
    }
}
/* localdecomp:end func_0039BF98 */

/* localdecomp:start func_0039BFF0 */
extern s32 D_00142438[];
extern u32 D_001D4CEC_0039BFF0;
extern s32 D_001D4CE8_0039BFF0;
extern void func_0039C408(void);
void func_0039BFF0(void) {
    s32 v;
    if (D_00142438[0] != 2) {
        v = 4;
    } else {
        u32 f = D_001D4CEC_0039BFF0;
        if (f & 0x20) {
            func_0039C408();
            v = 0x12;
        } else if (f & 0x2000) {
            v = 0x1D;
        } else {
            return;
        }
    }
    D_001D4CE8_0039BFF0 = v;
}
/* localdecomp:end func_0039BFF0 */

/* localdecomp:start func_0039C050 */
typedef struct { u8 pad0[0x10]; s32 f10; u8 pad14[0x148 - 0x14]; s32 f148; } S_396E80;
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, rest:17; } F_4CEC_396E80;
extern S_396E80 D_00142430_0039C050[];
__asm__(".extern D_001D62FC_0039C050, 4");
__asm__(".extern D_001D6300_0039C050, 4");
__asm__(".extern D_001D62F4, 4");
__asm__(".extern D_001D62F8_0039C050, 4");
__asm__(".extern D_001D6304_0039C050, 4");
__asm__(".extern D_001D9FA0, 1");
extern s32 D_001D62FC_0039C050;
extern s32 D_001D6300_0039C050;
extern s32 D_001D62F4;
extern s32 D_001D62F8_0039C050;
extern s32 D_001D6304_0039C050;
extern s8 D_001D9FA0;
extern F_4CEC_396E80 D_001D4CEC_f_396E80;
extern s8 D_001D9FA8;
extern s32 func_0039C228_0039C050();
extern void func_0039C408(void);
s32 func_0039C050(s32 a, s32 b) {
    s32 r = func_0039C228_0039C050(a);
    if (r) {
        S_396E80 *p = D_00142430_0039C050;
        D_001D4CEC_f_396E80.b4 = 1;
        D_001D4CEC_f_396E80.b2 = 0;
        D_001D4CEC_f_396E80.b1 = 0;
        D_001D4CEC_f_396E80.b6 = 0;
        D_001D6304_0039C050 = b;
        p->f148 = 0;
        p->f10 = 0;
        D_001D62F4 = 0;
        D_001D62F8_0039C050 = 0;
        D_001D62FC_0039C050 = 0;
        D_001D6300_0039C050 = 0;
        D_001D9FA8 = 0;
        D_001D9FA0 = 0;
        func_0039C408();
    }
    return r;
}
/* localdecomp:end func_0039C050 */

/* localdecomp:start func_0039C0E8 */
__asm__(".extern D_001D62F4, 4");
__asm__(".extern D_001D62F8_0039C0E8, 4");
__asm__(".extern D_001D6308_0039C0E8, 4");
__asm__(".extern D_001D62FC_0039C0E8, 4");
__asm__(".extern D_001D6300_0039C0E8, 4");
__asm__(".extern D_001D6304_0039C0E8, 4");
__asm__(".extern D_001D9FA0, 1");
typedef struct { u8 pad[0x10]; s32 x10; u8 padA[0x134]; s32 x148; } S_a;
extern void func_0039C408(void);
extern s32 D_001D62F4;
extern s32 D_001D62F8_0039C0E8;
extern s32 D_001D6308_0039C0E8;
extern s32 D_001D62FC_0039C0E8;
extern s32 D_001D6300_0039C0E8;
extern s32 D_001D6304_0039C0E8;
extern s8 D_001D9FA0;
extern s32 D_001D4CEC_0039C0E8;
extern s8 D_001D9FA8;
extern S_a D_00142430_0039C0E8[];
void func_0039C0E8(s32 arg0, s32 arg1, s32 arg2) {
    S_a *p = D_00142430_0039C0E8;
    s32 x;
    D_001D62F4 = arg0;
    D_001D62F8_0039C0E8 = arg2;
    D_001D6308_0039C0E8 = arg1;
    p->x148 = 0;
    D_001D62FC_0039C0E8 = 0;
    D_001D6300_0039C0E8 = 0;
    D_001D6304_0039C0E8 = 0;
    D_001D9FA8 = 0;
    D_001D9FA0 = 0;
    func_0039C408();
    p->x10 = 0;
    D_001D4CEC_0039C0E8 &= ~4; D_001D4CEC_0039C0E8 |= 2; D_001D4CEC_0039C0E8 &= ~0x40; D_001D4CEC_0039C0E8 &= ~0x10; D_001D4CEC_0039C0E8 &= ~0x4000;
}
/* localdecomp:end func_0039C0E8 */

extern s32 D_001D4CEC_g;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0039C170);

/* localdecomp:start func_0039C1A0 */
typedef struct { u8 pad0[0x10]; s32 f10; u8 pad14[0x148 - 0x14]; s32 f148; } S_396FD0;
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, rest:17; } F_4CEC_396FD0;
extern S_396FD0 D_00142430_0039C1A0[];
__asm__(".extern D_001D62FC_0039C1A0, 4");
__asm__(".extern D_001D6300_0039C1A0, 4");
__asm__(".extern D_001D6308_0039C1A0, 4");
__asm__(".extern D_001D62F4, 4");
__asm__(".extern D_001D62F8_0039C1A0, 4");
__asm__(".extern D_001D6304_0039C1A0, 4");
__asm__(".extern D_001D9FA8, 1");
extern s32 D_001D62FC_0039C1A0;
extern s32 D_001D6300_0039C1A0;
extern s32 D_001D6308_0039C1A0;
extern s32 D_001D62F4;
extern s32 D_001D62F8_0039C1A0;
extern s32 D_001D6304_0039C1A0;
extern s8 D_001D9FA8;
extern F_4CEC_396FD0 D_001D4CEC_f_396FD0;
extern s8 D_001D9FA0;
extern void func_0039C408(void);
void func_0039C1A0(s32 a, s32 b, s32 c) {
    S_396FD0 *p = D_00142430_0039C1A0;
    D_001D62FC_0039C1A0 = a;
    D_001D6300_0039C1A0 = c;
    p->f148 = 0;
    p->f10 = 0;
    D_001D6308_0039C1A0 = b;
    D_001D62F4 = 0;
    D_001D62F8_0039C1A0 = 0;
    D_001D6304_0039C1A0 = 0;
    D_001D9FA8 = 0;
    func_0039C408();
    D_001D9FA0 = 1;
    D_001D4CEC_f_396FD0.b2 = 1;
    D_001D4CEC_f_396FD0.b1 = 0;
    D_001D4CEC_f_396FD0.b6 = 0;
    D_001D4CEC_f_396FD0.b4 = 0;
    D_001D4CEC_f_396FD0.b14 = 0;
}
/* localdecomp:end func_0039C1A0 */

/* localdecomp:start func_0039C228 */
/* func_0039C228 (boot_elf), PAL.
   The only change from the US draft is the `.extern` size hint below: retail stores the
   argument through $gp (sw $4, -0x65C0($gp)), and with @ps2as the file is assembled by
   SN's Ps2EeAs, which reaches a global through $gp only when it knows the global's size
   (the same idiom the neighbouring blocks of src/boot_elf/text/39BE18.c use for
   D_001D62F4, D_001D62F8, D_001D6300, ...). Without the hint the store is
   lui $at, 0x1d / sw $a0, 0x62f0($at) (hi/lo), which is one instruction too many and
   shifts the branch offset. It declares a size; it generates no code. */

extern s32 D_001D4CEC_g;
extern s32 D_001D62F0;
__asm__(".extern D_001D62F0, 4");
s32 func_0039C228(u32 a) {
    if (a >= 4) return 0;
    D_001D62F0 = a;
    D_001D4CEC_g |= 0x1000;
    return 1;
}
/* localdecomp:end func_0039C228 */

extern s32 D_001D4CEC[];
extern s32 D_00142578[];

/* localdecomp:start func_0039C250 */
extern s32 D_001D4CEC_0039C250;
extern s32 D_00142578[];
void func_0039C250(void) {
    D_00142578[0] = 0;
    D_001D4CEC_0039C250 |= 0x800;
}
/* localdecomp:end func_0039C250 */

/* localdecomp:start func_0039C270 */
extern s32 D_001D4CEC_0039C270;
void func_0039C270(void) {
    D_001D4CEC_0039C270 |= 0x2000;
}
/* localdecomp:end func_0039C270 */
