#include "common.h"

typedef struct {
    u8 reserved[0xE8];
    void (*callback)(void *);
} State_L39_00679F90;

typedef struct {
    u8 reserved[0x60];
    State_L39_00679F90 *state;
} Owner_L39_00679F90;

extern void *D_001E1FD0_sda;
extern void func_L01_00475040(void);
extern void func_003ADAE0(s32);
extern void func_L39_005EF018(void);
extern void func_00195AE8(void);
extern void func_L39_0067C110(void);
extern void func_L39_006D6030(void *);
extern void func_L39_00679F08(void);

/* localdecomp:start func_L39_00679F90 */
void func_L39_00679F90(void) {
    void *saved = D_001E1FD0_sda;
    Owner_L39_00679F90 *object;
    func_L01_00475040();
    func_003ADAE0(0);
    func_L39_005EF018();
    func_00195AE8();
    func_L39_0067C110();
    func_L39_006D6030(saved);
    object = *(Owner_L39_00679F90 **)0x00247A74;
    if (object != 0) {
        object->state->callback(object);
    }
    func_L39_00679F08();
}
/* localdecomp:end func_L39_00679F90 */
