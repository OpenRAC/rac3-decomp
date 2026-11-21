/* functional: high. Near-miss draft (296 words differ: spills/regalloc only). Re-read the whole PAL asm block by block: stack frame layout of v (colors@0x40, uv@0x50, w70..w88@0x70, selectors@0x90, tint@0xA0) matches what func_003D2DA0 reads, branch structure, $gp globals (0x6E0..0x6EC), constants (0xFF9000000260, 0x8000000040|blend<<2) all verified. D_001A4BE0_00337880 is the file-local suffixed alias of D_001A4BE0. */
/* localdecomp:start func_L01_00337880 */
typedef struct {
    u8 pad0[0x234]; s32 flag234; u8 pad238[0x25C0 - 0x238]; u8 *moby;
} Hero_00337880;
typedef struct {
    s16 selectors[4];
    u32 colors[4][4];
    f32 rate;
    s128 *vertices;
    s16 (*indices)[8];
    f32 (*uv)[2];
    s16 count;
    u8 pad5A[2];
    f32 uv_rate;
} Row_00337880;
typedef struct { u8 bytes[0xF0]; } Equip_00337880;
extern Hero_00337880 D_001A4BE0_00337880;
extern u8 D_001425C0[];
extern Equip_00337880 D_L01_002C5600[];
extern Row_00337880 D_L01_002B13E8[];
__asm__(".extern D_001DCF94_sda, 4");
extern s32 D_001DCF94_sda;
__asm__(".extern D_001DCF98_sda, 4");
extern s32 D_001DCF98_sda;
__asm__(".extern D_001DCF9C_sda, 4");
extern s32 D_001DCF9C_sda;
__asm__(".extern D_001DCF90_sda, 4");
extern f32 D_001DCF90_sda;
extern s32 D_L01_001DFB40;
extern s32 D_L01_001E1890;
void func_L01_00337880(u8 *m) {
    extern unsigned long func_00389598(s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003D2DA0(void *, void *, s32);
    struct {
        s128 pos[4];
        u32 colors[4];
        f32 uv[8];
        unsigned long w70, w78, w80, w88;
        s32 selectors[4];
        s32 tint;
        s32 next;
        u32 *color_base;
        f32 *u_base, *v_base;
    } v;
    u8 *p = *(u8 **)(m + 0x68);
    Row_00337880 *r;
    s32 texture, blend, group, state, kind;
    s32 dt;
    s32 i, next;
    s32 j, offset;
    s32 quad_offset;
    s16 idx;
    s128 *dst;
    u32 *color;
    f32 *pu, *pv;
    f32 scale, alpha_scale;
    if (p == 0 || *(f32 *)(p + 0x70) == 0.0f) return;
    if (*(f32 *)(p + 0x70) == 1.0f) {
        u8 *hero = D_001A4BE0_00337880.moby;
        if (hero[0x42] != hero[0x43] || hero[0x42] == 0xFF) {
            *(f32 *)(p + 0x70) = 0.0f;
            return;
        }
    }
    v.tint = D_001DCF9C_sda;
    texture = D_001DCF94_sda;
    kind = D_L01_002C5600[D_001425C0[9]].bytes[1];
    if (kind == 1) texture = 0x31;
    else if (kind == 2) goto texture39;
    else if (kind == 3) { texture39: texture = 0x39; }
    else if (kind == 4) goto texture41;
    else if (kind == 5) goto texture41;
    else if (kind == 6) { texture41: texture = 0x41; }
    else if (kind == 7 || D_001A4BE0_00337880.flag234 != 0) texture = 0x38;
    blend = D_001DCF98_sda;
    scale = 1.0f;
    alpha_scale = 1.0f;
    state = D_001A4BE0_00337880.moby[0x42];
    if ((u32)(state - 0x17) < 3 || state == 0x28) state = D_001A4BE0_00337880.moby[0x42];
    else state = *(s16 *)(p + 0x78);
    if (state == 0x17) { *(s16 *)(p + 0x78) = state; group = 0; }
    else if (state == 0x18) { *(s16 *)(p + 0x78) = state; group = 1; }
    else if (state == 0x19) { *(s16 *)(p + 0x78) = state; group = 2; }
    else {
        *(s16 *)(p + 0x78) = 0x28;
        group = 3;
        if (D_L01_002C5600[D_001425C0[9]].bytes[1] < 7 && D_001A4BE0_00337880.flag234 == 0) texture = 0xC;
        else texture = 0xA;
        alpha_scale = 0.7f;
        scale = 1.25f;
        v.tint = 0x408080;
        blend = 2;
    }
    r = &D_L01_002B13E8[group];
    v.selectors[0] = r->selectors[0];
    v.selectors[1] = r->selectors[1];
    v.selectors[2] = r->selectors[2];
    v.selectors[3] = r->selectors[3];
    if (*(f32 *)(p + 0x70) == 1.0f) {
        *(s128 *)(p + 0) = *(s128 *)(D_001A4BE0_00337880.moby + 0xC0);
        *(s128 *)(p + 0x10) = *(s128 *)(D_001A4BE0_00337880.moby + 0xD0);
        *(s128 *)(p + 0x20) = *(s128 *)(D_001A4BE0_00337880.moby + 0xE0);
        D_L01_001E1890 = D_L01_001DFB40;
    }
    { s32 now = D_L01_001DFB40;
    dt = now - D_L01_001E1890;
    dt = dt > 0 ? dt : 1;
    *(f32 *)(p + 0x70) += (f32)dt * r->rate;
    D_L01_001E1890 = now; }
    if ((f32)(r->count * 2) <= *(f32 *)(p + 0x70)) {
        state = D_001A4BE0_00337880.moby[0x42];
        if ((u32)(state - 0x17) >= 3 && state != 0x28) *(s32 *)(p + 0x70) = 0;
        return;
    }
    v.w78 = func_00389598(texture);
    v.w80 = 0xFF9000000260;
    v.w88 = ((unsigned long)blend << 2) | 0x8000000040;
    v.w70 = 5;
    *(s128 *)(p + 0x30) = *(s128 *)(D_001A4BE0_00337880.moby + 0x10);
    v.color_base = v.colors;
    v.u_base = v.uv;
    v.v_base = v.uv + 1;
    for (i = 0; i < r->count;) {
        v.next = i + 1;
        pv = v.v_base;
        quad_offset = i * 16;
        pu = v.u_base;
        color = v.color_base;
        dst = v.pos;
        offset = 0;
        j = 3;
        do {
            idx = *(s16 *)((u8 *)r->indices + quad_offset + offset);
            if (i == v.selectors[0]) *color = *(u32 *)(offset + (s32)r + 8);
            else if (i == v.selectors[1]) *color = *(u32 *)(offset + (s32)r + 0x18);
            else if (i == v.selectors[2]) *color = *(u32 *)(offset + (s32)r + 0x28);
            else if (i == v.selectors[3]) *color = *(u32 *)(offset + (s32)r + 0x38);
            else *color = 0x50808080;
            *color = ((s32)((f32)*((s8 *)color + 3) * alpha_scale) << 24) | v.tint;
            func_0038CE20(dst, &r->vertices[idx], scale);
            dst++; color++;
            idx = *(s16 *)((u8 *)r->indices + quad_offset + offset + 2);
            {
                f32 *uv = r->uv[idx];
                f32 factor = D_001DCF90_sda;
                f32 fade = 1.0f - *(f32 *)(p + 0x70) * r->uv_rate;
                *pu = (uv[0] - 0.5f) * factor + 0.5f;
                *pv = (uv[1] - 0.5f) * factor + 0.5f + fade;
            }
            offset = offset + 4; pu = pu + 2; pv = pv + 2;
        } while (--j >= 0);
        i = v.next;
        func_003D2DA0(&v, p, 0);
    }
}
/* localdecomp:end func_L01_00337880 */
