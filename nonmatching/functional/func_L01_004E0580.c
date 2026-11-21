/* functional: high. Same logic as retail; retail reads the tick counter both through lui/lw and $gp, both are the same word (D_L01_001DFB40). 2 near-miss words from scheduling only. */
typedef struct { u8 pad[0x1160]; s32 blink, next, range; } Blink_004E0580;
extern s32 D_L01_001DFB40;
void func_L01_004E0580(void) {
    extern s32 func_00382468(s32);
    s32 a, b;
    Blink_004E0580 *h=(Blink_004E0580 *)&D_001A4BE0;
    if (h->blink==0) {
        s32 range=h->range;
        s32 now=D_L01_001DFB40;
        if (range==0) {
            h->next=D_L01_001DFB40+25;
        } else if (h->next<now) {
            h->blink=1;
            a=func_00382468(h->range);
            b=func_00382468(h->range);
            h->next=(s32)((long)D_L01_001DFB40 + (s32)((u32)a+17)) + b;
        }
    }
}
