/* functional: high. Clears bit 4 in D_001D4CEC; if D_00142430.f15C==2 and f164<0: with f16C!=0 sets D_001D4CEC|=0x40 and D_001D4CE8=0x16, else D_001D4CE8=f15C (=2). Verified against PAL asm (bit-clear store is unconditional, as retail's delay slot). */
typedef struct { u8 pad[0x15C]; s32 f15C; u8 pad2[4]; s32 f164; u8 pad3[4]; s32 f16C; } S_39BD90;
extern S_39BD90 D_00142430;
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];

void func_0039BD90(void)
{
    S_39BD90 *s = &D_00142430;

    D_001D4CEC[0] &= ~4;
    if (s->f15C == 2 && s->f164 < 0) {
        if (s->f16C != 0) {
            D_001D4CEC[0] |= 0x40;
            D_001D4CE8[0] = 0x16;
        } else {
            D_001D4CE8[0] = s->f15C;
        }
    }
}
