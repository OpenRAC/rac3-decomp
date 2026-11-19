/* functional: high. Written from PAL asm; the $gp slot is declared as a D_L01_ .sdata extern like neighbouring level code. */
extern void func_L01_004CAB30(void *, void *);
extern s32 D_L01_001D6694;
extern f32 D_L01_001D7F38 __attribute__((section(".sdata")));
void func_L01_0046CB28(u8 *p) {
    u8 *vars = p + 0x20;
    s32 t;
    u32 col;
    if (D_L01_001D6694 == 7) {
        D_L01_001D7F38 = *(f32 *)(p + 0xC);
        *(s32 *)(p + 0xC) = 0;
    } else {
        *(f32 *)(p + 0xC) = D_L01_001D7F38;
    }
    if (vars[2] != 1) {
        if (vars[2] == 2) {
            u8 *parent = *(u8 **)(vars + 4);
            *(f32 *)(p + 0x10) = *(f32 *)(parent + 0x10) + *(f32 *)(vars + 0x10);
            *(f32 *)(p + 0x14) = *(f32 *)(*(u8 **)(vars + 4) + 0x14) + *(f32 *)(vars + 0x14);
            *(f32 *)(p + 0x18) = *(f32 *)(*(u8 **)(vars + 4) + 0x18) + *(f32 *)(vars + 0x18);
        }
        col = *(u32 *)(p + 4);
        t = ((s32)col >> 24) - *(s16 *)vars;
        if (t <= 0) {
            func_003CD250((Obj *)p);
            return;
        }
        *(u32 *)(p + 4) = (col & 0xFFFFFF) | ((u32)t << 24);
    }
    if (vars[3] != 0) {
        func_L01_004CAB30(p + 0x10, p + 0x10);
    }
}
