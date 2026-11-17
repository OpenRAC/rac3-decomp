#include "common.h"

/* localdecomp:start func_L39_005C2098 */
typedef struct {
    u8 reserved0[0xA4];
    u8 flags[0x100];
} Flags_L39_005C2098;

extern Flags_L39_005C2098 D_001A5990;

/* Maps a value for an input slot: when the slot's flag is set, turns 0x40 into 0x44, 4 into 1 and 8
 * into 2; any other value is returned unchanged. */
s32 func_L39_005C2098(s32 value, u32 index) {
    if (D_001A5990.flags[index] != 0) {
        switch (value) {
        case 0x40:
            return 0x44;
        case 4:
            return 1;
        case 8:
            return 2;
        }
    }
    return value;
}
/* localdecomp:end func_L39_005C2098 */
