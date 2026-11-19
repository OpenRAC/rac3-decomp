/* functional: high. near exact; local copies of the later Pads typedef (rename on integration) */
#include "common.h"
/* localdecomp:start func_L01_004C21D0 */
typedef struct { s32 type; u8 p4[8]; s32 val; u8 p10[0x90]; } PadE_004C21D0;
typedef struct { u8 p0[8]; PadE_004C21D0 pad[2]; u8 p148[0x14]; s32 w15C; u8 p160[4]; s32 w164; } Pads_004C21D0;
typedef struct {
    s32 mode;
    u8 pad4[0x34];
    s32 state;
    u8 pad3C[0x740];
    s32 active;
} Vendor_004C21D0;
extern G_004BF8A0 D_L01_002446C0;
extern Pads_004C21D0 D_00142430;
extern s32 D_00142660[];
extern u8 D_001426E0[];
extern u32 D_L01_001E0F60[];
void func_L01_004C21D0(void) {
    extern s32 func_L01_004C1E78(void);
    extern s32 func_L01_004C1D38(s32);
    extern s32 func_L01_004BF660(void);
    extern void func_L01_004BB140(void);
    extern void func_L01_004BAA20(s32);
    extern void func_0039EF28(void);
    extern s32 func_L01_004BB0F0(s32);
    extern void func_L01_004BB120(s32);
    switch (((Vendor_004C21D0 *)&D_L01_002446C0)->state) {
    case 0:
    case 1: {
        Pads_004C21D0 *p;
        if (((Vendor_004C21D0 *)&D_L01_002446C0)->active) { ((Vendor_004C21D0 *)&D_L01_002446C0)->state = 6; break; }
        p = &D_00142430;
        if (p->w15C < 3 && p->w164 < 0 && p->pad[0].type == 2 && p->pad[0].val && func_L01_004C1E78()) {
            if (p->w164 < 0) {
                *(s32 *)((u8 *)p + 0x168) = 0;
                p->w164 = 24;
            }
            func_L01_004C1D38(0x17F4);
            ((Vendor_004C21D0 *)&D_L01_002446C0)->state = ((Vendor_004C21D0 *)&D_L01_002446C0)->state == 1 ? 3 : 2;
        } else {
            if (((Vendor_004C21D0 *)&D_L01_002446C0)->state == 1) func_L01_004C1D38(0x5C5);
            ((Vendor_004C21D0 *)&D_L01_002446C0)->state = 6;
        }
        break;
    }
    case 2:
    case 3: {
        Vendor_004C21D0 *v;
        Pads_004C21D0 *p = &D_00142430;
        if (p->w15C >= 3 || p->w164 >= 0 || !func_L01_004C1E78()) return;
        if (func_L01_004BF660()) {
            if (((Vendor_004C21D0 *)&D_L01_002446C0)->mode == 5) func_L01_004BB140();
            else func_L01_004BAA20(0);
        }
        v = (Vendor_004C21D0 *)&D_L01_002446C0;
        if (v->state == 3) {
            if (!(D_00142660[18] & 0x40)) {
                func_L01_004C1D38(0x5C5);
                goto state_six;
            }
            if (v->active == 0) func_L01_004C1D38(0x17F8);
            else func_L01_004C1D38(0x17F7);
            v->state = 7;
        } else {
            if (!v->active || D_001426E0[0xE2]) {
                goto state_six;
            } else if (func_L01_004C1D38(0x17F7)) {
                D_001426E0[0xE2] |= 1;
                func_0039EF28();
                v->state = 7;
            } else {
                goto state_six;
            }
        }
        break;
    }
    case 4: {
        Pads_004C21D0 *p = &D_00142430;
        if (p->w15C >= 3 || p->w164 >= 0) return;
        if (p->pad[1].type == 2 && p->pad[1].val) {
            p->w164 = 24;
            *(s32 *)((u8 *)p + 0x168) = 1;
            func_L01_004C1D38(0x1B90);
            ((Vendor_004C21D0 *)&D_L01_002446C0)->state = 5;
        } else {
            ((Vendor_004C21D0 *)&D_L01_002446C0)->state = 1;
        }
        break;
    }
    case 5: {
        Pads_004C21D0 *p = &D_00142430;
        Vendor_004C21D0 *v;
        if (p->w15C >= 3 || p->w164 >= 0 || !func_L01_004C1E78()) return;
        if (func_L01_004BF660()) func_L01_004BAA20(0);
        if (!(D_00142660[18] & 0x40)) {
            ((Vendor_004C21D0 *)&D_L01_002446C0)->state = 1;
            break;
        }
        v = (Vendor_004C21D0 *)&D_L01_002446C0;
        if (v->active) {
            func_L01_004C1D38(0x17F7);
            v->state = 7;
        }
        break;
    }
    case 6: break;
    case 7:
        if (func_L01_004BB0F0(5)) goto state_six;
        else if (D_L01_001E0F60[0] < 2 && func_L01_004C1D38(0x17F9)) {
            func_L01_004BB120(5);
            goto state_six;
        }
        break;
    }
    return;
state_six:
    ((Vendor_004C21D0 *)&D_L01_002446C0)->state = 6;
}
/* localdecomp:end func_L01_004C21D0 */
