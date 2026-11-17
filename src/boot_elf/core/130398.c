#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 1301D8.c's earlier functions (tools/port_from_us.py) */
typedef struct {
    u8 pad0[0x184];
    int f184;
    int f188;
} S_130210;

/* localdecomp:start func_00130398 */
typedef struct {
    u8 pad0[0x12C];
    s32 n;              /* 0x12C: motion requests queued */
    u8 pad130[0x140 - 0x130];
} Blk_130398;

typedef struct {
    u8 pad0[0x130];
    s32 f130;
    u8 pad134[0x160 - 0x134];
    s32 f160;
    u8 pad164[0x184 - 0x164];
    s32 f184;
    u8 pad188[0x1C8 - 0x188];
    s32 f1C8;
    s32 f1CC;
    u8 pad1D0[0x1D8 - 0x1D0];
    s32 f1D8;
    s32 f1DC;
    u8 pad1E0[0x1E8 - 0x1E0];
    s32 f1E8;
    s32 f1EC;
    u8 pad1F0[0x5A0 - 0x1F0];
    Blk_130398 blk[2];  /* 0x5A0, 0x140 each */
    s32 f820;
} G_130398;

/* libmpeg form_predictions (MSSG recon.c shape); 2.9-ee-991111 */
void func_00130398(G_130398 *g, s32 bx, s32 by, s32 mbt, s32 mt, s32 *pmv, s32 *sel, s32 *dmvec) {
    extern void func_00130CF0();
    extern void func_00130210();
    extern void func_0013A150(void *s, char *fmt, int x);
    extern char D_00151C90[];
    extern char D_00151CB0[];
    extern char D_00151CD0[];
    s32 done;
    s32 dmv[4];
    s32 ref[2][2];
    s32 cur;
    s32 sw;     /* 1: field flag of the frame-picture field calls; field pictures: which reference frame */

    done = 0;
    sw = 1;
    g->blk[g->f820].n = 0;
    if ((mbt & 8) || g->f160 == 2) {
        if (g->f184 == 3) {
            if (mt == 2 || !(mbt & 8)) {
                func_00130CF0(g, g->f1C8, 0, 0, 0, 0x10, bx, by, pmv[0], pmv[1], 0, 0);
            } else if (mt == 1) {
                func_00130CF0(g, g->f1C8, sel[0], 0, 0, 8, bx, by, pmv[0], pmv[1] >> 1, 1, 0);
                func_00130CF0(g, g->f1C8, sel[2], 1, 0, 8, bx, by, pmv[4], pmv[5] >> 1, 1, 0);
            } else if (mt == 3) {
                func_00130210(g, dmv, dmvec, pmv[0], pmv[1] >> 1);
                func_00130CF0(g, g->f1C8, 0, 0, 0, 8, bx, by, pmv[0], pmv[1] >> 1, sw, 0);
                func_00130CF0(g, g->f1C8, 1, 0, 0, 8, bx, by, dmv[0], dmv[1], sw, sw);
                func_00130CF0(g, g->f1C8, 1, 1, 0, 8, bx, by, pmv[0], pmv[1] >> 1, sw, 0);
                func_00130CF0(g, g->f1C8, 0, 1, 0, 8, bx, by, dmv[2], dmv[3], sw, sw);
            } else {
                func_0013A150(g, D_00151C90, mt);
            }
        } else {
            ref[0][0] = g->f1D8;
            ref[0][1] = g->f1E8;
            ref[1][0] = g->f1DC;
            ref[1][1] = g->f1EC;
            cur = g->f184 == 2;
            if (g->f160 == 2 && g->f130 != 0 && cur != sel[0]) {
                sw = 1;
            } else {
                sw = 0;
            }
            if (mt == 1 || !(mbt & 8)) {
                func_00130CF0(g, ref[sw][sel[0]], 0, 0, 0, 0x10, bx, by, pmv[0], pmv[1], 0, 0);
            } else if (mt == 2) {
                func_00130CF0(g, ref[sw][sel[0]], 0, 0, 0, 8, bx, by, pmv[0], pmv[1], 0, 0);
                sw = 0;
                if (g->f160 == mt && g->f130 != 0 && cur != sel[2]) {
                    sw = 1;
                }
                func_00130CF0(g, ref[sw][sel[2]], 0, 0, 8, 8, bx, by, pmv[4], pmv[5], 0, 0);
            } else if (mt == 3) {
                sw = 0;
                if (g->f130 != 0) {
                    sw = 1;
                }
                func_00130210(g, dmv, dmvec, pmv[0], pmv[1]);
                func_00130CF0(g, ref[0][cur], 0, 0, 0, 0x10, bx, by, pmv[0], pmv[1], 0, 0);
                func_00130CF0(g, ref[sw][cur ? 0 : 1], 0, 0, 0, 0x10, bx, by, dmv[0], dmv[1], 0, 1);
            } else {
                func_0013A150(g, D_00151CB0, mt);
            }
        }
        done = 1;
    }
    if (mbt & 4) {
        if (g->f184 == 3) {
            sw = 1;
            if (mt == 2) {
                func_00130CF0(g, g->f1CC, 0, 0, 0, 0x10, bx, by, pmv[2], pmv[3], 0, done);
            } else {
                func_00130CF0(g, g->f1CC, sel[1], 0, 0, 8, bx, by, pmv[2], pmv[3] >> 1, sw, done);
                func_00130CF0(g, g->f1CC, sel[3], 1, 0, 8, bx, by, pmv[6], pmv[7] >> 1, sw, done);
            }
        } else if (mt == 1) {
            func_00130CF0(g, sel[1] ? g->f1EC : g->f1DC, 0, 0, 0, 0x10, bx, by, pmv[2], pmv[3], 0, done);
        } else if (mt == 2) {
            func_00130CF0(g, sel[1] ? g->f1EC : g->f1DC, 0, 0, 0, 8, bx, by, pmv[2], pmv[3], 0, done);
            func_00130CF0(g, sel[3] ? g->f1EC : g->f1DC, 0, 0, 8, 8, bx, by, pmv[6], pmv[7], 0, done);
        } else {
            func_0013A150(g, D_00151CD0, mt);
        }
    }
}
/* localdecomp:end func_00130398 */
