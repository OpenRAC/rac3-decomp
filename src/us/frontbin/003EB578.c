#include "common.h"

/* localdecomp:start func_U_003EB578 */
typedef struct {
    u8 pad[0x2C];
    u8 *data;
} Object_003EB578;

void func_U_003EB578(Object_003EB578 *object, f32 value) {
    *(f32 *)(object->data + 0x50) = value;
}
/* localdecomp:end func_U_003EB578 */
