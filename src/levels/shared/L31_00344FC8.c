#include "common.h"

/* localdecomp:start func_L31_00344FC8 */
#include "vu0.h"
#include "structs/hero.h"
#include "structs/moby.h"

typedef struct {
    u8 weight;
    u8 pad1[0x30 - 1];
} E_00344FC8;

typedef struct {
    u8 pad0[2];
    E_00344FC8 e[8];
    u8 pad182[0x190 - 0x182];
    s32 cursor;
    s32 total;
    u8 pad198[0x1A4 - 0x198];
    u8 count;
    u8 pad1A5;
    u8 mode;
} S_00344FC8;

typedef struct {
    u8 pad0[0x68];
    S_00344FC8 *s;
} O_00344FC8;

extern struct Hero D_001A4BE0;
extern f32 D_L31_001DCFB8;
extern f32 D_L31_001DCFBC;
extern f32 D_L31_001DCFC0;
extern f32 D_L31_001DCFC4;
extern f32 func_0038DB00(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L31_00344C30(void *, s32, f32 *);

s32 func_L31_00344FC8(O_00344FC8 *o) {
    S_00344FC8 *s = o->s;
    s32 i;
    s32 n;

    if (s->mode == 1) {
        s32 w;
        i = 0;
        w = func_00382498(0, s->total - 1);
        n = s->count;
        for (; i < n && s->e[i].weight < w; w -= s->e[i].weight, i++) {
        }
        return i;
    } else if (s->mode == 2) {
        f32 buf[4];
        f32 a;
        s32 lo = 0;
        s32 hi = 0;
        s32 k;
        s32 w;
        s32 flag = 1;

        a = fabs_asm(func_0038DB00(D_L31_001DCFBC, D_001A4BE0.hero_moby->rotation.z));
        if (!(a < fabs_asm(func_0038DB00(D_L31_001DCFC0, D_001A4BE0.hero_moby->rotation.z)))) {
            flag = 0;
        }
        for (k = 0; k < 8; k++) {
            f32 x, hx;
            func_L31_00344C30(o, k, buf);
            x = buf[0];
            hx = D_001A4BE0.hero_moby->position.x;
            if (fabs_asm(x - hx) < D_L31_001DCFB8) continue;
            if (s->e[k].weight == 0xFF) continue;
            if ((x < hx && !flag) || (hx < x && flag)) {
                lo++;
            } else {
                hi++;
            }
        }
        if (D_L31_001DCFC4 < func_003824E0(0.0f, 1.0f) && hi > 0) {
            w = func_00382498(0, hi - 1);
            for (k = 0; k < 8; k++) {
                f32 x, hx;
                func_L31_00344C30(o, k, buf);
                x = buf[0];
                hx = D_001A4BE0.hero_moby->position.x;
                if ((x < hx && flag) || (hx < x && !flag)) {
                    if (s->e[k].weight != 0xFF) {
                        if (w <= 0) return k;
                        w--;
                    }
                }
            }
            return 0;
        } else if (lo > 0) {
            w = func_00382498(0, lo - 1);
            for (k = 0; k < 8; k++) {
                f32 x, hx;
                func_L31_00344C30(o, k, buf);
                x = buf[0];
                hx = D_001A4BE0.hero_moby->position.x;
                if ((x < hx && !flag) || (hx < x && flag)) {
                    if (s->e[k].weight != 0xFF) {
                        if (w <= 0) return k;
                        w--;
                    }
                }
            }
            return 0;
        }
        return 0;
    } else if (s->mode == 0) {
        u8 c;
        s32 cur;
        s32 acc = 0;
        i = 0;
        if (s->cursor >= s->total) {
            s->cursor -= s->total;
        }
        if ((c = s->count) != 0) {
            cur = s->cursor;
            if (s->e[0].weight <= cur) {
                do {
                    acc += s->e[i].weight;
                    i++;
                } while (i < c && s->e[i].weight + acc <= cur);
            }
        }
        if (i == s->count) i = 0;
        s->cursor++;
        return i;
    }
    return 0;
}
/* localdecomp:end func_L31_00344FC8 */
