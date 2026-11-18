/* func_L32_003A0C18 (level 32): 2 differences (was 10), round 6 (b13-x4). Check it with
 *   python tools/check.py nonmatching/levels/func_L32_003A0C18.c func_L32_003A0C18 --no-context --as ps2as
 * What changed against the old draft, all needed together:
 *  - D_L32_001E2280 and D_L32_001E22A0 are declared with a size of at most 8 bytes: retail's lui/addiu pairs for
 *    them are adjacent, the `la` form of a small object under Ps2EeAs, and with one address insn instead of a
 *    lui/addiu pair the scheduler's priorities come out as retail's (lw of *b first, then the address);
 *  - the 14 gp-relative scalars (D_L32_001DE...) carry `.extern X, 4` hints, because under @ps2as the default
 *    assembler's automatic small-data addressing is gone;
 *  - `s32 v68 = *(s32 *)(c + 0x68);` is read before the null tests: retail's lw 0x68($v0) sits in the delay slot of
 *    the first beqz, which only happens when the load is in the same block as that branch.
 * To land it the file needs @ps2as: the function sits alone with func_L32_003A0BB8 in L32_003A0BB8.c, so cut it
 * into its own file at 0x003A0C18 (8-aligned) with the flag line `-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as`
 * and keep the first function in the old file.
 * Still differs (2 words): retail issues `lbu $v0,D_L32_001DE74C($gp)` before `mtc1 $zero,$f12` for the call to
 * func_003824E0, this C the other way round. In sched1 the lbu waits for the store `sw $v0,4($s0)` (a true
 * dependence of cost 2) and the mtc1 takes its slot; retail has no such delay. Tried, all 2 diff: the +4 store as
 * a struct member, through a temporary, the byte load in the if condition, as u32, a variable for the 0.0f; `const`
 * on D_L32_001DE74C removes the dependence but hoists the load above the func_0038DBD8 call (6 diff). */
typedef int u128_t __attribute__((mode(TI)));
__asm__(".extern D_L32_001DE75C, 4");
__asm__(".extern D_L32_001DE734, 4");
__asm__(".extern D_L32_001DE73C, 4");
__asm__(".extern D_L32_001DE738, 4");
__asm__(".extern D_L32_001DE744, 4");
__asm__(".extern D_L32_001DE740, 4");
__asm__(".extern D_L32_001DE74C, 4");
__asm__(".extern D_L32_001DE770, 4");
__asm__(".extern D_L32_001DE754, 4");
__asm__(".extern D_L32_001DE750, 4");
__asm__(".extern D_L32_001DE758, 4");
__asm__(".extern D_L32_001DE774, 4");
__asm__(".extern D_L32_001DE778, 4");
__asm__(".extern D_L32_001DE748, 4");

extern u8 D_L32_001E2280[8];
extern u8 D_L32_001E22A0[8];
extern u8 *D_L32_0021FAF8[];
extern f32 D_L32_001DE75C; extern s32 D_L32_001DE734; extern s32 D_L32_001DE73C; extern s32 D_L32_001DE738;
extern s32 D_L32_001DE744; extern s32 D_L32_001DE740; extern u8 D_L32_001DE74C; extern s32 D_L32_001DE770;
extern f32 D_L32_001DE754; extern f32 D_L32_001DE750; extern f32 D_L32_001DE758; extern f32 D_L32_001DE774;
extern f32 D_L32_001DE778; extern f32 D_L32_001DE748;
void func_L30_0034C958(void *, f32);
s32 func_0038DBD8(f32, s32, s32);
f32 func_003824E0(f32, f32);
f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
f32 func_003C4088(f32, f32, f32);

void func_L32_003A0C18(u8 *a, u8 *b) {
    if (b != 0) {
        u8 *c = *(u8 **)b;
        u8 *arr = D_L32_001E2280;
        s32 v68 = *(s32 *)(c + 0x68);
        if (c != 0 && v68 != 0 && arr != 0) {
            f32 f22, f20;
            if (b[9] & 1) {
                *(u128_t *)(a + 0x20) = *(u128_t *)D_L32_001E22A0;
                func_L30_0034C958(a + 0x20, D_L32_001DE75C);
                *(s32 *)(a + 0xC) = D_L32_001DE734;
                {
                    u16 h = *(u16 *)(b + 0xA);
                    f32 t = (f32)((h & 0xFF0) >> 4) * 0.00390625f;
                    s32 x, y;
                    if (h & 1) { x = D_L32_001DE73C; y = D_L32_001DE738; }
                    else { x = D_L32_001DE744; y = D_L32_001DE740; }
                    *(s32 *)(a + 4) = func_0038DBD8(t, x, y);
                }
                                a[3] = D_L32_001DE74C;
                if (func_003824E0(0.0f, 1.0f) < 0.5f) {
                    a[2] = D_L32_0021FAF8[0][D_L32_001DE770];
                }
            }
            f22 = func_L03_0034B440(1, 0, 0, (f32)*(s16 *)(a + 0xA), (f32)(b[8] << 2), 1.0f);
            *(u128_t *)(a + 0x10) = *(u128_t *)(a + 0x20);
            f20 = func_003C4088(D_L32_001DE754, D_L32_001DE750, (f32)(*(u16 *)(b + 0xA) >> 8) * 0.00390625f);
            f20 *= func_003C4088(1.0f, D_L32_001DE758, f22);
            {
                f32 g = D_L32_001DE774;
                f32 g2 = D_L32_001DE778;
                f32 r;
                *(f32 *)(a + 0x18) += f20;
                r = func_003C4088(g, g2, (f32)b[0xA] * 0.00390625f);
                *(f32 *)(a + 0x2C) = D_L32_001DE748;
                *(f32 *)(a + 0x1C) = r * (1.0f - f22);
            }
        }
    }
}
