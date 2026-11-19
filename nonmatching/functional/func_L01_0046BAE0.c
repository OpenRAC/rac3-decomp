/* functional: high. Written from PAL asm; vsub/vadd.xyz done per component; third argument of func_0038CF68 is the f12 left over from the 1.5 compare (register passthrough made explicit). */
void func_L01_0046BAE0(u8 *p) {
    u8 *parent = *(u8 **)(p + 0x30);
    s32 count;
    f32 f20, f21, dist;
    vu0_v4 old;
    vu0_v4 v;
    f32 *cur;
    if (parent == 0 || *(s16 *)(parent + 0xAA) != *(s32 *)(p + 0x38) || parent[0x20] == 0xFE || parent[0x20] == 0xFD) {
        func_003CD250((Obj *)p);
        return;
    }
    f20 = *(f32 *)(p + 0x3C) * func_003824E0(0.5f, 1.0f);
    *(vu0_q *)&old = *(vu0_q *)(p + 0x10);
    f21 = *(f32 *)(p + 0x2C);
    count = *(s32 *)(p + 0x34);
    if (count > 0) {
        func_003C2F58(*(u8 **)(p + 0x30), count, p + 0x10);
    } else {
        *(vu0_q *)(p + 0x10) = *(vu0_q *)(*(u8 **)(p + 0x30) + 0x10);
    }
    cur = (f32 *)(p + 0x10);
    dist = func_0038CF00(cur, (f32 *)(p + 0x20));
    if (dist > 1.5f) {
        v = old;
        v.x = old.x - cur[0];
        v.y = old.y - cur[1];
        v.z = old.z - cur[2];
        func_0038CF68(&v, &v, 1.5f);
        *(f32 *)(p + 0x20) = cur[0] + v.x;
        *(f32 *)(p + 0x24) = cur[1] + v.y;
        *(f32 *)(p + 0x28) = cur[2] + v.z;
    }
    *(f32 *)(p + 0x2C) = f21;
    *(f32 *)(p + 0x1C) = f20;
}
