/* functional: high. 159 instruction positions differ at L01 (frame 0xf0 vs 0x100, retail spills idx to the stack, merged duplicate m[0x5C] decrement); same call order and arguments, same compares. Needs vu0.h (already in this file's prelude). */
extern f32 func_0038CE68(f32 *, f32 *);
void func_L01_003F8BE0(u8 *self, s32 idx, void *dir) {
    vu0_v4 L[9];
    u8 *m = *(u8 **)(self + 0x68);
    u8 *list = m + 0x59;
    u8 *entry = list + idx;
    u8 *cur;
    u8 *t;
    s32 i = 0;
    s32 off;
    f32 f;

    func_0038D000(&L[0], *(u8 **)(m + 0x30) + (*entry << 4), self + 0xC0);
    f = func_0038CE68((f32 *)dir, (f32 *)&L[0]);
    func_0038CF68(&L[4], dir, f);
    vec_sub_ab(&L[0], &L[0], &L[4]);
    if (m[0x5C] != 0) {
        cur = list;
        off = 0;
        do {
            if (*cur == idx) {
                *(vu0_q *)&L[1 + i] = *(vu0_q *)&L[0];
            } else {
                u8 *base = *(u8 **)(m + 0x30);
                vec_sub_ba(&L[1 + i], base + (*cur << 4), base + (*entry << 4));
                func_0038D000(&L[1 + i], &L[1 + i], self + 0xC0);
                f = func_0038CE68((f32 *)dir, (f32 *)&L[1 + i]);
                func_0038CF68(&L[4], dir, f);
                vec_sub_ab(&L[1 + i], &L[1 + i], &L[4]);
                if (func_0038CE68((f32 *)&L[1 + i], (f32 *)&L[0]) > 0.0f) {
                    *cur = list[m[0x5C] - 1];
                    m[0x5C] = m[0x5C] - 1;
                }
            }
            i++;
            cur++;
        } while (i < m[0x5C]);
    }
    if (m[0x5C] == 3) {
        func_0038CE90(&L[5], &L[1], &L[3]);
        func_0038CE90(&L[6], &L[2], &L[3]);
        func_0038CE90(&L[7], &L[1], &L[2]);
        func_0038CE90(&L[8], &L[2], &L[1]);
        if (func_0038CE68((f32 *)&L[5], (f32 *)&L[7]) < 0.0f) {
            m[0x5C] = m[0x5C] - 1;
            m[0x5A] = m[0x5B];
        } else if (func_0038CE68((f32 *)&L[6], (f32 *)&L[8]) < 0.0f) {
            m[0x5C] = m[0x5C] - 1;
            m[0x59] = m[0x5B];
        }
    }
}
