#include "common.h"

/* localdecomp:start func_L40_0041B6B8 */
extern void *func_L39_0066DCC8(void *a, s32 b, s32 c);
extern void func_L39_00662AA0(void *a, void *b, s32 n);

void func_L40_0041B6B8(void *moby, s32 type, s32 val, f32 f) {
    u8 c[16];
    struct {
        f32 f;
        s32 i;
        s32 p;
    } buf;
    void *pvars = *(void **)((u8 *)moby + 104);
    void *msg = func_L39_0066DCC8(moby, 0, 0);
    buf.f = f;
    func_L39_00662AA0(msg, &buf.f, 4);
    buf.i = val;
    func_L39_00662AA0(msg, &buf.i, 4);
    buf.p = *(s32 *)((u8 *)pvars + 80);
    func_L39_00662AA0(msg, &buf.p, 4);
    c[0] = type;
    func_L39_00662AA0(msg, c, 1);
}
/* localdecomp:end func_L40_0041B6B8 */

/* localdecomp:start func_L40_0041B770 */
extern s32 D_001A5DF8[];

void func_L40_0041B770(void *moby, s32 type) {
    s32 buf[2];
    void *msg;
    if (type == -1) {
        msg = ((void *(*)(void *, s32, s32, s32))func_L39_0066DCC8)(moby, 1, 0, 250);
    } else {
        msg = ((void *(*)(void *, s32, s32, s32))func_L39_0066DCC8)(moby, 1, 0, -1);
    }
    buf[0] = type;
    func_L39_00662AA0(msg, &buf[0], 4);
    buf[1] = D_001A5DF8[0];
    func_L39_00662AA0(msg, &buf[1], 4);
}
/* localdecomp:end func_L40_0041B770 */
