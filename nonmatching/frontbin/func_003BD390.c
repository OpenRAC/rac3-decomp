/* US draft of func_003BD390 (rac3-uya-decomp func_003B7EB0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003BD390 */
typedef struct { u8 p0[0x15C]; s32 f15C; s32 f160; s32 f164; } S_142430_3B7EB0;
typedef struct { u8 p0[7]; u8 f7; } S_1CCFD0_3B7EB0;
__asm__(".extern D_001D8CD1, 1");
__asm__(".extern D_001DA1F0, 4");
__asm__(".extern D_001D8CC4, 4");
extern u8 D_001D8CD1;
extern s32 D_001DA1F0;
extern void (*D_001D8CC4)(void);
extern S_142430_3B7EB0 D_142430_003BD390;
extern S_1CCFD0_3B7EB0 D_1CCFD0_003BD390;
extern void func_11F0A0();
extern void func_0039C410(void);
extern void func_0039ADE0(void);
extern s32 func_0039A1E0(void);
extern void func_13BF00(s32);
extern void func_13BED0(void);
extern void func_003A9AD0(void);
extern void func_00387EF0(void);
void func_003BD390(void) {
    s32 r;
    *(s32 *)0x1D4B4C = 0;
    if (D_001D8CD1 == 0) {
        do {
            func_11F0A0(0);
            func_12C908(0);
            func_0039C410();
            func_0039ADE0();
            r = D_001D8CD1 = func_0039A1E0() != 0;
        } while (r == 0);
    }
    while (D_142430_003BD390.f15C != 2 || D_142430_003BD390.f164 >= 0) {
        func_11F0A0(0);
        func_12C908(0);
        func_0039C410();
        func_0039ADE0();
    }
    if (D_001DA1F0 != 0) func_13BF00(D_001DA1F0);
    do {} while (func_13B620());
    func_13BED0();
    func_13CF40(0);
    ((s32 (*)(s32))func_13CDF0)(0);
    ((s32 (*)(s32))func_13CDF0)(0);
    { S_1CCFD0_3B7EB0 *c = &D_1CCFD0_003BD390; c->f7 = 0; }
    func_003A9AD0();
    if (D_001D8CC4 != 0) D_001D8CC4();
    func_00387EF0();
}
/* localdecomp:end func_003BD390 */
