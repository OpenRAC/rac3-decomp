/* functional: high. 7-word near miss (return-register scheduling); every branch, constant and offset re-verified against the PAL asm. */
extern u16 *D_L07_0021C020[];
extern s32 D_001DF458_sda;
extern u8 *D_L07_001DF41C_00333DB8;
extern f32 D_L07_001E1EC0[];
void func_L07_00333DB8(u8 *origin, u8 *self, f32 range, f32 *outLeft, f32 *outRight) {
    extern u8 *func_L07_00333918(u8 *);
    extern u8 *func_L01_00449020(u8 *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_L03_0032FB70(f32);
    extern f32 func_0038CF38(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038DB00(f32, f32);
    u8 *state = func_L07_00333918(self);
    f32 left = 100.0f;
    u8 *target = func_L01_00449020(self);
    f32 right = 100.0f;
    f32 base, dist, x, y;
    u16 *q;
    u8 *other, *otherState, *otherTarget;
    if (*(u8 **)(target + 0x10) != 0) {
        f32 angle = func_0038D160(*(f32 *)(self + 0x10) - *(f32 *)target, *(f32 *)(self + 0x14) - *(f32 *)(target + 4));
        *(f32 *)(state + 0x10) = angle;
        base = func_L03_0032FB70(angle);
        if (range > 0.0f) {
            dist = 24.8f - func_0038CF38(origin + 0x10, target);
            if (dist < range) {
                f32 d;
                u8 *p = *(u8 **)(target + 0x10);
                left = func_0038D160(*(f32 *)(origin + 0x10) - *(f32 *)(p + 0x10), *(f32 *)(origin + 0x14) - *(f32 *)(p + 0x14));
                dist = dist / range * 1.5707964f;
                dist = dist + 1.5707964f;
                d = func_0038DB00(*(f32 *)(state + 0x10), func_0038DAB8(left, dist));
                if (d < 0.0f) right = func_L03_0032FB70(-d);
                else right = 0.0f;
                d = func_0038DB00(*(f32 *)(state + 0x10), func_0038DB00(left, dist));
                if (d > 0.0f) left = func_L03_0032FB70(d);
                else left = 0.0f;
            }
        }
        if (self[0x21] != 0xFF) {
            for (q = D_L07_0021C020[self[0x21]];
                 self[0x21] != 0xFF && self[0x21] <= D_001DF458_sda && q != 0 &&
                 ((s16)q[-1] >= 0 || q == D_L07_0021C020[self[0x21]]); q++) {
                other = D_L07_001DF41C_00333DB8 + ((*q & 0x7FFF) << 8);
                if (other == 0) break;
                if (other == self || *(s16 *)(other + 0xAA) != *(s16 *)(self + 0xAA)) continue;
                otherState = func_L07_00333918(other);
                otherTarget = func_L01_00449020(other);
                if (state[0x1C] == otherState[0x1C] && *(u8 **)(target + 0x10) == *(u8 **)(otherTarget + 0x10)) {
                    f32 d = base - func_L03_0032FB70(*(f32 *)(otherState + 0x10));
                    x = func_L03_0032FB70(d);
                    y = func_L03_0032FB70(-d);
                    if (x < left) left = x;
                    if (y < right) right = y;
                }
            }
        }
        if (left > 10.0f) {
            if (outLeft) *outLeft = 6.2831855f;
            if (outRight) *outRight = 6.2831855f;
            *(f32 *)(state + 0x14) = *(f32 *)(state + 0x10);
        } else {
            if (outLeft) *outLeft = left;
            if (outRight) *outRight = right;
            if (func_L03_0032FB70(base - func_L03_0032FB70(D_L07_001E1EC0[6])) < left) *(f32 *)(state + 0x14) = D_L07_001E1EC0[6];
            else *(f32 *)(state + 0x14) = func_0038DAB8(*(f32 *)(state + 0x10), (right - left) * 0.5f);
        }
    }
}
