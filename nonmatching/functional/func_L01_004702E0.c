/* functional: medium. Per-frame update of a lens-flare/glint style sprite tied to a target object. Frees itself when its life ends or the target's signed byte at +0x20 is negative. Places itself at the target (q+4 >= 0: at the target's attach point q+4 plus offset; q+4 < 0: at the target position plus the offset rotated by the target's matrix, with the model byte from the distance to D_L01_001E29C0+0x20 when q[0xE] is set). Then, by mode q[0xC] (1 = direction away from the camera point D_L01_001E29C0, 2..7 = +-X/Y/Z axis of the target's matrix rows 0xC0/0xD0/0xE0), fades its alpha by how closely the view direction lines up with that axis (dot * -1.25 + 0.05, clamped 0..1; below 0 it zeroes the colour's top bits), scales its size by q+0x1C, advances its model byte and nudges the position along the vector toward D_L01_001E29C0. Mode >= 8 uses an uninitialised direction in retail; zero is used here. The switch's jump table was not inspected: cases 1..7 are mapped in the code's block order. */
extern vu0_v4 D_L01_001E29C0;
extern void func_003C2EC0(void *, s32, void *);
extern f32 func_0038CE68(void *, void *);

void func_L01_004702E0(u8 *o) {
    u8 *q = o + 0x20;
    u8 *t;
    vu0_v4 m[4];
    vu0_v4 v10;
    vu0_v4 dir;
    vu0_v4 w0;
    f32 f3;
    s32 c;
    s32 a;
    s32 w4;
    s32 i4;

    if (*(s16 *)(o + 0xA) < 0 || func_0038CB00((s16 *)(o + 0xA)) == 0) {
        t = *(u8 **)q;
        if (t == 0) {
            *(vu0_v4 *)(o + 0x10) = *(vu0_v4 *)(q + 0x10);
            goto common;
        }
        if ((s8)t[0x20] >= 0) {
            i4 = *(s32 *)(q + 4);
            if (i4 >= 0) {
                func_003C2EC0(t, i4, m);
                func_0038D000(o + 0x10, q + 0x10, m);
                vec_add_ab(o + 0x10, o + 0x10, &m[3]);
                *(f32 *)(o + 0x1C) = 0.0f;
                goto common;
            }
            *(vu0_v4 *)(o + 0x10) = *(vu0_v4 *)(t + 0x10);
            func_0038D000(&w0, q + 0x10, t + 0xC0);
            vec_add_ab(o + 0x10, o + 0x10, &w0);
            if (q[0xE] != 0) {
                vec_sub_ba(&v10, o + 0x10, &D_L01_001E29C0);
                o[8] = (s32)(func_0038CE68(&v10, (u8 *)&D_L01_001E29C0 + 0x20) * 6.0f);
            }
            c = q[0xC];
            if (c == 0) {
                goto common;
            }
            dir.x = dir.y = dir.z = dir.w = 0.0f;
            switch (c) {
            case 1:
                vec_sub_ab(&dir, o + 0x10, t + 0x10);
                func_0038CF68(&dir, &dir, 1.0f);
                break;
            case 2:
                dir = *(vu0_v4 *)(t + 0xC0);
                break;
            case 3:
                dir = *(vu0_v4 *)(t + 0xC0);
                vec_neg(&dir, &dir);
                break;
            case 4:
                dir = *(vu0_v4 *)(t + 0xD0);
                break;
            case 5:
                dir = *(vu0_v4 *)(t + 0xD0);
                vec_neg(&dir, &dir);
                break;
            case 6:
                dir = *(vu0_v4 *)(t + 0xE0);
                break;
            case 7:
                dir = *(vu0_v4 *)(t + 0xE0);
                vec_neg(&dir, &dir);
                break;
            }
            vec_sub_ba(&v10, o + 0x10, &D_L01_001E29C0);
            func_0038CF68(&v10, &v10, 1.0f);
            f3 = -func_0038CE68(&v10, &dir) * 1.25f + 0.05f;
            if (f3 < 0.0f) {
                *(s32 *)(o + 4) = *(s32 *)(o + 4) & 0x05FFFFFF;
                goto common;
            }
            if (1.0f < f3) {
                f3 = 1.0f;
            }
            w4 = *(s32 *)(o + 4);
            if (q[0xF] != 0) {
                a = (u32)(w4 & 0xFF000000) >> 24;
                *(s32 *)(o + 4) = (w4 & 0xFFFFFF) | ((s32)((f32)a * f3) << 24);
            } else {
                *(s32 *)(o + 4) = (w4 & 0xFFFFFF) | ((s32)(f3 * 255.0f) << 24);
            }
common:
            *(f32 *)(o + 0xC) = *(f32 *)(o + 0xC) * *(f32 *)(q + 0x1C);
            o[8] = o[8] + q[0xD];
            vec_sub_ba(&w0, &D_L01_001E29C0, o + 0x10);
            func_0038CF68(&w0, &w0, *(f32 *)(q + 8));
            vec_add_ab(o + 0x10, o + 0x10, &w0);
            return;
        }
    }
    func_003CD250((Obj *)o);
}
