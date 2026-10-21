#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003E41A8(void);
extern void func_003E41C0(void);
extern void func_003E4178(void);
/* --- end of declarations from other files --- */

/* declarations of 3E15B0.c's earlier functions (tools/port_from_us.py) */
extern void func_003A96A8(s32);
extern void func_00391708(void);
extern s32 D_001D5520[];
extern void func_00391A58(s32, s32, s32, s32, s32, s32);
extern void func_003D96F0(void);
extern s32 D_00306D40[];
typedef struct {
    s16 f0;
    u16 f2;
    s16 f4, f6, f8, fA, fC, fE;
    s16 f10;
    u16 f12;
    s16 f14, f16, f18, f1A;
} T_3DBEC8;
typedef struct {
    u8 pad0[0x40];
    s32 f40;
    s32 f44;
    u8 pad48[0x58 - 0x48];
    s32 f58;
    s32 f5C;
    s32 f60;
    u8 pad64[0x7C - 0x64];
    s16 f7C, f7E;
    s32 f80;
    u8 pad84[0x98 - 0x84];
} S_3DBEC8;
extern S_3DBEC8 D_00306D00_003E17D0;
extern T_3DBEC8 D_001D94D0;
extern T_3DBEC8 D_001D9510;
extern char D_001D94F0[];
extern char D_001D94F8[];
extern char D_001D9500[];
extern char D_001D9530[];
extern s32 D_001D9BC8;
extern u16 D_001D4BC4;
extern s32 D_001D5B90;
extern s32 D_001D4CE8;
extern u8 D_001D9FA0;
extern u8 D_001D5BDC;
extern u8 D_001D5BDD;
extern f32 D_001DA074;
extern s32 D_001DA070;
extern char *D_001D949C;
extern char *D_001D94A0;
extern char *D_001D94A4;
extern u8 D_001D94A8;
extern s32 D_001D94BC;
extern s32 D_001D94C0;
extern u8 D_003357E0[];
extern void func_0038B200(s32, s32, s32, s32);
extern void func_00389620(s32);
extern void func_003A97F8(s32, unsigned long);
extern char *func_00382468(s32);
extern s32 func_11BB58(void *, void *, s32);
extern s32 func_11B868(void *);
extern void func_003AF7C0(T_3DBEC8 *, u32, void *, s32, s32, s32, s32, void *, void *, s32);
extern s32 func_00396D48(s32, s32);
extern void func_00397040(s32, s32, s32, s32, s32, s32);
extern s32 func_00396E18(s32);
extern void func_00397A18(f32, f32, f32, f32, f32, s32, s32, s32);
extern s32 func_0011A264(void *, s32, s32);
extern void func_0038E530(s32);
extern void func_00382490(void);
extern void func_11B2E8();
extern void func_0038C790(s32, s32, s32, s32, s32, s32);
extern s32 func_0038DFB8(s32, s32, f32);
extern s32 func_00391198(s32, s32, s32, void *, s32);
extern long func_00389978(s32);
extern void func_003914C0(T_3DBEC8 *, s32, void *, s32, long, void *);
extern void func_003914A0(T_3DBEC8 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_00389750(void);
extern f32 D_001D94CC;
extern f32 D_00222420[];
extern void func_003C50A0();
extern void func_0038DBF0();
extern void func_0038D9D0();

extern void func_0038D270(void *, void *, void *);
extern u8 D_00306DD0[];

/* localdecomp:start func_003E4178 */
typedef struct { u8 pad[0x40]; s32 f40; u8 pad2[0x14]; s32 f58; } S_302D80;
extern S_302D80 D_00306D00;
 
void func_003E4178(void) {
    S_302D80 *s = &D_00306D00;
    if (s->f40 == 7 && s->f58 == 1) {
        s->f58 = 2;
    }
}
/* localdecomp:end func_003E4178 */

/* localdecomp:start func_003E41A8 */
extern s32 D_00306D40[];
s32 func_003E41A8(void) {
    return D_00306D40[0] == 7;
}
/* localdecomp:end func_003E41A8 */

/* localdecomp:start func_003E41C0 */
extern s32 D_001D94B0;
void func_003E41C0(void) {
    D_001D94B0 = 3;
}
/* localdecomp:end func_003E41C0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E41D0);

/* localdecomp:start func_003E41D8 */
extern s16 D_00306D84[];
 
void func_003E41D8(void) {
    D_00306D84[0] = 0;
}
/* localdecomp:end func_003E41D8 */

/* localdecomp:start func_003E41E8 */
void *func_003E41E8(void *p) {
    return (u8 *)p + 0xED1C;
}
/* localdecomp:end func_003E41E8 */
