/* Level 7 near miss: 31 differences, all in the loop test/junction block.
   Instructions, frame and register assignment match; sched1 moves five address/
   argument instructions from the if body up before the beqz, so the delay slot
   holds i++ instead of retail's addu. With a file-level -fno-sched-interblock it
   drops to 18; that is a scheduler-tie class already recorded. Not linked. */
extern void func_003C2F58(u8 *a, s32 b, f32 *out);

void func_L07_003AD088(void *arg0) {
    u8 *s = *(u8 **)((u8 *)arg0 + 0x68);
    u8 *a = s + 0x560;
    u8 *p = s + 0x562;
    u8 *q = s + 0x420;
    s32 i = 0;
    s32 ten = 10;
    s32 v;

    for (; i < 2; i++) {
        if ((s[0x567] >> i) & 1) {
            u8 *t = s + 0x562;

            v = p[-2] + 1;
            p[-2] = v;
            if ((u8)v >= 11) {
                p[-2] = ten;
                p[0] = (p[0] + 1) % ten;
            }
            func_003C2F58(arg0, i, (f32 *)(q + ((t[i] + a[i] - 1) % ten) * 16));
        }
        q += 0xA0;
        p++;
    }
}
