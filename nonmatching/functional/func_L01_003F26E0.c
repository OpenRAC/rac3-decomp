/* functional: high. 37 instruction positions differ at L01 (scheduling of the argument move and update order); same reads, writes, calls. Callee out buffer is s32[2] (+0 amount, +4 aux byte). */
typedef struct { s32 amt; u8 aux; } R_3F26E0;
extern u8 D_001CD0C0[];
extern u8 D_001439FE[];
extern s32 D_001D5FC8_sda;
__asm__(".extern D_001D5FC8_sda, 4");
extern s32 func_L01_003F22D8(s32 *out, u8 *e);

void func_L01_003F26E0(void) {
    R_3F26E0 r;
    u8 *e = D_001CD0C0;
    s32 *acc = &D_001D5FC8_sda;
    s32 i;
    for (i = 0; i < 8; i++) {
        if (e[0x558] != 0) {
            func_L01_003F22D8((s32 *)&r, e);
            if (D_001439FE[i] != 0) {
                s32 t = *acc + r.amt;
                *acc = t;
                if (t >= 0x100) {
                    e[0x188] = 1;
                    *acc = t - 0xFF;
                } else {
                    e[0x188] = 0;
                }
                e[0x189] = r.aux;
            }
        } else {
            e[0x188] = 0;
            e[0x189] = 0;
        }
        acc++;
        e += 0x5C0;
    }
}
