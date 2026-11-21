/* functional: high. VU0 vadd/vsub.xyz written as scalar math; compiles clean under file flags, not byte exact. */
extern void func_0038D000(void *, void *, void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern u8 D_L01_001EAA00[];
s32 func_L01_0045CCD8(u8 *self, u8 *b) {
    f32 pos[4] __attribute__((aligned(16)));
    f32 off[4] __attribute__((aligned(16)));
    f32 *sp = (f32 *)(self + 16);
    f32 *hit;
    off[0] = 0.0f;
    off[1] = 0.0f;
    off[2] = *(f32 *)(b + 4) + *(f32 *)b;
    off[3] = 0.0f;
    func_0038D000(off, off, self + 192);
    pos[0] = sp[0] + off[0];
    pos[1] = sp[1] + off[1];
    pos[2] = sp[2] + off[2];
    pos[3] = sp[3];
    if (func_L01_003FB640(pos, *(s32 *)(b + 56) & 2, self, *(f32 *)b) == 0) {
        return 0;
    }
    *(s32 *)(b + 132) = *(s32 *)(D_L01_001EAA00 + 24);
    hit = (f32 *)(D_L01_001EAA00 + 32);
    ((f32 *)(b + 96))[0] = hit[0];
    ((f32 *)(b + 96))[1] = hit[1];
    ((f32 *)(b + 96))[2] = hit[2];
    ((f32 *)(b + 96))[3] = hit[3];
    hit = (f32 *)(D_L01_001EAA00 + 48);
    sp[0] = hit[0] - off[0];
    sp[1] = hit[1] - off[1];
    sp[2] = hit[2] - off[2];
    sp[3] = hit[3];
    return 1;
}
