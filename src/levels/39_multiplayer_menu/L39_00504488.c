#include "common.h"

typedef struct S_00504410 {
    u8 pad[0x20];
    u8 *f20;
    void (*f24)(void);
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
} S_00504410;

/* declared by functions of L39_00504410.c, which this file was cut from */
extern S_00504410 *func_L39_004DBA08(void);

/* localdecomp:start func_L39_00504488 */
void func_L39_00504488(s32 arg0) {
    func_L39_004DBA08()->f30 = arg0;
}
/* localdecomp:end func_L39_00504488 */

/* localdecomp:start func_L39_005044B0 */
extern S_00504410 *func_L39_004DBA08(void);

void func_L39_005044B0(s32 arg0) {
    func_L39_004DBA08()->f2C = arg0;
}
/* localdecomp:end func_L39_005044B0 */

/* localdecomp:start func_L39_005044D8 */
void func_L39_005044D8(s32 arg0) {
    func_L39_004DBA08()->f34 = arg0;
}
/* localdecomp:end func_L39_005044D8 */

/* localdecomp:start func_L39_00504500 */
void func_L39_00504500(s32 arg0) {
    func_L39_004DBA08()->f38 = arg0;
}
/* localdecomp:end func_L39_00504500 */
