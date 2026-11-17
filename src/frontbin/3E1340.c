#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003E13F0();
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/remnants", func_003E1340);

/* func_003E1370: from the US C of func_003DBE20 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_003E1370 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001D5520_003E1370;
__asm__(".extern D_001D5520_003E1370, 16");
extern void func_003A92F0(s32);
extern void func_00391328(void);
extern s32 D_001D5520[];
extern void func_00391678(s32, s32, s32, s32, s32, s32);
extern void func_003D9338(void);
void func_003E1370(void) {   /* same as func_003B6438 plus the call below */
    func_003A92F0(1);
    func_00391328();
    if (D_001D5520_003E1370 != 0) {
        func_00391678(0x200, 0x1A0, 0x280, 0x1C0, 0, 0);
    } else {
        func_00391678(0x200, 0x1A0, 0x200, 0x1C0, 0, 0);
    }
    func_003D9338();
}
/* localdecomp:end func_003E1370 */

LINKER_REMNANT("asm/remnants", func_003E13E8);

/* localdecomp:start func_003E13F0 */
extern s32 D_00306D40[];
 
s32 func_003E13F0(void) {
    return D_00306D40[0];
}
/* localdecomp:end func_003E13F0 */

LINKER_REMNANT("asm/remnants", func_003E1400);

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
extern S_3DBEC8 D_00306D00_003E1418;
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
extern void func_0038AE20(s32, s32, s32, s32);
extern void func_00389240(s32);
extern void func_003A9440(s32, unsigned long);
extern char *func_00382088(s32);
extern s32 func_11BB58(void *, void *, s32);
extern s32 func_11B868(void *);
extern void func_003AF408(T_3DBEC8 *, u32, void *, s32, s32, s32, s32, void *, void *, s32);
extern s32 func_00396968(s32, s32);
extern void func_00396C60(s32, s32, s32, s32, s32, s32);
extern s32 func_00396A38(s32);
extern void func_00397638(f32, f32, f32, f32, f32, s32, s32, s32);
extern s32 func_0011A264(void *, s32, s32);
extern void func_0038E150(s32);
extern void func_003820B0(void);
extern void func_11B2E8();
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_00390DB8(s32, s32, s32, void *, s32);
extern long func_00389598(s32);
extern void func_003910E0(T_3DBEC8 *, s32, void *, s32, long, void *);
extern void func_003910C0(T_3DBEC8 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_00389370(void);
