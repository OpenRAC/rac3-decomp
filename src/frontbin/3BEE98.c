#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


extern u8 D_001DA2D4[];
extern u8 D_001DA300[];
extern s32 D_001D9364[];
u8 func_003BDBF8(void);
/* localdecomp:start func_003BEE98 */
s32 func_003BEE98(s32 a) {
    s32 r = 0;
    if ((D_001DA2D4[0] = func_003BDBF8()) != 0 && a) {
        r = D_001DA300[0] != 0;
    }
    D_001D9364[0] = 1;
    return r;
}
/* localdecomp:end func_003BEE98 */

extern u8 D_001DA2D4_003BEF00;
extern volatile u8 D_001DA300_003BEF00;
extern s32 D_001DA2D0;
extern s32 D_001D8D28;
extern s32 D_001D8D40;
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 h40; } S_3B9A08;
extern S_3B9A08 D_00225700_003BEF00;
extern void func_003BC768();
extern s32 func_003BDF10();
extern s32 func_003BDF18();
extern void func_003BE168();
extern void func_003BB968();
extern s32 func_003BDD38();
extern void func_003BDE60();
extern void func_003BE308();
extern void func_003BDF40();
extern void func_00387EF0();
extern void func_003BDF60();
INCLUDE_ASM("asm/nonmatchings/text", func_003BEF00);

/* localdecomp:start func_003BF030 */
extern void func_003BDF40();
extern void func_003BC768();
 
void func_003BF030(void) {
    func_003BDF40();
    func_003BC768();
}
/* localdecomp:end func_003BF030 */

extern u8 D_001DA310;
extern u8 D_001DA311;
extern s32 D_001D8DF0;
extern s32 D_001D8DF4;
extern void *D_002FCC40;
extern void func_003BBA08(s32, s32);
extern void func_003BC408();
extern void func_003BDCB0(s32, s32 *, s32);
extern s32 func_003BDD38(void);
extern void func_003BDE20(s32);
extern void func_003BF2A0();
extern void func_003BF0E0();
extern void func_003BE308(void *);
extern void func_003BE1F8(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003BF058);

typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x74]; s16 hAA; } S_3B9BE8;
extern s32 D_001D4B60[];
extern u8 func_00381CB0(void);
/* localdecomp:start func_003BF0E0 */
void func_003BF0E0(S_3B9BE8 *p) {
    if (p->hAA == 0x50A) {
        if (D_001D4B60[0] == 4 || ((s32 (*)(void))func_00381CB0)() > 0) {
            p->h34 |= 1;
        }
    }
    p->h34 |= 2;
}
/* localdecomp:end func_003BF0E0 */
