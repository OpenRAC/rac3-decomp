/* functional: high. Same calls, args and order as retail; byte layout differs (157 instrs differ, structure matches). abs written as sign branch. */
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L06_00352E20(void *, s32, s32, void *);
extern void func_L06_0045B1F8(void *, void *, void *, void *);
extern f32 func_L06_0045B290(void *, s32, s32, f32, f32);

s32 func_L06_00355C20(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 buf[0x30];
    s32 dir;
    f32 f;
    f32 y0;
    f32 y1;
    s32 next;

    if (*(s32 *)(v + 0x36C) != 0x12 && *(s32 *)(v + 0x384) != 0) {
        func_L01_004450F0(a0, 0xC, -1);
        return 1;
    }
    if (*(s32 *)(v + 0x350) == func_L06_00352E20(v, 0, *(s32 *)(v + 0x344), buf)) {
        func_L06_0045B1F8(*(void **)(v + 0x358), a0 + 0x10, v + 0x344, v + 0x348);
    }
    f = *(f32 *)(v + 0x34C);
    dir = 0.0f <= f ? 1 : 0;
    if (0.0f <= f) {
        if (*(s32 *)(v + 0x344) < **(s32 **)(v + 0x358) - 1) {
            if (func_L06_00352E20(v, dir, *(s32 *)(v + 0x344), buf)) {
                if (!func_L06_00352E20(v, dir, *(s32 *)(v + 0x344) + 1, buf)) {
                    s32 k = *(s32 *)(v + 0x344);
                    *(f32 *)(v + 0x348) = 0.0f;
                    *(s32 *)(v + 0x344) = k + 1;
                }
            }
        }
    } else {
        if (*(s32 *)(v + 0x344) > 0) {
            if (func_L06_00352E20(v, dir, *(s32 *)(v + 0x344), buf)) {
                if (!func_L06_00352E20(v, dir, *(s32 *)(v + 0x344) - 1, buf)) {
                    s32 k = *(s32 *)(v + 0x344);
                    *(f32 *)(v + 0x348) = 0.0f;
                    *(s32 *)(v + 0x344) = k - 1;
                }
            }
        }
    }
    f = *(f32 *)(v + 0x34C);
    if (f < 0.0f) {
        f = -f;
    }
    if (f < 0.75f) {
        func_L01_004450F0(a0, 0xF, -1);
        return 1;
    }
    if (*(s32 *)(v + 0x36C) != 0 && func_0038CF38(v + 0x4A0, a0 + 0x10) < *(f32 *)(v + 0xA4)) {
        func_L01_004450F0(a0, 0xF, -1);
        return 1;
    }
    if (*(s32 *)(v + 0x350) != 0) {
        func_L01_004450F0(a0, 6, -1);
        return 1;
    }
    if (func_L06_00352E20(v, dir, *(s32 *)(v + 0x344), buf) == 0) {
        if (*(s32 *)(v + 0x36C) == 0x12 && *(s32 *)(v + 0x384) == 0) {
            func_L01_004450F0(a0, 0xB, -1);
        } else {
            func_L01_004450F0(a0, 4, -1);
        }
        return 1;
    }
    func_L06_00352E20(v, dir ^ 1, *(s32 *)(v + 0x344), buf + 0x10);
    func_L06_0045B1F8(*(void **)(v + 0x358), buf + 0x10, buf + 0x20, buf + 0x24);
    y0 = func_L06_0045B290(*(void **)(v + 0x358), *(s32 *)(v + 0x344), *(s32 *)(buf + 0x20), *(f32 *)(v + 0x348),
                           *(f32 *)(buf + 0x24));
    func_L06_00352E20(v, dir, *(s32 *)(v + 0x344), buf);
    func_L06_0045B1F8(*(void **)(v + 0x358), buf, buf + 0x28, buf + 0x2C);
    y1 = func_L06_0045B290(*(void **)(v + 0x358), *(s32 *)(v + 0x344), *(s32 *)(buf + 0x28), *(f32 *)(v + 0x348),
                           *(f32 *)(buf + 0x2C));
    if (y0 < 0.0f) {
        y0 = -y0;
    }
    if (y1 < 0.0f) {
        y1 = -y1;
    }
    if (y0 < y1) {
        if (*(s32 *)(v + 0x36C) == 0x12 && *(s32 *)(v + 0x384) == 0) {
            func_L01_004450F0(a0, 0xB, -1);
            return 1;
        }
        func_L01_004450F0(a0, 4, -1);
    }
    f = *(f32 *)(v + 0x30) / (f32) * (s16 *)(v + 0x34) - 0.001f;
    if (*(s32 *)(v + 0x36C) != 0 && *(f32 *)(v + 0x308) < f) {
        *(f32 *)(v + 0x34C) = 0.0f;
        func_L01_004450F0(a0, 0xF, -1);
        return 1;
    }
    if (*(s32 *)(v + 0x384) != 0) {
        func_L01_004450F0(a0, 0xC, -1);
    } else {
        func_L01_004450F0(a0, 5, -1);
    }
    return 1;
}
