#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003AFC48(s32, s32, s32 (*)(s32, s32), s32, s32);
/* --- end of declarations from other files --- */

/* declarations of 3AF4B8.c's earlier functions (tools/port_from_us.py) */
extern u8 D_001D8798[];
extern u8 D_001D87B0[];
extern void func_00116F98(void *, s32, void *);
extern void func_003AF420(void *, s32);
extern void func_003AC590();
typedef s32 (*FN_A9EF0)();
typedef struct { FN_A9EF0 a; s32 b; } E_A9EF0;
typedef struct { u8 pad[0x24DD0]; void (*cb24DD0)(); u8 padA[0x14]; FN_A9EF0 cb24DE8; u8 padB[4]; E_A9EF0 e1[4]; E_A9EF0 e2[3]; } P_A9EF0;
extern P_A9EF0 *D_001D5C78_003AF850;
extern s32 D_001D9EC0;
extern s32 D_001D5B94;
extern s32 func_003E17A8();
extern void func_003AF760();
extern s32 D_001D5C78;
extern s32 D_001D52F0;
typedef s32 (*FN_AA0B8)();
typedef struct { s32 a; FN_AA0B8 f; } E_AA0B8;
typedef struct { u8 pad[0x24DCC]; void (*cb24DCC)(); u8 pad2[0x1C]; FN_AA0B8 cb24DEC; E_AA0B8 e1[4]; E_AA0B8 e2[3]; } P_AA0B8;
extern P_AA0B8 *D_001D5C78_003AFA18;
extern s32 D_001D9EC0;
extern s32 D_001D5B94;
typedef struct { u8 p0[0xB0]; f32 fB0; } G_AA0B8;
extern G_AA0B8 D_00225900[];
extern void func_00397FC0();
extern s32 func_003E17A8();
extern void func_003877A0();
extern void func_003AF9E0();
extern s32 D_001D5C78;
extern s32 D_0031D050[];
extern void func_00396948();
extern void func_003AF850();

extern s32 D_001DA08C;
extern s32 D_001DA090;
extern s32 D_001DA094;
extern s32 D_001DA098;
extern s32 D_001DA0A0;
extern s32 D_001DA0A4;
extern s32 D_001DA0A8;
extern s32 D_001DA0AC;
extern s32 D_001DA088_003AFC48;
extern s32 D_001DA09C_003AFC48;
extern s32 D_001DA0B0_003AFC48;
extern s32 D_001DA0B4_003AFC48;
extern s32 D_001DA0B8_003AFC48;
extern s32 D_001DA0C0[];
extern s32 D_001D4D40;
extern void func_00391880();
extern s32 func_003AFE10();
extern void func_003B0360();
extern void func_003B0188();
/* localdecomp:start func_003AFC48 */
extern s32 D_001DA08C;
extern s32 D_001DA090;
extern s32 D_001DA094;
extern s32 D_001DA098;
extern s32 D_001DA0A0;
extern s32 D_001DA0A4;
extern s32 D_001DA0A8;
extern s32 D_001DA0AC;
extern s32 D_001DA088_003AFC48;
extern s32 D_001DA09C_003AFC48;
extern s32 D_001DA0B0_003AFC48;
extern s32 D_001DA0B4_003AFC48;
extern s32 D_001DA0B8_003AFC48;
extern s32 D_001D4D40;
extern s32 D_001DA0C0[];
extern s32 D_001DA09C;
__asm__(".extern D_001DA0B4_003AFC48, 16");
__asm__(".extern D_001DA0B8_003AFC48, 16");
__asm__(".extern D_001DA09C_003AFC48, 16");
__asm__(".extern D_001D4D40, 16");
s32 func_003AFC48(s32 a, s32 b, s32 (*alloc)(s32, s32), s32 d, s32 e) {
    extern void func_00391880();
    extern void func_003B0188();
    extern s32 func_003AFE10();
    extern void func_003B0360();
    s32 i;
    s32 *p = D_001DA0C0;
    s32 result;
    D_001DA08C = alloc(0x1A0000, 0x40);
    D_001DA090 = alloc(0x4FC80, 0x40);
    D_001DA094 = alloc(0x1010, 0x40);
    D_001DA088_003AFC48 = alloc(0x14, 0x40);
    D_001DA098 = alloc(0xEC800, 0x40);
    D_001DA09C = alloc(0x5000C, 0x40);
    D_001DA0A0 = alloc(0xC000, 0x40);
    D_001DA0A4 = alloc(0x80000, 0x40);
    D_001DA0A8 = alloc(0x4000, 0x40);
    D_001DA0AC = alloc(0x3000, 0x40);
    D_001DA0B0_003AFC48 = alloc(0xC, 0x40);
    D_001DA0B4_003AFC48 = alloc(0xB8, 0x40);
    D_001DA0B8_003AFC48 = alloc(0x68, 0x40);
    for (i=1; i>=0; i--) *p++ = alloc(0x4000, 0x80);
    func_00391880(e != 0, e != 0);
    func_003B0188(a,b,d);
    result = func_003AFE10(D_001DA0B4_003AFC48,D_001DA09C_003AFC48,D_001DA0B0_003AFC48);
    func_003B0360();
    D_001D4D40 &= ~0x80;
    return result;
}
/* localdecomp:end func_003AFC48 */
