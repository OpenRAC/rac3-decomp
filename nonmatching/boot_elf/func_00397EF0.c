/* US draft of func_00397EF0 (rac3-uya-decomp func_00397E08, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_00397EF0 */
typedef struct {
    u8 pad0[8]; s32 f8; s32 *fC; u8 pad10[0x5C]; s32 f6C; u8 b[2]; u8 pad72[2]; s32 f74; u8 pad78[4]; s32 f7C;
} S_3932B0;
void func_00397EF0(S_3932B0 *p) {
    u8 *b = p->b;
    s32 t = *p->fC;
    s32 a = p->f8;
    p->f74 = t;
    if (a < t) {
        p->f74 = a;
    } else if (t < 0) {
        p->f74 = 0;
    }
    if (p->f7C >= 5) {
        p->f7C = 5;
        if (b[0] < 8) {
            b[0]++;
        } else if (b[1] < 8) {
            b[1]++;
        }
    } else {
        p->f6C = 1;
        if (b[1] != 0) {
            b[1]--;
        } else if (b[0] != 0) {
            b[0]--;
        } else {
            p->f6C = -6;
        }
    }
}
/* localdecomp:end func_00397EF0 */
