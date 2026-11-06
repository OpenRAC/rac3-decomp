#include "common.h"

/* localdecomp:start func_L39_005A3550 */
extern void (*D_001D7960_sda)(void);
typedef struct {
    u8 reserved[0x16C];
    s32 flag16C;
    u8 reserved170[0xC];
    s32 field17C;
} State_L39_005A3550;
extern State_L39_005A3550 D_001A4560;

void func_L39_005A3550(void) {
    void (*callback)(void) = D_001D7960_sda;
    if (callback != 0) {
        callback();
        D_001D7960_sda = 0;
    }
    if (D_001A4560.flag16C == 0) {
        D_001A4560.field17C = 1;
    }
    *(s32 *)0x00240578 = 1;
}
/* localdecomp:end func_L39_005A3550 */
