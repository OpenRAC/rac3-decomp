/* functional: high. Read against the PAL asm (all calls, args, vector ops match). Added two spare vector locals so the stack frame is retail's 0xF0 (the gate sees stack addresses); otherwise register allocation differs only. */
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_L01_003F8F48(u8 *a0, u8 *a1, u8 *a2);

void func_L01_003F8620(u8 *self) {
    vu0_v4 L[9]; vu0_v4 padx[2];
    u8 *m = *(u8 **)(self + 0x68);
    u8 *mat;
    u8 *pos;

    if (m[0x5C] >= 2) {
        u8 *base = *(u8 **)(m + 0x30);
        func_0038CDF8(&L[0], base + (m[0x59] << 4), base + (m[0x5A] << 4), 0.5f);
        mat = self + 0xC0;
        vec_sub_ab(&L[4], base + (m[0x59] << 4), base + (m[0x5A] << 4));
        func_0038D000(&L[4], &L[4], mat);
    } else {
        mat = self + 0xC0;
        *(vu0_q *)&L[0] = *(vu0_q *)(*(u8 **)(m + 0x30) + (m[0x59] << 4));
    }
    pos = m + 0x10;
    func_0038D000(&L[1], &L[0], mat);
    func_003C5180(self + 0x10, &L[5], 1);
    vec_sub_ab(&L[6], &L[0], m + 0x20);
    func_0038D000(&L[6], &L[6], mat);
    func_0038CF68(&L[6], &L[6], 1.0f);
    func_0038CE90(&L[7], &L[6], &L[5]);
    func_0038CF68(&L[7], &L[7], *(f32 *)(m + 0x4C));
    func_L01_003F8E78(self, pos, &L[7]);
    if (m[0x5C] >= 2) {
        func_L01_003F8F48(self, pos, (u8 *)&L[4]);
    }
    func_0038D810(pos, &L[8]);
    func_0038D5F0(mat, &L[8], mat);
    func_0038D000(&L[2], &L[0], mat);
    vec_sub_ba(&L[3], &L[2], &L[1]);
    vec_sub_ab(self + 0x10, self + 0x10, &L[3]);
}
