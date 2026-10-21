/* US draft of func_003A2028 (rac3-uya-decomp func_003A1EE8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003A2028 */
typedef struct {
    u8 p0[0x2C]; s16 f2C; u8 p2E[0xE]; s16 f3C; s16 f3E; u8 p40[4];
    s32 f44; s16 f48; u8 p4A[2]; s16 f4C; s16 f4E; u8 p50[0x1C];
    s32 f6C; u8 p70[4]; s16 f74; s16 f76; u8 p78[0x1C];
    s32 f94; u8 p98[4]; s16 f9C; s16 f9E; u8 pA0[0x1C];
    s32 fBC; u8 pC0[4]; s16 fC4; s16 fC6;
} S_1CCFD0_39CBA0;
__asm__(".extern D_001D6DB8_003A2028, 4");
extern S_1CCFD0_39CBA0 D_1CCFD0_003A2028;
extern s32 D_001D6DB8_003A2028;
extern s32 D_001D9FF0_003A2028;
extern s32 func_13B620_003A2028();
extern void func_13CA28(void);
extern void func_13CAE8();
extern s32 func_12C908(s32);
extern void func_13CD00();
void func_003A2028(void) {
    S_1CCFD0_39CBA0 *s;
    s32 t;
    D_001D6DB8_003A2028 = 1;
    D_001D9FF0_003A2028 = 0xB4;
    func_13CA28();
    func_13CAE8();
    while (func_13B620_003A2028() != 0) {
        func_12C908(0);
        t = D_001D9FF0_003A2028;
        if (t == 0) {
            break;
        }
        D_001D9FF0_003A2028 = t - 1;
    }
    func_13CD00(1);
    s = &D_1CCFD0_003A2028;
    s->f4E = 0;
    s->f4C = 0;
    s->f44 = 0;
    if (s->f3C != -1) {
        s->f48 = s->f3C;
    }
    s->f76 = 0;
    s->f74 = 0;
    s->f6C = 0;
    s->f9E = 0;
    s->f9C = 0;
    s->f94 = 0;
    s->fC6 = 0;
    s->fC4 = 0;
    s->fBC = 0;
    s->f2C = 0;
    s->f3C = -1;
    s->f3E = -1;
    D_001D6DB8_003A2028 = 0;
}
/* localdecomp:end func_003A2028 */
