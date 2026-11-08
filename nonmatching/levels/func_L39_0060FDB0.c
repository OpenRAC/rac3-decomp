/* func_L39_0060FDB0: near miss (w3 p2w2): MATCH at level 39 only; levels 40-53 use other gp offsets (0x1260/0x1298 vs 0x4D50/0x4D88), false fold.
   Static-init idiom: 2-element 0x1C array in sdata (declare as u8[8] to get addiu gp). */
extern u8 D_001E1600_sda[8];
extern s32 D_001E1638_sda;
extern void func_003F2208(void *p);
extern void func_118ED0(void *f);
extern void func_003E68C0(void);

void *func_L39_0060FDB0(s32 n) {
    s32 i;
    if (D_001E1638_sda == 0) {
        u8 *p = D_001E1600_sda;
        for (i = 1; i != -1; i--) {
            func_003F2208(p);
            p += 0x1C;
        }
        D_001E1638_sda = 1;
        func_118ED0(func_003E68C0);
    }
    return D_001E1600_sda + n * 0x1C;
}
