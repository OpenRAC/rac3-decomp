/* func_L01_0048BF00: matches (0 diff) only with @ps2as (the four lui $at/sw $zero stores are the assembler macro, the
   last sw is $gp-relative through the .extern hint). The file L01_0048B738.c is built without @ps2as and
   12 of its other C blocks stop matching under it (every $gp access turns into lui/lw), so it stays here. */
__asm__(".extern D_L01_001D8A60, 4");
extern s32 D_L01_001E08A0;
extern s32 D_L01_001E08A4;
extern s32 D_L01_001E08A8;
extern s32 D_L01_001E08AC;
extern s32 D_L01_001D8A60;

void func_L01_0048BF00(void) {
    D_L01_001E08A0 = 0;
    D_L01_001E08A4 = 0;
    D_L01_001E08A8 = 0;
    D_L01_001E08AC = 0;
    D_L01_001D8A60 = 0;
}
