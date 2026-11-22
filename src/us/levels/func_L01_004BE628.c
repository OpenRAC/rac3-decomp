#include "common.h"

/* NTSC-U counterpart of func_L01_004C21D0 (src/levels/shared/L01_004C21D0.c): 7 -> 6 */
typedef struct {
    s32 w0;
    u8 b4;
    u8 pad5[15];
} E_004BF8A0;
typedef struct {
    u8 pad0[92];
    s32 w92;
    u8 pad96[32];
    s32 w128;
    s32 w132;
    u8 pad136[184];
    E_004BF8A0 e[1];
} G_004BF8A0;

/* localdecomp:start func_L01_004BE628 */
typedef struct {
    s32 mode;
    u8 pad4[0x34];
    s32 state;
    u8 pad3C[0x740];
    s32 active;
} Vendor_004C21D0;
typedef struct {
    s32 type;
    u8 p4[8];
    s32 val;
    u8 p10[0x90];
} PadE_004C21D0;
typedef struct {
    u8 p0[8];
    PadE_004C21D0 pad[2];
    u8 p148[0x14];
    s32 w15C;
    u8 p160[4];
    s32 w164;
    s32 w168;
} Pads_004C21D0;
extern G_004BF8A0 D_L01_00244740;
extern Pads_004C21D0 D_00142430_004BE628;
extern s32 D_00142660[];
extern u8 D_001426E0[];
extern u32 D_L01_001E0FE0;
extern s32 func_L01_004BE2D0(void);
extern s32 func_L01_004BE190(s32);
extern s32 func_L01_004BBAB8(void);
extern void func_L01_004B75A8(void);
extern void func_L01_004B6E88(s32);
extern s32 func_00399F90(void);
extern s32 func_L01_004B7558(s32);
extern void func_L01_004B7588_004BE628(u32);

void func_L01_004BE628(void) {
    switch (((Vendor_004C21D0 *)&D_L01_00244740)->state) {
    case 0:
    case 1: {
        Pads_004C21D0 *p;
        if (((Vendor_004C21D0 *)&D_L01_00244740)->active) { ((Vendor_004C21D0 *)&D_L01_00244740)->state = 6; break; }
        p = &D_00142430_004BE628;
        if (p->w15C < 3 && p->w164 < 0 && p->pad[0].type == 2 && p->pad[0].val && func_L01_004BE2D0()) {
            if (p->w164 < 0) {
                p->w168 = 0;
                p->w164 = 24;
            }
            func_L01_004BE190(0x17F4);
            ((Vendor_004C21D0 *)&D_L01_00244740)->state = ((Vendor_004C21D0 *)&D_L01_00244740)->state == 1 ? 3 : 2;
        } else {
            if (((Vendor_004C21D0 *)&D_L01_00244740)->state == 1) func_L01_004BE190(0x5C5);
            ((Vendor_004C21D0 *)&D_L01_00244740)->state = 6;
        }
        break;
    }
    case 2:
    case 3: {
        Vendor_004C21D0 *v;
        Pads_004C21D0 *p = &D_00142430_004BE628;
        if (p->w15C >= 3 || p->w164 >= 0 || !func_L01_004BE2D0()) return;
        if (func_L01_004BBAB8()) {
            if (((Vendor_004C21D0 *)&D_L01_00244740)->mode == 5) func_L01_004B75A8();
            else func_L01_004B6E88(0);
        }
        v = (Vendor_004C21D0 *)&D_L01_00244740;
        if (v->state == 3) {
            if (!(D_00142660[18] & 0x40)) {
                func_L01_004BE190(0x5C5);
                goto state_six;
            }
            if (v->active == 0) {
                func_L01_004BE190(0x17F8);
                v->state = 7;
            } else {
                func_L01_004BE190(0x17F7);
                v->state = 7;
            }
        } else {
            if (!v->active || D_001426E0[0xE2]) {
                goto state_six;
            } else if (func_L01_004BE190(0x17F7)) {
                D_001426E0[0xE2] |= 1;
                func_00399F90();
                v->state = 7;
            } else {
                goto state_six;
            }
        }
        break;
    }
    case 4: {
        Pads_004C21D0 *p = &D_00142430_004BE628;
        if (p->w15C >= 3 || p->w164 >= 0) return;
        if (p->pad[1].type == 2 && p->pad[1].val) {
            p->w164 = 24;
            p->w168 = 1;
            func_L01_004BE190(0x1B90);
            ((Vendor_004C21D0 *)&D_L01_00244740)->state = 5;
        } else {
            ((Vendor_004C21D0 *)&D_L01_00244740)->state = 1;
        }
        break;
    }
    case 5: {
        Pads_004C21D0 *p = &D_00142430_004BE628;
        Vendor_004C21D0 *v;
        if (p->w15C >= 3 || p->w164 >= 0 || !func_L01_004BE2D0()) return;
        if (func_L01_004BBAB8()) func_L01_004B6E88(0);
        if (!(D_00142660[18] & 0x40)) {
            ((Vendor_004C21D0 *)&D_L01_00244740)->state = 1;
            break;
        }
        v = (Vendor_004C21D0 *)&D_L01_00244740;
        if (v->active) {
            func_L01_004BE190(0x17F7);
            v->state = 6;
        }
        break;
    }
    case 6: break;
    case 7:
        if (func_L01_004B7558(5)) goto state_six;
        else if (D_L01_001E0FE0 < 2 && func_L01_004BE190(0x17F9)) {
            func_L01_004B7588_004BE628(5);
            goto state_six;
        }
        break;
    }
    return;
state_six:
    ((Vendor_004C21D0 *)&D_L01_00244740)->state = 6;
}
/* localdecomp:end func_L01_004BE628 */
