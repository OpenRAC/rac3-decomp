/* functional: high. Rewritten from PAL asm; pure stores. */
/* localdecomp:start func_L01_004C17E8 */
extern s32 D_L01_001E0F38[];
extern s32 D_L01_001E0F3C[];
extern s32 D_L01_001E0F40[];
extern s32 D_L01_001E0F44[];
extern s32 D_L01_001E0F48[];
extern s32 D_L01_001E0F4C[];
extern f32 D_L01_001E0F5C[];
extern s32 D_L01_001E0F60[];
__asm__(".extern D_L01_001E0F38, 16");
__asm__(".extern D_L01_001E0F3C, 16");
__asm__(".extern D_L01_001E0F40, 16");
__asm__(".extern D_L01_001E0F44, 16");
__asm__(".extern D_L01_001E0F48, 16");
__asm__(".extern D_L01_001E0F4C, 16");
__asm__(".extern D_L01_001E0F5C, 16");

void func_L01_004C17E8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, f32 f) {
    D_L01_001E0F38[0] = a0;
    D_L01_001E0F40[0] = a2;
    D_L01_001E0F44[0] = a3;
    D_L01_001E0F48[0] = a4;
    D_L01_001E0F4C[0] = a5;
    D_L01_001E0F3C[0] = a1;
    D_L01_001E0F5C[0] = f;
    D_L01_001E0F60[0] = 1;
}
/* localdecomp:end func_L01_004C17E8 */
