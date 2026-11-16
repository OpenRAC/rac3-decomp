/* Resolved in the third retry on 2026-11-15: integrated in L07_003BCDD0.c.
   Full PAL level build MATCH (21 to 0); see the README row. This earlier
   draft is retained as historical evidence (its func_003C2F58 prototype
   predates the owning file's f32 * declaration). */
/* Level 7 near miss: 21 differences, localized to the argument region: the
   addiu for s+0x4F2 lands in the beqz delay slot where retail has addu, and two
   sum temporaries take $v0/$v1 instead of $a2/$v0. Scheduler-tie / cse-base
   class already recorded; the shared scheduler-tie draft stays. Not linked. */
extern void func_003C2F58(void *, s32, void *);

void func_L07_003BE9B8(u8 *arg0) {
    u8 *s = *(u8 **)(arg0 + 0x68);
    u8 *p = s + 0x4F2;
    u8 *q = s + 0x4F0;
    s32 ten = 10;
    s32 i;

    for (i = 0; i < 2; i++) {
        if ((s[0x4FB] >> i) & 1) {
            u8 *r = s + 0x4F2;
            u8 v = p[i - 2] + 1;

            p[i - 2] = v;
            if (v > 10) {
                p[i - 2] = ten;
                p[i] = (p[i] + 1) % ten;
            }
            func_003C2F58(arg0, i, s + 0x3B0 + i * 0xA0 + ((q[i] + r[i] - 1) % ten) * 16);
        }
    }
}
