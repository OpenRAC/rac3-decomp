/* functional: high. Written from the disassembly (not the draft ported from another game). Not byte exact (file lacks @ps2as for the inline 1.5707964f and 2 nops before div.s). */
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
void func_L01_0045BB60(u8 *self, u8 *other, f32 x) {
    f32 w1, w2, inv, d, k;
    u8 *left = *(u8 **)(other + 72);
    u8 *right = *(u8 **)(other + 76);
    if (left == 0 && right == 0) {
        return;
    }
    if (*(u32 *)(other + 56) & 16) {
        return;
    }
    w1 = 0.0f;
    if (left != 0) {
        w1 = 1.0f;
    }
    w2 = 0.0f;
    if (right != 0) {
        w2 = 1.0f;
    }
    inv = 1.0f / (w1 + w2);
    w2 = w2 * inv;
    w1 = w1 * inv;
    k = 1.5707964f;
    d = func_0038DB00(x, *(f32 *)(self + 248));
    if (k < d) {
        d = k;
    } else if (d < -k) {
        d = -k;
    }
    if (*(u16 *)(self + 52) & 0x8000) {
        d = -d;
    }
    if (*(u8 **)(other + 72) != 0) {
        u8 *l = *(u8 **)(other + 72);
        *(f32 *)(l + 104) = func_0038DAB8(d * w1, *(f32 *)(l + 104));
        l = *(u8 **)(other + 72);
        if (k < *(f32 *)(l + 104)) {
            *(f32 *)(l + 104) = k;
        } else if (*(f32 *)(l + 104) < -k) {
            *(f32 *)(l + 104) = -k;
        }
    }
    if (*(u8 **)(other + 76) != 0) {
        u8 *r = *(u8 **)(other + 76);
        *(f32 *)(r + 104) = func_0038DAB8(d * w2, *(f32 *)(r + 104));
        r = *(u8 **)(other + 76);
        if (k < *(f32 *)(r + 104)) {
            *(f32 *)(r + 104) = k;
        } else if (*(f32 *)(r + 104) < -k) {
            *(f32 *)(r + 104) = -k;
        }
    }
}
