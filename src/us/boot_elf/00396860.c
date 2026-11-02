/* Adapted from nonmatching/boot_elf/func_00396948.c in OpenRAC/rac3-decomp.
 * That draft credits the NTSC decomp, commit 13cf5c5, func_00396860.
 * Native addresses and the 13-entry extent were checked against owned retail.
 */
#include "common.h"

/* localdecomp:start func_U_00396860 */
typedef struct BootEntry396860 {
    s32 field0;
    s32 flags;
    u8 reserved8[0xC];
    void (*callback)(struct BootEntry396860 *);
    u8 reserved18[0x50];
    s32 active;
    s32 fade;
    u8 reserved70[0xC];
    s32 timer;
    u8 reserved80[0x10];
} BootEntry396860;

extern BootEntry396860 D_U_00331B60[];
extern s32 D_U_001D9F0C;
extern void func_U_003969D0(void);
extern void func_U_00393770(BootEntry396860 *);

s32 func_U_00396860(s32 update_callbacks) {
    BootEntry396860 *entry;
    s32 end;
    s32 count = 0;
    s32 remaining;
    s32 minimum = 10;
    s32 expired = -6;

    func_U_003969D0();
    entry = D_U_00331B60;
    end = (s32)(entry + 13);
    do {
        if ((entry->flags & 0x10) || D_U_001D9F0C) {
            if (entry->timer < 10) {
                entry->timer = minimum;
            }
        }
        remaining = entry->timer;
        if (remaining > 0) {
            remaining--;
            entry->timer = remaining;
            if (remaining > 0) {
                count++;
                if (entry->fade < 30) {
                    entry->fade++;
                }
                goto process_entry;
            }
        }
        if (entry->fade >= -5) {
            entry->fade--;
        }
process_entry:
        if (entry->active != 0 && entry->fade == expired) {
            func_U_00393770(entry);
        }
        if (update_callbacks != 0 && entry->callback != 0) {
            entry->callback(entry);
        }
        entry++;
    } while ((s32)entry < end);
    return count;
}
/* localdecomp:end func_U_00396860 */
