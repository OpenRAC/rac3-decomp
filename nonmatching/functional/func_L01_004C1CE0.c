/* functional: high. Rewritten from PAL asm; pure stores. */
/* localdecomp:start func_L01_004C1CE0 */
extern s32 D_L01_001E0F58[];
extern f32 D_L01_001E0F68[];
extern f32 D_L01_001E0F6C[];
extern s32 D_L01_001E0F70[];
extern s32 D_L01_001E0F74[];
extern s32 D_L01_001E0F60[];
__asm__(".extern D_L01_001E0F58, 16");
__asm__(".extern D_L01_001E0F68, 16");
__asm__(".extern D_L01_001E0F6C, 16");
__asm__(".extern D_L01_001E0F70, 16");
__asm__(".extern D_L01_001E0F74, 16");

s32 func_L01_004C1CE0(s32 a0, s32 a1, s32 a2, f32 f12, f32 f13) {
    if (D_L01_001E0F60[0] != 1) return 0;
    D_L01_001E0F58[0] = a0;
    D_L01_001E0F68[0] = f12;
    D_L01_001E0F6C[0] = f13;
    D_L01_001E0F60[0] = 2;
    D_L01_001E0F70[0] = a1;
    D_L01_001E0F74[0] = a2;
    return 1;
}
/* localdecomp:end func_L01_004C1CE0 */
