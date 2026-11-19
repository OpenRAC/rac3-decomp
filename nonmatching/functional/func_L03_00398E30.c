/* functional: high. Written from the PAL assembly (no draft). Per-step animation advance for a Phoenix object's keyed sub-blocks: on first use (stage 0x4EC == -1) it starts at stage 3 with the value of func_L03_00399218(3,1); every call it springs the current block's float towards func_L03_00399218(0,1) (func_L01_00448890), eases the earlier blocks with func_0038DAB8, and when func_0038DB00(block value, target at +0x4D0) is >= 0 it either steps the stage down (reloading +0x4D0) or, at stage 0, ends the sequence: frees the sound voice at +0x4E8 (func_003A4F28), sets it to -1 and switches the object to state `next`. */
/* localdecomp:start func_L03_00398E30 */
extern u8 D_001A30B0[];
extern f32 func_L03_00399218(s32, s32);
extern f32 func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_003A4F28(s32);
extern void func_L01_004450F0(void *, s32, s32);
void func_L03_00398E30(u8 *o, s32 idx, s32 next) {
    u8 *d = *(u8 **)(o + 0x68);
    u8 *blk;
    f32 f20, r;
    s32 i, voice, off;
    if (*(s16 *)(d + 0x4EC) == -1) {
        *(s32 *)(d + 0x4D4) = 0;
        *(s16 *)(d + 0x4EC) = 3;
        *(f32 *)(d + 0x4D0) = func_L03_00399218(3, 1);
    }
    off = idx << 7;
    blk = d + off + 0x3C0 + (*(s16 *)(d + 0x4EC) << 5);
    i = 3;
    f20 = func_L01_00448890(blk, d + 0x4D4, 0, func_L03_00399218(0, 1), 0.0006981318f, 0.0006981318f, 54.000004f);
    if (*(s16 *)(d + 0x4EC) < 3) {
        u8 *q = d + off + 0x60;
        do {
            *(f32 *)(q + 0x3C0) = func_0038DAB8(*(f32 *)(q + 0x3C0), f20);
            i--;
            q -= 0x20;
        } while (*(s16 *)(d + 0x4EC) < i);
    }
    r = func_0038DB00(*(f32 *)(d + off + (*(s16 *)(d + 0x4EC) << 5) + 0x3C0), *(f32 *)(d + 0x4D0));
    if (0.0f <= r) {
        if (*(s16 *)(d + 0x4EC) > 0) {
            s16 st = *(s16 *)(d + 0x4EC) - 1;
            *(s16 *)(d + 0x4EC) = st;
            *(f32 *)(d + 0x4D0) = func_L03_00399218(st, 1);
        } else {
            *(f32 *)(d + 0x4D4) = 0.0f;
            *(s16 *)(d + 0x4EC) = -1;
            voice = *(s32 *)(d + 0x4E8);
            if (voice != -1) {
                u8 *p = D_001A30B0 + (voice << 7);
                if (*(u8 **)(p + 0xDC) == o && p[0xD0] != 0) func_003A4F28(voice);
            }
            *(s32 *)(d + 0x4E8) = -1;
            func_L01_004450F0(o, next, -1);
        }
    }
}
/* localdecomp:end func_L03_00398E30 */
