#include "common.h"

typedef struct {
    u8 reserved[0xE8];
    void (*callback)(void *);
} State_L39_00679E90;

typedef struct {
    u8 reserved[0x60];
    State_L39_00679E90 *state;
} Owner_L39_00679E90;

extern Owner_L39_00679E90 *D_001DC1E4_sda;
extern void func_00195AE8(void);
extern void func_L39_0067C110(void);
extern void func_L01_00475040(void);
extern void func_003ADAE0(s32);
extern void func_L39_005EF018(void);
extern void func_L39_006D6030(void *);

/* localdecomp:start func_L39_00679E90 */
/* Runs a fixed sequence of per-frame calls (func_00195AE8, func_L39_0067C110, func_L01_00475040,
 * func_003ADAE0, func_L39_005EF018), calls func_L39_006D6030 on the current global object if any,
 * and then invokes the callback in the chosen object's state. */
void func_L39_00679E90(void) {
    Owner_L39_00679E90 *object;
    func_00195AE8();
    func_L39_0067C110();
    func_L01_00475040();
    func_003ADAE0(0);
    func_L39_005EF018();
    object = *(Owner_L39_00679E90 **)0x0024D860;
    if (object != 0) {
        func_L39_006D6030(object);
        object = *(Owner_L39_00679E90 **)0x00247A74;
    } else {
        object = D_001DC1E4_sda;
    }
    if (object != 0) {
        object->state->callback(object);
    }
}
/* localdecomp:end func_L39_00679E90 */
