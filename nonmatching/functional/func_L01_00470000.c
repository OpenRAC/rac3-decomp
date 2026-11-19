/* functional: high. Per-frame update of an effect attached to a target object: counts its model byte up; when the target is gone (null or dead flag 0xFE/0xFD) it runs the fade helper and frees itself when done; otherwise it ramps its alpha (top byte of the colour word) up or down by 4 depending on the target's flags, and puts itself at the target's position or at an attach point of the target (offset toward D_L01_001E29C0 by 0.4). */
extern vu0_v4 D_L01_001E29C0;
extern void func_003C2F58(void *target, s32 id, void *out);

void func_L01_00470000(u8 *o) {
    u8 *q;
    u8 *t;
    s32 w4;
    s32 a;
    s32 b;
    s32 h;
    vu0_v4 v0;
    vu0_v4 v10;

    if (o == 0) {
        return;
    }
    o[8] = o[8] + 1;
    q = o + 0x20;
    t = *(u8 **)q;
    if (t == 0 || t[0x20] == 0xFE || t[0x20] == 0xFD) {
        if (func_L01_00445EA8(o + 4, 4) != 0) {
            func_003CD250((Obj *)o);
        }
        return;
    }
    w4 = *(s32 *)(o + 4);
    a = w4 >> 24;
    b = (s8)q[0xB];
    if (t[0x31] != 0) {
        if ((*(u16 *)(t + 0x34) & 2) != 0) {
            a = a - 4;
            if (a < 0) {
                a = 0;
            }
        } else if (a < b) {
            a = a + 4;
            if (b < a) {
                a = b;
            }
        }
    } else {
        a = a - 4;
        if (a < 0) {
            a = 0;
        }
    }
    *(s32 *)(o + 4) = (w4 & 0xFFFFFF) | (a << 24);
    h = *(s16 *)(q + 6);
    if (h == -1) {
        *(vu0_v4 *)(o + 0x10) = *(vu0_v4 *)(*(u8 **)q + 0x10);
        return;
    }
    func_003C2F58(*(u8 **)q, h, &v0);
    vec_sub_ba(&v10, &D_L01_001E29C0, &v0);
    func_0038CF68(&v10, &v10, 0.4f);
    vec_add_ab(o + 0x10, &v0, &v10);
}
