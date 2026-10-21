#include "common.h"

/* localdecomp:start func_L02_004E12F0 */
typedef struct {
    u8 pad0[0x34];
    u16 x34;
} func_004DCEC0_t;
extern func_004DCEC0_t *D_001A71A0[];

void func_L02_004E12F0(void) {
    D_001A71A0[0]->x34 |= 1;
}
/* localdecomp:end func_L02_004E12F0 */

/* localdecomp:start func_L02_004E1308 */
extern func_004DCEC0_t *D_001A71A0[];
typedef struct {
    u8 pad0[0x34];
    u16 x34;
} func_004DCED8_t;

void func_L02_004E1308(void) {
    ((func_004DCED8_t * *)&D_001A71A0)[0]->x34 &= ~1;
}
/* localdecomp:end func_L02_004E1308 */
