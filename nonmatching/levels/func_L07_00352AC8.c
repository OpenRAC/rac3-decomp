/* NTSC-U draft (Claude wave C4): C of func_L07_00351DC8, the NTSC-U twin of func_L07_00352AC8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 0 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L07_00351DC8", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (MATCH, 0 diff) only with @ps2as added to the PAL file's line (float constants lui/ori/mtc1, e.g. 0x3B5A740E); jump table (24 entries at D_L07_002C0230) verified 0 mismatches with that flag. File: C4/w06/func_L07_00351DC8.near.c
 */
#include "common.h"

/* localdecomp:start func_L07_00351DC8 */
typedef struct {
    u8 pad0[0x170];
    f32 f170;
    f32 f174;
    f32 f178;
    u8 pad17C[0x74];
    f32 v1F0[4];
    f32 f200;
    u8 pad204[0x263];
    u8 b467;
} S_00351DC8;
typedef struct {
    u8 pad0[0x34];
    u16 h34;
    u8 pad36[0xD];
    u8 b43;
    u8 pad44[0x24];
    S_00351DC8 *p68;
} O_00351DC8;

extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_L07_00353088(void *);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L07_00351DC8(O_00351DC8 *a, s32 state) {
    S_00351DC8 *s = a->p68;

    switch (state) {
    case 1:
        break;
    case 2:
        if (a->b43 != 0) {
            func_003BE4F0(a, 0, 0, 0);
        }
        break;
    case 4:
        a->h34 |= 0x5000;
        s->f170 = 0.0033333334f;
        s->f174 = 0.0033333334f;
        s->f178 = 0.083333336f;
        if (a->b43 != 3) {
            func_003BE4F0(a, 3, 0, 8);
        }
        break;
    case 6:
    case 7:
        if (a->b43 != 0) {
            func_003BE4F0(a, 0, 0, 5);
        }
        break;
    case 8:
    case 24:
        s->f170 = 0.0022222223f;
        s->f174 = 0.0022222223f;
        s->f178 = 0.041666668f;
        if (0.041666668f < s->f200) {
            func_00388830(s->v1F0, s->v1F0, 0.041666668f);
            s->f200 = s->f178;
        }
        if (a->b43 != 2) {
            func_003BE4F0(a, 2, 0, 3);
        }
        break;
    case 9:
        s->f170 = 0.0033333334f;
        s->f174 = 0.0033333334f;
        s->f178 = 0.083333336f;
        if (0.083333336f < s->f200) {
            func_00388830(s->v1F0, s->v1F0, 0.083333336f);
            s->f200 = s->f178;
        }
        if (a->b43 != 3) {
            func_003BE4F0(a, 3, 0, 3);
        }
        break;
    case 10:
        s->f178 = 0.13333334f;
        s->f170 = 0.005f;
        s->f174 = 0.005f;
        if (a->b43 != 4) {
            func_003BE4F0(a, 4, 0, 3);
        }
        break;
    case 11:
        if (a->b43 != 5) {
            func_003BE4F0(a, 5, 0, 3);
        }
        break;
    case 12:
        if (a->b43 != 6) {
            func_003BE4F0(a, 6, 0, 8);
        }
        break;
    case 13:
        if (a->b43 != 10) {
            func_003BE4F0(a, 10, 8, 8);
        }
        break;
    case 14:
        if (a->b43 != 11) {
            func_003BE4F0(a, 11, 8, 8);
        }
        break;
    case 15:
        func_L07_00353088(a);
        s->b467 = 1;
        if (a->b43 != 12) {
            func_003BE4F0(a, 12, 10, 8);
        }
        break;
    case 16:
        func_L07_00353088(a);
        s->b467 = 1;
        if (a->b43 != 13) {
            func_003BE4F0(a, 13, 4, 3);
        }
        break;
    case 17:
        if (a->b43 != 14) {
            func_003BE4F0(a, 14, 0, 3);
        }
        break;
    case 18:
        if (a->b43 != 8) {
            func_003BE4F0(a, 8, 0, 3);
        }
        break;
    case 19:
        if (a->b43 != 7) {
            func_003BE4F0(a, 7, 0, 3);
        }
        break;
    case 20:
        if (a->b43 != 9) {
            func_003BE4F0(a, 9, 5, 6);
        }
        break;
    case 21:
        func_L07_00353088(a);
        s->b467 = 1;
        if (a->b43 != 15) {
            func_003BE4F0(a, 15, 10, 6);
        }
        break;
    case 22:
        if (a->b43 != 16) {
            func_003BE4F0(a, 16, 9, 7);
        }
        break;
    case 23:
        if (a->b43 != 17) {
            func_003BE4F0(a, 17, 0, 2);
        }
        break;
    }
    func_L01_00441FB8(a, state, -1);
}
/* localdecomp:end func_L07_00351DC8 */
