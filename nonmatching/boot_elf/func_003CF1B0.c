/* US draft of func_003CF1B0 (rac3-uya-decomp func_003CF048, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */

/* localdecomp:start func_003CF1B0 */
extern f32 D_001DA670[];
extern s32 D_001DA680[];
extern f32 D_00225B30[];
extern f32 D_00334FB0[];
extern void func_0038CF80();
void func_003CF1B0(void) {
    f32 *v = D_001DA670;
    f32 s = D_00225B30[0];
    f32 a, ar1, b, c, r1, r2;
    b = v[1] * s;
    a = v[0] * s;
    r1 = 1.0f / (a - b);
    ar1 = a * r1;
    D_001DA680[0] = (s32)(v[0] * 1024.0f);
    D_001DA680[1] = (s32)(v[1] * 1024.0f);
    c = v[2] * s;
    D_001DA680[2] = (s32)(v[2] * 1024.0f);
    r2 = 1.0f / (b - c);
    func_0038CF80(D_00334FB0, 0x40);
    D_00334FB0[13] = b * r2;
    D_00334FB0[3] = a;
    D_00334FB0[9] = ar1;
    D_00334FB0[0] = r1 * 0.5f;
    D_00334FB0[1] = -r1;
    D_00334FB0[8] = b * r1 * -0.5f;
    D_00334FB0[4] = r2 * 0.5f;
    D_00334FB0[7] = b;
    D_00334FB0[5] = -r2;
    D_00334FB0[12] = c * r2 * -0.5f;
}
/* localdecomp:end func_003CF1B0 */
