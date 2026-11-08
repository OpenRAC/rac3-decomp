/* func_L04_003E5788: near miss, 2 diff (Sonnet w3, p2w4). Size 272, 1 place (L04), src/levels/04_marcadia/L04_003E51D0.c
   Entity-walk template (func_L04_003627C8) + vsub asm block (m operands). Only diff: retail has `move $a0,$s1`
   before the sqc2 (j-form scheduling; levels lack -mvu0-use-vf0-vf2 so the j form cannot be used). */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_3E5788;
extern u16 *D_L04_0021C9A0[];
extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFD9C, 16");
extern s32 D_L04_001DFDD8;
extern void func_003C5060(void *, void *, void *, int);

int func_L04_003E5788(u8 *self) {
    u16 *p;
    u8 *e;
    int n = 0;
    V4_3E5788 v;
    for (p = D_L04_0021C9A0[self[0x21]];
         self[0x21] != 0xFF && self[0x21] <= D_L04_001DFDD8 && p != 0 &&
         ((s16)p[-1] >= 0 || p == D_L04_0021C9A0[self[0x21]]);
         p++) {
        e = D_L04_001DFD9C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            return n;
        if (e != self) {
            __asm__("lqc2 $vf2, %1\n"
                    "lqc2 $vf1, %2\n"
                    "vsub.xyz $vf2, $vf2, $vf1\n"
                    "sqc2 $vf2, %0\n"
                    : "=m"(v) : "m"(*(V4_3E5788 *)(e + 0x10)), "m"(*(V4_3E5788 *)(self + 0x10)));
            func_003C5060(self, &v, &v, 0);
            if (v.x < 0.0f)
                n++;
        }
    }
    return n;
}
