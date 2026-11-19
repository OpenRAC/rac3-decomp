/* functional: high. Verified block by block against the PAL asm; 46 words differ only in colour packing and scheduling. Hardware .extern size hacks dropped. */
typedef struct {
    u8 pad0[0x20E]; s16 tint_timer;
    u8 pad210[0x116C-0x210]; s16 blink_gap, blink;
    u8 pad1170[0x12F4-0x1170]; u8 *back;
    u8 pad12F8[0x25C0-0x12F8]; u8 *moby; s32 state;
    u8 pad25C8[0x25E4-0x25C8]; u8 mode;
    u8 pad25E5[0x2884-0x25E5]; s16 hide;
} H_004E0920;
extern u8 D_001D5470;
extern f32 D_L01_001DBD3C;
extern s32 D_L01_001DFB40;
void func_L01_004E0920(void) {
    extern f32 func_003C4138(f32 *, f32, f32);
    extern s32 func_L01_004DFD60(void);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038CB00(void *);
    extern s32 func_00382498(s32, s32);
    u8 *moby;
    s32 r, b, x, y, small, large, timer;
    s32 period;
    s32 low;
    f32 wave, factor;
    if (D_001D5470) {
        func_003C4138(&D_L01_001DBD3C, 1.8f, 0.05f);
    } else {
        func_003C4138(&D_L01_001DBD3C, 1.0f, 0.05f);
    }
    if ((u32)((*(H_004E0920 *)&D_001A4BE0).mode - 1) < 2) {
        moby = *(u8 **)((u8 *)&D_001A4BE0 + 0x25C0);
    } else {
        if ((*(H_004E0920 *)&D_001A4BE0).hide) return;
        moby = *(u8 **)((u8 *)&D_001A4BE0 + 0x12F4);
    }
    if (moby == 0) return;
    *(u16 *)(moby + 0x34) |= 0x10;
    low = 136;
    r = 56;
    if (func_L01_004DFD60()) r = low;
    period = 92;
    wave = func_0038D0B0(((f32)(D_L01_001DFB40 % period) / (f32)period * 2.0f) * 3.1415927f + -3.1415927f);
    small = (s32)(wave * 24.0f);
    large = (s32)(wave * 48.0f);
    x = small + 12;
    b = small + 76;
    y = large + 24;
    low = large + 160;
    r += x;
    timer = (*(H_004E0920 *)&D_001A4BE0).tint_timer;
    if (timer != 0) {
        s32 fade = 4;
        s32 rise = 17;
        factor = 1.0f;
        if (timer > 37 - fade) factor = (f32)(37 - timer) / (f32)fade;
        if (timer < 17) factor = (f32)timer / (f32)rise;
        {
            s32 remove_x = (s32)(x * factor);
            s32 remove_y = (s32)(y * factor);
            r -= remove_x;
            low -= remove_y;
            b -= remove_x;
        }
        r += (s32)(factor * 112.0f);
        low -= (s32)(factor * 72.0f);
    }
    {
        unsigned long alpha = 128;
        *(u32 *)(moby + 0x78) = (alpha << 24) | (b << 16) | (low << 8) | r;
    }
    if ((*(H_004E0920 *)&D_001A4BE0).mode == 0 && (*(H_004E0920 *)&D_001A4BE0).state != 129) {
        if (func_0038CB00(&(*(H_004E0920 *)&D_001A4BE0).blink_gap) && moby[0x43] == 1) {
            s32 delay = func_00382498(42, 167);
            (*(H_004E0920 *)&D_001A4BE0).blink = 1;
            (*(H_004E0920 *)&D_001A4BE0).blink_gap = delay;
        }
        if ((*(H_004E0920 *)&D_001A4BE0).blink != 0) {
            if (++(*(H_004E0920 *)&D_001A4BE0).blink >= 22) (*(H_004E0920 *)&D_001A4BE0).blink = 0;
        }
    }
}
