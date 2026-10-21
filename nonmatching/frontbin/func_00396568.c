/* Near miss of func_00396568 with its file's own flags: tools/check.py reports 17 diff
   (the version it replaces: 69).
   What differs: 17 diff: base address of D_00331AE0 is materialised in the prologue (lui
   $s0,%hi / addiu $s0,$s0,%lo) instead of after the call in retail's split form (lui $v0,%hi /
   addiu $s0,$v0,%lo), which also shifts the register allocation of the loop end pointer ($s5
   vs retail $s3) and of the constant 8 ($s3 vs retail $s5); everything else (lui/lw access to
   D_001D9E8C, constant 8 instead of 10, loop body, delay slots) matches.
*/

/* PAL candidate for func_00396568.
   Base: the US draft (rac3-uya-decomp func_00391D08) with the PAL differences applied:
   - the clamp constant is 8, not 10 (retail: slti $v0,$v0,8 and sw of 8),
   - D_001D9E8C is read with lui/lw in retail, so it is an unsized array (never small data),
   - the 8 is a literal (retail materialises it in the call's delay slot), -6 stays a
     variable initialised before the call (retail: addiu $s4,$zero,-6 before the jal).
   Still off (17 diff): the base address of D_00331AE0 is materialised in the prologue
   (lui $s0,%hi / addiu $s0,$s0,%lo) instead of after the call in retail's split form
   (lui $v0,%hi / addiu $s0,$v0,%lo), and that shifts the register allocation of the
   loop end pointer ($s5 here, $s3 in retail) and of the constant 8 ($s3 here, $s5 in
   retail). */

/* localdecomp:start func_00396568 */
typedef struct S_391D08 {
    s32 f0;
    s32 f4;
    u8 p8[0xC];
    void (*f14)(struct S_391D08 *);
    u8 p18[0x50];
    s32 f68;
    s32 f6C;
    u8 p70[0xC];
    s32 f7C;
    u8 p80[0x10];
} S_391D08;
extern S_391D08 D_00331AE0_00396568[];
extern s32 D_001D9E8C[];
extern void func_003966D8();
extern void func_00393450();
s32 func_00396568(s32 a0) {
    S_391D08 *s;
    s32 i;
    s32 cnt = 0;
    s32 t;
    s32 m6 = -6;
    func_003966D8();
    for (i = 0; i < 13; i++) {
        s = &D_00331AE0_00396568[i];
        if ((s->f4 & 0x10) || D_001D9E8C[0]) {
            if (s->f7C < 8) {
                s->f7C = 8;
            }
        }
        t = s->f7C;
        if (t > 0) {
            t--;
            s->f7C = t;
            if (t > 0) {
                cnt++;
                if (s->f6C < 30) {
                    s->f6C = s->f6C + 1;
                }
                goto skip;
            }
        }
        if (s->f6C >= -5) {
            s->f6C = s->f6C - 1;
        }
skip:
        if (s->f68 != 0 && s->f6C == m6) {
            func_00393450(s);
        }
        if (a0 != 0 && s->f14 != 0) {
            s->f14(s);
        }
    }
    return cnt;
}
/* localdecomp:end func_00396568 */
