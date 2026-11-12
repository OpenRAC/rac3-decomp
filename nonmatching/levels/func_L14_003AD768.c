/* func_L14_003AD768: near miss, 3 diff: file is already @ps2as; left: the loop-bottom reload of s->pC (lw/slt/bnel) uses $v1 in retail, $v0 in ours; not tried further
   Level 14 (Koros) only; flags of its file in config/levels/text_parts.txt. */
typedef struct {
    f32 f0;
    u8 *p4;
    f32 *p8;
    s32 pC;
    f32 *p10;
    f32 *p14;
    s32 f18;
    s32 f1C;
    s32 f20;
} S_3AD768;
extern void func_L01_00470150(void *, s32, s32, s32, s32, s32, f32, f32, s32, s32, f32, s32, s32);
extern void func_L01_00404A10(void *, void *);
extern void func_003AD850();
void func_L14_003AD768(u8 *a0) {
    S_3AD768 *s = *(S_3AD768 **)(a0 + 0x68);
    s32 i;
    if (*(u16 *)(a0 + 0x34) != 0) {
        if (a0[0x31] != 0) {
            for (i = 0; i < s->pC; i++) {
                func_L01_00470150(s->p4 + i * 16, (s32)a0, s->f20, -1, 0, 2, s->p8[i] * 210000.0f, 0.2f, 0, -1, 1.0f, 0, 0);
            }
            func_L01_00404A10(func_003AD850, a0);
        }
    }
}
