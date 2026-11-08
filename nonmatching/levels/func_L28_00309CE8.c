/* func_L28_00309CE8: ported from rac2 func_L08_003DB8E8; structure exact, one extra lui/lw reload of D_L28_001DE840 in retail (arm block) vs gp-only here
   Phase 2 w3 w7; 304 bytes, 1 place; 55 diff rows are mostly the 2-insn shift
   Draft below compiles */
#if 0
typedef int u128_t __attribute__((mode(TI)));
extern u128_t D_001A4C60;
extern u8 *D_L28_001DC560;
extern s32 D_L28_001DE840;
extern s32 D_L28_001D6694;
extern s32 func_L28_003098F0(void *a);
extern void func_L28_00309958(void);
extern void func_L24_0041CE48(s32 a, void *b, s32 c);

void func_L28_00309CE8(u8 *self) {
    s32 *vars = *(s32 **)(self + 0x68);
    s32 count;
    s32 shown;

    *(u128_t *)(self + 0x10) = D_001A4C60;
    count = func_L28_003098F0(self);
    if (self[0x20] == 0) {
        self[0x20] = 1;
        vars[0] = count;
        vars[1] = 0;
        self[0x30] = 0xFF;
        D_L28_001DC560 = self;
    }
    if (D_L28_001DE840 % 10 == 0) {
        shown = vars[0];
        if (shown < count) {
            vars[1] = 0;
            vars[0] = shown + 1;
        } else if (count < shown) {
            vars[0] = shown - 1;
        }
    }
    if (count > 0 && D_L28_001D6694 != 2 && (self[0x20] == 1 || self[0x20] == 2)) {
        self[0x20] = 2;
        func_L24_0041CE48(0, func_L28_00309958, 2);
        return;
    }
    if ((count <= 0 || D_L28_001D6694 == 2) && self[0x20] == 2) {
        func_L24_0041CE48(0, 0, 2);
        self[0x20] = 1;
    }
}
#endif
