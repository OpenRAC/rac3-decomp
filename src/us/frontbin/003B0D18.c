
#include "common.h"



/* localdecomp:start func_U_003B0D18 */
typedef struct {
    u8 pad[0xB7];
    u8 language;
} Settings_003B0D18;

extern Settings_003B0D18 D_00143950;
extern void func_U_003B0DA0(void);

void func_U_003B0D18(void)
{
    Settings_003B0D18 *settings = &D_00143950;
    u32 current = settings->language;

    if (current == 0) {
        settings->language = 2;
    } else if (current == 2) {
        settings->language = 4;
    } else if (current == 4) {
        settings->language = 0;
    }

    func_U_003B0DA0();
}
/* localdecomp:end func_U_003B0D18 */
