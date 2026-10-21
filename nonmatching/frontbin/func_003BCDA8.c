/* US draft of func_003BCDA8 (rac3-uya-decomp func_003B78C8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003BCDA8 */
typedef struct { u8 p0[0x18]; s16 f18; u8 p1A[0x142]; s32 f15C; s32 f160; s32 f164; u8 p168[0x14]; s32 f17C; } S_142430_3B78C8;
typedef struct { u8 p0[7]; u8 f7; u8 p8[8]; } S_1CCFD0_3B78C8;
typedef struct { u8 p0[0x10]; u32 f10; } S_2276C0_3B78C8;
typedef struct { u8 p0[0x90]; s32 f90[6]; } S_1A30B0_3B78C8;
extern s32 D_001D5B94;
extern s32 D_001D9D2C;
extern s32 D_001D4CEC;
extern s32 D_001D545C;
extern s32 D_001D9D04;
extern u8 D_00227480[];
extern S_2276C0_3B78C8 D_00227640;
extern S_1A30B0_3B78C8 D_1A30B0;
extern S_142430_3B78C8 D_142430;
extern S_1CCFD0_3B78C8 D_1CCFD0;
extern void func_0038CB78();
extern void func_003C2D88();
extern void func_11F0A0();
extern void func_13CF80(s32, s32, s32, s32, s32);
extern void func_13CA28(void);
extern void func_003A5430(void);
extern void func_003A1C28(void);
extern void func_13BF00(s32);
extern void func_13BED0(void);
extern void func_0039C410(void);
extern void func_0039ADE0(void);
extern s32 func_13CF40(s32);
extern void func_003A2750(s32);
extern void func_0038A238(s32);
extern void func_0039A150(void);
extern void func_13CDF0(s32);
extern void func_003A9AD0(void);
void func_003BCDA8(void) {
    s32 i;
    func_0038CB78(D_00227480, -1, 0x80);
    D_00227640.f10 |= 0x80000000;
    D_001D5B94 = 6;
    func_003C2D88();
    func_11F0A0(0);
    func_13CF80(2, 0, 0, 0, 0);
    func_13CA28();
    func_13B620();
    func_003A5430();
    func_003A1C28();
    D_1CCFD0.f7 = 1;
    for (i = 0; i < 6; i++) {
        if (D_1A30B0.f90[i] != 0) {
            func_13BF00(D_1A30B0.f90[i]);
            func_13BED0();
            D_001D9D2C = 0;
            D_1A30B0.f90[i] = 0;
        }
    }
    while (D_142430.f15C >= 3 || D_142430.f164 >= 0) {
        func_0039C410();
        func_0039ADE0();
    }
    if (D_142430.f17C != 0) D_142430.f17C = 0;
    if (D_142430.f18 >= 0) D_142430.f18 = -1;
    D_001D4CEC &= ~0x200;
    func_13CF40(0);
    D_1CCFD0.f7 = 0;
    func_003A2750(1);
    do {} while (((s32 (*)(void))func_13B620)());
    D_1CCFD0.f7 = 1;
    func_0038A238(6);
    D_001D545C = D_001D9D04;
    func_0039A150();
    func_13CDF0(0);
    D_1CCFD0.f7 = 0;
    func_003A9AD0();
}
/* localdecomp:end func_003BCDA8 */
