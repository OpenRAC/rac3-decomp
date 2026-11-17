/* func_L14_00362868: near miss, 22 diff, one cause: $s0/$s1 swapped between the counter n and a0 (file has the VU0 + @ps2as set since func_L14_003622D0); block layout, constants and tables match. global-alloc ranks a0 (17 refs over 68 insns) above n (29 over 130); 27 loop wordings (while, if + do-while, goto loops, outer do/while/goto) tried, the first inner loop as while and the second as if + do-while is the only shape that reaches 22
   Level 14 (Koros) only; flags of its file in config/levels/text_parts.txt. */
typedef s32 (*S_362868_fn)(u8 *, u8 *);
typedef struct {
    S_362868_fn f[7];
} S_362868_tab;
__asm__(".extern D_L14_001DD8E8, 8");
extern S_362868_fn D_L14_001DD8E8[2];
extern S_362868_tab D_L14_001DD8F8;
s32 func_L14_00362868(u8 *a0, u8 *a1) {
    S_362868_tab tab;
    s32 n;
    s32 r;
    tab = D_L14_001DD8F8;
    n = 0;
    r = 0;
    do {
        if (D_L14_001DD8E8[a0[0x95]] != 0) {
            while (n < 5) {
                r = D_L14_001DD8E8[a0[0x95]](a0, a1);
                switch (r) {
                case 4:
                    return 1;
                case 5:
                    return 0;
                case 2:
                    n++;
                    continue;
                }
                break;
            }
            if (r == 3) {
                goto next;
            }
        }
        if (tab.f[a0[0x20]] == 0) {
            break;
        }
            if (n < 5) {
                do {
                r = tab.f[a0[0x20]](a0, a1);
                switch (r) {
                case 4:
                    return 1;
                case 5:
                    return 0;
                case 2:
                    n++;
                    continue;
                }
                break;
                } while (n < 5);
            }
        if (r != 3) {
            break;
        }
    next:
        n++;
    } while (n < 5);
    return 1;
}
