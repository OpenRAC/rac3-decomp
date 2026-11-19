/* functional: medium. Written from PAL asm; vector helpers expanded per component, colour blends via func_0038DBD8; D_001DFB40 frame bit read as an s32. */
extern u8 D_001A4CC0[];
extern void func_L01_0044E130(void *, void *);
extern void func_003C4E80(void *, void *);
extern s32 D_001DFB40;
void func_L01_0046DC50(u8 *p) {
    u8 *v = p + 0x20;
    f32 dist, t;
    vu0_v4 q0, q1, q2;
    f32 *pos = (f32 *)(p + 0x10);
    if (D_001DFB40 & 1) {
        p[8] = p[8] + 1;
    }
    dist = func_0038CF00(p + 0x10, D_001A4CC0);
    if (dist < 5.0f) {
        f32 *tgt = *(f32 **)(v + 0x18);
        if (tgt[2] > 0.0f) {
            q1 = *(vu0_v4 *)tgt;
            q1.x = tgt[0] - pos[0];
            q1.y = tgt[1] - pos[1];
            q1.z = tgt[2] - pos[2];
            if (func_0038CEA8(&q1) > 0.5f) {
                func_0038CF68(&q1, &q1, 0.1f / dist);
                pos[0] = pos[0] + q1.x;
                pos[1] = pos[1] + q1.y;
                pos[2] = pos[2] + q1.z;
            } else {
                func_0038CF68(&q1, &q1, 0.005f);
                func_003C4E80(&q1, p + 0x24);
            }
        }
    }
    t = (2.5f - (dist - 0.5f)) / 2.5f;
    if (t > 1.0f) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    *(s32 *)(p + 4) = func_0038DBD8(*(s32 *)(v + 8), *(s32 *)(v + 0xC), t);
    if (*(s16 *)(v + 0x10) != 0) {
        s32 c;
        func_L01_0044E130(&q0, v);
        pos[0] = pos[0] + q0.x;
        pos[1] = pos[1] + q0.y;
        pos[2] = pos[2] + q0.z;
        c = *(s32 *)(p + 4);
        *(s32 *)(p + 4) = func_0038DBD8(c & 0xFFFFFF, c, 1.0f - (f32)*(s16 *)(p + 0xA) / (f32)*(s16 *)(v + 0x10));
        if (func_0038CB00((s16 *)(p + 0xA))) {
            *(s16 *)(v + 0x10) = 0;
            *(s16 *)(p + 0xA) = *(u16 *)(v + 0x12);
        }
    } else if (*(s16 *)(v + 0x12) != 0) {
        func_L01_0044E130(&q1, v);
        func_L01_0044E130(&q2, v + 4);
        func_0038CDF8((f32 *)&q0, (f32 *)&q2, (f32 *)&q1, (f32)*(s16 *)(p + 0xA) / (f32)*(s16 *)(v + 0x12));
        pos[0] = pos[0] + q0.x;
        pos[1] = pos[1] + q0.y;
        pos[2] = pos[2] + q0.z;
        if (func_0038CB00((s16 *)(p + 0xA))) {
            *(s16 *)(v + 0x12) = 0;
            *(s16 *)(p + 0xA) = *(u16 *)(v + 0x14);
        }
    } else {
        s32 c;
        func_L01_0044E130(&q0, v + 4);
        pos[0] = pos[0] + q0.x;
        pos[1] = pos[1] + q0.y;
        pos[2] = pos[2] + q0.z;
        c = *(s32 *)(p + 4);
        *(s32 *)(p + 4) = func_0038DBD8(c & 0xFFFFFF, c, (f32)*(s16 *)(p + 0xA) / (f32)*(s16 *)(v + 0x14));
        if (func_0038CB00((s16 *)(p + 0xA))) {
            func_003CD250((Obj *)p);
        }
    }
}
