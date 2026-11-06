#include "common.h"

typedef struct {
    u8 pad0[0x56C];
    s32 first;
    s32 second;
    u8 pad1[0x5C0 - 0x574];
} Entry_L39_00619C88;

/* localdecomp:start func_L39_00619C88 */
extern Entry_L39_00619C88 D_L39_00225900[];
extern void func_001999A8(s32);
extern void func_001999B0(s32);
extern void func_L39_00674BD0(void);

void func_L39_00619C88(void) {
    Entry_L39_00619C88 *entry;
    Entry_L39_00619C88 *end;
    func_001999A8(0);
    func_001999B0(0);
    func_L39_00674BD0();
    entry = D_L39_00225900;
    end = entry + 8;
    do {
        entry->first = 0;
        entry->second = 0;
        entry++;
    } while ((s32)entry < (s32)end);
}
/* localdecomp:end func_L39_00619C88 */
