#include "common.h"

/* localdecomp:start func_L39_006461A8 */
typedef struct {
    u8 reserved0[0xA4];
    u8 flags[0x100];
} Flags_L39_006461A8;

extern Flags_L39_006461A8 D_001A5990;
extern void func_L39_006460E8(u8 *, u8 *);
extern void func_L39_00646070(u8 *, u8 *);

void func_L39_006461A8(u8 *object, u8 *first, u8 *second) {
    if (D_001A5990.flags[*(s32 *)(object + 0x2544)]) {
        func_L39_006460E8(object, second);
    } else {
        func_L39_006460E8(object, first);
    }
    func_L39_00646070(object, first);
}
/* localdecomp:end func_L39_006461A8 */
