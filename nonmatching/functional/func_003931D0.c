/* functional: high. Checked block by block against asm: gp offsets of D_001D5B74/D_001D9D04 verified (gp=0x1DC8B0), struct offsets 0x17C and 0x18 (lh/sh), mask ~0x200, x==0x18 selects D_001D4CF0 else D_001D9D04. Bytes differ only in global addressing/frame. */
typedef struct { u8 pad[0x18]; s16 h18; u8 pad2[0x17C - 0x1A]; s32 x17C; } S_38E5B8;
extern S_38E5B8 D_00142430_003931D0[];
extern s32 D_001D5B74;
extern s32 D_001D9D04;
extern s32 D_001D545C[];
extern s32 D_001D4CF0[];
extern s32 D_001D4CEC_003931D0[];
extern void func_0039F008(s32, s32);
extern void func_00393120(s32 *);
extern void func_003932D0(void);
void func_003931D0(s32 a, s32 b) {
    s32 x = a;
    s32 y;
    S_38E5B8 *p;
    func_00393120(&x);
    y = x;
    D_001D5B74 = 1;
    D_001D4CF0[0] = D_001D545C[0];
    D_001D9D04 = y;
    if (y == -1) {
        p = D_00142430_003931D0;
        if (p->x17C != 0) p->x17C = 0;
        if (p->h18 >= 0) p->h18 = y;
        D_001D4CEC_003931D0[0] &= ~0x200;
    }
    if (b != 0) {
        func_003932D0();
        if (x != 0x18) func_0039F008(0, D_001D9D04);
        else func_0039F008(0, D_001D4CF0[0]);
    }
}
