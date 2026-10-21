/* US draft of func_00396C60 (rac3-uya-decomp func_00392400, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00396C60 */
typedef struct { s32 w; u8 pad[2]; u8 b6; u8 b7; } W_392400;
extern P_392108 *D_001D9EA8_00396C60;
extern W_392400 *D_001D9EAC_00396C60;
extern u32 *D_001DA050;
extern s32 func_00396A38_00396C60();
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern s32 D_001D9E94;
void func_00396C60(s32 idx, s32 x, s32 y, s32 w, s32 h, s32 col) {
    unsigned long *q;
    P_392108 *p = (P_392108 *)((idx << 2) + (s32)D_001D9EA8_00396C60);
    W_392400 *e = &D_001D9EAC_00396C60[p->b];
    s32 tw = 1 << e->b6;
    s32 th = 1 << e->b7;
    D_001DA050[0] = 0x10000005;
    D_001DA050[1] = 0;
    D_001DA050[2] = 0;
    D_001DA050[3] = 0x50000005;
    q = (unsigned long *)(D_001DA050 + 4);
    D_001DA050 = (u32 *)q;
    q[0] = 0xE800UL << 47 | 0x8001;
    q[1] = 0x5353106;
    q[2] = func_00396A38_00396C60(idx);
    q[3] = 0x156;
    q[4] = ((long)col << 24) | 0x7F7F7F;
    q[5] = 0;
    q[6] = (unsigned long)((x * 16 + D_001D4BD0 - 8) | ((long)(y * 16 + D_001D4BD4 - 8) << 16)) | ((long)D_001D9E94 << 32);
    q[7] = (th << 20) + (tw << 4);
    q[8] = (unsigned long)(((x + w) * 16 + D_001D4BD0 - 8) | ((long)((y + h) * 16 + D_001D4BD4 - 8) << 16)) | ((long)D_001D9E94 << 32);
    q[9] = 0;
    D_001DA050 += 0x14;
}
/* localdecomp:end func_00396C60 */
