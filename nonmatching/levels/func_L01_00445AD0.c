/* near miss: moby_group_count (open-rac-engine symbols.toml). All but the health test matches
 * (21 words): retail counts a moby with no damage record by `beql $v0, $zero` with the count in
 * the delay slot and reloads the list entry after the count (once at the join and once in the
 * bc1f delay slot); gcc loads the entry right after the call, in the beqz delay slot.
 * Tried: ||, nested ifs, else-if, continue, goto, a single count++. */
#include "common.h"

/* localdecomp:start func_L01_00445AD0 */
extern s16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
extern f32 *func_L01_00443828(u8 *moby);

/* moby_group_count: counts a moby group's members (lists at 0x21DE20, the last entry's top bit
 * set) whose state (+0x20) is not negative and not state (-1 for any), only those with health
 * left (or no damage record) if alive is set; 0 for group -1 or 0xFF. */
s32 func_L01_00445AD0(s32 group, s32 state, s32 alive) {
    s16 *list;
    s16 *entry;
    s32 count;

    if (group == -1 || group == 0xFF) return 0;
    list = D_L01_0021DE20[group];
    count = 0;
    if (list == 0) return 0;
    entry = list;
    do {
        u8 *moby = (u8 *)(((*(u16 *)entry & 0x7FFF) << 8) + (s32)D_L01_001E001C);
        if ((s8)moby[0x20] >= 0 && (state == -1 || moby[0x20] != state)) {
            if (!alive) {
                count++;
            } else {
                f32 *health = func_L01_00443828(moby);
                if (health == 0 || 0.0f < *health) count++;
            }
        }
    } while (*entry++ >= 0);
    return count;
}
/* localdecomp:end func_L01_00445AD0 */
