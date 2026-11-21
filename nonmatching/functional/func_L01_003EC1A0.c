/* functional: high. Per-frame aim/heading update of a player-linked mover: sets three smoothing values on the player's object from the target distance, picks (state 0x2B) the nearest valid candidate from the target's candidate list (kinds 0x323/0x2F6/0x19C4, score = distance - 10*dot), turns the heading toward it through func_00382C58, rebuilds the facing vector and offsets it by the pose. Reads tgt[0x21] even when tgt is NULL, as retail does. */
#include "vu0.h"
extern u8 D_L01_001E2A40[];
extern s32 D_001D545C;
extern s16 *D_0021DE20[];
extern u8 *D_001E001C;
extern void func_003C4138(f32 *, f32, f32);
extern void func_0038CF68(f32 *, f32 *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_00382C58(f32 *, f32, f32, f32, f32, f32);
extern s32 func_0038CB00(void *);
void func_L01_003EC1A0(u8 *a0) {
    f32 va[4] __attribute__((aligned(16)));
    f32 vb[4] __attribute__((aligned(16)));
    f32 vc[4] __attribute__((aligned(16)));
    f32 vd[4] __attribute__((aligned(16)));
    u8 *data = *(u8 **)(a0 + 0x70);
    u8 *dA0 = data + 0xA0;
    u8 *s = data + 0x40;
    u8 *e = D_L01_001E2A40 + *(s32 *)(a0 + 0x94) * 0x460;
    u8 *e150 = e + 0x150;
    u8 *tgt = *(u8 **)(e150 + 0x138);
    f32 *ang = (f32 *)(data + 0xB8);
    f32 r, A, B, f13, best, d, score, mag, lim;
    u8 *bestobj = 0;
    u8 *cand;
    s16 *list;
    u8 *objp;
    s32 st, idx, k;

    if (tgt != 0 && *(s32 *)(e150 + 0x100) == 0x2B) {
        r = *(f32 *)(tgt + 0x18) - *(f32 *)(e150 + 0x48);
        lim = *(f32 *)(e150 + 0x140);
        if (lim < r) r = lim;
        else if (r < 0.0f) r = 0.0f;
        r = r / lim;
        B = r + r;
        A = r + 3.65f;
    } else {
        A = 4.64f;
        B = 2.0f;
    }
    objp = *(u8 **)(e + 0x50);
    func_003C4138((f32 *)(*(u8 **)(objp + 0x70) + 0xA0), A, 0.16f);
    objp = *(u8 **)(e + 0x50);
    func_003C4138((f32 *)(*(u8 **)(objp + 0x70) + 0xB0), B, 0.08f);
    objp = *(u8 **)(e + 0x50);
    func_003C4138((f32 *)(*(u8 **)(objp + 0x70) + 0x8C), B - 0.5f, 0.16f);

    st = *(s32 *)(e150 + 0x100);
    if (st != 0x2B) {
        if (st == 0x24) {
            if (*(s32 *)(s + 0x40) == 1)
                f13 = *(f32 *)(*(u8 **)(s + 0x44) + 0xF8);
            else
                f13 = *(f32 *)(e150 + 0x58);
            ang[0] = func_00382C58(ang + 1, ang[0], f13, 0.00125f, 0.175f, 0.0f);
        }
    } else {
        st = D_001D545C;
        if (st == 0xE || st == 7 || st == 9) {
            idx = tgt[0x21];
            if (tgt != 0 && idx == 0xFF) goto turn_default;
            list = D_0021DE20[idx];
            best = 1000.0f;
            if (list != 0) {
                u8 *c;
                do {
                    c = D_001E001C + ((*(u16 *)list & 0x7FFF) << 8);
                    if (c != tgt) {
                        k = *(s16 *)(c + 0xAA);
                        if (k == 0x323 || k == 0x2F6 || k == 0x19C4) {
                            vec_sub_ba(vb, c + 0x10, tgt + 0x10);
                            func_0038CF68(vc, vb, 1.0f);
                            vd[0] = func_0038D098(*(f32 *)(e150 + 0x58));
                            vd[1] = func_0038D0B0(*(f32 *)(e150 + 0x58));
                            vd[2] = 0.0f;
                            d = func_0038CE68(vc, vd);
                            if (0.0f < d) {
                                mag = func_0038CEA8(vb);
                                score = mag - d * 10.0f;
                                if (score < best) {
                                    bestobj = c;
                                    best = score;
                                }
                            }
                        }
                    }
                } while (*(s16 *)list++ >= 0);
            }
            if (bestobj != 0) {
                vec_sub_ab(vb, bestobj + 0x10, tgt + 0x10);
                f13 = func_0038D160(vb[0], vb[1]);
                ang[0] = func_00382C58(ang + 1, ang[0], f13, 0.00125f, 0.175f, 0.0f);
            } else {
                if (*(s32 *)(s + 0x40) == 1)
                    f13 = *(f32 *)(*(u8 **)(s + 0x44) + 0xF8);
                else
                    f13 = *(f32 *)(e150 + 0x58);
                ang[0] = func_00382C58(ang + 1, ang[0], f13, 0.00125f, 0.175f, 0.0f);
            }
        } else {
turn_default:
            ang[0] = func_00382C58(ang + 1, ang[0], *(f32 *)(e150 + 0x58), 0.00125f, 0.175f, 0.0f);
        }
    }
    *(f32 *)(s + 0x30) = func_0038D098(ang[0]);
    *(s32 *)(s + 0x38) = 0;
    *(f32 *)(s + 0x34) = func_0038D0B0(ang[0]);
    *(s32 *)(s + 0x3C) = *(s32 *)(s + 0x38);
    func_0038CF68(va, (f32 *)(s + 0x30), -*(f32 *)dA0);
    va[2] = va[2] + *(f32 *)(dA0 + 0x10);
    vec_add_ba(va, va, e150 + 0x40);
    func_0038CB00(data + 0x1E);
    *(vu0_q *)(a0 + 0x30) = *(vu0_q *)va;
}
