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
extern void func_003A8A58(void);
extern void func_003A8980(s32, s32, s32, s32, s32);


extern u8 D_001A30B0[];
extern s32 D_001DA030;
extern s32 D_001DA034;
extern s32 D_001DA038;
extern s32 D_001DA03C;
extern s32 D_001DA040;
extern s32 D_001DA044;
extern s16 D_001CD018[];
extern void func_13CF80();
extern void func_11F0A0();
extern void func_003A1C28();
extern void func_0038A238();
extern void func_003A0D40();
/* localdecomp:start func_003A8980 */
extern u8 *D_001D6EEC_003A8980;
extern s32 func_0038DFB8(s32, s32, f32);
extern f32 func_0038DE98(f32, f32);
extern f32 func_003828C0(f32, f32);
extern void func_0038D200(f32 *, void *, f32);
extern s32 func_0038CEB0(void *);
typedef struct { u8 pad0[0x24]; f32 f24; f32 f28; u8 pad2C[4]; s32 f30; u8 pad34[4]; s32 f38; s32 f3C; u8 pad40[8]; s32 f48; s32 f4C; } E_3A3028_003A8980;
extern E_3A3028_003A8980 *D_001D6EEC_003A8850;
extern f32 D_001D6EF0_003A8980;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; } E_3A3128_003A8980;
extern s32 D_001D4B00_003A8980;
extern s32 D_001D4B04_003A8980;
extern s32 D_001D4B30_003A8980;
extern s32 D_001D4B34_003A8980;
extern E_3A3128_003A8980 D_0022DF20_3A88E8[];
extern s32 func_11F1E0_003A8980();
extern u8 D_001D7FC0_003A8980;
extern s32 D_001D8000_003A8980;
extern s32 D_001D8004_003A8980;
extern s32 D_001D8008_003A8980;
extern s32 D_001D800C_003A8980;
extern s32 D_001D8010_003A8980;
extern void func_0038CFA8(s32, s32);
extern u32 D_001D8010_003A8BE8;
extern u32 D_001D8004_003A8BE8;
extern s32 D_001D8000_003A8980;
extern s32 D_001D8008_003A8980;
extern s32 func_003A8B28(s32);
extern s32 D_001DA034_003A8980;
extern u8 D_00142BA0_003A8980[];
extern s32 D_00227400_003A8980[];
extern u8 D_00143A07_003A8980[];
extern u8 D_00160C40_003A8C70_003A8980[];
extern void func_00392F98(s32 *);

extern u8 D_001A30B0_003A8980[];
extern s32 D_001DA030_003A8980;
extern s32 D_001DA034_003A8980;
extern s32 D_001DA038_003A8980;
extern s32 D_001DA03C_003A8980;
extern s32 D_001DA040_003A8980;
extern s32 D_001DA044_003A8980;
extern s16 D_001CD018_003A8980[];
extern void func_13CF80_003A8980();
extern void func_11F0A0_003A8980();
extern void func_003A5430_003A8980();
extern void func_003A1C28_003A8980();
extern void func_0038A238_003A8980();
extern void func_003A0D40_003A8980();
void func_003A8980(s32 a, s32 b, s32 c, s32 d, s32 e) {
    D_001A30B0_003A8980[0x43] |= 8;
    func_13CF80_003A8980(2, 0, 0, 0, 0);
    func_11F0A0_003A8980(0);
    func_003A5430_003A8980();
    func_003A1C28_003A8980();
    D_001DA030_003A8980 = a;
    D_001DA044_003A8980 = D_001CD018_003A8980[0];
    D_001DA034_003A8980 = b;
    D_001DA038_003A8980 = c;
    D_001DA03C_003A8980 = d;
    D_001DA040_003A8980 = e;
    func_0038A238_003A8980(4);
    func_003A0D40_003A8980();
}
/* localdecomp:end func_003A8980 */

extern s32 D_001D4D40;
extern void *D_001DA044_003A8A58;
extern u8 D_001A30B0[];
extern void (*D_001D5BD4)(s32);
extern s32 D_00227460[];
extern s32 D_001D5B90;
extern s32 D_001D5BD8;
extern void func_0038A238(s32);
extern void func_003A1930(void *, s32, s32);
extern void func_003A1D00(void);
extern void func_003A9108(void);
/* localdecomp:start func_003A8A58 */
extern s32 D_001D4D40_003A8A58;
extern void *D_001DA044_003A8A58_003A8A58;
extern u8 D_001A30B0_003A8A58[];
extern void (*D_001D5BD4_003A8A58)(s32);
extern s32 D_00227460_003A8A58[];
extern s32 D_001D5B90_003A8A58;
extern s32 D_001D5BD8_003A8A58;
extern void func_0038A238_003A8A58(s32);
extern void func_003A1930_003A8A58(void *, s32, s32);
extern void func_003A1D00_003A8A58(void);
extern void func_003A9108_003A8A58(void);
void func_003A8A58(void) {
    if (D_001D4D40_003A8A58 == 0) { D_001D4D40_003A8A58 = 1; }
    func_0038A238_003A8A58(4);
    func_003A1930_003A8A58(D_001DA044_003A8A58_003A8A58, 1, 0x400);
    func_003A1D00_003A8A58();
    D_001A30B0_003A8A58[0x43] |= 0x10;
    func_003A9108_003A8A58();
    if (D_001D5BD4_003A8A58 != 0 && D_00227460_003A8A58[0] == 0 && D_001D5B90_003A8A58 != 2 && D_001D5B90_003A8A58 != 1) {
        D_001D5BD4_003A8A58(D_001D5BD8_003A8A58);
        D_001D5BD4_003A8A58 = 0;
        D_001D5BD8_003A8A58 = 0;
    }
}
/* localdecomp:end func_003A8A58 */
