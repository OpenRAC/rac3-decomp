/* near miss (open-rac-engine names it camera_set_tilt): matches in check.py and in every level but
 * the ones that differ: levels 02 and 16 store the tilt at 0x26C, the other 47 at 0x204: the catalogue counts them as one function (it masks load/store offsets), so one C cannot match all 49. */
#include "common.h"

typedef struct { u8 pad[0x460]; } Entry_3E6C58;

extern Entry_3E6C58 D_L01_001E2A40[];
void func_L01_003E8D48(s32 player, f32 tilt) {
    u8 *e = ((u8 *)&D_L01_001E2A40) + player * 1120;
    u8 *o = *(u8 **)(e + 80);
    if (*(s16 *)(o + 134) == 0) {
        *(f32 *)(*(u8 **)(o + 112) + 0x204) = tilt;
    }
}
