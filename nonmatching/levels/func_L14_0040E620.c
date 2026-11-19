/* func_L14_0040E620: 80 diff with the file's flags. Remaining: the order of the first instructions (retail computes &D_001D6AB0_sda and the 1.0f store before the D_001D545C load, and sd $ra before the lui of D_001D545C), register choice ($a0/$v1/$t0 for the address, D_001D545C and the constant 1), and the placement of the pointer locals C/E/G (retail loads them with lui+addiu when used). Divisions are div by a register holding 6, which this C gives too (the constant divisor is folded as in retail). Tried: 4 statement orders. */
extern u8 D_001D6AB0_sda;
extern u8 D_001D6AA5_sda;
extern f32 D_001D6B44_sda;
extern u8 D_001D7170_sda;
extern s32 D_001D545C[];
extern u8 D_L14_002E85E0[];
extern u8 D_L14_001E6480[];
extern u8 D_L14_002E8750[];
extern u8 D_L14_002E8690[];
extern u8 D_L14_002E8630[];
extern u8 D_L14_002E86F0[];
extern void func_L01_00423068(u8 *, u8 *, s32, s32, s32, s32, s32);

void func_L14_0040E620(void)
{
    u8 *q = 0;
    u8 *p5 = 0;
    u8 *A = D_L14_002E85E0;
    u8 *C;
    u8 *E;
    u8 *G;
    s32 v7, x, y, z, w;

    D_001D6B44_sda = 1.0f;
    *(s32 *)(A + 0x20) = (s32)&D_001D6AB0_sda;
    *(s32 *)(A + 0x30) = 1;
    if (D_001D545C[0] == 14) {
        D_001D6AA5_sda = 0;
        if (*(s32 *)(D_L14_001E6480 + 0x30) == 1) {
            C = D_L14_002E8750;
            v7 = *(s32 *)(D_L14_001E6480 + 0x34);
            x = *(s32 *)(C + 0x38);
            y = *(s32 *)(C + 0x3C);
            if (v7 < (x * 5 + 2) / 6 || (y * 5 + 2) / 6 < v7) {
                E = D_L14_002E8690;
                z = *(s32 *)(E + 0x38);
                if (v7 < (z * 5 + 2) / 6) {
                    q = D_L14_002E8630;
                } else {
                    G = D_L14_002E86F0;
                    w = *(s32 *)(G + 0x38);
                    if (v7 < (w * 5 + 2) / 6) {
                        q = E;
                    } else {
                        q = G;
                    }
                }
            } else {
                p5 = &D_001D7170_sda;
                q = C;
            }
        }
    }
    if (q != 0) {
        func_L01_00423068(q, p5, 0, 0, 0, 1, 0);
    }
}

INCLUDE_ASM("asm/levels", func_L14_0040E620);
