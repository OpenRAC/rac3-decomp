/* functional: high. Byte-identical at L04 (checked); uses the shared vec_neg helper. */
/* localdecomp:start func_L04_003E2818 */
typedef int s128_003E2818 __attribute__((mode(TI)));
extern void func_003C2EC0(void *, s32, void *);
extern u8 *func_L01_003B1750(u8 *, s128_003E2818 *, s128_003E2818 *, s32, s32, s32, s32, f32, f32);

void func_L04_003E2818(u8 *self, u8 *m) {
    char matrix[64] __attribute__((aligned(16)));
    s128_003E2818 v[2];
    func_003C2EC0(self, 1, matrix);
    vec_neg(matrix + 0x10, matrix + 0x10);
    v[0] = *(s128_003E2818 *)(matrix + 0x30);
    v[1] = *(s128_003E2818 *)(matrix + 0x10);
    func_L01_003B1750(self, &v[0], &v[1], 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, *(f32 *)(m + 0x6C), 0.65f);
}
/* localdecomp:end func_L04_003E2818 */
