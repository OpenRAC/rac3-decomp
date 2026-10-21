/* US draft of func_0039BD08 (rac3-uya-decomp func_00396F18, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0039BD08 */
__asm__(".extern D_001D62F4, 4");
__asm__(".extern D_001D62F8_0039BD08, 4");
__asm__(".extern D_001D6308_0039BD08, 4");
__asm__(".extern D_001D62FC_0039BD08, 4");
__asm__(".extern D_001D6300_0039BD08, 4");
__asm__(".extern D_001D6304_0039BD08, 4");
__asm__(".extern D_001D9FA0, 1");
typedef struct { u8 pad[0x10]; s32 x10; u8 padA[0x134]; s32 x148; } S_a;
extern void func_0039C028(void);
extern s32 D_001D62F4;
extern s32 D_001D62F8_0039BD08;
extern s32 D_001D6308_0039BD08;
extern s32 D_001D62FC_0039BD08;
extern s32 D_001D6300_0039BD08;
extern s32 D_001D6304_0039BD08;
extern s8 D_001D9FA0;
extern s32 D_001D4CEC_0039BD08;
extern s8 D_001D9FA8;
extern S_a D_00142430_0039BD08[];
void func_0039BD08(s32 arg0, s32 arg1, s32 arg2) {
    S_a *p = D_00142430_0039BD08;
    s32 x;
    D_001D62F4 = arg0;
    D_001D62F8_0039BD08 = arg2;
    D_001D6308_0039BD08 = arg1;
    p->x148 = 0;
    D_001D62FC_0039BD08 = 0;
    D_001D6300_0039BD08 = 0;
    D_001D6304_0039BD08 = 0;
    D_001D9FA8 = 0;
    D_001D9FA0 = 0;
    func_0039C028();
    p->x10 = 0;
    D_001D4CEC_0039BD08 &= ~4; D_001D4CEC_0039BD08 |= 2; D_001D4CEC_0039BD08 &= ~0x40; D_001D4CEC_0039BD08 &= ~0x10; D_001D4CEC_0039BD08 &= ~0x4000;
}
/* localdecomp:end func_0039BD08 */
