/* func_L14_003F81B8: near miss, 194 diff (mostly one shifted block): file already VU0 + @ps2as; frame, GS setup, the strip calls, the shrink loop and the func_L14_003F7EB8 re-test match up to register names; left: retail keeps &p in $s4 and the loop index in $s5 (this C $s5/$s4), builds the three result pointers before reading s->n, and reloads p.x/y/z inside the first copy loop where this C hoists them (pointer, index and pre-increment forms tried)
   Level 14 (Koros) only; flags of its file in config/levels/text_parts.txt. */
extern f32 D_L14_001E8AD0[];
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038C750(void);
extern s32 func_L14_003F7EB8(S_3F7C70 *, vu0_v4 *, s32 *, s32 *, s32 *, f32);
extern s32 func_L14_003F8060(u8 *, vu0_v4 *, f32);
extern void func_L14_003F8170(s32, s32, s32, s32, s32);
void func_L14_003F81B8(S_3F7C70 *s, vu0_v4 *pos) {
    vu0_v4 p;
    struct {
        s32 v[3];
        s32 *ptrs[3];
    } r;
    vu0_v4 *pp;
    f32 *o;
    s32 i;
    s32 k;
    s32 next;
    s32 n;
    s32 vis;
    s32 a;
    f32 scale;
    pp = &p;
    *pp = *pos;
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(0x47, 0x513F1);
    func_003A9440(6, func_00389598(1));
    func_0038C750();
    r.ptrs[0] = &r.v[0];
    r.ptrs[1] = &r.v[1];
    r.ptrs[2] = &r.v[2];
    o = D_L14_001E8AD0 - 1;
    for (i = 0; i < s->n; i++) {
        *++o = s->pts[i].x + pp->x;
        *++o = s->pts[i].y + pp->y;
        *++o = s->pts[i].z + pp->z;
    }
    scale = 1.0f;
    vis = func_L14_003F7EB8(s, pp, r.ptrs[0], r.ptrs[1], r.ptrs[2], scale);
    n = *((u8 *)s + 0xD63);
    n = (n * func_L14_003F8060((u8 *)s, pp, 1.5f)) >> 7;
    if (n <= 0) {
        return;
    }
    for (k = 0; k < s->fC; k = next) {
        if (r.v[1] != 0) {
            func_003A9440(0x42, ((unsigned long)(n + 2) << 32) | 0x68);
            func_L14_003F8170(r.v[0], r.v[2] - 1, (s32)D_L14_001E8AD0, (s32)s->col, (s32)s->uv);
            func_003A9440(0x42, ((unsigned long)n << 32) | 0x62);
            func_L14_003F8170(0, r.v[0] - 1, (s32)D_L14_001E8AD0, (s32)s->col, (s32)s->uv);
            if (vis == 0) {
                func_L14_003F8170(r.v[2], s->n0 + 1, (s32)D_L14_001E8AD0, (s32)s->col, (s32)s->uv);
            }
        } else {
            func_003A9440(0x42, ((unsigned long)(n + 2) << 32) | 0x68);
            func_L14_003F8170(0, r.v[0] - 1, (s32)D_L14_001E8AD0, (s32)s->col, (s32)s->uv);
            if (vis == 0) {
                func_L14_003F8170(r.v[2], s->n0 + 1, (s32)D_L14_001E8AD0, (s32)s->col, (s32)s->uv);
            }
            func_003A9440(0x42, ((unsigned long)n << 32) | 0x62);
            func_L14_003F8170(r.v[0], r.v[2] - 1, (s32)D_L14_001E8AD0, (s32)s->col, (s32)s->uv);
        }
        for (i = 0; i < s->n * 3; i += 3) {
            D_L14_001E8AD0[i] = (D_L14_001E8AD0[i] - pp->x) * 0.97f + pp->x;
            D_L14_001E8AD0[i + 1] = (D_L14_001E8AD0[i + 1] - pp->y) * 0.97f + pp->y;
        }
        next = k + 1;
        if (k != 0) {
            scale *= 0.97f;
            vis = func_L14_003F7EB8(s, pp, r.ptrs[0], r.ptrs[1], r.ptrs[2], scale);
        }
    }
}
