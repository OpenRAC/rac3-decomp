#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_0039C7F0(void);
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
typedef struct { u8 pad0[0x24]; s32 f24; u8 pad28[0x15C - 0x28]; s32 f15C; s32 pad160; s32 f164; s32 pad168; s32 f16C; u8 pad170[0xC]; s32 f17C; } S_00396C48;
extern S_00396C48 D_00142430_0039BE18[];
extern void (*D_001D62F8)();
extern s32 D_001D4CE8_0039BE18;
extern s32 D_001D4CEC_0039BE18;
typedef struct { u8 p0[8]; s32 f8; u8 p1[4]; s32 f10; u8 p2[0x15C-0x14]; s32 f15C; u8 p3[4]; s32 f164; u8 p4[4]; s32 f16C; u8 p5[0x17C-0x170]; s32 f17C; } S_396CE8;
extern S_396CE8 D_142430_0039BEB8[];
extern s32 D_001D4CE8_0039BEB8;
extern s32 D_001D4CEC_0039BEB8;
#define P D_142430_0039BEB8[0]
typedef struct { u32 b0:5; u32 f5:1; u32 b6:7; u32 f13:1; u32 rest:18; } S_396D70;
extern s32 D_00142438[];
extern s32 D_001D4CE8_0039BF40;
extern union { s32 i; S_396D70 b; } D_001D4CEC_0039BF40;
typedef struct { char pad0[8]; s32 x8; } S_396DC8;
extern S_396DC8 D_00142430_0039BF98;
extern s32 D_001D4CE8_0039BF98;
extern s32 D_001D4CEC_0039BF98;
extern s32 D_00142438[];
extern u32 D_001D4CEC_0039BFF0;
extern s32 D_001D4CE8_0039BFF0;
extern void func_0039C408(void);
typedef struct { u8 pad0[0x10]; s32 f10; u8 pad14[0x148 - 0x14]; s32 f148; } S_396E80;
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, rest:17; } F_4CEC_396E80;
extern S_396E80 D_00142430_0039C050[];
extern s32 D_001D62FC_0039C050;
extern s32 D_001D6300_0039C050;
extern s32 D_001D62F4;
extern s32 D_001D62F8_0039C050;
extern s32 D_001D6304_0039C050;
extern s8 D_001D9FA0;
extern F_4CEC_396E80 D_001D4CEC_f_396E80;
extern s8 D_001D9FA8;
extern s32 func_0039C228();
extern void func_0039C408(void);
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
extern void func_0039C0E8();
extern s32 D_001D4CEC_g;
typedef struct { u8 pad0[0x10]; s32 f10; u8 pad14[0x148 - 0x14]; s32 f148; } S_396FD0;
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, rest:17; } F_4CEC_396FD0;
extern S_396FD0 D_00142430_0039C1A0[];
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
extern s32 D_001D4CEC_g;
extern s32 D_001D62F0;
extern s32 D_001D4CEC[];
extern s32 D_00142578[];
extern s32 D_001D4CEC_0039C250;
extern s32 D_00142578[];
extern s32 D_001D4CEC_0039C270;
extern u8 D_001D9FA8_g;
extern S_142430 D_00142430;
typedef struct { u8 pad[0x18]; u16 h18; u8 pad2[0x148 - 0x1A]; s32 f148; u8 p14C[0x18]; s32 f164; s32 f168; u8 p16C[8]; s32 f174; } S_00397100;
extern S_00397100 D_00142430_0039C2D0[];
extern u16 D_001D6308;
extern s32 D_001D545C_0039C2D0;
extern s32 D_001D4BE0_0039C2D0;
extern u8 D_001A9318_0039C2D0[];
extern void func_12BE28();
extern void func_13AD58();
extern void func_0039FE68();
extern void func_0039E9C0();
extern F_4CEC D_001D4CEC_f;
extern F_4CEC D_001D4CEC_f;
extern F_4CEC D_001D4CEC_f;
extern s32 D_001D4CEC[];
extern F_4CEC D_001D4CEC_f;
extern char D_001D5360[];
extern char D_001D5378[], D_001D5390[], D_001D53A8[], D_001D53C8[], D_001D53E8[];
extern char D_001D5418[], D_001D5438[];
extern void func_0011BB58(char *, void *, s32);
extern u8 D_00332388[];
extern u8 D_00332618[];
extern s32 func_0039EA88();
extern s32 func_0039ED78();
extern void func_0039F2B8();
typedef struct { u8 pad[0x64C]; s32 f64C; u8 p650[0x10]; s32 f660; s32 f664; } S_160C40_00397380;
typedef struct { u8 pad[0x18]; s16 f18; u8 p1A[0x162]; s32 f17C; } S_142430_00397380;
typedef struct { u8 pad[0x18]; s32 f18; u8 p1C[0x14]; s32 f30; } S_16C580_00397380;
extern S_160C40_00397380 D_160C40_0039C6E0;
extern S_142430_00397380 D_142430_0039C6E0;
extern S_16C580_00397380 D_16C580_0039C6E0;
extern u8 D_00143950_0039C6E0[];
extern s32 D_001D545C_0039C6E0;
extern s32 D_001D4B60_0039C6E0, D_001D4CEC_0039C6E0, D_001D4B90_0039C6E0, D_001D4BA0_0039C6E0;
extern void func_003932E8();
extern s32 func_003A2B50();
extern s32 func_003A2AF0();
extern void func_0038D068();
extern void func_0039C600();

/* localdecomp:start func_0039C7F0 */
typedef struct {
    s32 port;  s32 slot;  s32 type;  s32 free;
    s32 f10;   s32 f14;   s16 f18;   s16 f1A;   s32 f1C;
    s32 f20;   s32 f24;   s32 f28;   s32 f2C;   s32 f30;
    u8 p34[0x18]; s32 f4C; u8 p50[0x18]; s32 f68; u8 p6C[0x18]; s32 f84; u8 p88[0x18];
} MC_397490;
typedef struct {
    MC_397490 c[2];
    s32 f140, f144, f148, f14C, f150, f154, f158, f15C, f160, f164, f168, f16C, f170, f174, f178, f17C, f180, f184, f188;
} S_397490;
typedef struct { u8 p0[0x10]; s32 size; u8 p14[0xC]; u8 name[0x20]; } DE_397490;
typedef struct { s32 type; s32 size; u8 d[0x40]; } E_397490;
typedef struct { u8 p0[0x48]; s32 f48; } S_142660_397490;
extern S_397490 D_142430_0039C7F0;
extern S_142660_397490 D_142660;
extern DE_397490 D_0022CCC0[];
extern u8 D_0022CCE0[];
extern char D_001D5378[], D_001D5390[], D_001D53A8[], D_001D53BD[], D_001D53C8[], D_001D53DD[], D_001D53E8[];
extern char D_001D53FD[], D_001D5418[], D_001D542D[], D_001D5438[];
extern u32 D_001D545C;
extern char D_001D6348[], D_001D6350[], D_001D6358[], D_001D6360[], D_001D6380[], D_001D63A0[];
extern char D_001D63C0[], D_001D63E0[], D_001D6400[], D_001D6420[];
__asm__(".extern D_001D6318, 4");
extern s32 D_001D6318;
extern s16 D_001CCFD4[];
extern u8 D_001C5BD0[], D_001C5BD8[], D_001CBBD0[];
extern s32 func_12E2E0(s32, s32 *, s32 *);
extern s32 func_12E400(s32, s32, s32 *, s32 *, s32 *);
extern s32 func_12E6D8(s32, s32);
extern s32 func_12E8D8(s32, s32);
extern s32 func_12E580(s32, s32, char *, s32, s32, void *);
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_11B610(u8 *, char *);
extern s32 func_11B9A0(u8 *, char *, s32);
extern void func_11B754();
extern s32 func_11B2E8();
extern s32 func_12DCA0(s32, s32, char *, s32);
extern s32 func_12E050(s32, void *, s32);
extern s32 func_12E168(s32, void *, s32);
extern s32 func_12DE00(s32);
extern s32 func_12DDC8(s32, s32, char *);
extern s32 func_12E7A8(s32, s32, char *);
extern s32 func_12DEC0(s32, s32, s32);
extern s32 func_003A2998(s32, s32, s32);
extern s32 func_0039EBA8();
extern s32 func_0039EB68();
extern void func_0039ECC0();

void func_0039C7F0(void) {
    s32 found[4];
    char path[0x40];
    s32 t;

    if (D_142430_0039C7F0.f154 != 0) {
        D_142430_0039C7F0.f154 = func_12E2E0(1, &D_142430_0039C7F0.f140, &D_142430_0039C7F0.f144) == 0;
        return;
    }
    D_142430_0039C7F0.f154 = 1;
    switch (D_142430_0039C7F0.f15C) {
    case 0:
        if ((u32)D_142430_0039C7F0.f180 >= 2) D_142430_0039C7F0.f180 = 0;
        if (func_12E400(D_142430_0039C7F0.c[D_142430_0039C7F0.f180].port, D_142430_0039C7F0.c[D_142430_0039C7F0.f180].slot, &D_142430_0039C7F0.c[D_142430_0039C7F0.f180].type, &D_142430_0039C7F0.c[D_142430_0039C7F0.f180].free, &D_142430_0039C7F0.c[D_142430_0039C7F0.f180].f14) == 0) D_142430_0039C7F0.f15C = 1;
        break;
    case 1:
        if (D_142430_0039C7F0.f144 != 0) {
            D_142430_0039C7F0.c[D_142430_0039C7F0.f180].f18 = -4;
            D_142430_0039C7F0.c[D_142430_0039C7F0.f180].f10 = D_142430_0039C7F0.f144;
            D_142430_0039C7F0.c[D_142430_0039C7F0.f180].f24 = -1;
            D_142430_0039C7F0.c[D_142430_0039C7F0.f180].f20 = 0;
            D_142430_0039C7F0.c[D_142430_0039C7F0.f180].f30 = -1;
            D_142430_0039C7F0.c[D_142430_0039C7F0.f180].f4C = -1;
            D_142430_0039C7F0.c[D_142430_0039C7F0.f180].f68 = -1;
            D_142430_0039C7F0.c[D_142430_0039C7F0.f180].f84 = -1;
            D_142430_0039C7F0.c[D_142430_0039C7F0.f180].f1C = 0;
        }
        D_142430_0039C7F0.f180++;
        if (D_142430_0039C7F0.f168 < D_142430_0039C7F0.f180 && D_142430_0039C7F0.f164 >= 0) {
            D_142430_0039C7F0.f15C = 2;
            if (D_142430_0039C7F0.f168 >= 0) {
                if (D_142430_0039C7F0.c[D_142430_0039C7F0.f168].f10 == 0 || D_142430_0039C7F0.f164 == 0x18) {
                    D_142430_0039C7F0.f14C = D_142430_0039C7F0.f168;
                    D_142430_0039C7F0.f15C = D_142430_0039C7F0.f164;
                    D_142430_0039C7F0.f16C = 0;
                } else {
                    D_142430_0039C7F0.f16C = 0x271A;
                }
            } else {
                D_142430_0039C7F0.f16C = 0x271A;
            }
            D_142430_0039C7F0.f164 = -1;
            D_142430_0039C7F0.f168 = -1;
        } else {
            if (D_142430_0039C7F0.f180 < 2) D_142430_0039C7F0.f15C = 0; else D_142430_0039C7F0.f15C = 2;
            D_142430_0039C7F0.f154 = 0;
        }
        break;
    case 2:
        D_142430_0039C7F0.f184++;
        if (D_142430_0039C7F0.f164 >= 0 || D_142430_0039C7F0.f184 > 10) {
            D_142430_0039C7F0.f184 = 0;
            D_142430_0039C7F0.f180 = 0;
            D_142430_0039C7F0.f15C = 0;
        }
        D_142430_0039C7F0.f154 = 0;
        break;
    case 3:
        if (D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f14 == 0) {
            if (func_12E6D8(D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].port, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].slot) == 0) D_142430_0039C7F0.f15C = 4;
        } else {
            D_142430_0039C7F0.f154 = 0;
            D_142430_0039C7F0.f15C = 2;
        }
        break;
    case 4:
        if (D_142430_0039C7F0.f144 != 0) {
            D_142430_0039C7F0.f16C = 1;
            D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
            D_142430_0039C7F0.f15C = 0;
            D_142430_0039C7F0.f14C = 0;
            D_142430_0039C7F0.f154 = 0;
            break;
        }
        D_142430_0039C7F0.f15C = 0;
        D_142430_0039C7F0.f14C = 0;
        D_142430_0039C7F0.f154 = 0;
        break;
    case 5:
        if (D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f14 == 0) {
            if (func_12E8D8(D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].port, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].slot) == 0) D_142430_0039C7F0.f15C = 6;
        } else {
            D_142430_0039C7F0.f154 = 0;
            D_142430_0039C7F0.f15C = 2;
        }
        break;
    case 6:
        if (D_142430_0039C7F0.f144 != 0) {
            D_142430_0039C7F0.f16C = 2;
            D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
            D_142430_0039C7F0.f15C = 0;
            D_142430_0039C7F0.f14C = 0;
            D_142430_0039C7F0.f154 = 0;
            break;
        }
        D_142430_0039C7F0.f15C = 0;
        D_142430_0039C7F0.f14C = 0;
        D_142430_0039C7F0.f154 = 0;
        break;
    case 7:
        if (func_12E580(D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].port, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].slot, D_001D5390, 0, 0xB, D_0022CCC0) == 0) {
            D_142430_0039C7F0.f160 = 0;
            D_142430_0039C7F0.f15C = 8;
        }
        break;
    case 8:
        switch (D_142430_0039C7F0.f160) {
        case 0:
            if (D_142430_0039C7F0.f144 > 0) {
                s32 i, total, fa, fb, fc, fd, n, total2;
                fa = 0;
                func_0011A264((s32)found, 0, 0x10);
                fb = 0;
                fc = 0;
                fd = 0;
                i = 0;
                total = 0;
                for (; i < D_142430_0039C7F0.f144; i++) {
                    DE_397490 *de = &D_0022CCC0[i];
                    total += (u32)(de->size + 0x3FF) >> 10;
                    if (func_11B610(D_0022CCC0[i].name, D_001D53BD) == 0) fa = 1;
                    if (func_11B610(D_0022CCC0[i].name, D_001D53DD) == 0) fb = 1;
                    if (func_11B610(D_0022CCC0[i].name, D_001D53FD) == 0) fc = 1;
                    if (func_11B610(D_0022CCC0[i].name, D_001D542D) == 0) fd = 1;
                    if (func_11B9A0(D_0022CCC0[i].name, D_001D6348, 4) == 0 && func_11B9A0(D_0022CCC0[i].name + 5, D_001D6350, 4) == 0) {
                        n = de->name[4] - '0';
                        if (n >= 0) {
                            if (n < 4) found[n] = 1;
                        }
                    }
                }
                total2 = total + 1;
                total = total2 + (D_142430_0039C7F0.f144 + 1) / 2;
                if ((total == 0x257 || total == 0x258) && D_142430_0039C7F0.f144 == 10 && fa && fb && fc && fd
                    && found[0] && found[1] && found[2] && found[3]) {
                    D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f20 = 0;
                    D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f18 = -1;
                    D_142430_0039C7F0.f160 = 1;
                    D_142430_0039C7F0.f154 = 0;
                    break;
                }
                D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f20 = total;
                D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f18 = -2;
            } else {
                D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f18 = -2;
                if (D_142430_0039C7F0.f144 == -2) {
                    D_142430_0039C7F0.f16C = 3;
                    D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                } else if (D_142430_0039C7F0.f144 >= 0) {
                    D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f18 = -2;
                } else if (D_142430_0039C7F0.f144 != -4) {
                    D_142430_0039C7F0.f16C = 4;
                    D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                }
            }
            D_142430_0039C7F0.f15C = 0;
            D_142430_0039C7F0.f14C = 0;
            D_142430_0039C7F0.f154 = 0;
            break;
        case 1:
            func_11B2E8(path, D_001D5438, 0);
            if (func_12DCA0(D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].port, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].slot, path, 1) == 0) D_142430_0039C7F0.f160++;
            break;
        case 2:
            if (D_142430_0039C7F0.f144 >= 0) {
                D_142430_0039C7F0.f158 = D_142430_0039C7F0.f144;
                D_142430_0039C7F0.f160 = 3;
            } else {
                D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f18 = -2;
                D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                if (D_142430_0039C7F0.f144 == -7) D_142430_0039C7F0.f16C = 0x2710;
                else if (D_142430_0039C7F0.f144 == -5) D_142430_0039C7F0.f16C = 0x2711;
                else if (D_142430_0039C7F0.f144 == -4) D_142430_0039C7F0.f16C = 0x2712;
                else if (D_142430_0039C7F0.f144 == -3) D_142430_0039C7F0.f16C = 0x2713;
                else if (D_142430_0039C7F0.f144 == -2) D_142430_0039C7F0.f16C = 3;
                else D_142430_0039C7F0.f16C = 4;
                D_142430_0039C7F0.f15C = 0;
                D_142430_0039C7F0.f14C = 0;
            }
            D_142430_0039C7F0.f154 = 0;
            break;
        case 3:
            D_142430_0039C7F0.f178 = 8;
            if (func_12E050(D_142430_0039C7F0.f158, &D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f28, 8) == 0) D_142430_0039C7F0.f160 = 4;
            break;
        case 4:
            if (D_142430_0039C7F0.f144 == D_142430_0039C7F0.f178) {
                D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f24 = 0;
                if (D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f28 != func_0039EA88(D_00332388)) D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f24++;
                if (D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f2C != func_0039EA88(D_00332618)) D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f24++;
                D_142430_0039C7F0.f154 = 0;
                D_142430_0039C7F0.f160 = 5;
            } else {
                D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f18 = -2;
                D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                if (D_142430_0039C7F0.f144 >= 0) {
                    D_142430_0039C7F0.f16C = 0x2716;
                    if (func_12DE00(D_142430_0039C7F0.f158) == 0) {
                        D_142430_0039C7F0.f15C = 0;
                        D_142430_0039C7F0.f14C = 0;
                        D_142430_0039C7F0.f154 = 0;
                    }
                } else {
                    if (D_142430_0039C7F0.f144 == -5) D_142430_0039C7F0.f16C = 0x2711;
                    else if (D_142430_0039C7F0.f144 == -4) D_142430_0039C7F0.f16C = 0x2714;
                    else if (D_142430_0039C7F0.f144 == -3) D_142430_0039C7F0.f16C = 0x2715;
                    else if (D_142430_0039C7F0.f144 == -2) D_142430_0039C7F0.f16C = 3;
                    else D_142430_0039C7F0.f16C = 4;
                    D_142430_0039C7F0.f15C = 0;
                    D_142430_0039C7F0.f14C = 0;
                    D_142430_0039C7F0.f154 = 0;
                }
            }
            break;
        case 5:
            if (func_12DE00(D_142430_0039C7F0.f158) == 0) {
                D_142430_0039C7F0.f154 = 0;
                D_142430_0039C7F0.f15C = 0x15;
            }
            break;
        }
        break;
    case 9:
        D_142430_0039C7F0.f15C = 10;
        D_142430_0039C7F0.f188 = 6;
        D_142430_0039C7F0.f160 = 0;
        D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f18 = 0;
    case 10:
        switch (D_142430_0039C7F0.f160) {
        case 0:
            if (D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].free + D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f20 >= 0x258) {
                D_142430_0039C7F0.f160 = 1;
            } else {
                D_142430_0039C7F0.f16C = 7;
                D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                D_142430_0039C7F0.f15C = 0;
                D_142430_0039C7F0.f14C = 0;
            }
            D_142430_0039C7F0.f154 = 0;
            break;
        case 1:
            if (func_12DDC8(D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].port, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].slot, D_001D5378) == 0) D_142430_0039C7F0.f160 = 2;
            break;
        case 2:
            if (D_142430_0039C7F0.f144 == 0 || D_142430_0039C7F0.f144 == -4) {
                D_142430_0039C7F0.f160 = 3;
            } else {
                D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                if (D_142430_0039C7F0.f144 == -3) D_142430_0039C7F0.f16C = 7;
                else if (D_142430_0039C7F0.f144 == -2) D_142430_0039C7F0.f16C = 6;
                else D_142430_0039C7F0.f16C = 0xD;
                D_142430_0039C7F0.f15C = 0;
                D_142430_0039C7F0.f14C = 0;
                D_142430_0039C7F0.f154 = 0;
            }
            break;
        case 3: {
            s32 *ptr;
            ((s32 (*)())func_003932E8)(D_160C40_0039C6E0.f664 << 11, &ptr);
            ((void (*)(s32, s32, s32))func_003A2998)((s32)ptr, D_160C40_0039C6E0.f660 + D_160C40_0039C6E0.f64C, D_160C40_0039C6E0.f664);
            D_142430_0039C7F0.f160 = 4;
            D_142430_0039C7F0.f154 = 0;
            break;
        }
        case 4:
            if (D_001CCFD4[0] == 0) D_142430_0039C7F0.f160 = 5;
            D_142430_0039C7F0.f154 = 0;
            break;
        case 5: case 9: case 13: case 17: case 22:
            switch (D_142430_0039C7F0.f160) {
            case 5: func_11B754(found, D_001D53A8); break;
            case 9: func_11B754(found, D_001D53C8); break;
            case 22: func_11B754(found, D_001D53E8); break;
            case 13: func_11B754(found, D_001D5418); break;
            case 17: func_11B2E8(found, D_001D5438, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f18); break;
            }
            if (func_12DCA0(D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].port, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].slot, (char *)found, 0x203) == 0) {
                D_142430_0039C7F0.f158 = -1;
                D_142430_0039C7F0.f160++;
            }
            break;
        case 6: case 10: case 14: case 18: case 23:
            if (D_142430_0039C7F0.f144 >= 0) {
                s32 *ptr;
                if (D_142430_0039C7F0.f158 < 0) D_142430_0039C7F0.f158 = D_142430_0039C7F0.f144;
                ((s32 (*)())func_003932E8)(D_160C40_0039C6E0.f664 << 11, &ptr);
                switch (D_142430_0039C7F0.f160) {
                case 6:
                    D_142430_0039C7F0.f178 = 0x3C4;
                    D_142430_0039C7F0.f174 = (s32)ptr + ptr[0];
                    D_142430_0039C7F0.f188++;
                    break;
                case 10:
                    D_142430_0039C7F0.f178 = ptr[3];
                    D_142430_0039C7F0.f174 = (s32)ptr + ptr[2];
                    D_142430_0039C7F0.f188 += (D_142430_0039C7F0.f178 + 0x3FF) >> 10;
                    break;
                case 23:
                    D_142430_0039C7F0.f174 = (s32)&D_001D545C;
                    D_142430_0039C7F0.f178 = (0x258 - D_142430_0039C7F0.f188) << 10;
                    break;
                case 14: {
                    s32 n = func_0039EBA8(D_001C5BD0, 0, &D_001D6318);
                    D_142430_0039C7F0.f174 = (s32)D_001C5BD0;
                    D_142430_0039C7F0.f178 = n;
                    D_142430_0039C7F0.f188 += (D_142430_0039C7F0.f178 + 0x3FF) >> 10;
                    break;
                }
                case 18: {
                    s32 n = func_0039EA88(D_00332388);
                    n += func_0039EA88(D_00332618) * 0x25;
                    D_142430_0039C7F0.f178 = n + 8;
                    D_142430_0039C7F0.f174 = (s32)ptr + ptr[4];
                    D_142430_0039C7F0.f188 += (D_142430_0039C7F0.f178 + 0x3FF) >> 10;
                    break;
                }
                }
                if (func_12E168(D_142430_0039C7F0.f158, (void *)D_142430_0039C7F0.f174, D_142430_0039C7F0.f178) == 0) D_142430_0039C7F0.f160++;
            } else {
                D_142430_0039C7F0.f16C = 0xA;
                D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                D_142430_0039C7F0.f15C = 0;
                D_142430_0039C7F0.f14C = 0;
                D_142430_0039C7F0.f154 = 0;
            }
            break;
        case 7: case 11: case 15: case 19: case 24:
            if (D_142430_0039C7F0.f144 == D_142430_0039C7F0.f178) {
                if (func_12DE00(D_142430_0039C7F0.f158) == 0) D_142430_0039C7F0.f160++;
            } else {
                D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                if (D_142430_0039C7F0.f144 >= 0) {
                    D_142430_0039C7F0.f16C = 0xB;
                    if (func_12DE00(D_142430_0039C7F0.f158) == 0) {
                        D_142430_0039C7F0.f15C = 0;
                        D_142430_0039C7F0.f14C = 0;
                        D_142430_0039C7F0.f154 = 0;
                    }
                } else {
                    if (D_142430_0039C7F0.f144 == -4) D_142430_0039C7F0.f16C = 8;
                    else if (D_142430_0039C7F0.f144 == -3) D_142430_0039C7F0.f16C = 7;
                    else if (D_142430_0039C7F0.f144 == -2) D_142430_0039C7F0.f16C = 6;
                    else D_142430_0039C7F0.f16C = 0xD;
                    D_142430_0039C7F0.f15C = 0;
                    D_142430_0039C7F0.f14C = 0;
                    D_142430_0039C7F0.f154 = 0;
                }
            }
            break;
        case 8: case 12: case 16: case 20:
            if (D_142430_0039C7F0.f144 == 0) {
                D_142430_0039C7F0.f160++;
            } else {
                D_142430_0039C7F0.f16C = 0xC;
                D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                D_142430_0039C7F0.f15C = 0;
                D_142430_0039C7F0.f14C = 0;
            }
            D_142430_0039C7F0.f154 = 0;
            break;
        case 21:
            if (++D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f18 < 4) D_142430_0039C7F0.f160 = 0x11;
            else D_142430_0039C7F0.f160++;
            D_142430_0039C7F0.f154 = 0;
            break;
        case 25:
            D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f28 = func_0039EA88(D_00332388);
            D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f2C = func_0039EA88(D_00332618);
            D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f18 = -1;
            D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f24 = 0;
            D_142430_0039C7F0.f15C = 0;
            D_142430_0039C7F0.f14C = 0;
            break;
        }
        break;
    case 11:
        D_142430_0039C7F0.f15C = 12;
        D_142430_0039C7F0.f160 = 0;
        D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f18 = -2;
    case 12:
        switch (D_142430_0039C7F0.f160) {
        case 0:
            if (func_12E580(D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].port, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].slot, D_001D5390, 0, 1, D_0022CCC0) == 0) D_142430_0039C7F0.f160 = 1;
            break;
        case 1:
            if (D_142430_0039C7F0.f144 == 1) {
                func_11B2E8(found, D_001D6358, D_001D5378, D_0022CCE0);
                if (func_12E7A8(D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].port, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].slot, (char *)found) == 0) D_142430_0039C7F0.f160 = 2;
                break;
            }
            if (D_142430_0039C7F0.f144 == 0) {
                D_142430_0039C7F0.f160 = 3;
            } else {
                D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                if (D_142430_0039C7F0.f144 == -5) D_142430_0039C7F0.f16C = 0x10;
                else if (D_142430_0039C7F0.f144 == -4) D_142430_0039C7F0.f16C = 0xF;
                else if (D_142430_0039C7F0.f144 == -2) D_142430_0039C7F0.f16C = 0xE;
                else D_142430_0039C7F0.f16C = 0x12;
                D_142430_0039C7F0.f15C = 0;
                D_142430_0039C7F0.f14C = 0;
            }
            D_142430_0039C7F0.f154 = 0;
            break;
        case 2:
            if (func_12E580(D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].port, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].slot, D_001D5390, 1, 1, D_0022CCC0) == 0) D_142430_0039C7F0.f160 = 1;
            break;
        case 3:
            if (func_12E7A8(D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].port, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].slot, D_001D5378) == 0) D_142430_0039C7F0.f160 = 4;
            break;
        case 4:
            if (D_142430_0039C7F0.f144 != 0) {
                D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                if (D_142430_0039C7F0.f144 == -6) D_142430_0039C7F0.f16C = 0x11;
                else if (D_142430_0039C7F0.f144 == -5) D_142430_0039C7F0.f16C = 0x10;
                else if (D_142430_0039C7F0.f144 == -4) D_142430_0039C7F0.f16C = 0xF;
                else if (D_142430_0039C7F0.f144 == -2) D_142430_0039C7F0.f16C = 0xE;
                else D_142430_0039C7F0.f16C = 0x12;
            }
            D_142430_0039C7F0.f15C = 0;
            D_142430_0039C7F0.f14C = 0;
            D_142430_0039C7F0.f154 = 0;
            break;
        }
        break;
    case 21:
        D_142430_0039C7F0.f15C = 0x16;
        D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f1A = -1;
        D_142430_0039C7F0.f150 = 0;
        break;
    case 22:
        D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f1A++;
        if (D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f1A < 4) {
            D_142430_0039C7F0.f160 = 0;
            D_142430_0039C7F0.f15C = 0x17;
        } else {
            D_142430_0039C7F0.f15C = 0;
            D_142430_0039C7F0.f14C = 0;
            D_142430_0039C7F0.f154 = 0;
        }
        break;
    case 13:
        if (D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f18 < 0) {
            D_142430_0039C7F0.f16C = 0x13;
            D_142430_0039C7F0.f15C = 0;
            D_142430_0039C7F0.f14C = 0;
            D_142430_0039C7F0.f154 = 0;
            break;
        }
        D_142430_0039C7F0.f150 = 0;
        D_142430_0039C7F0.f160 = 0;
        D_142430_0039C7F0.f15C = 14;
    case 14:
    case 23:
        switch (D_142430_0039C7F0.f160) {
        case 0:
            if (D_142430_0039C7F0.f15C == 0x17) func_11B2E8(found, D_001D5438, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f1A);
            else func_11B2E8(found, D_001D5438, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f18);
            if (func_12DCA0(D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].port, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].slot, (char *)found, 1) == 0) D_142430_0039C7F0.f160++;
            break;
        case 1:
            if (D_142430_0039C7F0.f144 >= 0) {
                D_142430_0039C7F0.f158 = D_142430_0039C7F0.f144;
                D_142430_0039C7F0.f160 = 2;
            } else {
                D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                if (D_142430_0039C7F0.f144 == -7) D_142430_0039C7F0.f16C = 0x14;
                else if (D_142430_0039C7F0.f144 == -5) D_142430_0039C7F0.f16C = 0x15;
                else if (D_142430_0039C7F0.f144 == -4) D_142430_0039C7F0.f16C = 0x16;
                else if (D_142430_0039C7F0.f144 == -3) D_142430_0039C7F0.f16C = 0x17;
                else if (D_142430_0039C7F0.f144 == -2) D_142430_0039C7F0.f16C = 0x18;
                else D_142430_0039C7F0.f16C = 0x1C;
                D_142430_0039C7F0.f15C = 0;
                D_142430_0039C7F0.f14C = 0;
            }
            D_142430_0039C7F0.f154 = 0;
            break;
        case 2:
            D_142430_0039C7F0.f178 = 8;
            if (func_12E050(D_142430_0039C7F0.f158, &D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f28, 8) == 0) D_142430_0039C7F0.f160 = 3;
            break;
        case 3:
            if (D_142430_0039C7F0.f144 == D_142430_0039C7F0.f178) {
                D_142430_0039C7F0.f154 = 0;
                D_142430_0039C7F0.f160 = 4;
            } else {
                D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                if (D_142430_0039C7F0.f144 >= 0) {
                    D_142430_0039C7F0.f16C = 0x1B;
                    if (func_12DE00(D_142430_0039C7F0.f158) == 0) {
                        D_142430_0039C7F0.f15C = 0;
                        D_142430_0039C7F0.f14C = 0;
                        D_142430_0039C7F0.f154 = 0;
                    }
                } else {
                    if (D_142430_0039C7F0.f144 == -5) D_142430_0039C7F0.f16C = 0x15;
                    else if (D_142430_0039C7F0.f144 == -4) D_142430_0039C7F0.f16C = 0x19;
                    else if (D_142430_0039C7F0.f144 == -3) D_142430_0039C7F0.f16C = 0x1A;
                    else if (D_142430_0039C7F0.f144 == -2) D_142430_0039C7F0.f16C = 0x18;
                    else D_142430_0039C7F0.f16C = 0x1C;
                    D_142430_0039C7F0.f15C = 0;
                    D_142430_0039C7F0.f14C = 0;
                    D_142430_0039C7F0.f154 = 0;
                }
            }
            break;
        case 4:
            D_142430_0039C7F0.f178 = D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f28;
            if (func_12E050(D_142430_0039C7F0.f158, D_001C5BD0, D_142430_0039C7F0.f178) == 0) D_142430_0039C7F0.f160 = 5;
            break;
        case 5:
            if (D_142430_0039C7F0.f144 == D_142430_0039C7F0.f178) {
                if (D_142430_0039C7F0.f15C == 0x17) {
                    func_0039ECC0(D_001C5BD0, D_142430_0039C7F0.f14C, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f1A);
                    D_142430_0039C7F0.f160 = 8;
                } else {
                    D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f24 = ((s32 (*)())func_0039ED78)(D_001C5BD0, D_001C5BD0 + D_142430_0039C7F0.f144, 0, D_00332388);
                    D_142430_0039C7F0.f160 = 6;
                }
                D_142430_0039C7F0.f154 = 0;
            } else {
                D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                if (D_142430_0039C7F0.f144 >= 0) {
                    D_142430_0039C7F0.f16C = 0x1B;
                    if (func_12DE00(D_142430_0039C7F0.f158) == 0) {
                        D_142430_0039C7F0.f15C = 0;
                        D_142430_0039C7F0.f14C = 0;
                        D_142430_0039C7F0.f154 = 0;
                    }
                } else {
                    if (D_142430_0039C7F0.f144 == -5) D_142430_0039C7F0.f16C = 0x15;
                    else if (D_142430_0039C7F0.f144 == -4) D_142430_0039C7F0.f16C = 0x19;
                    else if (D_142430_0039C7F0.f144 == -3) D_142430_0039C7F0.f16C = 0x1A;
                    else if (D_142430_0039C7F0.f144 == -2) D_142430_0039C7F0.f16C = 0x18;
                    else D_142430_0039C7F0.f16C = 0x1C;
                    D_142430_0039C7F0.f15C = 0;
                    D_142430_0039C7F0.f14C = 0;
                    D_142430_0039C7F0.f154 = 0;
                }
            }
            break;
        case 6:
            D_142430_0039C7F0.f178 = D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f2C;
            if (func_12E050(D_142430_0039C7F0.f158, D_001CBBD0, D_142430_0039C7F0.f178) == 0) D_142430_0039C7F0.f160 = 7;
            break;
        case 7:
            if (D_142430_0039C7F0.f144 == D_142430_0039C7F0.f178) {
                D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f24 += ((s32 (*)())func_0039ED78)(D_001CBBD0, D_001CBBD0 + D_142430_0039C7F0.f144, D_142430_0039C7F0.f150, D_00332618);
                D_142430_0039C7F0.f150++;
                if (D_142430_0039C7F0.f150 < 0x25) D_142430_0039C7F0.f160 = 6;
                else D_142430_0039C7F0.f160 = 8;
                D_142430_0039C7F0.f154 = 0;
            } else {
                D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                if (D_142430_0039C7F0.f144 >= 0) {
                    D_142430_0039C7F0.f16C = 0x1B;
                    if (func_12DE00(D_142430_0039C7F0.f158) == 0) {
                        D_142430_0039C7F0.f15C = 0;
                        D_142430_0039C7F0.f14C = 0;
                        D_142430_0039C7F0.f154 = 0;
                    }
                } else {
                    if (D_142430_0039C7F0.f144 == -5) D_142430_0039C7F0.f16C = 0x15;
                    else if (D_142430_0039C7F0.f144 == -4) D_142430_0039C7F0.f16C = 0x19;
                    else if (D_142430_0039C7F0.f144 == -3) D_142430_0039C7F0.f16C = 0x1A;
                    else if (D_142430_0039C7F0.f144 == -2) D_142430_0039C7F0.f16C = 0x18;
                    else D_142430_0039C7F0.f16C = 0x1C;
                    D_142430_0039C7F0.f15C = 0;
                    D_142430_0039C7F0.f14C = 0;
                    D_142430_0039C7F0.f154 = 0;
                }
            }
            break;
        case 8:
            if (func_12DE00(D_142430_0039C7F0.f158) == 0) {
                if (D_142430_0039C7F0.f15C == 0x17) {
                    D_142430_0039C7F0.f154 = 0;
                    D_142430_0039C7F0.f15C = 0x16;
                } else {
                    func_0039F2B8();
                    if (D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f24 != 0) D_142430_0039C7F0.f16C = 0x1C;
                    D_142430_0039C7F0.f15C = 0;
                    D_142430_0039C7F0.f14C = 0;
                }
            }
            break;
        }
        break;
    case 15:
        if (D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f24 != 0) {
            D_142430_0039C7F0.f16C = 0x2717;
            D_142430_0039C7F0.f15C = 0;
            D_142430_0039C7F0.f14C = 0;
            D_142430_0039C7F0.f154 = 0;
            break;
        }
        if (D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f18 < 0) {
            D_142430_0039C7F0.f16C = 0x1D;
            D_142430_0039C7F0.f15C = 0;
            D_142430_0039C7F0.f14C = 0;
            D_142430_0039C7F0.f154 = 0;
            break;
        }
        D_142430_0039C7F0.f160 = 0;
        D_142430_0039C7F0.f15C = 0x10;
    case 16:
        switch (D_142430_0039C7F0.f160) {
        case 0:
            func_11B2E8(found, D_001D5438, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f18);
            if (func_12DCA0(D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].port, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].slot, (char *)found, 2) == 0) D_142430_0039C7F0.f160 = 1;
            break;
        case 1:
            if (D_142430_0039C7F0.f144 >= 0) {
                D_142430_0039C7F0.f158 = D_142430_0039C7F0.f144;
                D_142430_0039C7F0.f160 = 2;
            } else {
                D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                if (D_142430_0039C7F0.f144 == -7) D_142430_0039C7F0.f16C = 0x1E;
                else if (D_142430_0039C7F0.f144 == -5) D_142430_0039C7F0.f16C = 0x1F;
                else if (D_142430_0039C7F0.f144 == -4) D_142430_0039C7F0.f16C = 0x20;
                else if (D_142430_0039C7F0.f144 == -3) D_142430_0039C7F0.f16C = 0x21;
                else if (D_142430_0039C7F0.f144 == -2) D_142430_0039C7F0.f16C = 0x22;
                else D_142430_0039C7F0.f16C = 0x26;
                D_142430_0039C7F0.f15C = 0;
                D_142430_0039C7F0.f14C = 0;
            }
            D_142430_0039C7F0.f154 = 0;
            break;
        case 2:
            if (func_12DEC0(D_142430_0039C7F0.f158, 8, 0) == 0) D_142430_0039C7F0.f160 = 3;
            break;
        case 3:
            if (D_142430_0039C7F0.f144 >= 0) {
                D_142430_0039C7F0.f160 = 4;
            } else if (func_12DE00(D_142430_0039C7F0.f158) == 0) {
                D_142430_0039C7F0.f16C = 0x26;
                D_142430_0039C7F0.f15C = 0;
                D_142430_0039C7F0.f14C = 0;
                D_142430_0039C7F0.f154 = 0;
            }
            break;
        case 4:
            if (func_12E168(D_142430_0039C7F0.f158, D_001C5BD0, func_0039EA88(D_00332388)) == 0) D_142430_0039C7F0.f160 = 5;
            break;
        case 5:
            if (D_142430_0039C7F0.f144 == func_0039EA88(D_00332388)) {
                D_142430_0039C7F0.f160 = 6;
            } else {
                D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                if (D_142430_0039C7F0.f144 >= 0) {
                    D_142430_0039C7F0.f16C = 0x25;
                    if (func_12DE00(D_142430_0039C7F0.f158) == 0) {
                        D_142430_0039C7F0.f15C = 0;
                        D_142430_0039C7F0.f14C = 0;
                        D_142430_0039C7F0.f154 = 0;
                    }
                } else {
                    if (D_142430_0039C7F0.f144 == -5) D_142430_0039C7F0.f16C = 0x1F;
                    else if (D_142430_0039C7F0.f144 == -4) D_142430_0039C7F0.f16C = 0x23;
                    else if (D_142430_0039C7F0.f144 == -3) D_142430_0039C7F0.f16C = 0x24;
                    else if (D_142430_0039C7F0.f144 == -2) D_142430_0039C7F0.f16C = 0x22;
                    else D_142430_0039C7F0.f16C = 0x26;
                    D_142430_0039C7F0.f15C = 0;
                    D_142430_0039C7F0.f14C = 0;
                    D_142430_0039C7F0.f154 = 0;
                }
            }
            break;
        case 6:
            if (func_12DEC0(D_142430_0039C7F0.f158, D_142430_0039C7F0.c[0].f28 + 8 + D_142430_0039C7F0.f150 * D_142430_0039C7F0.c[0].f2C, 0) == 0) D_142430_0039C7F0.f160 = 7;
            break;
        case 7:
            if (D_142430_0039C7F0.f144 == D_142430_0039C7F0.c[0].f28 + 8 + D_142430_0039C7F0.f150 * D_142430_0039C7F0.c[0].f2C) {
                D_142430_0039C7F0.f160 = 8;
            } else if (func_12DE00(D_142430_0039C7F0.f158) == 0) {
                D_142430_0039C7F0.f15C = 0;
                D_142430_0039C7F0.f14C = 0;
                D_142430_0039C7F0.f154 = 0;
            }
            break;
        case 8:
            if (func_12E168(D_142430_0039C7F0.f158, D_001CBBD0, func_0039EA88(D_00332618)) == 0) D_142430_0039C7F0.f160 = 9;
            break;
        case 9:
            if (D_142430_0039C7F0.f144 == func_0039EA88(D_00332618)) {
                D_142430_0039C7F0.f160 = 0xA;
            } else {
                D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                if (D_142430_0039C7F0.f144 >= 0) {
                    D_142430_0039C7F0.f16C = 0x25;
                    if (func_12DE00(D_142430_0039C7F0.f158) == 0) {
                        D_142430_0039C7F0.f15C = 0;
                        D_142430_0039C7F0.f14C = 0;
                        D_142430_0039C7F0.f154 = 0;
                    }
                } else {
                    if (D_142430_0039C7F0.f144 == -5) D_142430_0039C7F0.f16C = 0x1F;
                    else if (D_142430_0039C7F0.f144 == -4) D_142430_0039C7F0.f16C = 0x23;
                    else if (D_142430_0039C7F0.f144 == -3) D_142430_0039C7F0.f16C = 0x24;
                    else if (D_142430_0039C7F0.f144 == -2) D_142430_0039C7F0.f16C = 0x18;
                    else D_142430_0039C7F0.f16C = 0x1C;
                    D_142430_0039C7F0.f15C = 0;
                    D_142430_0039C7F0.f14C = 0;
                    D_142430_0039C7F0.f154 = 0;
                }
            }
            break;
        case 10:
            if (func_12DE00(D_142430_0039C7F0.f158) == 0) {
                D_142430_0039C7F0.f15C = 0;
                D_142430_0039C7F0.f14C = 0;
            }
            break;
        }
        break;
    case 17: {
        s32 *ptr;
        ((s32 (*)())func_003932E8)(D_160C40_0039C6E0.f664 << 11, &ptr);
        ((void (*)(s32, s32, s32))func_003A2998)((s32)ptr, D_160C40_0039C6E0.f660 + D_160C40_0039C6E0.f64C, D_160C40_0039C6E0.f664);
        D_142430_0039C7F0.f160 = 0x12;
        D_142430_0039C7F0.f154 = 0;
        break;
    }
    case 18:
        if (D_001CCFD4[0] == 0) {
            s32 *ptr;
            ((s32 (*)())func_003932E8)(D_160C40_0039C6E0.f664 << 11, &ptr);
            D_142430_0039C7F0.f160 = 0x13;
            D_142430_0039C7F0.f174 = (s32)ptr + ptr[4];
        }
        D_142430_0039C7F0.f154 = 0;
        break;
    case 19:
        if (D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f24 != 0) {
            D_142430_0039C7F0.f16C = 0x2718;
            D_142430_0039C7F0.f15C = 0;
            D_142430_0039C7F0.f14C = 0;
            D_142430_0039C7F0.f154 = 0;
            break;
        }
        if (D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f18 < 0) {
            D_142430_0039C7F0.f16C = 0x27;
            D_142430_0039C7F0.f15C = 0;
            D_142430_0039C7F0.f14C = 0;
            D_142430_0039C7F0.f154 = 0;
            break;
        }
        D_142430_0039C7F0.f150 = 0;
        D_142430_0039C7F0.f160 = 0;
        D_142430_0039C7F0.f15C = 0x14;
    case 20:
        switch (D_142430_0039C7F0.f160) {
        case 0:
            func_11B2E8(found, D_001D5438, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f18);
            if (func_12DCA0(D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].port, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].slot, (char *)found, 2) == 0) D_142430_0039C7F0.f160 = 1;
            break;
        case 1:
            if (D_142430_0039C7F0.f144 >= 0) {
                D_142430_0039C7F0.f158 = D_142430_0039C7F0.f144;
                t = func_0039EA88(D_00332388);
                t += func_0039EA88(D_00332618) * 0x25;
                D_142430_0039C7F0.f178 = t + 8;
                if (func_12E168(D_142430_0039C7F0.f158, (void *)D_142430_0039C7F0.f174, D_142430_0039C7F0.f178) == 0) D_142430_0039C7F0.f160 = 2;
            } else {
                D_142430_0039C7F0.f16C = 0x2B;
                D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                D_142430_0039C7F0.f15C = 0;
                D_142430_0039C7F0.f14C = 0;
                D_142430_0039C7F0.f154 = 0;
            }
            break;
        case 2:
            if (D_142430_0039C7F0.f144 == D_142430_0039C7F0.f178) {
                if (func_12DE00(D_142430_0039C7F0.f158) == 0) D_142430_0039C7F0.f160 = 3;
            } else {
                D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
                if (D_142430_0039C7F0.f144 >= 0) {
                    D_142430_0039C7F0.f16C = 0xB;
                    if (func_12DE00(D_142430_0039C7F0.f158) == 0) {
                        D_142430_0039C7F0.f15C = 0;
                        D_142430_0039C7F0.f14C = 0;
                        D_142430_0039C7F0.f154 = 0;
                    }
                } else {
                    if (D_142430_0039C7F0.f144 == -4) D_142430_0039C7F0.f16C = 0x28;
                    else if (D_142430_0039C7F0.f144 == -3) D_142430_0039C7F0.f16C = 0x29;
                    else if (D_142430_0039C7F0.f144 == -2) D_142430_0039C7F0.f16C = 0x2A;
                    else D_142430_0039C7F0.f16C = 0x2D;
                    D_142430_0039C7F0.f15C = 0;
                    D_142430_0039C7F0.f14C = 0;
                    D_142430_0039C7F0.f154 = 0;
                }
            }
            break;
        case 3:
            if (D_142430_0039C7F0.f144 != 0) {
                D_142430_0039C7F0.f16C = 0x2C;
                D_142430_0039C7F0.f170 = D_142430_0039C7F0.f14C;
            }
            D_142430_0039C7F0.f15C = 0;
            D_142430_0039C7F0.f14C = 0;
            D_142430_0039C7F0.f154 = 0;
            break;
        }
        break;
    case 24:
        D_142430_0039C7F0.f15C = 0x19;
        D_142430_0039C7F0.f160 = 0;
        D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f1C = 1;
    case 25: {
        s32 q = D_142430_0039C7F0.f160 / 5;
        s32 m = D_142430_0039C7F0.f160 % 5;
        switch (q) {
        case 0: func_11B2E8(found, D_001D6360, m); break;
        case 1: func_11B2E8(found, D_001D6380, m); break;
        case 2: func_11B2E8(found, D_001D63A0, m); break;
        case 3: *(u8 *)found = 0; break;
        }
        if (*(u8 *)found == 0) {
            D_142430_0039C7F0.f15C = 0x1C;
            D_142430_0039C7F0.f154 = 0;
        } else if (func_12DCA0(D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].port, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].slot, (char *)found, 1) == 0) {
            D_142430_0039C7F0.f15C = 0x1A;
        }
        break;
    }
    case 26:
        if (D_142430_0039C7F0.f144 >= 0) {
            D_142430_0039C7F0.f158 = D_142430_0039C7F0.f144;
            if (func_12E050(D_142430_0039C7F0.f158, D_001C5BD0, 0x2800) == 0) D_142430_0039C7F0.f15C = 0x1B;
        } else {
            D_142430_0039C7F0.f154 = 0;
            D_142430_0039C7F0.f15C = 0x19;
            D_142430_0039C7F0.f160 = (D_142430_0039C7F0.f160 / 5 + 1) * 5;
        }
        break;
    case 27:
        if (D_142430_0039C7F0.f144 >= 0x2800) {
            E_397490 *ent;
            if (func_12DE00(D_142430_0039C7F0.f158) != 0) return;
            if (func_0039EB68(D_001C5BD8) != 0) {
                ent = (E_397490 *)(D_001C5BD8 + 8);
                while (ent->type != -1) {
                    if (ent->type == 10) {
                        D_142660.f48 |= 0x40;
                        if (ent->d[0x1F] != 0) {
                            D_142660.f48 |= 1;
                            D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f1C++;
                        }
                        break;
                    }
                    ent = (E_397490 *)((u8 *)ent + ((ent->size + 3) / 4 * 4 + 8));
                }
            }
            D_142430_0039C7F0.f160++;
        } else {
            D_142430_0039C7F0.f160 = (D_142430_0039C7F0.f160 / 5 + 1) * 5;
        }
        D_142430_0039C7F0.f15C = 0x19;
        D_142430_0039C7F0.f154 = 0;
        break;
    case 28:
        D_142430_0039C7F0.f15C = 0x1D;
        D_142430_0039C7F0.f160 = 0;
        D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f1C++;
    case 29:
        switch (D_142430_0039C7F0.f160 / 5) {
        case 0: func_11B2E8(found, D_001D63C0, D_142430_0039C7F0.f160 % 4); break;
        case 1: func_11B2E8(found, D_001D63E0, D_142430_0039C7F0.f160 % 4); break;
        case 2: func_11B2E8(found, D_001D6400, D_142430_0039C7F0.f160 % 4); break;
        case 3: func_11B2E8(found, D_001D6420, D_142430_0039C7F0.f160 % 4); break;
        case 4: *(u8 *)found = 0; break;
        }
        if (*(u8 *)found == 0) {
            D_142430_0039C7F0.f15C = 0;
            D_142430_0039C7F0.f14C = 0;
            D_142430_0039C7F0.f154 = 0;
        } else if (func_12DCA0(D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].port, D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].slot, (char *)found, 1) == 0) {
            D_142430_0039C7F0.f15C = 0x1E;
        }
        break;
    case 30:
        if (D_142430_0039C7F0.f144 >= 0) {
            D_142430_0039C7F0.f158 = D_142430_0039C7F0.f144;
            if (func_12E050(D_142430_0039C7F0.f158, D_001C5BD0, 0x2800) == 0) D_142430_0039C7F0.f15C = 0x1F;
        } else {
            D_142430_0039C7F0.f154 = 0;
            D_142430_0039C7F0.f15C = 0x1D;
            D_142430_0039C7F0.f160 = (D_142430_0039C7F0.f160 / 5 + 1) * 5;
        }
        break;
    case 31:
        if (D_142430_0039C7F0.f144 >= 0x2800) {
            E_397490 *ent;
            if (func_12DE00(D_142430_0039C7F0.f158) != 0) return;
            if (func_0039EB68(D_001C5BD8) != 0) {
                ent = (E_397490 *)(D_001C5BD8 + 8);
                while (ent->type != -1) {
                    if (ent->type == 10) {
                        u8 *d = ent->d;
                        D_142660.f48 |= 0x80;
                        if (d[0x29] != 0) { D_142660.f48 |= 2; D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f1C++; }
                        if (d[0x1D] != 0) { D_142660.f48 |= 4; D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f1C++; }
                        if (d[0x25] != 0) { D_142660.f48 |= 8; D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f1C++; }
                        if (d[0x2D] != 0) { D_142660.f48 |= 0x10; D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f1C++; }
                        if (d[0x1C] != 0) { D_142660.f48 |= 0x20; D_142430_0039C7F0.c[D_142430_0039C7F0.f14C].f1C++; }
                        break;
                    }
                    ent = (E_397490 *)((u8 *)ent + ((ent->size + 3) / 4 * 4 + 8));
                }
            }
            D_142430_0039C7F0.f160++;
        } else {
            D_142430_0039C7F0.f160 = (D_142430_0039C7F0.f160 / 5 + 1) * 5;
        }
        D_142430_0039C7F0.f15C = 0x1D;
        D_142430_0039C7F0.f154 = 0;
        break;
    }
}
/* localdecomp:end func_0039C7F0 */
