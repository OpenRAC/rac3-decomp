/* US draft of func_003AF660 (rac3-uya-decomp func_003AA0B8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003AF660 */
typedef s32 (*FN_AA0B8)();
typedef struct { s32 a; FN_AA0B8 f; } E_AA0B8;
typedef struct { u8 pad[0x24DCC]; void (*cb24DCC)(); u8 pad2[0x1C]; FN_AA0B8 cb24DEC; E_AA0B8 e1[4]; E_AA0B8 e2[3]; } P_AA0B8;
extern P_AA0B8 *D_001D5C78_003AF660;
extern s32 D_001D9EC0;
extern s32 D_001D5B94;
typedef struct { u8 p0[0xB0]; f32 fB0; } G_AA0B8;
extern G_AA0B8 D_00225900[];
extern void func_00397BE0();
extern s32 func_003E13F0();
extern void func_003873C0();
extern void func_003AF628();
void func_003AF660(void) {
    s32 r, i, t;
    E_AA0B8 *e;
    G_AA0B8 *g;
    f32 sv;
    if (D_001D9EC0 == 0) {
        if (D_001D5C78_003AF660 != 0) {
            func_00397BE0();
            r = 0;
            if (D_001D5C78_003AF660->cb24DEC != 0) r = D_001D5C78_003AF660->cb24DEC() != 0;
            for (i = 0; i < 4; i++) {
                if (D_001D5C78_003AF660->e1[i].f != 0) {
                    E_AA0B8 *e2 = (E_AA0B8 *)(i * 8 + (s32)D_001D5C78_003AF660 + 0x24DF0);
                    r |= e2->f();
                }
            }
            for (i = 0; i < 3; i++) {
                if (D_001D5C78_003AF660->e2[i].f != 0) {
                    E_AA0B8 *e3 = (E_AA0B8 *)(i * 8 + (s32)D_001D5C78_003AF660 + 0x24E10);
                    r |= e3->f();
                }
            }
            if (r != 0) return;
        }
        t = D_001D5B94;
        if (t != 0x11 && t != 0 && t != 5 && t == 4) {
            if (func_003E13F0() != 7) return;
        }
        if (D_001D5C78_003AF660 != 0) {
            D_001D5C78_003AF660->cb24DCC();
            g = D_00225900;
            sv = g->fB0;
            g->fB0 = 0.62f;
            func_003873C0();
            func_003AF628();
            g->fB0 = sv;
            func_003873C0();
        }
    }
}
/* localdecomp:end func_003AF660 */
