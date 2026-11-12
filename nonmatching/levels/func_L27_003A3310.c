/* func_L27_003A3310: 2 diff (level 27, needs @ps2as for the inline float constants).
   Everything matches except the second of two identical blocks: retail loads p+0x158 before the
   call and puts the p+0x150 load in the jal func_0038DBD8 delay slot (block 1 has the opposite
   order, which this C reproduces); about 8 wordings of the second block (temps, order, struct
   field access) did not move it. */
/* localdecomp:start func_L27_003A3310 */
typedef struct { u8 p0[0x150]; s32 f150; s32 f154; s32 f158; } S_3310;
extern void func_L01_0040C948(void *, void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern s32 D_001DE060_sda;
__asm__(".extern D_001DE060_sda, 4");
extern f32 D_001DE0B0_sda;
__asm__(".extern D_001DE0B0_sda, 4");
extern f32 D_001DE0B4_sda;
__asm__(".extern D_001DE0B4_sda, 4");

void func_L27_003A3310(void *arg0) {
    S_3310 *p;
    s32 c;
    s32 c2;
    f32 f; f32 f2;
    p = *(void **)((u8 *)arg0 + 0x68);
    func_L01_0040C948((u8 *)p + 0x130, &D_001DE060_sda);
    c = func_0038DBD8(p->f150, p->f158, func_003824E0(0.0f, 1.0f)) | 0x60000000;
    f = D_001DE0B0_sda * func_003824E0(0.75f, 1.25f);
    func_003D9508((u8 *)p + 0x130, 0x31, c, 1, f, D_001DE0B4_sda, func_003824E0(-3.1415927f, 3.1415927f));
    c2 = func_0038DBD8(p->f150, p->f158, func_003824E0(0.0f, 1.0f)) | 0x60000000;
    f2 = D_001DE0B0_sda * func_003824E0(0.75f, 1.25f);
    func_003D9508((u8 *)p + 0x140, 0x31, c2, 1, f2, D_001DE0B4_sda, func_003824E0(-3.1415927f, 3.1415927f));
}
/* localdecomp:end func_L27_003A3310 */
