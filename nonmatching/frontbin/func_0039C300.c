/* US draft of func_0039C300 (rac3-uya-decomp func_00397380, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0039C300 */
typedef struct { u8 pad[0x64C]; s32 f64C; u8 p650[0x10]; s32 f660; s32 f664; } S_160C40_00397380;
typedef struct { u8 pad[0x18]; s16 f18; u8 p1A[0x162]; s32 f17C; } S_142430_00397380;
typedef struct { u8 pad[0x18]; s32 f18; u8 p1C[0x14]; s32 f30; } S_16C580_00397380;
extern S_160C40_00397380 D_160C40_0039C300;
extern S_142430_00397380 D_142430_0039C300;
extern S_16C580_00397380 D_16C580_0039C300;
extern u8 D_00143950_0039C300[];
extern s32 D_001D545C_0039C300;
extern s32 D_001D4B60_0039C300, D_001D4CEC_0039C300, D_001D4B90_0039C300, D_001D4BA0_0039C300;
extern void func_00392F08();
extern s32 func_003A2750();
extern s32 func_003A26F0();
extern void func_0038CC88();
extern void func_0039C220();
void func_0039C300(void) {
    u8 buf[0xBC];
    u8 *p;
    u8 *q;
    func_00392F08(D_160C40_0039C300.f664 << 11, &p);
    func_003A2750(1);
    func_003A26F0(p, D_160C40_0039C300.f660 + D_160C40_0039C300.f64C, D_160C40_0039C300.f664);
    q = p + *(s32 *)(p + 0x10);
    func_0038CC88(buf, D_00143950_0039C300, 0xBC);
    func_0039C220(q);
    func_0038CC88(D_00143950_0039C300, buf, 0xBC);
    D_001D545C_0039C300 = 1;
    if (D_142430_0039C300.f17C != 0) D_142430_0039C300.f17C = 0;
    if (D_142430_0039C300.f18 >= 0) D_142430_0039C300.f18 = -1;
    D_001D4CEC_0039C300 &= ~0x200;
    D_001D4B60_0039C300 = -1;
    D_001D4B90_0039C300 = -1;
    D_001D4BA0_0039C300 = -1;
    D_16C580_0039C300.f30 = -1;
    D_16C580_0039C300.f18 = -1;
}
/* localdecomp:end func_0039C300 */
