/* functional: high. Written from PAL asm; five placement modes (1,2,3 copy a slot of the target model, 4 copies the target position plus 0.2 in z, else integrate velocity), twice bounds checked. */
extern f32 func_L01_00443A18(f32, f32);
void func_L01_0046D980(u8 *p) {
    u8 *v = p + 0x20;
    f32 *pos = (f32 *)(p + 0x10);
    s32 mode;
    s32 sum;
    if (pos[0] < 2.0f || pos[0] > 1021.0f || pos[1] < 2.0f || pos[1] > 1021.0f || pos[2] < 2.0f || pos[2] > 1021.0f) {
        func_003CD250((Obj *)p);
        return;
    }
    mode = *(s16 *)(v + 0x16);
    if (mode == 1) {
        *(vu0_q *)pos = *(vu0_q *)(*(u8 **)(*(u8 **)(v + 0x1C) + 0x68) + 0xE0);
    } else if (mode == 3) {
        *(vu0_q *)pos = *(vu0_q *)(*(u8 **)(*(u8 **)(v + 0x1C) + 0x68) + 0xF0);
    } else if (mode == 2) {
        *(vu0_q *)pos = *(vu0_q *)(*(u8 **)(*(u8 **)(v + 0x1C) + 0x68) + 0x200);
    } else if (mode == 4) {
        *(vu0_q *)pos = *(vu0_q *)(*(u8 **)(v + 0x1C) + 0x10);
        pos[2] = pos[2] + 0.2f;
    } else {
        pos[0] = pos[0] + ((f32 *)v)[0];
        pos[1] = pos[1] + ((f32 *)v)[1];
        pos[2] = pos[2] + ((f32 *)v)[2];
    }
    if (pos[0] < 2.0f || pos[0] > 1021.0f || pos[1] < 2.0f || pos[1] > 1021.0f || pos[2] < 2.0f || pos[2] > 1021.0f) {
        func_003CD250((Obj *)p);
        return;
    }
    sum = p[8] + (s32)func_L01_00443A18(0.0f, 64.0f);
    if (sum >= 0x100) {
        sum -= 0xFF;
    }
    p[8] = sum;
    if (func_0038CB00((s16 *)(p + 0xA))) {
        func_003CD250((Obj *)p);
        return;
    }
    *(u32 *)(p + 4) = ((u32)(s32)((f32)*(s16 *)(p + 0xA) * *(f32 *)(v + 0x10) * (f32)*(s16 *)(v + 0x14)) << 24) | *(u32 *)(v + 0x18);
}
