/* US draft of func_00396948 (rac3-uya-decomp func_00396860, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_00396948 */
// near miss: 17 diff, N mode default flags; only regalloc: retail s3=end,s4=-6,s5=10 and lui/addiu of D_00331AE0 after the jal; mine s3=10,s4=-6,s5=end and base before jal
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
extern S_391D08 D_00331AE0_00396948[];
extern s32 D_001D9E8C_00396948;
extern void func_00396AB8();
extern void func_00393830();
s32 func_00396948(s32 a0) {
    S_391D08 *s;
    s32 i;
    s32 cnt = 0;
    s32 t;
    s32 ten = 10;
    s32 m6 = -6;
    func_00396AB8();
    for (i = 0; i < 13; i++) {
        s = &D_00331AE0_00396948[i];
        if ((s->f4 & 0x10) || D_001D9E8C_00396948) {
            if (s->f7C < 10) {
                s->f7C = ten;
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
            func_00393830(s);
        }
        if (a0 != 0 && s->f14 != 0) {
            s->f14(s);
        }
    }
    return cnt;
}
/* localdecomp:end func_00396948 */
