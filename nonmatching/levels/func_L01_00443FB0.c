/* Near miss: ammo_crate_pick. Structure and bytes match; only register choice differs: the not_full count lands in $s6 (retail $s5) with the D_001427F0 walker in $s5 (retail $s6), and in the all-guns loop i/k are $s0/$s1 (retail $s1/$s0). */
#include "common.h"
typedef struct {
    u8 pad0[0x8A];
    u16 max_ammo;
    u8 pad8C[0xF0 - 0x8C];
} W_443FB0;

extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern u8 D_L01_002C5600[];
extern s32 func_00382468(s32);
extern s32 func_L01_00443F50(s32);

/* ammo_crate_pick: a random allowed owned gun that uses ammo, among those not full if any;
 * stores it in *gun and returns the pickup count, 1 (4 in 5) or 2 (1 in 5), or 0 for none. */
s32 func_L01_00443FB0(s32 unused, s32 *gun) {
    s32 i;
    s32 not_full = 0;
    s32 allowed = 0;
    s32 k;

    for (i = 0; i < 156; i++) {
        if (D_00142CA0[i] != 0 && ((W_443FB0 *)D_L01_002C5600)[D_001425C0[i]].max_ammo != 0 && func_L01_00443F50(i) != 0) {
            allowed++;
            not_full += D_001427F0[i] < ((W_443FB0 *)D_L01_002C5600)[D_001425C0[i]].max_ammo;
        }
    }
    if (allowed == 0) {
        return 0;
    }
    if (not_full != 0) {
        k = func_00382468(not_full);
        for (i = 0; i < 156; i++) {
            if (D_00142CA0[i] != 0) {
                s32 max = ((W_443FB0 *)D_L01_002C5600)[D_001425C0[i]].max_ammo;
                if (max != 0 && D_001427F0[i] < max && func_L01_00443F50(i) != 0) {
                    if (k-- == 0) {
                        *gun = i;
                        goto done;
                    }
                }
            }
        }
    } else {
        k = func_00382468(allowed);
        for (i = 0; i < 156; i++) {
            if (D_00142CA0[i] != 0 && ((W_443FB0 *)D_L01_002C5600)[D_001425C0[i]].max_ammo != 0 && func_L01_00443F50(i) != 0) {
                if (k-- == 0) {
                    *gun = i;
                    goto done;
                }
            }
        }
    }
done:
    return func_00382468(5) != 0 ? 1 : 2;
}
