#include "common.h"

typedef int u128_L01_004EA5B0 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x18];
    f32 position;
    u8 pad1[0x380 - 0x1C];
    u128_L01_004EA5B0 vector;
} Source_L01_004EA5B0;

typedef struct {
    u8 pad0[0x190];
    u128_L01_004EA5B0 vector;
    f32 position;
    f32 speed;
    u8 pad1[0x143C - 0x1A8];
    f32 previous_speed;
} State_L01_004EA5B0;

/* localdecomp:start func_L01_004EA5B0 */
extern Source_L01_004EA5B0 D_L01_001E2AC0;
extern State_L01_004EA5B0 D_001A4BE0;
extern void func_L01_004EAFF8(s32, f32, f32, f32);

/* hero_strafe_turn: copies the position and vector from D_L01_001E2AC0 into the hero, calls
 * hero_turn_towards with fixed turn constants, and stores back the resulting speed. */
void func_L01_004EA5B0(void) {
    D_001A4BE0.position = D_L01_001E2AC0.position;
    D_001A4BE0.vector = D_L01_001E2AC0.vector;
    D_001A4BE0.speed = D_001A4BE0.previous_speed;
    func_L01_004EAFF8(0, 0.042f, 0.25f, 0.31997705f);
    D_001A4BE0.previous_speed = D_001A4BE0.speed;
}
/* localdecomp:end func_L01_004EA5B0 */
